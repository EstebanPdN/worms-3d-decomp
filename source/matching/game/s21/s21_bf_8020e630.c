// desc: Appears to copy the low halfword of each source word into consecutive destination halfwords, as its sibling for a given count and return zero.
int w3d_s21_unpack_halves_b_8020e630(unsigned char *src, int unused1, unsigned short *dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = *(unsigned short *)(src + 2);
        src += 4;
    }
    return 0;
}
