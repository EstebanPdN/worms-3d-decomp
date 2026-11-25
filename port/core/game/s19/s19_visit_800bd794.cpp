#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_visit_800bd794.c"
extern struct { Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; int pad[2]; } lbl_8043bb64;
extern int FUN_800b53d8(Ptr32<void>);

void s19_visit_marked_800bd794(Ptr32<void> self)
{
    Ptr32<Ptr32<void>> it = lbl_8043bb64.begin;
    Ptr32<Ptr32<void>> end = lbl_8043bb64.end;
    unsigned mask = 1;
    Ptr32<unsigned int> word;
    if (it != end) {
        word = (Ptr32<unsigned int>)((Ptr32<char>)self + 128);
        do {
            if (*word & mask)
                FUN_800b53d8(*it);
            mask <<= 1;
            if (mask == 0) {
                mask = 1;
                word++;
            }
            it++;
        } while (it != end);
    }
}

}
