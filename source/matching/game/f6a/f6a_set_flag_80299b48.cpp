// Observed string ABI and interface slots only; semantic roles inferred.
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*);
extern "C" unsigned short* fn_80341884(void*);
struct String {char*text;String(const String&o){fn_8020c5c0(this);text=o.text;unsigned short*h=fn_80341884(this);++*h;}~String(){fn_8020c5c4(this);fn_80341588(this);}};
struct Key {const char*text;Key(const char*p):text(p){}};
struct Handle {void*p;int unknown;Handle():p(0){}~Handle(){if(p)(*(void(***)(void*))p)[4](p);}int kind(){return (*(int(***)(void*))p)[6](p);}};
extern "C" int fn_800fc1b0(Key*,Handle*);
extern "C" void*fn_803426b4(void*),*fn_80342a78(void*);
extern "C" void fn_80178c54(void*,int*),fn_80178d28(void*,int*);
extern "C" void w3d_f6a_set_flag_80299b48(void*,String name,int value){
 Handle h;Key key(name.text);
 if(fn_800fc1b0(&key,&h)<0){String diagnostic(name);return;}
 switch(h.kind()){
 case 0:fn_80178c54(fn_803426b4(h.p),&value);break;
 case 1:fn_80178d28(fn_80342a78(h.p),&value);break;
 default:{String diagnostic(name);break;}
 }
}
