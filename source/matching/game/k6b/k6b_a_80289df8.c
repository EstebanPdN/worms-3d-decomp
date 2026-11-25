struct K6bCardSaver {
    void **vtable;
    char head[24];
    int selection;
    int slot;
    char name[84];
    char status[16];
};
extern void fn_802fb7ac(const char *format, ...);
extern int lbl_804abb5c;
extern char lbl_803cfa48[];
extern void w3d_s4_card_unsubscribe_navigation(struct K6bCardSaver *self);
extern void fn_80288bc8(struct K6bCardSaver *self, int slot, char *name);
extern int w3d_auto_802aba18(char *status, int state);
void w3d_k6b_card_saver_save_80289df8(struct K6bCardSaver *self)
{
    fn_802fb7ac(lbl_803cfa48);
    lbl_804abb5c++;
    w3d_s4_card_unsubscribe_navigation(self);
    fn_80288bc8(self, self->slot, self->name);
    w3d_auto_802aba18(self->status, 3);
    self->selection = -1;
    ((void (*)(struct K6bCardSaver *, int))self->vtable[8])(self, 0);
}
// desc: w3d_k6b_card_saver_save_80289df8: Appears to log Saving Game File To Memory Card, bump the save counter, unsubscribe navigation, write slot +32 with the name at +36, set status 3 and reset +28.
