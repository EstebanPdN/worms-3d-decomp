// d25c: 0x800d6424. Oil drum logic: when not dead (+88) or triggered (+120), compare the distance from the drum
// (raised by 9) to the mover with the mover's radius plus 9; when inside, mark triggered, record the time and,
// for the two drum types, report 'Oil Drum About To Explode'. Names are inferred.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Type { unsigned char u[20]; const Type *parent; };
struct Motion;
struct Context { char u[52]; int time; };
struct Self {
    struct V { void *u[5]; const Type *(*type)(Self *); } *vtable;
    char u4[24];
    Vec3 pos;           // +28
    char u40[48];
    int dead;           // +88
    char u92[28];
    int triggered;      // +120
    char u124[4];
    int when;           // +128
    char data[1];       // +132
};
extern "C" float radius_800668e4(Motion *);
extern "C" Vec3 position_80066894(Motion *);
extern "C" Context *ctx_80165254(void);
extern "C" int report_80022e20(const char *, const char *, int, void *);
extern const Type type_80361860[], type_803618f0[];
extern float height_80388eac[];
extern const char file_80388e78[], msg_80388e94[];
inline bool is_a(const Type *t, const Type *target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
inline float distance2(const Vec3 &a, const Vec3 &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}
extern "C" void d25c_oil_drum_check_800d6424(Self *self, Motion *m) {
    if (self->dead || self->triggered) return;
    Vec3 p(self->pos);
    const float h = 9.0f;
    p.y += h;
    float a = radius_800668e4(m);
    float b = radius_800668e4(m);
    float r2 = (a + h) * (b + h);
    Vec3 q = position_80066894(m);
    bool inside = distance2(p, q) < r2;
    if (inside) {
        self->triggered = 1;
        self->when = ctx_80165254()->time;
        if (is_a(self->vtable->type(self), type_80361860) || is_a(self->vtable->type(self), type_803618f0))
            report_80022e20("Oil Drum About To Explode", "OilDrumLogicEntity.cpp", 289, self->data);
    }
}
