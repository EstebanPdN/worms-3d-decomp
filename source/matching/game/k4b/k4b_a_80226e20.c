struct K4bString { char *text; };
struct K4bIface { void **vtable; };
struct K4bFontRef {
    void **vtable;
    char base[16];
    float size;
    struct K4bString name;
    struct K4bIface *font;
    struct K4bIface *owner;
};
extern struct K4bIface *lbl_804b05ac;
extern struct K4bIface *lbl_804b05b0;
extern void *lbl_8041a1b8[];
extern void *w3d_tagged_construct_801ea0ec(void *object, int);
/* The name text lives in a shared string pool, so it stays an original object. */
extern const char lbl_803b6408[];
extern struct K4bString *w3d_string_from_text(struct K4bString *string, const char *text);
static inline void k4b_ref_init(struct K4bIface **slot, struct K4bIface *iface)
{
    *slot = iface;
    if (iface != 0)
        ((void (*)(struct K4bIface *))iface->vtable[3])(iface);
}
struct K4bFontRef *w3d_k4b_font_ref_construct_80226e20(struct K4bFontRef *self, void * arg_r4)
{
    w3d_tagged_construct_801ea0ec(self, arg_r4);
    self->vtable = lbl_8041a1b8;
    self->size = 0.0f;
    w3d_string_from_text(&self->name, lbl_803b6408);
    k4b_ref_init(&self->font, lbl_804b05b0);
    k4b_ref_init(&self->owner, lbl_804b05ac);
    return self;
}
// desc: w3d_k4b_font_ref_construct_80226e20: Appears to construct a font reference over 0x801ea0ec: vtable 0x8041a1b8, zero size, name string FE.Font and two retained shared default interfaces.
