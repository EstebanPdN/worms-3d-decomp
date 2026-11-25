// Variant trials for 0x8018b360: operand order and lead-byte local.
extern "C" unsigned int cc39d_utf8_e(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return (text[1] & 0x3f) | ((text[0] & 0x1f) << 6); }
    else if ((text[0] & 0xf0) == 0xe0) { *length = 3; return (text[2] & 0x3f) | (((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6)); }
    else { *length = 0; return 0; }
}
extern "C" unsigned int cc39d_utf8_f(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    unsigned char lead = text[0];
    if (!(lead & 0x80)) { *length = 1; return text[0]; }
    else if ((lead & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((lead & 0xf0) == 0xe0) { *length = 3; return ((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f); }
    else { *length = 0; return 0; }
}
extern "C" unsigned int cc39d_utf8_g(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!(*text & 0x80)) { *length = 1; return *text; }
    else if ((*text & 0xe0) == 0xc0) { *length = 2; return ((*text & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((*text & 0xf0) == 0xe0) { *length = 3; return ((*text & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f); }
    else { *length = 0; return 0; }
}
extern "C" unsigned int cc39d_utf8_h(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) { *length = 3; return (((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6)) | (text[2] & 0x3f); }
    else { *length = 0; return 0; }
}
extern "C" unsigned int cc39d_utf8_i(const char *text, int *length) {
    int local;
    if (!length) length = &local;
    if (!((unsigned char)text[0] & 0x80)) { *length = 1; return (unsigned char)text[0]; }
    else if (((unsigned char)text[0] & 0xe0) == 0xc0) { *length = 2; return (((unsigned char)text[0] & 0x1f) << 6) | ((unsigned char)text[1] & 0x3f); }
    else if (((unsigned char)text[0] & 0xf0) == 0xe0) { *length = 3; return (((unsigned char)text[0] & 0x0f) << 12) | (((unsigned char)text[1] & 0x3f) << 6) | ((unsigned char)text[2] & 0x3f); }
    else { *length = 0; return 0; }
}
