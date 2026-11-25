/* Aim tracking (0x80098388): only in mode 2 (+116) with a valid target value (+152); sweeps from the
 * eye point (member 0x8003e304, 8 units up) to the target worm (+136) unless it is gone or the own
 * worm, then to the worm named by +152 when clear, and when blocked marks +140 as seen and derives the
 * head (+148) and yaw (+144) values, each wrapped and scaled by pi/2 and clamped to -1..1, using the
 * yaw at +124 through a built matrix; otherwise clears +140. Field names are inferred from the
 * original instructions. Owns the literals at 0x8037f75c. */
extern "C" float sqrt_802e82c0(float);
extern "C" float atan2_802e7e5c(float, float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Copy(const Vec &o) { Vec *p = this; float a = o.x, b = o.y, c = o.z; x = a; p->y = b; p->z = c; }
    void Take(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator/(const Vec &a, float k) { float f = 1.0f / k; Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
inline const float &Min(const float &a, const float &b) { return a < b ? a : b; }
inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }
struct Pos { float x, y, z; Pos(); };
struct Row3 { float x, y, z; };
struct Transform { Row3 r[3]; Pos p; const Pos &P() const { return p; } };
struct Row4 { float x, y, z, w; };
struct Mat44 {
    Row4 r[4];
    Mat44(const Transform &t) {
        r[0].x = t.r[0].x; r[0].y = t.r[0].y; r[0].z = t.r[0].z; r[0].w = 0.0f;
        r[1].x = t.r[1].x; r[1].y = t.r[1].y; r[1].z = t.r[1].z; r[1].w = 0.0f;
        r[2].x = t.r[2].x; r[2].y = t.r[2].y; r[2].z = t.r[2].z; r[2].w = 0.0f;
        r[3].x = t.P().x; r[3].y = t.P().y; r[3].z = t.P().z; r[3].w = 1.0f;
    }
    const Row4 &R(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern "C" void w3d_construct_801f7538(Transform *, float, float, float, float);
extern Vec lbl_8045e788[];
extern int lbl_804b1764;
extern "C" int w3d_value_80178c48(void *);
struct Worm { char unknown00[80]; Vec position; char unknown92[128]; int alive; };
extern "C" Worm *w3d_worm_800fc6dc(int);
struct Aim;
extern "C" const Vec *w3d_member_8003e304(Aim *);
extern "C" int w3d_sweep_800b0824(const Vec *, const Vec *, const Vec *, int, int);
struct Aim {
    char unknown00[116]; unsigned char mode; char unknown117[7]; float yaw; char unknown128[4]; int own; int target; int seen; float elev; float head; void *h152;
    void SetSeen(int v) { seen = v; }
};
inline const float &Clamp(const float &a, const float &lo, const float &hi) { return Max(Min(a, hi), lo); }
inline void Unit(float &v) { v = Clamp(v, -1.0f, 1.0f); }
extern "C" void w3d_d28b_aim_track_80098388(Aim *self) {
    Vec hit;
    Vec eye;
    Vec tgt;
    Vec dir;
    if (self->mode == 2 && w3d_value_80178c48(self->h152) != -1) {
    int dist = 1001;
    Worm *worm = w3d_worm_800fc6dc(self->target);
    Vec *ph = &hit;
    ph->Copy(lbl_8045e788[0]);
    eye.Take(*w3d_member_8003e304(self));
    eye.y += 8.0f;
    self->SetSeen(0);
    int same = 0;
    if (worm->alive == 0 || self->target == self->own) same = 1;
    else {
        tgt = worm->position;
        tgt.y += 9.0f;
        dir = (tgt - eye) / 1000.0f;
        w3d_sweep_800b0824(&eye, &dir, ph, 1000, 1);
        dist = lbl_804b1764;
    }
    if (same == 0 && dist > 999) goto aim;
    {
        worm = w3d_worm_800fc6dc(w3d_value_80178c48(self->h152));
        tgt = worm->position;
        tgt.y += 9.0f;
        dir = (tgt - eye) / 1000.0f;
        w3d_sweep_800b0824(&eye, &dir, &hit, 1000, 1);
        dist = lbl_804b1764;
    }
    if (dist > 1000) goto aim;
    }
    self->SetSeen(0);
    return;
aim:
    {
        self->SetSeen(1);
        Vec d = tgt - eye;
        Vec h = d;
        h.y = 0.0f;
        float n = h.lenSq();
        if (n == 0.0f) {
            self->elev = 0.0f;
            self->head = 1.0f;
        } else {
            float a = atan2_802e7e5c(d.y, sqrt_802e82c0(n));
            { a = Clamp(a, -3.1415927f, 3.1415927f);
              if (a > 1.5707964f) a = 3.1415927f - a;
              else if (a < -1.5707964f) a = -1.5707964f - a; }
            float top = 1.5707964f;
            self->head = a / top;
            Transform m;
            w3d_construct_801f7538(&m, 0.0f, 1.0f, 0.0f, -self->yaw);
            Mat44 t(m);
            Vec o;
            t.rotate(o, h);
            float b = 0.0f - atan2_802e7e5c(o.x, o.z);
            { b = Clamp(b, -3.1415927f, 3.1415927f);
              if (b > top) b = 3.1415927f - b;
              else if (b < -1.5707964f) b = -3.1415927f - b; }
            self->elev = b / 1.5707964f;
            self->elev = Clamp(self->elev, -1.0f, 1.0f);
        }
        Unit(self->head);
    }
}
