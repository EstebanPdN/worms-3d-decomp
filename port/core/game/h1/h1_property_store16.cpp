#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "h1_property_store16.c"
/* Keyed property-store template instance for 16-byte values (session
 * b169b320), the sibling of h1_property_store at 0x8035e2c0. Values are
 * returned and passed by value, compared with memcmp, and a missing key
 * reads as the default value at 0x804641cc. */

typedef struct W3dValue16
{
    int words[4];
} W3dValue16;
typedef struct W3dPropertyStore16 W3dPropertyStore16;
typedef struct W3dPropertyStore16Vtable
{
    Ptr32<void> unknown_00[12];
    Ptr32<void (Ptr32<W3dPropertyStore16>, int, W3dValue16)> set_converted; /* 0x30 */
    Ptr32<W3dValue16 (Ptr32<W3dPropertyStore16>, int)> convert;                 /* 0x34 */
} W3dPropertyStore16Vtable;
struct W3dPropertyStore16
{
    Ptr32<W3dPropertyStore16Vtable> vtable;
    unsigned char unknown_04[6];
    unsigned short value_offset;   /* 0x0a */
    unsigned char unknown_0c[4];
    Ptr32<void> table;                   /* 0x10 */
};
extern W3dValue16 w3d_property_default16_804641cc[];
Ptr32<unsigned char> w3d_s21_find_data_80207950(Ptr32<void> table, Ptr32<void> key, int entry_size);
Ptr32<unsigned char> w3d_property_insert_802078b4(Ptr32<void> table, Ptr32<void> key, int entry_size);
int memcmp(Ptr32<const void>, Ptr32<const void>, unsigned int);
void w3d_property_store16_assign_8035e2c0(Ptr32<W3dPropertyStore16> self, int key, int value)
{
    W3dValue16 converted = self->vtable->convert(self, value);
    self->vtable->set_converted(self, key, converted);
}

int w3d_property_store16_same_8035e348(Ptr32<W3dPropertyStore16> self, int first, int second)
{
    W3dValue16 a = self->vtable->convert(self, first);
    W3dValue16 b = self->vtable->convert(self, second);
    return memcmp(&a, &b, sizeof(W3dValue16)) == 0;
}

int w3d_property_store16_lacks_8035e3d0(Ptr32<W3dPropertyStore16> self, int key)
{
    return w3d_s21_find_data_80207950(self->table, w3d::G(key), self->value_offset + sizeof(W3dValue16)) == 0;
}

void w3d_property_store16_set_8035e404(Ptr32<W3dPropertyStore16> self, int key, W3dValue16 value)
{
    Ptr32<unsigned char> entry = w3d_property_insert_802078b4(self->table, w3d::G(key), self->value_offset + sizeof(W3dValue16));
    *(Ptr32<W3dValue16>)(entry + self->value_offset) = value;
}

W3dValue16 w3d_property_store16_get_8035e468(Ptr32<W3dPropertyStore16> self, int key)
{
    Ptr32<unsigned char> entry = w3d_s21_find_data_80207950(self->table, w3d::G(key), self->value_offset + sizeof(W3dValue16));
    if (entry != 0)
        return *(Ptr32<W3dValue16>)(entry + self->value_offset);
    return w3d_property_default16_804641cc[0];
}


}
