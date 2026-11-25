// d27c: 0x800ec1b4. A payload enters water: clamps the velocity to Payload.SinkSpeed.Max, scales horizontal motion by the square of the speed ratio, and enforces Payload.SinkSpeed.Min downward. Sets depth from the water level, posts messages and switches mesh. Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct W { int a, b, c; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
};
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline float absf(const float &v) { float r; *(unsigned *)&r = *(const unsigned *)&v & 0x7fffffff; return r; }
struct Desc { char u0[324]; float height; char u328[56]; char mesh[1]; };
struct Message { unsigned short id; void **vtable; };
struct Actor {
    char u0[60];
    Vec3 force;
    char u72[48];
    int settled;
    char u124[56];
    void *h180;
    char u184[8];
    void *h192;
    char u196[104];
    int notify;
};
extern W zero_8045e788[];
extern char keyMin_8038b520[], keyMax_8038b538[];
extern void *heap_804b1754;
extern int idA_804aeef0, idB_804aeef8;
extern void *vt_8040db38[];
extern "C" void *empty_80341584(void *);
extern "C" Desc *desc_801797b4(void *);
extern "C" int read_800fc270(const char **, float *);
extern "C" void *empty_80342a74(void *);
extern "C" float value_80178df0(void *);
extern "C" Message *alloc_801613f0(void *, int);
extern "C" short msg_id_8015f5a0(void *, int);
extern "C" int post_8015fc58(Actor *, Message *);
extern "C" void mesh_800ed9c8(Actor *, int, void *);
extern "C" void *init_80126000(void *, unsigned short, Vec3 *);
extern "C" int post_8016239c(void *);
extern "C" void d27c_payload_start_sinking_800ec1b4(Actor *self, Vec3 *pos, Vec3 *vel) {
    Desc *d = desc_801797b4(empty_80341584(self->h192));
    self->settled = 1;
    *(W *)&self->force = zero_8045e788[0];
    const char *k1 = keyMin_8038b520;
    float lo;
    read_800fc270(&k1, &lo);
    const char *k2 = keyMax_8038b538;
    float hi;
    read_800fc270(&k2, &hi);
    float speed = vel->len();
    speed = fmin(speed, hi);
    if (speed > 0.0f) {
        float f = 1.0f / vel->len();
        vel->x = vel->x * f * speed; vel->y = vel->y * f * speed; vel->z = vel->z * f * speed;
    }
    float r = speed / hi;
    float r2 = r * r;
    vel->x = vel->x * r2;
    vel->z = vel->z * r2;
    float sink = absf(vel->y) * r;
    sink = fmax(sink, lo);
    vel->y = -sink;
    pos->y = value_80178df0(empty_80342a74(self->h180)) - d->height;
    Message *m = alloc_801613f0(heap_804b1754, 8);
    m->id = msg_id_8015f5a0(&idA_804aeef0, 1);
    m->vtable = vt_8040db38;
    post_8015fc58(self, m);
    mesh_800ed9c8(self, 1, d->mesh);
    if (self->notify) {
        void *n = alloc_801613f0(heap_804b1754, 20);
        post_8016239c(init_80126000(n, msg_id_8015f5a0(&idB_804aeef8, 1), pos));
    }
}
