/* Inferred reference-ABI views; actual lifetime and notification core remain external. */
namespace w3d_reference_state_factory {
/* Inferred reference ABI; external registration and callback semantics unknown. */
typedef unsigned int u32;
typedef unsigned short u16;
struct NodeView { unsigned char unknown[8]; NodeView *next,*previous; };
struct RegistryView { unsigned char unknown[0x22]; u16 count; unsigned char tail[8]; NodeView *head; };
extern "C" {
extern RegistryView w3d_ref_state_registry;
extern void *w3d_ref_state_callback_argument;
extern void w3d_original_801d4544(void *,void *);
extern void *w3d_original_801fe1d8_for_state(u32);
extern void *w3d_original_8017ec0c_for_state(void *);
extern void w3d_state_register(RegistryView *,void *);
u32 w3d_state_completion_callback(void *,void *object) {
    w3d_original_801d4544(object,w3d_ref_state_callback_argument);
    return 0;
}
void *w3d_state_create(void) {
    void *object=w3d_original_8017ec0c_for_state(w3d_original_801fe1d8_for_state(0x74));
    void *subobject=object ? static_cast<unsigned char *>(object)+4 : 0;
    w3d_state_register(&w3d_ref_state_registry,subobject);
    ++w3d_ref_state_registry.count;
    return object;
}
void w3d_state_register(RegistryView *r,void *object) {
    NodeView *node=static_cast<NodeView *>(object);
    NodeView *old=r->head;
    node->previous=0;
    node->next=old;
    NodeView *latest=r->head;
    if(latest)latest->previous=node;
    r->head=node;
}

}

}
