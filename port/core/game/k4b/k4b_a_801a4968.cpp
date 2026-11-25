#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801a4968.c"
struct K4bNode {
    char pad0[6];
    unsigned short kind;
};
struct K4bVisitor;
typedef Ptr32<int (Ptr32<struct K4bVisitor>, Ptr32<struct K4bNode>)> K4bHandler;
struct K4bVisitor {
    char pad0[24];
    Ptr32<K4bHandler> handlers;
};
struct K4bItem {
    char pad0[92];
    Ptr32<struct K4bNode> head;
};
extern int w3d_s20_dispatch_five_targets_801a4874(Ptr32<struct K4bVisitor> self, Ptr32<struct K4bItem> item);
int w3d_k4b_visit_head_then_targets_801a4968(Ptr32<struct K4bVisitor> self, Ptr32<struct K4bItem> item)
{
    Ptr32<struct K4bNode> head = item->head;
    int status;
    if (head != 0) {
        status = self->handlers[head->kind](self, head);
        if (status < 0)
            return status;
    } else
        return 0;
    return w3d_s20_dispatch_five_targets_801a4874(self, item);
}
// desc: w3d_k4b_visit_head_then_targets_801a4968: Appears to dispatch an item's head node through the handler table by kind, then its five optional targets; returns zero when there is no head.

}
