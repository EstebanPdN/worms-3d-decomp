// Partial GC32 views; descriptor identities and all external calls have original witnesses.
struct Sol35d3BindingString;
extern "C" void fn_8020c5c0(Sol35d3BindingString *);
extern "C" void fn_8020c5c4(Sol35d3BindingString *);
extern "C" void fn_80341588(Sol35d3BindingString *);
extern "C" unsigned short *fn_80341884(Sol35d3BindingString *);
extern "C" void fn_8020bb2c(void *);
struct Sol35d3BindingString {
    char *data;
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
        ++*(unsigned short *)(other.data - 6);
        char *old = data;
        unsigned short *header = (unsigned short *)(old - 6);
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
extern "C" void *fn_801eb674(void *, void *);
extern "C" void *fn_801ebf38(void *, void *);
extern "C" void *fn_801ec0f8(void *, void *);
extern "C" Sol35d3TextBinding *fn_801ed24c(void *, void *);
extern "C" void fn_801e8d9c(void *);
extern Sol35d3BindingString lbl_804b06a0[];
extern unsigned char lbl_803bac20[];
extern unsigned char lbl_803bac50[];
extern unsigned char lbl_803bac80[];
extern unsigned char lbl_803bacac[];
extern unsigned char lbl_803bacdc[];
extern unsigned char lbl_803bad10[];
extern unsigned char lbl_803bad4c[];
extern unsigned char lbl_803bad88[];
extern unsigned char lbl_803badbc[];
extern unsigned char lbl_803badec[];
extern unsigned char lbl_803bae18[];
extern unsigned char lbl_803bae4c[];
extern unsigned char lbl_803bae7c[];
extern "C" int w3d_sol35d3_initialize_strings_80236870(void *self) {
    {
        Sol35d3TextBinding *binding = fn_801ed24c(self, lbl_803bac20);
        Sol35d3BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d3TextBinding *binding = fn_801ed24c(self, lbl_803bac50);
        Sol35d3BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d3TextBinding *binding = fn_801ed24c(self, lbl_803bac80);
        Sol35d3BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801eb674(self, lbl_803bacac);
    fn_801eb674(self, lbl_803bacdc);
    fn_801eb674(self, lbl_803bad10);
    fn_801ebf38(self, lbl_803bad4c);
    fn_801ebf38(self, lbl_803bad88);
    fn_801ec0f8(self, lbl_803badbc);
    {
        Sol35d3TextBinding *binding = fn_801ed24c(self, lbl_803badec);
        Sol35d3BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801ebf38(self, lbl_803bae18);
    fn_801eb674(self, lbl_803bae4c);
    fn_801ebf38(self, lbl_803bae7c);
    fn_801e8d9c(self);
    return 0;
}
typedef char Sol35d3StringSize[(sizeof(Sol35d3BindingString) == 4) ? 1 : -1];
