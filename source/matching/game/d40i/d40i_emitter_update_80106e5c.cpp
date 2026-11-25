// d40i: 0x80106e5c. Particle emitter per-frame update: derives its position
// and facing from the inverse camera matrix, refreshes the bounds, updates
// each particle and its colour fade, then ages the emitter and removes it
// when the fade ends. The leading 0.0f of the pool, 4 bytes past an 8-byte
// boundary, stays an external view.
struct Vec {
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float s) { Vec r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Mat4 { float m[4][4]; };
struct Rot {
    float a, b, c, d, e, f, g, h, i;
    Rot() {}
    void set(const Mat4 &o) { a = o.m[0][0]; b = o.m[0][1]; c = o.m[0][2]; d = o.m[1][0]; e = o.m[1][1]; f = o.m[1][2]; g = o.m[2][0]; h = o.m[2][1]; i = o.m[2][2]; }
};
struct Row { float x, y, z; };
struct Frame {
    Row r0, r1, r2;
    const Row &R(int i) const { return (&r0)[i]; }
    Frame() {}
    void set(const Mat4 &o) {
        r0.x = o.m[0][0]; r0.y = o.m[0][1]; r0.z = o.m[0][2];
        r1.x = o.m[1][0]; r1.y = o.m[1][1]; r1.z = o.m[1][2];
        r2.x = o.m[2][0]; r2.y = o.m[2][1]; r2.z = o.m[2][2];
    }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Config { char u0[144]; Vec orient; char u156[148]; int mode; };
struct Hold { char u0[1032]; int busy; };
struct Particle;
struct ParticleVt { char u0[36]; void (*update)(Particle *, int, Vec *, Config *, struct Temp *); };
struct Particle { char u0[112]; ParticleVt *vt; };
struct Temp { int v[4]; };
struct Colour { signed char r, g, b, a; };
inline void paint(Colour &c, int a) { c.r = -1; c.g = -1; c.b = -1; c.a = a; }
struct Pool;
struct PoolVt { char u0[20]; Particle *(*at)(Pool *, unsigned); };
struct Pool { PoolVt *vt; };
struct SinkVt { char u0[8]; void (*add)(void *, Particle *, int, int); };
struct Emitter {
    char u0[28]; char sink[4];
    Pool *pool; int last; char u40[68]; char link[32]; unsigned count; char u144[12]; void *cfg; char u160[16];
    int kind; int flags; unsigned index; Vec *points; Colour *colours; char u196[8]; void *p204; char u208[12];
    unsigned char dirty; char u221[27]; void *link248; char u252[4]; SinkVt *sinkVt; void *prop; char u264[40];
    unsigned colourMode; char u308[24]; Vec v332; unsigned char age; unsigned char ageMax; char u346[14]; void *hold; char u364[16]; float size;
};
struct Camera { char u0[48]; struct View *view; };
struct View { struct ViewVt *vt; };
struct ViewVt { char u0[24]; Mat4 *(*matrix)(View *); };
extern Camera *camera_804b1788;
extern "C" Mat4 *inverse_801f6c2c(Mat4 *, const Mat4 *);
extern "C" float sqrt_802e82c0(float);
extern "C" void *ref_80341584(void *);
extern "C" Config *cfg_801797b4(void *);
extern "C" void bounds_80107ccc(Emitter *, Rot, Vec);
extern "C" Vec *points_80189518(void *);
extern "C" void *second_80189828(void *);
extern "C" Colour *colours_80189760(void *);
extern "C" void near_80107f54(Emitter *, const Vec &);
extern "C" int wrap_80107ab8(Emitter *, Vec *);
extern "C" void hit_800dca14(Particle *, int);
extern "C" void orient_80107d70(Emitter *, const Vec &, const Vec &, const Vec &);
extern "C" Hold *lookup_80164fc8(void *);
extern "C" void remove_8015fd1c(Emitter *);
inline bool isBusy(Hold *h) { return h->busy != 0; }
extern float zero_80399adc[];
extern "C" int d40i_emitter_update_80106e5c(Emitter *self, int time) {
    Temp temp;
    Mat4 inv;
    Vec pos;
    Frame f;
    Mat4 *view = camera_804b1788->view->vt->matrix(camera_804b1788->view);
    Vec up;
    Vec *pu = &up;
    up.x = zero_80399adc[0];
    pu->y = zero_80399adc[0];
    pu->z = 1.0f;
    inverse_801f6c2c(&inv, view);
    pos.x = inv.m[3][0]; pos.y = inv.m[3][1]; pos.z = inv.m[3][2];
    f.set(inv);
    Vec n;
    f.rotate(n, up);
    float s = 1.0f / sqrt_802e82c0(n.x * n.x + n.y * n.y + n.z * n.z);
    n.x *= s; n.y *= s; n.z *= s;
    n.x = -n.x; n.y = -n.y; n.z = -n.z;
    Config *cfg = cfg_801797b4(ref_80341584(self->cfg));
    Rot rot;
    Vec o;
    Vec tip = pos + n * self->size;
    rot.set(*view);
    self->v332 = pos;
    bounds_80107ccc(self, rot, n);
    self->points = points_80189518(self->prop);
    self->p204 = second_80189828(self->prop);
    int last = self->last;
    int dt;
    self->dirty = 1;
    self->link248 = self->link;
    self->index = 0;
    if (last == 0) dt = 0; else dt = time - last;
    self->last = time;
    if (!(self->flags & 256)) near_80107f54(self, pos);
    if (self->colourMode & 1) self->colours = colours_80189760(self->prop);
    self->index = 0;
    if (self->index < self->count) {
        do {
            if (self->colourMode & 1) {
                if (self->colourMode & 2) {
                    paint(*(Colour *)((self->index << 2) + (unsigned)self->colours), self->ageMax - self->age);
                } else {
                    paint(*(Colour *)((self->index << 2) + (unsigned)self->colours), self->age);
                }
            }
            Particle *p = self->pool->vt->at(self->pool, self->index);
            p->vt->update(p, time, &self->points[self->index], cfg, &temp);
            if (wrap_80107ab8(self, &self->points[self->index])) {
                self->sinkVt->add(self->sink, p, time, 1);
                hit_800dca14(p, 1);
            }
            if (self->flags & 256) {
                Vec *base = self->points; Vec &e = *(Vec *)(self->index * 12 + (unsigned)base);
                f.rotate(o, e);
                o += tip;
                e = o;
            }
        } while (++self->index < self->count);
    }
    if (cfg->mode == 2) orient_80107d70(self, pos, n, cfg->orient);
    unsigned mode = self->colourMode;
    if (mode & 1) {
        int age = self->age;
        int a = (unsigned char)age;
        if ((float)a > (float)dt * 0.6f) {
            if ((float)(unsigned char)age - (float)dt * 0.6f < zero_80399adc[0]) self->age = 0;
            else self->age = age - (unsigned char)((float)dt * 0.6f);
        } else {
            if (a == 0) {
                if (self->kind == 3) {
                    if (cfg->mode == 2) {
                        Hold *h = lookup_80164fc8(self->hold);
                        if (h && isBusy(h)) goto done;
                    }
                    remove_8015fd1c(self);
                } else {
                    self->age = self->ageMax;
                    self->colourMode = mode & ~3;
                }
            } else {
                self->age = 0;
            }
        }
    }
done:
    return 0;
}
