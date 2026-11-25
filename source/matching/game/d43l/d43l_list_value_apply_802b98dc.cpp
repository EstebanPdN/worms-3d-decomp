// GWMP8P rev0 0x802b98dc. Applies the selected list entry's text to the
// named property: looks the property up by name, reports a missing one, and
// otherwise stores the text as an int, a second numeric kind or a string
// according to the property's type.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020c5c0(void *), fn_8020bb2c(void *);
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
inline void use(Str) {}
extern "C" void fn_8020c510(Str *, const char *, ...);
struct Value;
struct ValueVt { char u0[16]; void (*destroy)(Value *); char u20[4]; int (*type)(Value *); };
struct Value { ValueVt *vt; };
struct Handle {
    Value *r;
    Handle() { r = 0; }
    Handle(const Handle &);
    ~Handle() { if (r) r->vt->destroy(r); }
};
struct Key { const char *text; };
struct List { char u0[24]; unsigned count; char u28[4]; Str items[1]; };
struct Data { char u0[28]; List *list; };
struct Source { char u0[164]; Str name; };
struct Self {
    char u0[40];
    Source *source;
    char u44[64];
    Str message;
    char u112[144];
    int busy;
    char u260[20];
    void *holder;
    char u284[12];
    int index;
};
extern const char s_803d7fd0[];
extern "C" void fn_802b8be0(Self *);
extern "C" int fn_800fc1b0(Key *, Handle *);
extern "C" void *fn_80341584(void *);
extern "C" Data *fn_801797b4(void *);
extern "C" int atoi(const char *);
extern "C" void *fn_803426b4(Value *), *fn_80342a78(Value *), *fn_80343744(Value *);
extern "C" int fn_80178c54(void *, int *), fn_80178d28(void *, int *);
extern "C" int fn_801790bc(void *, const char *);
extern "C" void d43l_list_value_apply_802b98dc(Self *self) {
    if (self->index != -1 && self->holder) {
        Source *source = self->source;
        fn_802b8be0(self);
        if (source->name.len()) {
            self->busy = 1;
            Handle h;
            Key k;
            k.text = source->name.p;
            if (fn_800fc1b0(&k, &h) < 0) {
                use(source->name);
                fn_8020c510(&self->message, s_803d7fd0, source->name.p);
            } else {
                Str value;
                List *list = fn_801797b4(fn_80341584(self->holder))->list;
                if (list->count > (unsigned)self->index) {
                    unsigned offset = self->index * 4;
                    char *items; do { items = (char *)list + 32; } while (0);
                    const Str &item = *(const Str *)(offset + (int)items);
                    value.assign(item);
                    const char *text = value.p;
                    switch (h.r->vt->type(h.r)) {
                    case 0: {
                        int n = atoi(text);
                        fn_80178c54(fn_803426b4(h.r), &n);
                        break;
                    }
                    case 1: {
                        int n = atoi(text);
                        fn_80178d28(fn_80342a78(h.r), &n);
                        break;
                    }
                    case 4:
                        fn_801790bc(fn_80343744(h.r), value.p);
                        break;
                    }
                }
            }
            self->busy = 0;
        }
    }
}
