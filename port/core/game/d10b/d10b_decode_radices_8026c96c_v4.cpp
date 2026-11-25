#include "w3d_ptr.h"
#line 1 "d10b_decode_radices_8026c96c_v4.cpp"
// Partial field view: the complete owner type and sizeof are not established.
// The external table is read as ten unsigned halfword radices, never owned here.
struct d10b_RadixState {
    unsigned int unknown00;
    unsigned int values[10];
    unsigned int unknown2c[2];
    unsigned int encoded;
    unsigned int quotients[10];
};
extern const unsigned short d10b_radices_803cbcb0[];
extern "C" unsigned int d10b_decode_radices_8026c96c(Ptr32<d10b_RadixState> self, unsigned int encoded) {
    self->encoded=encoded;
    unsigned int remaining=encoded;
    for (int i=9; i>0; --i) {
        unsigned int product=d10b_radices_803cbcb0[0];
        for (int j=1; j<i; ++j) product *= d10b_radices_803cbcb0[j];
        self->quotients[i]=remaining/product;
        remaining%=product;
    }
    self->quotients[0]=remaining;
    self->values[0]=self->quotients[1];
    self->values[1]=self->quotients[2];
    self->values[2]=self->quotients[6]%d10b_radices_803cbcb0[6];
    self->values[3]=self->quotients[3]%d10b_radices_803cbcb0[3];
    self->values[4]=self->quotients[4]%d10b_radices_803cbcb0[4];
    self->values[5]=self->quotients[5]%d10b_radices_803cbcb0[5];
    self->values[6]=self->quotients[7]%d10b_radices_803cbcb0[7];
    self->values[7]=self->quotients[8]%d10b_radices_803cbcb0[8];
    self->values[8]=self->quotients[0]%d10b_radices_803cbcb0[0];
    self->values[9]=self->quotients[9]%d10b_radices_803cbcb0[9];
    return self->encoded;
}


