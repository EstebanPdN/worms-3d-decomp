// d29c: 0x800ff6a4. Radar update: for each player fetches the worm, transforms its offset from the viewer into radar space, clamps it to the radar radius and fills the mesh position, flag, team and size arrays. Names are inferred; classes are partial views.
extern "C" float sqrt_802e82c0(float);
struct W { int a, b, c; };
struct V {
    float x, y, z;
    V() {}
    V(const V &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    V operator-(const V &o) const { V r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    void operator*=(float s) { x *= s; y *= s; z *= s; }
    float len() const { return sqrt_802e82c0(x * x + y * y + z * z); }
};
struct Row { float x, y, z; };
struct Mat {
    Row row[3]; Row pos;
    const Row &R(int i) const { return row[i]; }
    const Row &P() const { return pos; }
    void transform(V &o, const V &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
struct Size { float w, h; };
struct Worm { int Team() const { return team; } char u0[28]; int team; char u32[8]; V pos; char u52[112]; int alive; };
struct Mesh;
struct Radar { char u0[36]; void *h36; float cx, cy; char u48[20]; void *scale; void *radius; char u76[4]; void *size; };
extern void *players_804aab4c;
extern "C" Mesh *empty_8034380c(void *);
extern "C" int count_8008c34c(void *);
extern "C" int setCount_8018920c(Mesh *, int);
extern "C" Worm *lookup_8008c360(void *, int);
extern "C" unsigned char *flags_80189704(Mesh *);
extern "C" V *positions_80189518(Mesh *);
extern "C" unsigned char *teams_80189828(Mesh *);
extern "C" Size *sizes_8018963c(Mesh *);
extern "C" float value_80178df0(void *);
extern "C" const Size *vector_80178ec4(void *);
extern "C" void d29c_radar_update_800ff6a4(Radar *self, const V *eye, const Mat *m) {
    Mesh *mesh = empty_8034380c(self->h36);
    int n = count_8008c34c(players_804aab4c);
    setCount_8018920c(mesh, n);
    for (int i = 0; i < n; i++) {
        Worm *w = lookup_8008c360(players_804aab4c, i);
        if (!w) {
            flags_80189704(mesh)[i] = (unsigned char)(int)w;
            continue;
        }
        int alive = w->alive;
        if (!alive) {
            flags_80189704(mesh)[i] = alive;
            continue;
        }
        V res;
        V d;
        d = *eye - V(w->pos);
        float zero = 0.0f;
        d.y = zero;
        m->transform(res, d);
        res *= value_80178df0(self->scale);
        float l = res.len();
        if (l >= value_80178df0(self->radius)) res *= value_80178df0(self->radius) / l;
        positions_80189518(mesh)[i].set(self->cx + res.x, self->cy - res.z, zero);
        flags_80189704(mesh)[i] = 1;
        teams_80189828(mesh)[i] = w->Team();
        Size &s = sizes_8018963c(mesh)[i];
        const Size *a = vector_80178ec4(self->size);
        const Size *b = vector_80178ec4(self->size);
        float h = b->h;
        s.w = a->w;
        s.h = h;
    }
}
