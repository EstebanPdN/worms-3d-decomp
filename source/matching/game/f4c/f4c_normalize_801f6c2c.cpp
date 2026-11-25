// Structural matrix representation and helper roles are inferred.
extern "C" void * fn_801f6cb8(float *, const float *);
extern "C" float fn_801f70b0(float *);
extern const float lbl_803b16dc[];
extern "C" int f4c_normalize_801f6c2c(float *matrix, const float *input) {
    fn_801f6cb8(matrix, input);
    float divisor = fn_801f70b0(matrix);
    if (__builtin_fabsf(divisor) < lbl_803b16dc[0]) return (int)0x80004005;
    for (int row = 0; row <= 3; ++row)
        for (int column = 0; column < 4; ++column)
            matrix[row * 4 + column] /= divisor;
    return 0;
}
