#include "w3d_ptr.h"
#line 1 "cc29b_replace_font_8018dfa0.cpp"
// Inferred names and partial source views; native handle declaration/sizeof unknown.
struct cc29b_Object_8018dfa0 {Ptr32<Ptr32<void>> vtable;};
inline void cc29b_retain_8018dfa0(Ptr32<cc29b_Object_8018dfa0> p){if(p)((Ptr32<void (Ptr32<cc29b_Object_8018dfa0>)>)p->vtable[3])(p);}
inline void cc29b_release_8018dfa0(Ptr32<cc29b_Object_8018dfa0> p){if(p)((Ptr32<void (Ptr32<cc29b_Object_8018dfa0>)>)p->vtable[4])(p);}
struct cc29b_Handle_8018dfa0 {Ptr32<cc29b_Object_8018dfa0> object;template <class W3dU> cc29b_Handle_8018dfa0(Ptr32<W3dU> w3d_p) : cc29b_Handle_8018dfa0((cc29b_Object_8018dfa0 *)w3d_p.get()) {}
 cc29b_Handle_8018dfa0(cc29b_Object_8018dfa0* p):object(p){cc29b_retain_8018dfa0(object);}~cc29b_Handle_8018dfa0(){cc29b_release_8018dfa0(object);}};
struct cc29b_Sink_8018dfa0 {char unknown[52];Ptr32<cc29b_Object_8018dfa0> font;void replace(Ptr32<cc29b_Object_8018dfa0> p){Ptr32<cc29b_Object_8018dfa0> old=font;font=p;cc29b_retain_8018dfa0(p);cc29b_release_8018dfa0(old);}};
struct cc29b_Text_8018dfa0 {char prefix[116];Ptr32<void> resource;char gap[48];Ptr32<cc29b_Object_8018dfa0> font;int unknown;Ptr32<cc29b_Sink_8018dfa0> sink;};
extern "C" Ptr32<cc29b_Object_8018dfa0> fn_801ea470(Ptr32<cc29b_Object_8018dfa0>);
extern "C" Ptr32<void> fn_8034435c(Ptr32<void>);
extern "C" int fn_801b14e8(Ptr32<cc29b_Object_8018dfa0>,Ptr32<cc29b_Object_8018dfa0>);
extern "C" Ptr32<cc29b_Object_8018dfa0> lbl_804b0238;extern "C" Ptr32<cc29b_Object_8018dfa0> lbl_804b023c;
extern "C" int w3d_cc29b_replace_font_8018dfa0(Ptr32<cc29b_Text_8018dfa0> self,int mode){
 cc29b_Handle_8018dfa0 font(fn_801ea470(self->font));fn_8034435c(self->resource);
 if(mode)fn_801b14e8(font.object,lbl_804b0238);else fn_801b14e8(font.object,lbl_804b023c);
 self->sink->replace(font.object);
 cc29b_retain_8018dfa0(font.object);cc29b_release_8018dfa0(self->font);self->font=font.object;
 return 0;
}


