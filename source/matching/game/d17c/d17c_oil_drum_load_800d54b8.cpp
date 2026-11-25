// d17c: 0x800d54b8 (448 bytes). Load an oil drum's mesh: load "OilDrum",
// clear and then set the retained node slot (+32), create a handle member of
// the node's kind (+48) and hand it a reference to the loaded resource,
// publish the current worm count, and when the "WormCount" setting is below
// 15 start the idle clip (1.0, 0.0, 0.0) and check its control; finally
// make the mesh follow its owner.
// 0x8015adf4 and the settings reader forward virtual results, so they are
// declared with status returns. The member attach call takes the reference
// by value (the callee releases it), so the caller only copy-retains it.
// The float literals form this function's constant pool at 0x80388df0.
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
struct d17c_Drum {
    unsigned char unknown00[32];
    d17c_Node *node;                     // +32
    unsigned char unknown36[12];
    d17c_Member *member;                 // +48
};
// Settings key: a pointer to the setting's name.
struct d17c_Key { const char *text; };
extern "C" int d17c_handle_load_8015adf4(const d17c_String_8020bb54 *, d17c_Object **, unsigned char);
extern "C" d17c_Node *d17c_as_node_80343584(d17c_Object *);
extern "C" void *d17c_heap_allocate_802098d8(d17c_Heap *, unsigned);
extern "C" d17c_Member *d17c_member_init_kind_8012656c(void *, int);
extern "C" void d17c_member_attach_80126610(d17c_Member *, d17c_Ref);
extern "C" void d17c_publish_worm_count_801555f8(void *);
extern "C" int d17c_read_uint_800fc230(d17c_Key *, unsigned *);
extern "C" int d17c_play_clip_80181640(d17c_Node *, const char *, int *, int, float, float, float);
extern "C" int d17c_check_control_8018179c(d17c_Node *, int, int);
extern "C" void d17c_follow_owner_800d56bc(d17c_Drum *);
extern d17c_Heap d17c_member_heap_804af5bc;
extern int d17c_worm_count_804ab400;
extern const char *d17c_idle_clip_804aae54;
extern const char d17c_oil_drum_80388d90[];      // "OilDrum"
extern const char d17c_worm_count_80388db8[];    // "WormCount"

static inline void d17c_load(const d17c_String_8020bb54 &name, d17c_Object **out) {
    d17c_handle_load_8015adf4(&name, out, 255);
}
extern "C" void d17c_oil_drum_load_800d54b8(d17c_Drum *self) {
    d17c_Ref loaded;
    loaded.value = 0;
    d17c_Object **out = &loaded.value;
    {
        d17c_String_8020bb54 name(d17c_oil_drum_80388d90);
        d17c_load(name, out);
    }
    if (self->node) self->node->vtable->release(self->node);
    self->node = 0;
    d17c_Node *node = d17c_as_node_80343584(loaded.value);
    if (node) node->vtable->retain(node);
    if (self->node) self->node->vtable->release(self->node);
    self->node = node;
    self->member = d17c_member_init_kind_8012656c(d17c_heap_allocate_802098d8(&d17c_member_heap_804af5bc, 4), self->node->vtable->kind(self->node));
    if (self->member) d17c_member_attach_80126610(self->member, loaded);
    d17c_publish_worm_count_801555f8((void *)d17c_worm_count_804ab400);
    d17c_Key key;
    key.text = d17c_worm_count_80388db8;
    unsigned count;
    d17c_read_uint_800fc230(&key, &count);
    if (count < 15) {
        int control;
        d17c_play_clip_80181640(self->node, d17c_idle_clip_804aae54, &control, 1, 1.0f, 0.0f, 0.0f);
        d17c_check_control_8018179c(self->node, control, 1);
    }
    d17c_follow_owner_800d56bc(self);
}
