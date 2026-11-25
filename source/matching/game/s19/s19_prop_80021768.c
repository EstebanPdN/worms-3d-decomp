struct S19Sel { int pad0; int f4, f8, f12; void *vt; int f20; };
extern unsigned char lbl_8040dd08[];
extern void * w3d_constructor_lookup_name(const char **, int *);
struct S19Sel *s19_active_worm_ctor_80021768(struct S19Sel *p) {
    const char *name;
    p->vt = (void *)lbl_8040dd08;
    p->f4 = 0;
    p->f8 = 0;
    p->f20 = 0;
    p->f12 = 4;
    name = "ActiveWormIndex";
    w3d_constructor_lookup_name(&name, &p->f20);
    return p;
}
