inline void *operator new(unsigned int,void *p){return p;}
struct Cc20aVec3 {float x,y,z;Cc20aVec3(float a,float b,float c){x=a;y=b;z=c;}};
struct Cc20aArena_802097ec {unsigned int words[2];Cc20aArena_802097ec(const char*,int,int);};
extern Cc20aArena_802097ec lbl_804aeca4,lbl_804aecac;
extern Cc20aVec3 lbl_804453c8;
extern "C" char *lbl_804aae9c;
extern "C" int fn_802ee7dc();
extern "C" int lbl_804aecb4;
extern "C" char lbl_80389d44[],lbl_80389d54[];
extern "C" const float lbl_80389d64[],lbl_80389d68[];
extern "C" char *lbl_804aec80;
extern "C" char *lbl_804aec84;
extern "C" char *lbl_804aec88;
extern "C" char *lbl_804aec8c;
extern "C" char *lbl_804aec90;
extern "C" char *lbl_804aec94;
extern "C" char *lbl_804aec98;
extern "C" char *lbl_804aec9c;
extern "C" char *lbl_804aeca0;
extern "C" void w3d_cc20a_particle_arenas_sinit_800e0450(int init,int priority){if(priority==0xffff&&init){
lbl_804aec80=lbl_804aae9c+16384;
lbl_804aec84=lbl_804aae9c;
lbl_804aec88=lbl_804aae9c+736;
lbl_804aec8c=lbl_804aae9c+12400;
lbl_804aec90=lbl_804aae9c;
lbl_804aec94=lbl_804aae9c+16368;
lbl_804aec98=lbl_804aae9c+16304;
lbl_804aec9c=lbl_804aae9c+16176;
lbl_804aeca0=lbl_804aae9c;
new (&lbl_804aeca4) Cc20aArena_802097ec(lbl_80389d44,0,0);new (&lbl_804aecac) Cc20aArena_802097ec(lbl_80389d54,0,0);
lbl_804aecb4=fn_802ee7dc();new (&lbl_804453c8) Cc20aVec3(lbl_80389d64[0],lbl_80389d64[0],lbl_80389d68[0]);}}