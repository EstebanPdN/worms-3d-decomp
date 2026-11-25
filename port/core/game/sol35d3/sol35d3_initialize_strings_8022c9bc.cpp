#include "w3d_ptr.h"
#line 1 "sol35d3_initialize_strings_8022c9bc.cpp"
// Partial GC32 views; descriptor identities and all external calls have original witnesses.
struct Sol35d3BindingString;
extern "C" void fn_8020c5c0(Ptr32<Sol35d3BindingString>);
extern "C" void fn_8020c5c4(Ptr32<Sol35d3BindingString>);
extern "C" void fn_80341588(Ptr32<Sol35d3BindingString>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<Sol35d3BindingString>);
extern "C" void fn_8020bb2c(Ptr32<void>);
struct Sol35d3BindingString {
    Ptr32<char> data;
    Sol35d3BindingString(const Sol35d3BindingString &other) {
        fn_8020c5c0(this);
        data = other.data;
        ++*fn_80341884(this);
    }
    ~Sol35d3BindingString() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    Sol35d3BindingString &operator=(const Sol35d3BindingString &other) {
        ++*(Ptr32<unsigned short>)(other.data - 6);
        Ptr32<char> old = data;
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(old - 6);
        unsigned short references = --*header;
        if (!references) fn_8020bb2c(header);
        data = other.data;
        return *this;
    }
};
struct Sol35d3TextBinding {
    unsigned unknown_00[2];
    Sol35d3BindingString value;
};
extern "C" Ptr32<void> fn_801eb674(Ptr32<void>, Ptr32<void>);
extern "C" Ptr32<Sol35d3TextBinding> fn_801ed24c(Ptr32<void>, Ptr32<void>);
extern "C" void fn_801e8d9c(Ptr32<void>);
extern Sol35d3BindingString lbl_804b06a0[];
extern unsigned char lbl_803ba668[];
extern unsigned char lbl_803ba698[];
extern unsigned char lbl_803ba6bc[];
extern unsigned char lbl_803ba6f0[];
extern "C" int w3d_sol35d3_initialize_strings_8022c9bc(Ptr32<void> self) {
    {
        Ptr32<Sol35d3TextBinding> binding = fn_801ed24c(self, lbl_803ba668);
        Sol35d3BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Ptr32<Sol35d3TextBinding> binding = fn_801ed24c(self, lbl_803ba698);
        Sol35d3BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Ptr32<Sol35d3TextBinding> binding = fn_801ed24c(self, lbl_803ba6bc);
        Sol35d3BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801eb674(self, lbl_803ba6f0);
    fn_801e8d9c(self);
    return 0;
}
typedef char Sol35d3StringSize[(sizeof(Sol35d3BindingString) == 4) ? 1 : -1];


