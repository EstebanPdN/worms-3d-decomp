#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "d40z_write_dispatch.c"
/* The ProDG runtime's low-level write, called by the printf console writers through 0x802e3294.
 * Descriptors 1 and 2 go to the SN debugger console, 0 fails, the rest go to the host file
 * handler at 0x802e4cfc. Names are inferred. */
int w3d_auto_802e31ec(Ptr32<const void> data, int length);
int w3d_d40z_host_write_802e4cfc(int fd, Ptr32<const void> data, int length);

int w3d_d40z_write_802e3244(int fd, Ptr32<const void> data, int length)
{
    if (fd == 1 || fd == 2)
        return w3d_auto_802e31ec(data, length);
    if (fd == 0)
        return -1;
    return w3d_d40z_host_write_802e4cfc(fd, data, length);
}

}
