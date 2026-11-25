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
extern "C" void *fn_801ebf38(void *, void *);
extern "C" void *fn_801ec52c(void *, void *);
extern "C" void *fn_801ece2c(void *, void *);
extern "C" Sol35d4TextBinding *fn_801ed24c(void *, void *);
extern "C" void fn_801e8d9c(void *);
extern Sol35d4BindingString lbl_804b06a0[];
extern unsigned char lbl_803ba75c[];
extern unsigned char lbl_803ba78c[];
extern unsigned char lbl_803ba7b8[];
extern unsigned char lbl_803ba7e8[];
extern unsigned char lbl_803ba818[];
extern unsigned char lbl_803ba848[];
extern unsigned char lbl_803ba878[];
extern unsigned char lbl_803ba8a8[];
extern unsigned char lbl_803ba8d8[];
extern unsigned char lbl_803ba904[];
extern unsigned char lbl_803ba934[];
extern unsigned char lbl_803ba95c[];
extern unsigned char lbl_803ba98c[];
extern unsigned char lbl_803ba9cc[];
extern unsigned char lbl_803baa0c[];
extern "C" int w3d_sol35d4_initialize_strings_8022d1dc(void *self) {
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803ba75c);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803ba78c);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803ba7b8);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803ba7e8);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803ba818);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803ba848);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803ba878);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801ece2c(self, lbl_803ba8a8);
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803ba8d8);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803ba904);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801ebf38(self, lbl_803ba934);
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803ba95c);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801eb674(self, lbl_803ba98c);
    fn_801ec52c(self, lbl_803ba9cc);
    fn_801ec52c(self, lbl_803baa0c);
    fn_801e8d9c(self);
    return 0;
}
typedef char Sol35d4StringSize[(sizeof(Sol35d4BindingString) == 4) ? 1 : -1];
