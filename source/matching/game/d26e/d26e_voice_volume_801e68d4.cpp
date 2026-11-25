// (Worms 3D GameCube PAL, 0x801e68d4).
//
// Sound volume for a playing voice: the base volume from the mixer (slot 33,
// keyed by the sound id), and for a positioned emitter the distance gain:
// full below near, 0 beyond far, linear between, times the listener volume
// and clamped to [0, 1]. The first near read in the falloff branch is
// discarded, as in the original. Reading of near and far (slots 33 and 32)
// is inferred from the arithmetic.

extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
};
inline float Dist(const Vec &a, const Vec &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
}
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
struct Listener3D { void **vt; };
struct Emitter { void **vt; };
struct Sound { void **vt; };
struct Mixer { void **vt; };
extern Mixer *lbl_804ab80c;
extern "C" int w3d_sound_id_801e25d4(Sound *);
struct Player { char u[44]; Sound *sound; char v[116]; Listener3D *listener; };
typedef int (*GetFn)(Listener3D *, int, Vec *);
typedef int (*GetVolFn)(Listener3D *, int, float *);
typedef float (*FloatFn)(Emitter *);
typedef float (*SFn)(Sound *);
typedef float (*MFn)(Mixer *, int);
typedef void (*VecFn)(Emitter *, Vec *);
extern "C" float w3d_d26e_voice_volume_801e68d4(Player *self, Emitter *e) {
    float r = ((MFn)lbl_804ab80c->vt[33])(lbl_804ab80c, w3d_sound_id_801e25d4(self->sound));
    float base = r;
    if (!e) return r;
    {
        Vec lpos, pos;
        ((VecFn)e->vt[14])(e, &pos);
        ((GetFn)self->listener->vt[17])(self->listener, 3, &lpos);
        float d = Dist(lpos, pos) * ((FloatFn)e->vt[11])(e);
        float gain;
        if (d < ((SFn)self->sound->vt[33])(self->sound)) gain = 1.0f;
        else if (d > ((SFn)self->sound->vt[32])(self->sound)) gain = 0.0f;
        else {
        ((SFn)self->sound->vt[33])(self->sound);
        gain = 1.0f - (d - ((SFn)self->sound->vt[33])(self->sound)) / (((SFn)self->sound->vt[32])(self->sound) - ((SFn)self->sound->vt[33])(self->sound));
        }
        float vol = 1.0f;
        ((GetVolFn)self->listener->vt[16])(self->listener, 1, &vol);
        vol *= gain;
        vol = fmax(vol, 0.0f);
        vol = fmin(vol, 1.0f);
        return vol * base;
    }
}
