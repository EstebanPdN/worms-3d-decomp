#include "w3d_ptr.h"
#line 1 "d20b_grave_load_80097980.cpp"
// d20b: 0x80097980 (732 bytes). Load a grave marker's mesh for its style
// (+40): load the style's "Grave.*" resource into the retained mesh slot (+28)
// and pick its "main*" clip (the eye style also reads the ActiveWormIndex
// setting into +60), play the clip once into +36 (rate 1, start 0), check the
// clip's control unless the style is the eye, replace the light member (+68)
// with a new member of the mesh's kind, hand it a reference to the mesh and
// set its scale to 0.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return. The member attach call takes the reference
// by value (the callee releases it), so the caller only copy-retains it; the
// copy reuses the freed string slot because both classes have copy
// constructors. The float literals form this function's constant pool at
// 0x8037f6fc.
extern "C" void d20b_string_init_8020c5c0(Ptr32<void>);
extern "C" Ptr32<unsigned short> d20b_string_header_80341884(Ptr32<void>);
// Shared engine string; constructor and release are out of line.
struct d20b_String_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> d20b_String_8020bb54(Ptr32<W3dU> w3d_p) : d20b_String_8020bb54((const char *)w3d_p.get()) {}
 d20b_String_8020bb54(const char *);
    d20b_String_8020bb54(const d20b_String_8020bb54 &o) {
        d20b_string_init_8020c5c0(this);
        text = o.text;
        ++*d20b_string_header_80341884(this);
    }
    ~d20b_String_8020bb54();
};
extern "C" void d20b_string_finish_8020c5c4(Ptr32<d20b_String_8020bb54>);
extern "C" void d20b_string_release_80341588(Ptr32<d20b_String_8020bb54>);
inline d20b_String_8020bb54::~d20b_String_8020bb54() {
    d20b_string_finish_8020c5c4(this);
    d20b_string_release_80341588(this);
}
struct d20b_Object;
struct d20b_ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<d20b_Object>)> retain;       // +12
    Ptr32<void (Ptr32<d20b_Object>)> release;      // +16
    Ptr32<void> unknown20[10];
    Ptr32<int (Ptr32<d20b_Object>)> kind;          // +60
};
struct d20b_Object { Ptr32<d20b_ObjectVtable> vtable; };
// Retaining reference (one pointer), passed by value: the callee releases it.
struct d20b_Ref {
    Ptr32<d20b_Object> value;
    d20b_Ref(const d20b_Ref &o) { value = o.value; if (value) value->vtable->retain(value); }
    ~d20b_Ref() { if (value) value->vtable->release(value); }
};
struct d20b_Member;
struct d20b_Heap { int opaque; };
struct d20b_Grave {
    unsigned char unknown00[28];
    d20b_Ref mesh;                       // +28
    unsigned char unknown32[4];
    unsigned clip;                       // +36
    unsigned char style;                 // +40
    unsigned char unknown41[19];
    int worm_index;                      // +60
    unsigned char unknown64[4];
    Ptr32<d20b_Member> member;                 // +68
};
extern "C" int d20b_handle_load_8015adf4(Ptr32<const d20b_String_8020bb54>, Ptr32<Ptr32<d20b_Object>>, unsigned char);
extern "C" int d20b_setting_read_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
extern "C" Ptr32<void> d20b_as_mesh_80343584(Ptr32<d20b_Object>);
extern "C" int d20b_play_clip_80181640(Ptr32<void>, Ptr32<const char>, Ptr32<unsigned int>, float, float, float, int);
extern "C" int d20b_check_control_8018179c(Ptr32<void>, unsigned, int);
extern "C" Ptr32<void> d20b_heap_allocate_802098d8(Ptr32<d20b_Heap>, unsigned);
extern "C" Ptr32<d20b_Member> d20b_member_init_kind_8012656c(Ptr32<void>, int);
// El llamado destruye el argumento (GCC 2.95): esta copia no lleva destructor.
struct d20b_RefArg {
    Ptr32<d20b_Object> value;
    d20b_RefArg(const d20b_Ref &o) { value = o.value; if (value) value->vtable->retain(value); }
    d20b_RefArg(const d20b_RefArg &);
};
extern "C" void d20b_member_attach_80126610(Ptr32<d20b_Member>, d20b_RefArg);
extern "C" void d20b_member_set_scale_80126688(Ptr32<d20b_Member>, float);
extern d20b_Heap d20b_member_heap_804af5bc;
extern const char d20b_grave_eye_8037f654[];        // "Grave.Eye"
extern const char d20b_main_eye_8037f660[];         // "mainEye"
extern const char d20b_active_worm_8037f668[];      // "ActiveWormIndex"
extern const char d20b_grave_pyramid_8037f678[];    // "Grave.Pyramid"
extern const char d20b_main_pyramid_8037f688[];     // "mainPyramid"
extern const char d20b_grave_flame_8037f694[];      // "Grave.Flame"
extern const char d20b_main_flame_8037f6a0[];       // "mainFlame"
extern const char d20b_grave_obelisk_8037f6ac[];    // "Grave.Obelisk"
extern const char d20b_main_obelisk_8037f6bc[];     // "mainObelisk"
extern const char d20b_grave_brown_8037f6c8[];      // "Grave.Brown"
extern const char d20b_main_brown_8037f6d4[];       // "mainBrown"
extern const char d20b_grave_marble_8037f6e0[];     // "Grave.Marble"
extern const char d20b_main_marble_8037f6f0[];      // "mainMarble"

extern "C" void d20b_grave_load_80097980(Ptr32<d20b_Grave> self) {
    Ptr32<const char> clip = 0;
    switch (self->style) {
    case 2: {
        {
            d20b_String_8020bb54 name(d20b_grave_eye_8037f654);
            d20b_handle_load_8015adf4(&name, &self->mesh.value, 255);
        }
        clip = d20b_main_eye_8037f660;
        Ptr32<const char> setting = d20b_active_worm_8037f668;
        d20b_setting_read_800fc1f0(&setting, &self->worm_index);
        break;
    }
    case 4: {
        {
            d20b_String_8020bb54 name(d20b_grave_pyramid_8037f678);
            d20b_handle_load_8015adf4(&name, &self->mesh.value, 255);
        }
        clip = d20b_main_pyramid_8037f688;
        break;
    }
    case 1: {
        {
            d20b_String_8020bb54 name(d20b_grave_flame_8037f694);
            d20b_handle_load_8015adf4(&name, &self->mesh.value, 255);
        }
        clip = d20b_main_flame_8037f6a0;
        break;
    }
    case 5: {
        {
            d20b_String_8020bb54 name(d20b_grave_obelisk_8037f6ac);
            d20b_handle_load_8015adf4(&name, &self->mesh.value, 255);
        }
        clip = d20b_main_obelisk_8037f6bc;
        break;
    }
    case 3: {
        {
            d20b_String_8020bb54 name(d20b_grave_brown_8037f6c8);
            d20b_handle_load_8015adf4(&name, &self->mesh.value, 255);
        }
        clip = d20b_main_brown_8037f6d4;
        break;
    }
    case 0: {
        {
            d20b_String_8020bb54 name(d20b_grave_marble_8037f6e0);
            d20b_handle_load_8015adf4(&name, &self->mesh.value, 255);
        }
        clip = d20b_main_marble_8037f6f0;
        break;
    }
    }
    Ptr32<void> mesh = d20b_as_mesh_80343584(self->mesh.value);
    d20b_play_clip_80181640(mesh, clip, &self->clip, 1.0f, 0.0f, 0.0f, 1);
    if (self->style != 2) d20b_check_control_8018179c(mesh, self->clip, 1);
    self->member = d20b_member_init_kind_8012656c(d20b_heap_allocate_802098d8(&d20b_member_heap_804af5bc, 4), self->mesh.value->vtable->kind(self->mesh.value));
    d20b_member_attach_80126610(self->member, self->mesh);
    d20b_member_set_scale_80126688(self->member, 0.0f);
}


