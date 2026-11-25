// d24i: 0x8010682c (440 bytes). Create two objects from the class records
// 0x80416560 and 0x80415c30 (0x8020b680), query the source for the record
// 0x8040e078 (virtual +56), clear +24 of the second object and set bit 2 of its
// flag byte, transform it through the manager 0x8020b648 (virtual +92 with
// 0x804143e0, then virtual +44), keep the result, and hand it and the queried
// object to the first object (virtual +48 and +24). Returns 0.
struct d24i_Flags {
    unsigned char unknown00[7];
    unsigned char bits;                  // +7
    void mark() { bits |= 2; }
};
struct d24i_Object;
struct d24i_ObjectVtable {
    void *unknown00[3];
    void (*retain)(d24i_Object *);                   // +12
    void (*release)(d24i_Object *);                  // +16
    void *unknown14;
    void (*set_child)(d24i_Object *, d24i_Object *); // +24
    void *unknown1c[4];
    d24i_Object *(*convert)(d24i_Object *, d24i_Object *);    // +44
    void (*set_shape)(d24i_Object *, d24i_Object *);          // +48
    void *unknown34;
    void (*query)(d24i_Object *, const void *, int, void *);  // +56
    void *unknown3c[8];
    d24i_Object *(*select)(d24i_Object *, const void *);      // +92
};
struct d24i_Object {
    d24i_ObjectVtable *vtable;
    d24i_Flags flags;                    // +4
    unsigned char unknown0c[12];
    int unknown18;                       // +24
};
struct d24i_Ref {
    d24i_Object *value;
    d24i_Ref() { value = 0; }
    d24i_Ref(d24i_Object *object) {
        value = object;
        if (object) object->vtable->retain(object);
    }
    ~d24i_Ref() { if (value) value->vtable->release(value); }
    d24i_Ref &operator=(d24i_Object *object) {
        if (object) object->vtable->retain(object);
        if (value) value->vtable->release(value);
        value = object;
        return *this;
    }
};
extern "C" d24i_Object *d24i_create_8020b680(const void *);
extern "C" d24i_Object *d24i_manager_8020b648(void);
extern const char d24i_class_80416560[], d24i_class_80415c30[], d24i_record_8040e078[], d24i_record_804143e0[];

static inline d24i_Object *d24i_select(const void *record) {
    d24i_Object *manager = d24i_manager_8020b648();
    return manager->vtable->select(manager, record);
}
static inline d24i_Ref d24i_make(const void *record) { return d24i_Ref(d24i_create_8020b680(record)); }
static inline int d24i_link3(d24i_Ref &first, d24i_Ref &second, d24i_Object *source) {
    d24i_Ref queried;
    source->vtable->query(source, d24i_record_8040e078, 0, &queried);
    d24i_Object *child = queried.value;
    d24i_Object *shape = second.value;
    shape->unknown18 = 0;
    shape->flags.mark();
    d24i_Object *converted = d24i_select(d24i_record_804143e0);
    second = converted->vtable->convert(converted, second.value);
    first.value->vtable->set_shape(first.value, second.value);
    first.value->vtable->set_child(first.value, child);
    return 0;
}
static inline int d24i_link2(d24i_Ref &first, d24i_Object *source) {
    d24i_Ref second = d24i_make(d24i_class_80415c30);
    return d24i_link3(first, second, source);
}
extern "C" int d24i_material_link_8010682c(void *, d24i_Object *source) {
    d24i_Ref first = d24i_make(d24i_class_80416560);
    return d24i_link2(first, source);
}
