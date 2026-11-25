#include "w3d_ptr.h"
#line 1 "d24d_resize_entries_801920b8.cpp"
// d24d: 0x801920b8 (180 bytes). Resize the owner's entry vector (+20) to the
// given count with a default entry as the fill value, then store the count
// (+76). Shrinking destroys the tail entries; growing calls the fill routine
// 0x8034cc3c. That routine witnesses the eight-byte stride and the attribute
// bytes at +4, +5 and the halfword at +6; the string constructor 0x803426b8
// writes only the text word.
#define D24D_FILL_INSERT d24d_fill_insert_8034cc3c
template<class T> struct d24d_Vector;
struct d24d_Entry;
extern "C" void D24D_FILL_INSERT(Ptr32<d24d_Vector < d24d_Entry >>, Ptr32<d24d_Entry>, unsigned, const d24d_Entry &);
#include "d24d_string_vector.h"
struct d24d_Entry {
    d24d_String_803426b8 text;
    unsigned char a, b;
    unsigned short c;
};
struct d24d_Owner {
    unsigned char unknown00[20];
    d24d_Vector<d24d_Entry> entries;     // +20
    unsigned char unknown24[40];
    unsigned count;                      // +76
};

extern "C" void d24d_resize_entries_801920b8(Ptr32<d24d_Owner> self, unsigned count) {
    self->entries.resize(count);
    self->count = count;
}


