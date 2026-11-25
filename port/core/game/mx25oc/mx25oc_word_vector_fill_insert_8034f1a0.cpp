#include "w3d_ptr.h"
#line 1 "mx25oc_word_vector_fill_insert_8034f1a0.cpp"
// 0x8034f1a0: insert n copies of a 4-byte value before a position in a
// vector. Inferred STLport-shaped container (identity unverified), same layout
// as the admitted 0x8034efd0 reserve: begin at 0, finish at 4, an allocator
// proxy at 8 holding the storage-end pointer at proxy offset 4.
// Evidence for the structure below:
//  - spare capacity path keeps a by-value copy of the value in a frame slot
//    (8(r1)) and reads it through its address in the fill loops;
//  - placement construction is null-checked (operator new declared throw());
//  - tail copy-back counts elements (lwzu/stwu loop), assignment fill and
//    uninitialized copies compare pointers;
//  - the growth path takes old size and n by reference (frame slots 12/16)
//    for the larger-of selection and special-cases a single inserted value;
//  - uninitialized copies take a non-trivial-type dispatch tag by const
//    reference created at each call site: the addressable temporary keeps
//    local CSE from merging the finish reload of the tail copy, so the
//    original keeps a separate register for its end pointer.
// Allocation 0x801907a8 takes a byte count; release 0x801907d0 a block.
// Portability: the 16-byte layout assumes 32-bit pointers (checked below).
extern "C" Ptr32<void> native_array_allocate_801907a8(unsigned);
extern "C" void native_array_free_801907d0(Ptr32<void>);
inline void *operator new(__SIZE_TYPE__,void *place) throw() { return place; }
// Opaque 4-byte element; its meaning is not recovered (copied as a word).
struct FillWord { unsigned bits; };
template<class T> struct FillAllocator {
    FillAllocator() {}
    FillAllocator(const FillAllocator &) {}
    Ptr32<T> allocate(unsigned count) { return (Ptr32<T>)native_array_allocate_801907a8(count*sizeof(T)); }
    void deallocate(Ptr32<T> p,unsigned) { if(p) native_array_free_801907d0(p); }
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
        Ptr32<T> new_finish=fill_uninitialized_copy(w3d::R((Ptr32<const T>)start),w3d::R((Ptr32<const T>)pos),w3d::R(new_start),FillNotTrivial());
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
    void fill_insert(Ptr32<T> pos,unsigned n,const T &x) {
        if(n!=0) {
            if(unsigned(end_of_storage.data-finish)>=n) {
                T x_copy=x;
                const unsigned elems_after=finish-pos;
                Ptr32<T> old_finish=finish;
                if(elems_after>n) {
                    fill_uninitialized_copy(w3d::R((Ptr32<const T>)(finish-n)),w3d::R((Ptr32<const T>)finish),w3d::R(finish),FillNotTrivial());
                    finish+=n;
                    fill_copy_backward(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)(old_finish-n)),w3d::R(old_finish));
                    fill_assign(w3d::R(pos),w3d::R(pos+n),x_copy);
                } else {
                    fill_uninitialized_fill_n(w3d::R(finish),n-elems_after,x_copy);
                    finish+=n-elems_after;
                    fill_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)old_finish),w3d::R(finish),FillNotTrivial());
                    finish+=elems_after;
                    fill_assign(w3d::R(pos),w3d::R(old_finish),x_copy);
                }
            } else {
                insert_overflow(pos,x,n);
            }
        }
    }
};
typedef FillVector<FillWord> WordFillVector;
typedef char FillWordFootprint[(sizeof(FillWord)==4)?1:-1];
typedef char FillVectorFootprint[(sizeof(WordFillVector)==16)?1:-1];
extern "C" void mx25oc_word_vector_fill_insert_8034f1a0(Ptr32<WordFillVector> self,Ptr32<FillWord> pos,unsigned n,const FillWord &x) {
    self->fill_insert(pos,n,x);
}


