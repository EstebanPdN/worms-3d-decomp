#include "w3d_ptr.h"
#line 1 "s8hand_800dc634.cpp"
extern char lbl_8040fe70[];
extern "C" void fn_800dc6a8(Ptr32<void>,int);
struct s8_PartialObject_800dc634 {
    char pad0[112];
    Ptr32<void> partVtable;
    s8_PartialObject_800dc634();
};
s8_PartialObject_800dc634::s8_PartialObject_800dc634() {
    partVtable=lbl_8040fe70;
    fn_800dc6a8(this,0);
}


