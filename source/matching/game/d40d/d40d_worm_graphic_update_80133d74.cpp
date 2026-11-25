// GWMP8P rev0 0x80133d74: per-frame update of a worm's graphic.
// Hides the mesh close to the camera, follows the simulation entry, places
// the three shadow parts along a downward test ray, and posts a splash
// message when the worm moves far enough in shallow water.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float distSq(const Vec &o) const { float dx = x - o.x, dy = y - o.y, dz = z - o.z; return dx * dx + dy * dy + dz * dz; }
    float dist(const Vec &o) const { return sqrt_802e82c0(distSq(o)); }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline bool same(const Vec &a, const Vec &b) {
    return *(const int *)&a.x == *(const int *)&b.x && *(const int *)&a.y == *(const int *)&b.y && *(const int *)&a.z == *(const int *)&b.z;
}
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Transform { Axis a[3]; Pos p; const Pos &P() const { return p; } };
struct Row { float x, y, z, w; };
struct Matrix {
    Row r[4];
    Matrix(const Transform &t) {
        r[0].x = t.a[0].x; r[0].y = t.a[0].y; r[0].z = t.a[0].z; r[0].w = 0.0f;
        r[1].x = t.a[1].x; r[1].y = t.a[1].y; r[1].z = t.a[1].z; r[1].w = 0.0f;
        r[2].x = t.a[2].x; r[2].y = t.a[2].y; r[2].z = t.a[2].z; r[2].w = 0.0f;
        r[3].x = t.P().x; r[3].y = t.P().y; r[3].z = t.P().z; r[3].w = 1.0f;
    }
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Mesh {
    struct Table { char u0[76]; void (*place)(Mesh *, const Vec *, int); void (*rotate)(Mesh *, const Vec *, int); void (*scale)(Mesh *, const Vec *, int); void (*show)(Mesh *, int); } *vt;
};
struct Tint { float r, g, b, a; Tint(float a0, float a1, float a2, float a3) { r = a0; g = a1; b = a2; a = a3; } Tint(float k) { r = 0.0f; g = 0.0f; b = 0.0f; a = k; } Tint(float z, float k) { r = z; g = z; b = z; a = k; } };
struct Info { char u0[68]; Vec rot; Vec pos; char u5c[128]; int alive; };
struct Graphic {
    char u0[28]; Mesh *mesh; char u20[8]; Mesh *parts[3]; Vec pos; char u40[0]; Vec rot; char u4c[36]; int index; char u74[8]; Vec lastCheck;
    char u88[16]; int forward; char u9c[340]; int state; Vec lastPos; char u200[100]; int side; float turn; float turnBlend; char u26c[0]; Vec lastRot; char u27c[36]; unsigned due; int dueArg;
};
struct Camera { char u0[4]; Vec pos; };
struct Scene { char u0[312]; int current; Camera **cameras; };
extern Scene *scene_804aa8c8;
struct Service { struct Table { char u0[96]; void (*notify)(Service *, int, const Vec *); } *vt; };
struct System { char u0[108]; Service *service; };
extern System *system_804b1788;
extern "C" Info *index_query_800fc6dc(int);
extern "C" int isCurrent_80139158(Graphic *);
extern "C" float delta_8013aa10(Graphic *, float, float);
extern "C" void test_800b0824(const Vec &, const Vec &, const Vec &, int, int);
extern "C" int set_tint_80182178(Mesh *, Tint *);
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" void forward_8013dda8(Graphic *);
extern "C" void pot_8013586c(Graphic *);
extern "C" void *alloc_801613f0(void *, int);
extern "C" short msg_id_8015f5a0(void *, int);
extern "C" void *vec_message_80126000(void *, unsigned short, const Vec *);
extern "C" int post_8016239c(void *);
extern "C" void anim_80135c20(Graphic *, unsigned);
extern "C" void refresh_8013f2f8(Graphic *);
extern "C" void colour_80139b3c(Graphic *);
extern "C" void tail_8013f73c(Graphic *, unsigned);
extern void *heap_804b1754;
extern int cache_804af7f0;
extern int traceFrac_804b1764;
extern float far_8039f1ec[];
extern "C" void w3d_d40d_worm_graphic_update_80133d74(Graphic *self, unsigned time) {
    if (self->mesh) {
        Vec p = self->pos;
        p.y += 10.0f;
        Scene *s = scene_804aa8c8;
        float dist = p.dist(((Camera **)((char *)s->cameras + (s->current << 2)))[0]->pos);
        if (self->state == 37 || dist <= 12.0f) self->mesh->vt->show(self->mesh, 0);
        else self->mesh->vt->show(self->mesh, 1);
        Info *info = index_query_800fc6dc(self->index);
        if (info->alive) {
            self->lastPos = self->pos;
            self->pos = info->pos;
            if (self->due && time > self->due) {
                self->due = 0;
                Service *sv = system_804b1788->service;
                if (sv) sv->vt->notify(sv, self->dueArg, &self->pos);
            }
            if (self->state != 11) {
                self->lastRot = self->rot;
                if (isCurrent_80139158(self)) self->rot = info->rot;
                float d = delta_8013aa10(self, self->rot.y, self->lastRot.y);
                float b = d * 0.75f + self->turnBlend * 0.25f;
                self->turn = d;
                self->turnBlend = b;
                self->side = b > 0.0f ? 1 : b < 0.0f ? 2 : 0;
            }
        }
        float along = 0.0f;
        Vec up(0.0f, 2.0f, 0.0f);
        Mesh *mm = self->mesh;
        Mesh::Table *mt = mm->vt;
        Vec a = self->pos + up;
        mt->place(mm, &a, 0);
        a.set(0.0f, -0.1f, 0.0f);
        Vec z(0.0f, 0.0f, 0.0f);
        test_800b0824(self->pos, a, z, 3000, 1);
        int n = traceFrac_804b1764;
        if (n <= 3000) {
            float t = (float)n;
            float f = (3000.0f - t) / 3000.0f;
            if (n <= 9 || dist >= far_8039f1ec[0]) {
                for (unsigned i = 0; i <= 2; i++) { Mesh **pp = &self->parts[i]; (*pp)->vt->show(*pp, 0); }
            } else {
                if (n <= 19) f *= t * 0.05f;
                float q = 1.0f - dist / far_8039f1ec[0];
                Tint tint(0.0f, 0.0f, 0.0f, f * 0.16f * q);
                Vec scale(0.5f, -0.2f, 1.0f);
                for (unsigned i = 0; i <= 2; i++) {
                    Mesh **pp;
                    do { pp = &self->parts[i]; } while (0);
                    along = t;
                    {
                        Mesh *m = *pp;
                        Mesh::Table *vt = m->vt;
                        Vec at = self->pos + a * along;
                        vt->place(m, &at, 0);
                    }
                    {
                        Mesh *m = *pp;
                        Mesh::Table *vt = m->vt;
                        Vec sc = scale * f;
                        vt->scale(m, &sc, 0);
                    }
                    f *= 0.9f;
                    (*pp)->vt->show(*pp, 1);
                    {
                        Vec r = self->rot;
                        r.x = 0.0f;
                        (*pp)->vt->rotate(*pp, &r, 0);
                    }
                    set_tint_80182178(*pp, &tint);
                }
            }
        } else {
            for (unsigned i = 0; i <= 2; i++) { Mesh **pp = &self->parts[i]; (*pp)->vt->show(*pp, 0); }
        }
        self->mesh->vt->rotate(self->mesh, &self->rot, 0);
        if (!same(self->rot, info->rot)) {
            Vec fw(0.0f, 0.0f, -5.0f);
            Transform m;
            const Vec &ir = info->rot;
            construct_801f7538(&m, 0.0f, 1.0f, 0.0f, ir.y);
            Vec o;
            Matrix(m).rotate(o, fw);
            Mesh *mm2 = self->mesh;
            Mesh::Table *mt2 = mm2->vt;
            Vec at = self->pos + up + o;
            mt2->place(mm2, &at, 0);
        }
        if (self->forward != -1) forward_8013dda8(self);
        pot_8013586c(self);
        if (self->pos.y < 0.0f && self->pos.y > -15.0f) {
            Vec moved = self->pos - self->lastCheck;
            if (moved.lenSq() > 9.0f) {
                self->lastCheck = self->pos;
                void *m = alloc_801613f0(heap_804b1754, 20);
                post_8016239c(vec_message_80126000(m, msg_id_8015f5a0(&cache_804af7f0, 1), &self->lastCheck));
            }
        }
        anim_80135c20(self, time);
        refresh_8013f2f8(self);
        colour_80139b3c(self);
        tail_8013f73c(self, time);
    }
}
