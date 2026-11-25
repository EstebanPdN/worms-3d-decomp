#include "w3d_ptr.h"
#line 1 "f9a_image_resolve_8028d8ec.cpp"
// Inferred shared-string lifetimes and partial image/listener view.
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
struct F9aImageHeader{unsigned short refs,length,capacity;};
struct F9aImageText{
 F9aImageText(const F9aImageText &); F9aImageText() {}Ptr32<char> text;~F9aImageText(){fn_8020c5c4(this);fn_80341588(this);}F9aImageText&operator=(const F9aImageText&o){Ptr32<F9aImageHeader> h=(Ptr32<F9aImageHeader>)(o.text-6);++h->refs;h=(Ptr32<F9aImageHeader>)(text-6);if(--h->refs==0)fn_8020bb2c(h);text=o.text;return *this;}};
struct F9aImageIface{Ptr32<Ptr32<void>> table;};struct F9aImageHandle{
 F9aImageHandle(const F9aImageHandle &);Ptr32<F9aImageIface> p;F9aImageHandle():p(0){}~F9aImageHandle(){if(p)((Ptr32<void (Ptr32<F9aImageIface>)>)p->table[4])(p);}};
struct F9aImageKey{Ptr32<const char> text;template <class W3dU> F9aImageKey(Ptr32<W3dU> w3d_p) : F9aImageKey((const char *)w3d_p.get()) {}
 F9aImageKey(const char*p):text(p){}};
struct F9aImageView{char unknown[212];int listener;};
extern char empty_803cffb8[];
extern "C" Ptr32<F9aImageText> fn_8020bd38(Ptr32<F9aImageText>,Ptr32<const char>);
extern "C" int fn_800fc1b0(const F9aImageKey&,F9aImageHandle&),fn_8028daa8(Ptr32<F9aImageView>,Ptr32<F9aImageText>);
extern "C" Ptr32<F9aImageIface> fn_80343744(Ptr32<F9aImageIface>);
extern "C" Ptr32<F9aImageText> fn_80179170(Ptr32<F9aImageIface>);
extern "C" void fn_800fd62c(Ptr32<F9aImageText>,Ptr32<void>,Ptr32<F9aImageView>,Ptr32<int>);
extern "C" int fn_8028dc30(Ptr32<void>, Ptr32<void>);
inline void register_listener(Ptr32<F9aImageText> name,Ptr32<F9aImageView> self,Ptr32<int> slot){if(!*slot)fn_800fd62c(name,(Ptr32<void>)fn_8028dc30,self,slot);}
extern "C" int w3d_f9a_image_resolve_8028d8ec(Ptr32<F9aImageView> self,F9aImageText name,Ptr32<F9aImageText> out){
 if(!*(Ptr32<unsigned short>)(name.text-4)){fn_8020bd38(out,empty_803cffb8);return 0;}
 *out=name;
 {F9aImageHandle value;F9aImageKey key(out->text);
 if(fn_800fc1b0(key,value)>=0 && ((Ptr32<int (Ptr32<F9aImageIface>)>)value.p->table[6])(value.p)==4){
  register_listener(out,self,&self->listener);
  *out=*fn_80179170(fn_80343744(value.p));
  if(!*(Ptr32<unsigned short>)(out->text-4)){fn_8020bd38(out,empty_803cffb8);return 0;}
 }}
 return fn_8028daa8(self,out);
}


