#include "w3d_ptr.h"
#line 1 "d32a_aim_arrow_start_80028708.cpp"
// GWMP8P rev0 0x80028708. Starts the aiming arrow: loads HUD.AimArrow and
// HUD.AimBase, reads ActiveWormIndex and eight HUD.AngleMeter settings,
// places the arrow at the off-screen position plus its arrow offset, places
// the base, scales the arrow from its setting and the base from
// Angle.Power.DaveThang.Scale, then subscribes two message handlers. Names
// are inferred from the original strings and instructions.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
};
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
    Ptr32<void> unknown20[14];
    Ptr32<int (Ptr32<Object>, const Vec3 &, int)> moveTo;  /* +76 */
    Ptr32<void> unknown80;
    Ptr32<int (Ptr32<Object>, const Vec3 &, int)> setScale;  /* +84 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() {}
private:
    Handle(const Handle &);
};
struct String;
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String();
};
struct PropertyKey { Ptr32<const char> name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Self {
    char unknown0[40];
    Ptr32<Object> handle40;  /* +40 */
    Ptr32<Object> handle44;  /* +44 */
    Vec3 position;  /* +48 */
    char slot60[4];            /* +60 */
    char slot64[4];            /* +64 */
    char unknown68[8];
    float offScreenX;  /* +76 */
    Ptr32<Object> activeWormIndex;  /* +80 */
    char unknown84[4];
    Ptr32<Object> hUDAngleMeterOffScreenX;  /* +88 */
    Ptr32<Object> hUDAngleMeterOnScreenX;  /* +92 */
    Ptr32<Object> hUDAngleMeterRotXOffset;  /* +96 */
    Ptr32<Object> hUDAngleMeterScaleArrowX;  /* +100 */
    Ptr32<Object> hUDAngleMeterScreenY;  /* +104 */
    Ptr32<Object> hUDAngleMeterSlideTime;  /* +108 */
    Ptr32<Object> hUDAngleMeterArrowOffset;  /* +112 */
    Ptr32<Object> hUDAngleMeterInvert;  /* +116 */
};
extern "C" float w3d_object_float_80178df0(Ptr32<Object>);
extern "C" Ptr32<Vec3> w3d_object_vector_80178ec4(Ptr32<Object>);
extern "C" int w3d_vector_property_800fc2f0(Ptr32<PropertyKey>, Ptr32<Vec3>);
extern float w3d_constant_8036ce9c[], w3d_constant_8036cea0[], w3d_constant_8036cea4[];
extern "C" char w3d_string_8036ce80[]; /* "Angle.Power" */
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<Ptr32<Object>>);
extern "C" Ptr32<Object> w3d_identity_803426b4(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_identity_80342a74(Ptr32<Object>);
extern "C" Ptr32<Object> w3d_identity_80342fa4(Ptr32<Object>);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_subscribe_80162024(Ptr32<Self>, const unsigned short &, Ptr32<void>);
extern MessageCache w3d_message_804acbec, w3d_message_804acbf4;
extern "C" int w3d_handle_load_8015adf4(Ptr32<const String>, Ptr32<Ptr32<Object>>, unsigned char);
extern "C" void w3d_string_finish_8020c5c4(Ptr32<String>);
extern "C" void w3d_string_release_80341588(Ptr32<String>);
extern "C" char w3d_string_8036cd7c[]; /* "HUD.AimArrow" */
extern "C" char w3d_string_8036cd8c[]; /* "HUD.AimBase" */
extern "C" char w3d_string_8036cd98[]; /* "ActiveWormIndex" */
extern "C" char w3d_string_8036cda8[]; /* "HUD.AngleMeter.OffScreenX" */
extern "C" char w3d_string_8036cdc4[]; /* "HUD.AngleMeter.OnScreenX" */
extern "C" char w3d_string_8036cde0[]; /* "HUD.AngleMeter.ScreenY" */
extern "C" char w3d_string_8036cdf8[]; /* "HUD.AngleMeter.RotXOffset" */
extern "C" char w3d_string_8036ce14[]; /* "HUD.AngleMeter.ScaleArrowX" */
extern "C" char w3d_string_8036ce30[]; /* "HUD.AngleMeter.SlideTime" */
extern "C" char w3d_string_8036ce4c[]; /* "HUD.AngleMeter.ArrowOffset" */
extern "C" char w3d_string_8036ce68[]; /* "HUD.AngleMeter.Invert" */

template <Ptr32<Object> (*Cast)(Ptr32<Object>)>
inline void LoadResource(Ptr32<const char> name, Ptr32<Object> &slot)
{
    Handle h;
    PropertyKey key;
    key.name = name;
    h.value = 0;
    w3d_resource_property_800fc1b0(&key, &h.value);
    Ptr32<Object> object = Cast(h.value);
    if (object) object->vtable->retain(object);
    if (slot) slot->vtable->release(slot);
    slot = object;
    if (h.value) h.value->vtable->release(h.value);
}

inline String::~String() { w3d_string_finish_8020c5c4(this); w3d_string_release_80341588(this); }

inline void GetNamed(const String &t, Ptr32<Object> &slot) { w3d_handle_load_8015adf4(&t, &slot, 255); }
extern "C" void w3d_d32a_aim_arrow_start_80028708(Ptr32<Self> self)
{
    GetNamed(String(w3d_string_8036cd7c), self->handle40);
    GetNamed(String(w3d_string_8036cd8c), self->handle44);
    { PropertyKey key; key.name = w3d_string_8036cd98; w3d_resource_property_800fc1b0(&key, &self->activeWormIndex); }
    {
    LoadResource<w3d_identity_80342a74>(w3d_string_8036cda8, self->hUDAngleMeterOffScreenX);
    LoadResource<w3d_identity_80342a74>(w3d_string_8036cdc4, self->hUDAngleMeterOnScreenX);
    LoadResource<w3d_identity_80342a74>(w3d_string_8036cde0, self->hUDAngleMeterScreenY);
    LoadResource<w3d_identity_80342a74>(w3d_string_8036cdf8, self->hUDAngleMeterRotXOffset);
    LoadResource<w3d_identity_80342a74>(w3d_string_8036ce14, self->hUDAngleMeterScaleArrowX);
    LoadResource<w3d_identity_803426b4>(w3d_string_8036ce30, self->hUDAngleMeterSlideTime);
    LoadResource<w3d_identity_80342fa4>(w3d_string_8036ce4c, self->hUDAngleMeterArrowOffset);
    LoadResource<w3d_identity_803426b4>(w3d_string_8036ce68, self->hUDAngleMeterInvert);
    }
    self->offScreenX = w3d_object_float_80178df0(self->hUDAngleMeterOffScreenX);
    self->position.Set(self->offScreenX, w3d_object_float_80178df0(self->hUDAngleMeterScreenY), 0.0f);
    {
        Ptr32<Object> arrow = self->handle40;
        arrow->vtable->moveTo(arrow, self->position + *w3d_object_vector_80178ec4(self->hUDAngleMeterArrowOffset), 0);
    }
    self->handle44->vtable->moveTo(self->handle44, self->position, 0);
    float scaleX = w3d_object_float_80178df0(self->hUDAngleMeterScaleArrowX);
    Vec3 scale(scaleX, scaleX * 0.5f, 1.0f);
    self->handle40->vtable->setScale(self->handle40, scale, 0);
    {
        Vec3 power;
        Ptr32<Vec3> p = &power;
        PropertyKey key;
        key.name = w3d_string_8036ce80;
        w3d_vector_property_800fc2f0(&key, p);
        self->handle44->vtable->setScale(self->handle44, *p, 0);
    }
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acbec, 1), self->slot60);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804acbf4, 1), self->slot64);
}


