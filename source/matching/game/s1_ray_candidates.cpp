/* Observed ordering and interval dispatch for ray intersection candidates. */
extern "C" {
extern float w3d_f32_804b17d4;
int w3d_fn_8004035c(float *p);
int w3d_fn_80040440(float *p);
int w3d_fn_800405d4(float *p);
int w3d_fn_800406b8(float *p);
int w3d_fn_8004084c(float *p);
int w3d_fn_80040b0c(float *p);
int w3d_fn_80040ca0(float *p);
int w3d_fn_80040d84(float *p);
int w3d_fn_80040f18(float *p);
static inline int pair_precedes(float a, const float &b)
{
    float zero = 0.0f;
    return a < zero ? 0 : (b < zero || a <= b ? 1 : 0);
}
static inline int triple_precedes(float a, const float &b, const float &c)
{
    float zero = 0.0f;
    return a < zero ? 0 : ((b < zero || a <= b) && (c < zero || a <= c) ? 1 : 0);
}
int w3d_fn_8004035c(float *p)
{
    if (pair_precedes(p[4], p[0])) {
        p[4] = p[5]; p[5] = -1.0f;
        return w3d_fn_800406b8(p);
    }
    if (pair_precedes(p[0], p[4])) {
        p[0] = p[1]; p[1] = -1.0f;
        return w3d_fn_80040440(p);
    }
    return 0;
}
int w3d_fn_80040440(float *p)
{
    if (triple_precedes(p[2], p[4], p[0])) {
        p[2] = p[3]; p[3] = -1.0f;
        return w3d_fn_800405d4(p);
    }
    if (triple_precedes(p[0], p[2], p[4])) {
        p[0] = p[1]; p[1] = -1.0f;
        return w3d_fn_8004035c(p);
    }
    if (triple_precedes(p[4], p[0], p[2])) {
        w3d_f32_804b17d4 = p[4];
        p[4] = p[5]; p[5] = -1.0f;
        return w3d_fn_8004084c(p);
    }
    return 0;
}
int w3d_fn_800405d4(float *p)
{
    if (pair_precedes(p[4], p[2])) {
        p[4] = p[5]; p[5] = -1.0f;
        return w3d_fn_80040b0c(p);
    }
    if (pair_precedes(p[2], p[4])) {
        p[2] = p[3]; p[3] = -1.0f;
        return w3d_fn_80040440(p);
    }
    return 0;
}
int w3d_fn_800406b8(float *p)
{
    if (triple_precedes(p[4], p[0], p[6])) {
        p[4] = p[5]; p[5] = -1.0f;
        return w3d_fn_8004035c(p);
    }
    if (triple_precedes(p[6], p[0], p[4])) {
        p[6] = p[7]; p[7] = -1.0f;
        return w3d_fn_80040ca0(p);
    }
    if (triple_precedes(p[0], p[6], p[4])) {
        w3d_f32_804b17d4 = p[0];
        p[0] = p[1]; p[1] = -1.0f;
        return w3d_fn_8004084c(p);
    }
    return 0;
}
static inline int quad_precedes(float a, const float &b, const float &c, const float &d)
{
    float zero = 0.0f;
    return a < zero ? 0 : ((b < zero || a <= b) && (c < zero || a <= c) && (d < zero || a <= d) ? 1 : 0);
}
int w3d_fn_80040ff4(float lower, float upper);
int w3d_fn_8004084c(float *p)
{
    if (quad_precedes(p[4], p[0], p[2], p[6])) {
        if (w3d_fn_80040ff4(w3d_f32_804b17d4, p[4])) return 1;
        p[4] = p[5]; p[5] = -1.0f;
        return w3d_fn_80040440(p);
    }
    if (quad_precedes(p[6], p[0], p[2], p[4])) {
        if (w3d_fn_80040ff4(w3d_f32_804b17d4, p[6])) return 1;
        p[6] = p[7]; p[7] = -1.0f;
        return w3d_fn_80040d84(p);
    }
    if (quad_precedes(p[0], p[6], p[2], p[4])) {
        if (w3d_fn_80040ff4(w3d_f32_804b17d4, p[0])) return 1;
        p[0] = p[1]; p[1] = -1.0f;
        return w3d_fn_800406b8(p);
    }
    if (quad_precedes(p[2], p[6], p[0], p[4])) {
        if (w3d_fn_80040ff4(w3d_f32_804b17d4, p[2])) return 1;
        p[2] = p[3]; p[3] = -1.0f;
        return w3d_fn_80040b0c(p);
    }
    return 0;
}
int w3d_fn_80040b0c(float *p)
{
    if (triple_precedes(p[4], p[2], p[6])) {
        p[4] = p[5]; p[5] = -1.0f;
        return w3d_fn_800405d4(p);
    }
    if (triple_precedes(p[6], p[2], p[4])) {
        p[6] = p[7]; p[7] = -1.0f;
        return w3d_fn_80040f18(p);
    }
    if (triple_precedes(p[2], p[6], p[4])) {
        w3d_f32_804b17d4 = p[2];
        p[2] = p[3]; p[3] = -1.0f;
        return w3d_fn_8004084c(p);
    }
    return 0;
}
int w3d_fn_80040ca0(float *p)
{
    if (pair_precedes(p[6], p[0])) {
        p[6] = p[7]; p[7] = -1.0f;
        return w3d_fn_800406b8(p);
    }
    if (pair_precedes(p[0], p[6])) {
        p[0] = p[1]; p[1] = -1.0f;
        return w3d_fn_80040d84(p);
    }
    return 0;
}
int w3d_fn_80040d84(float *p)
{
    if (triple_precedes(p[2], p[6], p[0])) {
        p[2] = p[3]; p[3] = -1.0f;
        return w3d_fn_80040f18(p);
    }
    if (triple_precedes(p[0], p[2], p[6])) {
        p[0] = p[1]; p[1] = -1.0f;
        return w3d_fn_80040ca0(p);
    }
    if (triple_precedes(p[6], p[0], p[2])) {
        w3d_f32_804b17d4 = p[6];
        p[6] = p[7]; p[7] = -1.0f;
        return w3d_fn_8004084c(p);
    }
    return 0;
}
#if 0 /* 0x80040f18: single invalidation uses a different floating register. */
static inline void invalidate(float &value) { value = -1.0f; }
int w3d_fn_80040f18(float *p)
{
    if (pair_precedes(p[6], p[2])) {
        invalidate(p[6]);
        return w3d_fn_80040b0c(p);
    }
    if (pair_precedes(p[2], p[6])) {
        p[2] = p[3]; p[3] = -1.0f;
        return w3d_fn_80040d84(p);
    }
    return 0;
}
#endif
}
