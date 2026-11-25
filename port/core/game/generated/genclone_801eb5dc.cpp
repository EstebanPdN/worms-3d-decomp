#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genclone_801eb5dc.c"
/* Byte-identical copies of hand-matched leaf functions, written by
 * tools/gen_clone_units.py and verified identical to the original after
 * linking. Names are structural (address); the owning classes are unknown. */

typedef struct W3dMemberFunction {
    short delta;
    short index;
    union { Ptr32<void> function; short vtable_offset; } u;
} W3dMemberFunction;
typedef Ptr32<void (Ptr32<void>, int)> W3dSetFn;
typedef Ptr32<int (Ptr32<void>, Ptr32<int>, int, int)> W3dReadFn;
typedef struct W3dReader { Ptr32<Ptr32<void>> vtable; } W3dReader;
typedef struct W3dReaderOwner { unsigned char unknown_00[8]; Ptr32<W3dReader> reader; } W3dReaderOwner;
typedef struct W3dReadBinding {
    Ptr32<W3dReaderOwner> owner;
    unsigned char unknown_04[0x10];
    W3dMemberFunction setter;
} W3dReadBinding;

int w3d_pmf_read_801eb5dc(Ptr32<const W3dReadBinding> binding, int key, Ptr32<char> target)
{
    int value;
    int result;
    W3dSetFn set;
    Ptr32<W3dReader> reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((Ptr32<Ptr32<void>>)*(Ptr32<Ptr32<char>>)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

int w3d_pmf_read_801ebea0(Ptr32<const W3dReadBinding> binding, int key, Ptr32<char> target)
{
    int value;
    int result;
    W3dSetFn set;
    Ptr32<W3dReader> reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((Ptr32<Ptr32<void>>)*(Ptr32<Ptr32<char>>)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

int w3d_pmf_read_801ec060(Ptr32<const W3dReadBinding> binding, int key, Ptr32<char> target)
{
    int value;
    int result;
    W3dSetFn set;
    Ptr32<W3dReader> reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((Ptr32<Ptr32<void>>)*(Ptr32<Ptr32<char>>)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

int w3d_pmf_read_801ec784(Ptr32<const W3dReadBinding> binding, int key, Ptr32<char> target)
{
    int value;
    int result;
    W3dSetFn set;
    Ptr32<W3dReader> reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((Ptr32<Ptr32<void>>)*(Ptr32<Ptr32<char>>)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

int w3d_pmf_read_801ecbd4(Ptr32<const W3dReadBinding> binding, int key, Ptr32<char> target)
{
    int value;
    int result;
    W3dSetFn set;
    Ptr32<W3dReader> reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((Ptr32<Ptr32<void>>)*(Ptr32<Ptr32<char>>)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

int w3d_pmf_read_801ecd94(Ptr32<const W3dReadBinding> binding, int key, Ptr32<char> target)
{
    int value;
    int result;
    W3dSetFn set;
    Ptr32<W3dReader> reader = binding->owner->reader;
    result = ((W3dReadFn)reader->vtable[18])(reader, &value, key, 0);
    if (result >= 0) {
        if (binding->setter.index >= 0)
            set = (W3dSetFn)((Ptr32<Ptr32<void>>)*(Ptr32<Ptr32<char>>)(target + binding->setter.u.vtable_offset))[binding->setter.index - 1];
        else
            set = (W3dSetFn)binding->setter.u.function;
        set(target + binding->setter.delta, value);
    }
    return result;
}

}
