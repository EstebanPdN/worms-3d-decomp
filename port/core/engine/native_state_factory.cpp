#include "w3d_ptr.h"
#line 1 "native_state_factory.cpp"
/* Inferred reference-ABI views; actual lifetime and notification core remain external. */
namespace w3d_reference_state_factory {
/* Inferred reference ABI; external registration and callback semantics unknown. */
typedef unsigned int u32;
typedef unsigned short u16;
struct NodeView { unsigned char unknown[8]; Ptr32<NodeView> next; Ptr32<NodeView> previous; };
struct RegistryView { unsigned char unknown[0x20]; unsigned short count; unsigned short w3d_flags_high; unsigned char tail[8]; Ptr32<NodeView> head; };
extern "C" {
extern RegistryView w3d_ref_state_registry;
extern Ptr32<void> w3d_ref_state_callback_argument;
extern void w3d_original_801d4544(Ptr32<void>,Ptr32<void>);
extern Ptr32<void> w3d_original_801fe1d8_for_state(u32);
extern Ptr32<void> w3d_original_8017ec0c_for_state(Ptr32<void>);
extern void w3d_state_register(Ptr32<RegistryView>,Ptr32<void>);
u32 w3d_state_completion_callback(Ptr32<void>,Ptr32<void> object) {
    w3d_original_801d4544(object,w3d_ref_state_callback_argument);
    return 0;
}
Ptr32<void> w3d_state_create(void) {
    Ptr32<void> object=w3d_original_8017ec0c_for_state(w3d_original_801fe1d8_for_state(0x74));
    Ptr32<void> subobject=object ? w3d::R(static_cast<unsigned char *>(object)+4) : 0;
    w3d_state_register(&w3d_ref_state_registry,subobject);
    ++w3d_ref_state_registry.count;
    return object;
}
void w3d_state_register(Ptr32<RegistryView> r,Ptr32<void> object) {
    Ptr32<NodeView> node=w3d::sc<NodeView *>(object);
    Ptr32<NodeView> old=r->head;
    node->previous=0;
    node->next=old;
    Ptr32<NodeView> latest=r->head;
    if(latest)latest->previous=node;
    r->head=node;
}

}

}


