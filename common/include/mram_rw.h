/*
 * Copyright (c) 2024 Alif Semiconductor
 *
 * SPDX-License-Identifier: Apache-2.0
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
