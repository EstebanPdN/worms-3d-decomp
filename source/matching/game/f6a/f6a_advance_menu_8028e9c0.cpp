// Partial observed menu history and deque layout; semantic roles inferred.
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*);
struct Header{unsigned short refs,length,unknown;};extern "C" Header*fn_80341884(void*);
struct Text_803426b8{char*text;int unknown;Text_803426b8();~Text_803426b8(){fn_8020c5c4(this);fn_80341588(this);}};
struct CallerString{char*text;int unknown;CallerString(const Text_803426b8&o){fn_8020c5c0(this);text=o.text;Header*h=fn_80341884(this);++h->refs;}~CallerString(){fn_8020c5c4(this);fn_80341588(this);}};
struct Key{const char*text;Key(const char*p):text(p){}};
struct Names{char unknown[20];};
struct Deque{int*current,*first,*last,**node;};
struct Owner{char unknown[68];int value;Names names,history;char unknown112[8];Deque deque;};
extern void*app_804b1788;extern char refcount_803d001c[],empty_803d0034[],briefing_803d0038[];
extern "C" int fn_8015ccbc(void*),fn_8006e71c(),fn_800fc1f0(Key*,int*),fn_800c4660(Names*),fn_802ef234(const char*,const char*),fn_800fc2b0(Key*,char**),fn_800fc550(Key*,const char*);
extern "C" void fn_800c4a7c(Names*,Text_803426b8*),fn_8035eec4(Deque*),fn_8028e630(Owner*,CallerString,int,const char*);
inline int different(const Text_803426b8&self,const char*other){return fn_802ef234(self.text,other)!=0;}
inline void pop(Deque*p){if(p->current!=p->last-1)++p->current;else fn_8035eec4(p);}
extern "C" void w3d_f6a_advance_menu_8028e9c0(Owner*self){
 if(fn_8015ccbc(app_804b1788)==1)return;if(fn_8006e71c()==1)return;
 int refs=0;Key refKey(refcount_803d001c);fn_800fc1f0(&refKey,&refs);if(refs>0)return;
 Text_803426b8 menu;fn_800c4a7c(&self->names,&menu);Text_803426b8 history;
 if(fn_800c4660(&self->history)){fn_800c4a7c(&self->history,&history);int changed=different(history,empty_803d0034);if(changed){Key key(history.text);char*text;fn_800fc2b0(&key,&text);Key target(briefing_803d0038);fn_800fc550(&target,text);}}
 self->value=*self->deque.current;pop(&self->deque);fn_8028e630(self,CallerString(menu),self->value,history.text);
}
