// Jet sound update (Worms 3D GameCube PAL, 0x800aec68, 460 bytes).
//
// Field names are inferred. The unit's .rodata starts with the Jetpack.End sound
// name from the same source file, which keeps the pool (0.0f at 4 past an 8-byte
// boundary, 1.0f, then the conversion double) at its original place.

extern const char lbl_803821e8[] = "Jetpack.End";
struct Vec3 { float x, y, z; };
struct Sound;
struct SoundVt {
    void *u0[5];
    void (*start)(Sound *);      // +20
    void (*stop)(Sound *);       // +24
    void *u28[2];
    int (*playing)(Sound *);     // +36
    void *u40[2];
    void (*setInt)(Sound *, int, int);    // +48
    void (*setFloat)(Sound *, int, float);  // +52
    void (*setVec)(Sound *, int, Vec3 *);   // +56
    void (*getInt)(Sound *, int, int *);    // +60
};
struct Sound { SoundVt *vt; };
extern "C" float fn_80178df0(void *);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
struct Jet { unsigned char u0[96]; Sound *sound; unsigned char u100[12]; void *clip; };
extern "C" void w3d_d25h_jet_sound_800aec68(Jet *self, Vec3 *pos, float speed) {
    if (speed > 0.0f) {
        if (self->sound->vt->playing(self->sound) == 0) self->sound->vt->start(self->sound);
        self->sound->vt->setVec(self->sound, 3, pos);
        float ratio = speed / fn_80178df0(self->clip);
        ratio = Max(ratio, 0.0f);
        ratio = Min(ratio, 1.0f);
        self->sound->vt->setFloat(self->sound, 1, ratio);
        int freq;
        self->sound->vt->getInt(self->sound, 12, &freq);
        freq += (int)((float)freq * ratio);
        self->sound->vt->setInt(self->sound, 2, freq);
    } else if (self->sound->vt->playing(self->sound)) {
        self->sound->vt->stop(self->sound);
    }
}
