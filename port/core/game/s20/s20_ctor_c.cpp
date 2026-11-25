#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_ctor_c.c"
/* Constructor with the common flagged header plus two extra zeroed words. */
extern char lbl_804144b0[];
extern char lbl_80414488[];

Ptr32<char> w3d_s20_construct_header_801b440c(Ptr32<char> self) {
    Ptr32<char> sub;
    Ptr32<char> later;
    *(Ptr32<Ptr32<char>>)self = lbl_804144b0;
    sub = self + 4;
    ((Ptr32<volatile unsigned char>)sub)[4] = 2;
    later = self + 12;
    *(Ptr32<int>)(sub + 4) = ((Ptr32<volatile unsigned char>)sub)[4];
    *(Ptr32<int>)(self + 12) = 0;
    *(Ptr32<volatile int>)(later + 4) = 0;
    *(Ptr32<short>)(self + 4) = 0;
    *(Ptr32<short>)(sub + 2) = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_80414488;
    *(Ptr32<int>)(self + 20) = 0;
    *(Ptr32<int>)(self + 24) = 0;
    return self;
}

}
