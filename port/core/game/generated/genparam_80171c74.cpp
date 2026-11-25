#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_80171c74.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef Ptr32<int (Ptr32<void>)> W3dKeyFn;
extern Ptr32<char> lbl_804b189c;
extern unsigned short lbl_804b18a4;
int fn_80185b0c(Ptr32<void> node);
extern Ptr32<char> lbl_804ab588;
extern unsigned short lbl_804ab58c;
extern Ptr32<char> lbl_804ab658;
extern unsigned short lbl_804ab65c;
extern Ptr32<char> lbl_804ab680;
extern unsigned short lbl_804ab684;

Ptr32<void> w3d_pool_next_80171c74(int key, Ptr32<int> index)
{
    Ptr32<char> found;
    if (*index < 0)
        return 0;
    found = lbl_804b189c + *index * 136;
    for (; *index < lbl_804b18a4; (*index)++) {
        if (fn_80185b0c(lbl_804b189c + *index * 136))
            break;
        if (key == ((W3dKeyFn)(*(Ptr32<Ptr32<Ptr32<void>>>)(lbl_804b189c + *index * 136))[16])(lbl_804b189c + *index * 136))
            break;
    }
    if (*index == lbl_804b18a4)
        *index = -1;
    return found;
}

Ptr32<void> w3d_pool_next_80174914(int key, Ptr32<int> index)
{
    Ptr32<char> found;
    if (*index < 0)
        return 0;
    found = lbl_804ab588 + *index * 172;
    for (; *index < lbl_804ab58c; (*index)++) {
        if (fn_80185b0c(lbl_804ab588 + *index * 172))
            break;
        if (key == ((W3dKeyFn)(*(Ptr32<Ptr32<Ptr32<void>>>)(lbl_804ab588 + *index * 172))[16])(lbl_804ab588 + *index * 172))
            break;
    }
    if (*index == lbl_804ab58c)
        *index = -1;
    return found;
}

Ptr32<void> w3d_pool_next_80184df8(int key, Ptr32<int> index)
{
    Ptr32<char> found;
    if (*index < 0)
        return 0;
    found = lbl_804ab658 + *index * 172;
    for (; *index < lbl_804ab65c; (*index)++) {
        if (fn_80185b0c(lbl_804ab658 + *index * 172))
            break;
        if (key == ((W3dKeyFn)(*(Ptr32<Ptr32<Ptr32<void>>>)(lbl_804ab658 + *index * 172))[16])(lbl_804ab658 + *index * 172))
            break;
    }
    if (*index == lbl_804ab65c)
        *index = -1;
    return found;
}

Ptr32<void> w3d_pool_next_80188750(int key, Ptr32<int> index)
{
    Ptr32<char> found;
    if (*index < 0)
        return 0;
    found = lbl_804ab680 + *index * 172;
    for (; *index < lbl_804ab684; (*index)++) {
        if (fn_80185b0c(lbl_804ab680 + *index * 172))
            break;
        if (key == ((W3dKeyFn)(*(Ptr32<Ptr32<Ptr32<void>>>)(lbl_804ab680 + *index * 172))[16])(lbl_804ab680 + *index * 172))
            break;
    }
    if (*index == lbl_804ab684)
        *index = -1;
    return found;
}

}
