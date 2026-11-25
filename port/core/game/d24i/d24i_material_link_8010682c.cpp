#include "w3d_ptr.h"
#line 1 "d24i_material_link_8010682c.cpp"
// d24i: 0x8010682c (440 bytes). Create two objects from the class records
// 0x80416560 and 0x80415c30 (0x8020b680), query the source for the record
// 0x8040e078 (virtual +56), clear +24 of the second object and set bit 2 of its
// flag byte, transform it through the manager 0x8020b648 (virtual +92 with
// 0x804143e0, then virtual +44), keep the result, and hand it and the queried
// object to the first object (virtual +48 and +24). Returns 0.
struct d24i_Flags {
    unsigned char unknown00[4];
    unsigned char bits; char w3d_tag_rest[3];                  // +7
    void mark() { bits |= 2; }
};
struct d24i_Object;
struct d24i_ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<d24i_Object>)> retain;                   // +12
    Ptr32<void (Ptr32<d24i_Object>)> release;                  // +16
    Ptr32<void> unknown14;
    Ptr32<void (Ptr32<d24i_Object>, Ptr32<d24i_Object>)> set_child; // +24
    Ptr32<void> unknown1c[4];
    Ptr32<Ptr32<d24i_Object> (Ptr32<d24i_Object>, Ptr32<d24i_Object>)> convert;    // +44
    Ptr32<void (Ptr32<d24i_Object>, Ptr32<d24i_Object>)> set_shape;          // +48
    Ptr32<void> unknown34;
    Ptr32<void (Ptr32<d24i_Object>, Ptr32<const void>, int, Ptr32<void>)> query;  // +56
    Ptr32<void> unknown3c[8];
    Ptr32<Ptr32<d24i_Object> (Ptr32<d24i_Object>, Ptr32<const void>)> select;      // +92
};
struct d24i_Object {
    Ptr32<d24i_ObjectVtable> vtable;
    d24i_Flags flags;                    // +4
    unsigned char unknown0c[12];
    int unknown18;                       // +24
};
struct d24i_Ref {
    Ptr32<d24i_Object> value;
    d24i_Ref() { value = 0; }
    template <class W3dU> d24i_Ref(Ptr32<W3dU> w3d_p) : d24i_Ref((d24i_Object *)w3d_p.get()) {}
 d24i_Ref(d24i_Object *object) {
        value = object;
        if (object) object->vtable->retain(object);
    }
    ~d24i_Ref() { if (value) value->vtable->release(value); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((d24i_Object *)w3d_p.get()); }
 d24i_Ref &operator=(d24i_Object *object) {
        if (object) object->vtable->retain(object);
        if (value) value->vtable->release(value);
        value = object;
        return *this;
    }
};
extern "C" Ptr32<d24i_Object> d24i_create_8020b680(Ptr32<const void>);
extern "C" Ptr32<d24i_Object> d24i_manager_8020b648(void);
extern const char d24i_class_80416560[], d24i_class_80415c30[], d24i_record_8040e078[], d24i_record_804143e0[];

static inline Ptr32<d24i_Object> d24i_select(Ptr32<const void> record) {
    Ptr32<d24i_Object> manager = d24i_manager_8020b648();
    return manager->vtable->select(manager, record);
}
static inline d24i_Ref d24i_make(Ptr32<const void> record) { return d24i_Ref(d24i_create_8020b680(record)); }
static inline int d24i_link3(d24i_Ref &first, d24i_Ref &second, Ptr32<d24i_Object> source) {
    d24i_Ref queried;
    source->vtable->query(source, d24i_record_8040e078, 0, &queried);
    Ptr32<d24i_Object> child = queried.value;
    Ptr32<d24i_Object> shape = second.value;
    shape->unknown18 = 0;
    shape->flags.mark();
    Ptr32<d24i_Object> converted = d24i_select(d24i_record_804143e0);
    second = converted->vtable->convert(converted, second.value);
    first.value->vtable->set_shape(first.value, second.value);
    first.value->vtable->set_child(first.value, child);
    return 0;
}
static inline int d24i_link2(d24i_Ref &first, Ptr32<d24i_Object> source) {
    d24i_Ref second = d24i_make(d24i_class_80415c30);
    return d24i_link3(first, second, source);
}
extern "C" int d24i_material_link_8010682c(Ptr32<void>, Ptr32<d24i_Object> source) {
    d24i_Ref first = d24i_make(d24i_class_80416560);
    return d24i_link2(first, source);
}


