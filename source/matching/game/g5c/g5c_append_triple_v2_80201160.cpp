// Original call includes the legacy unprototyped PowerPC condition-register setup.
extern "C" void* memset(...);
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
  for(Triple* at=begin;at!=position;++at,++out)if(out)new(out)Triple(*at);
  if(count==1){if(out)new(out)Triple(value);++out;}
  else {for(unsigned remaining=count;remaining;--remaining,++out)if(out)new(out)Triple(value);}
  for(Triple* at=begin;at!=end;++at)at->~Triple();
  if(begin)fn_802134fc(begin);
  begin=fresh;capacity=(Triple*)((char*)fresh+bytes);end=out;
 }
};
struct Owner {char unknown[44];TripleVectorView records;};
extern "C" int g5c_append_triple_80201160(Owner* owner,unsigned a,unsigned b,unsigned c) {
 Triple temporary;
 if(owner->records.end==owner->records.capacity){temporary.a=a;temporary.b=b;temporary.c=c;owner->records.grow(owner->records.end,1,temporary);}
 else {if(owner->records.end)new(owner->records.end)Triple(a,b,c);++owner->records.end;}
 return 0;
}
