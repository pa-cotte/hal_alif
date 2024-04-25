
zephyr_include_directories(include)
zephyr_include_directories(
  ieee802154/include
  ieee802154/src
)
zephyr_sources(src/alif_ahi.c src/alif_mac154_api.c)

set(MAC154_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib802154.a)
zephyr_link_libraries(${MAC154_LIB})
