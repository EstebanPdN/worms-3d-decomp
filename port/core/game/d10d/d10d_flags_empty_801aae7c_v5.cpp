#include "w3d_ptr.h"
#line 1 "d10d_flags_empty_801aae7c_v5.cpp"
// Flag-table emptiness test (0x801aae7c). The first argument is unused.
// A zero count in the owner record (+100, count at +24) gives 1; an empty
// table (+96, length at +24) gives 0; otherwise the result is 1 only when
// every flag byte (+32, one per table entry) is zero.
// One counter holds the owner count and then the set-flag count. The length
// is read once for the empty test, and the loop bound rereads it from the
// table (loop-invariant motion turns that into a register copy).
// Partial observed views; the full types and sizeof are unknown.
struct d10d_FlagOwner { unsigned char unknown00[24]; unsigned int count; };
struct d10d_FlagTable { unsigned char unknown00[24]; unsigned int length; unsigned char unknown1c[4]; unsigned char flags[1]; };
struct d10d_FlagQuery { unsigned char unknown00[96]; Ptr32<d10d_FlagTable> table; Ptr32<d10d_FlagOwner> owner; };

extern "C" int d10d_flags_empty_801aae7c(Ptr32<void> unused, Ptr32<d10d_FlagQuery> query) {
    Ptr32<d10d_FlagOwner> owner = query->owner;
    Ptr32<d10d_FlagTable> table = query->table;
    unsigned int length = table->length;
    Ptr32<unsigned char> flags = table->flags;
    unsigned int n = owner->count;
    if (n == 0) return 1;
    if (length == 0) return 0;
    n = 0;
    for (unsigned int i = 0; i < table->length; i++)
        if (flags[i]) n++;
    return n == 0;
}


