#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_c30_turn_advance_8021c74c.c"
/* Reference-only: when a pending flag is set and the "CurrentTeamIndex"
   property names a team whose word at offset 32 is zero, counts one more turn
   step and, once the count passes the stored limit, resets the engine state,
   leaves the current screen, posts an integer message and an empty message,
   and clears the flag. Offsets and meanings are inferred; the local property
   query keeps its name pointer and result as separate stack words. */
typedef struct Msg { unsigned short id, pad02; Ptr32<void> type; } Msg;
typedef struct Cache { int id; Ptr32<const char> name; } Cache;
typedef struct Prop { Ptr32<const char> name; int value; } Prop;
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern int fn_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
extern Ptr32<void> fn_800fc7f8(int);
extern void fn_801298cc(Ptr32<void>);
extern Ptr32<Msg> fn_801613f0(Ptr32<void>, int);
extern short fn_8015f5a0(Ptr32<Cache>, int);
extern Ptr32<Msg> fn_800a82f0(Ptr32<Msg>, unsigned short, int);
extern int fn_8016239c(Ptr32<Msg>);
extern Ptr32<void> lbl_804aaf48; extern Ptr32<void> lbl_804aac54; extern Ptr32<void> lbl_804b1788; extern Ptr32<void> lbl_804b1754;
extern int lbl_804abab4;
extern Cache lbl_804b078c, lbl_804b0714;
extern Ptr32<void> lbl_8040db38[];
void tsonnet_c30_turn_advance_8021c74c(Ptr32<void> self) {
    if (FIELD(self, int, 92)) {
        Ptr32<const char> name = "CurrentTeamIndex";
        int team = -1;
        fn_800fc1f0(&name, &team);
        if (team != -1) {
            int zero = FIELD(fn_800fc7f8(team), int, 32);
            if (zero == 0) {
                Ptr32<void> c = FIELD(FIELD(self, void *, 36), void *, 24);
                unsigned n = ++FIELD(c, unsigned, 28);
                if (n > FIELD(self, unsigned, 124)) {
                    Ptr32<void> g1 = lbl_804aaf48;
                    Ptr32<void> g2 = lbl_804aac54;
                    FIELD(g1, int, 432) = zero;
                    FIELD(g2, unsigned, 96) |= 0x400000;
                    { Ptr32<void> o = FIELD(c, void *, 60); ((Ptr32<void (Ptr32<void>)>)(*(Ptr32<Ptr32<Ptr32<void>>>)o)[11])(o); }
                    if (lbl_804abab4) fn_801298cc(lbl_804b1788);
                    { Ptr32<Msg> m = fn_801613f0(lbl_804b1754, 12);
                    fn_8016239c(fn_800a82f0(m, fn_8015f5a0(&lbl_804b078c, 1), 0)); }
                    { Ptr32<Msg> m = fn_801613f0(lbl_804b1754, 8);
                    m->id = fn_8015f5a0(&lbl_804b0714, 1);
                    m->type = lbl_8040db38;
                    fn_8016239c(m); }
                    FIELD(self, int, 92) = zero;
                }
            }
        }
    }
}

}
