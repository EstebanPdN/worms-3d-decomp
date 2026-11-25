// Partial views of tiny Dolphin SDK style accessors found between the OS and
// GX layers. Global names are the original small-data addresses; record
// layouts show only the offsets these functions touch.
extern "C" {

struct K11bWordPair {
    int first;   // offset 0
    int second;  // offset 4
};

struct K11bRecordA {
    int unknown0[3];
    int field_0c;  // offset 12, copied from another record's first word
    int unknown10[1];
    int field_14;  // offset 20
};

struct K11bRecordB {
    int unknown0[33];
    int field_84;  // offset 132
    int field_88;  // offset 136
};

extern int lbl_804ac5e4;                 // swapped through k11b_swap_value_802f778c
extern int lbl_804b1258;                 // set to 1 by k11b_raise_flag_80300c18
extern int lbl_804b1294;                 // plain word read back
extern int lbl_804b1318;                 // plain word read back
extern unsigned short lbl_804b1448;      // plain halfword read back

// Replaces the stored value and returns the previous one.
int w3d_k11b_swap_value_802f778c(int value) {
    int previous = lbl_804ac5e4;
    lbl_804ac5e4 = value;
    return previous;
}

// Zeroes the first word, then the second.
void w3d_k11b_clear_pair_802ffcf8(K11bWordPair *pair) {
    pair->first = 0;
    pair->second = 0;
}

// Zeroes the second word, then the first.
void w3d_k11b_clear_pair_802f9f64(K11bWordPair *pair) {
    pair->second = 0;
    pair->first = 0;
}

void w3d_k11b_raise_flag_80300c18() {
    lbl_804b1258 = 1;
}

int w3d_k11b_get_word_80304c00() {
    return lbl_804b1294;
}

int w3d_k11b_get_word_80306cb8() {
    return lbl_804b1318;
}

void w3d_k11b_copy_first_word_803096a4(K11bRecordA *dest, const int *source) {
    dest->field_0c = source[0];
}

int w3d_k11b_get_field_14_8030a080(const K11bRecordA *record) {
    return record->field_14;
}

unsigned short w3d_k11b_get_half_80314840() {
    return lbl_804b1448;
}

int w3d_k11b_get_field_88_80314bd4(const K11bRecordB *record) {
    return record->field_88;
}

int w3d_k11b_get_field_84_80314fd8(const K11bRecordB *record) {
    return record->field_84;
}

}
