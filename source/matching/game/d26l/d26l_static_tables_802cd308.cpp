// GWMP8P rev0 0x802cd308. Guarded static initializer called from the wrapper
// at 0x802cd3dc with (1, 0xffff). Vec is a partial view: three null words at
// +0, +4, +12 and a block-mode allocator temporary that accounts for the
// 8-byte frame slot, the shape of an STLport vector with an allocator proxy
// at +8. That reading is inference.
inline void *operator new(unsigned int, void *place) { return place; }
struct Alloc{Alloc(){}Alloc(const Alloc&){}};
struct Proxy:Alloc{void*data;Proxy(const Alloc&x,void*p):Alloc(x),data(p){}};
struct Vec{void*start;void*finish;Proxy end;Vec(const Alloc&a=Alloc()):start(0),finish(0),end(a,0){}};
struct Word{void*value;Word(){value=0;}};
extern Word count_804b10b0;
extern Word a_80473724[16],b_80473764[16];
extern Vec c_804737a4[16];
extern Word d_804738a4[16],e_804738e4[16];
extern "C" void d26l_static_tables_802cd308(int initialize,int priority){
 if(priority==0xffff&&initialize){
  new(&count_804b10b0)Word;
  {Word*p=a_80473724;for(int i=16;i;--i){new(p)Word;++p;}}
  {Word*p=b_80473764;for(int i=16;i;--i){new(p)Word;++p;}}
  {Vec*p=c_804737a4;for(int i=16;i;--i){new(p)Vec;++p;}}
  {Word*p=d_804738a4;for(int i=16;i;--i){new(p)Word;++p;}}
  {Word*p=e_804738e4;for(int i=16;i;--i){new(p)Word;++p;}}
 }
}
