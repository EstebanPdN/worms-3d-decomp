/* GC32 offsets are inferred from the original; identities remain unknown. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
extern void *context_804b17f0,*pool_804b1754;
extern const float width_803814d0[],height_803814d4[],depth_803814d8[];
extern char table_8040db38[];
extern "C" void *allocate_801613f0(void *,unsigned);
extern "C" void post_800a6c80(unsigned,void *);
extern "C" void tterra_a29_dimensions_800a79f8(float x,float y,unsigned target) {
 void *context=context_804b17f0; void *pool=pool_804b1754;
 float a=x/width_803814d0[0],b=y/height_803814d4[0];
 FIELD(context,float,32)=a; FIELD(context,float,36)=b;
 void *m=allocate_801613f0(pool,36);
 FIELD(m,unsigned short,0)=0x1004; FIELD(m,void *,4)=table_8040db38;
 FIELD(m,unsigned,12)=8; FIELD(m,unsigned short,18)=0; FIELD(m,unsigned char,20)=0;
 FIELD(m,float,24)=a; FIELD(m,float,28)=b; FIELD(m,float,32)=depth_803814d8[0];
 FIELD(m,unsigned,8)=0; FIELD(m,unsigned short,16)=0; post_800a6c80(target,m);
}
