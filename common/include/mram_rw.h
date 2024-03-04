/* Copyright (C) 2023 Alif Semiconductor - All Rights Reserved.
 * Use, distribution and modification of this code is permitted under the
 * terms stated in the Alif Semiconductor Software License Agreement
 *
 * You should have received a copy of the Alif Semiconductor Software
 * License Agreement with this file. If not, please write to:
 * contact@alifsemi.com, or visit: https://alifsemi.com/license
 *
 */
#ifndef MRAM_RW_H
#define MRAM_RW_H

#ifdef __cplusplus
extern "C" {
#endif

int write_16bytes(uint8_t *, uint8_t *);
int erase_16bytes(uint8_t *);

#ifdef __cplusplus
}
#endif
#endif /* MRAM_RW_H */
