/* Copyright (C) 2023 Alif Semiconductor - All Rights Reserved.
 * Use, distribution and modification of this code is permitted under the
 * terms stated in the Alif Semiconductor Software License Agreement
 *
 * You should have received a copy of the Alif Semiconductor Software
 * License Agreement with this file. If not, please write to:
 * contact@alifsemi.com, or visit: https://alifsemi.com/license
 *
 */

#include <string.h>
#include "es0_power_manager.h"
#include "se_service.h"

static volatile uint8_t es0_user_counter;
#define LL_BOOT_PARAMS_MAX_SIZE (512)

#define LL_CLK_SEL_CTRL_REG_ADDR   0x1A60201C
#define LL_UART_CLK_SEL_CTRL_16MHZ 0x00
#define LL_UART_CLK_SEL_CTRL_24MHZ 0x01
#define LL_UART_CLK_SEL_CTRL_48MHZ 0x03

/* Tag status: (STATUS_VALID | STATUS_NOT_LOCKED | STATUS_NOT_ERASED) */
#define DEFAULT_TAG_STATUS (0x00 | 0x02 | 0x04)

/* Boot time value definitions */
#define BOOT_PARAM_ID_LE_CODED_PHY_500          0x85
#define BOOT_PARAM_ID_DFT_SLAVE_MD              0x20
#define BOOT_PARAM_ID_CH_CLASS_REP_INTV         0x36
#define BOOT_PARAM_ID_BD_ADDRESS                0x01
#define BOOT_PARAM_ID_ACTIVITY_MOVE_CONFIG      0x15
#define BOOT_PARAM_ID_SCAN_EXT_ADV              0x16
#define BOOT_PARAM_ID_RSSI_HIGH_THR             0x3A
#define BOOT_PARAM_ID_RSSI_LOW_THR              0x3B
#define BOOT_PARAM_ID_SLEEP_ENABLE              0x11
#define BOOT_PARAM_ID_EXT_WAKEUP_ENABLE         0x12
#define BOOT_PARAM_ID_ENABLE_CHANNEL_ASSESSMENT 0x19
#define BOOT_PARAM_ID_RSSI_INTERF_THR           0x3C
#define BOOT_PARAM_ID_UART_BAUDRATE             0x10
#define BOOT_PARAM_ID_UART_INPUT_CLK_FREQ       0xC0
#define BOOT_PARAM_ID_NO_PARAM                  0xFF

#define BOOT_PARAM_LEN_LE_CODED_PHY_500          1
#define BOOT_PARAM_LEN_DFT_SLAVE_MD              1
#define BOOT_PARAM_LEN_CH_CLASS_REP_INTV         2
#define BOOT_PARAM_LEN_BD_ADDRESS                6
#define BOOT_PARAM_LEN_ACTIVITY_MOVE_CONFIG      1
#define BOOT_PARAM_LEN_SCAN_EXT_ADV              1
#define BOOT_PARAM_LEN_RSSI_THR                  1
#define BOOT_PARAM_LEN_SLEEP_ENABLE              1
#define BOOT_PARAM_LEN_EXT_WAKEUP_ENABLE         1
#define BOOT_PARAM_LEN_ENABLE_CHANNEL_ASSESSMENT 1
#define BOOT_PARAM_LEN_UART_BAUDRATE             4
#define BOOT_PARAM_LEN_UART_INPUT_CLK_FREQ       4

static uint8_t *write_tlv_int(uint8_t *target, uint8_t tag, uint32_t value, uint8_t len)
{
	*target++ = tag;
	*target++ = DEFAULT_TAG_STATUS;
	*target++ = len;
	if (len == 1) {
		memcpy(target, (uint8_t *)&value, len);
	} else if (len == 2) {
		memcpy(target, (uint16_t *)&value, len);
	} else {
		memcpy(target, &value, len);
	}

	target += len;

	return target;
}

static uint8_t *write_tlv_str(uint8_t *target, uint8_t tag, const void *value, uint8_t len)
{
	*target++ = tag;
	*target++ = DEFAULT_TAG_STATUS;
	*target++ = len;

	memcpy(target, value, len);

	target += len;

	return target;
}

int8_t take_es0_into_use(void)
{
	if (255 == es0_user_counter) {
		return -1;
	}

	if (es0_user_counter == 0) {
		/* Shuttdown is needed if riscv was already active */
		se_service_shutdown_es0();
	}

	static uint8_t ll_boot_params_buffer[LL_BOOT_PARAMS_MAX_SIZE];

	memset(ll_boot_params_buffer, 0xFF, LL_BOOT_PARAMS_MAX_SIZE);
	uint8_t *ptr = ll_boot_params_buffer;
	*ptr++ = 'N';
	*ptr++ = 'V';
	*ptr++ = 'D';
	*ptr++ = 'S';

	uint16_t total_length = BOOT_PARAM_LEN_LE_CODED_PHY_500 + BOOT_PARAM_LEN_DFT_SLAVE_MD +
				BOOT_PARAM_LEN_CH_CLASS_REP_INTV + BOOT_PARAM_LEN_BD_ADDRESS +
				BOOT_PARAM_LEN_ACTIVITY_MOVE_CONFIG + BOOT_PARAM_LEN_SCAN_EXT_ADV +
				BOOT_PARAM_LEN_RSSI_THR + BOOT_PARAM_LEN_RSSI_THR +
				BOOT_PARAM_LEN_SLEEP_ENABLE + BOOT_PARAM_LEN_EXT_WAKEUP_ENABLE +
				BOOT_PARAM_LEN_ENABLE_CHANNEL_ASSESSMENT + BOOT_PARAM_LEN_RSSI_THR +
				BOOT_PARAM_LEN_UART_BAUDRATE + BOOT_PARAM_LEN_UART_INPUT_CLK_FREQ;

	total_length += 4; /* N,V,D,S */

	total_length += (14 * 3); /* Each write_tlv_x call writes additional 3 bytes */

	if (total_length > LL_BOOT_PARAMS_MAX_SIZE) {
		return -2;
	}

	/* TODO: Fix this to have proper 48bit UID */
	uint8_t bd_address[BOOT_PARAM_LEN_BD_ADDRESS] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB};

	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_LE_CODED_PHY_500, CONFIG_ALIF_PM_LE_CODED_PHY_500,
			    BOOT_PARAM_LEN_LE_CODED_PHY_500);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_DFT_SLAVE_MD, CONFIG_ALIF_PM_DFT_SLAVE_MD,
			    BOOT_PARAM_LEN_DFT_SLAVE_MD);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_CH_CLASS_REP_INTV, CONFIG_ALIF_PM_CH_CLASS_REP_INTV,
			    BOOT_PARAM_LEN_CH_CLASS_REP_INTV);
	ptr = write_tlv_str(ptr, BOOT_PARAM_ID_BD_ADDRESS, bd_address, BOOT_PARAM_LEN_BD_ADDRESS);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_ACTIVITY_MOVE_CONFIG,
			    CONFIG_ALIF_PM_ACTIVITY_MOVE_CONFIG,
			    BOOT_PARAM_LEN_ACTIVITY_MOVE_CONFIG);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_SCAN_EXT_ADV, CONFIG_ALIF_PM_SCAN_EXT_ADV,
			    BOOT_PARAM_LEN_SCAN_EXT_ADV);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_RSSI_HIGH_THR, CONFIG_ALIF_PM_RSSI_HIGH_THR,
			    BOOT_PARAM_LEN_RSSI_THR);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_RSSI_LOW_THR, CONFIG_ALIF_PM_RSSI_LOW_THR,
			    BOOT_PARAM_LEN_RSSI_THR);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_SLEEP_ENABLE, CONFIG_ALIF_PM_SLEEP_ENABLE,
			    BOOT_PARAM_LEN_SLEEP_ENABLE);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_EXT_WAKEUP_ENABLE, CONFIG_ALIF_PM_EXT_WAKEUP_ENABLE,
			    BOOT_PARAM_LEN_EXT_WAKEUP_ENABLE);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_ENABLE_CHANNEL_ASSESSMENT,
			    CONFIG_ALIF_PM_ENABLE_CH_ASSESSMENT,
			    BOOT_PARAM_LEN_ENABLE_CHANNEL_ASSESSMENT);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_RSSI_INTERF_THR, CONFIG_ALIF_PM_RSSI_INTERF_THR,
			    BOOT_PARAM_LEN_RSSI_THR);
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_UART_BAUDRATE, CONFIG_ALIF_PM_LL_UART_BAUDRATE,
			    BOOT_PARAM_LEN_UART_BAUDRATE);

	uint32_t min_uart_clk_freq = CONFIG_ALIF_PM_LL_UART_BAUDRATE * 16;
	uint32_t reg_uart_clk_cfg = LL_UART_CLK_SEL_CTRL_16MHZ;
	uint32_t ll_uart_clk_freq = 16000000;

	/* UART input clock can be configured as 16/24/48Mhz */
	if (min_uart_clk_freq > 16000000) {
		if (min_uart_clk_freq <= 24000000) {
			ll_uart_clk_freq = 24000000;
			reg_uart_clk_cfg = LL_UART_CLK_SEL_CTRL_24MHZ;
		} else {
			ll_uart_clk_freq = 48000000;
			reg_uart_clk_cfg = LL_UART_CLK_SEL_CTRL_48MHZ;
		}
	}
	ptr = write_tlv_int(ptr, BOOT_PARAM_ID_UART_INPUT_CLK_FREQ, ll_uart_clk_freq,
			    BOOT_PARAM_LEN_UART_INPUT_CLK_FREQ);
	*(uint32_t volatile *)LL_CLK_SEL_CTRL_REG_ADDR = reg_uart_clk_cfg;

	if (total_length < (LL_BOOT_PARAMS_MAX_SIZE - 2)) {
		ptr = write_tlv_int(ptr, BOOT_PARAM_ID_NO_PARAM, 0, 0);
		total_length += 3;
	}

	if (total_length != (ptr - ll_boot_params_buffer)) {
		return -3;
	}

	if (es0_user_counter || 0 == se_service_boot_es0(ll_boot_params_buffer, total_length)) {
		es0_user_counter++;
	} else {
		return -4;
	}
	return 0;
}

int8_t stop_using_es0(void)
{
	if (!es0_user_counter) {
		return -1;
	}
	es0_user_counter--;
	if (!es0_user_counter) {
		if (se_service_shutdown_es0()) {
			return -2;
		}
	}

	return 0;
}
