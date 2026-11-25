#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_as.c"
/* Vector lookup through a name index. */
typedef struct S20V3 { int x; int y; int z; } S20V3;
extern int fn_80177eb0(Ptr32<char>, Ptr32<char>, Ptr32<unsigned short>);
extern int fn_80342fa4(int);
extern Ptr32<S20V3> fn_80178ec4(Ptr32<void>);

int w3d_s20_lookup_vector_80176aac(Ptr32<char> self, Ptr32<char> name, Ptr32<S20V3> out) {
    unsigned short index;
    Ptr32<S20V3> found;
    if (fn_80177eb0(self, name, &index) < 0)
        return 0x80004005;
    found = fn_80178ec4(w3d::G(fn_80342fa4(*(Ptr32<int>)(*(Ptr32<Ptr32<char>>)(self + 24) + index * 4))));
    *out = *found;
    return 0;
}

}
