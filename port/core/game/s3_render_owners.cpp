#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_render_owners.c"
/* Renderer owner lifetimes and service setup. */
typedef Ptr32<void (Ptr32<void>)> Method;
typedef struct Interface {Ptr32<Method> vtable;} Interface;
typedef struct Collection {unsigned char data[16];} Collection;
typedef struct RenderItem {int first;Ptr32<Interface> a; Ptr32<Interface> b; Ptr32<Interface> c;Collection collection;} RenderItem;
typedef struct RenderVector {Ptr32<RenderItem> begin; Ptr32<RenderItem> end; Ptr32<RenderItem> capacity;int pad;} RenderVector;
typedef struct RenderOwner {
 Ptr32<Method> vtable;unsigned char node[20];RenderVector items;
 unsigned char pad28[16];Ptr32<Interface> scene; Ptr32<Interface> camera; Ptr32<Interface> second_camera; Ptr32<Interface> renderer;Collection collection;
 Ptr32<Interface> a; Ptr32<Interface> b; Ptr32<Interface> c; Ptr32<Interface> d; Ptr32<Interface> e; Ptr32<Interface> f; Ptr32<Interface> g;unsigned char pad74[24];int active;
 int word90;Ptr32<Interface> last;
} RenderOwner;
typedef struct Descriptor {Ptr32<const char> name;int word04,word08,word0c;Ptr32<void> word10;int word14;Ptr32<void> word18;int word1c,word20,word24;} Descriptor;
extern Method w3d_vtable_804112e0[],w3d_vtable_804114b8[],w3d_vtable_80411378[];
extern void w3d_auto_80210abc(Ptr32<Collection>,int);
extern void w3d_handle_storage_release(Ptr32<void>),w3d_actor_member_delete_backend(Ptr32<void>);
extern void w3d_actor_node_destroy(Ptr32<void>,int);
extern int w3d_render_prepare_8015e598(Ptr32<RenderOwner>);
extern void w3d_render_bind_8015f090(Ptr32<Interface>,Ptr32<Interface>);
extern Ptr32<Interface> w3d_lookup_8020b680(Ptr32<void>);
extern unsigned char w3d_object_80413a68[],w3d_object_804163f8[],w3d_object_80413c78[];
extern const char w3d_str_803a4528[];
extern unsigned char w3d_object_8040e188[],w3d_object_804551e8[];
extern Descriptor w3d_descriptor_804551ec[];
extern void w3d_register_80200a70(Ptr32<Descriptor>);
static __inline__ void release(Ptr32<Interface> value){if(value)value->vtable[4](value);}
static __inline__ void assign(Ptr32<Ptr32<Interface>> field,Ptr32<Interface> value){if(value)value->vtable[3](value);release(*field);*field=value;}
void w3d_render_owner_destroy(Ptr32<RenderOwner> owner,int flags)
{
 Ptr32<RenderVector> items;Ptr32<RenderItem> item; Ptr32<RenderItem> end;Ptr32<void> node;
 owner->vtable=w3d_vtable_804112e0;
 release(owner->last);release(owner->g);release(owner->f);release(owner->e);release(owner->d);release(owner->c);release(owner->b);release(owner->a);
 w3d_auto_80210abc(&owner->collection,2);
 release(owner->renderer);release(owner->second_camera);release(owner->camera);release(owner->scene);
 items=&owner->items;item=items->begin;end=items->end;node=owner->node;
 for(;item!=end;item++) {w3d_auto_80210abc(&item->collection,2);release(item->c);release(item->b);release(item->a);}
 if(items->begin)w3d_handle_storage_release(items->begin);
 owner->vtable=w3d_vtable_80411378;w3d_actor_node_destroy(node,0);
 if(flags&1)w3d_actor_member_delete_backend(owner);
}
int w3d_render_owner_initialize(Ptr32<RenderOwner> owner)
{
 int result=w3d_render_prepare_8015e598(owner);Ptr32<Interface> value;Ptr32<unsigned char> camera;
 if(result<0)return result;camera=w3d_object_80413a68;
 value=w3d_lookup_8020b680(camera);if(value)value->vtable[3](value);release(owner->camera);owner->camera=value;
 value=w3d_lookup_8020b680(camera);if(value)value->vtable[3](value);release(owner->second_camera);owner->second_camera=value;
 ((Ptr32<void (Ptr32<void>, int)>)value->vtable[14])(value,11);
 value=w3d_lookup_8020b680(w3d_object_804163f8);if(value)value->vtable[3](value);release(owner->g);owner->g=value;
 value=w3d_lookup_8020b680(w3d_object_80413c78);if(value)value->vtable[3](value);release(owner->renderer);owner->renderer=value;
 ((Ptr32<void (Ptr32<void>, Ptr32<void>)>)owner->scene->vtable[6])(owner->scene,value);
 w3d_render_bind_8015f090(owner->c,owner->d);return 0;
}
int w3d_render_owner_finish(Ptr32<RenderOwner> owner)
{
 Ptr32<Interface> value;
 if(owner->active)owner->a->vtable[10](owner->a);
 assign(&owner->d,0);assign(&owner->c,0);assign(&owner->b,0);assign(&owner->a,0);assign(&owner->e,0);
 return 0;
}
int w3d_render_register_service(void)
{
 Ptr32<Descriptor> d=w3d_descriptor_804551ec;
 d->name=w3d_str_803a4528;d->word10=w3d_object_8040e188;d->word18=w3d_object_804551e8;
 d->word04=0;d->word0c=0;d->word24=1;
 w3d_register_80200a70(d);return 0;
}
void w3d_render_alternate_owner_destroy(Ptr32<RenderOwner> owner,int flags)
{
 Ptr32<RenderVector> items;Ptr32<RenderItem> item; Ptr32<RenderItem> end;Ptr32<void> node;
 owner->vtable=w3d_vtable_804114b8;
 release(owner->last);release(owner->g);release(owner->f);release(owner->e);release(owner->d);release(owner->c);release(owner->b);release(owner->a);
 w3d_auto_80210abc(&owner->collection,2);
 release(owner->renderer);release(owner->second_camera);release(owner->camera);release(owner->scene);
 items=&owner->items;item=items->begin;end=items->end;node=owner->node;
 for(;item!=end;item++) {w3d_auto_80210abc(&item->collection,2);release(item->c);release(item->b);release(item->a);}
 if(items->begin)w3d_handle_storage_release(items->begin);
 owner->vtable=w3d_vtable_80411378;w3d_actor_node_destroy(node,0);
 if(flags&1)w3d_actor_member_delete_backend(owner);
}

}
