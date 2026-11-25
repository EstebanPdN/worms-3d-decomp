// Inferred worm participation flags: team +0xd5, alive +0xdc, health +0xaa minus damage +0xa4.
struct Cx8aWorm { unsigned char unknown00[0xa4];int damage;unsigned char unknowna8[2];unsigned short health;unsigned char unknownac[0x29];unsigned char team;unsigned char unknownd6[6];int active; };
extern "C" Cx8aWorm *worm_800fc6dc(int);
extern "C" int w3d_cx8a_multiple_active_teams_8008e224() {
 int teams[4];int *cursor=teams;int remaining=4;do{cursor[remaining-1]=0;}while(--remaining);
 for(int i=0;i<16;++i){Cx8aWorm *w=worm_800fc6dc(i);if(w->active && (int)(-w->damage+w->health)>0) teams[w->team]=1;}
 int count=0;cursor=teams;remaining=4;do{if(*cursor++)++count;}while(--remaining);return count>1;
}
