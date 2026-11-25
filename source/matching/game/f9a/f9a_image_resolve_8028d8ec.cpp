// Inferred shared-string lifetimes and partial image/listener view.
extern "C" void fn_8020c5c4(void*),fn_80341588(void*),fn_8020bb2c(void*);
struct F9aImageHeader{unsigned short refs,length,capacity;};
struct F9aImageText{
 F9aImageText(const F9aImageText &); F9aImageText() {}char*text;~F9aImageText(){fn_8020c5c4(this);fn_80341588(this);}F9aImageText&operator=(const F9aImageText&o){F9aImageHeader*h=(F9aImageHeader*)(o.text-6);++h->refs;h=(F9aImageHeader*)(text-6);if(--h->refs==0)fn_8020bb2c(h);text=o.text;return *this;}};
struct F9aImageIface{void**table;};struct F9aImageHandle{
 F9aImageHandle(const F9aImageHandle &);F9aImageIface*p;F9aImageHandle():p(0){}~F9aImageHandle(){if(p)((void(*)(F9aImageIface*))p->table[4])(p);}};
struct F9aImageKey{const char*text;F9aImageKey(const char*p):text(p){}};
struct F9aImageView{char unknown[212];int listener;};
extern char empty_803cffb8[];
extern "C" F9aImageText*fn_8020bd38(F9aImageText*,const char*);
extern "C" int fn_800fc1b0(const F9aImageKey&,F9aImageHandle&),fn_8028daa8(F9aImageView*,F9aImageText*);
extern "C" F9aImageIface*fn_80343744(F9aImageIface*);
extern "C" F9aImageText*fn_80179170(F9aImageIface*);
extern "C" void fn_800fd62c(F9aImageText*,void*,F9aImageView*,int*);
extern "C" int fn_8028dc30(void *, void *);
inline void register_listener(F9aImageText*name,F9aImageView*self,int*slot){if(!*slot)fn_800fd62c(name,(void*)fn_8028dc30,self,slot);}
extern "C" int w3d_f9a_image_resolve_8028d8ec(F9aImageView*self,F9aImageText name,F9aImageText*out){
 if(!*(unsigned short*)(name.text-4)){fn_8020bd38(out,empty_803cffb8);return 0;}
 *out=name;
 {F9aImageHandle value;F9aImageKey key(out->text);
 if(fn_800fc1b0(key,value)>=0 && ((int(*)(F9aImageIface*))value.p->table[6])(value.p)==4){
  register_listener(out,self,&self->listener);
  *out=*fn_80179170(fn_80343744(value.p));
  if(!*(unsigned short*)(out->text-4)){fn_8020bd38(out,empty_803cffb8);return 0;}
 }}
 return fn_8028daa8(self,out);
}
