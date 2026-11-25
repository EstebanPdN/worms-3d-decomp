#include "w3d_ptr.h"
#line 1 "d24f_record_vector_resize_80349d40.cpp"
// GWMP8P rev0 0x80349d40. Observed 32-byte retained records: word, three
// held interfaces, counted reference array, trailing word (layout from
// sol35f6a_record32_insert_80347dec). The real tail copy folds away but its
// const tag temporary keeps the finish reload (d24d finding), with STLport-
// shaped three-layer destroy.
struct D24fInterface {
 void w3d_r_slot0() __asm__(W3D_SYM("_ZN13D24fInterface5slot0Ev"));
 void w3d_r_retain() __asm__(W3D_SYM("_ZN13D24fInterface6retainEv"));
 void w3d_r_release() __asm__(W3D_SYM("_ZN13D24fInterface7releaseEv"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D24fInterface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D24fInterface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_D24fInterface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_D24fInterface; };
struct D24fHeld {
 Ptr32<D24fInterface> pointer;
 D24fHeld():pointer(0) {}
 ~D24fHeld() { if(pointer) pointer->release(); }
};
struct D24fRefs;
extern "C" Ptr32<D24fRefs> w3d_construct_802109dc(Ptr32<D24fRefs>);
extern "C" void w3d_auto_80210abc(Ptr32<D24fRefs>,int);
struct D24fRefs {
 unsigned count;
 unsigned short capacity,growth;
 Ptr32<Ptr32<D24fInterface>> slots;
 D24fRefs() { w3d_construct_802109dc(this); }
 ~D24fRefs() { w3d_auto_80210abc(this,2); }
};
struct D24fRecord {
 unsigned key;
 D24fHeld a,b,c;
 D24fRefs refs;
 unsigned payload;
 D24fRecord &operator=(const D24fRecord &x);
};
struct D24fRecordVector {
 Ptr32<D24fRecord> start; Ptr32<D24fRecord> finish;
 int allocator;
 Ptr32<D24fRecord> storage_end;
 unsigned size() const { return finish-start; }
 Ptr32<D24fRecord> erase(Ptr32<D24fRecord> first,Ptr32<D24fRecord> last);
 void resize(unsigned n,const D24fRecord &x);
};
extern "C" void sol35f6a_record32_insert_80349260(Ptr32<D24fRecordVector>,Ptr32<D24fRecord>,unsigned,const D24fRecord &);
template<class T> inline void d24f_destroy(T *p) { p->~T(); }
struct D24fNotPod { char w3d_empty; };
template<class T> inline void d24f_destroy_aux(T *first,T *last,const D24fNotPod &) { for(;first!=last;++first) d24f_destroy(w3d::R(first)); }
template<class T> inline void d24f_destroy_typed(T *first,T *last,T *) { d24f_destroy_aux(w3d::R(first),w3d::R(last),D24fNotPod()); }
template<class T> inline void d24f_destroy_range(T *first,T *last) { d24f_destroy_typed(w3d::R(first),w3d::R(last),w3d::R((Ptr32<T>)0)); }
template<class T> inline Ptr32<T> d24f_copy_ptrs(const T *first,const T *last,T *out,const D24fNotPod &) { for(int n=last-first;n>0;--n) { *out=*first;++first;++out; } return out; }
inline Ptr32<D24fRecord> D24fRecordVector::erase(Ptr32<D24fRecord> first,Ptr32<D24fRecord> last) {
 Ptr32<D24fRecord> kept=d24f_copy_ptrs(w3d::R((Ptr32<const D24fRecord>)last),w3d::R((Ptr32<const D24fRecord>)finish),w3d::R(first),D24fNotPod());
 d24f_destroy_range(w3d::R(kept),w3d::R(finish));
 finish=kept;
 return first;
}
inline void D24fRecordVector::resize(unsigned n,const D24fRecord &x) {
 if(n<size()) erase(start+n,finish);
 else sol35f6a_record32_insert_80349260(this,finish,n-size(),x);
}
struct D24fRecordOwner {
 char pad[20];
 unsigned count;
 D24fRecordVector records;
};
extern "C" int d24f_record_vector_resize_80349d40(Ptr32<D24fRecordOwner> self,unsigned n) {
 self->records.resize(n,D24fRecord());
 self->count=n;
 return 0;
}


