#include "w3d_ptr.h"
#line 1 "e13p_count_matching_records_8008acd0.cpp"
// Recovered from the original DOL body at 0x8008acd0 (100 bytes).
//
// Counts records 0..3 whose kind byte at +0x3c equals the requested kind and
// whose state word at +0x2c is zero. Records come from the original indexed
// query function at 0x800fc7f8, which stays external until it is recovered.
//
// The loop index is deliberately initialised from the zero counter. Both
// initialisations are part of the original body's register allocation: GCC
// emits one zero constant and copies it into the index register, and that only
// happens when the index is assigned from the counter as well as from zero.
// The record layout is a partial view; offsets are observed, not recovered
// symbol names.

struct W3dRecordView {
    unsigned char unknown00[44];
    int state;                       // +0x2c
    unsigned char unknown30[12];
    unsigned char kind;              // +0x3c
};

extern "C" Ptr32<W3dRecordView> w3d_record_at_800fc7f8(unsigned int index);

extern "C" int w3d_count_matching_records_8008acd0(Ptr32<void> context, int wanted)
{
    int count = 0;
    unsigned int i = 0;
    i = (unsigned int)count;
    for (; i < 4; i++) {
        Ptr32<W3dRecordView> record = w3d_record_at_800fc7f8(i);
        if (record->kind == wanted && record->state == 0)
            count++;
    }
    return count;
}


