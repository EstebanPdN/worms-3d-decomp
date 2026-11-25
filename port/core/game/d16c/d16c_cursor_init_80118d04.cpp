#include "w3d_ptr.h"
#line 1 "d16c_cursor_init_80118d04.cpp"
// d16c: 0x80118d04 (336 bytes). Initialise the targeting cursor: set up its
// mesh, bitmap and Target clips, subscribe to its message (+40), load the
// "Targeting.Cursor.Shadow" mesh, keep it retained (+92, releasing the old
// one), colour it, attach it to the scene (+28) with the "Target_Shadow" clip
// and clear +96/+100.
// 0x8015adf4 forwards the resource manager's virtual load result and
// 0x80173df0 returns 0, so both are declared with status returns.
struct d16c_String_8020bb54 {
 d16c_String_8020bb54(const d16c_String_8020bb54 &);
    Ptr32<char> text;
    template <class W3dU> d16c_String_8020bb54(Ptr32<W3dU> w3d_p) : d16c_String_8020bb54((const char *)w3d_p.get()) {}
 d16c_String_8020bb54(const char *);
    ~d16c_String_8020bb54();
};
extern "C" void d16c_string_finish_8020c5c4(Ptr32<d16c_String_8020bb54>);
extern "C" void d16c_string_release_80341588(Ptr32<d16c_String_8020bb54>);
inline d16c_String_8020bb54::~d16c_String_8020bb54() {
    d16c_string_finish_8020c5c4(this);
    d16c_string_release_80341588(this);
}
struct d16c_Object;
struct d16c_ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<d16c_Object>)> retain;       // +12
    Ptr32<void (Ptr32<d16c_Object>)> release;      // +16
};
struct d16c_Object { Ptr32<d16c_ObjectVtable> vtable; };
// Retaining reference (one pointer, not copyable).
struct d16c_Ref {
    Ptr32<d16c_Object> value;
    d16c_Ref() { value = 0; }
    ~d16c_Ref() { if (value) value->vtable->release(value); }
private:
    d16c_Ref(const d16c_Ref &);
};
struct d16c_MessageId { unsigned short value; d16c_MessageId() {} };
struct d16c_Scene;
struct d16c_SceneVtable {
    Ptr32<void> unknown00[23];
    Ptr32<void (Ptr32<d16c_Scene>, Ptr32<d16c_Object>, Ptr32<const char>)> attach;   // +92
};
struct d16c_Scene { Ptr32<d16c_SceneVtable> vtable; };
struct d16c_Cursor {
    unsigned char unknown00[28];
    Ptr32<d16c_Scene> scene;                   // +28
    unsigned char unknown20[8];
    unsigned subscription;               // +40
    unsigned char unknown2c[48];
    Ptr32<d16c_Object> shadow;                 // +92
    int unknown60;                       // +96
    int unknown64;                       // +100
};
extern "C" void d16c_cursor_base_init_8004e0dc(Ptr32<d16c_Cursor>, Ptr32<const char>, Ptr32<const char>, Ptr32<const char>, Ptr32<const char>, Ptr32<const char>, Ptr32<const char>);
extern "C" unsigned short d16c_cached_message_id_8015f5a0(Ptr32<void>, int);
extern "C" int d16c_subscribe_80162024(Ptr32<d16c_Cursor>, Ptr32<d16c_MessageId>, Ptr32<unsigned int>);
extern "C" int d16c_handle_load_8015adf4(Ptr32<const d16c_String_8020bb54>, Ptr32<Ptr32<d16c_Object>>, unsigned char);
extern "C" Ptr32<d16c_Object> d16c_as_mesh_8034357c(Ptr32<d16c_Object>);
extern "C" int d16c_mesh_set_colour_80173df0(Ptr32<d16c_Object>, Ptr32<void>);
extern const char d16c_mesh_8039aa00[], d16c_bitmap_8039aa18[], d16c_target_8039aa30[],
    d16c_intro_8039aa38[], d16c_loop_8039aa48[], d16c_error_8039aa54[],
    d16c_shadow_name_8039aa64[], d16c_shadow_clip_8039aa7c[];
extern unsigned int d16c_message_804ad424;
extern unsigned int d16c_shadow_colour_804af314;

extern "C" void d16c_cursor_init_80118d04(Ptr32<d16c_Cursor> self) {
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
    Ptr32<d16c_Object> shadow = d16c_as_mesh_8034357c(loaded.value);
    if (shadow) shadow->vtable->retain(shadow);
    if (self->shadow) self->shadow->vtable->release(self->shadow);
    self->shadow = shadow;
    d16c_mesh_set_colour_80173df0(shadow, &d16c_shadow_colour_804af314);
    self->scene->vtable->attach(self->scene, self->shadow, d16c_shadow_clip_8039aa7c);
    self->unknown60 = 0;
    self->unknown64 = 0;
}


