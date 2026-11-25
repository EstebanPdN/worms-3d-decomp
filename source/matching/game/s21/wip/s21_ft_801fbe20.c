// desc: Appears to call virtual slot 19 of every non-null object in the pointer vector at offset 52 and return the last negative status, or zero.
struct S21Item;
struct S21ItemMethods { void (*reserved[19])(void); int (*update)(struct S21Item *); };
struct S21Item { struct S21ItemMethods *methods; };
struct S21Vector { struct S21Item **begin; struct S21Item **end; };
struct S21Object { char pad[52]; struct S21Vector items; };
int w3d_s21_update_all_801fbe20(struct S21Object *self)
{
    struct S21Vector *items = &self->items;
    struct S21Item **item = items->begin;
    struct S21Vector *holder;
    int failure = 0;
    if (item != items->end) {
        holder = &self->items;
        do {
            if (*item) {
                int status = (*item)->methods->update(*item);
                if (status < 0)
                    failure = status;
            }
            item++;
        } while (item != holder->end);
    }
    return failure;
}
