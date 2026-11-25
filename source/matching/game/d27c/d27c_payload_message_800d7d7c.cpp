// d27c: 0x800d7d7c. Payload message handler: start and stop, rest check, attraction force, direct impulses addressed to this actor, hit messages, and an earthquake impulse with magnitude from the Earthquake.ImpulseMagnitude settings. Other messages go to the base handler. Names are inferred.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
inline Vec3 scaled(Vec3 a, const float &s) { return a * s; }
struct Message { unsigned short Id() const { return id; } unsigned short id; char u2[6]; int target; char u12[4]; Vec3 dir; float power; };
struct Actor;
struct ActorV { void *u[11]; void (*position)(Actor *, int, Vec3 *); };
struct Actor { ActorV *vtable; char u4[16]; int id; char u24[360]; float quakeMax; float quakeMin; };
struct Context { char u0[52]; int now; };
extern int id_804aeaf8, id_804aeb58, id_804aeb70, id_804aeb18, id_804aeb00, id_804aeb08, id_804aeb10, id_804aeb38, id_804aeb40, id_804aeb20, id_804aeb78;
extern char keyMax_803891ec[], keyMin_8038920c[];
extern "C" int base_800ea62c(Actor *, Message *);
extern "C" void start_800d80c8(Actor *);
extern "C" void stop_800d82cc(Actor *);
extern "C" int same_8015f65c(unsigned short, int *);
extern "C" void rest_800d8300(Actor *, Message *);
extern "C" Context *ctx_80165254(void);
extern "C" void attract_800ecbac(Actor *, Message *, Vec3 *, Vec3 *);
extern "C" void impulse_800d9c74(Actor *, const Vec3 &);
extern "C" void hit_800d84cc(Actor *, Message *);
extern "C" int read_800fc270(const char **, float *);
extern "C" float rand_80162bc8(void);
extern "C" int d27c_payload_message_800d7d7c(Actor *self, Message *m) {
    unsigned short id = m->Id();
    switch (m->Id()) {
    case 64:
        if (base_800ea62c(self, m) >= 0) {
            start_800d80c8(self);
            goto done;
        }
        return 0x80004005;
    case 66:
        stop_800d82cc(self);
        break;
    default:
        if (same_8015f65c(id, &id_804aeaf8)) {
            rest_800d8300(self, m);
            goto done;
        }
        if (same_8015f65c(id, &id_804aeb58)) {
            Vec3 p, f;
            self->vtable->position(self, ctx_80165254()->now, &p);
            attract_800ecbac(self, m, &p, &f);
            impulse_800d9c74(self, f);
            goto done;
        }
        if (same_8015f65c(id, &id_804aeb70)) {
            if (m->target != self->id) goto done;
            float p = m->power;
            Vec3 d = scaled(m->dir, p);
            impulse_800d9c74(self, d);
            goto done;
        }
        if (same_8015f65c(id, &id_804aeb18) || same_8015f65c(id, &id_804aeb00) || same_8015f65c(id, &id_804aeb08) || same_8015f65c(id, &id_804aeb10) || same_8015f65c(id, &id_804aeb38) || same_8015f65c(id, &id_804aeb40) || same_8015f65c(id, &id_804aeb20)) {
            if (m->target != self->id) goto done;
            hit_800d84cc(self, m);
            goto done;
        }
        if (same_8015f65c(id, &id_804aeb78)) {
            if (self->quakeMax == 0.0f) {
                const char *k1 = keyMax_803891ec;
                read_800fc270(&k1, &self->quakeMax);
                const char *k2 = keyMin_8038920c;
                read_800fc270(&k2, &self->quakeMin);
            }
            Vec3 d;
            float r0 = rand_80162bc8();
            float one = 1.0f;
            d.y = 0.2f;
            d.x = r0 + r0 - one;
            { float r = rand_80162bc8(); d.z = r + r - one; }
            float pow = rand_80162bc8() * (self->quakeMax - self->quakeMin) * 0.65f;
            d = d * pow;
            impulse_800d9c74(self, d);
            goto done;
        }
        break;
    }
    return base_800ea62c(self, m);
done:
    return 0;
}
