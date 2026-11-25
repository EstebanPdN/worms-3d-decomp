#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_ctor_e.c"
/* Header constructors followed by cleared fields. */
typedef struct S20Bits {
    char pad[24];
    unsigned char first;
    unsigned char second;
    unsigned int :1; unsigned int top:15; unsigned int mid:14; unsigned int small:2; unsigned int :15; unsigned int low:17;
} S20Bits;
extern char lbl_80413270[];
extern char lbl_80413210[];
extern Ptr32<void> fn_803426b8(Ptr32<char>);

extern char lbl_80413338[];
extern char lbl_804132e0[];

Ptr32<char> w3d_s20_construct_flags_801902e8(Ptr32<char> self) {
    Ptr32<char> sub;
    Ptr32<char> later;
    Ptr32<S20Bits> bits = (Ptr32<S20Bits>)self;
    *(Ptr32<Ptr32<char>>)self = lbl_80413270;
    sub = self + 4;
    ((Ptr32<volatile unsigned char>)sub)[4] = 2;
    later = self + 12;
    *(Ptr32<int>)(sub + 4) = ((Ptr32<volatile unsigned char>)sub)[4];
    *(Ptr32<int>)(self + 12) = 0;
    *(Ptr32<volatile int>)(later + 4) = 0;
    *(Ptr32<short>)(self + 4) = 0;
    *(Ptr32<short>)(sub + 2) = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_80413210;
    fn_803426b8(self + 20);
    *(Ptr32<unsigned int>)(self + 24) &= 0xffff3fff;
    *(Ptr32<unsigned int>)(self + 28) &= 0x1ffff;
    *(Ptr32<unsigned char>)(self + 26) = 0;
    *(Ptr32<unsigned char>)(self + 27) = 0;
    return self;
}

Ptr32<char> w3d_s20_construct_cleared_80190800(Ptr32<char> self) {
    Ptr32<char> sub;
    Ptr32<char> later;
    Ptr32<char> a;
    Ptr32<char> b;
    Ptr32<char> c;
    Ptr32<char> d;
    Ptr32<char> e;
    Ptr32<char> f;
    volatile char pad[24];
    *(Ptr32<Ptr32<char>>)self = lbl_80413338;
    sub = self + 4;
    ((Ptr32<volatile unsigned char>)sub)[4] = 2;
    later = self + 12;
    *(Ptr32<int>)(sub + 4) = ((Ptr32<volatile unsigned char>)sub)[4];
    *(Ptr32<int>)(self + 12) = 0;
    *(Ptr32<volatile int>)(later + 4) = 0;
    *(Ptr32<short>)(self + 4) = 0;
    *(Ptr32<short>)(sub + 2) = 0;
    *(Ptr32<Ptr32<char>>)self = lbl_804132e0;
    a = self + 20;
    b = self + 28;
    c = self + 36;
    d = self + 44;
    e = self + 52;
    f = self + 60;
    *(Ptr32<int>)(self + 20) = 0;
    *(Ptr32<int>)(a + 4) = 0;
    *(Ptr32<int>)(b + 4) = 0;
    *(Ptr32<int>)(self + 36) = 0;
    *(Ptr32<int>)(c + 4) = 0;
    *(Ptr32<int>)(d + 4) = 0;
    *(Ptr32<int>)(self + 52) = 0;
    *(Ptr32<int>)(e + 4) = 0;
    *(Ptr32<int>)(f + 4) = 0;
    fn_803426b8(self + 68);
    *(Ptr32<int>)(self + 76) = 0;
    *(Ptr32<int>)(self + 72) = 0;
    return self;
}

}
