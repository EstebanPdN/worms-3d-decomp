#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_a.c"
/* Small leaf accessors and predicates. */
extern float lbl_803af62c[];
extern float lbl_803af630[];
extern float lbl_803af634[];
extern float lbl_803af638[];

unsigned char w3d_s20_get_byte_slot_801a9b04(Ptr32<char> self, int index) {
    Ptr32<char> table = self + 304;
    return *(Ptr32<unsigned char>)(table + index);
}

int w3d_s20_set_byte_slot_801a9af4(Ptr32<char> self, int index, int value) {
    Ptr32<char> table = self + 304;
    *(Ptr32<char>)(table + index) = value;
    return 0;
}

int w3d_s20_clear_word_slot_801a314c(Ptr32<char> self, int index) {
    Ptr32<int> table = *(Ptr32<Ptr32<int>>)(self + 72);
    int offset = index * 4;
    *(Ptr32<int>)((Ptr32<char>)table + offset) = 0;
    return 0;
}

unsigned char w3d_s20_sum_bytes_80177e04(Ptr32<void> self, unsigned int value) {
    unsigned char a = value, b = value >> 8, c = value >> 16, d = value >> 24;
    return a + b + c + d;
}

unsigned char w3d_s20_sum_bytes_8017e1a0(Ptr32<void> self, unsigned int value) {
    unsigned char a = value, b = value >> 8, c = value >> 16, d = value >> 24;
    return a + b + c + d;
}

int w3d_s20_has_record_key_80199f68(Ptr32<char> self, int key) {
    Ptr32<char> record;
    for (record = *(Ptr32<Ptr32<char>>)(self + 32); record != *(Ptr32<Ptr32<char>>)(self + 36); record += 24) {
        if (*(Ptr32<unsigned short>)(record + 18) == key)
            return 1;
    }
    return 0;
}

float w3d_s20_evaluate_polynomial_80197244(Ptr32<float> coefficients, int degree, float x) {
    float result = coefficients[degree];
    degree--;
    for (; degree >= 0; degree--)
        result = x * result + coefficients[degree];
    return result;
}

float w3d_s20_select_band_801d69dc(Ptr32<void> self, float x) {
    if (x > lbl_803af62c[0] && x <= lbl_803af630[0])
        return lbl_803af634[0];
    return lbl_803af638[0];
}

int w3d_s20_any_handle_set_8013f844(Ptr32<char> self) {
    if (*(Ptr32<int>)(self + 144) != -1)
        return 1;
    if (*(Ptr32<int>)(self + 140) != -1)
        return 1;
    if (*(Ptr32<int>)(self + 148) != -1)
        return 1;
    return 0;
}

}
