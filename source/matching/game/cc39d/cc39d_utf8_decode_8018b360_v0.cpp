// Decoder counterpart of the admitted encoder at 0x8018b2b0. Reads one UTF-8
// sequence of one, two or three bytes; continuation bytes are not validated.
// Any other lead byte yields length 0 and value 0. A local receives the
// length when no output is supplied. Original names unknown.
extern "C" unsigned int cc39d_utf8_decode_8018b360(const unsigned char *text, unsigned int *length) {
    unsigned int local;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    if ((text[0] & 0xf0) != 0xe0) { *length = 0; return 0; }
    *length = 3;
    return ((text[0] & 0x0f) << 12) | ((text[1] & 0x3f) << 6) | (text[2] & 0x3f);
}
