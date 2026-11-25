/* GWMP8P rev0 0x8035e070. hash_map default constructor from unmodified STLport 4.5.3 (100
 * buckets) for the 16-byte identifier map. The bucket vector and table members are admitted
 * at their own addresses. No hash or equality user constructor: the original's slot at sp+16 is
 * the compiler's copy of the empty functor. */
#include "compat/stlport_sn_oom.h"
#include <hash_map>
#include <string.h>
struct D30sGuid { unsigned w0, w1, w2, w3; };
struct D30sGuidKey { const D30sGuid *p; D30sGuidKey(const D30sGuid *q) : p(q) {} };
struct D30sGuidHash { unsigned operator()(const D30sGuidKey &g) const { return g.p->w0 + g.p->w2; } };
struct D30sGuidEq { bool operator()(const D30sGuidKey &a, const D30sGuidKey &b) const { return memcmp(a.p, b.p, 16) == 0; } };
struct D30sIface;
typedef std::hash_map<D30sGuidKey, D30sIface *, D30sGuidHash, D30sGuidEq> D30sIfaceMap;
typedef D30sIfaceMap::_Ht D30sIfaceTable;
typedef _STL::vector<void *, _STL::allocator<void *> > D30sBuckets;
template <> void D30sIfaceTable::clear();
template <> void D30sBuckets::reserve(unsigned);
template <> void D30sBuckets::_M_fill_insert(void **, unsigned, void *const &);
template <> D30sIfaceTable::size_type D30sIfaceTable::_M_next_size(D30sIfaceTable::size_type) const;
template D30sIfaceMap::hash_map();
