#include "w3d_ptr.h"
#line 1 "d29s_push_keyed_record_801f99d8.cpp"
/* Builds a 24-byte keyed record from a default descriptor overwritten by the caller's
 * five-word value, appends it to the STLport vector and returns 0. */
#include "compat/stlport_sn_oom.h"
#include <vector>

struct D29sDescriptor_801f99d8 {
    int a, b, c, d, e;
    D29sDescriptor_801f99d8() : a(3), b(4), c(0), d(0) {}
};
struct D29sKeyed_801f99d8 {
    int key;
    D29sDescriptor_801f99d8 value;
    D29sKeyed_801f99d8() { key = 0; }
};

extern "C" int d29s_push_keyed_record_801f99d8(Ptr32<_STL::vector < D29sKeyed_801f99d8 >> records, int key, const D29sDescriptor_801f99d8 &value) {
    D29sKeyed_801f99d8 record;
    record.value = value;
    record.key = key;
    records->push_back(record);
    return 0;
}


