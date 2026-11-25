// GWMP8P rev0 0x802c38cc. On-screen keyboard mode change: picks the upper,
// lower, number or symbol character set property for the mode, then for each
// of the 30 keys decodes the next UTF-8 character, enables it depending on
// the allowed-characters string of the optional item, and sets its label;
// the string argument to the label call is by value and destroyed by the
// callee. Key roles come from the property names in the original data.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020bb2c(void *), fn_8020c5c0(void *);
struct Header {
    unsigned short refs, length, capacity;
    void release() {
        if (!--refs)
            fn_8020bb2c(this);
    }
};
extern "C" Header *fn_80341884(void *);
struct Str {
    char *p;
    Str(const char *);
    Str(const Str &o);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    void assign(const Str &o) {
        ++((Header *)(o.p - 6))->refs;
        ((Header *)(p - 6))->release();
        p = o.p;
    }
};
struct Key { const char *text; };
struct Item { char u0[156]; Str chars; };
struct Keyboard {
    char u0[92];
    void *keys[30];
    char u212[8];
    void *w220;
    char u224[108];
    int mode;
    char u336[44];
    Item *item;
};
extern const char upper_803d866c[], lower_803d8678[], number_803d8684[], symbol_803d868c[], symbol_803d8698[], empty_803d86a4[], s_803d860c[];
extern "C" int fn_800fc2b0(Key *, const char **);
extern "C" int fn_8018b360(const char *, int *);
extern "C" char *strchr(const char *, int);
extern "C" void fn_802c8174(void *, int);
extern "C" void fn_802c7a0c(void *, Str, int);
extern "C" void fn_802c6924(void *, int);
extern "C" void d27l_keyboard_set_mode_802c38cc(Keyboard *self, int mode) {
    if (self->mode != mode) {
        int style; self->mode = mode; const char *text = 0;
        switch (self->mode) {
        case 0: { style = 1; Key k; k.text = upper_803d866c; fn_800fc2b0(&k, &text); break; }
        case 1: { style = 0; Key k; k.text = upper_803d866c; fn_800fc2b0(&k, &text); break; }
        case 2: { style = 2; Key k; k.text = lower_803d8678; fn_800fc2b0(&k, &text); break; }
        case 3: { style = 3; Key k; k.text = number_803d8684; fn_800fc2b0(&k, &text); break; }
        case 4: { style = 4; Key k; k.text = symbol_803d868c; fn_800fc2b0(&k, &text); break; }
        case 5: { style = 4; Key k; k.text = symbol_803d8698; fn_800fc2b0(&k, &text); break; }
        }
        if (text) {
            int size = 0;
            const char *allowed = 0;
            if (self->item) {
                Str chars(empty_803d86a4);
                chars.assign(self->item->chars);
                allowed = chars.p;
            }
            if (self->keys[0] && text) {
                for (unsigned i = 0; i <= 29; i++) {
                    int c = (short)fn_8018b360(text, &size);
                    text += size;
                    if (strchr(allowed, c))
                        fn_802c8174(self->keys[i], 0);
                    else
                        fn_802c8174(self->keys[i], 1);
                    fn_802c7a0c(self->keys[i], Str(s_803d860c), c);
                }
                fn_802c6924(self->w220, style);
            }
        }
    }
}
