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

zephyr_linker_sources_ifdef(CONFIG_ALIF_BLE_HOST_PATCHING SECTIONS ble_patch_info.ld)
zephyr_linker_sources_ifdef(CONFIG_ALIF_BLE_HOST_PATCHING RAM_SECTIONS ble_patch_ramable.ld)
