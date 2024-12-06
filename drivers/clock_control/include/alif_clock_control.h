/* SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2024 Alif Semiconductor.
 */

#ifndef ALIF_CLOCK_CONTROL_H_
#define ALIF_CLOCK_CONTROL_H_

#include <zephyr/sys/util_macro.h>

#define ALIF_CAMERA_PIX_CLK_DIV_MASK     BIT_MASK(9U)
#define ALIF_CAMERA_PIX_CLK_DIV_POS      16U
#define ALIF_CDC200_PIX_CLK_DIV_MASK     BIT_MASK(9U)
#define ALIF_CDC200_PIX_CLK_DIV_POS      16U
#define ALIF_CSI_PIX_CLK_DIV_MASK        BIT_MASK(9U)
#define ALIF_CSI_PIX_CLK_DIV_POS         16U
#define ALIF_CANFD0_CLK_DIV_MASK         BIT_MASK(8U)
#define ALIF_CANFD0_CLK_DIV_POS          0U
#define ALIF_CANFD1_CLK_DIV_MASK         BIT_MASK(8U)
#define ALIF_CANFD1_CLK_DIV_POS          16U
#define ALIF_I2S_CLK_DIV_MASK            BIT_MASK(10U)
#define ALIF_I2S_CLK_DIV_POS             0U
#define ALIF_GPIO_DB_CLK_DIV_MASK        BIT_MASK(10U)
#define ALIF_GPIO_DB_CLK_DIV_POS         0U
#define ALIF_LPI2S_CLK_DIV_MASK          BIT_MASK(10U)
#define ALIF_LPI2S_CLK_DIV_POS           0U
#define ALIF_LPCPI_PIX_CLK_DIV_MASK      BIT_MASK(9U)
#define ALIF_LPCPI_PIX_CLK_DIV_POS       16U


/**
 * \fn        void alif_set_clock_divisor(uint32_t *reg, uint32_t mask,
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
 * \fn        uint32_t alif_get_clock_divisor(uint32_t *reg,
 *                          uint32_t mask, uint32_t pos)
 * \brief     get clock frequency divisor
 * \param[in] reg       pointer to register base
 * \param[in] mask      clock divisor bit mask
 * \param[in] pos       clock divisor bit position
 * \return    clock divisor value
 */
uint32_t alif_get_clock_divisor(uint32_t *reg, uint32_t mask,
					uint32_t pos);

#endif /* ALIF_CLOCK_CONTROL_H_ */
