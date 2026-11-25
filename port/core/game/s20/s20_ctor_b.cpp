#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_ctor_b.c"
/* Constructors with the common header plus extra zeroed fields. */
extern char lbl_80411f40[];
extern char lbl_80411ef8[];
extern char lbl_80413858[];
extern char lbl_80413830[];

Ptr32<char> w3d_s20_construct_header_8016f2d8(Ptr32<char> self) {
    Ptr32<char> sub;
    Ptr32<char> later;
    *(Ptr32<Ptr32<char>>)self = lbl_80411f40;
    sub = self + 4;
    ((Ptr32<volatile unsigned char>)sub)[4] = 2;
    later = self + 12;
    *(Ptr32<int>)(sub + 4) = ((Ptr32<volatile unsigned char>)sub)[4];
    *(Ptr32<int>)(self + 12) = 0;
    *(Ptr32<volatile int>)(later + 4) = 0;
    *(Ptr32<short>)(self + 4) = 0;
    *(Ptr32<short>)(sub + 2) = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_80411ef8;
    *(Ptr32<int>)(self + 28) = 0;
    *(Ptr32<short>)(self + 20) = 0;
    *(Ptr32<short>)(self + 22) = 0;
    *(Ptr32<short>)(self + 24) = 0;
    *(Ptr32<short>)(self + 26) = 0;
    return self;
}

Ptr32<char> w3d_s20_construct_header_8019e5b0(Ptr32<char> self) {
    Ptr32<char> sub;
    Ptr32<char> later;
    *(Ptr32<Ptr32<char>>)self = lbl_80413858;
    sub = self + 4;
    ((Ptr32<volatile unsigned char>)sub)[4] = 2;
    later = self + 12;
    *(Ptr32<int>)(sub + 4) = ((Ptr32<volatile unsigned char>)sub)[4];
    *(Ptr32<int>)(self + 12) = 0;
    *(Ptr32<volatile int>)(later + 4) = 0;
    *(Ptr32<short>)(self + 4) = 0;
    *(Ptr32<short>)(sub + 2) = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_80413830;
    *(Ptr32<int>)(self + 24) = 0;
    return self;
}

}
