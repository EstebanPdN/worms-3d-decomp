// desc: Appears to convert each signed integer of the source to a float in the destination for a given count and return zero.
int w3d_s21_convert_int_to_float_8020e9d0(int *src, int unused1, float *dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = (float)*src++;
    }
    return 0;
}
