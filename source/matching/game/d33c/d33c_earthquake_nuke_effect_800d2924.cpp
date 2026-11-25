// GWMP8P rev0 0x800d2924. Nuclear-weapon effect: shakes the camera, poisons
// every other active worm, raises the water level, and spawns the nuke
// explosion above the camera position. The property setters return int
// (callees return their status in r3).
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
  float lenSq() const { return x * x + y * y + z * z; } void normalize(); };
extern "C" float sqrt_802e82c0(float);
inline void Vec3::normalize() { float f = 1.0f / sqrt_802e82c0(lenSq()); x *= f; y *= f; z *= f; }
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Key { const char *name; Key(const char *n) { name = n; } };
extern "C" int get_float_800fc270(Key *, float *);
extern "C" int set_float_800fc4c8(Key *, float);
extern "C" int get_int_800fc230(Key *, int *);
extern "C" int set_int_800fc3b0(Key *, int);
extern "C" int get_int_800fc1f0(Key *, int *);
extern "C" int set_int_800fc43c(Key *, int);
inline void setf(const char *n, const float &v) { Key k(n); set_float_800fc4c8(&k, v); }
inline void seti(const char *n, const int &v) { Key k(n); set_int_800fc3b0(&k, v); }
struct Msg { unsigned short id; const void *vt; };
extern void *arena_804b1754;
extern "C" Msg *alloc_801613f0(void *, int);
extern "C" int cached_8015f5a0(int *, int);
extern "C" int post_8016239c(Msg *);
extern "C" Msg *init_800a82f0(void *, unsigned short, int);
extern char vt_8040db38[];
extern int id_804ae9c4, id_804ae9dc, id_804ae9bc;
struct Info { char u0[220]; int active; };
extern "C" Info *query_800fc6dc(int);
extern Vec3 zero_8045e788;
struct Cam { char u0[4]; Vec3 at; Vec3 pos; };
struct Cams { Cam **v; Cam *&operator[](int i) { return v[i]; } };
struct Game { char u0[312]; int current; Cams cams; Cam *cam() { return cams[current]; } };
extern Game *game_804aa8c8;
extern "C" int quake_800e5ca4(Vec3 *, const char *, int, float);
extern "C" void d33c_earthquake_nuke_effect_800d2924(void) {
    Vec3 pos(zero_8045e788);
    Vec3 dir;
    Key k0("Earthquake.CameraShakeMagnitude"); float f0;
    get_float_800fc270(&k0, &f0);
    setf("Camera.Shake.Magnitude", f0);
    Key k2("Earthquake.Length.Default"); int i2;
    get_int_800fc230(&k2, &i2);
    seti("Camera.Shake.Length", i2);
    Msg *m = alloc_801613f0(arena_804b1754, 8);
    m->id = cached_8015f5a0(&id_804ae9c4, 1);
    m->vt = vt_8040db38;
    post_8016239c(m);
    Key k4("ActiveWormIndex"); int who;
    get_int_800fc1f0(&k4, &who);
    Key k5("Worm.Poison.Default");
    set_int_800fc43c(&k5, 5);
    Msg *n = alloc_801613f0(arena_804b1754, 8);
    n->id = cached_8015f5a0(&id_804ae9dc, 1);
    n->vt = vt_8040db38;
    post_8016239c(n);
    for (int i = 0; i <= 15; i++) {
        if (i != who && query_800fc6dc(i)->active == 1) {
            void *p = alloc_801613f0(arena_804b1754, 12);
            post_8016239c(init_800a82f0(p, cached_8015f5a0(&id_804ae9bc, 1), i));
        }
    }
    const char *wa = "Water.Level";
    Key k6(wa); float a;
    get_float_800fc270(&k6, &a);
    Key k7("Water.RiseAmount"); float b;
    get_float_800fc270(&k7, &b);
    a += b;
    Key k8(wa);
    set_float_800fc4c8(&k8, a);
    Game *g = game_804aa8c8;
    Vec3 p;
    *(Vec3 *)&p = g->cam()->pos;
    p.y = g->cam()->at.y;
    dir = p - g->cam()->at;
    dir.normalize();
    pos = g->cam()->pos + dir * 2000.0f;
    pos.y = a;
    quake_800e5ca4(&pos, "WeaponNuclear", 0, 0.0f);
}
