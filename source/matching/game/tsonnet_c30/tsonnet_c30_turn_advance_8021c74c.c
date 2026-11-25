/* Reference-only: when a pending flag is set and the "CurrentTeamIndex"
   property names a team whose word at offset 32 is zero, counts one more turn
   step and, once the count passes the stored limit, resets the engine state,
   leaves the current screen, posts an integer message and an empty message,
   and clears the flag. Offsets and meanings are inferred; the local property
   query keeps its name pointer and result as separate stack words. */
typedef struct Msg { unsigned short id, pad02; void *type; } Msg;
typedef struct Cache { int id; const char *name; } Cache;
typedef struct Prop { const char *name; int value; } Prop;
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
extern int fn_800fc1f0(const char **, int *);
extern void *fn_800fc7f8(int);
extern void fn_801298cc(void *);
extern Msg *fn_801613f0(void *, int);
extern short fn_8015f5a0(Cache *, int);
extern Msg *fn_800a82f0(Msg *, unsigned short, int);
extern int fn_8016239c(Msg *);
extern void *lbl_804aaf48, *lbl_804aac54, *lbl_804b1788, *lbl_804b1754;
extern int lbl_804abab4;
extern Cache lbl_804b078c, lbl_804b0714;
extern void *lbl_8040db38[];
void tsonnet_c30_turn_advance_8021c74c(void *self) {
    if (FIELD(self, int, 92)) {
        const char *name = "CurrentTeamIndex";
        int team = -1;
        fn_800fc1f0(&name, &team);
        if (team != -1) {
            int zero = FIELD(fn_800fc7f8(team), int, 32);
            if (zero == 0) {
                void *c = FIELD(FIELD(self, void *, 36), void *, 24);
                unsigned n = ++FIELD(c, unsigned, 28);
                if (n > FIELD(self, unsigned, 124)) {
                    void *g1 = lbl_804aaf48;
                    void *g2 = lbl_804aac54;
                    FIELD(g1, int, 432) = zero;
                    FIELD(g2, unsigned, 96) |= 0x400000;
                    { void *o = FIELD(c, void *, 60); ((void (*)(void *))(*(void ***)o)[11])(o); }
                    if (lbl_804abab4) fn_801298cc(lbl_804b1788);
                    { Msg *m = fn_801613f0(lbl_804b1754, 12);
                    fn_8016239c(fn_800a82f0(m, fn_8015f5a0(&lbl_804b078c, 1), 0)); }
                    { Msg *m = fn_801613f0(lbl_804b1754, 8);
                    m->id = fn_8015f5a0(&lbl_804b0714, 1);
                    m->type = lbl_8040db38;
                    fn_8016239c(m); }
                    FIELD(self, int, 92) = zero;
                }
            }
        }
    }
}
