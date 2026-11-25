#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10_near_templates.c"
typedef struct S10Node {
    char reserved[20];
    Ptr32<struct S10Node> parent;
} S10Node;
typedef struct S10NodeList {
    char reserved[40];
    Ptr32<Ptr32<S10Node>> begin;
    Ptr32<Ptr32<S10Node>> end;
} S10NodeList;
static __inline__ int s10_is_descendant(Ptr32<S10Node> node, Ptr32<const S10Node> ancestor)
{
    while (node != ancestor) {
        Ptr32<S10Node> parent = node->parent;
        if (node == parent)
            return 0;
        node = parent;
    }
    return 1;
}
int w3d_s10_has_ancestor_801b1de0(Ptr32<const S10NodeList> list, Ptr32<S10Node> node)
{
    Ptr32<Ptr32<S10Node>> end = list->end;
    Ptr32<Ptr32<S10Node>> entry = list->begin;
    while (entry != end) {
        if (s10_is_descendant(node, *entry))
            return 1;
        ++entry;
    }
    return 0;
}

}
