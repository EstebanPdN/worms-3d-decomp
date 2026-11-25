#include "w3d_ptr.h"
#line 1 "d19c_sky_load_80104e90.cpp"
// d19c: 0x80104e90 (724 bytes). Load the sky box: read the "Land.SkyBoxResource"
// setting (the sky name), load that layer node into +28 (load mode 255); if the
// node has a "Sun" bone, copy its translation to the shared sun position and
// set +68. Hand the node's owner value to the sky (0x80106300), give it unit
// scale and the shared sky layer position; load the layer again into +32 (load
// mode 6) as the Y-mirrored copy. With a sun, find the sky in the 13-entry
// lighting table and set that kind on the light service object before adding
// it to the light scene. Then run 0x80105164, the cloud and moon loaders, and
// store the index of the sky in the three-entry cloud speed table at +64.
// 0x8015adf4 and the settings reader 0x800fc2b0 forward virtual results and are
// declared with status returns (void reorders the &key/&value arguments).
// Shared engine string; constructor and release are out of line.
struct d19c_String_8020bb54 {
    Ptr32<char> text;
    template <class W3dU> d19c_String_8020bb54(Ptr32<W3dU> w3d_p) : d19c_String_8020bb54((const char *)w3d_p.get()) {}
 d19c_String_8020bb54(const char *);
    d19c_String_8020bb54(const d19c_String_8020bb54 &);
    ~d19c_String_8020bb54();
};
extern "C" void d19c_string_finish_8020c5c4(Ptr32<d19c_String_8020bb54>);
extern "C" void d19c_string_release_80341588(Ptr32<d19c_String_8020bb54>);
inline d19c_String_8020bb54::~d19c_String_8020bb54() {
    d19c_string_finish_8020c5c4(this);
    d19c_string_release_80341588(this);
}
struct d19c_Node;
struct d19c_Vec3 { float x, y, z; };
struct d19c_NodeVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<d19c_Node>)> retain;         // +12
    Ptr32<void (Ptr32<d19c_Node>)> release;        // +16
    Ptr32<void> unknown20[14];
    Ptr32<int (Ptr32<d19c_Node>, Ptr32<const d19c_Vec3>, int)> set_position;   // +76
    Ptr32<void> unknown80;
    Ptr32<int (Ptr32<d19c_Node>, Ptr32<const d19c_Vec3>, int)> set_scale;      // +84
};
struct d19c_Node {
    Ptr32<d19c_NodeVtable> vtable;
    unsigned char unknown04[56];
    unsigned char sky_kind;              // +60 (light objects: sky lighting kind)
};
struct d19c_Point3 { float x, y, z; };
extern "C" void d19c_point_init_80343740(Ptr32<d19c_Point3>);
struct d19c_Matrix {
    d19c_Point3 axis_x, axis_y, axis_z, translation;
    d19c_Matrix() { d19c_point_init_80343740(&translation); }
};
struct d19c_SkyFlag { Ptr32<const char> sky; unsigned char kind; };
struct d19c_SkyPair { Ptr32<const char> sky; Ptr32<const char> setting; };
struct d19c_Service;
struct d19c_Holder {
    Ptr32<d19c_Node> value;
    template <class W3dU> d19c_Holder(Ptr32<W3dU> w3d_p) : d19c_Holder((d19c_Node *)w3d_p.get()) {}
 d19c_Holder(d19c_Node *object) : value(object) { if (object) object->vtable->retain(object); }
    d19c_Holder(const d19c_Holder &o);
    ~d19c_Holder() { if (value) value->vtable->release(value); }
};
struct d19c_Sky {
    unsigned char unknown00[20];
    int scene;                           // +20
    unsigned char unknown24[4];
    Ptr32<d19c_Node> box;                      // +28
    Ptr32<d19c_Node> box_mirror;               // +32
    unsigned char unknown36[28];
    unsigned cloud_speed;                // +64
    int has_sun;                         // +68
};
extern "C" int d19c_settings_read_800fc2b0(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<const char>>);
extern "C" int d19c_handle_load_8015adf4(Ptr32<const d19c_String_8020bb54>, Ptr32<Ptr32<d19c_Node>>, unsigned char);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<d19c_Node> d19c_as_node_80343584(Ptr32<d19c_Node>);
extern "C" int d19c_find_bone_80181e3c(Ptr32<d19c_Node>, Ptr32<const char>, Ptr32<d19c_Matrix>);
extern "C" int d19c_owner_value_80182150(Ptr32<d19c_Node>);
extern "C" int d19c_sky_bind_clouds_80106300(Ptr32<d19c_Sky>, Ptr32<void>);
extern "C" Ptr32<d19c_Node> d19c_service_find_8020b680(Ptr32<d19c_Service>);
extern "C" int d19c_scene_add_light_80164514(Ptr32<void>, Ptr32<d19c_Node>, int);
extern "C" void d19c_sky_init_80105164(Ptr32<d19c_Sky>);
extern "C" void d19c_sky_clouds_load_8010562c(Ptr32<d19c_Sky>, Ptr32<const char>);
extern "C" void d19c_sky_moon_load_801058f0(Ptr32<d19c_Sky>, Ptr32<const char>);
extern d19c_Point3 d19c_sky_layer_position_8044b67c;
extern d19c_Point3 d19c_sun_position_8044b688;
extern d19c_SkyFlag d19c_sky_flags_80399a30[];
extern d19c_SkyPair d19c_sky_cloud_speeds_803fce40[];
extern d19c_Service d19c_light_service_8040f858;
extern Ptr32<void> d19c_light_scene_804b178c;

extern "C" void d19c_sky_load_80104e90(Ptr32<d19c_Sky> self) {
    d19c_Vec3 scale;
    Ptr32<d19c_Vec3> p = &scale;
    scale.x = 1.0f;
    p->y = 1.0f;
    p->z = 1.0f;
    d19c_Vec3 position;
    Ptr32<const d19c_Point3> from = &d19c_sky_layer_position_8044b67c;
    position.x = from->x;
    position.y = from->y;
    position.z = from->z;
    int has_sun = 0;
    self->has_sun = has_sun;
    Ptr32<const char> key = "Land.SkyBoxResource";
    Ptr32<const char> sky;
    d19c_settings_read_800fc2b0(&key, &sky);
    self->cloud_speed = 0;
    {
        d19c_String_8020bb54 name(sky);
        d19c_handle_load_8015adf4(&name, &self->box, 255);
    }
    {
        d19c_Matrix transform;
        Ptr32<d19c_Node> node = d19c_as_node_80343584(self->box);
        if (node && d19c_find_bone_80181e3c(node, "Sun", &transform) >= 0) {
            d19c_sun_position_8044b688 = transform.translation;
            has_sun = 1;
            self->has_sun = has_sun;
        }
    }
    d19c_sky_bind_clouds_80106300(self, (Ptr32<void>)w3d::G((d19c_owner_value_80182150(self->box))));
    self->box->vtable->set_scale(self->box, &scale, 0);
    self->box->vtable->set_position(self->box, &position, 0);
    {
        d19c_String_8020bb54 name(sky);
        d19c_handle_load_8015adf4(&name, &self->box_mirror, 6);
    }
    scale.y = -scale.y;
    position.y = -position.y;
    self->box_mirror->vtable->set_scale(self->box_mirror, &scale, 0);
    self->box_mirror->vtable->set_position(self->box_mirror, &position, 0);
    if (has_sun) {
        for (unsigned i = 0; i <= 12; i++) {
            if (strcmp(d19c_sky_flags_80399a30[i].sky, sky) == 0) {
                d19c_Holder light(d19c_service_find_8020b680(&d19c_light_service_8040f858));
                light.value->sky_kind = d19c_sky_flags_80399a30[i].kind;
                d19c_scene_add_light_80164514(d19c_light_scene_804b178c, light.value, self->scene);
                break;
            }
        }
    }
    d19c_sky_init_80105164(self);
    d19c_sky_clouds_load_8010562c(self, sky);
    d19c_sky_moon_load_801058f0(self, sky);
    for (unsigned i = 0; i <= 2; i++) {
        if (strcmp(sky, d19c_sky_cloud_speeds_803fce40[i].sky) == 0) {
            self->cloud_speed = i;
            break;
        }
    }
}


