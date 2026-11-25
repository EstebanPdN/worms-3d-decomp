/* Service registry maps, real STLport 4.5.3 hash_map keyed on a 16-byte identifier.
 * The bucket hash (words 0 and 2), the 16-byte memcmp and one-word key copies come from
 * the original; the class names and the Interface slot names are inferred. */
#ifndef D30S_GUID_MAP_H
#define D30S_GUID_MAP_H
#include "compat/stlport_sn_oom.h"
#include <hash_map>
#include <string.h>
struct D30sGuid { unsigned w0, w1, w2, w3; };
struct D30sGuidKey { Ptr32<const D30sGuid> p; template <class W3dU> D30sGuidKey(Ptr32<W3dU> w3d_p) : D30sGuidKey((const D30sGuid *)w3d_p.get()) {}
 D30sGuidKey(const D30sGuid *q) : p(q) {} };
struct D30sGuidHash { unsigned operator()(const D30sGuidKey &g) const { return g.p->w0 + g.p->w2; }  char w3d_empty; };
struct D30sGuidEq { bool operator()(const D30sGuidKey &a, const D30sGuidKey &b) const { return memcmp(a.p, b.p, 16) == 0; }  char w3d_empty; };
struct D30sIface {
    int w3d_r_query() __asm__(W3D_SYM("_ZN9D30sIface5queryEv"));
    int w3d_r_retain() __asm__(W3D_SYM("_ZN9D30sIface6retainEv"));
    int w3d_r_release() __asm__(W3D_SYM("_ZN9D30sIface7releaseEv"));
 __attribute__((always_inline)) inline int query() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sIface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int retain() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sIface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int release() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D30sIface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D30sIface; };
typedef _STL::hash_map <D30sGuidKey, Ptr32<D30sIface>, D30sGuidHash, D30sGuidEq > D30sIfaceMap;
typedef D30sIfaceMap::_Ht D30sIfaceTable;
template <> D30sIfaceTable::reference D30sIfaceTable::_M_insert(const D30sIfaceTable::value_type &);
template <> void D30sIfaceTable::erase(const D30sIfaceTable::const_iterator &);
extern "C" Ptr32<const D30sGuid> w3d_auto_801fff3c(Ptr32<D30sIface>);
enum { D30S_E_FAIL = 0x80004005 };
/* Erases the key if present. */
inline int d30s_map_remove(D30sIfaceMap &m, Ptr32<const D30sGuid> key) {
    D30sIfaceMap::iterator it = m.find(key);
    int hr;
    bool missing = it == m.end();
    if (missing) hr = D30S_E_FAIL;
    else { m.erase(it); hr = 0; }
    return hr;
}
#endif
