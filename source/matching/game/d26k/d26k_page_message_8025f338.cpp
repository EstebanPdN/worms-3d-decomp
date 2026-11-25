// Page message handler (Worms 3D GameCube PAL, 0x8025f338).
// 
// Message 64 forwards to the base and shows the page, 66 hides it. While the view
// at +28 is current: a click message naming this item, or a press/release pair
// while the mode is 1, activates the item's label unless it is empty or the page is
// blocked; an unavailable item reports an error through the view. Everything else
// goes to the view and then the base. The goto joins both activation paths, whose
// code is shared in the original.


struct Message { unsigned short id; };
struct Text { char *text; };
struct Item { char pad0[11]; unsigned char flags; char pad1[88 - 12]; const char *name; char pad2[128 - 92]; char *label; };
struct View {
    int word;
    int current_802b264c();
    void report_802b22b0();
    int forward_802aff9c(Message *);
};
struct Page {
    char pad0[28]; View view; char pad9[12 - sizeof(View)]; Item *item; char pad1[128 - 44]; int blocked; char pad2[140 - 132]; int ready;
    char pad3[176 - 144]; int mode; char pad4[220 - 180]; int pressed; int held;
};
extern "C" int base_8015fb34(Page *, Message *);
extern "C" void show_8025f54c(Page *);
extern "C" void hide_8025fa40(Page *);
extern "C" int same_8015f65c(unsigned short, void *);
extern "C" const char *payload_8010a8fc(Message *);
extern "C" int strcmp_802ef234(const char *, const char *);
extern "C" void activate_802b1258(const char *);
extern char cache_804b0968, cache_804b0958, cache_804b0960;
extern int global_804abb48;
extern "C" int w3d_d26k_page_message_8025f338(Page *self, Message *m) {
    char *label;
    Item *item;
    const char *text;
    int mode;
    int fire;
    Item *itm2;
    switch (m->id) {
    case 64:
        if (base_8015fb34(self, m) >= 0) { show_8025f54c(self); return 0; }
        return 0x80004005;
    case 66:
        hide_8025fa40(self);
        break;
    default:
        if (self->view.current_802b264c()) {
            if (same_8015f65c(m->id, &cache_804b0968)) {
                item = self->item;
                text = payload_8010a8fc(m);
                if (strcmp_802ef234(self->item->name, text) == 0) { if (((self->item->flags ^ 4) & 4) != 0) if (self->ready != 0) goto okitem; self->view.report_802b22b0(); return 0; okitem: label = item->label; goto use; }
            } else {
                mode = self->mode;
                if (mode == 1) {
                    fire = 0;
                    if (same_8015f65c(m->id, &cache_804b0958)) {
                        int was = self->pressed;
                        self->held = mode;
                        fire = was == 0;
                    } else if (same_8015f65c(m->id, &cache_804b0960)) {
                        if (self->pressed == 1 && self->held == 1) fire = 1;
                        self->held = 0;
                    }
if (fire == 1) { if (global_804abb48 != 0) goto zero; { itm2 = self->item; if (((itm2->flags ^ 4) & 4) != 0) if (self->ready != 0) goto ok2; self->view.report_802b22b0(); goto zero; ok2: label = itm2->label; use: if (reinterpret_cast<unsigned short *>(label)[-2] != 0 && self->blocked == 0) activate_802b1258(label); } zero: return 0; }
                }
            }
            self->view.forward_802aff9c(m);
        }
    }
    return base_8015fb34(self, m);
}
