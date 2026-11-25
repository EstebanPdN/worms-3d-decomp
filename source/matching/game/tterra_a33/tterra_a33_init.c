/* Observed small-data initialization; names describe addresses, not ownership. */
extern char *lbl_804aadb4;
extern char *lbl_804ae63c, *lbl_804ae640, *lbl_804ae644, *lbl_804ae648;
extern char *lbl_804ae64c, *lbl_804ae650, *lbl_804ae654, *lbl_804ae658, *lbl_804ae65c;
struct Zero { int value; };
extern struct Zero lbl_804ae660, lbl_804ae664, lbl_804ae668;
static inline void clear(struct Zero *p) { p->value = 0; }
void tterra_a33_init_800c1580(int initialize, int priority) {
    if (priority == 65535 && initialize) {
        char *base = lbl_804aadb4;
        clear(&lbl_804ae668);
        lbl_804ae63c = base + 0x4000;
        lbl_804ae644 = base + 0x2e0;
        lbl_804ae648 = base + 0x3070;
        lbl_804ae650 = base + 0x3ff0;
        lbl_804ae654 = base + 0x3fb0;
        lbl_804ae658 = base + 0x3f30;
        lbl_804ae65c = base;
        lbl_804ae640 = base;
        lbl_804ae64c = base;
        clear(&lbl_804ae664);
        clear(&lbl_804ae660);
    }
}
