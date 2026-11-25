/* Service registry maps, real STLport 4.5.3 hash_map keyed on a 16-byte identifier.
 * The bucket hash (words 0 and 2), the 16-byte memcmp and one-word key copies come from
 * the original; the class names and the Interface slot names are inferred. */
#ifndef D30S_GUID_MAP_H
#define D30S_GUID_MAP_H
#include "compat/stlport_sn_oom.h"
#include <hash_map>
#include <string.h>
struct D30sGuid { unsigned w0, w1, w2, w3; };
struct D30sGuidKey { const D30sGuid *p; D30sGuidKey(const D30sGuid *q) : p(q) {} };
struct D30sGuidHash { unsigned operator()(const D30sGuidKey &g) const { return g.p->w0 + g.p->w2; } };
struct D30sGuidEq { bool operator()(const D30sGuidKey &a, const D30sGuidKey &b) const { return memcmp(a.p, b.p, 16) == 0; } };
struct D30sIface {
    virtual int query();
    virtual int retain();
    virtual int release();
};
typedef std::hash_map<D30sGuidKey, D30sIface *, D30sGuidHash, D30sGuidEq> D30sIfaceMap;
typedef D30sIfaceMap::_Ht D30sIfaceTable;
template <> D30sIfaceTable::reference D30sIfaceTable::_M_insert(const D30sIfaceTable::value_type &);
template <> void D30sIfaceTable::erase(const D30sIfaceTable::const_iterator &);
extern "C" const D30sGuid *w3d_auto_801fff3c(D30sIface *);
enum { D30S_E_FAIL = 0x80004005 };
/* Erases the key if present. */
inline int d30s_map_remove(D30sIfaceMap &m, const D30sGuid *key) {
    D30sIfaceMap::iterator it = m.find(key);
    int hr;
    bool missing = it == m.end();
    if (missing) hr = D30S_E_FAIL;
    else { m.erase(it); hr = 0; }
    return hr;
}
#endif
