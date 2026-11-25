#include "w3d_ptr.h"
#line 1 "d29s_push_own_short_801a9b10.cpp"
/* Appends the owner's own 16-bit record at +304 to its vector at +308. The record
 * is a class, not a bare short: the original copies it element by element and
 * runs an empty destroy loop, which trivial STLport element traits would omit. */
#include "compat/stlport_sn_oom.h"
#include <vector>

struct D29sShortRecord_801a9b10 { unsigned short value; };
struct D29sOwner_801a9b10 {
    char head[304];
    D29sShortRecord_801a9b10 record;
    std::vector<D29sShortRecord_801a9b10> records;
};

extern "C" void d29s_push_own_short_801a9b10(Ptr32<D29sOwner_801a9b10> owner) {
    owner->records.push_back(owner->record);
}


