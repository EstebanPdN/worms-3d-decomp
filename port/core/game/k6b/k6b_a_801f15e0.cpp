#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_801f15e0.c"
struct K6bSpan { int start; int end; };
struct K6bValueNode {
    Ptr32<void> base;
    Ptr32<Ptr32<void>> vtable;
    char body[4];
    struct K6bSpan first;
    struct K6bSpan second;
};
struct K6bValueSource {
    char head[20];
    struct K6bSpan first;
    struct K6bSpan second;
};
extern Ptr32<void> lbl_804179a0[];
extern Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
extern void w3d_auto_801eb058(Ptr32<struct K6bValueNode> node);
extern void w3d_set_801eb0a8(Ptr32<struct K6bValueNode> node, Ptr32<struct K6bValueSource> source);
extern int w3d_s12_append_value_801e8bc4(Ptr32<void> owner, Ptr32<struct K6bValueNode> node);
Ptr32<struct K6bValueNode> w3d_k6b_value_node_clone_801f15e0(Ptr32<void> owner, Ptr32<struct K6bValueSource> source)
{
    Ptr32<struct K6bValueNode> node = (Ptr32<struct K6bValueNode>)w3d_heap_allocate_entry_a(28);
    w3d_auto_801eb058(node);
    node->vtable = lbl_804179a0;
    w3d_set_801eb0a8(node, source);
    {
        struct K6bSpan first = source->first;
        struct K6bSpan second = source->second;
        node->second = second;
        node->first = first;
    }
    w3d_s12_append_value_801e8bc4(owner, node);
    return node;
}
// desc: w3d_k6b_value_node_clone_801f15e0: Appears to allocate a 28-byte node, construct it with vtable 0x804179a0, copy the source through 0x801eb0a8 and two spans, and append it to the owner.

}
