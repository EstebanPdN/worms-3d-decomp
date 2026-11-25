#include "w3d_ptr.h"
#line 1 "f9b_choose_weapon_crate_8008a66c.cpp"
struct F9WeaponCrateChoice{int weight,id;};extern F9WeaponCrateChoice weights_80431c80[];extern Ptr32<const char> weapons_803eb63c[];extern const char contents_8037da74[];
extern "C" unsigned total_8008da24(),random_80162ba8();extern const char count_8037d930[];extern "C" int count_800fc3b0(Ptr32<Ptr32<const char>>,int);extern "C" int set_800fc550(Ptr32<Ptr32<const char>>,Ptr32<const char>);
extern "C" int f9b_choose_weapon_crate_8008a66c(){unsigned total=total_8008da24();if(!total)return 0;int choice;if(total==1)choice=0;else choice=random_80162ba8()%total;bool found=false;int index=0;int sum=weights_80431c80[0].weight;goto test;scan:index+=2;if(index>38)goto scanned;sum+=weights_80431c80[index].weight;test:if(choice>=sum)goto scan;found=true;scanned:if(!found)return 0;if(weights_80431c80[index].id==23){Ptr32<const char> property=count_8037d930;count_800fc3b0(&property,3);}Ptr32<const char> property=contents_8037da74;set_800fc550(&property,weapons_803eb63c[weights_80431c80[index].id]);return 1;}


