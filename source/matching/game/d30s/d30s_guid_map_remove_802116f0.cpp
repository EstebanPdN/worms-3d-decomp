/* GWMP8P rev0 0x802116f0. Erases a service's entry from the identifier map at +36;
 * returns 0, or E_FAIL when absent. Real STLport 4.5.3 hash_map (d30s_guid_map.h). */
#include "game/d30s/d30s_guid_map.h"
struct D30sRegistry36 { char unknown[36]; D30sIfaceMap services; };
extern "C" int d30s_guid_map_remove_802116f0(D30sRegistry36 *self, D30sIface *service) {
    return d30s_map_remove(self->services, w3d_auto_801fff3c(service));
}
