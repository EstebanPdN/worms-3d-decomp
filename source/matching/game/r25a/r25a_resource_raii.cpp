struct SharedString { void *value; inline SharedString(const char *); inline ~SharedString(); };
struct ResourceOwner;
struct ResourceTable { void *unknown[5]; void (*visit)(ResourceOwner *, SharedString *); };
struct ResourceOwner { ResourceTable *table; unsigned char unknown[184]; unsigned int flags; };
extern "C" {
void fn_8020bb54(SharedString *, const char *);
void fn_8020c5c4(SharedString *);
void fn_80341588(SharedString *);
extern char lbl_8039c85c[], lbl_8039c864[], lbl_8039c86c[], lbl_8039c874[], lbl_8039c878[], lbl_8039c88c[];
}
inline SharedString::SharedString(const char *p) { fn_8020bb54(this, p); }
inline SharedString::~SharedString() { fn_8020c5c4(this); fn_80341588(this); }
extern "C" void w3d_r25a_visit_resource_paths_80128f6c(ResourceOwner *self) {
    if (!(self->flags & 0x20000000)) goto common;
    {
        ResourceTable *table = self->table;
        SharedString text(lbl_8039c85c);
        table->visit(self, &text);
    }
    if (!(self->flags & 0x20000000)) goto common;
    if (!(self->flags & 0x10000000)) return;
common:
    {
        ResourceTable *table = self->table;
        SharedString text(lbl_8039c864);
        table->visit(self, &text);
    }
    {
        ResourceTable *table = self->table;
        SharedString text(lbl_8039c86c);
        table->visit(self, &text);
    }
    {
        ResourceTable *table = self->table;
        SharedString text(lbl_8039c874);
        table->visit(self, &text);
    }
    {
        ResourceTable *table = self->table;
        SharedString text(lbl_8039c878);
        table->visit(self, &text);
    }
    {
        ResourceTable *table = self->table;
        SharedString text(lbl_8039c88c);
        table->visit(self, &text);
    }
}
