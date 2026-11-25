#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_801d0de0.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Record16 { unsigned int words[4]; } S10Record16;

void w3d_s10_set_record_flags_801d0de0(Ptr32<void> object, Ptr32<const S10Record16> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record16>)((Ptr32<char>)object + 56) = *value;
    flags[4] |= 2;
}

void w3d_s10_set_record_flags_801d0e20(Ptr32<void> object, Ptr32<const S10Record16> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record16>)((Ptr32<char>)object + 40) = *value;
    flags[4] |= 2;
}

void w3d_s10_set_record_flags_801d0e60(Ptr32<void> object, Ptr32<const S10Record16> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record16>)((Ptr32<char>)object + 24) = *value;
    flags[4] |= 2;
}

void w3d_s10_set_record_flags_801d12e0(Ptr32<void> object, Ptr32<const S10Record16> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record16>)((Ptr32<char>)object + 24) = *value;
    flags[4] |= 2;
}

void w3d_s10_set_record_flags_801d1360(Ptr32<void> object, Ptr32<const S10Record16> value)
{
    Ptr32<unsigned char> flags = (Ptr32<unsigned char>)object + 4;
    *(Ptr32<S10Record16>)((Ptr32<char>)object + 24) = *value;
    flags[4] |= 2;
}

}
