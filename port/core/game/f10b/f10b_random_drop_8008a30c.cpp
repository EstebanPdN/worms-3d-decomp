#include "w3d_ptr.h"
#line 1 "f10b_random_drop_8008a30c.cpp"
struct F10DropType{char p[20];Ptr32<F10DropType> parent;};
struct F10DropOwner{Ptr32<Ptr32<void>> vtable;char p[352];unsigned logContext[6];Ptr32<void> crateCount;};
struct F10DropScheme{char p[300];int health,utility,weapon;};struct F10DropPot{char p[40];int mode;};
extern F10DropType type_80361860[],type_803618f0[];
extern const char randompos_8037da18[],delay_8037d9f4[],camera_8037dad8[],scheme_8037daf4[],pot_8037db04[],health_8037db0c[],count_8037d930[],type_8037da60[],shower_8037da08[],nodrop_8037db24[],file_8037db3c[];
extern Ptr32<const char> health_804aab40; extern Ptr32<const char> weapon_804aab44; extern Ptr32<const char> utility_804aab48;
extern "C" void defaults_8008a044(Ptr32<F10DropOwner>);
extern "C" int teams_8008c34c(Ptr32<F10DropOwner>),get_80178c48(Ptr32<void>),active_8008e224(Ptr32<F10DropOwner>),set_800fc3b0(Ptr32<Ptr32<const char>>,int),read_800fc330(Ptr32<Ptr32<const char>>,Ptr32<void>),number_800fc1f0(Ptr32<Ptr32<const char>>,Ptr32<int>),text_800fc550(Ptr32<Ptr32<const char>>,Ptr32<const char>),weapon_8008a66c(Ptr32<F10DropOwner>,Ptr32<F10DropScheme>),utility_8008a76c(Ptr32<F10DropOwner>,Ptr32<F10DropScheme>),append_80089eec(Ptr32<F10DropOwner>);extern "C" unsigned random_80162ba8();extern "C" int log_80022e20(Ptr32<const char>,Ptr32<const char>,int,Ptr32<void>);
inline bool drop_type0(Ptr32<F10DropOwner> s){Ptr32<F10DropType> p=((Ptr32<Ptr32<F10DropType> (Ptr32<F10DropOwner>)>)s->vtable[5])(s);while(p!=type_80361860){if(p==p->parent)return false;p=p->parent;}return true;}
inline bool drop_type1(Ptr32<F10DropOwner> s){Ptr32<F10DropType> p=((Ptr32<Ptr32<F10DropType> (Ptr32<F10DropOwner>)>)s->vtable[5])(s);while(p!=type_803618f0){if(p==p->parent)return false;p=p->parent;}return true;}

inline int drop_boolean(int v){int n=0;if(v)n=1;return n;}
extern "C" void f10b_random_drop_8008a30c(Ptr32<F10DropOwner> s,int delay,int shower,int camera){int teams=teams_8008c34c(s);int result=0;int crates=get_80178c48(s->crateCount);if(teams<crates&&active_8008e224(s)){
 defaults_8008a044(s);Ptr32<const char> p0=randompos_8037da18;set_800fc3b0(&p0,1);Ptr32<const char> p1=delay_8037d9f4;set_800fc3b0(&p1,delay);Ptr32<const char> p2=camera_8037dad8;set_800fc3b0(&p2,drop_boolean(camera));
 Ptr32<const char> p3=scheme_8037daf4;Ptr32<F10DropScheme> schemeResult;read_800fc330(&p3,&schemeResult);Ptr32<F10DropScheme> scheme=schemeResult;Ptr32<const char> p4=pot_8037db04;Ptr32<F10DropPot> pot;read_800fc330(&p4,&pot);
 int health;if(pot->mode)health=100;else health=scheme->health*25;int weapon;if(shower){weapon=100;health=0;}else weapon=scheme->weapon*25;int utility;if(shower)utility=25;else utility=scheme->utility*25;
 unsigned total=0;if(health>0)total=100;if(weapon>0)total+=100;if(utility>0)total+=100;
 if(total){unsigned random=random_80162ba8();int pick;if(shower)pick=random%(unsigned)(health+weapon+utility);else pick=random%total;
 if(pick<health){Ptr32<const char> p5=health_8037db0c;int amount;result=1;number_800fc1f0(&p5,&amount);Ptr32<const char> p6=count_8037d930;set_800fc3b0(&p6,amount);Ptr32<const char> p7=type_8037da60;text_800fc550(&p7,health_804aab40);}
 else if(pick<health+weapon){Ptr32<const char> p8=type_8037da60;text_800fc550(&p8,weapon_804aab44);result=weapon_8008a66c(s,scheme);}
 else if(pick<health+weapon+utility){Ptr32<const char> p9=type_8037da60;text_800fc550(&p9,utility_804aab48);result=utility_8008a76c(s,scheme);}}}
 if(!result){if(drop_type0(s)||drop_type1(s))log_80022e20(nodrop_8037db24,file_8037db3c,869,s->logContext);}
 else{if(shower){Ptr32<const char> p10=shower_8037da08;set_800fc3b0(&p10,1);}append_80089eec(s);defaults_8008a044(s);}}


