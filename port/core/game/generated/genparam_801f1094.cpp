#include "w3d_ptr.h"
#line 1 "genparam_801f1094.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef unsigned int size_t;
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
struct W3dPair { int word0; int word1; };
extern "C" char w3d_vtable_80417850[];
extern "C" void fn_801eb0a8(Ptr32<void> binding, Ptr32<char> source);
extern "C" int fn_801e8bc4(Ptr32<void> owner, Ptr32<void> binding);
struct W3dBindingBase_801eb058 {
    int unknown_00;
    W3dBindingBase_801eb058();
};
struct W3dBinding_80417850 : W3dBindingBase_801eb058 {
    Ptr32<void> vtable __attribute__((aligned(__alignof__(W3dBindingBase_801eb058))));
    int unknown_08[6];
    W3dPair first;
    W3dPair second;
    static void *operator new(__SIZE_TYPE__ size);
    template <class W3dU> W3dBinding_80417850(Ptr32<W3dU> w3d_p) : W3dBinding_80417850((char *)w3d_p.get()) {}
 W3dBinding_80417850(char *source)
    {
        vtable = w3d_vtable_80417850;
        fn_801eb0a8(this, source);
        W3dPair copied_first = FIELD(source, W3dPair, 20);
        W3dPair copied_second = FIELD(source, W3dPair, 28);
        second = copied_second;
        first = copied_first;
    }
};

extern "C" Ptr32<W3dBinding_80417850> w3d_binding_create_801f1094(Ptr32<void> owner, Ptr32<char> source)
{
    Ptr32<W3dBinding_80417850> binding = new W3dBinding_80417850(source);
    fn_801e8bc4(owner, binding);
    return binding;
}


