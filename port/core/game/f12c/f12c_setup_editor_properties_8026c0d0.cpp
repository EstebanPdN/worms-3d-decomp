#include "w3d_ptr.h"
#line 1 "f12c_setup_editor_properties_8026c0d0.cpp"
// Observed property-subscription members; original complete editor class remains external.
struct F12cSetupIface { Ptr32<Ptr32<void>> table; };
struct F12cSetupHeld {Ptr32<F12cSetupIface> p;void clear(Ptr32<F12cSetupIface> zero){if(p)((Ptr32<void (Ptr32<F12cSetupIface>)>)p->table[4])(p);p=zero;}};
struct F12cSetupOwner {char unknown0[452];F12cSetupHeld amount,bridges,largeObjects,smallObjects,size,seed,space,height,time,theme,realSeed;};
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F12cSetupText_8020bb54 {Ptr32<char> p;int unknown;template <class W3dU> F12cSetupText_8020bb54(Ptr32<W3dU> w3d_p) : F12cSetupText_8020bb54((const char *)w3d_p.get()) {}
 F12cSetupText_8020bb54(const char*);~F12cSetupText_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}};
extern "C" int fn_800fd62c(Ptr32<void>,Ptr32<void>,Ptr32<void>,Ptr32<void>);
extern const char name_803cb980[];extern "C" void callback_80269dd0();
extern const char name_803cb8f8[];extern "C" void callback_802699e8();
extern const char name_803cb908[];extern "C" void callback_80269a64();
extern const char name_803cb918[];extern "C" void callback_80269ae0();
extern const char name_803cb92c[];extern "C" void callback_80269b5c();
extern const char name_803cb940[];extern "C" void callback_80269bd8();
extern const char name_803cb950[];extern "C" void callback_80269c54();
extern const char name_803cb960[];extern "C" void callback_80269cd8();
extern const char name_803cb970[];extern "C" void callback_80269d54();
extern const char name_803cb990[];extern "C" void callback_80269e34();
extern const char name_803cb8bc[];extern "C" void callback_80269f90();
extern "C" void w3d_f12c_setup_editor_properties_8026c0d0(Ptr32<F12cSetupOwner> s,int active){
F12cSetupHeld &time=s->time;
if(!time.p){F12cSetupText_8020bb54 text(name_803cb980);fn_800fd62c(&text,(Ptr32<void>)callback_80269dd0,s,&time);}
if(!active){
s->amount.clear(0);
s->bridges.clear(0);
s->largeObjects.clear(0);
s->smallObjects.clear(0);
s->size.clear(0);
s->seed.clear(0);
s->space.clear(0);
s->height.clear(0);
s->theme.clear(0);
s->realSeed.clear(0);
}else {F12cSetupHeld &amount=s->amount;if(!amount.p){
{F12cSetupText_8020bb54 text(name_803cb8f8);fn_800fd62c(&text,(Ptr32<void>)callback_802699e8,s,&amount);}
{F12cSetupText_8020bb54 text(name_803cb908);fn_800fd62c(&text,(Ptr32<void>)callback_80269a64,s,&s->bridges);}
{F12cSetupText_8020bb54 text(name_803cb918);fn_800fd62c(&text,(Ptr32<void>)callback_80269ae0,s,&s->largeObjects);}
{F12cSetupText_8020bb54 text(name_803cb92c);fn_800fd62c(&text,(Ptr32<void>)callback_80269b5c,s,&s->smallObjects);}
{F12cSetupText_8020bb54 text(name_803cb940);fn_800fd62c(&text,(Ptr32<void>)callback_80269bd8,s,&s->size);}
{F12cSetupText_8020bb54 text(name_803cb950);fn_800fd62c(&text,(Ptr32<void>)callback_80269c54,s,&s->seed);}
{F12cSetupText_8020bb54 text(name_803cb960);fn_800fd62c(&text,(Ptr32<void>)callback_80269cd8,s,&s->space);}
{F12cSetupText_8020bb54 text(name_803cb970);fn_800fd62c(&text,(Ptr32<void>)callback_80269d54,s,&s->height);}
{F12cSetupText_8020bb54 text(name_803cb990);fn_800fd62c(&text,(Ptr32<void>)callback_80269e34,s,&s->theme);}
{F12cSetupText_8020bb54 text(name_803cb8bc);fn_800fd62c(&text,(Ptr32<void>)callback_80269f90,s,&s->realSeed);}
}
}
}


