#include "w3d_ptr.h"
#line 1 "d17c_light_node_load_800e9830.cpp"
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
extern "C" void d17c_string_init_8020c5c0(Ptr32<void>);
extern "C" Ptr32<unsigned short> d17c_string_header_80341884(Ptr32<void>);
// Shared engine string; constructor and release are out of line.
struct d17c_String_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> d17c_String_8020bb54(Ptr32<W3dU> w3d_p) : d17c_String_8020bb54((const char *)w3d_p.get()) {}
 d17c_String_8020bb54(const char *);
    d17c_String_8020bb54(const d17c_String_8020bb54 &o) {
        d17c_string_init_8020c5c0(this);
        text = o.text;
        ++*d17c_string_header_80341884(this);
    }
    ~d17c_String_8020bb54();
};
extern "C" void d17c_string_finish_8020c5c4(Ptr32<d17c_String_8020bb54>);
extern "C" void d17c_string_release_80341588(Ptr32<d17c_String_8020bb54>);
inline d17c_String_8020bb54::~d17c_String_8020bb54() {
    d17c_string_finish_8020c5c4(this);
    d17c_string_release_80341588(this);
}
struct d17c_Object;
struct d17c_ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<d17c_Object>)> retain;       // +12
    Ptr32<void (Ptr32<d17c_Object>)> release;      // +16
};
struct d17c_Object { Ptr32<d17c_ObjectVtable> vtable; };
// Retaining reference (one pointer), passed by value: the callee releases it.
struct d17c_Ref {
    Ptr32<d17c_Object> value;
    d17c_Ref() {}
    d17c_Ref(const d17c_Ref &o) { value = o.value; if (value) value->vtable->retain(value); }
    ~d17c_Ref() { if (value) value->vtable->release(value); }
};
struct d17c_Vec3 { float x, y, z; };
struct d17c_Node;
struct d17c_NodeVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<d17c_Node>)> retain;         // +12
    Ptr32<void (Ptr32<d17c_Node>)> release;        // +16
    Ptr32<void> unknown20[10];
    Ptr32<int (Ptr32<d17c_Node>)> kind;            // +60
    Ptr32<void> unknown64[5];
    Ptr32<int (Ptr32<d17c_Node>, Ptr32<const d17c_Vec3>, int)> set_scale;      // +84
    Ptr32<int (Ptr32<d17c_Node>, int)> set_visible;                       // +88
};
struct d17c_Node { Ptr32<d17c_NodeVtable> vtable; };
struct d17c_Member;
struct d17c_Heap { int opaque; };
struct d17c_Team { unsigned char unknown000[224]; float scale; };
struct d17c_Light {
    unsigned char unknown000[28];
    Ptr32<void> owner;                         // +28
    Ptr32<d17c_Node> node;                     // +32
    unsigned char unknown036[176];
    Ptr32<d17c_Member> member;                 // +212
};
extern "C" int d17c_handle_load_8015adf4(Ptr32<const d17c_String_8020bb54>, Ptr32<Ptr32<d17c_Object>>, unsigned char);
extern "C" Ptr32<void> d17c_as_owner_80341584(Ptr32<void>);
extern "C" Ptr32<d17c_Team> d17c_owner_team_801797b4(Ptr32<void>);
extern "C" Ptr32<d17c_Node> d17c_as_node_80343584(Ptr32<d17c_Object>);
extern "C" void d17c_member_destroy_801265a4(Ptr32<d17c_Member>, int);
extern "C" Ptr32<void> d17c_heap_allocate_802098d8(Ptr32<d17c_Heap>, unsigned);
extern "C" Ptr32<d17c_Member> d17c_member_init_kind_8012656c(Ptr32<void>, int);
// El llamado destruye el argumento (GCC 2.95): esta copia no lleva destructor.
struct d17c_RefArg {
    Ptr32<d17c_Object> value;
    d17c_RefArg(const d17c_Ref &o) { value = o.value; if (value) value->vtable->retain(value); }
    d17c_RefArg(const d17c_RefArg &);
};
extern "C" void d17c_member_attach_80126610(Ptr32<d17c_Member>, d17c_RefArg);
extern d17c_Heap d17c_member_heap_804af5bc;

static inline void d17c_load(const d17c_String_8020bb54 &name, Ptr32<Ptr32<d17c_Object>> out) {
    d17c_handle_load_8015adf4(&name, out, 255);
}
extern "C" void d17c_light_node_load_800e9830(Ptr32<d17c_Light> self, Ptr32<const char> text) {
    Ptr32<d17c_Team> team = d17c_owner_team_801797b4(d17c_as_owner_80341584(self->owner));
    d17c_Ref loaded;
    loaded.value = 0;
    Ptr32<Ptr32<d17c_Object>> out = &loaded.value;
    {
        d17c_String_8020bb54 name(text);
        d17c_load(name, out);
    }
    Ptr32<d17c_Node> node = d17c_as_node_80343584(loaded.value);
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


