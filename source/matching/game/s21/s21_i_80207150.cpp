struct S21Named;
struct S21NamedMethods { void (*reserved[5])(); const char *(*name)(S21Named *); };
struct S21Named { S21NamedMethods *methods; };
struct S21NamedList { char pad[20]; int count; int reserved; S21Named **items; };
extern int fn_802ef074(const char *, const char *);
extern "C" S21Named *w3d_s21_find_named_80207150(S21NamedList *list, const char *key)
{
    S21Named **item = list->items;
    S21Named **end = item + list->count;
    for (; item != end; item++) {
        const char *name = (*item)->methods->name(*item);
        if (fn_802ef074(name, key) == 0)
            return *item;
    }
    return 0;
}
