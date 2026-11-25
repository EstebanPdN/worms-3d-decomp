// desc: Appears to convert each float of the source to an unsigned integer in the destination for a given count and return zero.
int w3d_s21_convert_float_to_uint_8020e7c0(float *src, int unused1, unsigned *dst, int unused2, unsigned count)
{
    while (count--) {
        *dst = (unsigned)*src;
        dst++;
        src++;
    }
    return 0;
}
