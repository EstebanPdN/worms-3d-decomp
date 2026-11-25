#include "w3d_ptr.h"
#line 1 "f4c_normalize_801f6c2c.cpp"
// Structural matrix representation and helper roles are inferred.
extern "C" Ptr32<void> fn_801f6cb8(Ptr32<float>, Ptr32<const float>);
extern "C" float fn_801f70b0(Ptr32<float>);
extern const float lbl_803b16dc[];
extern "C" int f4c_normalize_801f6c2c(Ptr32<float> matrix, Ptr32<const float> input) {
    fn_801f6cb8(matrix, input);
    float divisor = fn_801f70b0(matrix);
    if (__builtin_fabsf(divisor) < lbl_803b16dc[0]) return (int)0x80004005;
    for (int row = 0; row <= 3; ++row)
        for (int column = 0; column < 4; ++column)
            matrix[row * 4 + column] /= divisor;
    return 0;
}


