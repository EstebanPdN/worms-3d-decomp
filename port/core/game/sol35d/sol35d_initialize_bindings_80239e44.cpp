#include "w3d_ptr.h"
#line 1 "sol35d_initialize_bindings_80239e44.cpp"
// Partial GC32 views; descriptor identities and all external calls have original witnesses.
struct Sol35dBindingString;
extern "C" void fn_8020c5c0(Ptr32<Sol35dBindingString>);
extern "C" void fn_8020c5c4(Ptr32<Sol35dBindingString>);
extern "C" void fn_80341588(Ptr32<Sol35dBindingString>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<Sol35dBindingString>);
extern "C" void fn_8020bb2c(Ptr32<void>);
struct Sol35dBindingString {
    Ptr32<char> data;
    Sol35dBindingString(const Sol35dBindingString &other) {
        fn_8020c5c0(this);
        data = other.data;
        ++*fn_80341884(this);
    }
    ~Sol35dBindingString() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    Sol35dBindingString &operator=(const Sol35dBindingString &other) {
        ++*(Ptr32<unsigned short>)(other.data - 6);
        Ptr32<char> old = data;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short references = --*header;
        if (!references) fn_8020bb2c(header);
        data = other.data;
        return *this;
    }
};
struct Sol35dTextBinding {
    unsigned unknown_00[2];
    Sol35dBindingString value;
};
extern "C" Ptr32<Sol35dTextBinding> fn_801ed24c(Ptr32<void>, Ptr32<void>);
extern "C" Ptr32<void> fn_801ebf38(Ptr32<void>, Ptr32<void>);
extern "C" void fn_801e8d9c(Ptr32<void>);
extern unsigned char lbl_803bb3e0[], lbl_803bb414[], lbl_803bb440[], lbl_803bb470[];
extern Sol35dBindingString lbl_804b06a0[];
extern "C" int w3d_sol35d_initialize_bindings_80239e44(Ptr32<void> self) {
    fn_801ebf38(self, lbl_803bb3e0);
    Ptr32<Sol35dTextBinding> binding = fn_801ed24c(self, lbl_803bb414);
    {
        Sol35dBindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801ebf38(self, lbl_803bb440);
    fn_801ebf38(self, lbl_803bb470);
    fn_801e8d9c(self);
    return 0;
}


