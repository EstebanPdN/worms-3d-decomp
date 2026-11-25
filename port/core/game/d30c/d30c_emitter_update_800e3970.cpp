#include "w3d_ptr.h"
#line 1 "d30c_emitter_update_800e3970.cpp"
// d30c: 0x800e3970. Emitter update: spawns parts when the interval has elapsed, picks random next intervals, updates active parts against a floor height and retires the emitter once nothing is alive. Names are inferred; classes are partial views.
extern const char logic_name_8038a028[] = "ParticleEmitterLogicEntity";
struct Type { char u0[340]; Ptr32<char> s340; char u344[44]; unsigned short u388; char u390[4]; unsigned short u394; char u396[2]; unsigned short u398; char u400[4]; unsigned short u404, u406; char u408[4]; unsigned short u412, u414, u416; char u418[2]; unsigned short u420; char u422[6]; int u428, u432; char u436[12]; int u448; char u452[8]; int u460; };
struct Box { float x, y, z; float rest[5]; };
struct Bounds { float x, y, z; float rest[3]; };
struct Part;
struct PartVt { Ptr32<void> u[4]; Ptr32<int (Ptr32<Part>, unsigned int, Ptr32<Type>)> alive; Ptr32<void> u20[4]; Ptr32<void (Ptr32<Part>, unsigned int, Ptr32<Box>, Ptr32<Type>, int)> state; };
struct Part { char u0[104]; unsigned char flag; char u105[7]; Ptr32<PartVt> vt;
    bool on() { bool r = true; if (flag == 0) r = false; return r; } };
struct Pool;
struct PoolVt { Ptr32<void> u[5]; Ptr32<Ptr32<Part> (Ptr32<Pool>, unsigned int)> get; };
struct Pool { Ptr32<PoolVt> vt; };
struct Fx;
struct FxVt { Ptr32<void> u[22]; Ptr32<void (Ptr32<Fx>, int)> show; };
struct Fx { Ptr32<FxVt> vt; };
struct FxList { Ptr32<Ptr32<Fx>> p; Ptr32<Fx> & operator[](unsigned i) { return p[i]; } Ptr32<Fx> at(unsigned i) { return p[i]; } };
struct SubVt { Ptr32<void> u[2]; Ptr32<void (Ptr32<void>, Ptr32<Part>, unsigned int, int)> spawn; };
struct Self { char u0[20]; Ptr32<void> u20; char u24[4]; Ptr32<void> u28; Ptr32<Pool> u32; unsigned u36; int u40, u44; unsigned u48; int u52, u56; char u60[48]; char u108[12]; int u120; unsigned u124, u128; char u132[8]; unsigned u140; char u144[12]; Ptr32<void> u156; char u160[16]; int u176; int u180; char u184[52]; Ptr32<void> u236; char u240[16]; Ptr32<SubVt> u256; char u260[16]; int u276; FxList u280; unsigned u284[16]; };

extern "C" int is_one_8006e71c(Ptr32<Self>);
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Type> cast_801797b4(Ptr32<void>);
extern "C" int sweep_800df570(Ptr32<void>);
extern "C" void mark_800dca14(Ptr32<Part>, int);
extern "C" int forward_800e5d4c(Ptr32<void>, unsigned, Ptr32<char>, int);
extern "C" float rnd_801610a0(Ptr32<Self>);
extern "C" void kill_800e422c(Ptr32<Self>, unsigned);
extern "C" void start_800ddcbc(Ptr32<Part>, unsigned, Ptr32<Bounds>, Ptr32<Type>, int, int);
extern "C" float frac_800de5b4(Ptr32<Part>, unsigned);
extern "C" void jitter_800dff7c(Ptr32<Box>, Ptr32<void>, Ptr32<Type>, float);
extern "C" Ptr32<void> empty_80342a74(Ptr32<void>);
extern "C" float value_80178df0(Ptr32<void>);
extern "C" void tick_800e464c(Ptr32<Self>, unsigned, unsigned);
extern "C" void finish_8015fd1c(Ptr32<Self>);
inline int spread(Ptr32<Self> self, int n) { return (int)((rnd_801610a0(self) - 0.5f) * 2.0f * n); }
extern "C" int d30c_emitter_update_800e3970(Ptr32<Self> self, unsigned now) {
    if (is_one_8006e71c(self)) return 20;
    if (self->u32 == 0) return 20;
    int alive = 0;
    Ptr32<Type> t = cast_801797b4(empty_80341584(self->u156));
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
            Ptr32<Part> p = self->u32->vt->get(self->u32, i);
            if (ready && !p->on()) {
                self->u124++;
                self->u128++;
                self->u256->spawn(&self->u28, p, now, 1);
                mark_800dca14(p, 1);
                Ptr32<char> s = t->s340;
                if (((Ptr32<unsigned short>)s)[-2]) forward_800e5d4c(self->u20, i, s, 0);
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
                    Ptr32<Bounds> q = &b;
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
                Ptr32<Fx> &o = *(Ptr32<Ptr32<Fx>>)w3d::G((i * 4 + (int)w3d::H(self->u280.p)));
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


