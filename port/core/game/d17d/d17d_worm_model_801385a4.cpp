#include "w3d_ptr.h"
#line 1 "d17d_worm_model_801385a4.cpp"
// d17d: 0x801385a4 (808 bytes). Refresh a worm graphic's model for the worm's
// current type: store the type as the graphic mode (+684); for detached modes
// release the actor (0x8013e458) or do nothing; otherwise look the type up in
// the resource table 0x803eb63c. When the resource names a model, load it into
// a handle (0x8015adf4), keep its mesh as the attachment (+164, retained),
// reset the graphic mesh scale to (1, 1, 1) (virtual +84), attach the model
// (virtual +92, attachment id 0x804ab328 or 0x804ab32c for mode 11) and pick
// the resource value +596 for "Prod" kinds, +600 otherwise. Modes 5 and 43 run
// their enter hooks; a non-empty idle animation is played and checked.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return. The resource lookup writes through an out
// parameter; the inline wrapper keeps its result in a register.
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void d17d_string_init_8020c5c0(Ptr32<void>);
extern "C" Ptr32<unsigned short> d17d_string_header_80341884(Ptr32<void>);
// Shared text pointer as stored in resource records.
struct d17d_SharedText { Ptr32<char> text; };
// Shared engine string; constructor and release are out of line.
struct d17d_String {
 d17d_String(const d17d_String &);
    Ptr32<char> text;
    template <class W3dU> d17d_String(Ptr32<W3dU> w3d_p) : d17d_String((const char *)w3d_p.get()) {}
 d17d_String(const char *);
    d17d_String(const d17d_SharedText &o) {
        d17d_string_init_8020c5c0(this);
        text = o.text;
        ++*d17d_string_header_80341884(this);
    }
    ~d17d_String();
};
extern "C" void d17d_string_finish_8020c5c4(Ptr32<d17d_String>);
extern "C" void d17d_string_release_80341588(Ptr32<d17d_String>);
inline d17d_String::~d17d_String() {
    d17d_string_finish_8020c5c4(this);
    d17d_string_release_80341588(this);
}
inline bool d17d_same(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) == 0; }
inline bool d17d_differs(Ptr32<const char> a, Ptr32<const char> b) { return strcmp(a, b) != 0; }

struct d17d_Object;
struct d17d_Object { Ptr32<Ptr32<void>> vtable; };
struct d17d_Vec3 {
    float x, y, z;
    d17d_Vec3(float ax, float ay, float az) { x = ax; y = ay; z = az; }
};
// Retaining reference (one pointer, not copyable).
struct d17d_Ref {
    Ptr32<d17d_Object> value;
    template <class W3dU> d17d_Ref(Ptr32<W3dU> w3d_p) : d17d_Ref((d17d_Object *)w3d_p.get()) {}
 d17d_Ref(d17d_Object *object) { value = object; if (object) ((Ptr32<void (Ptr32<d17d_Object>)>)object->vtable[3])(object); }
    ~d17d_Ref() { if (value) ((Ptr32<void (Ptr32<d17d_Object>)>)value->vtable[4])(value); }
private:
    d17d_Ref(const d17d_Ref &);
};
// Retaining member pointer.
struct d17d_Ptr {
    Ptr32<d17d_Object> value;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((d17d_Object *)w3d_p.get()); }
 void operator=(d17d_Object *object) {
        if (object) ((Ptr32<void (Ptr32<d17d_Object>)>)object->vtable[3])(object);
        if (value) ((Ptr32<void (Ptr32<d17d_Object>)>)value->vtable[4])(value);
        value = object;
    }
};
struct d17d_Graphic {
    unsigned char unknown000[28];
    Ptr32<d17d_Object> mesh;                  // +28
    unsigned char unknown020[80];
    Ptr32<d17d_Object> worm;                  // +112
    unsigned char unknown074[48];
    d17d_Ptr attachment;                // +164
    unsigned char unknown0a8[320];
    int control;                        // +488
    unsigned char unknown1ec[104];
    int primaryValue;                   // +596
    int resourceValue;                  // +600
    unsigned char unknown25c[80];
    unsigned int mode;                  // +684
};
struct d17d_WormData { unsigned char unknown00[132]; int type; };
struct d17d_Resource {
    unsigned char unknown00[72];
    d17d_SharedText model;              // +72
    Ptr32<const char> animation;              // +76
    Ptr32<const char> idle;                   // +80
};
struct d17d_Name { Ptr32<char> text; };
extern "C" Ptr32<d17d_WormData> d17d_worm_data_800fc6dc(int);
extern "C" Ptr32<void> d17d_resource_lookup_800fc330(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<d17d_Resource>>);
extern "C" void s9_release_actor_inner_8013e458(Ptr32<void>);
extern "C" int d17d_handle_load_8015adf4(Ptr32<const d17d_String>, Ptr32<Ptr32<d17d_Object>>, unsigned char);
extern "C" Ptr32<d17d_Object> d17d_mesh_of_80343584(Ptr32<d17d_Object>);
extern "C" int d17d_mesh_set_resource_value_80182410(Ptr32<d17d_Object>, int);
extern "C" void d17d_mode_enter_8013ef98(Ptr32<d17d_Graphic>);
extern "C" void d17d_mode_enter_8013efe8(Ptr32<d17d_Graphic>);
extern "C" int d17d_play_named_801359ec(Ptr32<d17d_Graphic>, Ptr32<d17d_Object>, Ptr32<const char>, Ptr32<int>, float, float, float);
extern "C" int d17d_check_control_8018179c(Ptr32<d17d_Object>, int, int);
inline Ptr32<d17d_Resource> d17d_resource_for(Ptr32<Ptr32<const char>> key) {
    Ptr32<d17d_Resource> resource;
    d17d_resource_lookup_800fc330(key, &resource);
    return resource;
}
extern int d17d_attach_id_804ab328, d17d_attach_id_804ab32c;
extern Ptr32<const char> d17d_resource_table_803eb63c[];

extern "C" void d17d_worm_refresh_model_801385a4(Ptr32<d17d_Graphic> self) {
    int attachId = d17d_attach_id_804ab328;
    self->mode = d17d_worm_data_800fc6dc((int)w3d::H(self->worm))->type;
    d17d_String empty("");
    switch (self->mode) {
    case 13: case 16: case 39: case 40: case 44: case 45: case 51: case 52:
        s9_release_actor_inner_8013e458(self);
        return;
    case 11:
        attachId = d17d_attach_id_804ab32c;
        break;
    case 41: case 42: case 48:
        return;
    }
    Ptr32<d17d_Resource> resource = d17d_resource_for(&d17d_resource_table_803eb63c[self->mode]);
    d17d_String model(resource->model);
    if (d17d_differs(model.text, "")) {
        {
            d17d_Ref handle(0);
            d17d_handle_load_8015adf4(&model, &handle.value, 255);
            self->attachment = d17d_mesh_of_80343584(handle.value);
        }
        d17d_Vec3 scale(1.0f, 1.0f, 1.0f);
        ((Ptr32<void (Ptr32<d17d_Object>, Ptr32<d17d_Vec3>, int)>)self->mesh->vtable[21])(self->mesh, &scale, 0);
        ((Ptr32<void (Ptr32<d17d_Object>, Ptr32<d17d_Object>, int)>)self->mesh->vtable[23])(self->mesh, self->attachment.value, attachId);
        Ptr32<d17d_Object> info = ((Ptr32<Ptr32<d17d_Object> (Ptr32<d17d_Object>)>)self->attachment.value->vtable[16])(self->attachment.value);
        Ptr32<d17d_Name> kind = ((Ptr32<Ptr32<d17d_Name> (Ptr32<d17d_Object>)>)info->vtable[17])(info);
        if (d17d_same(kind->text, "Prod"))
            d17d_mesh_set_resource_value_80182410(self->attachment.value, self->primaryValue);
        else
            d17d_mesh_set_resource_value_80182410(self->attachment.value, self->resourceValue);
    }
    if (self->mode == 5) d17d_mode_enter_8013ef98(self);
    else if (self->mode == 43) d17d_mode_enter_8013efe8(self);
    if (d17d_differs(resource->idle, "")) {
        d17d_play_named_801359ec(self, self->attachment.value, resource->idle, &self->control, 1.0f, 0.0f, 0.0f);
        d17d_check_control_8018179c(self->attachment.value, self->control, 1);
    }
}


