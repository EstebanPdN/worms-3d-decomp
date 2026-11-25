#include "w3d_ptr.h"
#line 1 "d24i_hud_text_start_8011ae58.cpp"
// d24i: 0x8011ae58 (232 bytes). Start a HUD text element: virtual +52 on itself,
// resolves its text (+28, 0x80343580) and applies a style record through the
// text's virtual +84: scale 5.0f on all axes, white colour, opaque black shadow;
// then 0x8011adf8 with the small-data settings, virtual +48 with state 2, and a
// subscription to the cached message 0x804af3a8 with the object's +48 slot.
struct d24i_Colour {
    // Stored as signed bytes: the original materializes 0xff as -1.
    signed char r, g, b, a;
};
struct d24i_TextStyle {
    float scale[3];
    float unknown0c;
    d24i_Colour colour;                  // +16
    d24i_Colour shadow;                  // +20
};
struct d24i_Text;
struct d24i_TextVtable {
    Ptr32<void> unknown00[21];
    Ptr32<void (Ptr32<d24i_Text>, Ptr32<d24i_TextStyle>, int)> apply;  // +84
};
struct d24i_Text { Ptr32<d24i_TextVtable> vtable; };
struct d24i_Hud;
struct d24i_HudVtable {
    Ptr32<void> unknown00[12];
    Ptr32<void (Ptr32<d24i_Hud>, int)> set_state;  // +48
    Ptr32<void (Ptr32<d24i_Hud>)> begin;           // +52
};
struct d24i_MessageId { unsigned short value; d24i_MessageId() {} };
struct d24i_Hud {
    Ptr32<d24i_HudVtable> vtable;
    unsigned char unknown04[24];
    Ptr32<d24i_Text> text;                     // +28
    unsigned char unknown20[16];
    unsigned subscription;               // +48
};
extern "C" Ptr32<d24i_Text> d24i_as_text_80343580(Ptr32<d24i_Text>);
extern "C" void d24i_hud_properties_8011adf8(Ptr32<d24i_Hud>, Ptr32<void>, Ptr32<void>);
extern "C" unsigned short d24i_cached_id_8015f5a0(Ptr32<void>, int);
extern "C" int d24i_subscribe_80162024(Ptr32<d24i_Hud>, Ptr32<d24i_MessageId>, Ptr32<unsigned int>);
extern const float d24i_five_8039ae84[];
extern unsigned int d24i_setting_804af3b0, d24i_setting_804af3b4, d24i_message_804af3a8;

extern "C" void d24i_hud_text_start_8011ae58(Ptr32<d24i_Hud> self) {
    self->vtable->begin(self);
    Ptr32<d24i_Text> text = d24i_as_text_80343580(self->text);
    d24i_TextStyle style;
    float five = d24i_five_8039ae84[0];
    style.scale[0] = five;
    Ptr32<float> scale = style.scale;
    scale[1] = five;
    scale[2] = five;
    style.colour.r = -1;
    Ptr32<d24i_Colour> colour = &style.colour;
    colour->g = -1;
    colour->b = -1;
    colour->a = -1;
    style.shadow.r = 0;
    Ptr32<d24i_Colour> shadow = &style.shadow;
    shadow->g = 0;
    shadow->b = 0;
    shadow->a = -1;
    text->vtable->apply(text, &style, 0);
    d24i_hud_properties_8011adf8(self, &d24i_setting_804af3b0, &d24i_setting_804af3b4);
    self->vtable->set_state(self, 2);
    d24i_MessageId id;
    id.value = d24i_cached_id_8015f5a0(&d24i_message_804af3a8, 1);
    d24i_subscribe_80162024(self, &id, &self->subscription);
}


