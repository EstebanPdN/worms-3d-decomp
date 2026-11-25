// desc: Appears to initialize and register the global W3DContainers descriptor object, setting its name, links and zeroed fields, and return zero.
struct S21Descriptor { const char *name; int a; int b; int c; void *table; int d; void *link; int e; int f; int g; };
extern struct S21Descriptor lbl_8046506c[];
extern char lbl_80465068[];
extern char lbl_8040cb00[];
extern const char lbl_803ca980[];
extern void fn_80200a70(struct S21Descriptor *);
int w3d_s21_register_descriptor_8025d61c(void)
{
    struct S21Descriptor *descriptor = lbl_8046506c;
    descriptor->name = lbl_803ca980;
    descriptor->table = lbl_8040cb00;
    descriptor->link = lbl_80465068;
    descriptor->a = 0;
    descriptor->c = 0;
    descriptor->g = 0;
    fn_80200a70(descriptor);
    return 0;
}
