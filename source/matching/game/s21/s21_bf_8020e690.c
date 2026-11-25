// desc: Appears to copy each source word into consecutive destination words, as its sibling for a given count and return zero.
int w3d_s21_unpack_words_b_8020e690(unsigned char *src, int unused1, unsigned *dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = *(unsigned *)src;
        src += 4;
    }
    return 0;
}
