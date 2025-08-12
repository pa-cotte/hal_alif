if(CONFIG_SOC_FAMILY_ENSEMBLE OR
   CONFIG_SOC_SERIES_ENSEMBLE_E1C OR
   CONFIG_SOC_SERIES_BALLETO)

    add_subdirectory(common)
    add_subdirectory(drivers)

    add_subdirectory_ifdef(CONFIG_HAS_ALIF_SE_SERVICES se_services)

    add_subdirectory_ifdef(CONFIG_ALIF_ROM_LC3_CODEC lc3)

    add_subdirectory_ifdef(CONFIG_IEEE802154_ALIF_SUPPORT ieee802154)

    add_subdirectory_ifdef(CONFIG_ALIF_BLE_HOST ble)
    add_subdirectory_ifdef(CONFIG_PM_RTSS drivers/pm)

endif()