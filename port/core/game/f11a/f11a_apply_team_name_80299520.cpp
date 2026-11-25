#include "w3d_ptr.h"
#line 1 "f11a_apply_team_name_80299520.cpp"
// Inferred by-value text ABI and partial handle/property views.
// Only pointer words are accessed. No full external type, allocation size, or unused-word meaning claimed.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct F11aNameText{Ptr32<char> text;F11aNameText(const F11aNameText&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}~F11aNameText(){fn_8020c5c4(this);fn_80341588(this);}};
struct F11aNameIface{Ptr32<Ptr32<void>> table;};struct F11aNameHeld{Ptr32<F11aNameIface> p;int unobserved;F11aNameHeld():p(0){}~F11aNameHeld(){if(p)((Ptr32<void (Ptr32<F11aNameIface>)>)p->table[4])(p);}};
struct F11aNameKey{Ptr32<const char> text;template <class W3dU> F11aNameKey(Ptr32<W3dU> w3d_p) : F11aNameKey((const char *)w3d_p.get()) {}
 F11aNameKey(const char*p):text(p){}};
extern char key_803d0a54[],key_803d0b88[];
extern "C" int fn_800fc43c(const F11aNameKey&,int),fn_800fc1f0(const F11aNameKey&,int&),fn_802997fc(Ptr32<void>);
extern "C" void fn_80299b48(Ptr32<void>,F11aNameText,bool);
extern "C" void w3d_f11a_apply_team_name_80299520(Ptr32<void> self,F11aNameText name){
 if(!*(Ptr32<unsigned short>)(name.text-4)){F11aNameKey skill(key_803d0a54);fn_800fc43c(skill,0);}
 else{bool changed=false;F11aNameHeld held;changed=fn_802997fc(self)==1;if(changed==true){int permission=0;F11aNameKey key(key_803d0b88);fn_800fc1f0(key,permission);if(permission==1)changed=false;}fn_80299b48(self,name,changed);}
}


