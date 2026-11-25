struct s8_Interface { void (**vtable)(); };
struct s8_Context { char pad0[32]; void *mesh; };
extern "C" s8_Interface *fn_80343584(void *);
extern "C" void s8_mesh_forward_800da818(s8_Context *context,int value) {
    s8_Interface *mesh=fn_80343584(context->mesh);
    ((void (*)(s8_Interface *,int))mesh->vtable[22])(mesh,value);
}
