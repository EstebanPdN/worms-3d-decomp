// desc: Appears to register the Bundles, Objects, Temp, HUD, Frontend/Mechanics and Frontend/Icons resource folders through a virtual call, skipping the last five when the flags select bundles only.
struct K1cText;
extern void fn_8020c5c4(K1cText *);
extern void fn_80341588(K1cText *);
struct K1cText {
    char *data;
    K1cText(const char *source);
    ~K1cText() { fn_8020c5c4(this); fn_80341588(this); }
};
struct K1cLoader;
struct K1cLoaderMethods { void (*reserved[5])(void); void (*add_folder)(K1cLoader *, K1cText *); };
struct K1cLoader { K1cLoaderMethods *methods; char pad[184]; unsigned int flags; };
extern const char lbl_8039c85c[];
extern const char lbl_8039c864[];
extern const char lbl_8039c86c[];
extern const char lbl_8039c874[];
extern const char lbl_8039c878[];
extern const char lbl_8039c88c[];
#define K1C_ADD(NAME) { K1cLoaderMethods *m = self->methods; K1cText text(NAME); m->add_folder(self, &text); }
extern "C" void w3d_k1c_add_resource_paths_80128f6c(K1cLoader *self)
{
    if (self->flags & 0x20000000) {
        K1C_ADD(lbl_8039c85c)
        if (self->flags & 0x20000000) {
            if (!(self->flags & 0x10000000))
                return;
        }
    }
    K1C_ADD(lbl_8039c864)
    K1C_ADD(lbl_8039c86c)
    K1C_ADD(lbl_8039c874)
    K1C_ADD(lbl_8039c878)
    K1C_ADD(lbl_8039c88c)
}
