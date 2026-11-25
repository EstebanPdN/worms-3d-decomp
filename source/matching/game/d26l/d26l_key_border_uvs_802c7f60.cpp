// GWMP8P rev0 0x802c7f60. Fills the texture coordinates of the FE.K.KeyBdr
// border resource: two tables of ten x,y pairs. The buffer roles of
// 0x80171fa0 and 0x80171ff8 are inferred from the memsets and the fill; the
// literals are decoded from the original pool.
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct S_8020bb54{char*p;S_8020bb54(const char*);S_8020bb54(const S_8020bb54&);~S_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}};
extern "C" int fn_8015ae3c(const S_8020bb54&);
extern "C" void*fn_80343808(int);
extern "C" int fn_80171f90(void*);
extern "C" int fn_80171ee0(void*,int);
extern "C" float*fn_80171fa0(void*);
extern "C" float*fn_80171ff8(void*);
extern "C" void*memset(void*,int,unsigned long);
extern char name_803d8df0[];
extern "C" void d26l_key_border_uvs_802c7f60(){
 void*o;
 {S_8020bb54 s(name_803d8df0);o=fn_80343808(fn_8015ae3c(s));}
 if(fn_80171f90(o)!=10){
  fn_80171ee0(o,10);
  float*a=fn_80171fa0(o);
  float*b=fn_80171ff8(o);
  memset(a,0,80);
  memset(b,0,80);
  a[0]=.015625f; a[1]=.015625f; a[2]=.125f; a[3]=.015625f; a[4]=.375f; a[5]=.015625f; a[6]=.515625f; a[7]=.015625f; a[8]=.625f; a[9]=.015625f; a[10]=.875f; a[11]=.015625f; a[12]=0.0f; a[13]=.5f; a[14]=.125f; a[15]=.5f; a[16]=.375f; a[17]=.5f; a[18]=.5f; a[19]=.5f; b[0]=.109375f; b[1]=.46875f; b[2]=.25f; b[3]=.46875f; b[4]=.109375f; b[5]=.46875f; b[6]=.125f; b[7]=.46875f; b[8]=.25f; b[9]=.46875f; b[10]=.125f; b[11]=.46875f; b[12]=.125f; b[13]=.5f; b[14]=.25f; b[15]=.5f; b[16]=.125f; b[17]=.5f; b[18]=.5f; b[19]=.5f;

  for(int i=0;i<10;i++){a[2*i+1]=1.0f-a[2*i+1]-b[2*i+1];}
 }
}
