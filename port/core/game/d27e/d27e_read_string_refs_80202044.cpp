#include "w3d_ptr.h"
#line 1 "d27e_read_string_refs_80202044.cpp"
// (Worms 3D GameCube PAL, 0x80202044).
//
// Reads n string indices through 0x802024f4 and, when an output array is
// given, stores the matching entry of the name table at +140 in each slot:
// the new string's 16-bit reference count at -6 goes up, the old one's goes
// down and it is freed at zero. Strings are viewed as raw character pointers
// here. Names are inferred.

extern "C" void string_free_8020bb2c(Ptr32<void>);
struct Reader { char u[140]; Ptr32<Ptr32<char>> names; };
extern "C" unsigned next_802024f4(Ptr32<Reader>);
inline void Release(Ptr32<char> old) {
    Ptr32<unsigned short> h = (Ptr32<unsigned short>)(old - 6);
    if (--*h == 0) string_free_8020bb2c(h);
}
extern "C" int w3d_d27e_read_string_refs_80202044(Ptr32<Reader> self, Ptr32<Ptr32<char>> out, unsigned n) {
    unsigned i = 0;
    if (i < n) {
        Ptr32<Ptr32<char>> q = out;
        do {
            unsigned index = next_802024f4(self);
            if (out) {
                Ptr32<char> const &from = *(Ptr32<Ptr32<char>>)((Ptr32<char>)self->names + (index << 2));
                ++out;
                Ptr32<Ptr32<char>> cur = q;
                ++q;
                ++*(Ptr32<unsigned short>)(from - 6);
                Release(q[-1]);
                *cur = from;
            }
            ++i;
        } while (i < n);
    }
    return 0;
}


