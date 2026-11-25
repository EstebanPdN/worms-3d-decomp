// Partial GC32 views; descriptor identities and all external calls have original witnesses.
struct Sol35d2BindingString;
extern "C" void fn_8020c5c0(Sol35d2BindingString *);
extern "C" void fn_8020c5c4(Sol35d2BindingString *);
extern "C" void fn_80341588(Sol35d2BindingString *);
extern "C" unsigned short *fn_80341884(Sol35d2BindingString *);
extern "C" void fn_8020bb2c(void *);
struct Sol35d2BindingString {
    char *data;
    Sol35d2BindingString(const Sol35d2BindingString &other) {
        fn_8020c5c0(this);
        data = other.data;
        ++*fn_80341884(this);
    }
    ~Sol35d2BindingString() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    Sol35d2BindingString &operator=(const Sol35d2BindingString &other) {
        ++*(unsigned short *)(other.data - 6);
        char *old = data;
        unsigned short *header = (unsigned short *)(old - 6);
        unsigned short references = --*header;
        if (!references) fn_8020bb2c(header);
        data = other.data;
        return *this;
    }
};
struct Sol35d2TextBinding {
    unsigned unknown_00[2];
    Sol35d2BindingString value;
};
extern "C" Sol35d2TextBinding *fn_801ed24c(void *, void *);
extern "C" void *fn_801ebf38(void *, void *);
extern "C" void *fn_801eb674(void *, void *);
extern "C" void *fn_801ecc6c(void *, void *);
extern "C" void fn_801e8d9c(void *);
extern Sol35d2BindingString lbl_804b06a0[];
extern unsigned char lbl_803bb5c4[];
extern unsigned char lbl_803bb5f8[];
extern unsigned char lbl_803bb630[];
extern unsigned char lbl_803bb658[];
extern unsigned char lbl_803bb680[];
extern unsigned char lbl_803bb6b0[];
extern unsigned char lbl_803bb6d8[];
extern unsigned char lbl_803bb70c[];
extern unsigned char lbl_803bb740[];
extern unsigned char lbl_803bb770[];
extern unsigned char lbl_803bb7a4[];
extern unsigned char lbl_803bb7d8[];
extern unsigned char lbl_803bb810[];
extern unsigned char lbl_803bb844[];
extern "C" int w3d_sol35d2_initialize_transfer_8023a9c4(void *self) {
    Sol35d2TextBinding *binding = fn_801ed24c(self, lbl_803bb5c4);
    {
        Sol35d2BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801ebf38(self, lbl_803bb5f8);
    fn_801ebf38(self, lbl_803bb630);
    fn_801ebf38(self, lbl_803bb658);
    fn_801ebf38(self, lbl_803bb680);
    fn_801ebf38(self, lbl_803bb6b0);
    fn_801ebf38(self, lbl_803bb6d8);
    fn_801eb674(self, lbl_803bb70c);
    fn_801ebf38(self, lbl_803bb740);
    fn_801ecc6c(self, lbl_803bb770);
    fn_801ebf38(self, lbl_803bb7a4);
    fn_801ebf38(self, lbl_803bb7d8);
    fn_801ebf38(self, lbl_803bb810);
    fn_801ebf38(self, lbl_803bb844);
    fn_801e8d9c(self);
    return 0;
}

typedef char Sol35d2StringSize[(sizeof(Sol35d2BindingString) == 4) ? 1 : -1];
