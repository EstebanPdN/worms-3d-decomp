struct SharedString { void *value; };
struct ResourceOwner;
struct ResourceTable { void *unknown[5]; void (*visit)(ResourceOwner *, SharedString *); };
struct ResourceOwner { ResourceTable *table; unsigned char unknown[184]; unsigned int flags; };
extern "C" {
void fn_8020bb54(SharedString *, const char *);
void fn_8020c5c4(SharedString *);
void fn_80341588(SharedString *);
extern char lbl_8039c85c[], lbl_8039c864[], lbl_8039c86c[], lbl_8039c874[], lbl_8039c878[], lbl_8039c88c[];
}
// The virtual action is unresolved; these are original path strings, not owned data.
inline void visitPath(ResourceOwner *self, const char *path, SharedString *text) {
    ResourceTable *table = self->table;
    fn_8020bb54(text, path);
    table->visit(self, text);
    fn_8020c5c4(text);
    fn_80341588(text);
}
extern "C" void w3d_r25a_visit_resource_paths_80128f6c(ResourceOwner *self) {
    SharedString text;
    if (self->flags & 0x20000000) {
        visitPath(self, lbl_8039c85c, &text);
        if ((self->flags & 0x20000000) && !(self->flags & 0x10000000)) return;
    }
    visitPath(self, lbl_8039c864, &text);
    visitPath(self, lbl_8039c86c, &text);
    visitPath(self, lbl_8039c874, &text);
    visitPath(self, lbl_8039c878, &text);
    visitPath(self, lbl_8039c88c, &text);
}
