#include "w3d_ptr.h"
#line 1 "sol35f6a_record32_insert_80347dec.cpp"
// GWMP8P rev0: repeated insertion of observed 32-byte retained records.
// GC32 outer vector: start +0, finish +4, allocator base +8, storage end +12.
// Element: word +0; held interfaces +4/+8/+12; counted-reference array +16;
// payload word +28. Interface retain/release dispatch at +12/+16 requires
// the observed four-byte thunk vtable ABI (-fvtable-thunks).
// Copy construction/destruction follows member lifetimes. Growth initializes
// its advancing destination iterator from new_start before the first copy.
// Names, semantic types and STL identity remain inferred. Valid storage,
// live compatible interfaces, representable same-array pointer arithmetic
// and external allocator/copy/destructor contracts are required. Native
// null-empty subtraction is not an ISO C++ portability guarantee.
inline void *operator new(__SIZE_TYPE__,void *place) throw() { return place; }
extern "C" Ptr32<void> sol35f6a_allocate_80212fd4(unsigned);
extern "C" Ptr32<void> sol35f6a_fallback_803413d8(unsigned);
extern "C" void sol35f6a_release_802134fc(Ptr32<void>);
// Fresh record ABI from 0x80347dec: word, three retained interfaces,
// 12-byte counted reference array, trailing word. All names are inferred.
struct Interface {
 void w3d_r_slot0() __asm__(W3D_SYM("_ZN9Interface5slot0Ev"));
 void w3d_r_retain() __asm__(W3D_SYM("_ZN9Interface6retainEv"));
 void w3d_r_release() __asm__(W3D_SYM("_ZN9Interface7releaseEv"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Interface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Interface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Interface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Interface; };
struct HeldInterface {
 Ptr32<Interface> pointer;
 HeldInterface(const HeldInterface &x):pointer(x.pointer) { if(pointer) pointer->retain(); }
 ~HeldInterface() { if(pointer) pointer->release(); }
};
struct CountedRefs;
extern "C" Ptr32<CountedRefs> sol35f6a_copy_refs_802109fc(Ptr32<CountedRefs>,Ptr32<const CountedRefs>);
extern "C" void sol35f6a_destroy_refs_80210abc(Ptr32<CountedRefs>,int);
struct CountedRefs {
 unsigned count;
 unsigned short capacity,growth;
 Ptr32<Ptr32<Interface>> slots;
 CountedRefs(const CountedRefs &x) { sol35f6a_copy_refs_802109fc(this,&x); }
 ~CountedRefs() { sol35f6a_destroy_refs_80210abc(this,2); }
};
struct RefRecord;
extern "C" Ptr32<RefRecord> sol35f6a_assign_80347ce0(Ptr32<RefRecord>,Ptr32<const RefRecord>);
struct RefRecord {
 unsigned key;
 HeldInterface a,b,c;
 CountedRefs refs;
 unsigned payload;
 RefRecord &operator=(const RefRecord &x) { sol35f6a_assign_80347ce0(this,&x); return *this; }
};
template<class T> struct FillAllocator {
    FillAllocator() {}
    FillAllocator(const FillAllocator &) {}
    static Ptr32<void> storage(unsigned bytes) {Ptr32<void> p=sol35f6a_allocate_80212fd4(bytes);if(!p)p=sol35f6a_fallback_803413d8(bytes);return p;}
    Ptr32<T> allocate(unsigned count) {return count?(Ptr32<T>)storage(count*sizeof(T)):0;}
    void deallocate(Ptr32<T> p,unsigned) { if(p) sol35f6a_release_802134fc(p); }
 char w3d_empty; };
template<class T> struct FillStorageEnd : FillAllocator<T> { Ptr32<T> data __attribute__((aligned(__alignof__(FillAllocator<T>)))); };
template<class T> inline const T &fill_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void fill_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void fill_destroy(T *p) { p->~T(); }
template<class T> inline void fill_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) fill_destroy(w3d::R(first));
}
template<class T> inline void fill_destroy_range(T *first,T *last) { fill_destroy_range_aux(w3d::R(first),w3d::R(last)); }
struct FillNotTrivial { char w3d_empty; };
template<class T> inline Ptr32<T> fill_uninitialized_copy(const T *first,const T *last,T *out,const FillNotTrivial &) {
    for(;first!=last;++first,++out) fill_construct(w3d::R(out),*first);
    return out;
}
template<class T> inline Ptr32<T> fill_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) fill_construct(w3d::R(out),value);
    return out;
}
template<class T> inline Ptr32<T> fill_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void fill_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct FillVector {
    Ptr32<T> start; Ptr32<T> finish;
    FillStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        fill_destroy_range(w3d::R(start),w3d::R(finish));
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(Ptr32<T> s,Ptr32<T> f,Ptr32<T> e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(Ptr32<T> pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+fill_max(old_size,fill_len);
        Ptr32<T> new_start=end_of_storage.allocate(len);
        Ptr32<T> new_finish=new_start;
        new_finish=fill_uninitialized_copy(w3d::R((Ptr32<const T>)start),w3d::R((Ptr32<const T>)pos),w3d::R(new_finish),FillNotTrivial());
        if(fill_len==1) {
            fill_construct(w3d::R(new_finish),x);
            ++new_finish;
        } else {
            new_finish=fill_uninitialized_fill_n(w3d::R(new_finish),fill_len,x);
        }
        new_finish=fill_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)finish),w3d::R(new_finish),FillNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }
};
typedef FillVector<RefRecord> RefRecordVector;
typedef char RefRecordFootprint[(sizeof(RefRecord)==32)?1:-1];
typedef char FillVectorFootprint[(sizeof(RefRecordVector)==16)?1:-1];
extern "C" void sol35f6a_record32_insert_80347dec(Ptr32<RefRecordVector> self,Ptr32<RefRecord> pos,unsigned n,const RefRecord &x) {
    typedef RefRecord T;
        if(n!=0) {
            if(unsigned(self->end_of_storage.data-self->finish)>=n) {
                T x_copy=x;
                const unsigned elems_after=self->finish-pos;
                Ptr32<T> old_finish=self->finish;
                if(elems_after>n) {
                    fill_uninitialized_copy(w3d::R((Ptr32<const T>)(self->finish-n)),w3d::R((Ptr32<const T>)self->finish),w3d::R(self->finish),FillNotTrivial());
                    self->finish+=n;
                    fill_copy_backward(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)(old_finish-n)),w3d::R(old_finish));
                    fill_assign(w3d::R(pos),w3d::R(pos+n),x_copy);
                } else {
                    fill_uninitialized_fill_n(w3d::R(self->finish),n-elems_after,x_copy);
                    self->finish+=n-elems_after;
                    fill_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)old_finish),w3d::R(self->finish),FillNotTrivial());
                    self->finish+=elems_after;
                    fill_assign(w3d::R(pos),w3d::R(old_finish),x_copy);
                }
            } else {
                self->insert_overflow(pos,x,n);
            }
        }
}


