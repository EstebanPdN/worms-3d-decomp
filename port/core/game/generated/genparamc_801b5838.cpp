#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparamc_801b5838.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family templates, 2026-10-22 (third session), seventh batch. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<int (Ptr32<void>, Ptr32<void>, int)> W3dMethod3;
typedef Ptr32<int (Ptr32<void>, Ptr32<void>, Ptr32<void>)> W3dMethodP;
typedef struct W3dBlock16 { int words[16 / 4]; } W3dBlock16;
int fn_802047e0(Ptr32<void>, Ptr32<void>, int);
Ptr32<void> fn_80164fc8(Ptr32<void>);
extern char lbl_803b29c8[];
void fn_8020c510(Ptr32<void>, Ptr32<const char>, ...);

void w3d_copy_block16_801b5838(Ptr32<void> self, Ptr32<const void> source)
{
    FIELD(self, W3dBlock16, 20) = *(Ptr32<const W3dBlock16>)source;
}

void w3d_copy_block16_801c8198(Ptr32<void> self, Ptr32<const void> source)
{
    FIELD(self, W3dBlock16, 24) = *(Ptr32<const W3dBlock16>)source;
}

void w3d_copy_block16_801c81e8(Ptr32<void> self, Ptr32<const void> source)
{
    FIELD(self, W3dBlock16, 20) = *(Ptr32<const W3dBlock16>)source;
}

void w3d_copy_block16_801d1860(Ptr32<void> self, Ptr32<const void> source)
{
    FIELD(self, W3dBlock16, 64) = *(Ptr32<const W3dBlock16>)source;
}

int w3d_forward_virtual_8020017c(Ptr32<void> self, Ptr32<void> a, Ptr32<void> b)
{
    return (*(Ptr32<W3dMethodP>)(*(Ptr32<Ptr32<char>>)self + 24))(self, a, b);
}

int w3d_forward_virtual_802001a8(Ptr32<void> self, Ptr32<void> a, Ptr32<void> b)
{
    return (*(Ptr32<W3dMethodP>)(*(Ptr32<Ptr32<char>>)self + 24))(self, a, b);
}

int w3d_forward_virtual_802001d4(Ptr32<void> self, Ptr32<void> a, Ptr32<void> b)
{
    return (*(Ptr32<W3dMethodP>)(*(Ptr32<Ptr32<char>>)self + 24))(self, a, b);
}

int w3d_forward_virtual_80200460(Ptr32<void> self, Ptr32<void> a, Ptr32<void> b)
{
    return (*(Ptr32<W3dMethodP>)(*(Ptr32<Ptr32<char>>)self + 24))(self, a, b);
}

int w3d_write_swapped_word_802040e4(Ptr32<void> stream, unsigned int value)
{
    unsigned int swapped = value;
    return fn_802047e0(stream, &swapped, 4);
}

int w3d_write_swapped_word_8020412c(Ptr32<void> stream, unsigned int value)
{
    unsigned int swapped = value;
    return fn_802047e0(stream, &swapped, 4);
}

int w3d_write_swapped_word_80204574(Ptr32<void> stream, unsigned int value)
{
    unsigned int swapped = value;
    return fn_802047e0(stream, &swapped, 4);
}

int w3d_forward_to_held_8025ee60(Ptr32<Ptr32<void>> self, Ptr32<void> argument)
{
    Ptr32<void> held = *self;
    return (*(Ptr32<W3dMethod3>)(*(Ptr32<Ptr32<char>>)held + 76))(held, argument, 0);
}

int w3d_call_with_owner_8025ee94(Ptr32<Ptr32<void>> self, Ptr32<void> target)
{
    return (*(Ptr32<W3dMethod3>)(*(Ptr32<Ptr32<char>>)target + 92))(target, *self, 0);
}

int w3d_forward_to_held_802af220(Ptr32<Ptr32<void>> self, Ptr32<void> argument)
{
    Ptr32<void> held = *self;
    return (*(Ptr32<W3dMethod3>)(*(Ptr32<Ptr32<char>>)held + 76))(held, argument, 0);
}

int w3d_call_with_owner_802af254(Ptr32<Ptr32<void>> self, Ptr32<void> target)
{
    return (*(Ptr32<W3dMethod3>)(*(Ptr32<Ptr32<char>>)target + 92))(target, *self, 0);
}

int w3d_forward_to_held_802bbc90(Ptr32<Ptr32<void>> self, Ptr32<void> argument)
{
    Ptr32<void> held = *self;
    return (*(Ptr32<W3dMethod3>)(*(Ptr32<Ptr32<char>>)held + 76))(held, argument, 0);
}

int w3d_call_with_owner_802bbcc4(Ptr32<Ptr32<void>> self, Ptr32<void> target)
{
    return (*(Ptr32<W3dMethod3>)(*(Ptr32<Ptr32<char>>)target + 92))(target, *self, 0);
}

}
