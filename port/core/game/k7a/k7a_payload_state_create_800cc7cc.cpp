#include "w3d_ptr.h"
#line 1 "k7a_payload_state_create_800cc7cc.cpp"
struct K7aStateClass { unsigned char pad0[0x20]; unsigned short count; unsigned short w3d_flags_high; };
struct K7aPayloadState { char pad0[4]; int links; };
extern "C" K7aStateClass w3d_state_class_80360b70;
extern "C" Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
extern "C" Ptr32<K7aPayloadState> w3d_payload_state_init_800cc8a0(Ptr32<void> storage);
extern "C" void w3d_state_register(Ptr32<K7aStateClass> list, Ptr32<void> link);

extern "C" Ptr32<K7aPayloadState> w3d_k7a_payload_state_create_800cc7cc()
{
    Ptr32<K7aPayloadState> self = w3d_payload_state_init_800cc8a0(w3d_heap_allocate_entry_a(68));
    w3d_state_register(&w3d_state_class_80360b70, self ? w3d::R(&self->links) : 0);
    w3d_state_class_80360b70.count++;
    return self;
}


