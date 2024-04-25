zephyr_include_directories(include)

zephyr_link_libraries_ifdef(CONFIG_ALIF_LC3_CODEC_PATCHING ${CONFIG_ALIF_LC3_CODEC_PATCH_FILE})

# Add linker snippet for section of DTCM that is reserved for the LC3 codec ROM code. SORT_KEY is
# used to place this at the start of DTCM.
zephyr_linker_sources(RAM_SECTIONS SORT_KEY 000 lc3_reserved_ram.ld)

zephyr_linker_sources_ifdef(CONFIG_ALIF_LC3_CODEC_PATCHING SECTIONS lc3_patch_info.ld)
zephyr_linker_sources_ifdef(CONFIG_ALIF_LC3_CODEC_PATCHING RAM_SECTIONS lc3_patch_ramable.ld)
