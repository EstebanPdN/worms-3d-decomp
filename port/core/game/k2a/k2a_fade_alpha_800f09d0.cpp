#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2a_fade_alpha_800f09d0.c"
typedef struct K2aFade {
    char pad0[68];
    int forward;
    char pad48[8];
    int start;
    unsigned char alpha;
    char pad55[11];
    int duration_ref;
    int full_ref;
} K2aFade;
extern unsigned int w3d_auto_80178d1c(Ptr32<void> ref);

void k2a_fade_alpha_800f09d0(Ptr32<K2aFade> self, int now)
{
    unsigned int elapsed = now - self->start;
    unsigned int duration = w3d_auto_80178d1c(w3d::G(self->duration_ref));
    int value;
    if (elapsed > duration) {
        if (self->forward != 0) {
            value = w3d_auto_80178d1c(w3d::G(self->full_ref));
        } else {
            self->alpha = 0;
            return;
        }
    } else {
        int full = w3d_auto_80178d1c(w3d::G(self->full_ref));
        duration = w3d_auto_80178d1c(w3d::G(self->duration_ref));
        self->alpha = (elapsed * full) / duration;
        if (self->forward != 0)
            return;
        value = w3d_auto_80178d1c(w3d::G(self->full_ref));
        value = value - self->alpha;
    }
    self->alpha = value;
}

}
