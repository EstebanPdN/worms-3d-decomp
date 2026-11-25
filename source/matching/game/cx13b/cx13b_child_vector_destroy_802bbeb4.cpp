// PPC32 vtable slots +12/+16 are retain/release; object field meanings inferred.
struct Interface;struct Vtable{void(*slots[5])(Interface*);};struct Interface{Vtable*vtable;};inline void release(Interface*p){if(p)p->vtable->slots[4](p);}

struct Object{void*table;unsigned char opaque[24];Interface*first;unsigned char gap[24];void*storage;unsigned char gap2[28];Interface*second;};extern "C" unsigned char table_8041c860[];extern "C" void storage_802134fc(void*);extern "C" void base_8015ff2c(Object*,int);
extern "C" void w3d_cx13b_child_vector_destroy_802bbeb4(Object*self,int flags){self->table=table_8041c860;release(self->second);if(self->storage)storage_802134fc(self->storage);release(self->first);base_8015ff2c(self,flags);}

