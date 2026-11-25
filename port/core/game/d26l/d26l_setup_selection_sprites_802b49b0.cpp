#include "w3d_ptr.h"
#line 1 "d26l_setup_selection_sprites_802b49b0.cpp"
// GWMP8P rev0 0x802b49b0. Selection-frame sprite setup, sibling of
// w3d_f11a_setup_selection_80286100 with a scale on the highlight. Owner and
// context are partial views; roles and names of the fields and interface
// slots are inferred from calls and resource names.
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct Text_803426b8{Text_803426b8(const Text_803426b8&);Ptr32<char> text;Text_803426b8();~Text_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct Iface{Ptr32<Ptr32<void>> table;};
struct Vec{float x,y,z;Vec(){} Vec(float a,float b,float c){x=a;y=b;z=c;}};
struct Ctx{char u0[20];Vec size;char u32[84];float scale;int colour;Ptr32<char> format;};
struct Base{int fn_802b1510(Ptr32<const char>,Ptr32<Ptr32<Iface>>,unsigned char);char u[4];unsigned char layer; char w3d_tag_rest[3];};
struct Sel{char u[28];Base base;char u36[4];Ptr32<Ctx> context;char u44[64];Ptr32<char> error;Ptr32<Iface> host;char u116[100];int mode;char u220[4];Ptr32<Iface> normal;Ptr32<Iface> highlight;Ptr32<Iface> grey;};
extern char txt_803d7e1c[],txt_803d7d60[],txt_803d7e28[],txt_803d7e30[],txt_803d7e38[],txt_803d7e40[],txt_803d7e48[],txt_803d7e4c[];
extern "C" void fn_8020c510(Ptr32<void>,Ptr32<const char>,...),fn_802b4e10(Ptr32<Sel>);
extern "C" Ptr32<Text_803426b8> fn_8020bd38(Ptr32<Text_803426b8>,Ptr32<const char>);
#define VCALL(P,N,T) ((w3d::slot_t<T>)((P)->table[N]))
inline int layer(Ptr32<Sel> s){return s->mode==0?s->base.layer+30:s->base.layer+29;}
inline void attach(Ptr32<Sel> s,Ptr32<Ptr32<Iface>> slot){VCALL(s->host,23,void(*)(Iface*,Iface*,int))(s->host,*slot,0);VCALL(*slot,21,void(*)(Iface*,void*,int))(*slot,(Ptr32<char>)s->context+20,0);}
extern "C" void d26l_setup_selection_sprites_802b49b0(Ptr32<Sel> s){
 Ptr32<Ctx> ctx=s->context;Text_803426b8 name;
 if(*(Ptr32<unsigned short>)(ctx->format-4)){
  fn_8020c510(&name,ctx->format,w3d::VA(txt_803d7e1c));
  if(s->base.fn_802b1510(name.text,&s->highlight,layer(s))<0)fn_8020c510((Ptr32<char>)s+108,txt_803d7d60,w3d::VA(name.text));
  else {
   VCALL(s->host,23,void(*)(Iface*,Iface*,int))(s->host,s->highlight,0);
   float sc=ctx->scale;if(sc==0.0f)VCALL(s->highlight,21,void(*)(Iface*,void*,int))(s->highlight,(Ptr32<char>)s->context+20,0);
   else{Ptr32<Ctx> c=s->context;Vec v(c->size.x*sc,c->size.y*sc,1.0f);VCALL(s->highlight,21,void(*)(Iface*,Vec*,int))(s->highlight,&v,0);}
   VCALL(s->highlight,22,void(*)(Iface*,int))(s->highlight,0);
  }
  fn_8020c510(&name,ctx->format,w3d::VA(txt_803d7e28));
  if(s->base.fn_802b1510(name.text,&s->grey,layer(s))>=0){attach(s,&s->grey);VCALL(s->grey,22,void(*)(Iface*,int))(s->grey,0);}
  if(ctx->colour){
   switch(ctx->colour){
   case 1:fn_8020c510(&name,ctx->format,w3d::VA(txt_803d7e30));break;
   case 2:fn_8020c510(&name,ctx->format,w3d::VA(txt_803d7e38));break;
   case 3:fn_8020c510(&name,ctx->format,w3d::VA(txt_803d7e30));break;
   case 4:fn_8020c510(&name,ctx->format,w3d::VA(txt_803d7e40));break;
   case 5:fn_8020c510(&name,ctx->format,w3d::VA(txt_803d7e48));break;
   default:fn_8020bd38(&name,txt_803d7e4c);break;
   }
   if(s->base.fn_802b1510(name.text,&s->normal,layer(s))<0)fn_8020c510((Ptr32<char>)s+108,txt_803d7d60,w3d::VA(name.text));
   else attach(s,&s->normal);
  }
 }
 fn_802b4e10(s);
}


