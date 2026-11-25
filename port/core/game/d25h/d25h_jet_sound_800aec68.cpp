#include "w3d_ptr.h"
#line 1 "d25h_jet_sound_800aec68.cpp"
// Jet sound update (Worms 3D GameCube PAL, 0x800aec68, 460 bytes).
//
// Field names are inferred. The unit's .rodata starts with the Jetpack.End sound
// name from the same source file, which keeps the pool (0.0f at 4 past an 8-byte
// boundary, 1.0f, then the conversion double) at its original place.

extern const char lbl_803821e8[] = "Jetpack.End";
struct Vec3 { float x, y, z; };
struct Sound;
struct SoundVt {
    Ptr32<void> u0[5];
    Ptr32<void (Ptr32<Sound>)> start;      // +20
    Ptr32<void (Ptr32<Sound>)> stop;       // +24
    Ptr32<void> u28[2];
    Ptr32<int (Ptr32<Sound>)> playing;     // +36
    Ptr32<void> u40[2];
    Ptr32<void (Ptr32<Sound>, int, int)> setInt;    // +48
    Ptr32<void (Ptr32<Sound>, int, float)> setFloat;  // +52
    Ptr32<void (Ptr32<Sound>, int, Ptr32<Vec3>)> setVec;   // +56
    Ptr32<void (Ptr32<Sound>, int, Ptr32<int>)> getInt;    // +60
};
struct Sound { Ptr32<SoundVt> vt; };
extern "C" float fn_80178df0(Ptr32<void>);
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
struct Jet { unsigned char u0[96]; Ptr32<Sound> sound; unsigned char u100[12]; Ptr32<void> clip; };
extern "C" void w3d_d25h_jet_sound_800aec68(Ptr32<Jet> self, Ptr32<Vec3> pos, float speed) {
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


