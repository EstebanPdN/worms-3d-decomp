#include "w3d_ptr.h"
#line 1 "d31i_effect_resource_load_80106300.cpp"
// d31i: 0x80106300. Registers the effect resources of a level by name
// through a finder object: Fractal, else Subtractive, and five numbered
// ones, then links the material.
struct String {
    Ptr32<char> text;
    String();
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
extern "C" void string_format_8020c510(Ptr32<String>, Ptr32<const char>, ...);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;
    Ptr32<void (Ptr32<Object>)> release;
    Ptr32<void> unknown14;
    Ptr32<int (Ptr32<Object>, Ptr32<Object>)> find;
    Ptr32<void> unknown1c[5];
    Ptr32<void (Ptr32<Object>, Ptr32<const char>)> set_name;
    Ptr32<Ptr32<void> (Ptr32<Object>)> result;
    Ptr32<void (Ptr32<Object>, Ptr32<const void>, int, Ptr32<void>)> query;
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() : value(0) {}
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Object *)w3d_p.get()) {}
 Handle(Object *next) : value(next) { if (value) value->vtable->retain(value); }
    Handle(const Handle &);
    ~Handle() { if (value) value->vtable->release(value); }
};
struct Level;
extern "C" Ptr32<Object> create_8020b680(Ptr32<const void>);
extern "C" void reg_a_80106530(Ptr32<Level>, Ptr32<void>);
extern "C" void reg_b_80106734(Ptr32<Level>, Ptr32<void>);
extern "C" void reg_c_8010663c(Ptr32<Level>, Ptr32<void>);
extern "C" int link_8010682c(Ptr32<Level>, Ptr32<Object>);
extern const char class_804164c0[], record_8040e078[], s_803998bc[], s_803998c4[], s_803998d0[];
extern "C" int d31i_effect_resource_load_80106300(Ptr32<Level> self, Ptr32<Object> source) {
    Handle finder(create_8020b680(class_804164c0));
    Handle queried;
    source->vtable->query(source, record_8040e078, 0, &queried);
    Ptr32<Object> child = queried.value;
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


