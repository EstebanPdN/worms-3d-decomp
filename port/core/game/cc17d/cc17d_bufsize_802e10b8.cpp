#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "cc17d_bufsize_802e10b8.c"
/* cc17d: buffer size computation at 0x802e10b8. Observed layout of the
   object reached through +4; meanings inferred from the arithmetic (one
   32-byte-aligned block of width*height, two of a quarter of it, ten rows of
   the +68 value and an optional +72 block, plus 4096). */
struct Cc17dVideoInfo {
    char pad00[68];
    unsigned int f68;                  /* +68, rounded up to 32 and scaled by 10 */
    unsigned int f72;                  /* +72, x4, rounded, x4 when +172 set */
    char pad4c[128 - 76];
    unsigned int width;                /* +128 */
    unsigned int height;               /* +132 */
    char pad88[160 - 136];
    int enabled;                       /* +160 */
    char pada4[172 - 164];
    int extra;                         /* +172 */
};
struct Cc17dVideo { char pad00[4]; Ptr32<struct Cc17dVideoInfo> info; };
#define CC17D_ALIGN32(x) (((x) + 31) & ~31u)
unsigned int w3d_cc17d_video_buffer_size_802e10b8(Ptr32<struct Cc17dVideo> self)
{
    int rows;                          /* separate int temporary: register choice */
    Ptr32<struct Cc17dVideoInfo> info = self->info;
    unsigned int pixels, size;
    if (info->enabled != 0) {
        rows = CC17D_ALIGN32(info->f68);
        pixels = info->width * info->height;
        size = rows * 10;
        size += CC17D_ALIGN32(pixels);
        size += CC17D_ALIGN32(pixels >> 2);
        size += CC17D_ALIGN32(pixels >> 2);
        if (info->extra)
            size += CC17D_ALIGN32(info->f72 * 4) * 4;
        return size + 4096;
    }
    return 0;
}

}
