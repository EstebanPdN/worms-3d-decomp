// Polynomial sine and cosine through a 16-bit angle (Worms 3D GameCube PAL, 0x801f3db0).
//
// Maps the angle plus pi (0x803b0e94) to 16 bits by the factor 0x803b0e98
// (65536 / 2 pi), folds it to one quadrant, and evaluates two polynomials in
// the reduced value (constants 0x803b0ea8..0x803b0ebc). Unit-owned data is the
// compiler's int-to-float conversion constant.
extern const float constant_803b0e94[], constant_803b0e98[], constant_803b0ea8[], constant_803b0eac[], constant_803b0eb0[], constant_803b0eb4[], constant_803b0eb8[], constant_803b0ebc[];
extern "C" void w3d_d24e_sin_cos_801f3db0(float angle, float *outSin, float *outCos) {
    int n = (int)((angle + constant_803b0e94[0]) * constant_803b0e98[0]);
    n &= 0xffff;
    int t = n - 32768;
    n = t;
    if (t < 0) n = -t;
    float s, c;
    if (n <= 16383) {
        int w = (unsigned short)n; float x = (float)w * constant_803b0ea8[0];
        float x2 = x * x;
        float v = ((x2 * constant_803b0eac[0] - constant_803b0eb0[0]) * x2 + constant_803b0eb4[0]) * x;
        if (n < 0) v = -v;
        s = v;
        c = (x2 * constant_803b0eb8[0] - constant_803b0ebc[0]) * x2 + constant_803b0eb4[0];
    } else {
        n -= 16384;
        int w = (unsigned short)n; float x = (float)w * constant_803b0ea8[0];
        float x2 = x * x;
        s = (x2 * constant_803b0eb8[0] - constant_803b0ebc[0]) * x2 + constant_803b0eb4[0];
        c = ((x2 * constant_803b0eac[0] - constant_803b0eb0[0]) * x2 + constant_803b0eb4[0]) * x;
        if (n >= 0) c = -c;
    }
    *outCos = c;
    if (t < 0) *outSin = -s;
    else *outSin = s;
}
