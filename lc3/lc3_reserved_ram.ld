/* Linker snippet for LC3 codec reserved memory */
#include <zephyr/devicetree.h>

SECTION_PROLOGUE(.lc3_codec_reserved, DT_REG_ADDR_BY_IDX(DT_NODELABEL(dtcm_lc3_codec), 0) (NOLOAD),)
{
    __lc3_codec_reserved_start = .;
    . = . + DT_REG_SIZE_BY_IDX(DT_NODELABEL(dtcm_lc3_codec), 0);
    __lc3_codec_reserved_end = .;
} GROUP_LINK_IN(RAMABLE_REGION)
