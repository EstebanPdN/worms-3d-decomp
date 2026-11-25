/* GWMP8P rev0 0x802124b4. Looks up a key in the map at +248; retains and releases the entry to
 * read its reference count, and when it held the only reference releases and erases it.
 * Returns 0, 1 when other references remain, or E_FAIL when absent. Real STLport 4.5.3 hash_map. */
#include "game/d30s/d30s_guid_map.h"
struct D30sRegistry248 { char unknown[248]; D30sIfaceMap services; };
inline int d30s_lookup(D30sIfaceMap &m, const D30sGuid *key, D30sIface **v) {
    D30sIfaceMap::iterator it = m.find(key);
    if (it == m.end()) return D30S_E_FAIL;
    *v = (*it).second;
    return 0;
}
inline int d30s_get(D30sIfaceMap &m, const D30sGuid *key, D30sIface **out) {
    D30sIface *v;
    int hr = d30s_lookup(m, key, &v);
    *out = v;
    return hr;
}
extern "C" int d30s_guid_map_release_last_802124b4(D30sRegistry248 *self, const D30sGuid *key) {
    D30sIface *p = 0;
    if (d30s_get(self->services, key, &p) < 0) return D30S_E_FAIL;
    int n = p->retain();
    p->release();
    if (n == 1) {
        p->release();
        D30sIfaceMap &m = self->services;
        D30sIfaceMap::iterator it = m.find(key);
        bool missing = it == m.end();
        if (!missing) m.erase(it);
    } else
        return 1;
    return 0;
}
