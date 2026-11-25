// Observed string ABI and interface slots only; semantic roles inferred.
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*);
extern "C" unsigned short* fn_80341884(void*);
struct String {char*text;String(const String&o){fn_8020c5c0(this);text=o.text;unsigned short*h=fn_80341884(this);++*h;}~String(){fn_8020c5c4(this);fn_80341588(this);}};
struct Key {const char*text;Key(const char*p):text(p){}};
struct Handle {void*p;int unknown;Handle():p(0){}~Handle(){if(p)(*(void(***)(void*))p)[4](p);}int kind(){return (*(int(***)(void*))p)[6](p);}};
extern "C" int fn_800fc1b0(Key*,Handle*);
extern "C" void*fn_803426b4(void*),*fn_80342a78(void*);
extern "C" void fn_80178c54(void*,int*),fn_80178d28(void*,int*);
extern char schemes_803d0164[];
extern "C" void*fn_80341584(void*),*fn_801797b4(void*);
struct List{char unknown[24];unsigned count;};
struct Data{char unknown[20];List*schemes;};
extern "C" void w3d_f6a_scheme_flag_80293020(void*,String name){
 if(((unsigned short*)name.text)[-2]){
 Handle valueHandle;Handle dataHandle;int value=1;
 Key dataKey(schemes_803d0164);
 if(fn_800fc1b0(&dataKey,&dataHandle)<0)return;
 Data*data=(Data*)fn_801797b4(fn_80341584(dataHandle.p));
 if(data->schemes->count>15)value=0;
 Key key(name.text);
 if(fn_800fc1b0(&key,&valueHandle)<0){String diagnostic(name);return;}
 switch(valueHandle.kind()){
 case 0:fn_80178c54(fn_803426b4(valueHandle.p),&value);break;
 case 1:fn_80178d28(fn_80342a78(valueHandle.p),&value);break;
 }
 }
}
