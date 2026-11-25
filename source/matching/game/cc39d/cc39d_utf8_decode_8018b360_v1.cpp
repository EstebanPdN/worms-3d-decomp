// Variant trials (one function per hypothesis) for 0x8018b360.
extern "C" unsigned int cc39d_utf8_a(const unsigned char *text, unsigned int *length) {
    unsigned int local; unsigned int value;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; value = text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; value = (text[1] & 0x3f) | ((text[0] & 0x1f) << 6); }
    else if ((text[0] & 0xf0) != 0xe0) { *length = 0; value = 0; }
    else { *length = 3; value = (text[2] & 0x3f) | (((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6)); }
    return value;
}
extern "C" unsigned int cc39d_utf8_b(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    if ((text[0] & 0xe0) == 0xc0) { *length = 2; return (text[1] & 0x3f) | ((text[0] & 0x1f) << 6); }
    if ((text[0] & 0xf0) == 0xe0) { *length = 3; return (text[2] & 0x3f) | (((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6)); }
    *length = 0; return 0;
}
extern "C" unsigned int cc39d_utf8_c(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) { *length = 3; return ((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f); }
    else { *length = 0; return 0; }
}
extern "C" unsigned int cc39d_utf8_d(const unsigned char *text, unsigned int *length) {
    unsigned int local; unsigned int value;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; value = text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; value = ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) { *length = 3; value = ((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f); }
    else { *length = 0; value = 0; }
    return value;
}
