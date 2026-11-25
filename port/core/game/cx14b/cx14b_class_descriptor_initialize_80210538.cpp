#include "w3d_ptr.h"
#line 1 "cx14b_class_descriptor_initialize_80210538.cpp"

// PPC32 descriptor: linkage word, name, create callback, destroy callback, size, parent pointer.
struct Descriptor{Ptr32<void> link;Ptr32<const char> name;Ptr32<void> create; Ptr32<void> destroy;unsigned size;Ptr32<void> parent;};
extern "C" char object_80463be0[];extern "C" Descriptor descriptor_80463bec[];extern "C" const char name_803b35a0[];extern "C" int callback_80210344();extern "C" char parent_80463308[];
extern "C" void construct_802109dc(Ptr32<void>);extern "C" void register_80200af8(Ptr32<Descriptor>);
extern "C" void w3d_cx14b_class_descriptor_initialize_80210538(int initialize,int priority){if(priority==65535&&initialize){construct_802109dc(object_80463be0);Ptr32<Descriptor> d=descriptor_80463bec;d->name=name_803b35a0;d->create=0;d->destroy=(Ptr32<void>)callback_80210344;d->size=0;d->parent=parent_80463308;register_80200af8(d);}}



