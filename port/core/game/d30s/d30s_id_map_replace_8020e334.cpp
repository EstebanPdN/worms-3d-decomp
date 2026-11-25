#include "w3d_ptr.h"
#line 1 "d30s_id_map_replace_8020e334.cpp"
/* GWMP8P rev0 0x8020e334. Stores a value under the key built from two objects' halfword ids in
 * the real STLport 4.5.3 map at +20 and returns the value it replaced, or null. */
#include "compat/stlport_sn_oom.h"
#include <map>
typedef _STL::map <unsigned int, Ptr32<void> > D30sPairMap;
typedef D30sPairMap::_Rep_type D30sPairTree;
template <> D30sPairTree::iterator D30sPairTree::insert_unique(D30sPairTree::iterator, const D30sPairTree::value_type &);
struct D30sNamed { char unknown[8]; unsigned short id; };
struct D30sPairOwner { char unknown[20]; D30sPairMap values; };
extern "C" Ptr32<void> d30s_id_map_replace_8020e334(Ptr32<D30sPairOwner> self, Ptr32<const D30sNamed> a, Ptr32<const D30sNamed> b, Ptr32<void> value) {
    unsigned key = (a->id << 16) | b->id;
    Ptr32<void> old = 0;
    D30sPairMap::iterator i = self->values.find(key);
    if (i != self->values.end()) {
        old = (*i).second;
        (*i).second = value;
    } else
        self->values[key] = value;
    return old;
}


