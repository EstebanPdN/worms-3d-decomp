#include "w3d_ptr.h"
#line 1 "k10a_health_label_8004a988.cpp"
// Appears to rebuild a worm pot's health label: doubles the stored amount when
// the "WormPot" property has kind 1, then appends an optional "+", the amount
// and the localized "Text.Health" text to the label string.
struct K10aPropertyValue
{
    char pad0[48];
    int kind;                 // +48
};

struct K10aPropertyKey
{
    Ptr32<const char> name;
    Ptr32<K10aPropertyValue> value;
};

struct K10aTextKey
{
    Ptr32<const char> name;
    Ptr32<const char> text;
};

struct K10aPot
{
    char pad0[68];
    int amount;               // +68
    char pad72[76];
    char label[4];            // +148 (string object, partial view)
};

extern "C" void w3d_fn_8004b3f0(Ptr32<K10aPot> self, float scale);
extern "C" Ptr32<void> w3d_auto_800fc330(Ptr32<Ptr32<const char>> key, Ptr32<Ptr32<K10aPropertyValue>> value);
extern "C" int w3d_auto_800fc2b0(Ptr32<Ptr32<const char>> key, Ptr32<Ptr32<const char>> text);
extern "C" Ptr32<void> w3d_string_append(Ptr32<void> string, Ptr32<const char> text);
extern "C" int sprintf(Ptr32<char> out, Ptr32<const char> format, ...);

extern "C" void w3d_k10a_health_label_8004a988(Ptr32<K10aPot> self)
{
    char digits[64];
    Ptr32<const char> potName;
    Ptr32<K10aPropertyValue> potValue;
    Ptr32<const char> healthName;
    Ptr32<const char> healthText;
    w3d_fn_8004b3f0(self, 7.0f);
    potName = "WormPot";
    w3d_auto_800fc330(&potName, &potValue);
    if (potValue->kind == 1)
        self->amount = self->amount + self->amount;
    Ptr32<void> label = self->label;
    if (self->amount > 0)
        w3d_string_append(label, "+");
    sprintf(digits, "%d ", self->amount);
    w3d_string_append(label, digits);
    healthText = 0;
    healthName = "Text.Health";
    w3d_auto_800fc2b0(&healthName, &healthText);
    w3d_string_append(label, healthText);
}


