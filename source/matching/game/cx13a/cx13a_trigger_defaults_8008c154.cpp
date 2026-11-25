// PPC32 observed offsets, inferred semantic names.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
extern "C" int set_800fc550(const char **,const char *),set_800fc3b0(const char **,int),set_800fc4c8(const char **,float);
extern const char key_8037deb8[],value_8037dec8[],key_8037ded8[],key_8037dee8[],key_8037def8[],key_8037df0c[],key_8037df20[],key_8037df34[],key_8037df48[],key_8037df60[],key_8037df78[],key_8037df90[];
extern const float radius_8037dfa4[];
extern "C" void w3d_cx13a_trigger_defaults_8008c154(){
 const char *a=key_8037deb8;set_800fc550(&a,value_8037dec8);const char *b=key_8037ded8;set_800fc3b0(&b,-1);const char *c=key_8037dee8;set_800fc4c8(&c,radius_8037dfa4[0]);const char *d=key_8037def8;set_800fc3b0(&d,1);const char *e=key_8037df0c;set_800fc3b0(&e,-1);const char *f=key_8037df20;set_800fc3b0(&f,-1);const char *g=key_8037df34;set_800fc3b0(&g,-1);const char *h=key_8037df48;set_800fc3b0(&h,2000);const char *i=key_8037df60;set_800fc3b0(&i,2000);const char *j=key_8037df78;set_800fc3b0(&j,0);const char *k=key_8037df90;set_800fc3b0(&k,0);
}
