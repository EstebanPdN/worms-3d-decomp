extern void *lbl_80419598[];
extern void *lbl_804195c0[];
struct K6bNode {
    void **vtable;
    char body[8];
    void **second_vtable;
};
extern void fn_8020fe64(struct K6bNode *self);
extern void w3d_auto_801ffe58(struct K6bNode *self, void *arg);
void w3d_k6b_node_init_8020fc60(struct K6bNode *self, void *arg)
{
    self->second_vtable = lbl_80419598;
    self->vtable = lbl_804195c0;
    fn_8020fe64(self);
    w3d_auto_801ffe58(self, arg);
}
// desc: w3d_k6b_node_init_8020fc60: Appears to install the vtables at +0 and +12, then call 0x8020fe64 and 0x801ffe58 with the object and argument.
