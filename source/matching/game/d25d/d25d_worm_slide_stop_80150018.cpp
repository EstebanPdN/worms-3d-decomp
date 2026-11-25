// GWMP8P rev0 0x80150018. Worm slide stop test: compare the worm direction
// 0x80146f10 with the reversed velocity; when both are non-zero and the
// angle (acos of the clamped dot product) is under pi/4, or when the
// velocity is exactly zero, ask limit test 0x8014c978. On success zero the
// velocity and enter state 12, otherwise constrain the motion, enter state 9
// and post an integer message with the worm id. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void normalize();
};
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
inline void Vec::normalize() { float f = 1.0f / sqrt_802e82c0(lenSq()); x *= f; y *= f; z *= f; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline const float &clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Worm {
    unsigned char u0[584]; int id;
    unsigned char u588[88]; Vec vel;
    unsigned char u688[72]; int state;
};
extern "C" Vec motion_direction_80146f10(Worm *);
extern "C" int limit_8014c978(Vec *);
extern "C" void constrain_8014b40c(Worm *);
extern "C" void *arena_801613f0(void *, int);
extern "C" short msgid_8015f5a0(void *, int);
extern "C" void *msg_init_800a82f0(void *, unsigned short, int);
extern "C" int post_8016239c(void *);
extern void *arena_804b1754;
extern int cache_804afc60;
extern const Vec zero_8045e788[];
extern "C" void d25d_worm_slide_stop_80150018(Worm *self) {
    Vec dir = motion_direction_80146f10(self);
    Vec to = zero_8045e788[0] - self->vel;
    if (dir.lenSq() > 0.0f && to.lenSq() > 0.0f) {
        to.normalize();
        dir.normalize();
        float d = to.dot(dir);
        d = clamp(d, -1.0f, 1.0f);
        if (acos_802e79e0(d) < 0.7853982f && limit_8014c978(&dir)) {
            self->vel = zero_8045e788[0];
            self->state = 12;
        } else {
            constrain_8014b40c(self);
            self->state = 9;
            void *m = arena_801613f0(arena_804b1754, 12);
            post_8016239c(msg_init_800a82f0(m, msgid_8015f5a0(&cache_804afc60, 1), self->id));
        }
    } else if (to.lenSq() == 0.0f) {
        if (limit_8014c978(&dir)) {
            self->vel = zero_8045e788[0];
            self->state = 12;
        } else {
            constrain_8014b40c(self);
            self->state = 9;
            void *m = arena_801613f0(arena_804b1754, 12);
            post_8016239c(msg_init_800a82f0(m, msgid_8015f5a0(&cache_804afc60, 1), self->id));
        }
    }
}
