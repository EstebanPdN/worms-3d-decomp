typedef struct S12BindingFields { int a, b, c, d; } S12BindingFields;
typedef struct S12PropertySource { char reserved[20]; S12BindingFields fields; int state; } S12PropertySource;
typedef struct S12PropertyBinding { void *unknown; void *vtable; int state; S12BindingFields fields; } S12PropertyBinding;
extern void *fn_801fe1d8(int);
extern void fn_801eb058(S12PropertyBinding *);
extern void fn_801eb0a8(S12PropertyBinding *, S12PropertySource *);
extern void fn_801e8bc4(void *, S12PropertyBinding *);
extern char lbl_804175d0[];
S12PropertyBinding *w3d_s12_create_binding_801eb674(void *owner, S12PropertySource *source)
{
    S12PropertyBinding *binding = fn_801fe1d8(28);
    int state, a, b, c, d;
    fn_801eb058(binding);
    binding->vtable = lbl_804175d0;
    fn_801eb0a8(binding, source);
    state = source->state;
    binding->fields = source->fields;
    binding->state = state;
    fn_801e8bc4(owner, binding);
    return binding;
}
