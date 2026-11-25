struct K4bItem {
    char pad0[11];
    unsigned char flags;
};
struct K4bVisitor;
typedef int (*K4bHandler)(struct K4bVisitor *, struct K4bItem *);
struct K4bVisitor {
    char pad0[24];
    K4bHandler *handlers;
};
struct K4bTypeDesc {
    char pad0[32];
    unsigned int handler_index : 10;
    unsigned int rest : 22;
};
extern struct K4bTypeDesc *lbl_80363938[];
extern void fn_801a4278(struct K4bItem *item);
/* A dispatch macro wrapped in do/while (0) reproduces the original register choice. */
#define K4B_DISPATCH(self, item) do { return (self)->handlers[lbl_80363938[0]->handler_index]((self), (item)); } while (0)
int w3d_k4b_visit_prepared_item_801a4c8c(struct K4bVisitor *self, struct K4bItem *item)
{
    if (item->flags & 2)
        fn_801a4278(item);
    K4B_DISPATCH(self, item);
}
// desc: w3d_k4b_visit_prepared_item_801a4c8c: Appears to prepare an item when its flag bit two is set, then dispatch it through the handler slot named by a global type descriptor.
