#include "w3d_ptr.h"
#line 1 "f12c_ensure_random_land_8026c54c.cpp"
// Partial context/property views; string and interface cleanup follow the original ownership protocol.
struct F12cRandomIface{Ptr32<Ptr32<void>> table;};
struct F12cRandomHeld {Ptr32<F12cRandomIface> p;int unknown;F12cRandomHeld():p(0){}~F12cRandomHeld(){if(p)((Ptr32<void (Ptr32<F12cRandomIface>)>)p->table[4])(p);}};
struct F12cRandomKey{Ptr32<const char> p;};
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
struct F12cRandomHeader{unsigned short refs,length,capacity;void release(){if(!--refs)fn_8020bb2c(this);}};
struct F12cRandomText{Ptr32<char> p;int unknown;~F12cRandomText(){fn_8020c5c4(this);fn_80341588(this);}void assign(const F12cRandomText&s){++((Ptr32<F12cRandomHeader>)(s.p-6))->refs;((Ptr32<F12cRandomHeader>)(p-6))->release();p=s.p;}};
struct F12cRandomText_803426b8:F12cRandomText{F12cRandomText_803426b8();};
struct F12cRandomContext{char unknown0[156];Ptr32<char> name;};struct F12cRandomOwner{char unknown0[40];Ptr32<F12cRandomContext> context;};
extern "C" int fn_800fc1b0(Ptr32<F12cRandomKey>,Ptr32<F12cRandomHeld>),fn_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" Ptr32<void> fn_80343744(Ptr32<void>);extern "C" Ptr32<F12cRandomText> fn_80179170(Ptr32<void>);extern "C" int fn_801790bc(Ptr32<void>,Ptr32<const char>);
extern const char random_803cba20[];
extern "C" void w3d_f12c_ensure_random_land_8026c54c(Ptr32<F12cRandomOwner> s){
 Ptr32<F12cRandomContext> context=s->context;
 if(*(Ptr32<unsigned short>)(context->name-4)){
 F12cRandomText_803426b8 current;
 F12cRandomHeld property;F12cRandomKey key;key.p=context->name;fn_800fc1b0(&key,&property);
 current.assign(*fn_80179170(fn_80343744(property.p)));
 Ptr32<const char> random=random_803cba20;int different;if(fn_802ef234(current.p,random)==0)different=0;else different=1;
 if(different)fn_801790bc(fn_80343744(property.p),random);
 }
}


