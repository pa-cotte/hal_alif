zephyr_include_directories(
  include
  zephyr/include
)

zephyr_library()

zephyr_library_sources(zephyr/src/se_service.c)
