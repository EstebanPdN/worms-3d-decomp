// d16c: 0x80118d04 (336 bytes). Initialise the targeting cursor: set up its
// mesh, bitmap and Target clips, subscribe to its message (+40), load the
// "Targeting.Cursor.Shadow" mesh, keep it retained (+92, releasing the old
// one), colour it, attach it to the scene (+28) with the "Target_Shadow" clip
// and clear +96/+100.
// 0x8015adf4 forwards the resource manager's virtual load result and
// 0x80173df0 returns 0, so both are declared with status returns.
struct d16c_String_8020bb54 {
 d16c_String_8020bb54(const d16c_String_8020bb54 &);
    char *text;
    d16c_String_8020bb54(const char *);
    ~d16c_String_8020bb54();
};
extern "C" void d16c_string_finish_8020c5c4(d16c_String_8020bb54 *);
extern "C" void d16c_string_release_80341588(d16c_String_8020bb54 *);
inline d16c_String_8020bb54::~d16c_String_8020bb54() {
    d16c_string_finish_8020c5c4(this);
    d16c_string_release_80341588(this);
}
struct d16c_Object;
struct d16c_ObjectVtable {
    void *unknown00[3];
    void (*retain)(d16c_Object *);       // +12
    void (*release)(d16c_Object *);      // +16
};
struct d16c_Object { d16c_ObjectVtable *vtable; };
// Retaining reference (one pointer, not copyable).
struct d16c_Ref {
    d16c_Object *value;
    d16c_Ref() { value = 0; }
    ~d16c_Ref() { if (value) value->vtable->release(value); }
private:
    d16c_Ref(const d16c_Ref &);
};
struct d16c_MessageId { unsigned short value; d16c_MessageId() {} };
struct d16c_Scene;
struct d16c_SceneVtable {
    void *unknown00[23];
    void (*attach)(d16c_Scene *, d16c_Object *, const char *);   // +92
};
struct d16c_Scene { d16c_SceneVtable *vtable; };
struct d16c_Cursor {
    unsigned char unknown00[28];
    d16c_Scene *scene;                   // +28
    unsigned char unknown20[8];
    unsigned subscription;               // +40
    unsigned char unknown2c[48];
    d16c_Object *shadow;                 // +92
    int unknown60;                       // +96
    int unknown64;                       // +100
};
extern "C" void d16c_cursor_base_init_8004e0dc(d16c_Cursor *, const char *, const char *, const char *, const char *, const char *, const char *);
extern "C" unsigned short d16c_cached_message_id_8015f5a0(void *, int);
extern "C" int d16c_subscribe_80162024(d16c_Cursor *, d16c_MessageId *, unsigned *);
extern "C" int d16c_handle_load_8015adf4(const d16c_String_8020bb54 *, d16c_Object **, unsigned char);
extern "C" d16c_Object *d16c_as_mesh_8034357c(d16c_Object *);
extern "C" int d16c_mesh_set_colour_80173df0(d16c_Object *, void *);
extern const char d16c_mesh_8039aa00[], d16c_bitmap_8039aa18[], d16c_target_8039aa30[],
    d16c_intro_8039aa38[], d16c_loop_8039aa48[], d16c_error_8039aa54[],
    d16c_shadow_name_8039aa64[], d16c_shadow_clip_8039aa7c[];
extern unsigned int d16c_message_804ad424;
extern unsigned int d16c_shadow_colour_804af314;

extern "C" void d16c_cursor_init_80118d04(d16c_Cursor *self) {
    d16c_cursor_base_init_8004e0dc(self, d16c_mesh_8039aa00, d16c_bitmap_8039aa18, d16c_target_8039aa30,
        d16c_intro_8039aa38, d16c_loop_8039aa48, d16c_error_8039aa54);
    d16c_MessageId id;
    id.value = d16c_cached_message_id_8015f5a0(&d16c_message_804ad424, 1);
    d16c_subscribe_80162024(self, &id, &self->subscription);
    d16c_Ref loaded;
    {
        d16c_String_8020bb54 name(d16c_shadow_name_8039aa64);
        d16c_handle_load_8015adf4(&name, &loaded.value, 255);
    }
    d16c_Object *shadow = d16c_as_mesh_8034357c(loaded.value);
    if (shadow) shadow->vtable->retain(shadow);
    if (self->shadow) self->shadow->vtable->release(self->shadow);
    self->shadow = shadow;
    d16c_mesh_set_colour_80173df0(shadow, &d16c_shadow_colour_804af314);
    self->scene->vtable->attach(self->scene, self->shadow, d16c_shadow_clip_8039aa7c);
    self->unknown60 = 0;
    self->unknown64 = 0;
}
