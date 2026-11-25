// desc: Appears to scan the counted array of interface objects for the first whose virtual slot 7 returns one and return the result of its virtual slot 15, or 0x80004005 when none matches.
struct S21Item;
struct S21ItemMethods { void (*reserved[7])(void); int (*kind)(struct S21Item *); void (*reserved2[7])(void); int (*activate)(struct S21Item *); };
struct S21Item { struct S21ItemMethods *methods; };
struct S21Array { unsigned count; int reserved; struct S21Item **items; };
struct S21Object { char pad[48]; struct S21Array array; };
int w3d_s21_activate_first_801dba3c(struct S21Object *self)
{
    unsigned i = 0;
    if (i < self->array.count) {
        struct S21Array *array = &self->array;
        unsigned offset = 0;
        do {
            struct S21Item *item = *(struct S21Item **)(offset + (unsigned)array->items);
            if (item->methods->kind(item) == 1) {
                item = *(struct S21Item **)(offset + (unsigned)array->items);
                return item->methods->activate(item);
            }
            i++;
            offset += 4;
        } while (i < self->array.count);
    }
    return 0x80004005;
}
