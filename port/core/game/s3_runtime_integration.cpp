#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_runtime_integration.c"
/* Runtime owners and retained service interfaces; names are inferred. */
typedef Ptr32<void (Ptr32<void>)> Method;
typedef struct Interface {Ptr32<Method> vtable;} Interface;
typedef struct Text {Ptr32<char> data;} Text;
typedef struct FileOwner {
 Ptr32<Method> vtable; unsigned char node[4];unsigned int kind;Text path;
 Ptr32<Interface> files; Ptr32<Interface> archives;int from_cd;
} FileOwner;
typedef struct RuntimeOwner {
 Ptr32<Method> vtable;unsigned char pad04[0x2c];Ptr32<Interface> view;
 unsigned char pad34[0x10];Ptr32<Interface> service;int word48;unsigned int state;
 int quantum,remainder,mode,word5c;Ptr32<Interface> core; Ptr32<Interface> context; Ptr32<Interface> input; Ptr32<Interface> renderer; Ptr32<Interface> output;
 int value,word78;
} RuntimeOwner;
typedef struct Descriptor {
 Ptr32<const char> name;int word04,word08,word0c;Ptr32<void> word10;int word14;Ptr32<void> word18;
 int word1c,word20,word24;
} Descriptor;
extern Method w3d_vtable_804111a0[],w3d_vtable_80411168[],w3d_vtable_804111c8[];
extern Ptr32<FileOwner> w3d_singleton_804b17ec;
extern Ptr32<Ptr32<Interface>> w3d_handle_804b1880;
extern unsigned char w3d_object_80412790[],w3d_object_804143e0[],w3d_object_80412240[],w3d_object_804118f8[];
extern unsigned char w3d_object_80411960[],w3d_object_804168b0[],w3d_object_80411698[],w3d_object_8040ca60[],w3d_object_804551a0[];
extern const char w3d_str_803a4348[],w3d_str_803a4368[];
extern Descriptor w3d_descriptor_804551a4[];
extern void w3d_string_default(Ptr32<Text>);
extern void w3d_string_base_finish(Ptr32<Text>);
extern void w3d_string_release(Ptr32<Text>);
extern void w3d_actor_node_destroy(Ptr32<void>,int);
extern void w3d_setting_80206920(Ptr32<const char>,Ptr32<int>);
extern void w3d_auto_80165594(Ptr32<void>);
extern Ptr32<void> w3d_runtime_base_construct_8015b4ac(Ptr32<void>);
extern void w3d_runtime_destroy_owned_resources(Ptr32<void>,int);
extern void w3d_auto_80164f88(Ptr32<void>);
extern int w3d_auto_8015b764(Ptr32<void>);
extern Ptr32<Interface> w3d_auto_8020b648(void);
extern Ptr32<Interface> w3d_lookup_8020b680(Ptr32<void>);
extern void w3d_actor_member_delete_backend(Ptr32<void>);
extern void w3d_register_80200a70(Ptr32<Descriptor>);
extern void w3d_bind_80164514(Ptr32<Interface>,Ptr32<Interface>,int);
extern void w3d_auto_8015b72c(Ptr32<void>);
void w3d_runtime_prepare_services(Ptr32<RuntimeOwner>);
void w3d_runtime_prepare_renderer(Ptr32<RuntimeOwner>);
#if 0 /* Node initialization and zero-value scheduling differ after three attempts. */
FileOwner *w3d_file_owner_construct(FileOwner *owner)
{
 int setting,result;struct Node {unsigned int a,b;} *node=(struct Node *)owner->node;
 owner->vtable=w3d_vtable_804111a0;
 ((unsigned char*)node)[7]=2;node->b=((unsigned char*)node)[7];
 owner->vtable=w3d_vtable_80411168;
 w3d_string_default(&owner->path);
 owner->files=0;owner->archives=0;setting=0;
 w3d_setting_80206920(w3d_str_803a4348,&setting);
 result=setting;if(result)result=1;
 owner->from_cd=result;w3d_singleton_804b17ec=owner;
 w3d_auto_80165594(owner);return owner;
}
#endif
void w3d_file_owner_destroy(Ptr32<FileOwner> owner)
{
 owner->vtable=w3d_vtable_80411168;
 if(owner->archives)owner->archives->vtable[4](owner->archives);
 if(owner->files)owner->files->vtable[4](owner->files);
 w3d_string_base_finish(&owner->path);w3d_string_release(&owner->path);
 owner->vtable=w3d_vtable_804111a0;w3d_actor_node_destroy(owner->node,0);
}
void w3d_file_owner_virtual_step(Ptr32<FileOwner> owner){owner->vtable[11](owner);}
int w3d_file_owner_apply_file(Ptr32<FileOwner> owner,Ptr32<void> file,int mode)
{
 if(mode==0)((Ptr32<void (Ptr32<void>, Ptr32<void>)>)owner->files->vtable[12])(owner->files,file);
 else ((Ptr32<void (Ptr32<void>, Ptr32<void>)>)owner->files->vtable[11])(owner->files,file);
 return 0;
}
int w3d_runtime_register_help(void)
{
 Ptr32<Descriptor> d=w3d_descriptor_804551a4;
 d->name=w3d_str_803a4368;d->word10=w3d_object_8040ca60;d->word18=w3d_object_804551a0;
 d->word04=0;d->word0c=0;d->word24=1;
 w3d_register_80200a70(d);return 0;
}
Ptr32<RuntimeOwner> w3d_runtime_owner_construct(Ptr32<RuntimeOwner> owner)
{
 w3d_runtime_base_construct_8015b4ac(owner);
 owner->vtable=w3d_vtable_804111c8;owner->core=0;owner->context=0;owner->input=0;owner->renderer=0;owner->output=0;owner->mode=0;owner->word78=0;owner->word5c=0;
 return owner;
}
#if 0 /* Null-register initialization is scheduled late after three attempts. */
void w3d_runtime_owner_destroy(RuntimeOwner *owner)
{
 Interface *service=owner->core;owner->vtable=w3d_vtable_804111c8;
 if(service)service->vtable[4](service);
 service=owner->renderer;owner->core=0;if(service)service->vtable[4](service);
 service=owner->context;owner->renderer=0;if(service)service->vtable[4](service);
 service=owner->output;owner->context=0;if(service)service->vtable[4](service);
 if(owner->renderer)owner->renderer->vtable[4](owner->renderer);
 if(owner->input)owner->input->vtable[4](owner->input);
 if(owner->context)owner->context->vtable[4](owner->context);
 if(owner->core)owner->core->vtable[4](owner->core);
 w3d_runtime_destroy_owned_resources(owner,0);
}
#endif
#if 0 /* Temporary interface handle stays in registers after three attempts. */
int w3d_runtime_owner_initialize(RuntimeOwner *owner)
{
 struct {Interface *pointer;int spare;} hold;
 Interface *service;unsigned char *name=w3d_object_804143e0;Interface *registry=w3d_auto_8020b648();
 ((void (*)(void *,void *))registry->vtable[23])(registry,name);
 service=w3d_lookup_8020b680(w3d_object_80412240);if(service)service->vtable[3](service);
 if(owner->context)owner->context->vtable[4](owner->context);owner->context=service;
 service=w3d_lookup_8020b680(w3d_object_804118f8);if(service)service->vtable[3](service);
 if(owner->core)owner->core->vtable[4](owner->core);owner->core=service;
 service->vtable[6](service);
 hold.pointer=w3d_lookup_8020b680(w3d_object_80411960);if(hold.pointer)hold.pointer->vtable[3](hold.pointer);
 w3d_bind_80164514(owner->core,hold.pointer,0x0babE000);
 w3d_auto_8015b72c(owner);w3d_runtime_prepare_services(owner);
 if(owner->mode==0){
 service=w3d_lookup_8020b680(w3d_object_804168b0);if(service)service->vtable[3](service);
 if(owner->renderer)owner->renderer->vtable[4](owner->renderer);owner->renderer=service;
 }
 w3d_runtime_prepare_renderer(owner);
 service=w3d_lookup_8020b680(w3d_object_80411698);if(service)service->vtable[3](service);
 if(owner->input)owner->input->vtable[4](owner->input);owner->input=service;
 w3d_bind_80164514(owner->core,service,0x0babE000);
 if(hold.pointer)hold.pointer->vtable[4](hold.pointer);
 return 0;
}
#endif
int w3d_runtime_owner_finish(Ptr32<RuntimeOwner> owner)
{
 int result;Ptr32<Interface> registry;
 w3d_auto_80164f88(owner->core);result=w3d_auto_8015b764(owner);
 registry=w3d_auto_8020b648();((Ptr32<void (Ptr32<void>, Ptr32<void>)>)registry->vtable[26])(registry,w3d_object_80412790);
 return result;
}
void w3d_runtime_replace_global_handle(Ptr32<RuntimeOwner> owner)
{
 Ptr32<Ptr32<Interface>> handle=((Ptr32<Ptr32<Ptr32<Interface>> (Ptr32<void>)>)owner->service->vtable[33])(owner->service);
 if(handle){
 Ptr32<Ptr32<Interface>> old=w3d_handle_804b1880;
 if(old){if(*old)(*old)->vtable[4](*old);w3d_actor_member_delete_backend(old);}
 owner->state&=0xff7fffff;w3d_handle_804b1880=handle;
 }
}
void w3d_runtime_query_service_handle(Ptr32<RuntimeOwner> owner){owner->service->vtable[34](owner->service);}
void w3d_runtime_prepare_services(Ptr32<RuntimeOwner> owner)
{
 owner->value=((Ptr32<int (Ptr32<void>)>)owner->service->vtable[17])(owner->service);
 owner->vtable[21](owner);owner->service->vtable[6](owner->service);owner->context->vtable[6](owner->context);
 ((Ptr32<void (Ptr32<void>, int)>)owner->service->vtable[18])(owner->service,1);
 ((Ptr32<void (Ptr32<void>, int, Ptr32<Interface>)>)owner->service->vtable[20])(owner->service,0,owner->view);
}
void w3d_runtime_prepare_renderer(Ptr32<RuntimeOwner> owner)
{
 if(owner->mode==0){owner->renderer->vtable[5](owner->renderer);
 ((Ptr32<void (Ptr32<void>, Ptr32<void>)>)owner->renderer->vtable[26])(owner->renderer,&owner->output);
 owner->vtable[22](owner);}
}
void w3d_runtime_service_set_mode(Ptr32<RuntimeOwner> owner,int mode)
{
 ((Ptr32<void (Ptr32<void>, int)>)owner->service->vtable[18])(owner->service,mode);
}

}
