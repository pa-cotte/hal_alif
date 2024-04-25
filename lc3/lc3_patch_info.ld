/* Linker snippet for LC3 codec patch info to be placed in read-only memory. */

SECTION_PROLOGUE(.lc3_patch_info,,)
{
    __lc3_patch_info_start = .;
    KEEP(*(._lc3_patch_info));
    . = ALIGN(16);
    __lc3_patch_info_end = .;
} GROUP_LINK_IN(ROMABLE_REGION)
