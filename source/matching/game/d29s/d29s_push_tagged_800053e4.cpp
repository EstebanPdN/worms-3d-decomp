/* Appends a pointer to one of 1024 STLport vectors chosen by a hash of the object's
 * 16-bit id at +2, then counts it. */
#include "compat/stlport_sn_oom.h"
#include <vector>

struct D29sTagged_800053e4 { short pad; short id; };
typedef std::vector<D29sTagged_800053e4 *> D29sBucket_800053e4;
struct D29sBuckets_800053e4 { D29sBucket_800053e4 slot[1024]; int count; };

extern "C" void d29s_push_tagged_800053e4(D29sBuckets_800053e4 *table, D29sTagged_800053e4 *item) {
    int id = item->id;
    int hash = id + ((id << 5) + id);
    D29sBucket_800053e4 *bucket = table->slot + (hash & 0x3ff);
    bucket->push_back(item);
    table->count++;
}
