// Partial GC32 views; descriptor identities and all external calls have original witnesses.
struct Sol35d4BindingString;
extern "C" void fn_8020c5c0(Sol35d4BindingString *);
extern "C" void fn_8020c5c4(Sol35d4BindingString *);
extern "C" void fn_80341588(Sol35d4BindingString *);
extern "C" unsigned short *fn_80341884(Sol35d4BindingString *);
extern "C" void fn_8020bb2c(void *);
struct Sol35d4BindingString {
    char *data;
    Sol35d4BindingString(const Sol35d4BindingString &other) {
        fn_8020c5c0(this);
        data = other.data;
        ++*fn_80341884(this);
    }
    ~Sol35d4BindingString() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    Sol35d4BindingString &operator=(const Sol35d4BindingString &other) {
        ++*(unsigned short *)(other.data - 6);
        char *old = data;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short references = --*header;
        if (!references) fn_8020bb2c(header);
        data = other.data;
        return *this;
    }
};
struct Sol35d4TextBinding {
    unsigned unknown_00[2];
    Sol35d4BindingString value;
};
extern "C" void *fn_801eb674(void *, void *);
extern "C" void *fn_801ec52c(void *, void *);
extern "C" void *fn_801ece2c(void *, void *);
extern "C" Sol35d4TextBinding *fn_801ed24c(void *, void *);
extern "C" void fn_801e8d9c(void *);
extern Sol35d4BindingString lbl_804b06a0[];
extern unsigned char lbl_803b7020[];
extern unsigned char lbl_803b7044[];
extern unsigned char lbl_803b7068[];
extern unsigned char lbl_803b708c[];
extern unsigned char lbl_803b70b0[];
extern unsigned char lbl_803b70e8[];
extern unsigned char lbl_803b7120[];
extern unsigned char lbl_803b7158[];
extern unsigned char lbl_803b718c[];
extern unsigned char lbl_803b71b4[];
extern unsigned char lbl_803b71ec[];
extern unsigned char lbl_803b7214[];
extern "C" int w3d_sol35d4_initialize_strings_80222db8(void *self) {
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803b7020);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803b7044);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803b7068);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803b708c);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801ece2c(self, lbl_803b70b0);
    fn_801eb674(self, lbl_803b70e8);
    fn_801eb674(self, lbl_803b7120);
    fn_801ece2c(self, lbl_803b7158);
    fn_801ec52c(self, lbl_803b718c);
    fn_801ec52c(self, lbl_803b71b4);
    fn_801eb674(self, lbl_803b71ec);
    fn_801eb674(self, lbl_803b7214);
    fn_801e8d9c(self);
    return 0;
}
typedef char Sol35d4StringSize[(sizeof(Sol35d4BindingString) == 4) ? 1 : -1];
