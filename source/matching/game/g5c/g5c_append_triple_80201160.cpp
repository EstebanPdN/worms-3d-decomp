extern "C" void* memset(void*,int,unsigned);
extern "C" void* fn_80212fd4(unsigned);
extern "C" void* fn_803413d8(unsigned);
extern "C" void fn_802134fc(void*);
inline void* operator new(unsigned,void* p) {return p;}
struct Triple {
 unsigned a,b,c;
 Triple() {memset(this,0,sizeof(*this));}
 Triple(unsigned x,unsigned y,unsigned z):a(x),b(y),c(z){}
 Triple(const Triple& v) {unsigned x=v.a,y=v.b,z=v.c;a=x;b=y;c=z;}
};
inline const unsigned& larger(const unsigned& a,const unsigned& b){return a<b?b:a;}
struct TripleVectorView {
 Triple* begin;
 Triple* end;
 unsigned allocatorState;
 Triple* capacity;
 void grow(Triple* position,unsigned count,const Triple& value) {
  unsigned oldSize=end-begin;
  unsigned newCount=oldSize+larger(oldSize,count);
  unsigned bytes=newCount*sizeof(Triple);
  Triple* fresh=0;
  if(newCount){fresh=(Triple*)fn_80212fd4(bytes);if(!fresh)fresh=(Triple*)fn_803413d8(bytes);}
  Triple* out=fresh;
  for(Triple* at=begin;at!=position;++at,++out)new(out)Triple(*at);
  if(count==1){new(out)Triple(value);++out;}
  else {for(unsigned remaining=count;remaining;--remaining,++out)new(out)Triple(value);}
  for(Triple* at=begin;at!=end;++at)at->~Triple();
  if(begin)fn_802134fc(begin);
  begin=fresh;capacity=(Triple*)((char*)fresh+bytes);end=out;
 }
};
struct Owner;
extern "C" int g5c_append_triple_80201160(Owner* owner,unsigned a,unsigned b,unsigned c) {
 Triple temporary;
 TripleVectorView* vector=(TripleVectorView*)((char*)owner+44);
 if(vector->end==vector->capacity){temporary.a=a;temporary.b=b;temporary.c=c;vector->grow(vector->end,1,temporary);}
 else {new(vector->end)Triple(a,b,c);++vector->end;}
 return 0;
}
