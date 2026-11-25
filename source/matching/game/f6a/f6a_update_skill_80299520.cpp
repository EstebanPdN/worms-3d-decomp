// Observed string ABI and interface slots only; semantic roles inferred.
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*);
extern "C" unsigned short* fn_80341884(void*);
struct String {char*text;String(const String&o){fn_8020c5c0(this);text=o.text;unsigned short*h=fn_80341884(this);++*h;}~String(){fn_8020c5c4(this);fn_80341588(this);}};
struct Key {const char*text;Key(const char*p):text(p){}};
struct Handle {void*p;int unknown;Handle():p(0){}~Handle(){if(p)(*(void(***)(void*))p)[4](p);}int kind(){return (*(int(***)(void*))p)[6](p);}};
extern "C" int fn_800fc1b0(Key*,Handle*);
extern "C" void*fn_803426b4(void*),*fn_80342a78(void*);
extern "C" void fn_80178c54(void*,int*),fn_80178d28(void*,int*);
extern char skill_803d0a54[],perm_803d0b88[];
extern "C" int fn_802997fc(void*),fn_800fc1f0(Key*,int*),fn_800fc43c(Key*,int);
extern "C" void fn_80299b48(void*,String,int);
extern "C" void w3d_f6a_update_skill_80299520(void*self,String name){
 if(!((unsigned short*)name.text)[-2]){Key key(skill_803d0a54);fn_800fc43c(&key,0);}
 else {Handle h;int value=fn_802997fc(self)==1;if(value==1){int permanent=0;Key key(perm_803d0b88);fn_800fc1f0(&key,&permanent);if(permanent==1)value=0;}fn_80299b48(self,name,value);}
}
