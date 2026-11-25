#include "w3d_ptr.h"
#line 1 "cx14b_string_allocator_initialize_8020c9a4.cpp"

// PPC32 descriptor fields are six words. Original globals are external objects, not owned literals.
struct Descriptor{Ptr32<void> link;Ptr32<const char> name;Ptr32<void> create; Ptr32<void> destroy;unsigned size;Ptr32<void> parent;};
extern "C" char string_804b06a0[],handle_804b06a4;extern "C" const char label_803b3170[],label_803b3178[];extern "C" Descriptor descriptor_80463348[];extern "C" char parent_80463308[];
extern "C" Ptr32<void> default_803426b8(Ptr32<void>);extern "C" Ptr32<void> handle_802097ec(Ptr32<void>,Ptr32<const char>,unsigned,int);extern "C" int destroy_8020bab4();
extern "C" int create_8020baac();extern "C" void register_80200af8(Ptr32<Descriptor>);
extern "C" void w3d_cx14b_string_allocator_initialize_8020c9a4(int initialize,int priority){if(priority==65535&&initialize){default_803426b8(string_804b06a0);handle_802097ec(&handle_804b06a4,label_803b3170,8,0);Ptr32<Descriptor> d=descriptor_80463348;d->name=label_803b3178;d->create=(Ptr32<void>)create_8020baac;d->destroy=(Ptr32<void>)destroy_8020bab4;d->size=120;d->parent=parent_80463308;register_80200af8(d);}}




