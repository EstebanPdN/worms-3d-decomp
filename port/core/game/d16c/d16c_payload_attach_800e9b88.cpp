#include "w3d_ptr.h"
#line 1 "d16c_payload_attach_800e9b88.cpp"
// d16c: 0x800e9b88 (384 bytes). Load "NULL" resources into an entity's two
// handles (+200, +204), register both with its sink through virtual slot +92
// using the owner team's values (+240, +408); when both succeed, create a
// label service, attach it to the manager (result kept at +196) and initialise
// it with a copy of the team name (+412) and code (+406).
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return. The label constructor takes the shared string
// by value (the callee destroys it, so the caller only copies it).
extern "C" void d16c_string_init_8020c5c0(Ptr32<void>);
extern "C" Ptr32<unsigned short> d16c_string_header_80341884(Ptr32<void>);
struct d16c_String_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> d16c_String_8020bb54(Ptr32<W3dU> w3d_p) : d16c_String_8020bb54((const char *)w3d_p.get()) {}
 d16c_String_8020bb54(const char *);
    d16c_String_8020bb54(const d16c_String_8020bb54 &o) {
        d16c_string_init_8020c5c0(this);
        text = o.text;
        ++*d16c_string_header_80341884(this);
    }
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
    template <class W3dU> d16c_Ref(Ptr32<W3dU> w3d_p) : d16c_Ref((d16c_Object *)w3d_p.get()) {}
 d16c_Ref(d16c_Object *object) { value = object; if (object) object->vtable->retain(object); }
    ~d16c_Ref() { if (value) value->vtable->release(value); }
private:
    d16c_Ref(const d16c_Ref &);
};
struct d16c_Sink;
struct d16c_SinkVtable {
    Ptr32<void> unknown00[23];
    Ptr32<int (Ptr32<d16c_Sink>, Ptr32<void>, int)> attach;   // +92
};
struct d16c_Sink { Ptr32<d16c_SinkVtable> vtable; };
struct d16c_Team {
    unsigned char unknown000[240];
    int primary;                         // +240
    unsigned char unknown244[162];
    unsigned short code;                 // +406
    int secondary;                       // +408
    d16c_String_8020bb54 name;           // +412
};
struct d16c_Payload {
    unsigned char unknown000[28];
    Ptr32<void> owner;                         // +28
    Ptr32<d16c_Sink> sink;                     // +32
    unsigned char unknown036[160];
    int link;                            // +196
    Ptr32<void> primary;                       // +200
    Ptr32<void> secondary;                     // +204
};
struct d16c_Config { unsigned char unknown00[20]; int layer; };
extern "C" int d16c_handle_load_8015adf4(Ptr32<const d16c_String_8020bb54>, Ptr32<Ptr32<void>>, unsigned char);
extern "C" Ptr32<void> d16c_as_owner_80341584(Ptr32<void>);
extern "C" Ptr32<d16c_Team> d16c_owner_team_801797b4(Ptr32<void>);
extern "C" Ptr32<d16c_Object> d16c_service_forward_8020b680(Ptr32<void>);
extern "C" int d16c_manager_attach_80164514(Ptr32<void>, Ptr32<d16c_Object>, int);
extern "C" void d16c_label_create_801222cc(Ptr32<d16c_Object>, d16c_String_8020bb54, unsigned short, int, int);
extern const char d16c_null_text_8038b2a0[];   // "NULL"
extern unsigned char d16c_label_service_80410b08[];
extern Ptr32<void> d16c_manager_804b178c;
extern Ptr32<d16c_Config> d16c_config_804aaba4;

extern "C" void d16c_payload_attach_800e9b88(Ptr32<d16c_Payload> self) {
    Ptr32<d16c_Team> team = d16c_owner_team_801797b4(d16c_as_owner_80341584(self->owner));
    {
        d16c_String_8020bb54 name(d16c_null_text_8038b2a0);
        d16c_handle_load_8015adf4(&name, &self->primary, 255);
    }
    {
        d16c_String_8020bb54 name(d16c_null_text_8038b2a0);
        d16c_handle_load_8015adf4(&name, &self->secondary, 255);
    }
    int first = self->sink->vtable->attach(self->sink, self->primary, team->primary);
    int second = self->sink->vtable->attach(self->sink, self->secondary, team->secondary);
    if (first >= 0 && second >= 0) {
        d16c_Ref label(d16c_service_forward_8020b680(d16c_label_service_80410b08));
        self->link = d16c_manager_attach_80164514(d16c_manager_804b178c, label.value, d16c_config_804aaba4->layer);
        d16c_label_create_801222cc(label.value, team->name, team->code, 0, 1);
    }
}


