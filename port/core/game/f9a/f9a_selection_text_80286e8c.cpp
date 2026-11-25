#include "w3d_ptr.h"
#line 1 "f9a_selection_text_80286e8c.cpp"
// Partial selection, entry and shared-string views. Semantic names inferred.
extern "C" void fn_8020c5c0(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_8020bb2c(Ptr32<void>);
struct F9aSelectHeader{unsigned short refs,length,capacity;};extern "C" Ptr32<F9aSelectHeader> fn_80341884(Ptr32<void>);
struct F9aSelectText{Ptr32<char> text;F9aSelectText(const F9aSelectText&o){fn_8020c5c0(this);text=o.text;++fn_80341884(this)->refs;}~F9aSelectText(){fn_8020c5c4(this);fn_80341588(this);}F9aSelectText&operator=(const F9aSelectText&o){Ptr32<F9aSelectHeader> h=(Ptr32<F9aSelectHeader>)(o.text-6);++h->refs;h=(Ptr32<F9aSelectHeader>)(text-6);if(--h->refs==0)fn_8020bb2c(h);text=o.text;return *this;}unsigned length()const{return *(Ptr32<unsigned short>)(text-4);}};
struct F9aSelectIface{Ptr32<Ptr32<void>> table;};struct F9aSelectHandle{
 F9aSelectHandle(const F9aSelectHandle &);Ptr32<F9aSelectIface> p;F9aSelectHandle():p(0){}~F9aSelectHandle(){if(p)((Ptr32<void (Ptr32<F9aSelectIface>)>)p->table[4])(p);}};
struct F9aSelectEntry{Ptr32<F9aSelectIface> held;int index;Ptr32<char> text;};struct F9aSelectConfig{char unknown[68];Ptr32<char> text;};
struct F9aSelectView{char unknown[28];char base[12];Ptr32<F9aSelectConfig> config;char unknown44[52];Ptr32<F9aSelectIface> target;char unknown100[8];Ptr32<char> error;char unknown112[112];Ptr32<F9aSelectEntry> begin; Ptr32<F9aSelectEntry> end; Ptr32<F9aSelectEntry> capacity;int unknown236;unsigned selected;};
struct F9aSelectContext{char unknown[188];unsigned flags;};extern Ptr32<F9aSelectContext> context_804b1788;
struct F9aSelectKey{Ptr32<const char> text;template <class W3dU> F9aSelectKey(Ptr32<W3dU> w3d_p) : F9aSelectKey((const char *)w3d_p.get()) {}
 F9aSelectKey(const char*p):text(p){}};
extern "C" int fn_800fc1b0(const F9aSelectKey&,F9aSelectHandle&),fn_801790bc(Ptr32<F9aSelectIface>,Ptr32<const char>);
extern "C" Ptr32<F9aSelectIface> fn_80343744(Ptr32<F9aSelectIface>);extern "C" Ptr32<F9aSelectText> fn_80179170(Ptr32<F9aSelectIface>);
extern "C" void fn_802b1714(Ptr32<void>),fn_8020c510(Ptr32<void>,Ptr32<const char>,...);
extern char error_803cf4c4[],empty_803cf460[];
extern "C" void w3d_f9a_selection_text_80286e8c(Ptr32<F9aSelectView> self){
 Ptr32<F9aSelectEntry> begin=self->begin;int count=self->end-begin;
 unsigned selected;
 if(!count || (selected=self->selected)>=(unsigned)count){fn_802b1714(self->base);return;}
 if(!*(Ptr32<unsigned short>)(self->error-4)||!(context_804b1788->flags&0x40000000)){
 F9aSelectText text(*(Ptr32<F9aSelectText>)&begin[selected].text);
 if(!text.length()&&self->selected)text=*(Ptr32<F9aSelectText>)&begin->text;
 if(!text.length())text=*(Ptr32<F9aSelectText>)&self->config->text;
 if(text.length()){
  F9aSelectHandle value;F9aSelectKey key(text.text);
  if(fn_800fc1b0(key,value)>=0){Ptr32<F9aSelectIface> target=fn_80343744(self->target);fn_801790bc(target,fn_80179170(fn_80343744(value.p))->text);}
  else{fn_8020c510(&self->error,error_803cf4c4,w3d::VA(text.text));fn_801790bc(fn_80343744(self->target),self->error);}
 }else fn_801790bc(fn_80343744(self->target),empty_803cf460);
 }else fn_801790bc(fn_80343744(self->target),self->error);
}


