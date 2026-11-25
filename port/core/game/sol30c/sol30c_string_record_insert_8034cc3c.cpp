#include "w3d_ptr.h"
#line 1 "sol30c_string_record_insert_8034cc3c.cpp"
// GWMP8P rev0: shared-string record fill insertion.
// Eight-byte records and a sixteen-byte vector are observed GC32 layouts;
// container and allocator identities remain structural inferences.
extern "C" Ptr32<void> native_array_allocate_801907a8(unsigned);
extern "C" void native_array_free_801907d0(Ptr32<void>);
inline void *operator new(__SIZE_TYPE__,void *place) throw() { return place; }
struct Sol30cString;
extern "C" void sol30c_string_init_8020c5c0(Ptr32<Sol30cString>);
extern "C" void sol30c_string_finish_8020c5c4(Ptr32<Sol30cString>);
extern "C" void sol30c_string_release_80341588(Ptr32<Sol30cString>);
extern "C" Ptr32<unsigned short> sol30c_string_header_80341884(Ptr32<Sol30cString>);
// Six-byte prefix observed at data - 6; other halfword meanings are unknown.
struct Sol30cStringHeader { unsigned short references; unsigned short metadata0,metadata1; };
extern "C" void sol30c_header_release_8020bb2c(Ptr32<Sol30cStringHeader>);
struct Sol30cString {
    Ptr32<char> data;
    Sol30cString(const Sol30cString &x) {
        sol30c_string_init_8020c5c0(this);
        data=x.data;
        ++*sol30c_string_header_80341884(this);
    }
    ~Sol30cString() {
        sol30c_string_finish_8020c5c4(this);
        sol30c_string_release_80341588(this);
    }
    Ptr32<Sol30cStringHeader> header() const { return ((Ptr32<Sol30cStringHeader>)data)-1; }
    // The original computes the header before decrementing and passes that same
    // pointer to release; capture it as a helper argument across the decrement.
    static void release(Ptr32<Sol30cStringHeader> h) { if(--h->references==0) sol30c_header_release_8020bb2c(h); }
    Sol30cString &operator=(const Sol30cString &x) {
        ++x.header()->references;
        release(header());
        data=x.data;
        return *this;
    }
};
// Original stores the two byte fields separately and the final halfword.
struct Sol30cRecord {
    Sol30cString name;
    unsigned char first,second;
    unsigned short value;
};
template<class T> struct Sol30cRecordAllocator {
    Sol30cRecordAllocator() {}
    Sol30cRecordAllocator(const Sol30cRecordAllocator &) {}
    Ptr32<T> allocate(unsigned count) { return (Ptr32<T>)native_array_allocate_801907a8(count*sizeof(T)); }
    void deallocate(Ptr32<T> p,unsigned) { if(p) native_array_free_801907d0(p); }
 char w3d_empty; };
template<class T> struct Sol30cRecordStorageEnd : Sol30cRecordAllocator<T> { Ptr32<T> data __attribute__((aligned(__alignof__(Sol30cRecordAllocator<T>)))); };
template<class T> inline const T &sol30c_record_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol30c_record_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol30c_record_destroy(T *p) { p->~T(); }
template<class T> inline void sol30c_record_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol30c_record_destroy(w3d::R(first));
}
template<class T> inline void sol30c_record_destroy_range(T *first,T *last) { sol30c_record_destroy_range_aux(w3d::R(first),w3d::R(last)); }
struct Sol30cRecordNotTrivial { char w3d_empty; };
template<class T> inline Ptr32<T> sol30c_record_uninitialized_copy(const T *first,const T *last,T *out,const Sol30cRecordNotTrivial &) {
    for(;first!=last;++first,++out) sol30c_record_construct(w3d::R(out),*first);
    return out;
}
template<class T> inline Ptr32<T> sol30c_record_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol30c_record_construct(w3d::R(out),value);
    return out;
}
template<class T> inline Ptr32<T> sol30c_record_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol30c_record_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol30cRecordVector {
    Ptr32<T> start; Ptr32<T> finish;
    Sol30cRecordStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol30c_record_destroy_range(w3d::R(start),w3d::R(finish));
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(Ptr32<T> s,Ptr32<T> f,Ptr32<T> e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(Ptr32<T> pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+sol30c_record_max(old_size,fill_len);
        Ptr32<T> new_start=end_of_storage.allocate(len);
        Ptr32<T> new_finish=sol30c_record_uninitialized_copy(w3d::R((Ptr32<const T>)start),w3d::R((Ptr32<const T>)pos),w3d::R(new_start),Sol30cRecordNotTrivial());
        if(fill_len==1) {
            sol30c_record_construct(w3d::R(new_finish),x);
            ++new_finish;
        } else {
            new_finish=sol30c_record_uninitialized_fill_n(w3d::R(new_finish),fill_len,x);
        }
        new_finish=sol30c_record_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)finish),w3d::R(new_finish),Sol30cRecordNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }

};
typedef Sol30cRecordVector<Sol30cRecord> Sol30cRecordContainer;
typedef char Sol30cRecordFootprint[(sizeof(Sol30cRecord)==8)?1:-1];
typedef char Sol30cRecordVectorFootprint[(sizeof(Sol30cRecordContainer)==16)?1:-1];
extern "C" void sol30c_record_fill_insert_8034cc3c(Ptr32<Sol30cRecordContainer> self,Ptr32<Sol30cRecord> pos,unsigned n,const Sol30cRecord &x) {
    typedef Sol30cRecord T;

    if(n!=0) {
        if(unsigned(self->end_of_storage.data-self->finish)>=n) {
            T x_copy=x;
            const unsigned elems_after=self->finish-pos;
            Ptr32<T> old_finish=self->finish;
            if(elems_after>n) {
                sol30c_record_uninitialized_copy(w3d::R((Ptr32<const T>)(self->finish-n)),w3d::R((Ptr32<const T>)self->finish),w3d::R(self->finish),Sol30cRecordNotTrivial());
                self->finish+=n;
                sol30c_record_copy_backward(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)(old_finish-n)),w3d::R(old_finish));
                sol30c_record_assign(w3d::R(pos),w3d::R(pos+n),x_copy);
            } else {
                sol30c_record_uninitialized_fill_n(w3d::R(self->finish),n-elems_after,x_copy);
                self->finish+=n-elems_after;
                sol30c_record_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)old_finish),w3d::R(self->finish),Sol30cRecordNotTrivial());
                self->finish+=elems_after;
                sol30c_record_assign(w3d::R(pos),w3d::R(old_finish),x_copy);
            }
        } else {
            self->insert_overflow(pos,x,n);
        }
    }
    
}



