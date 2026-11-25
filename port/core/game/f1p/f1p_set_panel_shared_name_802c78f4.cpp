#include "w3d_ptr.h"
#line 1 "f1p_set_panel_shared_name_802c78f4.cpp"
// Observed by-value shared-string ownership and partial resource panel state.
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);extern "C" int fn_802ef234(Ptr32<const char>,Ptr32<const char>);
struct F1pSharedName{
 F1pSharedName(const F1pSharedName &); F1pSharedName() {}Ptr32<char> text;~F1pSharedName(){fn_8020c5c4(this);fn_80341588(this);}};struct F1pSharedHeader{unsigned short refs,length,capacity;void release(){if(!--refs)fn_8020bb2c(this);}};
struct F1pSharedTextView{Ptr32<char> text;void assign(const F1pSharedName&s){++((Ptr32<F1pSharedHeader>)(s.text-6))->refs;((Ptr32<F1pSharedHeader>)(text-6))->release();text=s.text;}};
struct F1pNameIface{Ptr32<Ptr32<void>> table;};struct F1pNameOwner{char unknown[28];Ptr32<F1pNameIface> main;char unknown32[60];Ptr32<F1pNameIface> child;short id,unknown98;F1pSharedTextView name;int unknown104,active;};extern "C" void fn_802c7a98(Ptr32<F1pNameOwner>);
extern "C" void w3d_set_panel_shared_name_802c78f4(Ptr32<F1pNameOwner> s,F1pSharedName name,int force){if(*(Ptr32<unsigned short>)(name.text-4)){if(fn_802ef234(name.text,s->name.text)!=0||force){s->name.assign(name);if(s->child){((Ptr32<void (Ptr32<F1pNameIface>, Ptr32<F1pNameIface>)>)s->main->table[24])(s->main,s->child);if(s->child)((Ptr32<void (Ptr32<F1pNameIface>)>)s->child->table[4])(s->child);s->child=0;}if(force&&s->id&&s->active)fn_802c7a98(s);}}}


