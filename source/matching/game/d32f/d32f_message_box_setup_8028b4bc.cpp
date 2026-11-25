// GWMP8P rev0 0x8028b4bc. Message box setup: starts the sub-object,
// registers four message handlers, loads the FE.TextBoxBackground resource
// into the box, reads the configured count property, then looks up the data
// property, watches it and clamps the current value to the count. Observed
// partial layouts, roles inferred. The by-value Note call is the discarded
// string copy the original makes before formatting the error.
struct Obj { void **table; };
inline void retain(Obj *p) { if (p) ((void (*)(Obj *))p->table[3])(p); }
inline void release(Obj *p) { if (p) ((void (*)(Obj *))p->table[4])(p); }
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(const Handle &);
    ~Handle() { release(p); }
};
extern "C" void w3d_string_base_init(void *), w3d_string_base_finish(void *), w3d_string_release(void *);
extern "C" unsigned short *w3d_string_header(void *);
struct String {
    char *text;
    String(const String &o) { w3d_string_base_init(this); text = o.text; ++*w3d_string_header(this); }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
    unsigned Length() const { return ((unsigned short *)text)[-2]; }
};
struct Key { const char *text; Key(const char *t) : text(t) {} };
struct Config { char pad[164]; const char *images; String data; };
struct Box {
    char pad0[28]; char area[12]; Config *config; char pad44[64]; char error[120];
    Obj *background; char pad232[20]; int m252, m256; char pad260[4]; int m264; char pad268[4]; int m272; int m276;
    Obj *data; int pad284; unsigned value; char pad292[16]; unsigned count;
};
struct Cache { int v[2]; };
extern Cache lbl_804b0c84, lbl_804b0c8c, lbl_804b0c9c, lbl_804b0c7c;
extern char lbl_803cfc58[], lbl_803cfc98[];
extern "C" void *w3d_engine_get_context_80165254();
extern "C" void fn_802b0b84(void *, void *, unsigned);
extern "C" unsigned short fn_8015f5a0(Cache *, int);
extern "C" int fn_80162024(void *, const unsigned short &, void *);
extern "C" void fn_8028c64c(void *), fn_8028ba38(void *), fn_8028c290(void *);
extern "C" int fn_8028c71c(void *, void *);
extern "C" int fn_800fc1b0(const Key &, void *);
extern "C" int fn_800fc230(const Key &, void *);
extern "C" int fn_800fd62c(const String *, int (*)(void *, void *), void *, void *);
extern "C" Obj *fn_80343df4(Obj *);
extern "C" Obj *fn_803426b4(Obj *), *fn_80342a78(Obj *);
extern "C" unsigned fn_80178c48(Obj *), fn_80178d1c(Obj *);
extern "C" void w3d_string_format(void *, const char *, ...);
inline void Note(String) {}
extern "C" void d32f_message_box_setup_8028b4bc(Box *self) {
    fn_802b0b84(self->area, self, *(unsigned *)((char *)w3d_engine_get_context_80165254() + 52));
    fn_80162024(self, fn_8015f5a0(&lbl_804b0c84, 1), &self->m252);
    fn_80162024(self, fn_8015f5a0(&lbl_804b0c8c, 1), &self->m256);
    fn_80162024(self, fn_8015f5a0(&lbl_804b0c9c, 1), &self->m272);
    fn_80162024(self, fn_8015f5a0(&lbl_804b0c7c, 1), &self->m264);
    fn_8028c64c(self);
    Config *config = self->config;
    Handle resource;
    fn_800fc1b0(lbl_803cfc58, &resource);
    Obj *back = fn_80343df4(resource.p);
    retain(back);
    release(self->background);
    self->background = back;
    if (((unsigned short *)config->images)[-2])
        fn_800fc230(config->images, &self->count);
    if (config->data.Length()) {
        if (fn_800fc1b0(config->data.text, &self->data) < 0) {
            release(self->data);
            self->data = 0;
            Note(config->data);
            w3d_string_format(self->error, lbl_803cfc98, config->data.text);
        } else {
            fn_800fd62c(&config->data, fn_8028c71c, self, &self->m276);
            switch (((int (*)(Obj *))self->data->table[6])(self->data)) {
            case 0: self->value = fn_80178c48(fn_803426b4(self->data)); break;
            case 1: self->value = fn_80178d1c(fn_80342a78(self->data)); break;
            }
            unsigned last = self->count - 1;
            if (self->value > last)
                self->value = last;
        }
    }
    fn_8028ba38(self);
    fn_8028c290(self);
}
