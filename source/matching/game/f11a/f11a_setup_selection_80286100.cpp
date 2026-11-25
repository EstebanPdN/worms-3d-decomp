// Inferred selection resources; partial views of owner and context only.
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
struct F11aSelectionText_803426b8{
 F11aSelectionText_803426b8(const F11aSelectionText_803426b8 &);char*text;// Only the text pointer is observed.
F11aSelectionText_803426b8();~F11aSelectionText_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct F11aIface{void**table;};
struct F11aContext{char unknown[116];int colour;char unknown120[8];char*format;};
struct F11aBase{int fn_802b1510(const char*,F11aIface**,unsigned char);char unknown[7];unsigned char layer;};
struct F11aSelection{char unknown[28];F11aBase base;char unknown36[4];F11aContext*context;char unknown44[64];char*error;F11aIface*host;char unknown116[100];int mode;char unknown220[24];F11aIface*normal,*highlight,*grey;};
// Partial owner/context views only; no complete allocation size claimed.
// Error is observed at108 and host at112; its text view is a single word.
extern char txt_803cf40c[],txt_803cf418[],txt_803cf43c[],txt_803cf444[],txt_803cf44c[],txt_803cf454[],txt_803cf45c[],txt_803cf460[];
extern "C" void fn_8020c510(void*,const char*,...),fn_802870fc(F11aSelection*);
extern "C" F11aSelectionText_803426b8*fn_8020bd38(F11aSelectionText_803426b8*,const char*);
extern "C" int fn_802b1510(void*,const char*,F11aIface**,unsigned char);
#define VCALL(P,N,T) ((T)((P)->table[N]))
inline int layer(F11aSelection*s){return s->mode==0?s->base.layer+31:s->base.layer+30;}
inline void attach(F11aSelection*s,F11aIface**slot){VCALL(s->host,23,void(*)(F11aIface*,F11aIface*,int))(s->host,*slot,0);VCALL(*slot,21,void(*)(F11aIface*,void*,int))(*slot,(char*)s->context+20,0);}
extern "C" void w3d_f11a_setup_selection_80286100(F11aSelection*s){
 F11aContext*ctx=s->context;F11aSelectionText_803426b8 name;
 if(*(unsigned short*)(ctx->format-4)){
  fn_8020c510(&name,ctx->format,txt_803cf40c);
  if(s->base.fn_802b1510(name.text,&s->highlight,layer(s))<0)fn_8020c510((char*)s+108,txt_803cf418,name.text);
  else {attach(s,&s->highlight);VCALL(s->highlight,22,void(*)(F11aIface*,int))(s->highlight,0);}
  fn_8020c510(&name,ctx->format,txt_803cf43c);
  if(s->base.fn_802b1510(name.text,&s->grey,layer(s))>=0){attach(s,&s->grey);VCALL(s->grey,22,void(*)(F11aIface*,int))(s->grey,0);}
  if(ctx->colour){
   switch(ctx->colour){
   case 1:fn_8020c510(&name,ctx->format,txt_803cf444);break;
   case 2:fn_8020c510(&name,ctx->format,txt_803cf44c);break;
   case 3:fn_8020c510(&name,ctx->format,txt_803cf444);break;
   case 4:fn_8020c510(&name,ctx->format,txt_803cf454);break;
   case 5:fn_8020c510(&name,ctx->format,txt_803cf45c);break;
   default:fn_8020bd38(&name,txt_803cf460);break;
   }
   if(s->base.fn_802b1510(name.text,&s->normal,layer(s))<0)fn_8020c510((char*)s+108,txt_803cf418,name.text);
   else attach(s,&s->normal);
  }
 }
 fn_802870fc(s);
}
