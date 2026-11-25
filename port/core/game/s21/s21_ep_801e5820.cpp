#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ep_801e5820.c"
// desc: Appears to set a voice volume: it scales the argument by a factor taken from the global sound service when a link exists, converts it to a byte with a quantizing store and passes it to the voice setter.
// flags: -mfast-cast
struct S21Service;
struct S21ServiceMethods { Ptr32<void (void)> reserved[33]; Ptr32<float (Ptr32<struct S21Service>, int)> scale; };
struct S21Service { Ptr32<struct S21ServiceMethods> methods; };
struct S21Object { char pad[4]; int link; char pad1[8]; int voice; };
extern Ptr32<struct S21Service> lbl_804ab80c;
extern float lbl_803b072c[];
extern float lbl_803b0730[];
extern int fn_801df288(Ptr32<void>);
extern int fn_80322838(int, int, unsigned);
void w3d_s21_set_volume_801e5820(Ptr32<struct S21Object> self, float volume)
{
    float scale = lbl_803b072c[0];
    if (self->link) {
        Ptr32<struct S21Service> service = lbl_804ab80c;
        scale = service->methods->scale(service, fn_801df288(w3d::G(self->link)));
    }
    fn_80322838(self->voice, 7, (unsigned char)(volume * scale * lbl_803b0730[0]));
}

}
