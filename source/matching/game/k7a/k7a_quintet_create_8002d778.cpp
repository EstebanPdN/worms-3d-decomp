struct K7aStateClass { char pad0[34]; unsigned short count; };
struct K7aQuintet
{
    const void *vtable;
    int links;               // +4: registry link
    char pad8[84];
    void *parts[5];          // +92
};
extern "C" K7aStateClass w3d_state_class_8035fdc0;
extern "C" const void *w3d_vtable_8040e430[];
extern "C" void *w3d_heap_allocate_entry_a(unsigned int size);
extern "C" int w3d_cx13a_initialize_property_owner_8004db14(K7aQuintet *self);
extern "C" void w3d_state_register(K7aStateClass *list, void *link);

extern "C" K7aQuintet *w3d_k7a_quintet_create_8002d778()
{
    K7aQuintet *self = (K7aQuintet *)w3d_heap_allocate_entry_a(112);
    w3d_cx13a_initialize_property_owner_8004db14(self);
    self->vtable = w3d_vtable_8040e430;
    void **part = self->parts;
    for (int i = 0; i < 5; i++)
        *part++ = 0;
    w3d_state_register(&w3d_state_class_8035fdc0, self ? &self->links : 0);
    w3d_state_class_8035fdc0.count++;
    return self;
}
