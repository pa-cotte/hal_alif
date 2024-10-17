/* SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (C) 2024 Alif Semiconductor.
 */

#include <stdint.h>
#include <soc_memory_map.h>

uint64_t ethosu_address_remap(uint64_t address, int index)
{
	(void)index;

	/* Double cast to avoid build warning about pointer/integer size mismatch */
	return local_to_global((void *) (uint32_t) address);
}

