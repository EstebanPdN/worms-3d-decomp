#include "w3d_ptr.h"
#line 1 "weapon_stock_800fcec8.cpp"
// Partial layouts inferred only for the GC32 reference ABI.
struct Sol32aWorm {unsigned char unknown0[132];int weapon;unsigned char unknown136[77];unsigned char team;int teamIndex()const{return team;}};
struct Sol32aTeam {unsigned char unknown0[60];unsigned char alliance;int allianceIndex()const{return alliance;}};
struct Sol32aUnsignedProperty; struct Sol32aSignedProperty;
struct Sol32aPropertyName {Ptr32<const char> text;template <class W3dU> Sol32aPropertyName(Ptr32<W3dU> w3d_p) : Sol32aPropertyName((const char *)w3d_p.get()) {}
 Sol32aPropertyName(const char *s):text(s){}};
extern "C" int readIndex_800fc1f0(Ptr32<Sol32aPropertyName>,Ptr32<int>);
extern "C" int readProperty_800fc330(Ptr32<Sol32aPropertyName>,Ptr32<Ptr32<Sol32aUnsignedProperty>>);
extern "C" Ptr32<Sol32aWorm> worm_800fc6dc(int);
extern "C" Ptr32<Sol32aTeam> team_800fc7f8(int);
extern "C" unsigned delay_8025c3a8(Ptr32<Sol32aUnsignedProperty>,int);
extern "C" int enabled_800fd014(Ptr32<Sol32aWorm>,int);
extern "C" Ptr32<Sol32aSignedProperty> wormStock_800fca30(int);
extern "C" Ptr32<Sol32aSignedProperty> teamStock_800fcc68(int);
extern "C" Ptr32<Sol32aSignedProperty> allianceStock_800fcd84(int);
extern "C" int stock_8025cbe0(Ptr32<Sol32aSignedProperty>,int);
inline bool hasDelay(Ptr32<Sol32aUnsignedProperty> p,int w){return delay_8025c3a8(p,w)!=0;}
extern "C" int sol32a_weapon_stock_800fcec8(int index,int weapon){
 if(index==-1){Sol32aPropertyName key("ActiveWormIndex");readIndex_800fc1f0(&key,&index);}
 Ptr32<Sol32aWorm> worm=worm_800fc6dc(index);
 Ptr32<Sol32aTeam> team=team_800fc7f8(worm->teamIndex());
 if(weapon==60)weapon=worm->weapon;
 Ptr32<Sol32aUnsignedProperty> delays;
 Sol32aPropertyName key("Inventory.WeaponDelays");readProperty_800fc330(&key,&delays);
 if(hasDelay(delays,weapon)||!enabled_800fd014(worm,weapon))return 0;
 int amount=stock_8025cbe0(wormStock_800fca30(index),weapon);
 int t=worm->teamIndex();
 if(t>=0){int n=stock_8025cbe0(teamStock_800fcc68(t),weapon);if(amount==-1||n==-1)amount=-1;else amount+=n;}
 int a=team->allianceIndex();
 if(a>=0){int n=stock_8025cbe0(allianceStock_800fcd84(a),weapon);if(amount==-1||n==-1)amount=-1;else amount+=n;}
 return amount;
}

// These are reference ABI observations, not a portable class definition.
typedef char Sol32aStockPointer32[sizeof(Ptr32<void>)==4?1:-1];
typedef char Sol32aStockInt32[sizeof(int)==4?1:-1];
typedef char Sol32aStockWormTeamOffset[__builtin_offsetof(Sol32aWorm,team)==213?1:-1];
typedef char Sol32aStockWeaponOffset[__builtin_offsetof(Sol32aWorm,weapon)==132?1:-1];
typedef char Sol32aStockTeamAllianceOffset[__builtin_offsetof(Sol32aTeam,alliance)==60?1:-1];


