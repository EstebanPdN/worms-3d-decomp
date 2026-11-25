// desc: Appears to erase one pointer from the vector at offset 20: it locates the element through a helper, shifts the tail down with memmove and shrinks the vector by one entry.
// desc: Appears to erase one pointer from the vector at offset 20: it locates the element through a helper, shifts the tail down with memmove and shrinks the vector by one entry.
struct S21Vector { int *begin; int *end; };
struct S21Object { char pad[20]; struct S21Vector items; };
extern int *fn_80359cec(int *, int *, int *);
extern void *fn_802eeef4(void *, const void *, unsigned);
void w3d_s21_erase_item_801f804c(struct S21Object *self, int key)
{
    struct S21Vector *items = &self->items;
    int *position = fn_80359cec(self->items.begin, items->end, &key);
    int *next = position + 1;
    if (next != items->end) {
        int *end = items->end;
        if (end != next)
            fn_802eeef4(position, next, (char *)end - (char *)next);
    }
    items->end = items->end - 1;
}
