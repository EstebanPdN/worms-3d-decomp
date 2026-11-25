#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "h1_property_store.c"
/* Keyed property-store template instances (session b169b320).
 * Four instantiations at 0x8035e118, 0x8035e504, 0x8035e6ac and 0x8035e854
 * share one shape: assign converts a value through vtable slot 0x34 and
 * stores it through slot 0x30; same compares two converted values; lacks,
 * set and get look a key up in the store's table (entries of
 * value_offset + 4 bytes) with the s21 find routine or insert it, and read
 * or write the int value at value_offset inside the entry. */

typedef struct W3dPropertyStore W3dPropertyStore;
typedef struct W3dPropertyStoreVtable
{
    Ptr32<void> unknown_00[12];
    Ptr32<void (Ptr32<W3dPropertyStore>, int, int)> set_converted; /* 0x30 */
    Ptr32<int (Ptr32<W3dPropertyStore>, int)> convert;                  /* 0x34 */
} W3dPropertyStoreVtable;
struct W3dPropertyStore
{
    Ptr32<W3dPropertyStoreVtable> vtable;
    unsigned char unknown_04[6];
    unsigned short value_offset;   /* 0x0a */
    unsigned char unknown_0c[4];
    Ptr32<void> table;                   /* 0x10 */
};
Ptr32<unsigned char> w3d_s21_find_data_80207950(Ptr32<void> table, Ptr32<void> key, int entry_size);
Ptr32<unsigned char> w3d_property_insert_802078b4(Ptr32<void> table, Ptr32<void> key, int entry_size);

void w3d_property_store_assign_8035e118(Ptr32<W3dPropertyStore> self, int key, int value)
{
    int converted = self->vtable->convert(self, value);
    self->vtable->set_converted(self, key, converted);
}

int w3d_property_store_same_8035e174(Ptr32<W3dPropertyStore> self, int first, int second)
{
    return self->vtable->convert(self, first) == self->vtable->convert(self, second);
}

int w3d_property_store_lacks_8035e1e0(Ptr32<W3dPropertyStore> self, int key)
{
    return w3d_s21_find_data_80207950(self->table, w3d::G(key), self->value_offset + 4) == 0;
}

void w3d_property_store_set_8035e214(Ptr32<W3dPropertyStore> self, int key, int value)
{
    Ptr32<unsigned char> entry = w3d_property_insert_802078b4(self->table, w3d::G(key), self->value_offset + 4);
    *(Ptr32<int>)(entry + self->value_offset) = value;
}

int w3d_property_store_get_8035e258(Ptr32<W3dPropertyStore> self, int key)
{
    Ptr32<unsigned char> entry = w3d_s21_find_data_80207950(self->table, w3d::G(key), self->value_offset + 4);
    if (entry != 0)
        return *(Ptr32<int>)(entry + self->value_offset);
    return 0;
}

void w3d_property_store_assign_8035e504(Ptr32<W3dPropertyStore> self, int key, int value)
{
    int converted = self->vtable->convert(self, value);
    self->vtable->set_converted(self, key, converted);
}

int w3d_property_store_same_8035e560(Ptr32<W3dPropertyStore> self, int first, int second)
{
    return self->vtable->convert(self, first) == self->vtable->convert(self, second);
}

int w3d_property_store_lacks_8035e5cc(Ptr32<W3dPropertyStore> self, int key)
{
    return w3d_s21_find_data_80207950(self->table, w3d::G(key), self->value_offset + 4) == 0;
}

void w3d_property_store_set_8035e600(Ptr32<W3dPropertyStore> self, int key, int value)
{
    Ptr32<unsigned char> entry = w3d_property_insert_802078b4(self->table, w3d::G(key), self->value_offset + 4);
    *(Ptr32<int>)(entry + self->value_offset) = value;
}

int w3d_property_store_get_8035e644(Ptr32<W3dPropertyStore> self, int key)
{
    Ptr32<unsigned char> entry = w3d_s21_find_data_80207950(self->table, w3d::G(key), self->value_offset + 4);
    if (entry != 0)
        return *(Ptr32<int>)(entry + self->value_offset);
    return 0;
}

void w3d_property_store_assign_8035e6ac(Ptr32<W3dPropertyStore> self, int key, int value)
{
    int converted = self->vtable->convert(self, value);
    self->vtable->set_converted(self, key, converted);
}

int w3d_property_store_same_8035e708(Ptr32<W3dPropertyStore> self, int first, int second)
{
    return self->vtable->convert(self, first) == self->vtable->convert(self, second);
}

int w3d_property_store_lacks_8035e774(Ptr32<W3dPropertyStore> self, int key)
{
    return w3d_s21_find_data_80207950(self->table, w3d::G(key), self->value_offset + 4) == 0;
}

void w3d_property_store_set_8035e7a8(Ptr32<W3dPropertyStore> self, int key, int value)
{
    Ptr32<unsigned char> entry = w3d_property_insert_802078b4(self->table, w3d::G(key), self->value_offset + 4);
    *(Ptr32<int>)(entry + self->value_offset) = value;
}

int w3d_property_store_get_8035e7ec(Ptr32<W3dPropertyStore> self, int key)
{
    Ptr32<unsigned char> entry = w3d_s21_find_data_80207950(self->table, w3d::G(key), self->value_offset + 4);
    if (entry != 0)
        return *(Ptr32<int>)(entry + self->value_offset);
    return 0;
}

void w3d_property_store_assign_8035e854(Ptr32<W3dPropertyStore> self, int key, int value)
{
    int converted = self->vtable->convert(self, value);
    self->vtable->set_converted(self, key, converted);
}

int w3d_property_store_same_8035e8b0(Ptr32<W3dPropertyStore> self, int first, int second)
{
    return self->vtable->convert(self, first) == self->vtable->convert(self, second);
}

int w3d_property_store_lacks_8035e91c(Ptr32<W3dPropertyStore> self, int key)
{
    return w3d_s21_find_data_80207950(self->table, w3d::G(key), self->value_offset + 4) == 0;
}

void w3d_property_store_set_8035e950(Ptr32<W3dPropertyStore> self, int key, int value)
{
    Ptr32<unsigned char> entry = w3d_property_insert_802078b4(self->table, w3d::G(key), self->value_offset + 4);
    *(Ptr32<int>)(entry + self->value_offset) = value;
}

int w3d_property_store_get_8035e994(Ptr32<W3dPropertyStore> self, int key)
{
    Ptr32<unsigned char> entry = w3d_s21_find_data_80207950(self->table, w3d::G(key), self->value_offset + 4);
    if (entry != 0)
        return *(Ptr32<int>)(entry + self->value_offset);
    return 0;
}

}
