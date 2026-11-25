static inline int k5b_nearly_equal(float a, float b)
{
    float difference = a - b;
    float limit = 0.01f;
    return (*(unsigned int *)&difference & 0x7fffffff) < *(unsigned int *)&limit;
}
int w3d_k5b_pairs_cancel_801f5da0(const float *values)
{
    if (k5b_nearly_equal(values[0], -values[1]) && k5b_nearly_equal(values[2], -values[3]))
        return 1;
    return 0;
}
// desc: w3d_k5b_pairs_cancel_801f5da0: Appears to return 1 when values[0] is within 0.01 of -values[1] and values[2] within 0.01 of -values[3] (sign-cleared bit compare).
