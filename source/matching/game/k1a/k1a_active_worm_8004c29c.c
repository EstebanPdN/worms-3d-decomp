extern void w3d_auto_800fc1f0(const char **, int *);
extern void w3d_auto_8004c2f0(void *, int);

void k1a_active_worm_apply_8004c29c(void *self)
{
    const char *name;
    int active = 0;
    name = "ActiveWormIndex";
    w3d_auto_800fc1f0(&name, &active);
    w3d_auto_8004c2f0(self, active);
}
