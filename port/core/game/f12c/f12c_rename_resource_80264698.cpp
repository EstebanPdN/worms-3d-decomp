#include "w3d_ptr.h"
#line 1 "f12c_rename_resource_80264698.cpp"
// Observed owned descriptor and retained interface/string lifetime protocol.
extern "C" void fn_80178474(Ptr32<void>,int),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
struct F12cRenameOwned_80178474 {Ptr32<void> p;unsigned tag;F12cRenameOwned_80178474():p(0),tag(58280){}~F12cRenameOwned_80178474();};
struct F12cRenameHeader{unsigned short refs,length,capacity;void release(){if(!--refs)fn_8020bb2c(this);}};
struct F12cRenameText{Ptr32<char> p;void assign(const F12cRenameText&s){++((Ptr32<F12cRenameHeader>)(s.p-6))->refs;((Ptr32<F12cRenameHeader>)(p-6))->release();p=s.p;}};
struct F12cRenameText_8020bb54:F12cRenameText{int unknown __attribute__((aligned(__alignof__(F12cRenameText))));template <class W3dU> F12cRenameText_8020bb54(Ptr32<W3dU> w3d_p) : F12cRenameText_8020bb54((const char *)w3d_p.get()) {}
 F12cRenameText_8020bb54(const char*);~F12cRenameText_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}};
struct F12cRenameIface {Ptr32<Ptr32<void>> table;char unknown4[36];F12cRenameText text;int state;};
struct F12cRenameHeld{Ptr32<F12cRenameIface> p;int unknown;F12cRenameHeld():p(0){}template <class W3dU> F12cRenameHeld(Ptr32<W3dU> w3d_p) : F12cRenameHeld((F12cRenameIface *)w3d_p.get()) {}
 F12cRenameHeld(F12cRenameIface*next):p(next){if(p)((Ptr32<void (Ptr32<F12cRenameIface>)>)p->table[3])(p);}~F12cRenameHeld(){if(p)((Ptr32<void (Ptr32<F12cRenameIface>)>)p->table[4])(p);}void assign(Ptr32<F12cRenameIface> next){if(next){((Ptr32<void (Ptr32<F12cRenameIface>)>)next->table[3])(next);if(p)((Ptr32<void (Ptr32<F12cRenameIface>)>)p->table[4])(p);p=next;}}};
struct F12cRenameOwner{char unknown0[28];Ptr32<void> resource;};struct F12cRenameEngine{char unknown0[188];unsigned flags;};extern Ptr32<F12cRenameEngine> engine_804b1788;
extern "C" Ptr32<void> fn_80341584(Ptr32<void>);extern "C" Ptr32<F12cRenameIface> fn_80179598(Ptr32<void>,Ptr32<F12cRenameOwned_80178474>);
extern "C" void w3d_f12c_rename_resource_80264698(Ptr32<F12cRenameOwner> s,Ptr32<const char> name){
 if((engine_804b1788->flags&8)&&name&&*name&&s->resource){
 F12cRenameOwned_80178474 descriptor;F12cRenameHeld current;
 {F12cRenameHeld acquired(fn_80179598(fn_80341584(s->resource),&descriptor));current.assign(acquired.p);}
 if(current.p->state==1||!*(Ptr32<unsigned short>)(current.p->text.p-4))return;
 {F12cRenameText_8020bb54 text(name);current.p->text.assign(text);}
 }
}


