struct K8cPanel {
    char pad00[224];
    void *tabs[3];
    void *scrolls[3];
};
extern void fn_8025e0c4(void *tab, int flags);
extern void fn_80293528(void *scroll, int flags);
void w3d_k8c_panel_release_slots_8027035c(struct K8cPanel *self, int release_tabs, int release_scrolls)
{
    unsigned i;
    for (i = 0; i <= 2; i++) {
        if (release_tabs && self->tabs[i]) {
            fn_8025e0c4(self->tabs[i], 3);
            self->tabs[i] = 0;
        }
        if (release_scrolls && self->scrolls[i]) {
            fn_80293528(self->scrolls[i], 3);
            self->scrolls[i] = 0;
        }
    }
}
