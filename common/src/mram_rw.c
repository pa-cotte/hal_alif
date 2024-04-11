/* Copyright (C) 2023 Alif Semiconductor - All Rights Reserved.
 * Use, distribution and modification of this code is permitted under the
 * terms stated in the Alif Semiconductor Software License Agreement
 *
 * You should have received a copy of the Alif Semiconductor Software
 * License Agreement with this file. If not, please write to:
 * contact@alifsemi.com, or visit: https://alifsemi.com/license
 *
 */
#include <stdint.h>
#include <string.h>
#include <cmsis_core.h>
#include <errno.h>
#include <zephyr/cache.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(mram_rw, CONFIG_SOC_LOG_LEVEL);

#define MRAM_UNIT_SECTOR_SIZE      16

/**
 * @brief write 16 bytes of data into MRAM
 *
 * @param dst Pointer containing MRAM address where data is written.
 * @param src Pointer to source containing data to be written.
 *
 * @return 0 if successful.
 * @return -EINVAL if dst is not 16 bytes aligned address.
 */
int write_16bytes(uint8_t *dst, uint8_t *src)
{
	if((uint32_t) dst & 0x0000000F)
	{
		LOG_ERR("Address %p must be %d bytes aligned for MRAM write\n",
			dst, MRAM_UNIT_SECTOR_SIZE);
		return -EINVAL;
	}
	uint32_t tmp_buf[4] = {0};
	__disable_irq();
	if((uint32_t) src & 0x0000000F)
	{
		memcpy(tmp_buf, src, MRAM_UNIT_SECTOR_SIZE);
		((volatile uint64_t *)dst)[0] =
					((volatile uint64_t *)tmp_buf)[0];
		((volatile uint64_t *)dst)[1] =
					((volatile uint64_t *)tmp_buf)[1];
	}
	else
	{
		((volatile uint64_t *)dst)[0] = ((volatile uint64_t *)src)[0];
		((volatile uint64_t *)dst)[1] = ((volatile uint64_t *)src)[1];
	}
	__asm__ volatile ("dmb 0xF":::"memory");
#if defined(CONFIG_CACHE_MANAGEMENT)
	sys_cache_data_flush_range(dst, MRAM_UNIT_SECTOR_SIZE);
#endif
	__enable_irq();
	return 0;
}
/**
 * @brief erase 16 bytes of MRAM
 *
 * @param dst Pointer containing MRAM address for erase.
 *
 * @return 0 if successful.
 * @return -EINVAL if dst is not 16 bytes aligned address.
 */
int erase_16bytes(uint8_t *dst)
{
	if((uint32_t) dst & 0x0000000F)
	{
		LOG_ERR("Address %p must be %d bytes aligned for MRAM write\n",
			dst, MRAM_UNIT_SECTOR_SIZE);
		return -EINVAL;
	}
	__disable_irq();
	((volatile uint64_t *)dst)[0] = 0x0;
	((volatile uint64_t *)dst)[1] = 0x0;
	__asm__ volatile ("dmb 0xF":::"memory");
#if defined(CONFIG_CACHE_MANAGEMENT)
	sys_cache_data_flush_range(dst, MRAM_UNIT_SECTOR_SIZE);
#endif
	__enable_irq();
	return 0;
}
