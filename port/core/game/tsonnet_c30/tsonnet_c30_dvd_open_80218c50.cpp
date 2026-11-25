#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c30_dvd_open_80218c50.c"
/* Reference-only: opens a file by path through the DVD entry lookup and logs
   the result. Field offsets are observed; names and meanings are inferred. */
extern int fn_80218d10(Ptr32<void> self);
extern int fn_802f4ef0(Ptr32<char> path);
extern int fn_802f51e4(int entry, Ptr32<void> info);
extern void fn_802fb7ac(Ptr32<const char> fmt, ...);
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))

int tsonnet_c30_dvd_open_80218c50(Ptr32<void> self, Ptr32<char> path, int flags) {
    int entry, ok;
    fn_80218d10(self);
    FIELD(self, int, 108) = -1;
    FIELD(self, int, 104) = 0;
    FIELD(self, int, 100) = 0;
    if (flags & 2) return 0;
    entry = fn_802f4ef0(path);
    if (entry >= 0) {
        ok = fn_802f51e4(entry, (Ptr32<char>)self + 24);
        FIELD(self, int, 96) = ok != 0;
        fn_802fb7ac("DVDOpen: '%s' %s\n", w3d::VA(path), w3d::VA(ok ? w3d::R("ok") : w3d::R("fail!")));
        if (ok) return 0;
    }
    return 0x90000004;
}

}
