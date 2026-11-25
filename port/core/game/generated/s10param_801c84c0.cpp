#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_801c84c0.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Record12 { unsigned int words[3]; } S10Record12;

void w3d_s10_set_record_flags_801c84c0(Ptr32<void> object, Ptr32<const S10Record12> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record12>)((Ptr32<char>)object + 96) = *value;
    flags[4] |= 2;
}

void w3d_s10_set_record_flags_801c84f8(Ptr32<void> object, Ptr32<const S10Record12> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record12>)((Ptr32<char>)object + 84) = *value;
    flags[4] |= 2;
}

void w3d_s10_set_record_flags_801c8530(Ptr32<void> object, Ptr32<const S10Record12> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record12>)((Ptr32<char>)object + 72) = *value;
    flags[4] |= 2;
}

void w3d_s10_set_record_flags_801c8588(Ptr32<void> object, Ptr32<const S10Record12> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record12>)((Ptr32<char>)object + 124) = *value;
    flags[4] |= 2;
}

void w3d_s10_set_record_flags_801c85c0(Ptr32<void> object, Ptr32<const S10Record12> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record12>)((Ptr32<char>)object + 112) = *value;
    flags[4] |= 2;
}

void w3d_s10_set_record_flags_801c85f8(Ptr32<void> object, Ptr32<const S10Record12> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record12>)((Ptr32<char>)object + 124) = *value;
    flags[4] |= 2;
}

void w3d_s10_set_record_flags_801c8630(Ptr32<void> object, Ptr32<const S10Record12> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record12>)((Ptr32<char>)object + 112) = *value;
    flags[4] |= 2;
}

}
