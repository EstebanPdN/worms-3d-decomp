#include "w3d_ptr.h"
#line 1 "f1p_initialize_named_panel_802ba5c4.cpp"
// Partial external panel/data views; callback identity is observed by address.
struct F1pNamedIface{Ptr32<Ptr32<void>> table;};struct F1pNamedHeld{
 F1pNamedHeld(const F1pNamedHeld &);Ptr32<F1pNamedIface> p;F1pNamedHeld():p(0){}~F1pNamedHeld(){if(p)((Ptr32<void (Ptr32<F1pNamedIface>)>)p->table[4])(p);}};
struct F1pNamedText{Ptr32<char> p;};struct F1pNamedKey{Ptr32<const char> p;template <class W3dU> F1pNamedKey(Ptr32<W3dU> w3d_p) : F1pNamedKey((const char *)w3d_p.get()) {}
 F1pNamedKey(const char*t):p(t){}};
struct F1pNamedData{char unknown0[140];F1pNamedText resource;};struct F1pNamedOwner{char unknown0[40];Ptr32<F1pNamedData> data;char unknown44[172];unsigned handle;};struct F1pNamedContext{char unknown0[52];Ptr32<void> service;};
extern "C" Ptr32<F1pNamedContext> fn_80165254();extern "C" void fn_802b0b84(Ptr32<void>,Ptr32<void>,Ptr32<void>),fn_802ba710(Ptr32<void>),fn_802ba818(Ptr32<void>);
extern "C" int fn_802baca0(Ptr32<void>, Ptr32<void>);extern "C" int fn_800fc1b0(Ptr32<F1pNamedKey>,Ptr32<F1pNamedHeld>);extern "C" void fn_800fd62c(Ptr32<F1pNamedText>,Ptr32<void (void)>,Ptr32<void>,Ptr32<unsigned int>);
extern "C" void w3d_initialize_named_panel_802ba5c4(Ptr32<F1pNamedOwner> s){fn_802b0b84((Ptr32<char>)s+28,s,fn_80165254()->service);F1pNamedHeld h;Ptr32<F1pNamedText> text=&s->data->resource;if(*(Ptr32<unsigned short>)(text->p-4)){F1pNamedKey key(text->p);if(fn_800fc1b0(&key,&h)>=0)fn_800fd62c(text,(Ptr32<void (void)>)fn_802baca0,s,&s->handle);}fn_802ba710(s);fn_802ba818(s);}


