#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_tga_read_801d9f0c.c"
struct K8bStream { Ptr32<Ptr32<int (Ptr32<struct K8bStream>, Ptr32<void>, unsigned int, Ptr32<unsigned int>)>> vtable; };
extern int fn_802ebfbc(Ptr32<const char> format, ...);
extern unsigned int lbl_804ab800;
extern unsigned int lbl_804ab7fc;

unsigned int w3d_k8b_tga_read_801d9f0c(Ptr32<void> unused, Ptr32<void> buffer, unsigned int size, unsigned int count, Ptr32<struct K8bStream> stream)
{
    unsigned int done;
    int status;
    if (lbl_804ab800 > 1) {
        lbl_804ab7fc += count * size;
        fn_802ebfbc("TGA: std_fread %d (total %d)\n", count * size, lbl_804ab7fc);
    }
    done = 0;
    status = stream->vtable[5](stream, buffer, size * count, &done);
    if (status < 0)
        return 0;
    return done / size;
}

}
