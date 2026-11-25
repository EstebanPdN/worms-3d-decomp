// desc: Appears to convert each unsigned integer of the source to a float in the destination for a given count and return zero.
int w3d_s21_convert_uint_to_float_8020e834(unsigned *src, int unused1, float *dst, int unused2, unsigned count)
{
    while (count--) {
        *dst++ = (float)*src++;
    }
    return 0;
}
