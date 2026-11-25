#include "w3d_ptr.h"
#line 1 "k10a_team_flags_apply_80064dcc.cpp"
// Appears to apply a team-flags value given as text: it parses the number, binds
// the "FE.TeamFlags" property name to the element's handle slot, configures the
// bound object, stores the flag byte and then places the object at a vector made
// from two limits read from its sub-objects.
extern "C" int atoi(Ptr32<const char> text);
extern "C" Ptr32<void> w3d_string_from_text(Ptr32<void> string, Ptr32<const char> text);
extern "C" void w3d_string_base_finish(Ptr32<void> string);
extern "C" void w3d_string_release(Ptr32<void> string);

struct K10aString
{
    Ptr32<char> text;
    unsigned int storage;
    K10aString() {}
    ~K10aString() { w3d_string_base_finish(this); w3d_string_release(this); }
};

struct K10aVec3
{
    float x, y, z;
    K10aVec3(float v) { x = v; y = v; z = v; }
};

struct K10aBound;
struct K10aBoundTable
{
    Ptr32<void (void)> slots0[19];
    Ptr32<void (Ptr32<K10aBound>, Ptr32<void>, int)> configure;   // +76
    Ptr32<void (void)> slot20;
    Ptr32<void (Ptr32<K10aBound>, Ptr32<K10aVec3>, int)> place;   // +84
};
struct K10aBound
{
    Ptr32<K10aBoundTable> vtable;
};

struct K10aElement
{
    char pad0[32];
    Ptr32<K10aBound> bound;            // +32
    char pad36[24];
    char settings[1];            // +60
    char pad61[67];
    Ptr32<void> limitX;                // +128
    Ptr32<void> limitY;                // +132
};

extern "C" Ptr32<void> w3d_handle_set_name(Ptr32<K10aString> name, Ptr32<void> slot, unsigned int flags);
extern "C" Ptr32<K10aBound> w3d_empty_8034357c(Ptr32<K10aBound> bound);
extern "C" int w3d_s20_store_byte_value_80173f88(Ptr32<K10aBound> bound, Ptr32<unsigned char> value);
extern "C" float w3d_auto_80178df0(Ptr32<void> limit);

extern "C" void w3d_k10a_team_flags_apply_80064dcc(Ptr32<K10aElement> self, Ptr32<const char> text)
{
    if (text && *text)
    {
        int flags = atoi(text);
        {
            K10aString name;
            w3d_string_from_text(&name, "FE.TeamFlags");
            w3d_handle_set_name(&name, &self->bound, 255);
        }
        self->bound->vtable->configure(self->bound, self->settings, 0);
        Ptr32<K10aBound> target = w3d_empty_8034357c(self->bound);
        unsigned char value = flags;
        w3d_s20_store_byte_value_80173f88(target, &value);
        K10aVec3 position(1.0f);
        position.x = w3d_auto_80178df0(self->limitX);
        position.y = w3d_auto_80178df0(self->limitY);
        self->bound->vtable->place(self->bound, &position, 0);
    }
}


