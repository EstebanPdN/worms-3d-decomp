// Names, roles, types, qualifiers and layouts are inferred from original instructions.
inline void*operator new(unsigned,void*p){return p;}
extern "C" int fn_80251f40(void*, void *);extern "C" void fn_8020c5c0(void*);extern "C" unsigned short*fn_80341884(void*);
struct F8cStrings628;extern F8cStrings628 lbl_804b06a0[];
struct F8cStrings628 {char*text;F8cStrings628(){fn_8020c5c0(this);text=lbl_804b06a0[0].text;++*fn_80341884(this);}F8cStrings628(const F8cStrings628&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}};
extern void*lbl_8041b9f0[];extern const float lbl_803c8574[];
struct F8cVec628 {float x,y,z;F8cVec628(float f){x=f;y=f;z=f;}};
struct F8cOwner628{void*vtable;char unknown_base[160];F8cVec628 a,b;float c;unsigned limit,z0,z1,z2,z3;float d,e,f,g,h;unsigned z4;float i,j,k;F8cStrings628 s0,s1,s2,s3,s4,s5,s6,s7,s8;float l,m,n,o,p;unsigned z5,z6,z7,z8,z9,z10,z11,z12;};
extern "C" F8cOwner628*f8c_ctor_80255ddc(F8cOwner628*self, void * arg_r4){fn_80251f40(self, arg_r4);self->vtable=lbl_8041b9f0;float f=lbl_803c8574[0];new(&self->a)F8cVec628(f);new(&self->b)F8cVec628(f);self->c=f;self->limit=1000;self->z0=0;self->z1=0;self->z2=0;self->z3=0;self->d=f;self->e=f;self->f=f;self->g=f;self->h=f;self->z4=0;self->i=f;self->j=f;self->k=f;new(&self->s0)F8cStrings628;new(&self->s1)F8cStrings628;new(&self->s2)F8cStrings628;new(&self->s3)F8cStrings628;new(&self->s4)F8cStrings628;new(&self->s5)F8cStrings628;new(&self->s6)F8cStrings628;new(&self->s7)F8cStrings628;new(&self->s8)F8cStrings628; self->l=f;self->m=f;self->n=f;self->o=f;self->p=f;self->z5=0;self->z6=0;self->z7=0;self->z8=0;self->z9=0;self->z10=0;self->z11=0;self->z12=0;return self;}
