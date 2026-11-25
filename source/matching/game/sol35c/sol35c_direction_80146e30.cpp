// Nonexact recovery experiment; no admission requested.
typedef struct { float x, y, z; } V3;
typedef struct { char p0[1152]; V3 src; char p1[40]; V3 dir; } Obj;
extern "C" V3 *fn_80141564(V3 *);
extern "C" float fn_802e82c0(float);
extern float lbl_803a0fec[];
extern float lbl_803a0ff0[];
extern "C" void sol35c_direction_80146e30(Obj *o) {
    V3 v = *fn_80141564(&o->src);
    V3 *pv = &v;
    float len2 = v.x * v.x + pv->y * pv->y + pv->z * pv->z;
    if (len2 > lbl_803a0fec[0]) {
        float inv = lbl_803a0ff0[0] / fn_802e82c0(len2);
        v.x = v.x * inv; pv->y = pv->y * inv; pv->z = pv->z * inv;
    } else {
        pv->z = lbl_803a0fec[0]; v.x=lbl_803a0fec[0];pv->y=lbl_803a0ff0[0];
    }
    o->dir = v;
}
