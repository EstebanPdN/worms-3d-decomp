#include "w3d_ptr.h"
#line 1 "f1p_bind_text_control_properties_802c28a0.cpp"
// Inferred external text-control prefix and native held interface lifetime.
struct F1pBindIface{Ptr32<Ptr32<void>> table;};struct F1pBindHeld{Ptr32<F1pBindIface> p;unsigned unspecified;F1pBindHeld():p(0){}~F1pBindHeld(){if(p)((Ptr32<void (Ptr32<F1pBindIface>)>)p->table[4])(p);}void assign(Ptr32<F1pBindIface> q){if(q)((Ptr32<void (Ptr32<F1pBindIface>)>)q->table[3])(q);if(p)((Ptr32<void (Ptr32<F1pBindIface>)>)p->table[4])(p);p=q;}};
struct F1pBindKey{Ptr32<const char> text;template <class W3dU> F1pBindKey(Ptr32<W3dU> w3d_p) : F1pBindKey((const char *)w3d_p.get()) {}
 F1pBindKey(const char*p):text(p){}};struct F1pBindOwner{char pre0[52];F1pBindHeld flash;char pre60[268];unsigned id;unsigned other;F1pBindHeld thickness;};
extern "C" int fn_800fc1b0(Ptr32<F1pBindKey>,Ptr32<F1pBindHeld>);extern "C" Ptr32<F1pBindIface> fn_80342a74(Ptr32<F1pBindIface>); Ptr32<F1pBindIface> fn_80342a78(Ptr32<F1pBindIface>);extern "C" void fn_802c37e4(Ptr32<F1pBindOwner>);extern char key_803d85a0[],key_803d85b4[];extern unsigned counter_804abb5c,offset_804abb60,current_804abb54;
extern "C" void w3d_bind_text_control_properties_802c28a0(Ptr32<F1pBindOwner> s){F1pBindHeld h;F1pBindKey key(key_803d85a0);fn_800fc1b0(&key,&h);s->thickness.assign(fn_80342a74(h.p));F1pBindKey flash(key_803d85b4);fn_800fc1b0(&flash,&h);s->flash.assign(fn_80342a78(h.p));unsigned id=counter_804abb5c+1;counter_804abb5c=id;s->id=id;offset_804abb60+=6;current_804abb54=id;fn_802c37e4(s);}


