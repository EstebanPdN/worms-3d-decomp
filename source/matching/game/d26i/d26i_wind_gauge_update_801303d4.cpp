// GWMP8P rev0 0x801303d4. Updates the wind gauge needle rotation and its
// fade.
extern "C" float sin_802e88ac(float);
extern "C" float atan2_802e7e5c(float, float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Row { float x, y, z, w; };
struct Matrix {
    Row row[4];
    const Row &R(int i) const { return row[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Camera { virtual void v0(); virtual void v1(); virtual void v2(); void *view(); };
struct Node { virtual void v0(); };
struct World { char u0[48]; void *camera; };
extern World *world_804b1788;
extern const float span_8039dfec[];
struct Gauge {
    char u0[28]; void *node; int pending; char u36[24]; float phase; char u64[24]; int time; int reversed; unsigned int start; float t;
};
extern "C" void w3d_a_80130d1c(Gauge *, int);
extern "C" void w3d_b_80131610(Gauge *);
extern "C" void * w3d_wind_direction_80131520(Vec *, Gauge *);
extern "C" int w3d_matrix_from_801f6c2c(Matrix *, void *);
extern "C" void w3d_c_80130fb8(Gauge *, float);
extern "C" void w3d_d_80131338(Gauge *);
extern "C" void w3d_e_80130ed8(Gauge *);
typedef void *(*GetFn)(void *);
typedef void (*SetRot)(void *, const Vec &, int);
extern "C" int d26i_wind_gauge_update_801303d4(Gauge *self, unsigned int now) {
    w3d_a_80130d1c(self, 1);
    Vec wind;
    Matrix m;
    w3d_b_80131610(self);
    float wobble = sin_802e88ac(self->phase / span_8039dfec[0]);
    w3d_wind_direction_80131520(&wind, self);
    float heading = atan2_802e7e5c(wind.x, wind.z);
    void *cam = world_804b1788->camera;
    w3d_matrix_from_801f6c2c(&m, (*(GetFn *)(*(char **)cam + 24))(cam));
    Vec axis(1.0f, 0.0f, 0.0f);
    Vec o;
    m.rotate(o, axis);
    float view = atan2_802e7e5c(o.z, o.x);
    Vec rot(0.0f, 0.0f, 0.0f);
    rot.y = view + 3.1415927f - wobble + heading;
    void *node = self->node;
    (*(SetRot *)(*(char **)node + 80))(node, rot, 0);
    if ((float)self->start + 500.0f < (float)now) self->t = 1.0f;
    else self->t = (float)(now - self->start) / 500.0f;
    if (self->reversed == 0) self->t = 1.0f - self->t;
    w3d_c_80130fb8(self, self->t * 0.5f + 0.5f);
    self->time = now;
    w3d_d_80131338(self);
    if (self->pending == -1) w3d_e_80130ed8(self);
    return 0;
}
