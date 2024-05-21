/* Linker snippet for BLE host reserved memory */
#include <zephyr/devicetree.h>

SECTION_PROLOGUE(.ble_host_reserved, DT_REG_ADDR_BY_IDX(DT_NODELABEL(dtcm_ble_host), 0) (NOLOAD),)
{
    __ble_host_reserved_start = .;
    . = . + DT_REG_SIZE_BY_IDX(DT_NODELABEL(dtcm_ble_host), 0);
    __ble_host_reserved_end = .;
} GROUP_LINK_IN(RAMABLE_REGION)
