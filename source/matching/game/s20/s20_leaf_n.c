/* Flag bit, matrix and vector copies, record search and counting. */
typedef struct S20Vec { float x; float y; float z; } S20Vec;
typedef struct S20Mat4 { float m[12]; } S20Mat4;
typedef struct S20FlagObject { void **vtable; unsigned int pad; unsigned int high : 31; unsigned int low : 1; } S20FlagObject;
typedef int (*S20Call0)(void *);

int w3d_s20_set_low_bit_801865c0(S20FlagObject *self, int value) {
    if (value == self->low)
        return 0;
    self->low = value;
    return ((S20Call0)self->vtable[39])(self);
}

int w3d_s20_set_matrix_80186614(char *self, S20Mat4 *value) {
    *(S20Mat4 *)(self + 56) = *value;
    return 0;
}

int w3d_s20_set_vectors_8018993c(char *self, S20Vec *first, S20Vec *second) {
    char *inner = *(char **)(*(char **)(self + 168) + 48);
    *(S20Vec *)(inner + 120) = *first;
    *(S20Vec *)(inner + 108) = *second;
    return 0;
}

typedef struct S20Record { char pad0[18]; unsigned short key; char pad1[4]; } S20Record;

S20Record *w3d_s20_find_record_8019a2a8(char *self, int key) {
    S20Record *record;
    for (record = *(S20Record **)(self + 32); record != *(S20Record **)(self + 36); record++) {
        if (record->key == key)
            return record;
    }
    for (record = *(S20Record **)(self + 48); record != *(S20Record **)(self + 52); record++) {
        if (record->key == key)
            return record;
    }
    return 0;
}

typedef struct S20Entry { char pad0[6]; unsigned short slot; unsigned int flags; char pad1[264]; } S20Entry;
extern unsigned short lbl_804b18ac;
extern S20Entry *lbl_804b18b0;

void w3d_s20_count_active_entries_8018a800(int *counts) {
    unsigned short i;
    for (i = 0; i < lbl_804b18ac; i++) {
        S20Entry *entry = (S20Entry *)(i * 276 + (int)lbl_804b18b0);
        int active = 1;
        if ((entry->flags & 0xfffe) == 0)
            active = 0;
        if (active)
            counts[entry->slot] += 1;
    }
}
