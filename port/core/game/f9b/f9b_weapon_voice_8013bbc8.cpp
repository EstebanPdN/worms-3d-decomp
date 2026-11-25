#include "w3d_ptr.h"
#line 1 "f9b_weapon_voice_8013bbc8.cpp"
struct F9VoiceOwner{char p[112];int index;};struct F9VoiceRecord{char p[132];unsigned weapon;};
extern const char option_8039f824[],a_8039f834[],watch_8039f83c[],dragon_8039f848[],fireball_8039f854[],incoming_8039f860[],orders_8039f86c[],yes_8039f874[],laugh_8039f190[];
extern "C" int get_800fc230(Ptr32<Ptr32<const char>>,Ptr32<int>);extern "C" Ptr32<F9VoiceRecord> record_800fc6dc(int);extern "C" unsigned random_80162c20();extern "C" void say_8013bd0c(Ptr32<F9VoiceOwner>,Ptr32<const char>);
extern "C" void f9b_weapon_voice_8013bbc8(Ptr32<F9VoiceOwner> s){int voices=1;Ptr32<const char> option=option_8039f824;get_800fc230(&option,&voices);if(!voices)return;unsigned weapon=record_800fc6dc(s->index)->weapon;unsigned random=random_80162c20()&1;Ptr32<const char> line;switch(weapon){case 0:case 1:case 2:case 5:case 6:case 20:case 21:if(random==0)line=a_8039f834;else line=watch_8039f83c;break;case 13:if(random==0)line=dragon_8039f848;else line=fireball_8039f854;break;case 3:line=incoming_8039f860;break;case 4:case 7:case 33:line=laugh_8039f190;break;case 47:if((random_80162c20()&1)==0)line=orders_8039f86c;else line=yes_8039f874;break;default:return;}say_8013bd0c(s,line);}


