// Mitchell-Netravali cubic reconstruction filter with B = C = 1/3
// (0x801d6bf0), trials.
extern "C" float d10d_ma(float x) {
    float x2 = x * x;
    if (x < 0.0f) x = -x;
    if (x < 1.0f)
        return (x * x2 * 7.0f + x2 * -12.0f + 5.33333333f) / 6.0f;
    if (x < 2.0f)
        return (x * x2 * -2.33333333f + x2 * 12.0f + x * -20.0f + 10.6666667f) / 6.0f;
    return 0.0f;
}

extern "C" float d10d_mb(float x) {
    float x2 = x * x;
    if (x < 0.0f) x = -x;
    if (x < 1.0f)
        return (7.0f * (x * x2) + -12.0f * x2 + 5.33333333f) / 6.0f;
    else if (x < 2.0f)
        return (-2.33333333f * (x * x2) + 12.0f * x2 + -20.0f * x + 10.6666667f) / 6.0f;
    else
        return 0.0f;
}
