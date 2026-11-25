float w3d_k3b_math_mitchell_801d6bf0(float x)
{
    float a = x;
    float x2 = a * a;
    if (a < 0.0f)
        a = -a;
    if (a < 1.0f)
        return ((a * x2) * 7.0f + x2 * -12.0f + 5.3333335f) / 6.0f;
    if (a < 2.0f)
        return ((a * x2) * -2.3333333f + x2 * 12.0f + a * -20.0f + 10.666667f) / 6.0f;
    return 0.0f;
}
// desc: Appears to evaluate the Mitchell-Netravali cubic resampling kernel (B = C = 1/3) for |x| below two, otherwise zero.
