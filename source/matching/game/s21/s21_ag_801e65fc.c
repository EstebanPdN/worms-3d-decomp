// desc: Appears to return the result of a virtual slot of the linked object, or zero when there is no link.
struct S21Link;
struct S21LinkMethods { void (*reserved[24])(void); int (*query)(struct S21Link *); };
struct S21Link { struct S21LinkMethods *methods; };
struct S21Object { char pad[44]; struct S21Link *link; };
int w3d_s21_link_query_801e65fc(struct S21Object *self)
{
    if (self->link != 0)
        return self->link->methods->query(self->link);
    return 0;
}
