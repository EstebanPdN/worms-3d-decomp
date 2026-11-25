#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_801b4060.c"
/* String search with observed range layouts. */
typedef struct S10StringList28 { char reserved[28]; Ptr32<Ptr32<const char>> begin; Ptr32<Ptr32<const char>> end; } S10StringList28;
extern int fn_802ef074(Ptr32<const char>, Ptr32<const char>);
typedef struct S10StringList72 { char reserved[72]; Ptr32<Ptr32<const char>> begin; Ptr32<Ptr32<const char>> end; } S10StringList72;

int w3d_s10_find_string_801b4060(Ptr32<const S10StringList28> list, Ptr32<const char> value)
{
    Ptr32<Ptr32<const char>> end = list->end;
    Ptr32<Ptr32<const char>> entry = list->begin;
    while (entry != end) {
        if (fn_802ef074(value, *entry) == 0)
            return entry - list->begin;
        ++entry;
    }
    return -1;
}

int w3d_s10_find_string_801b40d0(Ptr32<const S10StringList72> list, Ptr32<const char> value)
{
    Ptr32<Ptr32<const char>> end = list->end;
    Ptr32<Ptr32<const char>> entry = list->begin;
    while (entry != end) {
        if (fn_802ef074(value, *entry) == 0)
            return entry - list->begin;
        ++entry;
    }
    return -1;
}

}
