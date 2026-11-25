// d30c: 0x800e3970. Emitter update: spawns parts when the interval has elapsed, picks random next intervals, updates active parts against a floor height and retires the emitter once nothing is alive. Names are inferred; classes are partial views.
extern const char logic_name_8038a028[] = "ParticleEmitterLogicEntity";
struct Type { char u0[340]; char *s340; char u344[44]; unsigned short u388; char u390[4]; unsigned short u394; char u396[2]; unsigned short u398; char u400[4]; unsigned short u404, u406; char u408[4]; unsigned short u412, u414, u416; char u418[2]; unsigned short u420; char u422[6]; int u428, u432; char u436[12]; int u448; char u452[8]; int u460; };
struct Box { float x, y, z; float rest[5]; };
struct Bounds { float x, y, z; float rest[3]; };
struct Part;
struct PartVt { void *u[4]; int (*alive)(Part *, unsigned, Type *); void *u20[4]; void (*state)(Part *, unsigned, Box *, Type *, int); };
struct Part { char u0[104]; unsigned char flag; char u105[7]; PartVt *vt;
    bool on() { bool r = true; if (flag == 0) r = false; return r; } };
struct Pool;
struct PoolVt { void *u[5]; Part *(*get)(Pool *, unsigned); };
struct Pool { PoolVt *vt; };
struct Fx;
struct FxVt { void *u[22]; void (*show)(Fx *, int); };
struct Fx { FxVt *vt; };
struct FxList { Fx **p; Fx *&operator[](unsigned i) { return p[i]; } Fx *at(unsigned i) { return p[i]; } };
struct SubVt { void *u[2]; void (*spawn)(void *, Part *, unsigned, int); };
struct Self { char u0[20]; void *u20; char u24[4]; void *u28; Pool *u32; unsigned u36; int u40, u44; unsigned u48; int u52, u56; char u60[48]; char u108[12]; int u120; unsigned u124, u128; char u132[8]; unsigned u140; char u144[12]; void *u156; char u160[16]; int u176; int u180; char u184[52]; void *u236; char u240[16]; SubVt *u256; char u260[16]; int u276; FxList u280; unsigned u284[16]; };

extern "C" int is_one_8006e71c(Self *);
extern "C" void *empty_80341584(void *);
extern "C" Type *cast_801797b4(void *);
extern "C" int sweep_800df570(void *);
extern "C" void mark_800dca14(Part *, int);
extern "C" int forward_800e5d4c(void *, unsigned, char *, int);
extern "C" float rnd_801610a0(Self *);
extern "C" void kill_800e422c(Self *, unsigned);
extern "C" void start_800ddcbc(Part *, unsigned, Bounds *, Type *, int, int);
extern "C" float frac_800de5b4(Part *, unsigned);
extern "C" void jitter_800dff7c(Box *, void *, Type *, float);
extern "C" void *empty_80342a74(void *);
extern "C" float value_80178df0(void *);
extern "C" void tick_800e464c(Self *, unsigned, unsigned);
extern "C" void finish_8015fd1c(Self *);
inline int spread(Self *self, int n) { return (int)((rnd_801610a0(self) - 0.5f) * 2.0f * n); }
extern "C" int d30c_emitter_update_800e3970(Self *self, unsigned now) {
    if (is_one_8006e71c(self)) return 20;
    if (self->u32 == 0) return 20;
    int alive = 0;
    Type *t = cast_801797b4(empty_80341584(self->u156));
    self->u124 = alive;
    int dt;
    if (self->u48 == 0) {
        self->u48 = now;
        dt = 0;
        self->u40 = t->u416;
    } else dt = now - self->u36;
    int total = self->u40 + dt;
    self->u40 = total;
    int ready;
    if (self->u176 != 0) ready = 0;
    else ready = total >= t->u416 + self->u56;
    if (self->u44 >= t->u394) {
        if (self->u28) {
            if (t->u460 && !sweep_800df570(&self->u28)) {
                self->u176 = 3;
                ready = 0;
            }
            self->u28 = 0;
        }
        for (unsigned i = 0; i < self->u140; i++) {
            Part *p = self->u32->vt->get(self->u32, i);
            if (ready && !p->on()) {
                self->u124++;
                self->u128++;
                self->u256->spawn(&self->u28, p, now, 1);
                mark_800dca14(p, 1);
                char *s = t->s340;
                if (((unsigned short *)s)[-2]) forward_800e5d4c(self->u20, i, s, 0);
                if (self->u124 >= t->u404 + self->u120) {
                    ready = 0;
                    self->u40 -= t->u416 + self->u56;
                    { float r = (rnd_801610a0(self) - 0.5f) * 2.0f; int n = t->u388; self->u56 = (int)(r * n); }
                    { float r = (rnd_801610a0(self) - 0.5f) * 2.0f; int n = t->u406; self->u120 = (int)(r * n); }
                }
            }
            if (p->on()) {
                if (!p->vt->alive(p, now, t)) {
                    kill_800e422c(self, i);
                } else {
                    Box a;
                    Bounds b;
                    Bounds *q = &b;
                    p->vt->state(p, now, &a, t, 0);
                    start_800ddcbc(p, now, q, t, 0, 0);
                    if (t->u428) jitter_800dff7c(&a, self->u108, t, frac_800de5b4(p, now));
                    float h = value_80178df0(empty_80342a74(self->u236));
                    int v = a.y - q->y * 0.5f < h;
                    if (t->u432) v ^= 1;
                    else if (t->u448) v = 0;
                    if (!v) alive++;
                    else mark_800dca14(p, 0);
                }
                if (i % t->u414 == 0) tick_800e464c(self, i, now);
            } else if (self->u276) {
                Fx *&o = *(Fx **)(i * 4 + (int)self->u280.p);
                if (o) o->vt->show(o, 0);
            }
        }
    }
    if (t->u412) {
        for (int i = 0; i < 16; i++) {
            unsigned v = self->u284[i];
            if (v && v < now) self->u284[i] = 0;
        }
    }
    int st = self->u176;
    self->u36 = now;
    if (st) {
        int dead = alive == 0;
        if (t->u420 == 0xffff && (t->u398 == t->u420 || st != 2)) dead = 1;
        if (dead) finish_8015fd1c(self);
    } else {
        int n = self->u44 + dt;
        self->u44 = n;
        if ((self->u180 & 1) == 0 && n > t->u398 + self->u52 && self->u128 >= self->u140) self->u176 = 2;
    }
    return 20;
}
