// d22b: 0x800928fc (444 bytes). Bind an item to its owner: pass the item's
// three colour bytes (+48..+50) to the owner's preparation call and its mode
// setter (blue + 2*red - 4*green, truncated to a byte), set the owner colour
// from the bytes converted to float together with the item's two parameter
// blocks (+60, +52), move every interface in the item's child array (+44)
// to the array at +80 (kind 10) and erase them from +44 (kind 3), release
// and clear the two held objects (+72, then +68; virtual slot +16), clear
// the two state halfwords, copy the item's placement (+20, 16 bytes) to the
// owner (+540), attach the item, clear the owner's pair and re-append the
// optional interfaces at +88/+92 to +44. Returns 0.
// Built with -mfast-cast: the byte to float conversions go through a stack
// byte and psq_l (and leave the dead 'mr r11,r9; mr r10,r9' copies). The
// placement copy reads through a reference to the item's placement: the
// float is copied first, then the 12-byte key as a plain struct copy.
// Field names are inferred; the structs are partial views.
struct d22b_Object;
struct d22b_ObjectTable {
    unsigned char unknown00[16];
    void (*release)(d22b_Object *);      // +16
};
struct d22b_Object { d22b_ObjectTable *vtable; };
struct d22b_ArrayHeader {
    unsigned char unknown00[24];
    unsigned count;                      // +24
    unsigned char unknown28[4];
    void *data[1];                       // +32
};
struct d22b_Key { int a; int b; int c; };
struct d22b_Placement {
    d22b_Key key;
    float scale;
};
struct d22b_Item {
    unsigned char unknown00[20];
    d22b_Placement placement;            // +20
    unsigned char unknown36[8];
    d22b_ArrayHeader *children;          // +44
    unsigned char red;                   // +48
    unsigned char green;                 // +49
    unsigned char blue;                  // +50
    unsigned char unknown51;
    unsigned char unknown52[8];          // +52
    unsigned char unknown60[8];          // +60
    d22b_Object *first;                  // +68
    d22b_Object *second;                 // +72
    unsigned char unknown76[12];
    void *extra0;                        // +88
    void *extra1;                        // +92
    unsigned char unknown96[6];
    unsigned short state102;             // +102
    unsigned short state104;             // +104
};
struct d22b_Owner {
    unsigned char unknown000[540];
    d22b_Placement placement;            // +540
};
extern "C" void d22b_prepare_80092388(d22b_Owner *, unsigned char, unsigned char, unsigned char);
extern "C" void d22b_set_mode_800919cc(d22b_Owner *, unsigned char);
extern "C" void d22b_set_colour_80092234(d22b_Owner *, void *, void *, float, float, float);
extern "C" void d22b_array_append_801ef174(void *, unsigned, unsigned, void *);
extern "C" void d22b_array_erase_801ef380(void *, unsigned, unsigned, unsigned, unsigned);
extern "C" void d22b_attach_800927b4(d22b_Owner *, d22b_Item *);
extern "C" void d22b_clear_pair_8008ecac(d22b_Owner *);

extern "C" int d22b_object_reset_800928fc(d22b_Owner *self, d22b_Item *item) {
    unsigned i = 0;
    d22b_prepare_80092388(self, item->blue, item->green, item->red);
    d22b_set_mode_800919cc(self, item->blue + item->red * 2 - item->green * 4);
    d22b_set_colour_80092234(self, item->unknown60, item->unknown52,
                             (float)item->blue, (float)item->green, (float)item->red);
    d22b_ArrayHeader *children = item->children;
    unsigned count = children->count;
    void **data = children->data;
    for (; i < count; i++)
        d22b_array_append_801ef174(item, 80, 10, data[i]);
    d22b_array_erase_801ef380(item, 44, 3, 0, count);
    d22b_Object *object = item->second;
    item->second = 0;
    if (object) object->vtable->release(object);
    object = item->first;
    item->first = 0;
    if (object) object->vtable->release(object);
    item->state102 = 0;
    item->state104 = 0;
    const d22b_Placement &src = item->placement;
    self->placement.scale = src.scale;
    self->placement.key = src.key;
    d22b_attach_800927b4(self, item);
    d22b_clear_pair_8008ecac(self);
    if (item->extra0) d22b_array_append_801ef174(item, 44, 3, item->extra0);
    if (item->extra1) d22b_array_append_801ef174(item, 44, 3, item->extra1);
    return 0;
}
