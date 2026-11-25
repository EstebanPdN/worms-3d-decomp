// Partial owner/interface layouts inferred from accesses; names are descriptive hypotheses.
struct cc41a_Interface;
struct cc41a_InterfaceVtable {void* unknown00[3];int (*retain)(cc41a_Interface*);int (*release)(cc41a_Interface*);};
struct cc41a_Interface {cc41a_InterfaceVtable* vtable;};
struct cc41a_Resource;
struct cc41a_ResourceVtable {void* unknown00[14];int (*query)(cc41a_Resource*,const void*,int,cc41a_Interface**);};
struct cc41a_Resource {cc41a_ResourceVtable* vtable;};
union cc41a_Flags {unsigned int word;unsigned char bytes[4];};
struct cc41a_Binding {unsigned char unknown00[24];cc41a_Flags flags;unsigned int unknown1c,value;unsigned int unknown24;cc41a_Resource* resource;unsigned int copied;cc41a_Interface* held;};
struct cc41a_Local {cc41a_Interface* pointer;cc41a_Local():pointer(0){}~cc41a_Local(){if(pointer)pointer->vtable->release(pointer);}};
extern "C" cc41a_Binding* cc41a_identity_80341348(cc41a_Binding*);
extern "C" void cc41a_scene_8017fb8c(cc41a_Binding*);
extern "C" const unsigned char cc41a_queryKey_8040e078[];
extern "C" int cc41a_clone_binding_8017f078(cc41a_Binding* self,cc41a_Binding* input){
 cc41a_Binding* source=cc41a_identity_80341348(input);
 self->flags.bytes[1]=source->flags.bytes[1];
 self->value=source->value;
 self->copied=source->copied;
 self->flags.word|=0x8000;
 cc41a_scene_8017fb8c(self);
 cc41a_Local local;
 if(self->resource->vtable->query(self->resource,cc41a_queryKey_8040e078,0,&local.pointer)<0)return (int)0x80004005u;
 cc41a_Interface* incoming=local.pointer;
 if(incoming)incoming->vtable->retain(incoming);
 if(self->held)self->held->vtable->release(self->held);
 self->held=incoming;
 return 0;
}
