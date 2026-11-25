#include "w3d_ptr.h"
#line 1 "d24b_land_render_start_800b983c.cpp"
/* Land render start (0x800b983c): subscribes the object (0x80162024) to three
 * cached messages with handler slots +28, +32 and +36, creates the 2796-byte
 * landscape renderer (0x802098d8, ctor 0x8008fb3c) into the global 0x804b183c,
 * clears +40, reads settings (key 0x804aace0 into 0x804ae548, "Land.Changed" into +44,
 * "Sun.LightVector"), passes the vector to the renderer's slot +20 (interface
 * at +2792), loads "Land.LightGradientResource" through a string name into
 * the retained +6208, hands its +60 member to the renderer's slot +28, releases
 * the resource and clears +6208 and the globals 0x804b180c and 0x804b17fc.
 * Field and type names are inferred from the original instructions; strings
 * and globals are external views of original data; the unit owns no data. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { x = o.x; y = o.y; z = o.z; }
};
struct PropertyKey { Ptr32<const char> name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *text);
    String(const String &);
    ~String();
};
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
inline String::~String() {
    w3d_string_finish_8020c5c4(this);
    w3d_string_release_80341588(this);
}
struct RendererInterface;
struct RendererVtable {
    Ptr32<void> unknown00[5];
    Ptr32<void (Ptr32<RendererInterface>, Ptr32<Vec3>)> setLight;  /* +20 */
    Ptr32<void> unknown24;
    Ptr32<void (Ptr32<RendererInterface>, int)> setGradient;  /* +28 */
};
struct RendererInterface {
    char unknown00[2792];
    Ptr32<RendererVtable> vtable;  /* +2792 */
};
struct Gradient { char unknown00[60]; int texture; /* +60 */ };
struct LandRender {
    char unknown00[28];
    char slot28[4], slot32[4], slot36[4];
    int unknown40;   /* +40 */
    char changed[4]; /* +44 */
    char unknown48[6160];
    Ptr32<Object> gradient; /* +6208 */
};
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<void>);
extern "C" int w3d_vector_property_800fc2f0(Ptr32<PropertyKey>, Ptr32<Vec3>);
extern "C" int w3d_string_property_800fc2b0(Ptr32<PropertyKey>, Ptr32<Ptr32<const char>>);
extern "C" Ptr32<Object> w3d_identity_8034357c(Ptr32<Object>);
extern "C" Ptr32<Gradient> w3d_lookup_optional_80174074(Ptr32<Object>);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_subscribe_80162024(Ptr32<LandRender>, const unsigned short &, Ptr32<void>);
extern "C" int w3d_handle_load_8015adf4(Ptr32<const String>, Ptr32<Ptr32<Object>>, unsigned char);
extern "C" Ptr32<void> w3d_heap_allocate_802098d8(Ptr32<void>, int);
extern "C" Ptr32<RendererInterface> w3d_renderer_ctor_8008fb3c(Ptr32<void>);
extern MessageCache w3d_message_804ae518, w3d_message_804ae520, w3d_message_804ae540;
extern int w3d_setting_804ae548;
extern char w3d_pool_804adde4[8];
extern PropertyKey w3d_property_804aace0;
extern Ptr32<RendererInterface> w3d_renderer_804b183c;
extern int w3d_global_804b180c, w3d_global_804b17fc;
extern "C" char w3d_string_8038285c[]; /* "Land.Changed" */
extern "C" char w3d_string_8038286c[]; /* "Sun.LightVector" */
extern "C" char w3d_string_8038287c[]; /* "Land.LightGradientResource" */

extern "C" void w3d_d24b_land_render_start_800b983c(Ptr32<LandRender> self)
{
    Vec3 light;
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae518, 1), self->slot28);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae520, 1), self->slot32);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ae540, 1), self->slot36);
    w3d_renderer_804b183c = w3d_renderer_ctor_8008fb3c(w3d_heap_allocate_802098d8(w3d_pool_804adde4, 2796));
    self->unknown40 = 0;
    w3d_resource_property_800fc1b0(&w3d_property_804aace0, &w3d_setting_804ae548);
    PropertyKey changed;
    changed.name = w3d_string_8038285c;
    w3d_resource_property_800fc1b0(&changed, self->changed);
    PropertyKey sun;
    sun.name = w3d_string_8038286c;
    w3d_vector_property_800fc2f0(&sun, &light);
    {
        Vec3 copy(light);
        w3d_renderer_804b183c->vtable->setLight(w3d_renderer_804b183c, &copy);
    }
    PropertyKey gradientKey;
    gradientKey.name = w3d_string_8038287c;
    Ptr32<const char> gradientName;
    w3d_string_property_800fc2b0(&gradientKey, &gradientName);
    {
        String name(gradientName);
        {
            Handle handle;
            handle.value = 0;
            w3d_handle_load_8015adf4(&name, &handle.value, 255);
            Ptr32<Object> object = w3d_identity_8034357c(handle.value);
            if (object) object->vtable->retain(object);
            if (self->gradient) self->gradient->vtable->release(self->gradient);
            self->gradient = object;
        }
    }
    Ptr32<Gradient> gradient = w3d_lookup_optional_80174074(self->gradient);
    w3d_renderer_804b183c->vtable->setGradient(w3d_renderer_804b183c, gradient->texture);
    if (self->gradient) self->gradient->vtable->release(self->gradient);
    self->gradient = 0;
    w3d_global_804b17fc = 0;
    w3d_global_804b180c = 0;
}


