/* Fill the 256-entry unit-vector table 0x80431ea0 (0x8008f478): for each index, sums one
 * diagonal of the cube per set bit and normalizes the result unless it is the zero
 * vector 0x8045e788 (word comparison). Names are inferred. The unit owns its float
 * literals at 0x8037e7ac. */
extern "C" float w3d_sqrtf_802e82c0(float);
struct D24bVec3 {
    float x, y, z;
    D24bVec3() {}
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    void AddTo(D24bVec3 &o) const { o.x += x; o.y += y; o.z += z; }
};
struct D24bWords { int x, y, z; };
extern D24bVec3 w3d_zero_8045e788[];
extern D24bVec3 w3d_table_80431ea0[256];
inline int SameWords(const D24bVec3 &a, const D24bVec3 &b)
{
    const D24bWords &p = (const D24bWords &)a;
    const D24bWords &q = (const D24bWords &)b;
    return p.x == q.x && p.y == q.y && p.z == q.z;
}
extern "C" void w3d_d24b_fill_unit_table_8008f478()
{
    float zero = 0.0f;
    float one = 1.0f;
    float minusOne = -1.0f;
    D24bVec3 n;
    D24bVec3 *q = &n;
    D24bVec3 *out = w3d_table_80431ea0;
    D24bVec3 d;
    unsigned i = 0;
    D24bVec3 *p = &d;
    for (; i <= 255; i++) {
        n.x = zero;
        q->y = zero;
        q->z = zero;
        D24bVec3 *r = &n;
        if (i & 128) { d.x = one; p->y = one; p->z = one; d.AddTo(*r); }
        if (i & 64) { d.x = minusOne; p->y = one; p->z = one; d.AddTo(*r); }
        if (i & 32) { d.x = one; p->y = one; p->z = minusOne; d.AddTo(*r); }
        if (i & 16) { d.x = minusOne; p->y = one; p->z = minusOne; d.AddTo(*r); }
        if (i & 8) { d.x = one; p->y = minusOne; p->z = one; d.AddTo(*r); }
        if (i & 4) { d.x = minusOne; p->y = minusOne; p->z = one; d.AddTo(*r); }
        if (i & 2) { d.x = one; p->y = minusOne; p->z = minusOne; d.AddTo(*r); }
        if (i & 1) { d.x = minusOne; p->y = minusOne; p->z = minusOne; d.AddTo(*r); }
        if (!SameWords(*r, w3d_zero_8045e788[0])) {
            float k = one / w3d_sqrtf_802e82c0(n.x * n.x + q->y * q->y + q->z * q->z);
            n.x *= k;
            q->y *= k;
            q->z *= k;
        }
        {
            D24bWords *to = (D24bWords *)out;
            int wx = ((const D24bWords &)n).x, wy = ((const D24bWords *)q)->y, wz = ((const D24bWords *)q)->z;
            to->x = wx;
            to->y = wy;
            to->z = wz;
        }
        out++;
    }
}
