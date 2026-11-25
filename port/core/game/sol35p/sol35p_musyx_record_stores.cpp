#include "w3d_ptr.h"
#line 1 "sol35p_musyx_record_stores.cpp"
// Observed GameCube ABI layout; names and return types are inferred.
// Both entries leave the selected record address in r3. Callers observed so
// far use only the stores, so a public pointer-return API is not established.
typedef unsigned char u8;
typedef unsigned int u32;
struct Sol35pMusyxRecord {
    u8 unknown_0[28];
    u32 word_28;
    u8 unknown_32[128];
    u8 byte_160;
    u8 unknown_161[83];
};
typedef char sol35p_record_size[sizeof(Sol35pMusyxRecord)==244 ? 1 : -1];
extern Ptr32<Sol35pMusyxRecord> lbl_804b1744;
extern "C" Ptr32<Sol35pMusyxRecord> sol35p_musyx_store_word_80333ccc(u32 index,u32 value) {
    Ptr32<Sol35pMusyxRecord> record=lbl_804b1744+index;
    record->word_28=value;
    return record;
}
extern "C" Ptr32<Sol35pMusyxRecord> sol35p_musyx_store_byte_803340ec(u32 index,u32 value) {
    Ptr32<Sol35pMusyxRecord> record=lbl_804b1744+index;
    record->byte_160=(u8)value;
    return record;
}


