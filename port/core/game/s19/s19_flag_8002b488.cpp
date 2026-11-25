#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_flag_8002b488.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<int (Ptr32<S19Iface>)> S19Query;
typedef Ptr32<void (Ptr32<S19Iface>, int)> S19Set;
extern Ptr32<void> w3d_s20_lookup_handle_object_80164fc8(int);

int s19_update_flag_8002b488(Ptr32<void> self)
{
    int handle = FIELD(self, int, 28);
    if (handle == -1)
        return 0;
    {
        Ptr32<void> object = w3d_s20_lookup_handle_object_80164fc8(handle);
        if (FIELD(object, int, 96) != 0) {
            if (((S19Query)FIELD(self, S19Iface *, 32)->vtable[28])(FIELD(self, S19Iface *, 32)) == 0)
                ((S19Set)FIELD(self, S19Iface *, 32)->vtable[22])(FIELD(self, S19Iface *, 32), 1);
        } else {
            if (((S19Query)FIELD(self, S19Iface *, 32)->vtable[28])(FIELD(self, S19Iface *, 32)) == 1)
                ((S19Set)FIELD(self, S19Iface *, 32)->vtable[22])(FIELD(self, S19Iface *, 32), 0);
        }
    }
    return 0;
}

}
