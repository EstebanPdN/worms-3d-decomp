/* GWMP8P rev0 0x80211c10. Erases a service from the map at +64 if present, then forwards to
 * the registry's table slot at +24. Real STLport 4.5.3 hash_map; the slot names are inferred. */
#include "game/d30s/d30s_guid_map.h"
struct D30sRegistryBase { virtual int s0(); virtual int s1(); virtual int s2(); virtual int attach(D30sIface *); virtual int detach(D30sIface *); };
struct D30sRegistry64 : D30sRegistryBase { char unknown[60]; D30sIfaceMap services; };
extern "C" int d30s_guid_map_detach_80211c10(D30sRegistry64 *self, D30sIface *service) {
    D30sIfaceMap &m = self->services;
    D30sIfaceMap::iterator it = m.find(w3d_auto_801fff3c(service));
    bool missing = it == m.end();
    if (!missing) m.erase(it);
    return self->detach(service);
}
