#include "w3d_ptr.h"
#line 1 "s12_member_binding.cpp"
/* The two eight-byte fields have the observed member-function-pointer layout. */
struct S12BoundObject { void method();  char w3d_empty; };
typedef w3d::Pmf<S12BoundObject, void()> S12BoundMethod;
struct S12PropertySource { char reserved[20]; S12BoundMethod read, write; int state; };
struct S12PropertyBinding { Ptr32<void> object; Ptr32<void> vtable; int state; S12BoundMethod read, write; };
extern Ptr32<void> fn_801fe1d8(int);
extern void fn_801eb058(Ptr32<S12PropertyBinding>);
extern void fn_801eb0a8(Ptr32<S12PropertyBinding>, Ptr32<S12PropertySource>);
extern int fn_801e8bc4(Ptr32<void>, Ptr32<S12PropertyBinding>);
extern char lbl_804175d0[];
extern "C" Ptr32<S12PropertyBinding> w3d_s12_create_member_binding_801eb674(Ptr32<void> owner, Ptr32<S12PropertySource> source)
{
    Ptr32<S12PropertyBinding> binding = (Ptr32<S12PropertyBinding>)fn_801fe1d8(28);
    fn_801eb058(binding);
    binding->vtable = lbl_804175d0;
    fn_801eb0a8(binding, source);
    S12BoundMethod read = source->read;
    S12BoundMethod write = source->write;
    int state = source->state;
    binding->read = read;
    binding->write = write;
    binding->state = state;
    fn_801e8bc4(owner, binding);
    return binding;
}


