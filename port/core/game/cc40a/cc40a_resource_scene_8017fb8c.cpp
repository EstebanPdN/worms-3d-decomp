#include "w3d_ptr.h"
#line 1 "cc40a_resource_scene_8017fb8c.cpp"
// Inferred partial views of the queried interface and runtime type chain.
// The query fills one local pointer; the original does not initialize it beforehand.
struct cc40a_Type { unsigned char unknown00[20]; Ptr32<const cc40a_Type> parent; };
struct cc40a_Interface;
struct cc40a_InterfaceVtable { Ptr32<void> unused00[3]; Ptr32<int (Ptr32<cc40a_Interface>)> retain; Ptr32<int (Ptr32<cc40a_Interface>)> release; Ptr32<Ptr32<const cc40a_Type> (Ptr32<cc40a_Interface>)> getType; };
struct cc40a_Interface { Ptr32<cc40a_InterfaceVtable> vtable; };
struct cc40a_Resource;
struct cc40a_ResourceVtable { Ptr32<void> unused00[14]; Ptr32<int (Ptr32<cc40a_Resource>, Ptr32<const void>, int, Ptr32<Ptr32<cc40a_Interface>>)> query; };
struct cc40a_Resource { Ptr32<cc40a_ResourceVtable> vtable; };
struct cc40a_SceneBinding { unsigned char unknown00[40]; Ptr32<cc40a_Resource> resource; unsigned char unknown2c[8]; Ptr32<cc40a_Interface> scene; };
extern "C" const unsigned char cc40a_queryKey_8040e158[];
extern "C" const cc40a_Type cc40a_sceneType_80362158[];
inline bool cc40a_isScene(Ptr32<const cc40a_Type> type){
 while(type!=cc40a_sceneType_80362158){
  if(type==type->parent)return false;
  type=type->parent;
 }
 return true;
}
extern "C" void cc40a_resource_scene_8017fb8c(Ptr32<cc40a_SceneBinding> self){
 Ptr32<cc40a_Interface> local;
 self->resource->vtable->query(self->resource,cc40a_queryKey_8040e158,0,&local);
 Ptr32<cc40a_Interface> scene=local;
 if(!scene || !cc40a_isScene(scene->vtable->getType(scene)))scene=0;
 if(scene)scene->vtable->retain(scene);
 if(self->scene)self->scene->vtable->release(self->scene);
 self->scene=scene;
 if(local)local->vtable->release(local);
}


