// desc: Appears to copy the last byte of each source word into consecutive destination bytes for a given count and return zero.
int w3d_s21_unpack_bytes_b_8020e5d0(unsigned char *src, int unused1, unsigned char *dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = src[3];
        src += 4;
    }
    return 0;
}
