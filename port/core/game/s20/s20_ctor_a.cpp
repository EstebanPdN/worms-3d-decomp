#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_ctor_a.c"
/* Constructors that install a base vtable, initialize a small header and install the final vtable. */
extern char lbl_80411fc0[];
extern char lbl_80411f90[];
extern char lbl_80413730[];
extern char lbl_80413710[];
extern char lbl_80413890[];
extern char lbl_80416610[];
extern char lbl_804165f0[];

Ptr32<char> w3d_s20_construct_header_8016f7cc(Ptr32<char> self) {
    Ptr32<char> sub;
    Ptr32<char> later;
    *(Ptr32<Ptr32<char>>)self = lbl_80411fc0;
    sub = self + 4;
    ((Ptr32<volatile unsigned char>)sub)[4] = 2;
    later = self + 12;
    *(Ptr32<int>)(sub + 4) = ((Ptr32<volatile unsigned char>)sub)[4];
    *(Ptr32<int>)(self + 12) = 0;
    *(Ptr32<volatile int>)(later + 4) = 0;
    *(Ptr32<short>)(self + 4) = 0;
    *(Ptr32<short>)(sub + 2) = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_80411f90;
    return self;
}

Ptr32<char> w3d_s20_construct_header_8019d78c(Ptr32<char> self) {
    Ptr32<char> sub;
    Ptr32<char> later;
    *(Ptr32<Ptr32<char>>)self = lbl_80413730;
    sub = self + 4;
    ((Ptr32<volatile unsigned char>)sub)[4] = 2;
    later = self + 12;
    *(Ptr32<int>)(sub + 4) = ((Ptr32<volatile unsigned char>)sub)[4];
    *(Ptr32<int>)(self + 12) = 0;
    *(Ptr32<volatile int>)(later + 4) = 0;
    *(Ptr32<short>)(self + 4) = 0;
    *(Ptr32<short>)(sub + 2) = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_80413710;
    return self;
}

Ptr32<char> w3d_s20_construct_header_801a0078(Ptr32<char> self) {
    Ptr32<char> sub;
    Ptr32<char> later;
    *(Ptr32<Ptr32<char>>)self = lbl_80413730;
    sub = self + 4;
    ((Ptr32<volatile unsigned char>)sub)[4] = 2;
    later = self + 12;
    *(Ptr32<int>)(sub + 4) = ((Ptr32<volatile unsigned char>)sub)[4];
    *(Ptr32<int>)(self + 12) = 0;
    *(Ptr32<volatile int>)(later + 4) = 0;
    *(Ptr32<short>)(self + 4) = 0;
    *(Ptr32<short>)(sub + 2) = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_80413890;
    return self;
}

Ptr32<char> w3d_s20_construct_header_801d47b8(Ptr32<char> self) {
    Ptr32<char> sub;
    Ptr32<char> later;
    *(Ptr32<Ptr32<char>>)self = lbl_80416610;
    sub = self + 4;
    ((Ptr32<volatile unsigned char>)sub)[4] = 2;
    later = self + 12;
    *(Ptr32<int>)(sub + 4) = ((Ptr32<volatile unsigned char>)sub)[4];
    *(Ptr32<int>)(self + 12) = 0;
    *(Ptr32<volatile int>)(later + 4) = 0;
    *(Ptr32<short>)(self + 4) = 0;
    *(Ptr32<short>)(sub + 2) = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_804165f0;
    return self;
}


}
