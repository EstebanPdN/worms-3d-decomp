#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_eo_801e4ce0.c"
// desc: Appears to start a voice for a sound object: it checks the object's sound slot, queries its id twice, starts the voice with fixed volume and pan and records the handle in both records, returning one, or zero without a sound.
struct S21Sound;
struct S21SoundMethods { Ptr32<void (void)> reserved[16]; Ptr32<int (Ptr32<struct S21Sound>)> id; };
struct S21Sound { Ptr32<struct S21SoundMethods> methods; };
struct S21Object;
struct S21ObjectMethods { Ptr32<void (void)> reserved[18]; Ptr32<int (Ptr32<struct S21Object>)> time; };
struct S21Object { Ptr32<struct S21ObjectMethods> methods; char pad[52]; int voice; char pad1[28]; Ptr32<struct S21Sound> sound; };
struct S21Voice { int time; Ptr32<struct S21Sound> sound; int pad8; Ptr32<struct S21Object> owner; int handle; };
extern int fn_80322938(unsigned, int, int, int);
int w3d_s21_start_voice_801e4ce0(Ptr32<struct S21Voice> voice, Ptr32<struct S21Object> object)
{
    Ptr32<struct S21Sound> sound = object->sound;
    int handle;
    if (sound == 0)
        return 0;
    if (sound->methods->id(sound) >= 0) {
        voice->time = object->methods->time(object);
        handle = fn_80322938((unsigned short)sound->methods->id(sound), 127, 64, 0);
        voice->owner = object;
        voice->handle = handle;
        voice->sound = object->sound;
        object->voice = handle;
    }
    return 1;
}

}
