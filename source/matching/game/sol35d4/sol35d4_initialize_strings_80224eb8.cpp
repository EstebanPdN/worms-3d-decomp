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
extern "C" Sol35d4TextBinding *fn_801ed24c(void *, void *);
extern "C" void fn_801e8d9c(void *);
extern Sol35d4BindingString lbl_804b06a0[];
extern unsigned char lbl_803b7aa4[];
extern unsigned char lbl_803b7ac8[];
extern unsigned char lbl_803b7afc[];
extern unsigned char lbl_803b7b30[];
extern unsigned char lbl_803b7b68[];
extern unsigned char lbl_803b7ba4[];
extern unsigned char lbl_803b7bd8[];
extern unsigned char lbl_803b7c10[];
extern "C" int w3d_sol35d4_initialize_strings_80224eb8(void *self) {
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803b7aa4);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803b7ac8);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803b7afc);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803b7b30);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801ebf38(self, lbl_803b7b68);
    fn_801ebf38(self, lbl_803b7ba4);
    fn_801eb674(self, lbl_803b7bd8);
    {
        Sol35d4TextBinding *binding = fn_801ed24c(self, lbl_803b7c10);
        Sol35d4BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801e8d9c(self);
    return 0;
}
typedef char Sol35d4StringSize[(sizeof(Sol35d4BindingString) == 4) ? 1 : -1];
