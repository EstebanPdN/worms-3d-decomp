#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k7b_a_801ce3f4.c"
struct K7bSettingsBlock { int words[16]; };
struct K7bSettingsObject { Ptr32<const void> vtable; char pad04[16]; struct K7bSettingsBlock settings; };
extern int w3d_ctor_801ce28c(Ptr32<struct K7bSettingsObject> self, Ptr32<void>);
extern const char lbl_80415e70[];
extern struct K7bSettingsBlock lbl_8045e708[];
Ptr32<struct K7bSettingsObject> w3d_k7b_settings_object_ctor_801ce3f4(Ptr32<struct K7bSettingsObject> self, Ptr32<void> arg_r4)
{
    w3d_ctor_801ce28c(self, arg_r4);
    self->vtable = lbl_80415e70;
    self->settings = lbl_8045e708[0];
    return self;
}

}
