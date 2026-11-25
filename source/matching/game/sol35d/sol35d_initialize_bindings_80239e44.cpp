// Partial GC32 views; descriptor identities and all external calls have original witnesses.
struct Sol35dBindingString;
extern "C" void fn_8020c5c0(Sol35dBindingString *);
extern "C" void fn_8020c5c4(Sol35dBindingString *);
extern "C" void fn_80341588(Sol35dBindingString *);
extern "C" unsigned short *fn_80341884(Sol35dBindingString *);
extern "C" void fn_8020bb2c(void *);
struct Sol35dBindingString {
    char *data;
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
        ++*(unsigned short *)(other.data - 6);
        char *old = data;
        unsigned short *header = (unsigned short *)(old - 6);
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
extern "C" Sol35dTextBinding *fn_801ed24c(void *, void *);
extern "C" void *fn_801ebf38(void *, void *);
extern "C" void fn_801e8d9c(void *);
extern unsigned char lbl_803bb3e0[], lbl_803bb414[], lbl_803bb440[], lbl_803bb470[];
extern Sol35dBindingString lbl_804b06a0[];
extern "C" int w3d_sol35d_initialize_bindings_80239e44(void *self) {
    fn_801ebf38(self, lbl_803bb3e0);
    Sol35dTextBinding *binding = fn_801ed24c(self, lbl_803bb414);
    {
        Sol35dBindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801ebf38(self, lbl_803bb440);
    fn_801ebf38(self, lbl_803bb470);
    fn_801e8d9c(self);
    return 0;
}
