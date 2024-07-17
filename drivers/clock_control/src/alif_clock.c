/* SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2024 Alif Semiconductor.
 */

#include <stdint.h>
#include <zephyr/dt-bindings/clock/alif_clock_control.h>
#include "alif_clock.h"

uint32_t alif_get_input_clock(uint32_t clock_name)
{
	switch (clock_name) {
	case ALIF_CAMERA_PIX_SYST_ACLK:
	case ALIF_CDC200_PIX_SYST_ACLK:
	case ALIF_CSI_PIX_SYST_ACLK:
		return ALIF_CLOCK_SYST_ACLK_FREQ;
	case ALIF_CAMERA_PIX_PLL_CLK3:
	case ALIF_CDC200_PIX_PLL_CLK3:
	case ALIF_CSI_PIX_PLL_CLK3:
		return ALIF_CLOCK_PLL_CLK3_FREQ;
	case ALIF_CANFD_HFOSC_CLK:
		return ALIF_CLOCK_HFOSC_CLK_FREQ;
	case ALIF_CANFD_160M_CLK:
		return ALIF_CLOCK_160M_CLK_FREQ;
	case ALIF_I2Sn_76M8_CLK(0):
	case ALIF_I2Sn_76M8_CLK(1):
	case ALIF_I2Sn_76M8_CLK(2):
	case ALIF_I2Sn_76M8_CLK(3):
	case ALIF_LPI2S_76M8_CLK:
		return ALIF_CLOCK_76M8_CLK_FREQ;
	case ALIF_LPRTC_CLK:
	case ALIF_GPIOn_DB_CLK(0):
	case ALIF_GPIOn_DB_CLK(1):
	case ALIF_GPIOn_DB_CLK(2):
	case ALIF_GPIOn_DB_CLK(3):
	case ALIF_GPIOn_DB_CLK(4):
	case ALIF_GPIOn_DB_CLK(5):
	case ALIF_GPIOn_DB_CLK(6):
	case ALIF_GPIOn_DB_CLK(7):
	case ALIF_GPIOn_DB_CLK(8):
	case ALIF_GPIOn_DB_CLK(9):
	case ALIF_GPIOn_DB_CLK(10):
	case ALIF_GPIOn_DB_CLK(11):
	case ALIF_GPIOn_DB_CLK(12):
	case ALIF_GPIOn_DB_CLK(13):
	case ALIF_GPIOn_DB_CLK(14):
	case ALIF_LPTIMERn_S32K_CLK(0):
	case ALIF_LPTIMERn_S32K_CLK(1):
	case ALIF_LPTIMERn_S32K_CLK(2):
	case ALIF_LPTIMERn_S32K_CLK(3):
		return ALIF_CLOCK_S32K_CLK_FREQ;
	case ALIF_LPTIMERn_128K_CLK(0):
	case ALIF_LPTIMERn_128K_CLK(1):
	case ALIF_LPTIMERn_128K_CLK(2):
	case ALIF_LPTIMERn_128K_CLK(3):
		return ALIF_CLOCK_128K_CLK_FREQ;
	default:
		return 0;
	}

	return 0;
}

void alif_set_clock_divisor(uint32_t *reg, uint32_t mask,
			uint32_t pos, uint32_t value)
{
	uint32_t reg_value;

	reg_value = *reg;
	reg_value &= ~(mask << pos);
	reg_value |= (value << pos);
	*reg = reg_value;
}

uint32_t alif_get_clock_divisor(uint32_t *reg, uint32_t mask,
				uint32_t pos)
{
	uint32_t freq_div, reg_val;

	reg_val = *reg;
	freq_div = ((reg_val & (mask << pos)) >> pos);

	return freq_div;
}

void alif_get_div_reg_info(uint32_t clock_name, uint32_t *mask,
			uint32_t *pos)
{
	switch (clock_name) {
	case ALIF_CAMERA_PIX_SYST_ACLK:
	case ALIF_CAMERA_PIX_PLL_CLK3:
		*mask = ALIF_CAMERA_PIX_CLK_DIV_MASK;
		*pos = ALIF_CAMERA_PIX_CLK_DIV_POS;
		break;
	case ALIF_CDC200_PIX_SYST_ACLK:
	case ALIF_CDC200_PIX_PLL_CLK3:
		*mask = ALIF_CDC200_PIX_CLK_DIV_MASK;
		*pos = ALIF_CDC200_PIX_CLK_DIV_POS;
		break;
	case ALIF_CSI_PIX_SYST_ACLK:
	case ALIF_CSI_PIX_PLL_CLK3:
		*mask = ALIF_CSI_PIX_CLK_DIV_MASK;
		*pos = ALIF_CSI_PIX_CLK_DIV_POS;
		break;
	case ALIF_CANFD_HFOSC_CLK:
	case ALIF_CANFD_160M_CLK:
		*mask = ALIF_CANFD_CLK_DIV_MASK;
		*pos = ALIF_CANFD_CLK_DIV_POS;
		break;
	case ALIF_I2Sn_76M8_CLK(0):
	case ALIF_I2Sn_76M8_CLK(1):
	case ALIF_I2Sn_76M8_CLK(2):
	case ALIF_I2Sn_76M8_CLK(3):
		*mask = ALIF_I2Sn_CLK_DIV_MASK;
		*pos = ALIF_I2Sn_CLK_DIV_POS;
		break;
	case ALIF_LPI2S_76M8_CLK:
		*mask = ALIF_LPI2S_CLK_DIV_MASK;
		*pos = ALIF_LPI2S_CLK_DIV_POS;
		break;
	case ALIF_GPIOn_DB_CLK(0):
	case ALIF_GPIOn_DB_CLK(1):
	case ALIF_GPIOn_DB_CLK(2):
	case ALIF_GPIOn_DB_CLK(3):
	case ALIF_GPIOn_DB_CLK(4):
	case ALIF_GPIOn_DB_CLK(5):
	case ALIF_GPIOn_DB_CLK(6):
	case ALIF_GPIOn_DB_CLK(7):
	case ALIF_GPIOn_DB_CLK(8):
	case ALIF_GPIOn_DB_CLK(9):
	case ALIF_GPIOn_DB_CLK(10):
	case ALIF_GPIOn_DB_CLK(11):
	case ALIF_GPIOn_DB_CLK(12):
	case ALIF_GPIOn_DB_CLK(13):
	case ALIF_GPIOn_DB_CLK(14):
		*mask = ALIF_GPIOn_DB_CLK_DIV_MASK;
		*pos = ALIF_GPIOn_DB_CLK_DIV_POS;
		break;
	default:
		*mask = 0U;
		*pos = 0U;
		break;
	}
}
