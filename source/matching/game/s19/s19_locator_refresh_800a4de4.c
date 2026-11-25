struct S19Frozen { char pad0[32]; void *owner; char pad36[4]; void *locator; };
extern void w3d_auto_800a4da4(void *);
extern void *w3d_empty_80343584(void *);
extern void *FUN_800e5cf0(void *, const char *, const char *, int, int);

void s19_locator_refresh_800a4de4(struct S19Frozen *p) {
    if (p->locator)
        w3d_auto_800a4da4((void *)p);
    p->locator = FUN_800e5cf0(w3d_empty_80343584(p->owner), "IceGasLocator", "UtilityFreeze", -1, 0);
}
