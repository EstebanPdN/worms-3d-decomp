// GC32 vector assignment at 0x80350ca8. Observed 16-byte vector with copied
// 4-byte elements. Type/algorithm names are inferred. The addressable trivial
// copy and destruction dispatch tags preserve the original inline lifetimes;
// no source or runtime identity of an STL implementation is claimed.
// Portability: pointer differences assume a valid same-array GC32 container.
// Null-empty pointer subtraction follows the reference library idiom and is
// not a portable ISO C++ guarantee; this unit is instruction proof only.
extern "C" void *sol35f_allocate_801907a8(unsigned);
extern "C" void sol35f_free_801907d0(void *);
extern "C" void *sol35f_memmove_802eeef4(void *,const void *,unsigned);
struct Sol35fTrivial {};
template<class T> inline T *sol35f_copy(const T *first,const T *last,T *out,const Sol35fTrivial &) {
 if(last!=first) { unsigned n=(char *)last-(char *)first; sol35f_memmove_802eeef4(out,first,n); }
 return out+(last-first);
}
template<class T> inline void sol35f_destroy(T *,T *,const Sol35fTrivial &) {}
template<class T> struct Sol35fVector {
 T *start,*finish; unsigned allocator; T *storage_end;
 unsigned size() const { return finish-start; }
 unsigned capacity() const { return storage_end-start; }
 T *allocate_copy(unsigned n,const T *first,const T *last) {
  T *p=(T *)sol35f_allocate_801907a8(n*sizeof(T));
  sol35f_copy(first,last,p,Sol35fTrivial());return p;
 }
 Sol35fVector &operator=(const Sol35fVector &x) {
  if(&x!=this) {
   unsigned length=x.size();
   if(length>capacity()) {
    T *tmp=allocate_copy(length,x.start,x.finish);
    if(start) sol35f_free_801907d0(start);
    start=tmp;storage_end=start+length;
   }else if(size()>=length) {
    sol35f_destroy(sol35f_copy(x.start,x.finish,start,Sol35fTrivial()),finish,Sol35fTrivial());
   }else {
    sol35f_copy(x.start,x.start+size(),start,Sol35fTrivial());
    sol35f_copy(x.start+size(),x.finish,finish,Sol35fTrivial());
   }
   finish=start+length;
  }
  return *this;
 }
};
extern "C" Sol35fVector<unsigned> *sol35f_word_vector_assign_80350ca8(Sol35fVector<unsigned> *self,const Sol35fVector<unsigned> *x) { return &(*self=*x); }

typedef char Sol35fVectorSize[(sizeof(Sol35fVector<unsigned>)==16)?1:-1];
