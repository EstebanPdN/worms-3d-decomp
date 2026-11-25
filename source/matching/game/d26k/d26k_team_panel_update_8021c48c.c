// Team panel update (Worms 3D GameCube PAL, 0x8021c48c).
// 
// Reads the CurrentTeamIndex setting and shows or hides the panel: a live team
// member leaves the app state and posts 0 unless a start time is pending, in
// which case the time window and forced flag decide. Each change posts a 12-byte
// int message built from the cached message id. Struct fields are partial views.

typedef unsigned short u16;
typedef struct Msg Msg;
typedef struct { int pad[5]; int startTime; } TeamState;
typedef struct { char pad[24]; TeamState *state; } Owner;
typedef struct { char pad0[36]; Owner *owner; char pad1[92-40]; int active; char pad2[156-96]; int forced; int enabled; } Panel;
typedef struct { char pad[32]; int member; } TeamEntry;
typedef struct { char pad[36]; int busy; } Ctx3;
typedef struct { char pad[52]; int now; } EngineCtx;
typedef struct { char pad[240]; unsigned bits; } Cfg;
extern const char text_803b3efc[];
extern void *global_804b1788;
extern void *global_804b1754;
extern Cfg *global_804aaabc;
extern int global_804abab4;
extern char global_804b078c;
int fn_800fc1f0(void *, int *);
TeamEntry *fn_800fc7f8(int);
Ctx3 *fn_8003888c(void);
int fn_8015ccbc(void *);
void fn_80129878(void *);
void fn_801298cc(void *);
Msg *fn_801613f0(void *, int);
int fn_8015f5a0(void *, int);
Msg *fn_800a82f0(Msg *, u16, int);
int fn_8016239c(Msg *);
EngineCtx *fn_80165254(void);
static __inline__ void post(void *arena, int v) { Msg *m = fn_801613f0(arena, 12); fn_8016239c(fn_800a82f0(m, fn_8015f5a0(&global_804b078c, 1), v)); }
typedef struct { const char *name; } Key;
void w3d_d26k_team_panel_update_8021c48c(Panel *self) {
    TeamState *st = self->owner->state;
    int quiet;
    if (self->active) {
        int index = -1;
        Key k;
        k.name = text_803b3efc;
        fn_800fc1f0(&k, &index);
        if (index != -1) {
            if (fn_800fc7f8(index)->member != 0 && self->enabled != 0 && fn_8003888c()->busy == 0
                && (quiet = (global_804aaabc->bits >> 23) & 1) == 0) {
                if (global_804abab4) {
                    fn_801298cc(global_804b1788);
                    { void *a = global_804b1754; global_804abab4 = quiet; post(a, 0); }
                }
            } else {
                int t = st->startTime;
                if (t < 0) {
                    if (global_804abab4) {
                        fn_801298cc(global_804b1788);
                        { void *a = global_804b1754; global_804abab4 = 0; post(a, 0); }
                    }
                } else if (t - fn_80165254()->now <= 2999 && self->forced == 0) {
                    if (fn_8015ccbc(global_804b1788) == 0) {
                        fn_80129878(global_804b1788);
                        { void *a = global_804b1754; global_804abab4 = 1; post(a, 1); }
                    }
                } else if (global_804abab4) {
                    fn_801298cc(global_804b1788);
                    { void *a = global_804b1754; global_804abab4 = 0; post(a, 0); }
                }
            }
        }
    }
}
