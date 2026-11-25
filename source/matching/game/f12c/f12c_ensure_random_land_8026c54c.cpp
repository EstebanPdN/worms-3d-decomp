// Partial context/property views; string and interface cleanup follow the original ownership protocol.
struct F12cRandomIface{void**table;};
struct F12cRandomHeld {F12cRandomIface*p;int unknown;F12cRandomHeld():p(0){}~F12cRandomHeld(){if(p)((void(*)(F12cRandomIface*))p->table[4])(p);}};
struct F12cRandomKey{const char*p;};
extern "C" void fn_8020c5c4(void*),fn_80341588(void*),fn_8020bb2c(void*);
struct F12cRandomHeader{unsigned short refs,length,capacity;void release(){if(!--refs)fn_8020bb2c(this);}};
struct F12cRandomText{char*p;int unknown;~F12cRandomText(){fn_8020c5c4(this);fn_80341588(this);}void assign(const F12cRandomText&s){++((F12cRandomHeader*)(s.p-6))->refs;((F12cRandomHeader*)(p-6))->release();p=s.p;}};
struct F12cRandomText_803426b8:F12cRandomText{F12cRandomText_803426b8();};
struct F12cRandomContext{char unknown0[156];char*name;};struct F12cRandomOwner{char unknown0[40];F12cRandomContext*context;};
extern "C" int fn_800fc1b0(F12cRandomKey*,F12cRandomHeld*),fn_802ef234(const char*,const char*);
extern "C" void*fn_80343744(void*);extern "C" F12cRandomText*fn_80179170(void*);extern "C" int fn_801790bc(void*,const char*);
extern const char random_803cba20[];
extern "C" void w3d_f12c_ensure_random_land_8026c54c(F12cRandomOwner*s){
 F12cRandomContext*context=s->context;
 if(*(unsigned short*)(context->name-4)){
 F12cRandomText_803426b8 current;
 F12cRandomHeld property;F12cRandomKey key;key.p=context->name;fn_800fc1b0(&key,&property);
 current.assign(*fn_80179170(fn_80343744(property.p)));
 const char *random=random_803cba20;int different;if(fn_802ef234(current.p,random)==0)different=0;else different=1;
 if(different)fn_801790bc(fn_80343744(property.p),random);
 }
}
