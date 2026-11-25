#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_name_8002732c.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef Ptr32<Ptr32<const char> (Ptr32<void>)> S19NameFn;
extern int strcmp(Ptr32<const char>, Ptr32<const char>);
extern void w3d_auto_8002709c(Ptr32<void>);

int s19_on_name_8002732c(Ptr32<void> self, Ptr32<void> target)
{
    if (target) {
        if (strcmp(((S19NameFn)FIELD(self, void **, 0)[8])(self), "ActiveWormIndex") == 0)
            w3d_auto_8002709c(target);
    }
    return 0;
}

}
