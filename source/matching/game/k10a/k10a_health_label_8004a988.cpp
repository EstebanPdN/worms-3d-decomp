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
    const char *name;
    K10aPropertyValue *value;
};

struct K10aTextKey
{
    const char *name;
    const char *text;
};

struct K10aPot
{
    char pad0[68];
    int amount;               // +68
    char pad72[76];
    char label[4];            // +148 (string object, partial view)
};

extern "C" void w3d_fn_8004b3f0(K10aPot *self, float scale);
extern "C" void * w3d_auto_800fc330(const char **key, K10aPropertyValue **value);
extern "C" int w3d_auto_800fc2b0(const char **key, const char **text);
extern "C" void * w3d_string_append(void *string, const char *text);
extern "C" int sprintf(char *out, const char *format, ...);

extern "C" void w3d_k10a_health_label_8004a988(K10aPot *self)
{
    char digits[64];
    const char *potName;
    K10aPropertyValue *potValue;
    const char *healthName;
    const char *healthText;
    w3d_fn_8004b3f0(self, 7.0f);
    potName = "WormPot";
    w3d_auto_800fc330(&potName, &potValue);
    if (potValue->kind == 1)
        self->amount = self->amount + self->amount;
    void *label = self->label;
    if (self->amount > 0)
        w3d_string_append(label, "+");
    sprintf(digits, "%d ", self->amount);
    w3d_string_append(label, digits);
    healthText = 0;
    healthName = "Text.Health";
    w3d_auto_800fc2b0(&healthName, &healthText);
    w3d_string_append(label, healthText);
}
