zephyr_include_directories(include)

zephyr_library_sources_ifdef(CONFIG_HAS_ALIF_POWER_MANAGER
    src/es0_power_manager.c
)

zephyr_library_sources_ifdef(CONFIG_DT_HAS_ALIF_MRAM_FLASH_CONTROLLER_ENABLED
    src/mram_rw.c
)
