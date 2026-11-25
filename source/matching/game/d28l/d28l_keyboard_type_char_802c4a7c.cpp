// GWMP8P rev0 0x802c4a7c. On-screen keyboard typing: rejects the character
// when the text is full or the character is zero, measures the text with the
// character inserted at the cursor against the box width and limit, then
// commits the new text, advances the cursor and plays the key sound, or
// plays the error sound. Field names are inferred.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020bb2c(void *);
struct Header {
    unsigned short refs, length, capacity;
    void release() {
        if (!--refs)
            fn_8020bb2c(this);
    }
};
struct Str {
    char *p;
    Str();
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned short len() const { return *(unsigned short *)(p - 4); }
    void assign(const Str &o) {
        ++((Header *)(o.p - 6))->refs;
        ((Header *)(p - 6))->release();
        p = o.p;
    }
};
struct Res;
struct ResVt { char u0[16]; void (*destroy)(Res *); };
struct Res { ResVt *vt; };
struct Handle {
    Res *r;
    Handle() { r = 0; }
    Handle(const Handle &);
    ~Handle() { if (r) r->vt->destroy(r); }
};
struct Key { const char *text; };
struct Font;
struct FontOwner;
struct FontOwnerVt { char u0[64]; void *(*font)(FontOwner *); };
struct FontOwner { FontOwnerVt *vt; };
struct Keyboard {
    char u0[64];
    int selected;
    char u68[24];
    void *keys[31];
    void *back;
    void *shift;
    void *accept;
    void *right;
    void *left;
    char u236[8];
    FontOwner *fonts;
    Str item;
    char u252[4];
    Str text;
    Str command;
    int cursor;
    char u268[56];
    int commandOn;
    char u328[4];
    int cycle;
    void *box;
    char u340[24];
    unsigned maximum;
    float limit;
    float scale;
    int masked;
};
extern "C" unsigned fn_8020c5cc(Str *);
extern "C" void fn_802c43ec(Keyboard *, const char *);
extern "C" void fn_802c4744(Keyboard *);
extern "C" void fn_802c4998(Keyboard *);
extern "C" void fn_802c4080(Keyboard *);
extern const char s_803d8728[], s_803d8730[], s_803d873c[], s_803d8744[], s_803d874c[], s_803d8764[];
extern "C" void * fn_8020bdf4(Str *, const char *, unsigned);
extern "C" Str *fn_8020c6a4(Str *, const Str *, unsigned);
extern "C" const char *fn_8018b2b0(unsigned short, void *, void *);
extern "C" Str *fn_8020bf2c(Str *, const char *);
extern "C" int fn_8020c620(Str *, int);
extern "C" void fn_8020c43c(Str *, const char *, unsigned);
extern "C" Font *fn_8034435c(void *);
extern "C" float fn_8018b4cc(Font *, const char *);
extern "C" float fn_80178df0(void *);
extern "C" void d28l_keyboard_type_char_802c4a7c(Keyboard *self, int ch) {
    Str out;
    int ok = 1;
    bool typed = false;
    if (fn_8020c5cc(&self->text) >= self->maximum || !ch) {
        ok = 0;
    }
    if (ok == 1) {
        Str test;
        if (self->masked == 1) {
            fn_8020bdf4(&test, s_803d8764, fn_8020c5cc(&self->text) + 1);
        } else {
            fn_8020c6a4(&test, &self->text, self->cursor);
            fn_8020bf2c(&test, fn_8018b2b0(ch, 0, 0));
            int off = fn_8020c620(&self->text, self->cursor);
            fn_8020c43c(&test, self->text.p + off, self->text.len() - off);
        }
        float width = fn_8018b4cc(fn_8034435c(self->fonts->vt->font(self->fonts)), test.p);
        float right = width * 30.0f;
        if (right >= 380.0f - fn_80178df0(self->box) * 1.9f) {
            ok = 0;
        }
        if (width * self->scale >= self->limit && self->limit != 0.0f) {
            ok = 0;
        }
    }
    if (ok == 1) {
        typed = true;
        fn_8020c6a4(&out, &self->text, self->cursor);
        fn_8020bf2c(&out, fn_8018b2b0(ch, 0, 0));
        int off = fn_8020c620(&self->text, self->cursor);
        fn_8020c43c(&out, self->text.p + off, self->text.len() - off);
    } else {
        fn_802c43ec(self, s_803d8728);
    }
    if (typed) {
        self->text.assign(out);
        self->cursor++;
        fn_802c4744(self);
        if (self->cycle == 1) {
            fn_802c4080(self);
        }
        fn_802c4998(self);
        fn_802c43ec(self, s_803d8730);
    }
}
