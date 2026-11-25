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
// Four observed 32-bit bounds words. Their semantic scalar types remain inferred.
struct Sol35d2Bounds {
    unsigned words[4];
};
struct Sol35d2BoundsBinding {
    unsigned unknown_00[2];
    Sol35d2Bounds value;
};
extern "C" Sol35d2BoundsBinding *fn_801f0f74(void *, void *);
extern "C" void *fn_801ece2c(void *, void *);
extern "C" Sol35d2TextBinding *fn_801ed24c(void *, void *);
extern "C" void fn_801e8d9c(void *);
extern unsigned char lbl_803aac54[], lbl_803aac84[], lbl_803aacb4[];
extern Sol35d2Bounds lbl_8045e63c[];
extern Sol35d2BindingString lbl_804b06a0[];
extern "C" int w3d_sol35d2_initialize_bounds_801b4cd4(void *self) {
    Sol35d2BoundsBinding *bounds = fn_801f0f74(self, lbl_803aac54);
    bounds->value = lbl_8045e63c[0];
    fn_801ece2c(self, lbl_803aac84);
    Sol35d2TextBinding *binding = fn_801ed24c(self, lbl_803aacb4);
    {
        Sol35d2BindingString text(lbl_804b06a0[0]);
        binding->value = text;
    }
    fn_801e8d9c(self);
    return 0;
}

// Reference GC32 layouts; these are partial native views, not portable ownership proof.
typedef char Sol35d2StringSize[(sizeof(Sol35d2BindingString) == 4) ? 1 : -1];
typedef char Sol35d2BoundsSize[(sizeof(Sol35d2Bounds) == 16) ? 1 : -1];
