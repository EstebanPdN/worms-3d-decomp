#include "w3d_ptr.h"
#line 1 "mx19oc_nested_vector_reserve_8034efd0.cpp"
// 0x8034efd0: reserve() of a vector whose elements are vectors of 12-byte
// records. Inferred STLport-shaped container (identity unverified): begin at 0,
// finish at 4, an allocator proxy at 8 holding the storage-end pointer at proxy
// offset 4, 16 bytes per vector. Evidence for the lifetimes below:
//  - the element copy reads the source length before zeroing the destination,
//    so the length is an argument of an allocating base constructor;
//  - an 8-byte local slot is reserved but never written by data: the
//    by-value allocator temporary passed to that base constructor;
//  - placement construction is null-checked (operator new declared throw());
//  - destruction runs an empty loop over the 12-byte records before freeing.
// Allocation 0x801907a8 takes a byte count; release 0x801907d0 a block.
// Portability: the 16-byte layout assumes 32-bit pointers (checked below).
extern "C" Ptr32<void> native_array_allocate_801907a8(unsigned);
extern "C" void native_array_free_801907d0(Ptr32<void>);
inline void *operator new(__SIZE_TYPE__,void *place) throw() { return place; }
template<class T> struct NativeAllocator {
    NativeAllocator() {}
    NativeAllocator(const NativeAllocator &) {}
    Ptr32<T> allocate(unsigned count) { return (Ptr32<T>)native_array_allocate_801907a8(count*sizeof(T)); }
    void deallocate(Ptr32<T> p,unsigned) { if(p) native_array_free_801907d0(p); }
 char w3d_empty; };
template<class T> struct AllocatorProxy : NativeAllocator<T> {
    Ptr32<T> data __attribute__((aligned(__alignof__(NativeAllocator<T>))));
    AllocatorProxy(const NativeAllocator<T> &a,Ptr32<T> p):NativeAllocator<T>(a),data(p) {}
};
struct Triple { unsigned x,y,z; };
template<class T> inline void construct_at(T *p,const T &value) { new(p) T(value); }
template<class T> inline void destroy_at(T *p) { p->~T(); }
template<class T> inline Ptr32<T> uninitialized_copy_values(const T *first,const T *last,T *out) {
    for(;first!=last;++first,++out) construct_at(w3d::R(out),*first);
    return out;
}
template<class T> inline void destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) destroy_at(w3d::R(first));
}
template<class T> inline void destroy_range(T *first,T *last) { destroy_range_aux(w3d::R(first),w3d::R(last)); }
template<class T> struct VectorBase {
    Ptr32<T> start; Ptr32<T> finish;
    AllocatorProxy<T> end_of_storage;
    VectorBase(unsigned n,const NativeAllocator<T> &a):start(0),finish(0),end_of_storage(a,0) {
        start=end_of_storage.allocate(n);
        finish=start;
        end_of_storage.data=start+n;
    }
    ~VectorBase() { if(start!=0) end_of_storage.deallocate(start,end_of_storage.data-start); }
};
template<class T> struct NativeVector : VectorBase<T> { using VectorBase<T>::start; using VectorBase<T>::finish; using VectorBase<T>::end_of_storage;
    unsigned size() const { return finish-start; }
    unsigned capacity() const { return end_of_storage.data-start; }
    NativeAllocator<T> get_allocator() const { return end_of_storage; }
    NativeVector(const NativeVector &x):VectorBase<T>(x.size(),x.get_allocator()) {
        finish=uninitialized_copy_values<T>((const T *)x.start,(const T *)x.finish,start);
    }
    ~NativeVector() { destroy_range<T>(start,finish); }
    Ptr32<T> allocate_and_copy(unsigned n,Ptr32<const T> first,Ptr32<const T> last) {
        Ptr32<T> result=end_of_storage.allocate(n);
        uninitialized_copy_values<T>(w3d::R(first),w3d::R(last),w3d::R(result));
        return result;
    }
    void clear_storage() {
        destroy_range<T>(start,finish);
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(Ptr32<T> s,Ptr32<T> f,Ptr32<T> e) { start=s; finish=f; end_of_storage.data=e; }
    void reserve(unsigned n) {
        if(capacity()<n) {
            const unsigned old_size=size();
            Ptr32<T> tmp;
            if(start) {
                tmp=allocate_and_copy(n,start,finish);
                clear_storage();
            } else {
                tmp=end_of_storage.allocate(n);
            }
            set(tmp,tmp+old_size,tmp+n);
        }
    }
};
typedef NativeVector<Triple> TripleVector;
typedef NativeVector<TripleVector> NestedVector;
typedef char TripleFootprint[(sizeof(Triple)==12)?1:-1];
typedef char VectorFootprint[(sizeof(TripleVector)==16)?1:-1];
extern "C" void mx19oc_nested_vector_reserve_8034efd0(Ptr32<NestedVector> self,unsigned capacity) {
    self->reserve(capacity);
}


