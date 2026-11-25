// desc: Appears to initialize and register the global W3DNet descriptor object, setting its name, links and zeroed fields, and return zero.
struct S21Descriptor { const char *name; int a; int b; int c; void *table; int d; void *link; int e; int f; int g; };
extern struct S21Descriptor lbl_804641f0[];
extern char lbl_804641ec[];
extern char lbl_8040e528[];
extern const char lbl_803b42e4[];
extern void fn_80200a70(struct S21Descriptor *);
int w3d_s21_register_descriptor_8021d024(void)
{
    struct S21Descriptor *descriptor = lbl_804641f0;
    descriptor->name = lbl_803b42e4;
    descriptor->table = lbl_8040e528;
    descriptor->link = lbl_804641ec;
    descriptor->a = 0;
    descriptor->c = 0;
    descriptor->g = 0;
    fn_80200a70(descriptor);
    return 0;
}
