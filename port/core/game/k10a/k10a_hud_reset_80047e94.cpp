#include "w3d_ptr.h"
#line 1 "k10a_hud_reset_80047e94.cpp"
// Appears to reset a HUD element: looks up its target object, publishes the
// element's color (scaled from floats to bytes) through the target's HUD
// properties, clears the target's text and sets its anchor, then zeroes two
// timing words and copies a default offset into the element.
// Quantized byte conversion requires the original -mfast-cast option.
struct K10aVec3
{
    float x, y, z;
    K10aVec3(float a, float b, float c) { x = a; y = b; z = c; }
};

struct K10aDefaultOffset
{
    int x, y, z;
};

extern const float w3d_f32_803763bc[];   // 255.0f

struct K10aColor
{
    char r, g, b, a;
    K10aColor() { r = -1; g = -1; b = -1; a = -1; }
    void set(Ptr32<const float> p)
    {
        r = (unsigned char)(p[0] * w3d_f32_803763bc[0]);
        g = (unsigned char)(p[1] * w3d_f32_803763bc[0]);
        b = (unsigned char)(p[2] * w3d_f32_803763bc[0]);
        a = (unsigned char)(p[3] * w3d_f32_803763bc[0]);
    }
};

struct K10aTarget;
struct K10aTargetTable
{
    Ptr32<void (void)> slots0[10];
    Ptr32<void (Ptr32<K10aTarget>, Ptr32<const void>)> set_anchor;   // +40
    Ptr32<void (Ptr32<K10aTarget>, Ptr32<const char>)> set_text;       // +44
};
struct K10aTarget
{
    Ptr32<K10aTargetTable> vtable;
};

struct K10aElement
{
    char pad0[32];
    float rgba[4];               // +32
    char pad48[16];
    unsigned int state;          // +64
    int handle;                  // +68
    char pad72[16];
    int pending;                 // +88
    char pad92[20];
    K10aDefaultOffset offset;    // +112
};

extern float w3d_f32_804aa980;
extern int w3d_text_804af3b4;
extern const char w3d_str_80374dd8[];
extern K10aDefaultOffset w3d_default_offset_80427468;
extern "C" Ptr32<K10aTarget> w3d_s20_lookup_handle_object_80164fc8(int handle);
extern "C" void w3d_hud_properties_8011adf8(Ptr32<K10aTarget> target, Ptr32<const K10aColor> color, Ptr32<const void> key);

extern "C" void w3d_k10a_hud_reset_80047e94(Ptr32<K10aElement> self)
{
    Ptr32<K10aTarget> target = w3d_s20_lookup_handle_object_80164fc8(self->handle);
    // The original also builds an unused origin vector from this global.
    K10aVec3 origin(w3d_f32_804aa980, w3d_f32_804aa980, w3d_f32_804aa980);
    K10aColor color;
    color.set(self->rgba);
    w3d_hud_properties_8011adf8(target, &color, &w3d_text_804af3b4);
    target->vtable->set_text(target, w3d_str_80374dd8);
    target->vtable->set_anchor(target, &w3d_default_offset_80427468);
    self->state = 0;
    self->pending = 0;
    self->offset = w3d_default_offset_80427468;
}


