/* Launch effect setup (0x8009aaac): reads the active worm, posts the launch message and reads
 * Weapon.GraphicalLaunchLocation, then, when the target object exists, takes its position or, when
 * that is the default vector, a point 1000 units ahead along the worm pitch and yaw (0x801a3eb0), and
 * sets the emitter at +32: position, scale with z from a hundredth of the distance, and rotation from
 * the direction (0x8009b070). Returns 0. Field names are inferred from the original instructions;
 * Emitter is a partial view of the original virtual table with 4-byte entries. Owns the strings and
 * float literals from 0x8037ffbc. */
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Message { unsigned short id; void *vtable; };
extern "C" char lbl_8040db38[];
extern "C" void *w3d_arena_alloc_801613f0(void *, int);
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_message_post_8016239c(void *);
extern void *lbl_804b1754;
extern MessageCache lbl_804adfbc;
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Scale(float f) { x *= f; y *= f; z *= f; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline Vec operator/(const Vec &a, float k) { float f = 1.0f / k; Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline float Distance(const Vec &a, const Vec &b) { float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z; return sqrt_802e82c0(dx * dx + dy * dy + dz * dz); }
inline bool operator==(const Vec &a, const Vec &b) { return *(int *)&a.x == *(int *)&b.x && *(int *)&a.y == *(int *)&b.y && *(int *)&a.z == *(int *)&b.z; }
struct Row { float x, y, z; };
struct Mat {
    Row r[3];
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern const Vec lbl_8045e788[];
struct PropertyKey { const char *name; };
extern "C" int w3d_read_time_800fc1f0(PropertyKey *, int *);
extern "C" int w3d_read_vec_800fc2f0(PropertyKey *, Vec *);
struct Worm { char unknown00[72]; float yaw; char unknown76[40]; float pitch; };
extern "C" Worm *w3d_worm_800fc6dc(int);
struct Holder { char unknown00[72]; Vec position; };
extern "C" Holder *w3d_lookup_80164fc8(int);
extern "C" void w3d_euler_801a3eb0(const Vec *, int, Mat *);
struct Emitter {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16();
    virtual void SetPosition(const Vec *, int);
    virtual void SetRotation(const Vec *, int);
    virtual void SetScale(const Vec *, int);
};
struct Entity;
extern "C" Vec f7b_direction_angles_8009b070(Entity *, const Vec &);
struct Entity { char unknown00[32]; Emitter *emitter; int target; };
extern "C" int w3d_d28b_launch_effect_8009aaac(Entity *self) {
    Vec pos;
    Vec target;
    Vec mid;
    Vec spin(1.0f, 1.0f, 1.0f);
    Vec rot;
    PropertyKey index; index.name = "ActiveWormIndex";
    int active;
    w3d_read_time_800fc1f0(&index, &active);
    Worm *worm = w3d_worm_800fc6dc(active);
    Message *m = (Message *)w3d_arena_alloc_801613f0(lbl_804b1754, 8);
    m->id = w3d_cached_message_id_8015f5a0(&lbl_804adfbc, 1);
    m->vtable = lbl_8040db38;
    w3d_message_post_8016239c(m);
    PropertyKey where; where.name = "Weapon.GraphicalLaunchLocation";
    w3d_read_vec_800fc2f0(&where, &pos);
    Holder *h = w3d_lookup_80164fc8(self->target);
    if (h) {
        target = h->position;
        if (lbl_8045e788[0] == target) {
            Vec ang;
            Vec dir;
            Mat mat;
            ang = lbl_8045e788[0];
            ang.x = -worm->pitch;
            ang.y = worm->yaw;
            float one = 1.0f;
            Vec fwd;
            Vec *p = &fwd;
            fwd.x = 0.0f;
            p->y = 0.0f;
            p->z = one;
            w3d_euler_801a3eb0(&ang, 0, &mat);
            mat.rotate(dir, fwd);
            dir.Scale(one / dir.len());
            target = pos + dir * 1000.0f;
        }
        mid = pos + (target - pos) / 2.0f;
        spin.z = Distance(target, pos) * 0.01f;
        rot = f7b_direction_angles_8009b070(self, target - pos);
        self->emitter->SetPosition(&pos, 0);
        self->emitter->SetScale(&spin, 0);
        self->emitter->SetRotation(&rot, 0);
    }
    return 0;
}
