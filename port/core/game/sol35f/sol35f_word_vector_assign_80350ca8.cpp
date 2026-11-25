#include "w3d_ptr.h"
#line 1 "sol35f_word_vector_assign_80350ca8.cpp"
// GC32 vector assignment at 0x80350ca8. Observed 16-byte vector with copied
// 4-byte elements. Type/algorithm names are inferred. The addressable trivial
// copy and destruction dispatch tags preserve the original inline lifetimes;
// no source or runtime identity of an STL implementation is claimed.
// Portability: pointer differences assume a valid same-array GC32 container.
// Null-empty pointer subtraction follows the reference library idiom and is
// not a portable ISO C++ guarantee; this unit is instruction proof only.
extern "C" Ptr32<void> sol35f_allocate_801907a8(unsigned);
extern "C" void sol35f_free_801907d0(Ptr32<void>);
extern "C" Ptr32<void> sol35f_memmove_802eeef4(Ptr32<void>,Ptr32<const void>,unsigned);
struct Sol35fTrivial { char w3d_empty; };
template<class T> inline Ptr32<T> sol35f_copy(const T *first,const T *last,T *out,const Sol35fTrivial &) {
 if(last!=first) { unsigned n=(Ptr32<char>)last-(Ptr32<char>)first; sol35f_memmove_802eeef4(out,first,n); }
 return out+(last-first);
}
template<class T> inline void sol35f_destroy(T *,T *,const Sol35fTrivial &) {}
template<class T> struct Sol35fVector {
 Ptr32<T> start; Ptr32<T> finish; unsigned allocator; Ptr32<T> storage_end;
 unsigned size() const { return finish-start; }
 unsigned capacity() const { return storage_end-start; }
 Ptr32<T> allocate_copy(unsigned n,Ptr32<const T> first,Ptr32<const T> last) {
  Ptr32<T> p=(Ptr32<T>)sol35f_allocate_801907a8(n*sizeof(T));
  sol35f_copy(w3d::R(first),w3d::R(last),w3d::R(p),Sol35fTrivial());return p;
 }
 Sol35fVector &operator=(const Sol35fVector &x) {
  if(&x!=this) {
   unsigned length=x.size();
   if(length>capacity()) {
    Ptr32<T> tmp=allocate_copy(length,x.start,x.finish);
    if(start) sol35f_free_801907d0(start);
    start=tmp;storage_end=start+length;
   }else if(size()>=length) {
    sol35f_destroy(w3d::R(sol35f_copy(w3d::R(x.start),w3d::R(x.finish),w3d::R(start),Sol35fTrivial())),w3d::R(finish),Sol35fTrivial());
   }else {
    sol35f_copy(w3d::R(x.start),w3d::R(x.start+size()),w3d::R(start),Sol35fTrivial());
    sol35f_copy(w3d::R(x.start+size()),w3d::R(x.finish),w3d::R(finish),Sol35fTrivial());
   }
   finish=start+length;
  }
  return *this;
 }
};
extern "C" Ptr32<Sol35fVector < unsigned int >> sol35f_word_vector_assign_80350ca8(Ptr32<Sol35fVector < unsigned int >> self,Ptr32<const Sol35fVector < unsigned int >> x) { return &(*self=*x); }

typedef char Sol35fVectorSize[(sizeof(Sol35fVector<unsigned>)==16)?1:-1];


