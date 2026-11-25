typedef struct S10BindingFields { int a, b, c, d; } S10BindingFields;
typedef struct S10PropertySource { char reserved[20]; S10BindingFields fields; int state; } S10PropertySource;
typedef struct S10PropertyBinding { void *unknown; void *vtable; int state; S10BindingFields fields; } S10PropertyBinding;
extern void *fn_801fe1d8(int);
extern void fn_801eb058(S10PropertyBinding *);
extern void fn_801eb0a8(S10PropertyBinding *, S10PropertySource *);
extern void fn_801e8bc4(void *, S10PropertyBinding *);
extern char lbl_804175d0[];
static __inline__ void s10_set_fields(S10PropertyBinding *binding, int a, int b, int c, int d, int state)
{
    binding->fields.a = a;
    binding->fields.b = b;
    binding->fields.c = c;
    binding->fields.d = d;
    binding->state = state;
}
S10PropertyBinding *w3d_s10_create_binding_801eb674(void *owner, S10PropertySource *source)
{
    S10PropertyBinding *binding = fn_801fe1d8(28);
    int state, a, b, c, d;
    fn_801eb058(binding);
    binding->vtable = lbl_804175d0;
    fn_801eb0a8(binding, source);
    s10_set_fields(binding, source->fields.a, source->fields.b, source->fields.c, source->fields.d, source->state);
    fn_801e8bc4(owner, binding);
    return binding;
}
