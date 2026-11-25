// GC32 registry entry views, inferred from the complete original.
// The metadata word has no native default store; it is overwritten from the
// supplied complete signature before any comparison or copy can read it.
namespace sol35d7_erase_signature {
struct Signature {
 unsigned first,second,third,fourth,metadata;
 Signature():first(3),second(4),third(0),fourth(0) {}
 bool operator!=(const Signature &o) const {
  return first!=o.first || fourth!=o.fourth || second!=o.second || third!=o.third;
 }
 bool operator==(const Signature &o) const {return !(*this!=o);}
};
struct Entry {
 unsigned key;
 Signature signature;
 Entry():key(0) {}
 bool operator==(const Entry &o) const {
  return key==o.key && signature==o.signature;
 }
};
struct Registry {Entry *begin,*end,*capacity;};
typedef char SignatureSize[(sizeof(Signature)==20)?1:-1];
typedef char EntrySize[(sizeof(Entry)==24)?1:-1];
inline Entry *copy(Entry *first,Entry *last,Entry *out) {
 for(int n=last-first;n>0;--n) *out++=*first++;
 return out;
}
}
extern "C" int sol35d7_erase_signature_801f9c60(sol35d7_erase_signature::Registry *self,unsigned key,const sol35d7_erase_signature::Signature *signature) {
 using namespace sol35d7_erase_signature;
 Entry sought;
 sought.key=key;
 sought.signature=*signature;
 for(Entry *it=self->begin;it!=self->end;++it) {
  if(*it==sought) {
   if(it+1!=self->end) copy(it+1,self->end,it);
   --self->end;
   return 0;
  }
 }
 return static_cast<int>(0x80004005U);
}
