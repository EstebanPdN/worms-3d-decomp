// Variant trials for 0x8018b360: separate cursor for the three-byte case.
extern "C" unsigned short cc39d_utf8_t(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned short value = (s[0] & 0x0f) << 12;
        s++;
        value |= (s[0] & 0x3f) << 6;
        s++;
        return value | (s[0] & 0x3f);
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_u(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(*s & 0x80)) { *length = 1; return *text; }
    else if ((*s & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((*s & 0xf0) == 0xe0) { *length = 3; return ((s[0] & 0x0f) << 12) | ((s[1] & 0x3f) << 6) | (s[2] & 0x3f); }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_v(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    unsigned char lead = *text;
    if (!(lead & 0x80)) { *length = 1; return *text; }
    else if ((lead & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((lead & 0xf0) == 0xe0) { *length = 3; return ((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f); }
    else { *length = 0; return 0; }
}
