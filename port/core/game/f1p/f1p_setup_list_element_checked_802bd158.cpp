#include "w3d_ptr.h"
#line 1 "f1p_setup_list_element_checked_802bd158.cpp"
// Native shared-text, vector and held-slot lifetimes; partial external owner.
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F1pListText_8020bb54{
 F1pListText_8020bb54(const F1pListText_8020bb54 &);Ptr32<char> p;template <class W3dU> F1pListText_8020bb54(Ptr32<W3dU> w3d_p) : F1pListText_8020bb54((const char *)w3d_p.get()) {}
 F1pListText_8020bb54(const char*);~F1pListText_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}};
struct F1pListIface{Ptr32<Ptr32<void>> table;};struct F1pListHeld{
 F1pListHeld(const F1pListHeld &);Ptr32<F1pListIface> p;F1pListHeld():p(0){}~F1pListHeld(){if(p)((Ptr32<void (Ptr32<F1pListIface>)>)p->table[4])(p);}};
struct F1pListViewHeld{Ptr32<F1pListIface> p;void assign(Ptr32<F1pListIface> q){if(q)((Ptr32<void (Ptr32<F1pListIface>)>)q->table[3])(q);if(p)((Ptr32<void (Ptr32<F1pListIface>)>)p->table[4])(p);p=q;}};
struct F1pListVec{float x,y,z;F1pListVec(float a,float b,float c):x(a),y(b),z(c){}};struct F1pListKey{Ptr32<const char> p;template <class W3dU> F1pListKey(Ptr32<W3dU> w3d_p) : F1pListKey((const char *)w3d_p.get()) {}
 F1pListKey(const char*t):p(t){}};
struct F1pListOwner{char unknown0[20];int enabled;char unknown24[16];F1pListVec position;char unknown52[16];F1pListViewHeld border;char unknown72[24];Ptr32<F1pListIface> child; Ptr32<F1pListIface> parent;};extern char text_803d8360[],key_803d8368[];
extern "C" void fn_802bd4fc(Ptr32<F1pListOwner>),fn_802bdd24(Ptr32<F1pListOwner>);
extern "C" Ptr32<void> fn_8015adf4(Ptr32<F1pListText_8020bb54>,Ptr32<Ptr32<F1pListIface>>,unsigned char);extern "C" int fn_800fc1b0(Ptr32<F1pListKey>,Ptr32<F1pListHeld>);extern "C" Ptr32<F1pListIface> fn_80342a74(Ptr32<F1pListIface>);
extern "C" void w3d_setup_list_element_802bd158(Ptr32<F1pListOwner> s){{F1pListText_8020bb54 text(text_803d8360);fn_8015adf4(&text,&s->child,255);}((Ptr32<void (Ptr32<F1pListIface>, Ptr32<F1pListIface>, int)>)s->parent->table[23])(s->parent,s->child,0);F1pListVec scale(1.0f,1.0f,1.0f);((Ptr32<void (Ptr32<F1pListIface>, const F1pListVec &, int)>)s->child->table[21])(s->child,scale,0);((Ptr32<void (Ptr32<F1pListIface>, const F1pListVec &, int)>)s->child->table[19])(s->child,s->position,0);s->enabled=1;F1pListHeld h;F1pListKey key(key_803d8368);fn_800fc1b0(&key,&h);s->border.assign(fn_80342a74(h.p));fn_802bd4fc(s);fn_802bdd24(s);}


