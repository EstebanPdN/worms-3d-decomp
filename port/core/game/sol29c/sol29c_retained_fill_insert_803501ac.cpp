#include "w3d_ptr.h"
#line 1 "sol29c_retained_fill_insert_803501ac.cpp"
// GWMP8P rev0 0x803501ac: fill insertion for an opaque retained 16-byte record.
// Direct four-byte virtual entries at vtable offsets 12 and 16 independently
// require the original thunk ABI (-fvtable-thunks); this is not a flag search.
extern "C" Ptr32<void> native_array_allocate_801907a8(unsigned);
extern "C" void native_array_free_801907d0(Ptr32<void>);
inline void *operator new(__SIZE_TYPE__,void *place) throw() { return place; }
// Observed interface handle followed by four byte fields and two words.
struct Sol29cRetainedInterface {
    void w3d_r_slot0() __asm__(W3D_SYM("_ZN23Sol29cRetainedInterface5slot0Ev"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN23Sol29cRetainedInterface6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN23Sol29cRetainedInterface7releaseEv"));
 __attribute__((always_inline)) inline void slot0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sol29cRetainedInterface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sol29cRetainedInterface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Sol29cRetainedInterface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Sol29cRetainedInterface; };
struct Sol29cRetainedHandle {
    Ptr32<Sol29cRetainedInterface> pointer;
    Sol29cRetainedHandle(const Sol29cRetainedHandle &x):pointer(x.pointer) { if(pointer) pointer->retain(); }
    ~Sol29cRetainedHandle() { if(pointer) pointer->release(); }
    Sol29cRetainedHandle &operator=(const Sol29cRetainedHandle &x) {
        if(x.pointer) x.pointer->retain();
        if(pointer) pointer->release();
        pointer=x.pointer;
        return *this;
    }
};
struct Sol29cRetainedRecord {
    Sol29cRetainedHandle handle;
    unsigned char a,b,c,d;
    unsigned value0,value1;
};
template<class T> struct Sol29cRetainedAllocator {
    Sol29cRetainedAllocator() {}
    Sol29cRetainedAllocator(const Sol29cRetainedAllocator &) {}
    Ptr32<T> allocate(unsigned count) { return (Ptr32<T>)native_array_allocate_801907a8(count*sizeof(T)); }
    void deallocate(Ptr32<T> p,unsigned) { if(p) native_array_free_801907d0(p); }
 char w3d_empty; };
template<class T> struct Sol29cRetainedStorageEnd : Sol29cRetainedAllocator<T> { Ptr32<T> data __attribute__((aligned(__alignof__(Sol29cRetainedAllocator<T>)))); };
template<class T> inline const T &sol29c_retained_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol29c_retained_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol29c_retained_destroy(T *p) { p->~T(); }
template<class T> inline void sol29c_retained_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol29c_retained_destroy(w3d::R(first));
}
template<class T> inline void sol29c_retained_destroy_range(T *first,T *last) { sol29c_retained_destroy_range_aux(w3d::R(first),w3d::R(last)); }
struct Sol29cRetainedNotTrivial { char w3d_empty; };
template<class T> inline Ptr32<T> sol29c_retained_uninitialized_copy(const T *first,const T *last,T *out,const Sol29cRetainedNotTrivial &) {
    for(;first!=last;++first,++out) sol29c_retained_construct(w3d::R(out),*first);
    return out;
}
template<class T> inline Ptr32<T> sol29c_retained_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol29c_retained_construct(w3d::R(out),value);
    return out;
}
template<class T> inline Ptr32<T> sol29c_retained_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol29c_retained_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol29cRetainedVector {
    Ptr32<T> start; Ptr32<T> finish;
    Sol29cRetainedStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol29c_retained_destroy_range(w3d::R(start),w3d::R(finish));
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(Ptr32<T> s,Ptr32<T> f,Ptr32<T> e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(Ptr32<T> pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+sol29c_retained_max(old_size,fill_len);
        Ptr32<T> new_start=end_of_storage.allocate(len);
        Ptr32<T> new_finish=sol29c_retained_uninitialized_copy(w3d::R((Ptr32<const T>)start),w3d::R((Ptr32<const T>)pos),w3d::R(new_start),Sol29cRetainedNotTrivial());
        if(fill_len==1) {
            sol29c_retained_construct(w3d::R(new_finish),x);
            ++new_finish;
        } else {
            new_finish=sol29c_retained_uninitialized_fill_n(w3d::R(new_finish),fill_len,x);
        }
        new_finish=sol29c_retained_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)finish),w3d::R(new_finish),Sol29cRetainedNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }

};
typedef Sol29cRetainedVector<Sol29cRetainedRecord> Sol29cRetainedContainer;
typedef char Sol29cRetainedRecordFootprint[(sizeof(Sol29cRetainedRecord)==16)?1:-1];
typedef char Sol29cRetainedVectorFootprint[(sizeof(Sol29cRetainedContainer)==16)?1:-1];
extern "C" void sol29c_retained_fill_insert_803501ac(Ptr32<Sol29cRetainedContainer> self,Ptr32<Sol29cRetainedRecord> pos,unsigned n,const Sol29cRetainedRecord &x) {
    typedef Sol29cRetainedRecord T;

        if(n!=0) {
            if(unsigned(self->end_of_storage.data-self->finish)>=n) {
                T x_copy=x;
                const unsigned elems_after=self->finish-pos;
                Ptr32<T> old_finish=self->finish;
                if(elems_after>n) {
                    sol29c_retained_uninitialized_copy(w3d::R((Ptr32<const T>)(self->finish-n)),w3d::R((Ptr32<const T>)self->finish),w3d::R(self->finish),Sol29cRetainedNotTrivial());
                    self->finish+=n;
                    sol29c_retained_copy_backward(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)(old_finish-n)),w3d::R(old_finish));
                    sol29c_retained_assign(w3d::R(pos),w3d::R(pos+n),x_copy);
                } else {
                    sol29c_retained_uninitialized_fill_n(w3d::R(self->finish),n-elems_after,x_copy);
                    self->finish+=n-elems_after;
                    sol29c_retained_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)old_finish),w3d::R(self->finish),Sol29cRetainedNotTrivial());
                    self->finish+=elems_after;
                    sol29c_retained_assign(w3d::R(pos),w3d::R(old_finish),x_copy);
                }
            } else {
                self->insert_overflow(pos,x,n);
            }
        }
    
}


