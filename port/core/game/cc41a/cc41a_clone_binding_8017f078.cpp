#include "w3d_ptr.h"
#line 1 "cc41a_clone_binding_8017f078.cpp"
// Partial owner/interface layouts inferred from accesses; names are descriptive hypotheses.
struct cc41a_Interface;
struct cc41a_InterfaceVtable {Ptr32<void> unknown00[3];Ptr32<int (Ptr32<cc41a_Interface>)> retain;Ptr32<int (Ptr32<cc41a_Interface>)> release;};
struct cc41a_Interface {Ptr32<cc41a_InterfaceVtable> vtable;};
struct cc41a_Resource;
struct cc41a_ResourceVtable {Ptr32<void> unknown00[14];Ptr32<int (Ptr32<cc41a_Resource>, Ptr32<const void>, int, Ptr32<Ptr32<cc41a_Interface>>)> query;};
struct cc41a_Resource {Ptr32<cc41a_ResourceVtable> vtable;};
union cc41a_Flags {unsigned int word;w3d::be_array<unsigned char, 4> bytes;};
struct cc41a_Binding {unsigned char unknown00[24];cc41a_Flags flags;unsigned int unknown1c,value;unsigned int unknown24;Ptr32<cc41a_Resource> resource;unsigned int copied;Ptr32<cc41a_Interface> held;};
struct cc41a_Local {Ptr32<cc41a_Interface> pointer;cc41a_Local():pointer(0){}~cc41a_Local(){if(pointer)pointer->vtable->release(pointer);}};
extern "C" Ptr32<cc41a_Binding> cc41a_identity_80341348(Ptr32<cc41a_Binding>);
extern "C" void cc41a_scene_8017fb8c(Ptr32<cc41a_Binding>);
extern "C" const unsigned char cc41a_queryKey_8040e078[];
extern "C" int cc41a_clone_binding_8017f078(Ptr32<cc41a_Binding> self,Ptr32<cc41a_Binding> input){
 Ptr32<cc41a_Binding> source=cc41a_identity_80341348(input);
 self->flags.bytes[1]=source->flags.bytes[1];
 self->value=source->value;
 self->copied=source->copied;
 self->flags.word|=0x8000;
 cc41a_scene_8017fb8c(self);
 cc41a_Local local;
 if(self->resource->vtable->query(self->resource,cc41a_queryKey_8040e078,0,&local.pointer)<0)return (int)0x80004005u;
 Ptr32<cc41a_Interface> incoming=local.pointer;
 if(incoming)incoming->vtable->retain(incoming);
 if(self->held)self->held->vtable->release(self->held);
 self->held=incoming;
 return 0;
}


