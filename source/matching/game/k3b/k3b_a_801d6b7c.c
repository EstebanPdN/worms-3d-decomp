extern float w3d_math_sinc_801d6b24(float x);
float w3d_k3b_math_lanczos3_801d6b7c(float x)
{
    float a = x;
    float r = 0.0f;
    if (a < 0.0f)
        a = -a;
    if (a < 3.0f)
        r = w3d_math_sinc_801d6b24(a) * w3d_math_sinc_801d6b24(a / 3.0f);
    return r;
}
// desc: Appears to evaluate the Lanczos window kernel with radius three: sinc(x) * sinc(x/3) for |x| below three, otherwise zero.
