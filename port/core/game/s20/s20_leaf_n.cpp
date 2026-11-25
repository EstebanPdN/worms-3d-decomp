#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_n.c"
/* Flag bit, matrix and vector copies, record search and counting. */
typedef struct S20Vec { float x; float y; float z; } S20Vec;
typedef struct S20Mat4 { float m[12]; } S20Mat4;
typedef struct S20FlagObject { Ptr32<Ptr32<void>> vtable; unsigned int pad; unsigned int low:1; unsigned int high:31; } S20FlagObject;
typedef Ptr32<int (Ptr32<void>)> S20Call0;

int w3d_s20_set_low_bit_801865c0(Ptr32<S20FlagObject> self, int value) {
    if (value == self->low)
        return 0;
    self->low = value;
    return ((Ptr32<int (Ptr32<void>, int)>)self->vtable[39])(self, value);  /* el PPC deja r4 intacto: 0x8017b15c lo recibe */
}

int w3d_s20_set_matrix_80186614(Ptr32<char> self, Ptr32<S20Mat4> value) {
    *(Ptr32<S20Mat4>)(self + 56) = *value;
    return 0;
}

int w3d_s20_set_vectors_8018993c(Ptr32<char> self, Ptr32<S20Vec> first, Ptr32<S20Vec> second) {
    Ptr32<char> inner = *(Ptr32<Ptr32<char>>)(*(Ptr32<Ptr32<char>>)(self + 168) + 48);
    *(Ptr32<S20Vec>)(inner + 120) = *first;
    *(Ptr32<S20Vec>)(inner + 108) = *second;
    return 0;
}

typedef struct S20Record { char pad0[18]; unsigned short key; char pad1[4]; } S20Record;

Ptr32<S20Record> w3d_s20_find_record_8019a2a8(Ptr32<char> self, int key) {
    Ptr32<S20Record> record;
    for (record = *(Ptr32<Ptr32<S20Record>>)(self + 32); record != *(Ptr32<Ptr32<S20Record>>)(self + 36); record++) {
        if (record->key == key)
            return record;
    }
    for (record = *(Ptr32<Ptr32<S20Record>>)(self + 48); record != *(Ptr32<Ptr32<S20Record>>)(self + 52); record++) {
        if (record->key == key)
            return record;
    }
    return 0;
}

typedef struct S20Entry { char pad0[6]; unsigned short slot; unsigned int flags; char pad1[264]; } S20Entry;
extern unsigned short lbl_804b18ac;
extern Ptr32<S20Entry> lbl_804b18b0;

void w3d_s20_count_active_entries_8018a800(Ptr32<int> counts) {
    unsigned short i;
    for (i = 0; i < lbl_804b18ac; i++) {
        Ptr32<S20Entry> entry = (Ptr32<S20Entry>)w3d::G((i * 276 + (int)w3d::H(lbl_804b18b0)));
        int active = 1;
        if ((entry->flags & 0xfffe) == 0)
            active = 0;
        if (active)
            counts[entry->slot] += 1;
    }
}

}
