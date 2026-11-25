// Inferred engine names. Layout offsets and PPC32 four-byte pointers follow original effective addresses.
typedef unsigned int u32;typedef unsigned short u16;typedef unsigned char u8;
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))

extern "C" {int inverse_80302da0(void *,void *);void load_8030c0c8(void *,u32,int);void texgen_80307e24(int,int,int,u32,int,u32);extern u32 object_803a56b0[],context_803a56d0[];extern void *global_804b1884;}
struct Matrix{float v[12];};
static inline void apply(void *self,int index,u32 offset,u32 modes){if((*(int *)(modes+offset))!=2){Matrix temp;inverse_80302da0((char *)self+236,&temp);u32 object=object_803a56b0[index];load_8030c0c8(&temp,object,0);u32 context=context_803a56d0[index];load_8030c0c8((char *)global_804b1884+920,context,0);texgen_80307e24(index,0,1,object,1,context);FIELD(self,u32,304)=0;(*(int *)(modes+offset))=2;}}
extern "C" void w3d_cx15b_gx_texgen_inverse_bind_8016c07c(void *self,int index){apply(self,index,index*4,(u32)self+328);}


