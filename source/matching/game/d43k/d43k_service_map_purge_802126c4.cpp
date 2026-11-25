// GWMP8P rev0 0x802126c4. Releases services nothing else references. Walks
// the registry's hash map, asks each object for its reference count through
// retain and release, copies still-referenced entries to a new map, drops
// the rest, then replaces the map and repeats while anything was dropped,
// since a release can free other references. Real STLport 4.5.3 hash_map
// keyed on a 16-byte identifier (d30s_guid_map.h). Member names are
// inferred.
#include "game/d30s/d30s_guid_map.h"
template <> D30sIfaceMap::hash_map();
template <> void D30sIfaceTable::_M_copy_from(const D30sIfaceTable &);
template <> void D30sIfaceTable::clear();
struct D43kServiceMap : D30sIfaceMap { D43kServiceMap() {} };
struct D43kRegistry {
    char unknown_0[248];
    D43kServiceMap services;
    D30sIface *ObjectAt(int index) const {
        D30sIfaceMap::const_iterator it = services.begin();
        while (index != 0 && it != services.end()) { ++it; --index; }
        return it != services.end() ? (*it).second : 0;
    }
    D30sGuidKey KeyAt(int index) const {
        D30sIfaceMap::const_iterator it = services.begin();
        while (index != 0 && it != services.end()) { ++it; --index; }
        bool found = it != services.end();
        D30sGuidKey key(0);
        if (found) key = (*it).first;
        return key;
    }
};
extern "C" int w3d_d43k_service_map_purge_802126c4(D43kRegistry *self) {
    bool again;
    do {
        D43kServiceMap kept;
        again = false;
        unsigned count = self->services.size();
        for (unsigned i = 0; i < count; i++) {
            D30sIface *object = self->ObjectAt(i);
            int others = object->retain() - 1;
            object->release();
            if (others) {
                kept[self->KeyAt(i)] = object;
            } else {
                object->release();
                again = true;
            }
        }
        self->services.clear();
        self->services = kept;
    } while (again);
    return 0;
}
