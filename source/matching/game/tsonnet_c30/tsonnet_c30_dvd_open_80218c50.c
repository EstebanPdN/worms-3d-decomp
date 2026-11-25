/* Reference-only: opens a file by path through the DVD entry lookup and logs
   the result. Field offsets are observed; names and meanings are inferred. */
extern int fn_80218d10(void *self);
extern int fn_802f4ef0(char *path);
extern int fn_802f51e4(int entry, void *info);
extern void fn_802fb7ac(const char *fmt, ...);
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))

int tsonnet_c30_dvd_open_80218c50(void *self, char *path, int flags) {
    int entry, ok;
    fn_80218d10(self);
    FIELD(self, int, 108) = -1;
    FIELD(self, int, 104) = 0;
    FIELD(self, int, 100) = 0;
    if (flags & 2) return 0;
    entry = fn_802f4ef0(path);
    if (entry >= 0) {
        ok = fn_802f51e4(entry, (char *)self + 24);
        FIELD(self, int, 96) = ok != 0;
        fn_802fb7ac("DVDOpen: '%s' %s\n", path, ok ? "ok" : "fail!");
        if (ok) return 0;
    }
    return 0x90000004;
}
