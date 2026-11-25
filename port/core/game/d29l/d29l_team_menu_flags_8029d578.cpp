#include "w3d_ptr.h"
#line 1 "d29l_team_menu_flags_8029d578.cpp"
// GWMP8P rev0 0x8029d578. Team menu refresh: reads User.Skill, the team
// state queries and the User.Human slots, then sets the TM.Skill, TM.Add,
// TM.Delete, TM.Accept, TM.Team and TM.Flag menu flags. Field and flag roles
// come from the original strings; flag variable names are inferred. The two
// empty tests hold the compares the original keeps in condition registers
// across the calls.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>);
struct Str;
extern "C" void fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
struct Str {
    Ptr32<char> p;
    Str();
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &);
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
    void assign(Ptr32<const char> v) { fn_8020bd38(this, v); }
    Ptr32<const char> cstr() const { return p; } unsigned short len() const { return *(Ptr32<unsigned short>)(p - 4); }
};
struct Key { Ptr32<const char> p; };
extern "C" int fn_800fc230(Ptr32<const Key>, Ptr32<unsigned int>);
extern "C" int fn_800fc2b0(Ptr32<const Key>, Ptr32<Ptr32<const char>>);
extern "C" int fn_802997fc(Ptr32<void>), fn_80299a94(Ptr32<void>), fn_8029d7b4(Ptr32<void>), fn_8029d89c(Ptr32<void>);
extern "C" void fn_8020c510(Ptr32<Str>, Ptr32<const char>, ...);
extern "C" void fn_80299b48(Ptr32<void>, Str, int);
extern const char skill_803d0a54[], worm_803d0a0c[], menuSkill_803d0d7c[], menuAdd_803d0d88[], menuDelete_803d0d90[], menuAccept_803d0d9c[], menuTeam_803d0da8[], menuFlag_803d0db0[];
extern "C" void d29l_team_menu_flags_8029d578(Ptr32<void> self) {
    int team = 0;
    Key sk;
    sk.p = skill_803d0a54;
    unsigned skill = team;
    fn_800fc230(&sk, &skill);
    int a = 0, b = 0, c = 0, d = 0;
    int sel = fn_802997fc(self);
    int exists = fn_80299a94(self);
    int full = fn_8029d7b4(self);
    if (fn_8029d89c(self)) sel = 1;
    if (sel) {}
    Str name;
    if (full) {}
    int five = 1;
    for (unsigned i = 0; i <= 5; i++) {
        unsigned n = i + 1;
        fn_8020c510(&name, worm_803d0a0c, n);
        Key k; k.p = name.cstr();
        Ptr32<const char> v;
        fn_800fc2b0(&k, &v);
        name.assign(v);
        if (!name.len() || *v == ' ') { five = 0; break; }
        i = n - 1;
    }
    if (full) a = 1;
    if (!sel) {
        if (exists) b = 1;
        c = 1;
        goto setTeam;
    }
    if (five) d = 1;
    goto done;
setTeam:
    team = 1;
done:
    fn_80299b48(self, Str(menuSkill_803d0d7c), a);
    fn_80299b48(self, Str(menuAdd_803d0d88), b);
    fn_80299b48(self, Str(menuDelete_803d0d90), c);
    fn_80299b48(self, Str(menuAccept_803d0d9c), d);
    fn_80299b48(self, Str(menuTeam_803d0da8), team);
    fn_80299b48(self, Str(menuFlag_803d0db0), skill);
}


