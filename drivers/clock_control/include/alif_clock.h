/* SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2024 Alif Semiconductor.
 */

#ifndef ALIF_CLOCK_H_
#define ALIF_CLOCK_H_

#include <zephyr/sys/util_macro.h>

#define ALIF_CLOCK_SYST_ACLK_FREQ        400000000UL
#define ALIF_CLOCK_SYST_HCLK_FREQ        200000000UL
#define ALIF_CLOCK_SYST_PCLK_FREQ        100000000UL
#define ALIF_CLOCK_PLL_CLK3_FREQ         480000000UL
#define ALIF_CLOCK_HFOSC_CLK_FREQ        38400000UL
#define ALIF_CLOCK_S32K_CLK_FREQ         32768UL
#define ALIF_CLOCK_76M8_CLK_FREQ         76800000UL
#define ALIF_CLOCK_USB_CLK_FREQ          20000000UL
#define ALIF_CLOCK_160M_CLK_FREQ         160000000UL
#define ALIF_CLOCK_128K_CLK_FREQ         128000UL

#define ALIF_CAMERA_PIX_CLK_DIV_MASK     BIT_MASK(9U)
#define ALIF_CAMERA_PIX_CLK_DIV_POS      16U
#define ALIF_CDC200_PIX_CLK_DIV_MASK     BIT_MASK(9U)
#define ALIF_CDC200_PIX_CLK_DIV_POS      16U
#define ALIF_CSI_PIX_CLK_DIV_MASK        BIT_MASK(9U)
#define ALIF_CSI_PIX_CLK_DIV_POS         16U
#define ALIF_CANFD_CLK_DIV_MASK          BIT_MASK(8U)
#define ALIF_CANFD_CLK_DIV_POS           0U
#define ALIF_I2Sn_CLK_DIV_MASK           BIT_MASK(10U)
#define ALIF_I2Sn_CLK_DIV_POS            0U
#define ALIF_GPIOn_DB_CLK_DIV_MASK       BIT_MASK(10U)
#define ALIF_GPIOn_DB_CLK_DIV_POS        0U
#define ALIF_LPI2S_CLK_DIV_MASK          BIT_MASK(10U)
#define ALIF_LPI2S_CLK_DIV_POS           0U
#define ALIF_LPCPI_PIX_CLK_DIV_MASK      BIT_MASK(9U)
#define ALIF_LPCPI_PIX_CLK_DIV_POS       16U

/**
 * \fn        uint32_t get_input_clock(uint32_t clock_name)
 * \brief     get clock input frequency from clock name.
 * \param[in] clock_name name of clock device
 * \return    clock frequency
 */
uint32_t alif_get_input_clock(uint32_t clock_name);

/**
 * \fn        void alif_set_clock_divisor(uint32_t reg_addr, uint32_t mask,
 *                           uint32_t pos, uint32_t value)
 * \brief     set clock frequency divisor
 * \param[in] reg       pointer to register base
 * \param[in] mask      clock divisor bit mask
 * \param[in] pos       clock divisor bit position
 * \param[in] value     divisor value
 * \return    none
 */
void alif_set_clock_divisor(uint32_t *reg, uint32_t mask,
				uint32_t pos, uint32_t value);

/**
 * \fn        uint32_t alif_get_clock_divisor(uint32_t reg_addr,
 *                          uint32_t mask, uint32_t pos)
 * \brief     get clock frequency divisor
 * \param[in] reg       pointer to register base
 * \param[in] mask      clock divisor bit mask
 * \param[in] pos       clock divisor bit position
 * \return    clock divisor value
 */
uint32_t alif_get_clock_divisor(uint32_t *reg, uint32_t mask,
					uint32_t pos);

/**
 * \fn          void alif_get_div_reg_info(uint32_t clock_name,
 *                      uint32_t *mask, uint32_t *pos)
 * \brief       get clock divisor mask and bit position info in a register.
 * \param[in]   clock_name clock device name
 * \param[in]   mask       pointer to which div mask value is stored
 * \param[in]   pos        pointer to which div bit pos value is stored
 * \return      none
 */
void alif_get_div_reg_info(uint32_t clock_name, uint32_t *mask,
					uint32_t *pos);

#endif /* ALIF_CLOCK_H_ */
