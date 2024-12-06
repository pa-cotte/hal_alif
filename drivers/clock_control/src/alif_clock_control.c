/* SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2024 Alif Semiconductor.
 */

#include <stdint.h>
#include "alif_clock_control.h"

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
