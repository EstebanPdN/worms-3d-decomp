// desc: Appears to convert each float of the source to a signed integer in the destination for a given count and return zero.
int w3d_s21_convert_float_to_int_8020e98c(float *src, int unused1, int *dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = (int)*src++;
    }
    return 0;
}
