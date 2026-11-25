extern unsigned char *lbl_804ab8d0;
float w3d_k5b_fast_rsqrt_801f3fec(float x)
{
    union {
        float f;
        unsigned int i;
    } bits;
    float y;
    unsigned int i = *(unsigned int *)&x;
    bits.i = (((380 - ((i >> 23) & 0xff)) >> 1) << 23) | (lbl_804ab8d0[(i >> 17) & 0x7f] << 15);
    y = bits.f;
    y = (3.0f - y * y * x) * y * 0.5f;
    y = (3.0f - y * y * x) * y * 0.5f;
    return y;
}
// desc: w3d_k5b_fast_rsqrt_801f3fec: Appears to approximate 1/sqrt(x) from a 128-entry mantissa table at 0x804ab8d0 and the halved exponent, refined by two Newton steps.
