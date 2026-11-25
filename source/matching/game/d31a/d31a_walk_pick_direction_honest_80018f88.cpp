// GWMP8P rev0 0x80018f88. AI walk direction choice: rates eight compass
// directions at four distances from the grid cell, marks, players and
// blasts, keeps the running total in best (capped at 1), and points dir at
// the safest direction.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator*(const Vec &v, float k) { Vec r; r.x = v.x * k; r.y = v.y * k; r.z = v.z * k; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r(b); r.x = a.x + r.x; r.y = a.y + r.y; r.z = a.z + r.z; return r; }
struct Row { float x, y, z; };
struct Mat { Row r[3]; };
extern "C" void w3d_construct_801f6034(Mat *);
extern "C" void w3d_rotate_rows_y_801f61a0(Mat *, float);
inline float Dot(const Vec &v, float a, float b, float c) { return v.x * a + v.y * b + v.z * c; }
inline Vec operator*(const Vec &v, const Mat &m)
{
    Vec r;
    Vec *p = &r;
    const Row &a = m.r[0], &b = m.r[1], &c = m.r[2];
    p->x = Dot(v, a.x, b.x, c.x);
    p->y = Dot(v, a.y, b.y, c.y);
    p->z = Dot(v, a.z, b.z, c.z);
    return r;
}
struct Res : Vec {
    void Mul(const Vec &v, const Mat &m)
    {
        const Row &a = m.r[0], &b = m.r[1], &c = m.r[2];
        x = v.x * a.x + v.y * b.x + v.z * c.x;
        y = v.x * a.y + v.y * b.y + v.z * c.y;
        z = v.x * a.z + v.y * b.z + v.z * c.z;
    }
};
inline Vec Rotated(const Vec &v, const Mat &m) { Res r; r.Mul(v, m); return r; }
inline void Add(float &s, float a) { s += a; }
struct Grid { char pad[108]; float top, low; };
struct Blast { int pad0; int pad1; int team; float power; Vec pos; };
struct Words { float x, y, z; };
struct Mark { Vec pos; };
template <class T> struct List {
    T *start, *finish;
    int size() const { return finish - start; }
    T &operator[](int i) const { return start[i]; }
};
struct Slot { char pad[28]; Words pos; Words Pos() const { return pos; } };
struct Walker { char pad[16]; Vec pos; int pad1; float best; Vec dir; };
extern int g_ready_804ac8c4;
extern float g_origin_8041d480[3];
extern Grid *w3d_grid_804b1758;
extern List<Blast *> *g_blasts_804aa750;
extern List<Mark> *g_marks_804aa754;
extern float g_blast_scale_804aa764;
extern int g_players_804aab4c;
extern const float g_reach_803eb8e8[];
extern "C" int cc26a_grid_select_layer_8001e328(Grid *, const Vec *, short *, short *, int *);
extern "C" unsigned char *cc26a_grid_byte_cell_8001dff8(Grid *, int, int, int);
extern "C" float *w3d_cc18a_grid_cell_slot_8001e11c(Grid *, int, int, int);
extern "C" int w3d_player_list_weapon_count_8008c534(void *);
extern "C" Slot *s19_lookup_slot_8008c548(void *, int);
extern "C" void w3d_d31a_walk_pick_direction_honest_80018f88(Walker *self, int skip)
{
    if (!g_ready_804ac8c4) {
        float z = 0.0f;
        g_origin_8041d480[1] = z;
        g_origin_8041d480[0] = z;
        g_ready_804ac8c4 = 1;
        g_origin_8041d480[2] = z;
    }
    float score[8];
    self->best = 0.0f;
    float top = w3d_grid_804b1758->top;
    top += (top - w3d_grid_804b1758->low) + (top - w3d_grid_804b1758->low);
    for (int i = 0; i <= 7; i++) {
        float angle = (float)i * 0.7853982f;
        float one = 1.0f;
        score[i] = 0.0f;
        Mat m;
        w3d_construct_801f6034(&m);
        w3d_rotate_rows_y_801f61a0(&m, angle);
        Vec v(one, 0.0f, 0.0f);
        v = v * m;
        for (int j = 0; j <= 3; j++) {
            Vec pos = self->pos + v * g_reach_803eb8e8[j];
            float w = 2.0f / (float)(j + 2);
            float sum = 0.0f;
            short x, z;
            int layer;
            cc26a_grid_select_layer_8001e328(w3d_grid_804b1758, &pos, &x, &z, &layer);
            float h = *w3d_cc18a_grid_cell_slot_8001e11c(w3d_grid_804b1758, x, z, layer);
            pos.y = h;
            if (*cc26a_grid_byte_cell_8001dff8(w3d_grid_804b1758, x, z, layer) == 1 || h < top)
                sum += w * 0.2f;
            if (self->pos.y - h > 30.0f)
                sum += w * 0.05f;
            float near = 0.0f;
            int m2 = g_marks_804aa754->size();
            for (int k = 0; k < m2; k++) {
                Vec c = (*g_marks_804aa754)[k].pos;
                float dx = c.x - pos.x, dy = c.y - pos.y, dz = c.z - pos.z;
                float d = dx * dx + dy * dy + dz * dz;
                if (d < 10000.0f)
                    Add(near, (100.0f - sqrt_802e82c0(d)) * 0.01f);
            }
            sum += near * 0.1f * w;
            int n = w3d_player_list_weapon_count_8008c534((void *)g_players_804aab4c);
            near = 0.0f;
            for (int k = 0; k < n; k++) {
                Words c = s19_lookup_slot_8008c548((void *)g_players_804aab4c, k)->Pos();
                float dx = c.x - pos.x, dy = c.y - pos.y, dz = c.z - pos.z;
                float d = dx * dx + dy * dy + dz * dz;
                if (d < 10000.0f)
                    Add(near, (100.0f - sqrt_802e82c0(d)) * 0.01f);
            }
            sum += near * 0.05f * w;
            float threat = 0.0f;
            int b = g_blasts_804aa750->size();
            for (int k = 0; k < b; k++) {
                if (k == skip) continue;
                Blast *e = (*g_blasts_804aa750)[k];
                if (e->power > 0.0f) {
                    const Vec &c = e->pos;
                    float dx = c.x - pos.x, dy = c.y - pos.y, dz = c.z - pos.z;
                    float d = dx * dx + dy * dy + dz * dz;
                    if (d < 10000.0f) {
                        float t = e->power / g_blast_scale_804aa764;
                        t *= 100.0f - sqrt_802e82c0(d);
                        threat += t * 0.01f;
                    }
                }
            }
            sum += threat * 0.05f * w;
            self->best += sum;
            score[i] += sum;
        }
    }
    if (self->best > 1.0f) self->best = 1.0f;
    float most = 0.0f;
    int pick = -1;
    for (int i = 0; i < 8; i++) {
        if (score[i] > most) { most = score[i]; pick = i; }
    }
    if (pick != -1) {
        float angle = (float)pick * 0.7853982f;
        Mat m;
        w3d_construct_801f6034(&m);
        w3d_rotate_rows_y_801f61a0(&m, angle);
        Vec v(-1.0f, 0.0f, 0.0f);
        v = v * m;
        self->dir = v;
    }
}
