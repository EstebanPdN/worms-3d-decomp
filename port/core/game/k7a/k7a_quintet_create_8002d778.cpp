#include "w3d_ptr.h"
#line 1 "k7a_quintet_create_8002d778.cpp"
struct K7aStateClass { unsigned char pad0[0x20]; unsigned short count; unsigned short w3d_flags_high; };
struct K7aQuintet
{
    Ptr32<const void> vtable;
    int links;               // +4: registry link
    char pad8[84];
    Ptr32<void> parts[5];          // +92
};
extern "C" K7aStateClass w3d_state_class_8035fdc0;
extern "C" Ptr32<const void> w3d_vtable_8040e430[];
extern "C" Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
extern "C" int w3d_cx13a_initialize_property_owner_8004db14(Ptr32<K7aQuintet> self);
extern "C" void w3d_state_register(Ptr32<K7aStateClass> list, Ptr32<void> link);

extern "C" Ptr32<K7aQuintet> w3d_k7a_quintet_create_8002d778()
{
    Ptr32<K7aQuintet> self = (Ptr32<K7aQuintet>)w3d_heap_allocate_entry_a(112);
    w3d_cx13a_initialize_property_owner_8004db14(self);
    self->vtable = w3d_vtable_8040e430;
    Ptr32<Ptr32<void>> part = self->parts;
    for (int i = 0; i < 5; i++)
        *part++ = 0;
    w3d_state_register(&w3d_state_class_8035fdc0, self ? w3d::R(&self->links) : 0);
    w3d_state_class_8035fdc0.count++;
    return self;
}


