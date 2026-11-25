// desc: Appears to widen each source byte to a boolean word in the destination for a given count and return zero.
int w3d_s21_unpack_bools_8020e590(unsigned char *src, int unused1, int *dst, int unused2, unsigned count)
{
    while (count--) {
        int value = 1;
        if (*src == 0)
            value = 0;
        *dst = value;
        dst++;
        src++;
    }
    return 0;
}
