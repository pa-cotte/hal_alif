zephyr_include_directories(
  include
  plf
)

zephyr_sources(
  plf/alif_ble.c
  plf/hci_uart.c
  plf/host_timer_kernel.c
  plf/sync_timer.c
)

zephyr_link_libraries_ifdef(CONFIG_ALIF_BLE_HOST_PATCHING ${CONFIG_ALIF_BLE_HOST_PATCH_FILE})

# Add linker snippet for section of DTCM that is reserved for the host stack ROM code. SORT_KEY is
# used to place this after the LC3 codec reserved RAM but before any sections with default SORT_KEY
zephyr_linker_sources(RAM_SECTIONS SORT_KEY 001 ble_reserved_ram.ld)

zephyr_linker_sources_ifdef(CONFIG_ALIF_BLE_HOST_PATCHING SECTIONS ble_patch_info.ld)
zephyr_linker_sources_ifdef(CONFIG_ALIF_BLE_HOST_PATCHING RAM_SECTIONS ble_patch_ramable.ld)
