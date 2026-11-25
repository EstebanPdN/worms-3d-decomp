// Variant trials for 0x8018b360: 16-bit code unit result (UCS-2), the
// counterpart of the admitted 16-bit encoder at 0x8018b2b0.
extern "C" unsigned short cc39d_utf8_n(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) { *length = 3; return ((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f); }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_o(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    if ((text[0] & 0xf0) != 0xe0) { *length = 0; return 0; }
    *length = 3;
    return ((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f);
}
