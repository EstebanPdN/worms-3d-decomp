#include "w3d_ptr.h"
#line 1 "f1p_construct_text_control_802c0eac.cpp"
// Observed owner fields through byte111. No complete class identity claimed.
struct F1pTextCtorIface{Ptr32<Ptr32<void>> table;};struct F1pTextCtorOwner{Ptr32<Ptr32<void>> table;char unknown4[24];Ptr32<F1pTextCtorIface> a; Ptr32<F1pTextCtorIface> b; Ptr32<F1pTextCtorIface> c;float f40;Ptr32<char> text;int i48;float f52,x,y,z;int i68,i72,i76,i80;char unknown84[24];int i108;};extern Ptr32<void> vt_8041c8a0[];extern const float zero_803d84b4[],one_803d84b8[],z_803d84bc[];extern "C" Ptr32<void> fn_8015fef0(Ptr32<void>);extern "C" Ptr32<void> fn_803426b8(Ptr32<void>);
extern "C" Ptr32<F1pTextCtorOwner> w3d_construct_text_control_802c0eac(Ptr32<F1pTextCtorOwner> s){int zero=0;fn_8015fef0(s);s->a=(Ptr32<F1pTextCtorIface>)w3d::G(zero);s->b=(Ptr32<F1pTextCtorIface>)w3d::G(zero);s->c=(Ptr32<F1pTextCtorIface>)w3d::G(zero);s->table=vt_8041c8a0;fn_803426b8(&s->text);s->i68=zero;s->i48=zero;if(s->c)((Ptr32<void (Ptr32<F1pTextCtorIface>)>)s->c->table[4])(s->c);s->c=(Ptr32<F1pTextCtorIface>)w3d::G(zero);s->f40=zero_803d84b4[0];s->f52=zero_803d84b4[0];s->x=zero_803d84b4[0];s->y=one_803d84b8[0];s->z=z_803d84bc[0];s->i72=99;s->i76=zero;s->i80=zero;s->i108=zero;return s;}


