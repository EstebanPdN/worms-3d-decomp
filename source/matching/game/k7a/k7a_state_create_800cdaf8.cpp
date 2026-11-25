struct K7aStateClass { char pad0[34]; unsigned short count; };
struct K7aState { char pad0[4]; int links; };
extern "C" K7aStateClass w3d_state_class_80360ba0;
extern "C" void *w3d_heap_allocate_entry_a(unsigned int size);
extern "C" K7aState *w3d_state_init_800cdbcc(void *storage);
extern "C" void w3d_state_register(K7aStateClass *list, void *link);

extern "C" K7aState *w3d_k7a_state_create_800cdaf8()
{
    K7aState *self = w3d_state_init_800cdbcc(w3d_heap_allocate_entry_a(316));
    w3d_state_register(&w3d_state_class_80360ba0, self ? &self->links : 0);
    w3d_state_class_80360ba0.count++;
    return self;
}
