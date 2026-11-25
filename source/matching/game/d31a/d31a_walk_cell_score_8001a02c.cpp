// GWMP8P rev0 0x8001a02c. AI score of a grid cell for a walking worm: danger
// from blasts, marks, players and height, plus the openness of the 25 by 25
// cells around it, with mine forces added and the total capped at 10.
extern "C" float sqrt_802e82c0(float);
extern "C" float w3d_libm_forward_802e83cc(float);
extern "C" float w3d_fn_802e8094(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Grid { char pad[108]; float top, low; };
struct Blast { int pad0; int pad1; int team; float power; Vec pos; };
struct Mark { Vec pos; };
struct Mine { int pad; Vec pos; char pad2[24]; Vec force; };
template <class T> struct List {
    T *start, *finish;
    int size() const { return finish - start; }
    T &operator[](int i) const { return start[i]; }
};
struct Words { float x, y, z; };
struct Slot { char pad[28]; Words pos; Words Pos() const { return pos; } };
struct Game { char pad[336]; float radius; };
extern float g_tick_804aa570;
extern Grid *w3d_grid_804b1758;
extern List<Blast *> *g_blasts_804aa750;
extern List<Mark> *g_marks_804aa754;
extern List<Mine *> *g_mines_804aa75c;
extern float g_blast_scale_804aa764;
extern int g_players_804aab4c;
extern Game *w3d_game_804aa6d8;
extern "C" Vec *w3d_auto_80015588(int);
extern "C" Vec w3d_cx12a_sample_grid_8001e224(Grid *, int, int, int);
extern "C" unsigned char *cc26a_grid_byte_cell_8001dff8(Grid *, int, int, int);
extern "C" float *k5a_grid_cell_slot_8001e1a0(Grid *, int, int, int);
extern "C" float *w3d_cc18a_grid_cell_slot_8001e11c(Grid *, int, int, int);
extern "C" int w3d_player_list_weapon_count_8008c534(void *);
extern "C" Slot *s19_lookup_slot_8008c548(void *, int);
extern "C" float w3d_d31a_walk_cell_score_8001a02c(int x, int z, int layer, int team, float w1, float w2)
{
    g_tick_804aa570 += 10.0f;
    Vec home = *w3d_auto_80015588(team);
    Vec p = w3d_cx12a_sample_grid_8001e224(w3d_grid_804b1758, x, z, layer);
    if (*cc26a_grid_byte_cell_8001dff8(w3d_grid_804b1758, x, z, layer) == 1)
        return 0.0f;
    float height = *k5a_grid_cell_slot_8001e1a0(w3d_grid_804b1758, x, z, layer);
    float danger = 1.0f;
    if (w1 != 0.0f) {
        if (layer > 0) danger = 5.0f;
        float threat = 0.0f;
        int hit = -1;
        int n = g_blasts_804aa750->size();
        for (int i = 0; i < n; i++) {
            Blast *b = (*g_blasts_804aa750)[i];
            if (b->power < 0.0f) {
                if (b->team == team) hit = i;
                else {
                    const Vec &c = b->pos;
                    float dx = c.x - p.x, dy = c.y - p.y, dz = c.z - p.z;
                    float d = dx * dx + dy * dy + dz * dz;
                    if (d < 10000.0f) {
                        float k = b->power / g_blast_scale_804aa764;
                        k *= 100.0f - sqrt_802e82c0(d);
                        k *= 0.01f;
                        threat -= k;
                    }
                }
            }
        }
        if (hit != -1) {}
        danger *= w3d_fn_802e8094(threat * w3d_libm_forward_802e83cc(0.1f));
        float near = 0.0f;
        int m = g_marks_804aa754->size();
        for (int i = 0; i < m; i++) {
            Vec c = (*g_marks_804aa754)[i].pos;
            float dx = c.x - p.x, dy = c.y - p.y, dz = c.z - p.z;
            float d = dx * dx + dy * dy + dz * dz;
            if (d < 10000.0f)
                near += (100.0f - sqrt_802e82c0(d)) * 0.01f;
        }
        danger *= w3d_fn_802e8094(near * w3d_libm_forward_802e83cc(0.02f));
        int w = w3d_player_list_weapon_count_8008c534((void *)g_players_804aab4c);
        near = 0.0f;
        for (int i = 0; i < w; i++) {
            Words c = s19_lookup_slot_8008c548((void *)g_players_804aab4c, i)->Pos();
            float dx = c.x - p.x, dy = c.y - p.y, dz = c.z - p.z;
            float d = dx * dx + dy * dy + dz * dz;
            if (d < 10000.0f)
                near += (100.0f - sqrt_802e82c0(d)) * 0.01f;
        }
        danger *= w3d_fn_802e8094(near * w3d_libm_forward_802e83cc(0.05f));
        Grid *g = w3d_grid_804b1758;
        float span = g->top - g->low;
        float e = (height - g->top) * 0.01f;
        float mul = 1.05f;
        if (span > 0.0f) mul = 1.2f;
        danger *= w3d_libm_forward_802e83cc(mul * w3d_fn_802e8094(e));
        if (hit != -1)
            danger *= -(*g_blasts_804aa750)[hit]->power / g_blast_scale_804aa764;
    }
    float low = 1.0f, below = 0.0f, open = below;
    for (int dx = -12; dx <= 12; dx++) {
        for (int dz = -12; dz <= 12; dz++) {
            float f = 1.0f / sqrt_802e82c0((float)(dx * dx + dz * dz));
            if (*cc26a_grid_byte_cell_8001dff8(w3d_grid_804b1758, x + dx, z + dz, 0) == 1)
                open += f;
            float dh = height - *w3d_cc18a_grid_cell_slot_8001e11c(w3d_grid_804b1758, x + dx, z + dz, 0);
            if (dh > 30.0f)
                open += dh * 0.2f * f / 30.0f;
            if (dh < 0.0f) {
                float t = dh * -0.01f;
                if (t > 1.0f) t = 1.0f;
                t *= f;
                open -= t;
                below += t;
            }
        }
    }
    float k = 5.0f;
    float lim = k * -0.5f;
    if (open < lim) open = lim;
    danger *= k / (open + k);
    low *= k / (below + k);
    float score = danger * w1 + low * w2;
    if (g_mines_804aa75c->start != g_mines_804aa75c->finish) {
        float r2 = w3d_game_804aa6d8->radius;
        r2 *= r2;
        int n = g_mines_804aa75c->size();
        for (int i = 0; i < n; i++) {
            float d;
            {
                Vec c = (*g_mines_804aa75c)[i]->pos;
                float dx = p.x - c.x, dy = p.y - c.y, dz = p.z - c.z;
                d = dx * dx + dy * dy + dz * dz;
            }
            if (d < r2) d = r2;
            Vec v = (*g_mines_804aa75c)[i]->force;
            score += v.y * r2 / d;
        }
    }
    if (score >= 10.0f) score = 10.0f;
    return score;
}
