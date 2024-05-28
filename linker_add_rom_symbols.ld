/*
 * SPDX-License-Identifier: Apache-2.0
 */


#include <zephyr/linker/sections.h>
#include <zephyr/devicetree.h>

#include <zephyr/linker/linker-defs.h>
#include <zephyr/linker/linker-tool.h>

#include <zephyr/arch/arm/cortex_m/scripts/linker.ld>

/* Symbols in ROM */
#include "lc3/rom_symbols_lc3.lds"

#include "ble/rom_symbols_ble.lds"

