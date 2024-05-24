/*
 * Copyright (c) 2024 Alif Semiconductor
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <openthread/instance.h>

uint32_t otPlatRadioGetBusSpeed(otInstance *aInstance)
{
	OT_UNUSED_VARIABLE(aInstance);
	/* Adjusting openthread timing based on radio bus speed*/
	return 250000;
}
