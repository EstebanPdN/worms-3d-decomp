// Partial views of render interface and 2048-byte copied payload; no allocation inferred.
struct F9aCardObj{void**table;};
inline void retain(F9aCardObj*p){if(p)((void(*)(F9aCardObj*))p->table[3])(p);}inline void release(F9aCardObj*p){if(p)((void(*)(F9aCardObj*))p->table[4])(p);}
struct F9aCardHandle{
 F9aCardHandle(const F9aCardHandle &);F9aCardObj*p;F9aCardHandle():p(0){}F9aCardHandle(F9aCardObj*q):p(q){retain(q);}~F9aCardHandle(){release(p);}void clear(){release(p);p=0;}};
struct F9aCardText_8020bb54{
 F9aCardText_8020bb54(const F9aCardText_8020bb54 &);char*text;F9aCardText_8020bb54(const char*);~F9aCardText_8020bb54();};
extern "C" void fn_8020c5c4(void*),fn_80341588(void*);
inline F9aCardText_8020bb54::~F9aCardText_8020bb54(){fn_8020c5c4(this);fn_80341588(this);}
struct F9aCardPayload{int words[512];};struct F9aCardBlob{char unknown[32];F9aCardPayload data;};struct F9aCardResource{char unknown[48];F9aCardBlob*blob;char unknown52[8];void*font;};
extern "C" void * fn_8015adf4(F9aCardText_8020bb54*,F9aCardHandle*,int);
extern "C" F9aCardResource*fn_80174074(F9aCardObj*);
extern char type_80413db0[];extern int tint_804b195c;
extern "C" F9aCardObj*fn_8020b680(void*);
inline void*operator new(unsigned int,void*p){return p;}
struct F9aCardSlot{int words[2];~F9aCardSlot(){((F9aCardHandle*)this)->~F9aCardHandle();}};
extern "C" void w3d_f9a_card_read_80289088(void*,const char*name,F9aCardPayload*out){
 F9aCardHandle source;F9aCardSlot slot;F9aCardText_8020bb54*text=(F9aCardText_8020bb54*)&slot;new(text)F9aCardText_8020bb54(name);fn_8015adf4(text,&source,255);text->~F9aCardText_8020bb54();
 void*font=fn_80174074(source.p)->font;
 F9aCardHandle*render=new(&slot)F9aCardHandle(fn_8020b680(type_80413db0));
 ((void(*)(F9aCardObj*,int))render->p->table[14])(render->p,4);
 ((void(*)(F9aCardObj*,int))render->p->table[36])(render->p,0);
 ((void(*)(F9aCardObj*,int))render->p->table[16])(render->p,1);
 ((void(*)(F9aCardObj*,int*,int))render->p->table[20])(render->p,&tint_804b195c,1);
 ((void(*)(F9aCardObj*,void*))render->p->table[6])(render->p,font);
 // Observed font object also has the payload owner at byte48.
 *out=((F9aCardResource*)font)->blob->data;
 source.clear();
}
