/* Light table setup (0x8008f7c4): fills the 256-entry table 0x80433760 with 1 for every
 * index whose high nibble has a bit set outside its low nibble, unless that masked value
 * is 0 or 0xf0, normalizes the first vectors of four records (0x804336a0, 0x804336b8,
 * 0x804336d0, 0x804336e8), halves them, then normalizes their second vectors (0x804336ac,
 * 0x804336c4, 0x804336dc, 0x804336f4) through 0x802e82c0. Names are inferred from the
 * original instructions. Owns the literals 1.0 and 0.5 at 0x8037e7b8. */
extern "C" float w3d_sqrt_802e82c0(float);
struct Vec3 {
    float x, y, z;
    void Normalize() {
        float k = 1.0f / w3d_sqrt_802e82c0(x * x + y * y + z * z);
        x *= k;
        y *= k;
        z *= k;
    }
};
extern int w3d_table_80433760[];
extern Vec3 w3d_v_804336a0[], w3d_v_804336b8[], w3d_v_804336d0[], w3d_v_804336e8[];
extern Vec3 w3d_v_804336ac[], w3d_v_804336c4[], w3d_v_804336dc[], w3d_v_804336f4[];
extern "C" void w3d_d26b_light_tables_8008f7c4()
{
    int *t = w3d_table_80433760;
    for (unsigned i = 0; i < 256; i++) {
        unsigned hi = i & 0xf0;
        unsigned lo = (i & 0xf) << 4;
        unsigned v = hi & ~lo;
        if (v != 0 && v != 0xf0) *t = 1;
        else *t = 0;
        t++;
    }
    w3d_v_804336a0[0].Normalize();
    w3d_v_804336b8[0].Normalize();
    w3d_v_804336d0[0].Normalize();
    w3d_v_804336e8[0].Normalize();
    const float s = 0.5f;
    w3d_v_804336a0[0].x *= s; w3d_v_804336a0[0].y *= s; w3d_v_804336a0[0].z *= s;
    w3d_v_804336b8[0].x *= s; w3d_v_804336b8[0].y *= s; w3d_v_804336b8[0].z *= s;
    w3d_v_804336d0[0].x *= s; w3d_v_804336d0[0].y *= s; w3d_v_804336d0[0].z *= s;
    w3d_v_804336e8[0].x *= s; w3d_v_804336e8[0].y *= s; w3d_v_804336e8[0].z *= s;
    w3d_v_804336ac[0].Normalize();
    w3d_v_804336c4[0].Normalize();
    w3d_v_804336dc[0].Normalize();
    w3d_v_804336f4[0].Normalize();
}
