// d17c: 0x800e9830 (412 bytes). Load a light's node by name: load the named
// resource into a retained node slot (+32; the previous node is released),
// scale it uniformly by the owner team's scale (+224), hide it, replace the
// owned handle member (+212; the old one is destroyed with its delete flag)
// with a new member of the node's kind and, when created, hand it a
// reference to the loaded resource.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return, as are the node slots that GCC schedules as
// value-returning calls. The member attach call takes the reference by value
// (the callee releases it), so the caller only copy-retains it; the copy
// reuses the freed string slot because both classes have copy constructors.
extern "C" void d17c_string_init_8020c5c0(void *);
extern "C" unsigned short *d17c_string_header_80341884(void *);
// Shared engine string; constructor and release are out of line.
struct d17c_String_8020bb54 {
    char *text;
    d17c_String_8020bb54(const char *);
    d17c_String_8020bb54(const d17c_String_8020bb54 &o) {
        d17c_string_init_8020c5c0(this);
        text = o.text;
        ++*d17c_string_header_80341884(this);
    }
    ~d17c_String_8020bb54();
};
extern "C" void d17c_string_finish_8020c5c4(d17c_String_8020bb54 *);
extern "C" void d17c_string_release_80341588(d17c_String_8020bb54 *);
inline d17c_String_8020bb54::~d17c_String_8020bb54() {
    d17c_string_finish_8020c5c4(this);
    d17c_string_release_80341588(this);
}
struct d17c_Object;
struct d17c_ObjectVtable {
    void *unknown00[3];
    void (*retain)(d17c_Object *);       // +12
    void (*release)(d17c_Object *);      // +16
};
struct d17c_Object { d17c_ObjectVtable *vtable; };
// Retaining reference (one pointer), passed by value: the callee releases it.
struct d17c_Ref {
    d17c_Object *value;
    d17c_Ref() {}
    d17c_Ref(const d17c_Ref &o) { value = o.value; if (value) value->vtable->retain(value); }
    ~d17c_Ref() { if (value) value->vtable->release(value); }
};
struct d17c_Vec3 { float x, y, z; };
struct d17c_Node;
struct d17c_NodeVtable {
    void *unknown00[3];
    void (*retain)(d17c_Node *);         // +12
    void (*release)(d17c_Node *);        // +16
    void *unknown20[10];
    int (*kind)(d17c_Node *);            // +60
    void *unknown64[5];
    int (*set_scale)(d17c_Node *, const d17c_Vec3 *, int);      // +84
    int (*set_visible)(d17c_Node *, int);                       // +88
};
struct d17c_Node { d17c_NodeVtable *vtable; };
struct d17c_Member;
struct d17c_Heap { int opaque; };
struct d17c_Team { unsigned char unknown000[224]; float scale; };
struct d17c_Light {
    unsigned char unknown000[28];
    void *owner;                         // +28
    d17c_Node *node;                     // +32
    unsigned char unknown036[176];
    d17c_Member *member;                 // +212
};
extern "C" int d17c_handle_load_8015adf4(const d17c_String_8020bb54 *, d17c_Object **, unsigned char);
extern "C" void *d17c_as_owner_80341584(void *);
extern "C" d17c_Team *d17c_owner_team_801797b4(void *);
extern "C" d17c_Node *d17c_as_node_80343584(d17c_Object *);
extern "C" void d17c_member_destroy_801265a4(d17c_Member *, int);
extern "C" void *d17c_heap_allocate_802098d8(d17c_Heap *, unsigned);
extern "C" d17c_Member *d17c_member_init_kind_8012656c(void *, int);
extern "C" void d17c_member_attach_80126610(d17c_Member *, d17c_Ref);
extern d17c_Heap d17c_member_heap_804af5bc;

static inline void d17c_load(const d17c_String_8020bb54 &name, d17c_Object **out) {
    d17c_handle_load_8015adf4(&name, out, 255);
}
extern "C" void d17c_light_node_load_800e9830(d17c_Light *self, const char *text) {
    d17c_Team *team = d17c_owner_team_801797b4(d17c_as_owner_80341584(self->owner));
    d17c_Ref loaded;
    loaded.value = 0;
    d17c_Object **out = &loaded.value;
    {
        d17c_String_8020bb54 name(text);
        d17c_load(name, out);
    }
    d17c_Node *node = d17c_as_node_80343584(loaded.value);
    if (node) node->vtable->retain(node);
    if (self->node) self->node->vtable->release(self->node);
    self->node = node;
    d17c_Vec3 v;
    float scale = team->scale;
    v.x = scale;
    v.y = scale;
    v.z = scale;
    node->vtable->set_scale(node, &v, 0);
    self->node->vtable->set_visible(self->node, 0);
    if (self->member) d17c_member_destroy_801265a4(self->member, 3);
    self->member = d17c_member_init_kind_8012656c(d17c_heap_allocate_802098d8(&d17c_member_heap_804af5bc, 4), self->node->vtable->kind(self->node));
    if (self->member) d17c_member_attach_80126610(self->member, loaded);
}
