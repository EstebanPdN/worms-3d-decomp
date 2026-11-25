// desc: Appears to report whether any object in the counted array returns a name from virtual slot 10 that equals the given text.
struct S21Named;
struct S21NamedMethods { void (*reserved[10])(void); const char *(*name)(struct S21Named *); };
struct S21Named { struct S21NamedMethods *methods; };
struct S21Array { unsigned count; int reserved; struct S21Named **items; };
struct S21Object { char pad[20]; struct S21Array array; };
extern int fn_802ef234(const char *, const char *);
int w3d_s21_has_name_801ddff4(struct S21Object *self, const char *name)
{
    unsigned i = 0;
    if (i < self->array.count) {
        struct S21Array *array = &self->array;
        unsigned offset = 0;
        do {
            struct S21Named *item = *(struct S21Named **)(offset + (unsigned)array->items);
            if (fn_802ef234(item->methods->name(item), name) == 0)
                return 1;
            i++;
            offset += 4;
        } while (i < self->array.count);
    }
    return 0;
}
