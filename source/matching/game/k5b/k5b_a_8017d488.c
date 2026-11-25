struct K5bKeyHandler { void **vtable; };
extern int lbl_804a8bd8[];
extern int lbl_804a8dd8[];
extern int lbl_804a89d8[];
int w3d_k5b_key_binding_set_8017d488(struct K5bKeyHandler *self, unsigned char *key, int binding)
{
    lbl_804a8bd8[*key] = binding;
    if (binding != 0 && lbl_804a8dd8[*key] != 0 && lbl_804a89d8[*key] == 0)
        return ((int (*)(struct K5bKeyHandler *, unsigned char *, int))self->vtable[16])(self, key, binding);
    return 0;
}
// desc: w3d_k5b_key_binding_set_8017d488: Appears to store a binding in the table at 0x804a8bd8 indexed by the key byte, then forwards to virtual slot 16 when the key is active and not suppressed.
