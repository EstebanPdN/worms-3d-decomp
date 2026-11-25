#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "d24z_open.c"
extern int d24z_open_802e4cdc(Ptr32<const char>, int);
extern int d24z_close_802e4cec(int);
extern int d24z_create_802e4ce4(Ptr32<const char>, int, int);
int w3d_d24z_open_802e3324(Ptr32<const char> path, int flags, ...)
{
    int fd;
    if (flags & 512) {
        fd = d24z_open_802e4cdc(path, 0);
        if (fd != -1) {
            if (d24z_close_802e4cec(fd) != 0) return -1;
        }
    }
    return d24z_create_802e4ce4(path, flags, 0);
}

}
