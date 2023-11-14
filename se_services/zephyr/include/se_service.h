#ifndef SE_SERVICES_ZEPHYR_INCLUDE_SE_SERVICE_H_
#define SE_SERVICES_ZEPHYR_INCLUDE_SE_SERVICE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/device.h>
#include <services_lib_api.h>
#include <services_lib_ids.h>

int se_service_heartbeat(void);
int se_service_sync(void);
int se_service_get_rnd_num(uint8_t *,uint16_t);
int se_service_get_toc_number(uint32_t *);
int se_service_get_se_revision(uint8_t *);
int se_service_get_device_part_number(uint32_t *);

#ifdef __cplusplus
}
#endif
#endif /* SE_SERVICES_ZEPHYR_INCLUDE_SE_UTILITIES_H_ */
