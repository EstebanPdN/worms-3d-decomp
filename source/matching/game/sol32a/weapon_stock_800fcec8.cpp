// Partial layouts inferred only for the GC32 reference ABI.
struct Sol32aWorm {unsigned char unknown0[132];int weapon;unsigned char unknown136[77];unsigned char team;int teamIndex()const{return team;}};
struct Sol32aTeam {unsigned char unknown0[60];unsigned char alliance;int allianceIndex()const{return alliance;}};
struct Sol32aUnsignedProperty; struct Sol32aSignedProperty;
struct Sol32aPropertyName {const char *text;Sol32aPropertyName(const char *s):text(s){}};
extern "C" int readIndex_800fc1f0(Sol32aPropertyName *,int *);
extern "C" int readProperty_800fc330(Sol32aPropertyName *,Sol32aUnsignedProperty **);
extern "C" Sol32aWorm *worm_800fc6dc(int);
extern "C" Sol32aTeam *team_800fc7f8(int);
extern "C" unsigned delay_8025c3a8(Sol32aUnsignedProperty *,int);
extern "C" int enabled_800fd014(Sol32aWorm *,int);
extern "C" Sol32aSignedProperty *wormStock_800fca30(int);
extern "C" Sol32aSignedProperty *teamStock_800fcc68(int);
extern "C" Sol32aSignedProperty *allianceStock_800fcd84(int);
extern "C" int stock_8025cbe0(Sol32aSignedProperty *,int);
inline bool hasDelay(Sol32aUnsignedProperty *p,int w){return delay_8025c3a8(p,w)!=0;}
extern "C" int sol32a_weapon_stock_800fcec8(int index,int weapon){
 if(index==-1){Sol32aPropertyName key("ActiveWormIndex");readIndex_800fc1f0(&key,&index);}
 Sol32aWorm *worm=worm_800fc6dc(index);
 Sol32aTeam *team=team_800fc7f8(worm->teamIndex());
 if(weapon==60)weapon=worm->weapon;
 Sol32aUnsignedProperty *delays;
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
typedef char Sol32aStockPointer32[sizeof(void*)==4?1:-1];
typedef char Sol32aStockInt32[sizeof(int)==4?1:-1];
typedef char Sol32aStockWormTeamOffset[(unsigned)&((Sol32aWorm*)0)->team==213?1:-1];
typedef char Sol32aStockWeaponOffset[(unsigned)&((Sol32aWorm*)0)->weapon==132?1:-1];
typedef char Sol32aStockTeamAllianceOffset[(unsigned)&((Sol32aTeam*)0)->alliance==60?1:-1];
