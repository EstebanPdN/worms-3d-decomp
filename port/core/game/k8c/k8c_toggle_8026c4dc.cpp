#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8c_toggle_8026c4dc.c"
struct K8cHolder { char pad00[4]; };
struct K8cOwner { char pad00[0x90]; Ptr32<const char> name; };
struct K8cWidget {
    char pad00[0x28];
    Ptr32<struct K8cOwner> owner;
    char pad2c[0x16c];
    Ptr32<void> target;
    int state;
};
extern Ptr32<void> fn_80342a78(Ptr32<void> p);
extern int fn_80178d28(Ptr32<void> p, Ptr32<int> value);
extern void fn_802b1258(Ptr32<const char> name);
void w3d_k8c_widget_set_state_8026c4dc(Ptr32<struct K8cWidget> self, int state)
{
    int flag;
    Ptr32<void> target;
    if (state != self->state) {
        self->state = state;
        target = fn_80342a78(self->target);
        flag = state == 0;
        fn_80178d28(target, &flag);
        if (((Ptr32<unsigned short>)self->owner->name)[-2] != 0)
            fn_802b1258(self->owner->name);
    }
}

}
