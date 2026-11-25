// d31i: 0x80105ac8. Builds a framed text panel with its background, inner,
// colour and extra widgets, attaches it to the owner and adds it to the
// panel list.
struct Object;
struct ObjectVtable { void *unknown00[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Handle {
    Object *value;
    Handle(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
};
struct Ref {
    Object *value;
    void operator=(Object *next) {
        Object *old = value;
        value = next;
        if (next) next->vtable->retain(next);
        if (old) old->vtable->release(old);
    }
};
struct Colour {
    float r, g, b, a;
    void set(float x, float y, float z, float w) { r = x; g = y; b = z; a = w; }
};
struct Flags { unsigned char unknown00[7]; unsigned char bits; void Set(int m) { bits |= m; } };
struct Widget {
    Object base;
    Flags flags;        // +4
    unsigned char unknown0c[8];
    int mode;           // +20 unused view
    union { int w24; Colour c24; };
    unsigned char unknown28[0];
};
struct Plain {
    Object base;
    Flags flags;        // +4
    unsigned char unknown0c[12];
    int w24;
    int w28;
    void Set24(int v) { w24 = v; flags.Set(2); }
    void Set28(int v) { w28 = v; flags.Set(2); }
};
struct Box {
    Object base;
    Flags flags;        // +4
    unsigned char unknown0c[12];
    Colour a24;
    Colour a40;
    Colour a56;
    Colour a72;
    float f88;
    void SetA(const Colour &c) { a56 = c; flags.Set(2); }
    void SetB(const Colour &c) { a72 = c; flags.Set(2); }
    void SetC(const Colour &c) { a24 = c; flags.Set(2); }
    void SetD(const Colour &c) { a40 = c; flags.Set(2); }
    void SetF(float f) { f88 = f; flags.Set(2); }
};
struct Theme { unsigned char unknown00[20]; Ref child; };
struct Panel {
    unsigned char unknown00[28];
    float f28, f32, f36, f40, f44;
    unsigned char unknown30[4];
    Ref r52;
    Ref r56;
};
struct Owner { unsigned char unknown00[52]; Ref panel; };
struct Array { Object **start, **finish, **end; };
extern "C" Object *create_8020b680(const void *);
extern "C" Object **find_801d0858(Object *, int *);
extern "C" void list_append_801ef174(Object *, int, int, Object *);
extern "C" void *allocate_80212fd4(unsigned);
extern "C" void release_802134fc(void *);
extern "C" void *memcpy(void *, const void *, unsigned, ...);
extern const char class_80415b40[], class_80415c30[], class_80415d00[], class_80415c00[], class_80415ba0[], class_80415cb0[];
extern int guard_804af1dc, guard_804af1e0, guard_804af1e4;
extern Colour c0_8044b64c, c1_8044b65c, c2_8044b66c;
extern Array panels_8044b694;
inline const int &imax(const int &a, const int &b) { return a < b ? b : a; }
inline const unsigned &umin(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
inline void Push(Array &list, Object *const &v) {
    if (list.finish == list.end) {
        unsigned size = (char *)list.finish - (char *)list.start;
        unsigned bytes = imax(size + 1, size + (size >> 1)) << 2;
        void *mem = allocate_80212fd4(bytes);
        if (list.start) {
            memcpy(mem, list.start, umin(bytes, size));
            release_802134fc(list.start);
        }
        list.finish = (Object **)((char *)mem + size);
        list.start = (Object **)mem;
        list.end = (Object **)((char *)mem + bytes);
    }
    *list.finish = v;
    ++list.finish;
}
extern "C" int d31i_panel_build_80105ac8(void *self, Owner *owner) {
    Handle panel(create_8020b680(class_80415b40));
    Object *theme = 0;
    int found;
    Object **q = find_801d0858(owner->panel.value, &found);
    if (found) theme = *q;
    Handle bg(create_8020b680(class_80415c30));
    int on = 1;
    ((Plain *)bg.value)->Set24(0);
    ((Theme *)theme)->child = create_8020b680(class_80415d00);
    Handle inner(create_8020b680(class_80415c00));
    ((Plain *)inner.value)->Set24(0);
    Handle box(create_8020b680(class_80415ba0));
    if (!guard_804af1dc) {
        guard_804af1dc = on;
        c0_8044b64c.set(1.0f, 1.0f, 1.0f, 1.0f);
    }
    if (!guard_804af1e0) {
        guard_804af1e0 = on;
        c1_8044b65c.set(0.0f, 0.0f, 0.0f, 0.0f);
    }
    if (!guard_804af1e4) {
        c2_8044b66c.set(0.75f, 0.75f, 0.75f, 0.0f);
        guard_804af1e4 = on;
    }
    ((Box *)box.value)->SetA(c0_8044b64c);
    ((Box *)box.value)->SetB(c0_8044b64c);
    ((Box *)box.value)->SetC(c2_8044b66c);
    ((Box *)box.value)->SetD(c1_8044b65c);
    ((Box *)box.value)->SetF(20.0f);
    ((Box *)box.value)->flags.Set(1);
    Handle extra(create_8020b680(class_80415cb0));
    ((Plain *)extra.value)->Set28(on);
    ((Plain *)extra.value)->Set24(on);
    list_append_801ef174(panel.value, 48, 4, bg.value);
    list_append_801ef174(panel.value, 48, 4, extra.value);
    list_append_801ef174(panel.value, 48, 4, box.value);
    list_append_801ef174(panel.value, 48, 4, inner.value);
    ((Panel *)panel.value)->r56 = theme;
    ((Panel *)panel.value)->r52 = theme;
    owner->panel = panel.value;
    ((Panel *)panel.value)->f28 = 1.7f;
    ((Panel *)panel.value)->f44 = 0.0f;
    ((Panel *)panel.value)->f40 = 0.0f;
    ((Panel *)panel.value)->f36 = 0.0f;
    ((Panel *)panel.value)->f32 = 0.0f;
    Object *value = panel.value;
    Push(panels_8044b694, value);
    return 0;
}
