extern void w3d_auto_800fc230(const char **, unsigned *);
struct S19Task { char pad0[4]; int done; char pad8[12]; unsigned limit; };

void s19_check_bullet_count_80021958(struct S19Task *p) {
    unsigned count = 0;
    const char *name = "AI.BulletCount";
    w3d_auto_800fc230(&name, &count);
    if (count > p->limit)
        p->done = 1;
}
