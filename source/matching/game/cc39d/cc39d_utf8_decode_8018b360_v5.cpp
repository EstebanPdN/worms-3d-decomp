// Variant trials for 0x8018b360: 16-bit result with parameter/local forms.
extern "C" unsigned short cc39d_utf8_p(const char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!((unsigned char)text[0] & 0x80)) { *length = 1; return (unsigned char)text[0]; }
    else if (((unsigned char)text[0] & 0xe0) == 0xc0) { *length = 2; return (((unsigned char)text[0] & 0x1f) << 6) | ((unsigned char)text[1] & 0x3f); }
    else if (((unsigned char)text[0] & 0xf0) == 0xe0) { *length = 3; return (((unsigned char)text[0] & 0x0f) << 12) | (((unsigned char)text[1] & 0x3f) << 6) | ((unsigned char)text[2] & 0x3f); }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_q(const unsigned char *text, int *length) {
    int local;
    if (length == 0) length = &local;
    if ((text[0] & 0x80) == 0) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) { *length = 3; return ((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f); }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_r(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    unsigned short value;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; value = text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; value = ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) { *length = 3; value = ((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f); }
    else { *length = 0; value = 0; }
    return value;
}
extern "C" unsigned short cc39d_utf8_s(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    unsigned int *out = length ? length : &local;
    if (!(text[0] & 0x80)) { *out = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *out = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) { *out = 3; return ((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f); }
    else { *out = 0; return 0; }
}
