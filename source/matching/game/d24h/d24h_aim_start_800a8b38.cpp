// Airstrike AI start (Worms 3D GameCube PAL, 0x800a8b38, 456 bytes).
//
// Field names are inferred from the setting names in the original data.
// The unit owns its literal pool at 0x803818e8.

struct Vec3 {
    float x, y, z;
    Vec3() {}
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    float DistSq(const Vec3 &o) const { float dx = x - o.x, dy = y - o.y, dz = z - o.z; return dx * dx + dy * dy + dz * dz; }
};
struct Key {
    const char *name;
    Key(const char *n) { name = n; }
};
extern "C" int fn_800fc2f0(Key *, Vec3 *);
extern "C" int fn_800fc230(Key *, int *);
extern "C" int fn_800fc5dc(Key *, Vec3 *);
extern "C" int fn_800fc43c(Key *, int);
extern "C" float fn_802e7e5c(float, float);
extern "C" void fn_800a93fc(void *);
struct Arena;
extern Arena *lbl_804b1754;
extern "C" void *fn_801613f0(Arena *, unsigned);
extern "C" void *fn_80131b50(void *, int);
extern "C" int fn_8016239c(void *);
extern const char lbl_80381840[], lbl_80381854[], lbl_8038186c[], lbl_80381880[], lbl_80381898[], lbl_803818a8[], lbl_803818bc[], lbl_803818d0[];
struct Aim {
    unsigned char u0[16];
    Vec3 pos;      // +16
    Vec3 target;   // +28
    unsigned char u40[36];
    float speed;   // +76
    float yaw;     // +80
    unsigned char u84[12];
    Vec3 goal;     // +96
};
extern "C" void w3d_d24h_aim_start_800a8b38(Aim *self) {
    Vec3 where;
    Vec3 dir;
    Key k1(lbl_80381854);
    fn_800fc2f0(&k1, &where);
    Key k2(lbl_8038186c);
    fn_800fc2f0(&k2, &dir);
    Key k3(lbl_80381840);
    int active;
    fn_800fc230(&k3, &active);
    if (active == 0) return;
    self->speed = 1.5707964f;
    self->goal = where;
    self->target.Set(0.0f, 1.0f, 0.0f);
    self->yaw = fn_802e7e5c(dir.y, dir.x);
    fn_800a93fc(self);
    if (self->pos.DistSq(where) < 10.0f) {
        Key k4(lbl_80381880);
        fn_800fc5dc(&k4, &where);
        Key k5(lbl_80381898);
        fn_800fc5dc(&k5, &where);
        Key k6(lbl_803818a8);
        fn_800fc5dc(&k6, &dir);
        Key k7(lbl_803818bc);
        fn_800fc43c(&k7, 1);
        Key k8(lbl_803818d0);
        fn_800fc43c(&k8, 0);
        Key k9(lbl_80381840);
        fn_800fc43c(&k9, 0);
        fn_8016239c(fn_80131b50(fn_801613f0(lbl_804b1754, 12), 13));
    }
}
