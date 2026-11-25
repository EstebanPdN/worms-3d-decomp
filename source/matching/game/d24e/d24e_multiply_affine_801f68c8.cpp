// Multiplies a packed 4x3 affine matrix by a 4x4 matrix (Worms 3D GameCube PAL, 0x801f68c8).
//
// out[i] = a[i].x * b[0] + a[i].y * b[1] + a[i].z * b[2] for the three rotation
// rows; the translation row also adds b[3]. Operands may alias. The array index
// operators keep the original's indexed loads.
struct V3 { float x, y, z; };
struct R4 { float v[4]; const float &operator[](int j) const { return v[j]; } float &operator[](int j) { return v[j]; } };
struct M4 { R4 r[4]; const R4 &operator[](int i) const { return r[i]; } R4 &operator[](int i) { return r[i]; } };
struct M3 { V3 r[4]; const V3 &operator[](int i) const { return r[i]; } };
extern "C" void w3d_d24e_multiply_affine_801f68c8(M4 &out, const M3 &a, const M4 &b) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            out.r[i].v[j] = a[i].x * b.r[0].v[j] + a[i].y * b.r[1].v[j] + a[i].z * b.r[2].v[j];
    for (int j = 0; j < 4; ++j)
        out.r[3].v[j] = a[3].x * b.r[0].v[j] + a[3].y * b.r[1].v[j] + a[3].z * b.r[2].v[j] + b.r[3].v[j];
}
