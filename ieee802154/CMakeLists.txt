
zephyr_include_directories(include)
zephyr_include_directories(
  ieee802154/include
  ieee802154/src
)
zephyr_sources(src/alif_ahi.c src/alif_mac154_api.c)

if(CONFIG_OPENTHREAD)
  zephyr_sources(src/alif_ot_plf.c)
endif()

set(MAC154_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib802154.a)

if(CONFIG_FPU)
    if(CONFIG_FP_HARDABI)
      set(MAC154_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib802154_hf.a)
    endif()
endif()

zephyr_link_libraries(${MAC154_LIB})
