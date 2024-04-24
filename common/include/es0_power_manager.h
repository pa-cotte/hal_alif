/* Copyright (C) 2023 Alif Semiconductor - All Rights Reserved.
 * Use, distribution and modification of this code is permitted under the
 * terms stated in the Alif Semiconductor Software License Agreement
 *
 * You should have received a copy of the Alif Semiconductor Software
 * License Agreement with this file. If not, please write to:
 * contact@alifsemi.com, or visit: https://alifsemi.com/license
 *
 */
#ifndef __ES0_POWER_MANAGER_H__
#define __ES0_POWER_MANAGER_H__

#include <stdint.h>
/*
 * This class is taking care of power modes of the available system cores.
 * It will also take care of the users of a specific core and when last user
 * stops using the core, it will be shutdown to save power.
 */

enum core_error_t {
	ALIF_PM_ERROR_COUNTER_CORRUPTED = -2,
	ALIF_PM_ERROR_FAILED = -1,
	ALIF_PM_ERROR_NONE = 0
};

#define BD_ADDRESS_LENGTH 6

/**
 * @brief Register a user of a ES0
 * @return  -1 If too many users
 *          -2 If calculated size of boot params > 512
 *          -3 If calculated size of boot params differs from actual size.
 *          -4 Starting ES0 failed
 */
int8_t take_es0_into_use(void);

/**
 * @brief De-register a user of a ES0
 * @return  -1 If no active users
 *          -2 Shutdown of ES0 failed
 */
int8_t stop_using_es0(void);

#endif /* __ES0_POWER_MANAGER_H__ */
