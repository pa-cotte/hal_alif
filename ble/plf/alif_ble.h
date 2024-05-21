/*
 * Copyright (c) 2023 Alif Semiconductor
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _ALIF_BLE_H
#define _ALIF_BLE_H

/**
 * @brief Enable the Alif BLE stack. This must be called before any other Alif BLE API calls.
 *
 * @param cb If non-NULL, the BLE stack initialisation will take place asynchronously and the
 *           provided callback function will be called when BLE is ready to use. If NULL, then
 *           initialisation takes place synchronously and this function call will block until BLE
 *           is ready.
 *
 * @return 0 on success, or error code
 */
int alif_ble_enable(void (*cb)(void));

#endif /* _ALIF_BLE_H */
