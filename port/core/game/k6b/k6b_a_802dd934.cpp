#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k6b_a_802dd934.c"
typedef struct lua_State lua_State;
typedef struct K6bFile {
    Ptr32<unsigned char> pointer;
    int read_count;
    int write_count;
    unsigned short flags;
} K6bFile;
typedef struct K6bLoadF {
    Ptr32<K6bFile> f;
    char buff[1024];
} K6bLoadF;
extern unsigned int fread(Ptr32<void> buffer, unsigned int size, unsigned int count, Ptr32<K6bFile> file);
Ptr32<const char> w3d_k6b_lua_getF_802dd934(Ptr32<lua_State> L, Ptr32<void> ud, Ptr32<unsigned int> size)
{
    Ptr32<K6bLoadF> lf = (Ptr32<K6bLoadF>)ud;
    (void)L;
    if (lf->f->flags & 0x20) return 0;
    *size = fread(lf->buff, 1, 1024, lf->f);
    return (*size > 0) ? w3d::R(lf->buff) : 0;
}
// desc: w3d_k6b_lua_getF_802dd934: Appears to be Lua 5.0 lauxlib getF: return NULL at end of file, else fread up to 1024 bytes into the LoadF buffer and return it when nonempty.

}
