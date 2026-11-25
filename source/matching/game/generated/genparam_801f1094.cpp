/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef unsigned int size_t;
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
struct W3dPair { int word0; int word1; };
extern "C" char w3d_vtable_80417850[];
extern "C" void fn_801eb0a8(void *binding, char *source);
extern "C" int fn_801e8bc4(void *owner, void *binding);
struct W3dBindingBase_801eb058 {
    int unknown_00;
    W3dBindingBase_801eb058();
};
struct W3dBinding_80417850 : W3dBindingBase_801eb058 {
    void *vtable;
    int unknown_08[6];
    W3dPair first;
    W3dPair second;
    static void *operator new(size_t size);
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

extern "C" W3dBinding_80417850 *w3d_binding_create_801f1094(void *owner, char *source)
{
    W3dBinding_80417850 *binding = new W3dBinding_80417850(source);
    fn_801e8bc4(owner, binding);
    return binding;
}
