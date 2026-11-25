// d31i: 0x80106300. Registers the effect resources of a level by name
// through a finder object: Fractal, else Subtractive, and five numbered
// ones, then links the material.
struct String {
    char *text;
    String();
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
extern "C" void string_format_8020c510(String *, const char *, ...);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);
    void (*release)(Object *);
    void *unknown14;
    int (*find)(Object *, Object *);
    void *unknown1c[5];
    void (*set_name)(Object *, const char *);
    void *(*result)(Object *);
    void (*query)(Object *, const void *, int, void *);
};
struct Object { ObjectVtable *vtable; };
struct Handle {
    Object *value;
    Handle() : value(0) {}
    Handle(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
};
struct Level;
extern "C" Object *create_8020b680(const void *);
extern "C" void reg_a_80106530(Level *, void *);
extern "C" void reg_b_80106734(Level *, void *);
extern "C" void reg_c_8010663c(Level *, void *);
extern "C" int link_8010682c(Level *, Object *);
extern const char class_804164c0[], record_8040e078[], s_803998bc[], s_803998c4[], s_803998d0[];
extern "C" int d31i_effect_resource_load_80106300(Level *self, Object *source) {
    Handle finder(create_8020b680(class_804164c0));
    Handle queried;
    source->vtable->query(source, record_8040e078, 0, &queried);
    Object *child = queried.value;
    int found = 0;
    finder.value->vtable->set_name(finder.value, s_803998bc);
    if (finder.value->vtable->find(finder.value, child) >= 0) {
        found = 1;
        reg_a_80106530(self, finder.value->vtable->result(finder.value));
    }
    if (!found) {
        finder.value->vtable->set_name(finder.value, s_803998c4);
        if (finder.value->vtable->find(finder.value, child) >= 0)
            reg_b_80106734(self, finder.value->vtable->result(finder.value));
    }
    String name;
    for (unsigned i = 0; i <= 4; ++i) {
        string_format_8020c510(&name, s_803998d0, i);
        finder.value->vtable->set_name(finder.value, name.text);
        if (finder.value->vtable->find(finder.value, child) >= 0)
            reg_c_8010663c(self, finder.value->vtable->result(finder.value));
    }
    link_8010682c(self, source);
    return 0;
}
