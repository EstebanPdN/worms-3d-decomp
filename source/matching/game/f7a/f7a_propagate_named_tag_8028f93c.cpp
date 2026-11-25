// Observed handles and dynamic tag descriptor; semantic types inferred.
struct F7aObject{void**table;};
inline void retain(F7aObject*p){if(p)((void(*)(F7aObject*))p->table[3])(p);}
inline void release(F7aObject*p){if(p)((void(*)(F7aObject*))p->table[4])(p);}
struct F7aHandle{F7aObject*p;F7aHandle():p(0){}F7aHandle(F7aObject*x):p(x){retain(p);}F7aHandle(const F7aHandle&o):p(o.p){retain(p);}~F7aHandle(){release(p);}F7aHandle&operator=(F7aObject*next){retain(next);release(p);p=next;return *this;}F7aHandle&operator=(const F7aHandle&o){F7aObject*next=o.p;if(next){retain(next);release(p);p=next;}return *this;}};
struct F7aTag_80178474{int zero;unsigned type;F7aTag_80178474():zero(0),type(58280){}~F7aTag_80178474();};
extern "C" void fn_80178474(void*,int);

struct F7aKey{const char*text;F7aKey(const char*p):text(p){}};
extern char barracks_803ceaa0[];
extern "C" int fn_800fc1b0(const F7aKey&,F7aHandle&);
extern "C" F7aObject* fn_80341584(F7aObject*);
extern "C" F7aObject* fn_80179598(F7aObject*,F7aTag_80178474*);
extern "C" void fn_801ea4c8(F7aObject*,void*);
extern "C" void w3d_f7a_propagate_named_tag_8028f93c(void*,const char*name,void*target){
 if(target){
 F7aHandle object;
 {F7aHandle value;fn_800fc1b0(*(const F7aKey*)&name,value);object=fn_80341584(value.p);}
 F7aTag_80178474 tag;
 fn_801ea4c8(fn_80179598(object.p,&tag),target);
 }
}
