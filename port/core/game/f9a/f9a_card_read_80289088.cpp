#include "w3d_ptr.h"
#line 1 "f9a_card_read_80289088.cpp"
// Partial views of render interface and 2048-byte copied payload; no allocation inferred.
struct F9aCardObj{Ptr32<Ptr32<void>> table;};
inline void retain(Ptr32<F9aCardObj> p){if(p)((Ptr32<void (Ptr32<F9aCardObj>)>)p->table[3])(p);}inline void release(Ptr32<F9aCardObj> p){if(p)((Ptr32<void (Ptr32<F9aCardObj>)>)p->table[4])(p);}
struct F9aCardHandle{
 F9aCardHandle(const F9aCardHandle &);Ptr32<F9aCardObj> p;F9aCardHandle():p(0){}template <class W3dU> F9aCardHandle(Ptr32<W3dU> w3d_p) : F9aCardHandle((F9aCardObj *)w3d_p.get()) {}
 F9aCardHandle(F9aCardObj*q):p(q){retain(q);}~F9aCardHandle(){release(p);}void clear(){release(p);p=0;}};
struct F9aCardText_8020bb54{
 F9aCardText_8020bb54(const F9aCardText_8020bb54 &);Ptr32<char> text;template <class W3dU> F9aCardText_8020bb54(Ptr32<W3dU> w3d_p) : F9aCardText_8020bb54((const char *)w3d_p.get()) {}
 F9aCardText_8020bb54(const char*);~F9aCardText_8020bb54();};
extern "C" void fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
inline F9aCardText_8020bb54::~F9aCardText_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}
struct F9aCardPayload{int words[512];};struct F9aCardBlob{char unknown[32];F9aCardPayload data;};struct F9aCardResource{char unknown[48];Ptr32<F9aCardBlob> blob;char unknown52[8];Ptr32<void> font;};
extern "C" Ptr32<void> fn_8015adf4(Ptr32<F9aCardText_8020bb54>,Ptr32<F9aCardHandle>,int);
extern "C" Ptr32<F9aCardResource> fn_80174074(Ptr32<F9aCardObj>);
extern char type_80413db0[];extern int tint_804b195c;
extern "C" Ptr32<F9aCardObj> fn_8020b680(Ptr32<void>);
inline void*operator new(__SIZE_TYPE__,void*p){return p;}
struct F9aCardSlot{int words[2];~F9aCardSlot(){((Ptr32<F9aCardHandle>)this)->~F9aCardHandle();}};
extern "C" void w3d_f9a_card_read_80289088(Ptr32<void>,Ptr32<const char> name,Ptr32<F9aCardPayload> out){
 F9aCardHandle source;F9aCardSlot slot;Ptr32<F9aCardText_8020bb54> text=(Ptr32<F9aCardText_8020bb54>)&slot;new(text)F9aCardText_8020bb54(name);fn_8015adf4(text,&source,255);text->~F9aCardText_8020bb54();
 Ptr32<void> font=fn_80174074(source.p)->font;
 Ptr32<F9aCardHandle> render=new(&slot)F9aCardHandle(fn_8020b680(type_80413db0));
 ((Ptr32<void (Ptr32<F9aCardObj>, int)>)render->p->table[14])(render->p,4);
 ((Ptr32<void (Ptr32<F9aCardObj>, int)>)render->p->table[36])(render->p,0);
 ((Ptr32<void (Ptr32<F9aCardObj>, int)>)render->p->table[16])(render->p,1);
 ((Ptr32<void (Ptr32<F9aCardObj>, Ptr32<int>, int)>)render->p->table[20])(render->p,&tint_804b195c,1);
 ((Ptr32<void (Ptr32<F9aCardObj>, Ptr32<void>)>)render->p->table[6])(render->p,font);
 // Observed font object also has the payload owner at byte48.
 *out=((Ptr32<F9aCardResource>)font)->blob->data;
 source.clear();
}


