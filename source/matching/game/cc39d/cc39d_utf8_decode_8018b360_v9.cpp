// Variant trials for 0x8018b360: live cursor with narrowed final expressions.
extern "C" unsigned short cc39d_utf8_c1(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned short high = (s[0] & 0x0f) << 12; s++;
        unsigned short middle = (s[0] & 0x3f) << 6; s++;
        unsigned short low = s[0] & 0x3f;
        return high | middle | low;
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_c2(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned short high = (*s++ & 0x0f) << 12;
        unsigned short middle = (*s++ & 0x3f) << 6;
        return high | middle | (*s & 0x3f);
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_c3(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned int high = (*s++ & 0x0f) << 12;
        unsigned int middle = (*s++ & 0x3f) << 6;
        return high | middle | (*s & 0x3f);
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_c4(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned int value = (*s++ & 0x0f) << 12;
        value |= (*s++ & 0x3f) << 6;
        return (unsigned short)(value | (*s & 0x3f));
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_c5(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        int high = (*s++ & 0x0f) << 12;
        int middle = (*s++ & 0x3f) << 6;
        return high | middle | (*s & 0x3f);
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_c6(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned char b0 = *s++;
        unsigned char b1 = *s++;
        unsigned char b2 = *s;
        return ((b0 & 0x0f) << 12) | ((b1 & 0x3f) << 6) | (b2 & 0x3f);
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_c7(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned int b0 = *s++;
        unsigned int b1 = *s++;
        unsigned int b2 = *s;
        return ((b0 & 0x0f) << 12) | ((b1 & 0x3f) << 6) | (b2 & 0x3f);
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_c8(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned short high = (*s++ & 0x0f) << 12;
        return high | ((*s++ & 0x3f) << 6) | (*s & 0x3f);
    }
    else { *length = 0; return 0; }
}
