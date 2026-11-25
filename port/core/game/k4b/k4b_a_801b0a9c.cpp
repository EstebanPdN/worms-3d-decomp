#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801b0a9c.c"
struct K4bRgba { unsigned char r, g, b, a; };
int w3d_k4b_image_classify_alpha_801b0a9c(Ptr32<struct K4bRgba> pixels, unsigned int width, int height)
{
    int opaque = 1;
    while (height-- != 0) {
        unsigned int x;
        for (x = 0; x < width; x++) {
            unsigned char a = pixels[x].a;
            if (a != 255) {
                if (a != 0)
                    return 1;
                opaque = 0;
            }
        }
        pixels += width;
    }
    return opaque ? 0 : 2;
}
// desc: w3d_k4b_image_classify_alpha_801b0a9c: Appears to scan RGBA pixel rows and return 1 for any partial alpha, 2 when some pixels are fully transparent, otherwise 0.

}
