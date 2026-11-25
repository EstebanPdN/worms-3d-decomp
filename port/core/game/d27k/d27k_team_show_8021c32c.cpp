#include "w3d_ptr.h"
#line 1 "d27k_team_show_8021c32c.cpp"
// Team panel show (Worms 3D GameCube PAL, 0x8021c32c).
// 
// Reads the CurrentTeamIndex setting; for a valid index enters the app state when not yet running
// and sets the shown flag. A team with a member dispatches its property with the current time, clears
// the start time and posts 0; otherwise a pending dispatch is flushed and 1 is posted. The constant one is
// an inline parameter (kept in a saved register); the start time store goes through a plain pointer.

typedef unsigned short u16;
struct Msg;
struct TeamState { int pad[5]; int startTime; };
struct Owner { char pad[24]; Ptr32<TeamState> state; };
struct Panel { char pad0[36]; Ptr32<Owner> owner; };
struct TeamEntry { char pad[32]; int member; };
struct EngineCtx { char pad[52]; int now; };
struct Cfg { char p0[96]; unsigned int pad1:22; unsigned int flag:1; unsigned int pad0:9; };
struct Ctl { char pad[432]; int w432; };
extern const char text_803b3efc[];
extern Ptr32<void> global_804b1788;
extern Ptr32<void> global_804b1754;
extern Ptr32<Cfg> global_804aac54;
extern Ptr32<Ctl> global_804aaf48;
extern int global_804abab4, global_804abab8;
extern char global_804b078c;
struct Key { Ptr32<const char> name; };
extern "C" int fn_800fc1f0(Ptr32<Key>, Ptr32<int>);
extern "C" Ptr32<TeamEntry> fn_800fc7f8(int);
extern "C" int fn_8015ccbc(Ptr32<void>);
extern "C" void fn_80129878(Ptr32<void>);
extern "C" Ptr32<Msg> fn_801613f0(Ptr32<void>, int);
extern "C" int fn_8015f5a0(Ptr32<void>, int);
extern "C" Ptr32<Msg> fn_800a82f0(Ptr32<Msg>, u16, int);
extern "C" int fn_8016239c(Ptr32<Msg>);
extern "C" Ptr32<EngineCtx> fn_80165254(void);
extern "C" void fn_8021c294(Ptr32<Panel>, int);
inline void post(int v) { Ptr32<Msg> m = fn_801613f0(global_804b1754, 12); fn_8016239c(fn_800a82f0(m, fn_8015f5a0(&global_804b078c, 1), v)); }
inline void run(Ptr32<Panel> self, Ptr32<TeamEntry> e, int one) {
    global_804abab4 = one;
    fn_80165254();
    int member = e->member;
    if (member) {
        global_804aaf48->w432 = one;
        fn_8021c294(self, fn_80165254()->now);
        global_804aac54->flag = one;
        global_804abab8 = one;
        Ptr32<int> start = &self->owner->state->startTime; *start = 0;
        post(0);
    } else {
        if (global_804abab8) { global_804abab8 = 0; fn_8021c294(self, -1); }
        global_804aac54->flag = one;
        global_804aaf48->w432 = 0;
        post(1);
    }
}
extern "C" void w3d_d27k_team_show_8021c32c(Ptr32<Panel> self) {
    int index = -1;
    Key k;
    k.name = text_803b3efc;
    fn_800fc1f0(&k, &index);
    if (index != -1) {
        Ptr32<TeamEntry> e = fn_800fc7f8(index);
        if (fn_8015ccbc(global_804b1788) == 0) fn_80129878(global_804b1788);
        run(self, e, 1);
    }
}


