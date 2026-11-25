extern void * w3d_auto_800fc1f0(const char **, int *);
extern void FUN_8008a30c(void *, int, int, int);
struct S19Crate { char pad0[288]; int state; };

void s19_crate_showered_8008a848(struct S19Crate *p) {
    const char *name = "Crate.Showered";
    int value;
    w3d_auto_800fc1f0(&name, &value);
    if (p->state != 0 && value == 1)
        FUN_8008a30c(p, 0, 1, 0);
}
