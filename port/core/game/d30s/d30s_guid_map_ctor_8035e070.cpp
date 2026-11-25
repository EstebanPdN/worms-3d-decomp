#include "w3d_ptr.h"
#line 1 "d30s_guid_map_ctor_8035e070.cpp"
/* GWMP8P rev0 0x8035e070. hash_map default constructor from unmodified STLport 4.5.3 (100
 * buckets) for the 16-byte identifier map. The bucket vector and table members are admitted
 * at their own addresses. No hash or equality user constructor: the original's slot at sp+16 is
 * the compiler's copy of the empty functor. */
#include "compat/stlport_sn_oom.h"
#include <hash_map>
#include <string.h>
struct D30sGuid { unsigned w0, w1, w2, w3; };
struct D30sGuidKey { Ptr32<const D30sGuid> p; template <class W3dU> D30sGuidKey(Ptr32<W3dU> w3d_p) : D30sGuidKey((const D30sGuid *)w3d_p.get()) {}
 D30sGuidKey(const D30sGuid *q) : p(q) {} };
struct D30sGuidHash { unsigned operator()(const D30sGuidKey &g) const { return g.p->w0 + g.p->w2; }  char w3d_empty; };
struct D30sGuidEq { bool operator()(const D30sGuidKey &a, const D30sGuidKey &b) const { return memcmp(a.p, b.p, 16) == 0; }  char w3d_empty; };
struct D30sIface;
typedef _STL::hash_map <D30sGuidKey, Ptr32<D30sIface>, D30sGuidHash, D30sGuidEq > D30sIfaceMap;
typedef D30sIfaceMap::_Ht D30sIfaceTable;
typedef _STL::vector <Ptr32<void>, _STL::allocator <Ptr32<void> > > D30sBuckets;
template <> void D30sIfaceTable::clear();
template <> void D30sBuckets::reserve(unsigned);
template <> void D30sBuckets::_M_fill_insert(Ptr32<Ptr32<void>>, unsigned, Ptr32<void> const &);
template <> D30sIfaceTable::size_type D30sIfaceTable::_M_next_size(D30sIfaceTable::size_type) const;
template D30sIfaceMap::hash_map();


