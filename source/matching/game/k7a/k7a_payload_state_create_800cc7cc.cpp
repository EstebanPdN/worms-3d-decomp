struct K7aStateClass { char pad0[34]; unsigned short count; };
struct K7aPayloadState { char pad0[4]; int links; };
extern "C" K7aStateClass w3d_state_class_80360b70;
extern "C" void *w3d_heap_allocate_entry_a(unsigned int size);
extern "C" K7aPayloadState *w3d_payload_state_init_800cc8a0(void *storage);
extern "C" void w3d_state_register(K7aStateClass *list, void *link);

extern "C" K7aPayloadState *w3d_k7a_payload_state_create_800cc7cc()
{
    K7aPayloadState *self = w3d_payload_state_init_800cc8a0(w3d_heap_allocate_entry_a(68));
    w3d_state_register(&w3d_state_class_80360b70, self ? &self->links : 0);
    w3d_state_class_80360b70.count++;
    return self;
}
