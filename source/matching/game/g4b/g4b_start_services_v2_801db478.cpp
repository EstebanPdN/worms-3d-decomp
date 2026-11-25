// Complete local Held owns one interface pointer; external objects remain partial views.
struct Interface {void**table;};
inline void retain(Interface*p){if(p)((void(*)(Interface*))p->table[3])(p);}
inline void release(Interface*p){if(p)((void(*)(Interface*))p->table[4])(p);}
struct Held {Interface*p;Held(Interface*q):p(q){retain(p);} Held(const Held&q):p(q.p){retain(p);}~Held(){release(p);}
 void set(Interface*q){retain(q);release(p);p=q;}
 Held&operator=(const Held&q){retain(q.p);release(p);p=q.p;return *this;}
 void clear(){release(p);p=0;}
};
struct Storage;
struct List {int count,unknown;Storage*storage;void append(Interface*value);};
extern "C" void fn_80210d54(List*,int);
inline void List::append(Interface*value){fn_80210d54(this,count+1);Held*slot=(Held*)((count<<2)+(char*)storage);slot->set(value);++count;}
struct Service {void**table;unsigned unknown[4];Interface*output;int initialize(){return ((int(*)(Service*))table[5])(this);}};
struct Owner {unsigned unknown[12];List services;unsigned unknown60[11];int primary,mode;unsigned unknown112;int enabled;unsigned unknown120[13];Held output;int done;};
extern char key_80416cb8[],key_80416e78[];
extern "C" Interface*fn_8020b680(const void*);
extern "C" void fn_801e344c(Interface*,Interface*);
extern "C" int g4b_start_services_801db478(Owner*self){
 self->enabled=1;
 int result=0;Held current=Held(0),primary=Held(0);self->mode=1;
 if(self->primary){
  current.set(fn_8020b680(key_80416cb8));primary=current;
  result=((Service*)current.p)->initialize();
  self->output.clear();self->output.set(((Service*)current.p)->output);
  if(result)goto finish;
  self->services.append(current.p);
 }
 if(!self->enabled)self->done=1;
 else{
  if(self->mode<2 && self->mode>=0){
   current.set(fn_8020b680(key_80416e78));result=((Service*)current.p)->initialize();
   if(self->output.p)fn_801e344c(current.p,self->output.p);
  }
  if(!result)self->services.append(current.p);
 }
 finish:return result;
}
