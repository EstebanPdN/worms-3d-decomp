#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_v_802c43ec.c"
// desc: Appears to open a named resource through a global service, store the returned interface and notify it, or close the current one for an empty name.
struct S21Resource;
struct S21ResourceMethods { Ptr32<void (Ptr32<struct S21Resource>)> reserved[5]; Ptr32<void (Ptr32<struct S21Resource>)> retain; };
struct S21Resource { Ptr32<struct S21ResourceMethods> methods; };
struct S21Service;
struct S21ServiceMethods { Ptr32<void (void)> reserved[23]; Ptr32<int (Ptr32<struct S21Service>, Ptr32<const char>, Ptr32<Ptr32<struct S21Resource>>)> open; };
struct S21Service { Ptr32<struct S21ServiceMethods> methods; };
struct S21Globals { char pad[108]; Ptr32<struct S21Service> service; };
struct S21Player { char pad[236]; Ptr32<struct S21Resource> resource; int open; };
extern Ptr32<struct S21Globals> lbl_804b1788;
extern void fn_802c4380(Ptr32<struct S21Player>);
void w3d_s21_player_open_802c43ec(Ptr32<struct S21Player> self, Ptr32<const char> name)
{
    Ptr32<struct S21Service> service;
    if (name == 0 || *name == 0) {
        fn_802c4380(self);
        return;
    }
    if (self->open)
        fn_802c4380(self);
    service = lbl_804b1788->service;
    if (service) {
        if (service->methods->open(service, name, &self->resource) >= 0) {
            Ptr32<struct S21Resource> resource = self->resource;
            self->open = 1;
            resource->methods->retain(resource);
        }
    }
}

}
