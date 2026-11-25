// desc: Appears to return the index of the last element of the pointer vector at offset 56 whose field at offset 16 is nonzero and whose helper value equals the key, or minus one.
struct S21Item { char pad[16]; int enabled; };
struct S21Vector { struct S21Item **begin; struct S21Item **end; };
struct S21Object { char pad[56]; struct S21Vector items; };
extern int fn_802bd2bc(struct S21Item *);
int w3d_s21_find_index_802bc6a8(struct S21Object *self, int key)
{
    struct S21Vector *items = &self->items;
    struct S21Item **item = items->begin;
    int found = -1;
    int index = 0;
    for (; item != items->end; item++, index++) {
        if (!(*item)->enabled)
            continue;
        if (fn_802bd2bc(*item) == key)
            found = index;
    }
    return found;
}
