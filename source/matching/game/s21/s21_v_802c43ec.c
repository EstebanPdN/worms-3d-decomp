// desc: Appears to open a named resource through a global service, store the returned interface and notify it, or close the current one for an empty name.
struct S21Resource;
struct S21ResourceMethods { void (*reserved[5])(struct S21Resource *); void (*retain)(struct S21Resource *); };
struct S21Resource { struct S21ResourceMethods *methods; };
struct S21Service;
struct S21ServiceMethods { void (*reserved[23])(void); int (*open)(struct S21Service *, const char *, struct S21Resource **); };
struct S21Service { struct S21ServiceMethods *methods; };
struct S21Globals { char pad[108]; struct S21Service *service; };
struct S21Player { char pad[236]; struct S21Resource *resource; int open; };
extern struct S21Globals *lbl_804b1788;
extern void fn_802c4380(struct S21Player *);
void w3d_s21_player_open_802c43ec(struct S21Player *self, const char *name)
{
    struct S21Service *service;
    if (name == 0 || *name == 0) {
        fn_802c4380(self);
        return;
    }
    if (self->open)
        fn_802c4380(self);
    service = lbl_804b1788->service;
    if (service) {
        if (service->methods->open(service, name, &self->resource) >= 0) {
            struct S21Resource *resource = self->resource;
            self->open = 1;
            resource->methods->retain(resource);
        }
    }
}
