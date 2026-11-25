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
    void *unknown_00[12];
    void (*set_converted)(W3dPropertyStore *self, int key, int value); /* 0x30 */
    int (*convert)(W3dPropertyStore *self, int value);                  /* 0x34 */
} W3dPropertyStoreVtable;
struct W3dPropertyStore
{
    W3dPropertyStoreVtable *vtable;
    unsigned char unknown_04[6];
    unsigned short value_offset;   /* 0x0a */
    unsigned char unknown_0c[4];
    void *table;                   /* 0x10 */
};
unsigned char *w3d_s21_find_data_80207950(void *table, void *key, int entry_size);
unsigned char *w3d_property_insert_802078b4(void *table, void *key, int entry_size);

void w3d_property_store_assign_8035e118(W3dPropertyStore *self, int key, int value)
{
    int converted = self->vtable->convert(self, value);
    self->vtable->set_converted(self, key, converted);
}

int w3d_property_store_same_8035e174(W3dPropertyStore *self, int first, int second)
{
    return self->vtable->convert(self, first) == self->vtable->convert(self, second);
}

int w3d_property_store_lacks_8035e1e0(W3dPropertyStore *self, int key)
{
    return w3d_s21_find_data_80207950(self->table, key, self->value_offset + 4) == 0;
}

void w3d_property_store_set_8035e214(W3dPropertyStore *self, int key, int value)
{
    unsigned char *entry = w3d_property_insert_802078b4(self->table, key, self->value_offset + 4);
    *(int *)(entry + self->value_offset) = value;
}

int w3d_property_store_get_8035e258(W3dPropertyStore *self, int key)
{
    unsigned char *entry = w3d_s21_find_data_80207950(self->table, key, self->value_offset + 4);
    if (entry != 0)
        return *(int *)(entry + self->value_offset);
    return 0;
}

void w3d_property_store_assign_8035e504(W3dPropertyStore *self, int key, int value)
{
    int converted = self->vtable->convert(self, value);
    self->vtable->set_converted(self, key, converted);
}

int w3d_property_store_same_8035e560(W3dPropertyStore *self, int first, int second)
{
    return self->vtable->convert(self, first) == self->vtable->convert(self, second);
}

int w3d_property_store_lacks_8035e5cc(W3dPropertyStore *self, int key)
{
    return w3d_s21_find_data_80207950(self->table, key, self->value_offset + 4) == 0;
}

void w3d_property_store_set_8035e600(W3dPropertyStore *self, int key, int value)
{
    unsigned char *entry = w3d_property_insert_802078b4(self->table, key, self->value_offset + 4);
    *(int *)(entry + self->value_offset) = value;
}

int w3d_property_store_get_8035e644(W3dPropertyStore *self, int key)
{
    unsigned char *entry = w3d_s21_find_data_80207950(self->table, key, self->value_offset + 4);
    if (entry != 0)
        return *(int *)(entry + self->value_offset);
    return 0;
}

void w3d_property_store_assign_8035e6ac(W3dPropertyStore *self, int key, int value)
{
    int converted = self->vtable->convert(self, value);
    self->vtable->set_converted(self, key, converted);
}

int w3d_property_store_same_8035e708(W3dPropertyStore *self, int first, int second)
{
    return self->vtable->convert(self, first) == self->vtable->convert(self, second);
}

int w3d_property_store_lacks_8035e774(W3dPropertyStore *self, int key)
{
    return w3d_s21_find_data_80207950(self->table, key, self->value_offset + 4) == 0;
}

void w3d_property_store_set_8035e7a8(W3dPropertyStore *self, int key, int value)
{
    unsigned char *entry = w3d_property_insert_802078b4(self->table, key, self->value_offset + 4);
    *(int *)(entry + self->value_offset) = value;
}

int w3d_property_store_get_8035e7ec(W3dPropertyStore *self, int key)
{
    unsigned char *entry = w3d_s21_find_data_80207950(self->table, key, self->value_offset + 4);
    if (entry != 0)
        return *(int *)(entry + self->value_offset);
    return 0;
}

void w3d_property_store_assign_8035e854(W3dPropertyStore *self, int key, int value)
{
    int converted = self->vtable->convert(self, value);
    self->vtable->set_converted(self, key, converted);
}

int w3d_property_store_same_8035e8b0(W3dPropertyStore *self, int first, int second)
{
    return self->vtable->convert(self, first) == self->vtable->convert(self, second);
}

int w3d_property_store_lacks_8035e91c(W3dPropertyStore *self, int key)
{
    return w3d_s21_find_data_80207950(self->table, key, self->value_offset + 4) == 0;
}

void w3d_property_store_set_8035e950(W3dPropertyStore *self, int key, int value)
{
    unsigned char *entry = w3d_property_insert_802078b4(self->table, key, self->value_offset + 4);
    *(int *)(entry + self->value_offset) = value;
}

int w3d_property_store_get_8035e994(W3dPropertyStore *self, int key)
{
    unsigned char *entry = w3d_s21_find_data_80207950(self->table, key, self->value_offset + 4);
    if (entry != 0)
        return *(int *)(entry + self->value_offset);
    return 0;
}
