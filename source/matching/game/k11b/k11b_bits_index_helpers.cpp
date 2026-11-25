// Two small helpers recovered from the 0x801f9fbc and 0x8021d7b0 area.

// Pointer vector view: only the begin and end pointers are used here.
struct K11bPointerVector {
    int *begin;
    int *end;
};

extern "C" {

// Appears to validate an index against the element count of a pointer
// vector. Selector modes 2 and 3 take the caller's index, modes 0 and 1
// select nothing, and every other mode is rejected. Returns -1 when no valid
// index was selected.
int w3d_k11b_checked_index_801f9fbc(const K11bPointerVector *vector, int mode, int index) {
    int position = -1;
    switch (mode) {
    case 0:
    case 1:
        position = -1;
        break;
    case 2:
        position = index;
        break;
    case 3:
        position = index;
        break;
    default:
        return -1;
    }
    if (position < 0 || (unsigned)position >= (unsigned)(vector->end - vector->begin))
        return -1;
    return position;
}

// Mirrors the low `count` bits of `bits`: bit i of the input becomes bit
// count-1-i of the result. The first argument is unused.
unsigned w3d_k11b_reverse_bits_8021d7b0(int unused, unsigned bits, int count) {
    unsigned result = 0;
    for (int i = 1; i < count + 1; i++) {
        if (bits & 1)
            result |= 1u << (count - i);
        bits >>= 1;
    }
    return result;
}

}
