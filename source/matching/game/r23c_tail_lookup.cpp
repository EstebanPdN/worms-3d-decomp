// Worms 3D PAL GWMP8P rev0; inferred names and partial layouts.
// These leaf helpers have no unresolved external calls or global references.
typedef unsigned int r23c_u32;
typedef unsigned char r23c_u8;
struct r23c_Row {
    r23c_u32 unknown0[3];
    r23c_u32 value;          // +0x0c
    r23c_u32 unknown16[2];
    r23c_u32 *entries;       // +0x18; row stride 0x20
    r23c_u32 unknown28;
};
struct r23c_Lookup {
    r23c_u8 unknown0[24];
    r23c_Row *rows;          // +0x18
    r23c_u8 unknown28[52];
    r23c_u32 *entries;       // +0x50
    r23c_u8 unknown84[16];
    r23c_u32 fallback;       // +0x64
};
// Unsigned address arithmetic expresses the original 32-bit index addition.
// This cast depends on the reference pointer width and is a future port boundary.
extern "C" r23c_u32 r23c_indexed_entry_803486f0(r23c_Lookup *self, r23c_u32 index) {
    return *(r23c_u32 *)((index << 2) + (r23c_u32)self->entries);
}
extern "C" r23c_u32 r23c_row_entry_80348c64(r23c_Lookup *self, r23c_u32 row, r23c_u32 index) {
    return *(r23c_u32 *)((index << 2) +
        (r23c_u32)((r23c_Row *)((char *)self->rows + (row << 5)))->entries);
}
extern "C" r23c_u32 r23c_row_value_80348d74(r23c_Lookup *self, r23c_u32 row) {
    r23c_u32 value;
    if (row) value = ((r23c_Row *)((char *)self->rows + (row << 5)))->value;
    else value = self->fallback;
    return value;
}
// Valid half-open sorted word range; signed element count and unsigned comparison.
extern "C" const r23c_u32 *r23c_lower_bound_8035c4d0(
    const r23c_u32 *first, const r23c_u32 *last, const r23c_u32 *key) {
    int count = last - first;
    while (count > 0) {
        int half = count >> 1;
        const r23c_u32 *middle = first + half;
        if (*middle < *key) {
            first = middle + 1;
            count = (count - half) - 1;
        } else count = half;
    }
    return first;
}
