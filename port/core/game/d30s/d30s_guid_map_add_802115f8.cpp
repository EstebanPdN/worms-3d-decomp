#include "w3d_ptr.h"
#line 1 "d30s_guid_map_add_802115f8.cpp"
/* GWMP8P rev0 0x802115f8. Stores a service under its 16-byte identifier in a real
 * STLport 4.5.3 hash_map and returns 0. The key class, its hash (words 0 and 2) and
 * its memcmp equality follow the original; class names are inferred. */
#include "compat/stlport_sn_oom.h"
#include <hash_map>
#include <string.h>
struct D30sGuid { unsigned w0, w1, w2, w3; };
struct D30sGuidKey { Ptr32<const D30sGuid> p; template <class W3dU> D30sGuidKey(Ptr32<W3dU> w3d_p) : D30sGuidKey((const D30sGuid *)w3d_p.get()) {}
 D30sGuidKey(const D30sGuid *q) : p(q) {} };
struct D30sGuidHash { unsigned operator()(const D30sGuidKey &g) const { return g.p->w0 + g.p->w2; }  char w3d_empty; };
struct D30sGuidEq { bool operator()(const D30sGuidKey &a, const D30sGuidKey &b) const { return memcmp(a.p, b.p, 16) == 0; }  char w3d_empty; };
struct D30sService;
typedef _STL::hash_map <D30sGuidKey, Ptr32<D30sService>, D30sGuidHash, D30sGuidEq > D30sServiceMap;
typedef D30sServiceMap::_Ht D30sServiceTable;
template <> D30sServiceTable::reference D30sServiceTable::_M_insert(const D30sServiceTable::value_type &);
extern "C" Ptr32<const D30sGuid> w3d_auto_801fff3c(Ptr32<D30sService>);
struct D30sRegistry { char unknown[36]; D30sServiceMap services; };
extern "C" int d30s_guid_map_add_802115f8(Ptr32<D30sRegistry> self, Ptr32<D30sService> service) {
    self->services[w3d_auto_801fff3c(service)] = service;
    return 0;
}


