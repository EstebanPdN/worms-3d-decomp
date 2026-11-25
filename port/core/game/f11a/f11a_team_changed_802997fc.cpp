#include "w3d_ptr.h"
#line 1 "f11a_team_changed_802997fc.cpp"
// Partial team state and property views; roles inferred.
// Only pointer words are observed. The trailing name[1] is a partial view into caller-owned variable storage;
// no complete state/name-container allocation or unknown-slot semantics is claimed.
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F11aTeamText_803426b8{
 F11aTeamText_803426b8(const F11aTeamText_803426b8 &);Ptr32<char> text;F11aTeamText_803426b8();~F11aTeamText_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct F11aTeamIface{Ptr32<Ptr32<void>> table;};
struct F11aTeamHeld{
 F11aTeamHeld(const F11aTeamHeld &);Ptr32<F11aTeamIface> p;F11aTeamHeld():p(0){}~F11aTeamHeld(){if(p)((Ptr32<void (Ptr32<F11aTeamIface>)>)p->table[4])(p);}};
struct F11aTeamKey{Ptr32<const char> text;template <class W3dU> F11aTeamKey(Ptr32<W3dU> w3d_p) : F11aTeamKey((const char *)w3d_p.get()) {}
 F11aTeamKey(const char*p):text(p){}};
struct F11aTeamNames{char unknown[24];unsigned count;char unknown28[4];Ptr32<char> name[1];};
struct F11aTeamState{char unknown[24];Ptr32<char> speech; Ptr32<char> flag;int weapon,grave,skill;char unknown44[12];Ptr32<F11aTeamNames> names;};
extern char key_803d0940[],key_803d0a20[],key_803d0a2c[],key_803d0a54[],key_803d0a0c[],key_803d0a3c[],key_803d0a48[];
extern "C" int fn_800fc1b0(const F11aTeamKey&,F11aTeamHeld&),fn_800fc230(const F11aTeamKey&,int&),fn_800fc2b0(const F11aTeamKey&,Ptr32<const char> &),fn_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" Ptr32<F11aTeamIface> fn_80341584(Ptr32<F11aTeamIface>);
extern "C" Ptr32<F11aTeamState> fn_801797b4(Ptr32<F11aTeamIface>);
extern "C" void fn_8020c510(Ptr32<void>,Ptr32<const char>,...);
extern "C" Ptr32<F11aTeamText_803426b8> fn_8020bd38(Ptr32<F11aTeamText_803426b8>,Ptr32<const char>);
inline bool differs(F11aTeamText_803426b8&text,Ptr32<const char> other){return fn_802ef234(text.text,other)!=0;}
extern "C" bool w3d_f11a_team_changed_802997fc(){
 bool changed=false;F11aTeamHeld held;F11aTeamKey store(key_803d0940);
 if(fn_800fc1b0(store,held)<0)return false;
 Ptr32<F11aTeamState> state=fn_801797b4(fn_80341584(held.p));
 F11aTeamKey grave(key_803d0a20);int number;fn_800fc230(grave,number);if(state->grave!=number)changed=true;
 F11aTeamKey weapon(key_803d0a2c);fn_800fc230(weapon,number);if(state->weapon!=number)changed=true;
 F11aTeamKey skill(key_803d0a54);fn_800fc230(skill,number);if(state->skill!=number)changed=true;
 F11aTeamText_803426b8 value;unsigned i=0;unsigned count=state->names->count;Ptr32<Ptr32<char>> names=state->names->name;F11aTeamText_803426b8 name;
 for(;i<count;){unsigned next=i+1;fn_8020c510(&name,key_803d0a0c,next);F11aTeamKey worm(name.text);Ptr32<const char> text;fn_800fc2b0(worm,text);if(fn_802ef234(names[i],text))changed=true;i=next;}
 F11aTeamKey flag(key_803d0a3c);Ptr32<const char> text;fn_800fc2b0(flag,text);fn_8020bd38(&value,text);if(differs(value,state->flag))changed=true;
 F11aTeamKey speech(key_803d0a48);fn_800fc2b0(speech,text);fn_8020bd38(&value,text);if(differs(value,state->speech))changed=true;
 return changed;
}


