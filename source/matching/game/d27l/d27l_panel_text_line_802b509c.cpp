// GWMP8P rev0 0x802b509c. Panel text: splits the source text at backslashes
// and keeps the piece selected by the second-line flag, then looks it up as
// a text property and sets the item's text, or sets an error message on a
// failed lookup; a message already present is kept when the settings flag at
// +188 bit 30 is set. Field roles are inferred from calls and diagnostic
// strings.
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
    Str();
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Header *h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned len() const { return *(unsigned short *)(p - 4); }
    void assign(const Str &o) {
        ++((Header *)(o.p - 6))->refs;
        ((Header *)(p - 6))->release();
        p = o.p;
    }
};
extern "C" void *fn_8020bd38(Str *, const char *);
extern "C" void fn_8020c3a0(Str *, unsigned);
extern "C" void fn_8020c510(Str *, const char *, ...);
extern "C" unsigned strcspn(const char *, const char *);
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
struct Source { char u0[68]; Str text; };
struct Settings { char u0[188]; unsigned flags; };
struct Self {
    char u0[40];
    Source *source;
    char u44[52];
    void *item;
    char u100[8];
    Str message;
    char u112[108];
    bool second;
};
extern Settings *settings_804b1788;
extern const char s_803d7e4c[], s_803d7e84[], s_803d7e88[];
extern "C" void *fn_80343744(void *);
extern "C" int fn_801790bc(void *, const char *);
extern "C" int fn_800fc1b0(Key *, Handle *);
extern "C" const char **fn_80179170(void *);
extern "C" void d27l_panel_text_line_802b509c(Self *self) {
    Str rest;
    Str part;
    Source *source = self->source;
    rest.assign(source->text);
    int n = 0;
    if (!rest.len()) {
        fn_8020bd38(&part, s_803d7e4c);
    } else {
        do {
            char *s = rest.p;
            part.assign(rest);
            unsigned k = strcspn(s, s_803d7e84);
            if (s[k] == '\\') {
                fn_8020c3a0(&part, k);
                k++;
            }
            s = rest.p;
            fn_8020bd38(&rest, s + k);
            if (!self->second == n)
                break;
            n++;
        } while (rest.len());
    }
    if (!self->message.len() || !(settings_804b1788->flags & 0x40000000)) {
        Str copy(part);
        if (copy.len()) {
            Handle h;
            Key k;
            k.text = copy.p;
            if (fn_800fc1b0(&k, &h) >= 0) {
                void *item = fn_80343744(self->item);
                fn_801790bc(item, *fn_80179170(fn_80343744(h.r)));
            } else {
                fn_8020c510(&self->message, s_803d7e88, copy.p);
                fn_801790bc(fn_80343744(self->item), self->message.p);
            }
        } else {
            fn_801790bc(fn_80343744(self->item), s_803d7e4c);
        }
    } else {
        fn_801790bc(fn_80343744(self->item), self->message.p);
    }
}
