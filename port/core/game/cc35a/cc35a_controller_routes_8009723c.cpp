#include "w3d_ptr.h"
#line 1 "cc35a_controller_routes_8009723c.cpp"

struct cc35a_Controller_8009723c {char prefix[20];unsigned int route;char gap[40];Ptr32<void> modeProperty;Ptr32<void> vectorProperty;};
struct cc35a_Target_8009723c {char prefix[20];unsigned int route;char gap[72];int first,second;};
struct cc35a_Worm_8009723c {char prefix[132];int weapon;};
struct cc35a_Weapon_8009723c {char prefix[160];int kind;};
extern "C" {
extern unsigned int cc35a_cache_804adf4c[2],cc35a_cache_804adf5c[2],cc35a_cache_804adf64[2],cc35a_cache_804adf6c[2],cc35a_cache_804adf74[2],cc35a_cache_804adf7c[2],cc35a_cache_804adf84[2],cc35a_cache_804adf8c[2];
extern char cc35a_type_8040ea30[],cc35a_type_8040dfb8[],cc35a_type_8040ef18[],cc35a_type_8040e420[],cc35a_type_804108f8[],cc35a_type_8040ed70[];
extern const char cc35a_key_8037f508[];extern Ptr32<const char> cc35a_weapons_803eb63c[];extern Ptr32<void> cc35a_service_804b178c;
int cc35a_equal_8015f620(Ptr32<void>,unsigned short);unsigned int cc35a_handle_801190d0(Ptr32<void>);Ptr32<cc35a_Target_8009723c> cc35a_lookup_80164fc8(unsigned int);
Ptr32<cc35a_Target_8009723c> cc35a_get_8020b680(Ptr32<void>);int cc35a_route_80164514(Ptr32<void>,Ptr32<void>,unsigned int);
Ptr32<void> cc35a_cast_803426b4(Ptr32<void>);int cc35a_value_80178c48(Ptr32<void>);void cc35a_mode_8004eae4(Ptr32<void>,int);
Ptr32<void> cc35a_cast_80342fa4(Ptr32<void>);Ptr32<void> cc35a_value_80178ec4(Ptr32<void>);void cc35a_vector_8004eb34(Ptr32<void>,Ptr32<void>);
int cc35a_read_800fc1f0(Ptr32<Ptr32<const char>>,Ptr32<int>);Ptr32<cc35a_Worm_8009723c> cc35a_worm_800fc6dc(int);int cc35a_weapon_800fc330(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<cc35a_Weapon_8009723c>>);
}
inline void cc35a_activate_8009723c(Ptr32<void> type,Ptr32<cc35a_Target_8009723c> owner){Ptr32<cc35a_Target_8009723c> target=cc35a_get_8020b680(type);cc35a_route_80164514(cc35a_service_804b178c,target,owner->route);}
extern "C" void cc35a_controller_routes_8009723c(Ptr32<cc35a_Controller_8009723c> self,Ptr32<unsigned short> event){
 if(cc35a_equal_8015f620(cc35a_cache_804adf4c,*event)){
  Ptr32<cc35a_Target_8009723c> target=cc35a_get_8020b680(cc35a_type_8040ea30);cc35a_route_80164514(cc35a_service_804b178c,target,self->route);
  cc35a_mode_8004eae4(target,cc35a_value_80178c48(cc35a_cast_803426b4(self->modeProperty)));
  cc35a_vector_8004eb34(target,cc35a_value_80178ec4(cc35a_cast_80342fa4(self->vectorProperty)));
 }else if(cc35a_equal_8015f620(cc35a_cache_804adf5c,*event)){
  Ptr32<cc35a_Target_8009723c> owner=cc35a_lookup_80164fc8(cc35a_handle_801190d0(event));cc35a_activate_8009723c(cc35a_type_8040dfb8,owner);
  Ptr32<const char> key=cc35a_key_8037f508;int index;cc35a_read_800fc1f0(&key,&index);Ptr32<cc35a_Worm_8009723c> worm=cc35a_worm_800fc6dc(index);
  Ptr32<cc35a_Weapon_8009723c> weapon;cc35a_weapon_800fc330((Ptr32<Ptr32<const char>>)((worm->weapon*4)+(Ptr32<char>)cc35a_weapons_803eb63c),&weapon);
  if(weapon->kind==1)cc35a_activate_8009723c(cc35a_type_8040ef18,owner);
 }else if(cc35a_equal_8015f620(cc35a_cache_804adf64,*event)){
  Ptr32<cc35a_Target_8009723c> owner=cc35a_lookup_80164fc8(cc35a_handle_801190d0(event));cc35a_activate_8009723c(cc35a_type_8040e420,owner);
 }else if(cc35a_equal_8015f620(cc35a_cache_804adf6c,*event)){
  Ptr32<cc35a_Target_8009723c> owner=cc35a_lookup_80164fc8(cc35a_handle_801190d0(event));cc35a_activate_8009723c(cc35a_type_804108f8,owner);
 }else if(cc35a_equal_8015f620(cc35a_cache_804adf74,*event)){
  Ptr32<cc35a_Target_8009723c> owner=cc35a_lookup_80164fc8(cc35a_handle_801190d0(event));Ptr32<cc35a_Target_8009723c> target=cc35a_get_8020b680(cc35a_type_804108f8);cc35a_route_80164514(cc35a_service_804b178c,target,owner->route);target->first=1;
 }else if(cc35a_equal_8015f620(cc35a_cache_804adf7c,*event)){
  Ptr32<cc35a_Target_8009723c> owner=cc35a_lookup_80164fc8(cc35a_handle_801190d0(event));Ptr32<cc35a_Target_8009723c> target=cc35a_get_8020b680(cc35a_type_804108f8);cc35a_route_80164514(cc35a_service_804b178c,target,owner->route);target->second=1;
 }else if(cc35a_equal_8015f620(cc35a_cache_804adf84,*event)){
  cc35a_lookup_80164fc8(cc35a_handle_801190d0(event));cc35a_get_8020b680(cc35a_type_8040dfb8)->second=1;
 }else if(cc35a_equal_8015f620(cc35a_cache_804adf8c,*event)){
  Ptr32<cc35a_Target_8009723c> target=cc35a_get_8020b680(cc35a_type_8040ed70);cc35a_route_80164514(cc35a_service_804b178c,target,self->route);
 }
}


