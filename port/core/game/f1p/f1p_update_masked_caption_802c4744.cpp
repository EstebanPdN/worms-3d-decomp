#include "w3d_ptr.h"
#line 1 "f1p_update_masked_caption_802c4744.cpp"
// Inferred partial owner and native shared-text cleanup scopes.
extern "C" void fn_803426b8(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
// Inferred partial owner and native shared-text cleanup scopes.
extern "C" Ptr32<void> fn_8020bdf4(Ptr32<void>,Ptr32<const char>,int);
struct F1pMaskedText_803426b8{
 F1pMaskedText_803426b8(const F1pMaskedText_803426b8 &);Ptr32<char> p;F1pMaskedText_803426b8();~F1pMaskedText_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pMaskedView{Ptr32<char> p;};struct F1pMaskedIface{Ptr32<Ptr32<void>> table;};struct F1pMaskedOwner{char unknown0[84];int active;char unknown88[156];Ptr32<F1pMaskedIface> caption;char unknown248[4];F1pMaskedView name,text;char unknown260[116];int mask;};extern "C" Ptr32<F1pMaskedIface> fn_80343580(Ptr32<F1pMaskedIface>);extern "C" int fn_8020c5cc(Ptr32<F1pMaskedView>);extern "C" int fn_8018c5b0(Ptr32<F1pMaskedIface>,Ptr32<const char>);extern char text_803d8764[];
inline void updateMasked(Ptr32<F1pMaskedOwner> s,Ptr32<F1pMaskedView> text,Ptr32<F1pMaskedIface> p){if(!*(Ptr32<unsigned short>)(text->p-4)){((Ptr32<void (Ptr32<F1pMaskedIface>, int)>)s->caption->table[22])(s->caption,0);return;}if(s->mask){F1pMaskedText_803426b8 masked;fn_8020bdf4(&masked,text_803d8764,fn_8020c5cc(text));fn_8018c5b0(p,masked.p);}else fn_8018c5b0(p,text->p);((Ptr32<void (Ptr32<F1pMaskedIface>, int)>)s->caption->table[22])(s->caption,1);}
extern "C" void w3d_update_masked_caption_802c4744(Ptr32<F1pMaskedOwner> s){if(s->active&&*(Ptr32<unsigned short>)(s->name.p-4)&&s->caption){Ptr32<F1pMaskedIface> p=fn_80343580(s->caption);updateMasked(s,&s->text,p);}}


