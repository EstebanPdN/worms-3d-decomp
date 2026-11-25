/* The two eight-byte fields have the observed member-function-pointer layout. */
struct S12BoundObject { void method(); };
typedef void (S12BoundObject::*S12BoundMethod)();
struct S12PropertySource { char reserved[20]; S12BoundMethod read, write; int state; };
struct S12PropertyBinding { void *object; void *vtable; int state; S12BoundMethod read, write; };
extern void *fn_801fe1d8(int);
extern void fn_801eb058(S12PropertyBinding *);
extern void fn_801eb0a8(S12PropertyBinding *, S12PropertySource *);
extern int fn_801e8bc4(void *, S12PropertyBinding *);
extern char lbl_804175d0[];
extern "C" S12PropertyBinding *w3d_s12_create_member_binding_801eb674(void *owner, S12PropertySource *source)
{
    S12PropertyBinding *binding = (S12PropertyBinding *)fn_801fe1d8(28);
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
