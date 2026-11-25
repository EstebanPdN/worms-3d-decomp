#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8c_panel_release_slots_8027035c.c"
struct K8cPanel {
    char pad00[224];
    Ptr32<void> tabs[3];
    Ptr32<void> scrolls[3];
};
extern void fn_8025e0c4(Ptr32<void> tab, int flags);
extern void fn_80293528(Ptr32<void> scroll, int flags);
void w3d_k8c_panel_release_slots_8027035c(Ptr32<struct K8cPanel> self, int release_tabs, int release_scrolls)
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

}
