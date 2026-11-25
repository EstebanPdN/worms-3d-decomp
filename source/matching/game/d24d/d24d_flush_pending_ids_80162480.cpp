// d24d: 0x80162480 (348 bytes). Flush a global pending id list: append every
// value of the list at 0x80455250 to the list at 0x80455244, then clear the
// pending list. Names are inferred from the shape.
#include "d24d_int_list_range.h"
extern d24d_RangeList d24d_ids_80455244, d24d_pending_80455250;

extern "C" void d24d_flush_pending_ids_80162480() {
    for (int *p = d24d_pending_80455250.start; p != d24d_pending_80455250.finish; ++p)
        d24d_ids_80455244.push_back(*p);
    d24d_pending_80455250.clear();
}
