#include "w3d_ptr.h"
#line 1 "d30s_record_map_get_80205654.cpp"
/* GWMP8P rev0 0x80205654. Returns the record for a key in the real STLport 4.5.3 map at +44,
 * inserting a new record (id set to the key, count zero, two words left uninitialized) if absent. */
#include "compat/stlport_sn_oom.h"
#include <map>
struct D30sCountRecord { unsigned id; int count; unsigned a, b; };
typedef std::map<unsigned, D30sCountRecord> D30sRecordMap;
typedef D30sRecordMap::_Rep_type D30sRecordTree;
template <> _STL::pair<D30sRecordTree::iterator, bool> D30sRecordTree::insert_unique(const D30sRecordTree::value_type &);
struct D30sRecordOwner { char unknown[44]; D30sRecordMap records; };
extern "C" Ptr32<D30sCountRecord> d30s_record_map_get_80205654(Ptr32<D30sRecordOwner> self, unsigned key) {
    D30sRecordMap::iterator i;
    i = self->records.find(key);
    if (i == self->records.end()) {
        D30sCountRecord r;
        r.id = key;
        r.count = 0;
        i = self->records.insert(D30sRecordMap::value_type(key, r)).first;
    }
    return &(*i).second;
}


