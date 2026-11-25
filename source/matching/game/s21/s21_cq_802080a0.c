// desc: Appears to clear an existing value, ask the service object through virtual slot 6 to fill the field at offset 20 and return its negative status or zero.
struct S21Service;
struct S21ServiceMethods { void (*reserved[6])(void); int (*fill)(struct S21Service *, int, int, void *); };
struct S21Service { struct S21ServiceMethods *methods; };
struct S21Object { char pad[20]; int value; };
extern int fn_8020810c(struct S21Object *);
extern struct S21Service *fn_8020b884(void);
int w3d_s21_refill_802080a0(struct S21Object *self, int a, int b)
{
    struct S21Service *service;
    int status;
    if (self->value)
        fn_8020810c(self);
    service = fn_8020b884();
    status = service->methods->fill(service, a, b, &self->value);
    if (status >= 0)
        status = 0;
    return status;
}
