#include "w3d_ptr.h"
#line 1 "sol34c_bind_selected_weapon_802a75ec.cpp"
// GWMP8P GC32 observed resource lookup and binding. No original type names.
struct Sol34cWeaponIface { Ptr32<Ptr32<void>> table; };
struct Sol34cWeaponHeld {
 Ptr32<Sol34cWeaponIface> pointer;
 Sol34cWeaponHeld():pointer(0) {}
 ~Sol34cWeaponHeld() { if(pointer) ((Ptr32<void (Ptr32<Sol34cWeaponIface>)>)pointer->table[4])(pointer); }
 void clear(Ptr32<Sol34cWeaponIface> next) { if(pointer) ((Ptr32<void (Ptr32<Sol34cWeaponIface>)>)pointer->table[4])(pointer); pointer=next; }
};
struct Sol34cWeaponText;
extern "C" void sol34c_weapon_string_init_8020c5c0(Ptr32<Sol34cWeaponText>);
extern "C" Ptr32<unsigned short> sol34c_weapon_string_header_80341884(Ptr32<Sol34cWeaponText>);
extern "C" void sol34c_weapon_string_finish_8020c5c4(Ptr32<Sol34cWeaponText>);
extern "C" void sol34c_weapon_string_release_80341588(Ptr32<Sol34cWeaponText>);
struct Sol34cWeaponText {
 Ptr32<char> data;
 Sol34cWeaponText(const Sol34cWeaponText &x) {
  sol34c_weapon_string_init_8020c5c0(this); data=x.data;
  ++*sol34c_weapon_string_header_80341884(this);
 }
 ~Sol34cWeaponText() { sol34c_weapon_string_finish_8020c5c4(this); sol34c_weapon_string_release_80341588(this); }
 unsigned short length() const { return *(Ptr32<unsigned short>)(data-4); }
};
struct Sol34cWeaponKey { Ptr32<const char> data; template <class W3dU> Sol34cWeaponKey(Ptr32<W3dU> w3d_p) : Sol34cWeaponKey((const char *)w3d_p.get()) {}
 Sol34cWeaponKey(const char *p):data(p) {} };
struct Sol34cWeaponDescriptor { unsigned words[5]; Ptr32<Sol34cWeaponDescriptor> parent; };
struct Sol34cWeaponState {
 unsigned words0[27]; Sol34cWeaponText error;
 unsigned words112[66]; Sol34cWeaponHeld held;
 unsigned words380[20]; Sol34cWeaponText names[31];
 unsigned count; unsigned words588[3]; unsigned selected;
};
extern "C" int sol34c_weapon_lookup_800fc1b0(Ptr32<Sol34cWeaponKey>,Ptr32<Sol34cWeaponHeld>);
extern "C" void sol34c_weapon_format_8020c510(Ptr32<Sol34cWeaponText>,Ptr32<const char>,...);
extern "C" Ptr32<Sol34cWeaponIface> sol34c_weapon_identity_80341584(Ptr32<Sol34cWeaponIface>);
extern "C" Ptr32<Sol34cWeaponIface> sol34c_weapon_resource_801797b4(Ptr32<Sol34cWeaponIface>);
extern "C" int sol34c_weapon_callback_802a75a0(Ptr32<void>,Ptr32<Sol34cWeaponState>);
extern "C" int sol34c_weapon_bind_800fd62c(Ptr32<Sol34cWeaponText>,Ptr32<int (Ptr32<void>, Ptr32<Sol34cWeaponState>)>,Ptr32<Sol34cWeaponState>,Ptr32<Sol34cWeaponHeld>);
extern Sol34cWeaponDescriptor sol34c_weapon_type_80366578[];
extern const char sol34c_weapon_error_803d6188[];
inline bool sol34c_weapon_is_type(Ptr32<Sol34cWeaponDescriptor> type,Ptr32<Sol34cWeaponDescriptor> base) {
 while(type!=base) { Ptr32<Sol34cWeaponDescriptor> parent=type->parent; if(type==parent)return false; type=parent; }
 return true;
}
typedef char Sol34cWeaponStateSize[(sizeof(Sol34cWeaponState)==604)?1:-1];
typedef char Sol34cWeaponTextSize[(sizeof(Sol34cWeaponText)==4)?1:-1];
extern "C" void sol34c_bind_selected_weapon_802a75ec(Ptr32<Sol34cWeaponState> self) {
 self->held.clear(0);
 if(self->selected<self->count && (*(Ptr32<Sol34cWeaponText>)((Ptr32<char>)self+self->selected*4+460)).length()) {
  Sol34cWeaponHeld held;
  Sol34cWeaponKey key((*(Ptr32<Sol34cWeaponText>)((Ptr32<char>)self+self->selected*4+460)).data);
  if(sol34c_weapon_lookup_800fc1b0(&key,&held)<0) {
   { Sol34cWeaponText temporary((*(Ptr32<Sol34cWeaponText>)((Ptr32<char>)self+self->selected*4+460))); }
   sol34c_weapon_format_8020c510(&self->error,sol34c_weapon_error_803d6188,w3d::VA((*(Ptr32<Sol34cWeaponText>)((Ptr32<char>)self+self->selected*4+460)).data));
  } else if(((Ptr32<int (Ptr32<Sol34cWeaponIface>)>)held.pointer->table[6])(held.pointer)==5) {
   Ptr32<Sol34cWeaponIface> resource=sol34c_weapon_resource_801797b4(sol34c_weapon_identity_80341584(held.pointer));
   Ptr32<Sol34cWeaponDescriptor> type=((Ptr32<Ptr32<Sol34cWeaponDescriptor> (Ptr32<Sol34cWeaponIface>)>)resource->table[5])(resource);
   if(sol34c_weapon_is_type(type,sol34c_weapon_type_80366578))
    sol34c_weapon_bind_800fd62c((Ptr32<Sol34cWeaponText>)((Ptr32<char>)self+(self->selected*4+460)),sol34c_weapon_callback_802a75a0,self,&self->held);
  }
 }
}


