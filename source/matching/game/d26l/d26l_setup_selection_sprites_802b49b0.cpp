// GWMP8P rev0 0x802b49b0. Selection-frame sprite setup, sibling of
// w3d_f11a_setup_selection_80286100 with a scale on the highlight. Owner and
// context are partial views; roles and names of the fields and interface
// slots are inferred from calls and resource names.
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct Text_803426b8{Text_803426b8(const Text_803426b8&);char*text;Text_803426b8();~Text_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct Iface{void**table;};
struct Vec{float x,y,z;Vec(){} Vec(float a,float b,float c){x=a;y=b;z=c;}};
struct Ctx{char u0[20];Vec size;char u32[84];float scale;int colour;char*format;};
struct Base{int fn_802b1510(const char*,Iface**,unsigned char);char u[7];unsigned char layer;};
struct Sel{char u[28];Base base;char u36[4];Ctx*context;char u44[64];char*error;Iface*host;char u116[100];int mode;char u220[4];Iface*normal;Iface*highlight;Iface*grey;};
extern char txt_803d7e1c[],txt_803d7d60[],txt_803d7e28[],txt_803d7e30[],txt_803d7e38[],txt_803d7e40[],txt_803d7e48[],txt_803d7e4c[];
extern "C" void fn_8020c510(void*,const char*,...),fn_802b4e10(Sel*);
extern "C" Text_803426b8*fn_8020bd38(Text_803426b8*,const char*);
#define VCALL(P,N,T) ((T)((P)->table[N]))
inline int layer(Sel*s){return s->mode==0?s->base.layer+30:s->base.layer+29;}
inline void attach(Sel*s,Iface**slot){VCALL(s->host,23,void(*)(Iface*,Iface*,int))(s->host,*slot,0);VCALL(*slot,21,void(*)(Iface*,void*,int))(*slot,(char*)s->context+20,0);}
extern "C" void d26l_setup_selection_sprites_802b49b0(Sel*s){
 Ctx*ctx=s->context;Text_803426b8 name;
 if(*(unsigned short*)(ctx->format-4)){
  fn_8020c510(&name,ctx->format,txt_803d7e1c);
  if(s->base.fn_802b1510(name.text,&s->highlight,layer(s))<0)fn_8020c510((char*)s+108,txt_803d7d60,name.text);
  else {
   VCALL(s->host,23,void(*)(Iface*,Iface*,int))(s->host,s->highlight,0);
   float sc=ctx->scale;if(sc==0.0f)VCALL(s->highlight,21,void(*)(Iface*,void*,int))(s->highlight,(char*)s->context+20,0);
   else{Ctx*c=s->context;Vec v(c->size.x*sc,c->size.y*sc,1.0f);VCALL(s->highlight,21,void(*)(Iface*,Vec*,int))(s->highlight,&v,0);}
   VCALL(s->highlight,22,void(*)(Iface*,int))(s->highlight,0);
  }
  fn_8020c510(&name,ctx->format,txt_803d7e28);
  if(s->base.fn_802b1510(name.text,&s->grey,layer(s))>=0){attach(s,&s->grey);VCALL(s->grey,22,void(*)(Iface*,int))(s->grey,0);}
  if(ctx->colour){
   switch(ctx->colour){
   case 1:fn_8020c510(&name,ctx->format,txt_803d7e30);break;
   case 2:fn_8020c510(&name,ctx->format,txt_803d7e38);break;
   case 3:fn_8020c510(&name,ctx->format,txt_803d7e30);break;
   case 4:fn_8020c510(&name,ctx->format,txt_803d7e40);break;
   case 5:fn_8020c510(&name,ctx->format,txt_803d7e48);break;
   default:fn_8020bd38(&name,txt_803d7e4c);break;
   }
   if(s->base.fn_802b1510(name.text,&s->normal,layer(s))<0)fn_8020c510((char*)s+108,txt_803d7d60,name.text);
   else attach(s,&s->normal);
  }
 }
 fn_802b4e10(s);
}
