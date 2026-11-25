/* GWMP8P rev0 0x802115f8. Stores a service under its 16-byte identifier in a real
 * STLport 4.5.3 hash_map and returns 0. The key class, its hash (words 0 and 2) and
 * its memcmp equality follow the original; class names are inferred. */
#include "compat/stlport_sn_oom.h"
#include <hash_map>
#include <string.h>
struct D30sGuid { unsigned w0, w1, w2, w3; };
struct D30sGuidKey { const D30sGuid *p; D30sGuidKey(const D30sGuid *q) : p(q) {} };
struct D30sGuidHash { unsigned operator()(const D30sGuidKey &g) const { return g.p->w0 + g.p->w2; } };
struct D30sGuidEq { bool operator()(const D30sGuidKey &a, const D30sGuidKey &b) const { return memcmp(a.p, b.p, 16) == 0; } };
struct D30sService;
typedef std::hash_map<D30sGuidKey, D30sService *, D30sGuidHash, D30sGuidEq> D30sServiceMap;
typedef D30sServiceMap::_Ht D30sServiceTable;
template <> D30sServiceTable::reference D30sServiceTable::_M_insert(const D30sServiceTable::value_type &);
extern "C" const D30sGuid *w3d_auto_801fff3c(D30sService *);
struct D30sRegistry { char unknown[36]; D30sServiceMap services; };
extern "C" int d30s_guid_map_add_802115f8(D30sRegistry *self, D30sService *service) {
    self->services[w3d_auto_801fff3c(service)] = service;
    return 0;
}
