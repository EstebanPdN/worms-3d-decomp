// desc: Appears to fetch an object through two virtual slots, pass it to a helper together with this and return it.
struct S21Object;
struct S21Methods { void (*reserved[5])(void); struct S21Object *(*first)(struct S21Object *); char pad[64]; struct S21Object *(*second)(struct S21Object *); };
struct S21Object { struct S21Methods *methods; };
extern void fn_801ea4c8(struct S21Object *, struct S21Object *);
struct S21Object *w3d_s21_fetch_801ea470(struct S21Object *self)
{
    struct S21Object *inner = self->methods->first(self);
    struct S21Object *object = inner->methods->second(inner);
    fn_801ea4c8(object, self);
    return object;
}
