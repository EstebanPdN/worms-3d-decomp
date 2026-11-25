/* GWMP8P rev0 0x802123b0. Releases the given interface, then erases its key from the
 * map at +248; returns 0, or E_FAIL when absent. Real STLport 4.5.3 hash_map. */
#include "game/d30s/d30s_guid_map.h"
struct D30sRegistry248 { char unknown[248]; D30sIfaceMap services; };
extern "C" int d30s_guid_map_release_remove_802123b0(D30sRegistry248 *self, const D30sGuid *key, D30sIface *service) {
    service->release();
    return d30s_map_remove(self->services, key);
}
