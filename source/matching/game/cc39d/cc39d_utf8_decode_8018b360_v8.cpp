// Variant trials for 0x8018b360: two-byte operand order with cursor forms.
extern "C" unsigned short cc39d_utf8_At(const unsigned char *text, unsigned int *length) {
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
extern "C" unsigned short cc39d_utf8_Ax(const unsigned char *text, unsigned int *length) {
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
        return (s[0] & 0x3f) | value;
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_Ay(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned int value = (*s++ & 0x0f) << 12;
        value |= (*s++ & 0x3f) << 6;
        value |= *s & 0x3f;
        return value;
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_Az2(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned short value = (*s++ & 0x0f) << 12;
        value |= (*s++ & 0x3f) << 6;
        return (*s & 0x3f) | value;
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_Bt(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return (text[1] & 0x3f) | ((text[0] & 0x1f) << 6); }
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
extern "C" unsigned short cc39d_utf8_Bx(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return (text[1] & 0x3f) | ((text[0] & 0x1f) << 6); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned short value = (s[0] & 0x0f) << 12;
        s++;
        value |= (s[0] & 0x3f) << 6;
        s++;
        return (s[0] & 0x3f) | value;
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_By(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return (text[1] & 0x3f) | ((text[0] & 0x1f) << 6); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned int value = (*s++ & 0x0f) << 12;
        value |= (*s++ & 0x3f) << 6;
        value |= *s & 0x3f;
        return value;
    }
    else { *length = 0; return 0; }
}
extern "C" unsigned short cc39d_utf8_Bz2(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    const unsigned char *s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return (text[1] & 0x3f) | ((text[0] & 0x1f) << 6); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned short value = (*s++ & 0x0f) << 12;
        value |= (*s++ & 0x3f) << 6;
        return (*s & 0x3f) | value;
    }
    else { *length = 0; return 0; }
}
