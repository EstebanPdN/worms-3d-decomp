// GWMP8P rev0 0x80295cec. Creates or clears the seven scroll box part
// handles: with a source it loads the box by name, resolves each part at the
// box level plus an offset, tags six parts with their ids, adds all seven to
// the list and lays the box out. The handle and the by-value name temporary
// share one stack block, as the original's frame shows.
struct Obj { void **vtable; };
inline void retain(Obj *p) { ((void (*)(Obj *))p->vtable[3])(p); }
inline void release(Obj *p) { ((void (*)(Obj *))p->vtable[4])(p); }
extern "C" void w3d_string_base_init(void *), w3d_string_base_finish(void *), w3d_string_release(void *);
extern "C" unsigned short *w3d_string_header(void *);
struct String {
    char *text;
    String(const String &o) {
        w3d_string_base_init(this);
        text = o.text;
        ++*w3d_string_header(this);
    }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Handle {
    Obj *p;
    Handle() : p(0) {}
    Handle(const Handle &);
    ~Handle() { if (p) release(p); }
};
struct Ref {
    Obj *p;
    Ref &operator=(Obj *q) {
        if (q) retain(q);
        if (p) release(p);
        p = q;
        return *this;
    }
    };
struct Self {
    char pad[31]; unsigned char level; char pad32[28]; int active; char pad64[60]; Obj *list; Ref a, b, c, d, e, f, g; char pad156[16]; Obj *source; String name;
};
extern "C" int w3d_handle_set_name(String *, Handle *, unsigned char);
extern "C" Obj *w3d_empty_8034357c(Obj *);
extern "C" int w3d_s20_store_byte_value_80173f88(Obj *, const unsigned char *);
extern "C" void fn_80263608(String, int);
extern "C" void d29f_scroll_box_layout_8029556c(Self *);
inline void Add(Self *self, Obj *o) { ((int (*)(Obj *, Obj *, int))self->list->vtable[23])(self->list, o, 0); }
extern "C" void d31f_scroll_box_parts_80295cec(Self *self) {
    Obj *source = self->source;
    if (source == 0) {
        self->a = 0;
        self->b = 0;
        self->c = 0;
        self->d = 0;
        self->e = 0;
        self->f = 0;
        self->g = 0;
        self->active = 0;
        return;
    }
    fn_80263608(self->name, 0);
    Handle h;
    w3d_handle_set_name(&self->name, &h, self->level + 33);
    self->b = w3d_empty_8034357c(h.p);
    w3d_handle_set_name(&self->name, &h, self->level + 33);
    self->c = w3d_empty_8034357c(h.p);
    w3d_handle_set_name(&self->name, &h, self->level + 32);
    self->d = w3d_empty_8034357c(h.p);
    w3d_handle_set_name(&self->name, &h, self->level + 33);
    self->e = w3d_empty_8034357c(h.p);
    w3d_handle_set_name(&self->name, &h, self->level + 33);
    self->f = w3d_empty_8034357c(h.p);
    w3d_handle_set_name(&self->name, &h, self->level + 33);
    self->g = w3d_empty_8034357c(h.p);
    w3d_handle_set_name(&self->name, &h, self->level + 31);
    self->a = w3d_empty_8034357c(h.p);
    Obj *second = self->b.p;
    unsigned char c0 = 13;
    w3d_s20_store_byte_value_80173f88(second, &c0);
    unsigned char c1 = 14;
    w3d_s20_store_byte_value_80173f88(self->c.p, &c1);
    unsigned char c2 = 65;
    w3d_s20_store_byte_value_80173f88(self->d.p, &c2);
    unsigned char c3 = 47;
    w3d_s20_store_byte_value_80173f88(self->e.p, &c3);
    unsigned char c4 = 48;
    w3d_s20_store_byte_value_80173f88(self->f.p, &c4);
    unsigned char c5 = 49;
    w3d_s20_store_byte_value_80173f88(self->g.p, &c5);
    Add(self, self->a.p);
    Add(self, self->b.p);
    Add(self, self->c.p);
    Add(self, self->d.p);
    Add(self, self->e.p);
    Add(self, self->f.p);
    Add(self, self->g.p);
    self->active = 1;
    d29f_scroll_box_layout_8029556c(self);
}
