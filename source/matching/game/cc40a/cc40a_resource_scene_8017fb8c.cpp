// Inferred partial views of the queried interface and runtime type chain.
// The query fills one local pointer; the original does not initialize it beforehand.
struct cc40a_Type { unsigned char unknown00[20]; const cc40a_Type* parent; };
struct cc40a_Interface;
struct cc40a_InterfaceVtable { void* unused00[3]; int (*retain)(cc40a_Interface*); int (*release)(cc40a_Interface*); const cc40a_Type* (*getType)(cc40a_Interface*); };
struct cc40a_Interface { cc40a_InterfaceVtable* vtable; };
struct cc40a_Resource;
struct cc40a_ResourceVtable { void* unused00[14]; int (*query)(cc40a_Resource*,const void*,int,cc40a_Interface**); };
struct cc40a_Resource { cc40a_ResourceVtable* vtable; };
struct cc40a_SceneBinding { unsigned char unknown00[40]; cc40a_Resource* resource; unsigned char unknown2c[8]; cc40a_Interface* scene; };
extern "C" const unsigned char cc40a_queryKey_8040e158[];
extern "C" const cc40a_Type cc40a_sceneType_80362158[];
inline bool cc40a_isScene(const cc40a_Type* type){
 while(type!=cc40a_sceneType_80362158){
  if(type==type->parent)return false;
  type=type->parent;
 }
 return true;
}
extern "C" void cc40a_resource_scene_8017fb8c(cc40a_SceneBinding* self){
 cc40a_Interface* local;
 self->resource->vtable->query(self->resource,cc40a_queryKey_8040e158,0,&local);
 cc40a_Interface* scene=local;
 if(!scene || !cc40a_isScene(scene->vtable->getType(scene)))scene=0;
 if(scene)scene->vtable->retain(scene);
 if(self->scene)self->scene->vtable->release(self->scene);
 self->scene=scene;
 if(local)local->vtable->release(local);
}
