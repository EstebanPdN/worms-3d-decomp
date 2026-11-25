struct K4bNode {
    char pad0[6];
    unsigned short kind;
};
struct K4bVisitor;
typedef int (*K4bHandler)(struct K4bVisitor *, struct K4bNode *);
struct K4bVisitor {
    char pad0[24];
    K4bHandler *handlers;
};
struct K4bItem {
    char pad0[92];
    struct K4bNode *head;
};
extern int w3d_s20_dispatch_five_targets_801a4874(struct K4bVisitor *self, struct K4bItem *item);
int w3d_k4b_visit_head_then_targets_801a4968(struct K4bVisitor *self, struct K4bItem *item)
{
    struct K4bNode *head = item->head;
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
