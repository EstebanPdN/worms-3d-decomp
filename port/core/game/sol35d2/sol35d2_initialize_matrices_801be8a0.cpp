#include "w3d_ptr.h"
#line 1 "sol35d2_initialize_matrices_801be8a0.cpp"
// Native 64-byte matrix view. Copy instruction shape and descriptors are observed; names inferred.
struct Sol35d2Matrix { float values[4][4]; };
struct Sol35d2MatrixBinding { unsigned unknown_00[2]; Sol35d2Matrix value; };
extern "C" Ptr32<Sol35d2MatrixBinding> fn_801f0d2c(Ptr32<void>, Ptr32<void>);
extern "C" Ptr32<void> fn_801eb674(Ptr32<void>, Ptr32<void>);
extern "C" void fn_801e8d9c(Ptr32<void>);
extern Sol35d2Matrix lbl_8045e708[];
extern unsigned char lbl_803abd70[], lbl_803abda0[], lbl_803abdcc[];
extern "C" int w3d_sol35d2_initialize_matrices_801be8a0(Ptr32<void> self) {
    fn_801f0d2c(self, lbl_803abd70)->value = lbl_8045e708[0];
    fn_801f0d2c(self, lbl_803abda0)->value = lbl_8045e708[0];
    fn_801eb674(self, lbl_803abdcc);
    fn_801e8d9c(self);
    return 0;
}

typedef char Sol35d2MatrixSize[(sizeof(Sol35d2Matrix) == 64) ? 1 : -1];


