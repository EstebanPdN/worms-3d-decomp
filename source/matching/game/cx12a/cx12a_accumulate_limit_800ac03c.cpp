// PPC32 byte offsets, four-byte pointer slots and three-float vectors are observed. Semantic names inferred.
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
#define VCALL(p,T,o) ((T)(*(void **)(*(char **)(p)+(o))))
inline const float &cx12a_max(const float &a,const float &b){return a<b?b:a;}
inline const float &cx12a_min(const float &a,const float &b){return b<a?b:a;}
extern "C" float read_80178df0(void *);extern const float one_80381c44[];
extern "C" void w3d_cx12a_accumulate_limit_800ac03c(void *self){
 float delta=(one_80381c44[0]-FIELD(self,float,0x68))*read_80178df0(FIELD(self,void *,0xd0));
 delta=cx12a_min(delta,read_80178df0(FIELD(self,void *,0xec)));
 FIELD(self,float,0xa0)=delta*read_80178df0(FIELD(self,void *,0xd4))+FIELD(self,float,0xa0);
 FIELD(self,float,0xa0)=cx12a_min(FIELD(self,float,0xa0),read_80178df0(FIELD(self,void *,0xec)));
}
