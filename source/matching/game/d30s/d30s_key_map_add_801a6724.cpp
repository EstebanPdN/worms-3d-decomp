/* GWMP8P rev0 0x801a6724. Adds a value to the real STLport 4.5.3 map at +76: E_FAIL if the key
 * exists, otherwise stores it and returns 0. */
#include "compat/stlport_sn_oom.h"
#include <map>
typedef std::map<unsigned, int> D30sKeyMap;
typedef D30sKeyMap::_Rep_type D30sKeyTree;
template <> D30sKeyTree::iterator D30sKeyTree::insert_unique(D30sKeyTree::iterator, const D30sKeyTree::value_type &);
struct D30sKeyOwner { char unknown[76]; D30sKeyMap values; };
extern "C" int d30s_key_map_add_801a6724(D30sKeyOwner *self, unsigned key, int value) {
    D30sKeyMap::const_iterator i = self->values.find(key);
    if (i != self->values.end()) return 0x80004005;
    self->values[key] = value;
    return 0;
}
