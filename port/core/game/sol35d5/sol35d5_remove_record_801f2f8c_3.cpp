#include "w3d_ptr.h"
#line 1 "sol35d5_remove_record_801f2f8c_3.cpp"
// Inferred pair-key record collection, based on the complete original 184-byte body.
// GC32 address arithmetic follows the native byte-copy count. The external
// transfer at 802eee50 must support the original downward overlapping ranges;
// allocation ownership, object lifetime and cross-boundary aliasing stay external.
// The flag position is observed; its semantic name and complete classes are hypotheses.
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, unsigned, ...);
struct Record { unsigned first,second,third; };
struct Records {
    Ptr32<Record> begin; Ptr32<Record> end; Ptr32<Record> capacity;
    bool erase(Ptr32<Record> position) {
        if (position + 1 != end)
            fn_802eee50(position,position+1,(unsigned)w3d::H(end) + (-12 - (unsigned)w3d::H(position)));
        --end;
        return begin == end;
    }
};
struct Flags { unsigned int rest:29; unsigned int empty:1; unsigned int high:2; };
struct Owner { unsigned prefix[8]; Flags flags; unsigned unknown; Records records; };
extern "C" unsigned sol35d5_remove_record_801f2f8c_3(Ptr32<Owner> owner, unsigned first,unsigned second) {
    Ptr32<Record> last=owner->records.end;
    Ptr32<Record> p=owner->records.begin;
    for (;p!=last;++p) {
        if (p->first==first && p->second==second) {
            owner->flags.empty=owner->records.erase(p);
            return 0;
        }
    }
    return 0x80004005u;
}
typedef char RecordSize[sizeof(Record)==12?1:-1];
typedef char BeginOffset[__builtin_offsetof(Owner,records.begin)==40?1:-1];
typedef char EndOffset[__builtin_offsetof(Owner,records.end)==44?1:-1];
typedef char FlagOffset[__builtin_offsetof(Owner,flags)==32?1:-1];


