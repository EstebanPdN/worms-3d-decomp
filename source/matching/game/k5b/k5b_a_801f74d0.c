struct K5bVec3 { float x, y, z; };
struct K5bMtx34 { float m[3][3]; struct K5bVec3 t; };
struct K5bMtx44 { float m[4][4]; };
static inline void k5b_vec3_set(struct K5bVec3 *v, float x, float y, float z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}
static inline void k5b_mtx33_set(float m[3][3], float a, float b, float c, float d, float e, float f, float g,
    float h, float i)
{
    m[0][0] = a;
    m[0][1] = b;
    m[0][2] = c;
    m[1][0] = d;
    m[1][1] = e;
    m[1][2] = f;
    m[2][0] = g;
    m[2][1] = h;
    m[2][2] = i;
}
void w3d_k5b_mtx34_from_mtx44_801f74d0(struct K5bMtx34 *d, const struct K5bMtx44 *s)
{
    k5b_mtx33_set(d->m, s->m[0][0], s->m[0][1], s->m[0][2], s->m[1][0], s->m[1][1], s->m[1][2], s->m[2][0],
        s->m[2][1], s->m[2][2]);
    k5b_vec3_set(&d->t, s->m[3][0], s->m[3][1], s->m[3][2]);
}
// desc: w3d_k5b_mtx34_from_mtx44_801f74d0: Appears to copy the 3x3 rotation and the translation row of a 4x4 float matrix into a 3x4 matrix with a separate translation vector.
