#include "w3d_ptr.h"
#line 1 "cx13b_child_vector_destroy_802bbeb4.cpp"
// PPC32 vtable slots +12/+16 are retain/release; object field meanings inferred.
struct Interface;struct Vtable{Ptr32<void (Ptr32<Interface>)> slots[5];};struct Interface{Ptr32<Vtable> vtable;};inline void release(Ptr32<Interface> p){if(p)p->vtable->slots[4](p);}

struct Object{Ptr32<void> table;unsigned char opaque[24];Ptr32<Interface> first;unsigned char gap[24];Ptr32<void> storage;unsigned char gap2[28];Ptr32<Interface> second;};extern "C" unsigned char table_8041c860[];extern "C" void storage_802134fc(Ptr32<void>);extern "C" void base_8015ff2c(Ptr32<Object>,int);
extern "C" void w3d_cx13b_child_vector_destroy_802bbeb4(Ptr32<Object> self,int flags){self->table=table_8041c860;release(self->second);if(self->storage)storage_802134fc(self->storage);release(self->first);base_8015ff2c(self,flags);}



