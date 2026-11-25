// Variant trials for 0x8018b360: second pointer variable for the
// three-byte case (r11) while the argument stays in r3 elsewhere.
extern "C" unsigned int cc39d_utf8_j(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *p = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) { *length = 3; return ((p[0] & 0x0f) << 12) | ((p[1] & 0x3f) << 6) | (p[2] & 0x3f); }
    else { *length = 0; return 0; }
}
static inline unsigned int cc39d_utf8_three(const unsigned char *p) {
    return ((p[0] & 0x0f) << 12) | ((p[1] & 0x3f) << 6) | (p[2] & 0x3f);
}
extern "C" unsigned int cc39d_utf8_k(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) { *length = 3; return cc39d_utf8_three(text); }
    else { *length = 0; return 0; }
}
extern "C" unsigned int cc39d_utf8_l(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) { const unsigned char *p = text; *length = 3; return ((p[0] & 0x0f) << 12) | ((p[1] & 0x3f) << 6) | (p[2] & 0x3f); }
    else { *length = 0; return 0; }
}
extern "C" unsigned int cc39d_utf8_m(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *p = text;
    if (!length) length = &local;
    if (!(*p & 0x80)) { *length = 1; return *text; }
    else if ((*p & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((*p & 0xf0) == 0xe0) { *length = 3; return ((p[0] & 0x0f) << 12) | ((p[1] & 0x3f) << 6) | (p[2] & 0x3f); }
    else { *length = 0; return 0; }
}
