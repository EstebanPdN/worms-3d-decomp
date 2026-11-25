#include "w3d_ptr.h"
#line 1 "sol35f4r_record64_insert_8035ab00.cpp"
// GWMP8P rev0 0x8035ab00: fill insertion for opaque 64-byte records.
// All sixteen words are copied by the original; their semantic fields remain
// unknown. The user-defined copy constructor delegates to whole-record
// assignment, matching the original block-copy construction at each site.
// GC32 vector: start +0, finish +4, allocator base +8, storage end +12.
// The new destination iterator is initialized from new_start before copying.
// Names and STL identity are inferred. Valid same-array storage extents are
// required; null-empty subtraction follows the native idiom, not ISO C++.
inline void *operator new(__SIZE_TYPE__,void *place) throw() { return place; }
extern "C" Ptr32<void> sol35f4r_allocate_80212fd4(unsigned);
extern "C" Ptr32<void> sol35f4r_fallback_803413d8(unsigned);
extern "C" void sol35f4r_release_802134fc(Ptr32<void>);
struct Record64 {
    unsigned words[16];
    Record64(const Record64 &x) { *this=x; }
};
template<class T> struct FillAllocator {
    FillAllocator() {}
    FillAllocator(const FillAllocator &) {}
    static Ptr32<void> storage(unsigned bytes) {Ptr32<void> p=sol35f4r_allocate_80212fd4(bytes);if(!p)p=sol35f4r_fallback_803413d8(bytes);return p;}
    Ptr32<T> allocate(unsigned count) {return count?(Ptr32<T>)storage(count*sizeof(T)):0;}
    void deallocate(Ptr32<T> p,unsigned) { if(p) sol35f4r_release_802134fc(p); }
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
typedef FillVector<Record64> Record64Vector;
typedef char Record64Footprint[(sizeof(Record64)==64)?1:-1];
typedef char FillVectorFootprint[(sizeof(Record64Vector)==16)?1:-1];
extern "C" void sol35f4r_record64_insert_8035ab00(Ptr32<Record64Vector> self,Ptr32<Record64> pos,unsigned n,const Record64 &x) {
    typedef Record64 T;
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


