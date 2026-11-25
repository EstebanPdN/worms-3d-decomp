// desc: Appears to be a static initialization entry that clears a table of thirteen records and registers the ComponentRegistry descriptor in an ordered list when called with the final priority.
struct S21Record { int a; int b; int c; };
struct S21Descriptor { int zero; const char *name; int pad; void *callback; int count; void *link; };
extern struct S21Record lbl_8045e890[];
extern struct S21Descriptor lbl_8045e928[];
extern const char lbl_803b1d2c[];
extern char lbl_801fc7b0[];
extern char lbl_80463308[];
extern void fn_80200af8(void *);
void w3d_s21_static_register_components_801fca98(int initialize, int priority)
{
    if (priority == 0xffff && initialize) {
        int i;
        struct S21Descriptor *descriptor;
        for (i = 0; i < 13; i++) {
            lbl_8045e890[i].c = 0;
            lbl_8045e890[i].b = 0;
            lbl_8045e890[i].a = 0;
        }
        descriptor = &lbl_8045e928[1];
        descriptor->name = lbl_803b1d2c;
        descriptor->pad = 0;
        descriptor->callback = lbl_801fc7b0;
        descriptor->count = 10;
        descriptor->link = lbl_80463308;
        fn_80200af8(descriptor);
    }
}
