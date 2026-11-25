// d41i: 0x80105164. Fills a star or spark mesh from numbered locators of a
// parent object, then adds random points on a dome up to the mesh count.
extern "C" void str_finish_8020c5c4(void *);
extern "C" void str_release_80341588(void *);
extern "C" float sqrt_802e82c0(float);
struct String_8020bb54 {
    char *text;
    String_8020bb54(const char *);
    String_8020bb54(const String_8020bb54 &);
    ~String_8020bb54() { str_finish_8020c5c4(this); str_release_80341588(this); }
};
struct String_803426b8 {
    char *text;
    String_803426b8();
    String_803426b8(const String_803426b8 &);
    ~String_803426b8() { str_finish_8020c5c4(this); str_release_80341588(this); }
};
struct Vec_80343740 {
    float x, y, z;
    Vec_80343740();
    Vec_80343740(const Vec_80343740 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
};
struct Vec {
    float x, y, z;
    Vec() {}
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
struct Rgba { unsigned char r, g, b; signed char a; };
struct V2 { float x, y; void set(float a) { x = a; y = a; } };
struct Loc { float m[9]; Vec_80343740 pos; };
struct Mesh;
struct MeshVt { char u0[88]; int (*show)(Mesh *, int); };
struct Mesh { MeshVt *vt; };
struct Self { char u0[28]; void *p28; char u32[16]; void *h48; char u52[8]; unsigned count; };
extern char s_80399860[], s_80399868[], s_80399874[];
extern "C" {
void fmt_8020c510(void *, const char *, ...);
void *m_80343584(void *);
Mesh *m_8034380c(void *);
int find_80181e3c(void *, const char *, Loc *);
int load_8015adf4(const String_8020bb54 &, void **, int);
int setc_8018920c(Mesh *, int);
float rf_8015ff7c(Self *);
unsigned ru_8015ff5c(Self *);
unsigned char *idx_80189828(Mesh *);
V2 *siz_8018963c(Mesh *);
Vec *pos_80189518(Mesh *);
Rgba *col_80189760(Mesh *);
}
inline V2 &at(int b, unsigned i) { return *(V2 *)(b + (i << 3)); }
template <class T> inline void put(Mesh *m, unsigned i, float size, const T &p, unsigned char c) {
    idx_80189828(m)[i] = 0;
    at((int)siz_8018963c(m), i).set(size);
    pos_80189518(m)[i].set(p.x, p.y, p.z);
    Rgba *k = col_80189760(m);
    k[i].r = c; k[i].g = c; k[i].b = c; k[i].a = -1;
}
extern "C" void d41i_star_field_mesh_build_80105164(Self *self) {
    self->count = 0;
    Loc loc;
    Vec_80343740 *pos = &loc.pos;
    void *base = m_80343584(self->p28);
    if (base) {
        String_803426b8 s;
        fmt_8020c510(&s, s_80399860);
        if (find_80181e3c(base, s.text, &loc) >= 0) {
            Vec_80343740 c(*pos);
            float radius = c.len();
            {
                String_8020bb54 n(s_80399868);
                load_8015adf4(n, &self->h48, 255);
            }
            Mesh *m = m_8034380c(self->h48);
            unsigned i = 0;
            unsigned n;
            for (;;) {
                if (i > 39) { n = i - 1; break; }
                unsigned next = i + 1;
                fmt_8020c510(&s, s_80399874, next);
                if (find_80181e3c(base, s.text, &loc) < 0) { n = i - 1; break; }
                i = next;
            }
            if (n > 10) self->count = n;
            else self->count = n == 0 ? 201 : n + 100;
            m->vt->show(m, 1);
            setc_8018920c(m, self->count);
            float rr = radius * radius;
            float top = -1000.0f;
            for (i = 0; i < n; i++) {
                unsigned next = i + 1;
                fmt_8020c510(&s, s_80399874, next);
                if (find_80181e3c(base, s.text, &loc) >= 0) {
                    c = loc.pos;
                    float size = rf_8015ff7c(self) * 20.0f + 20.0f;
                    unsigned char g = ru_8015ff5c(self) % 224 + 32;
                    put(m, i, size, c, g);
                    if (c.y > top) top = c.y;
                }
            }
            if (top < 0.0f) top = 100.0f;
            float w = sqrt_802e82c0(rr - top * top);
            float h = radius - top;
            w = w + w;
            for (i = n; i < self->count; i++) {
                Vec v;
                v.x = rf_8015ff7c(self) + -0.5f;
                v.y = rf_8015ff7c(self) + 0.01f;
                v.z = rf_8015ff7c(self) + -0.5f;
                v.x *= w;
                v.y = v.y * h + top;
                v.z *= w;
                v.normalize();
                v.x *= radius; v.y *= radius; v.z *= radius;
                float size = rf_8015ff7c(self) * 20.0f + 20.0f;
                unsigned char g = ru_8015ff5c(self) % 224 + 32;
                put(m, i, size, v, g);
            }
        }
    }
}
