#include "w3d_ptr.h"
#line 1 "sol35f7a_string_record_insert_8034d568.cpp"
// Exact-reference candidate for GWMP8P rev0 0x8034d568.
// GC32 vector stride 16; element stride 8: shared string +0, bytes +4/+5,
// halfword +6. Shared-string header starts six bytes before its data.
// Names and STL identity are inferred. Real member copy/destruction and
// initialized advancing destination iterator follow the observed instructions.
// Valid live storage, same-array bounds and external ownership contracts are
// required; native null-empty pointer arithmetic is not ISO-portable evidence.
// GWMP8P rev0: shared-string record fill insertion.
// Eight-byte records and a sixteen-byte vector are observed GC32 layouts;
// container and allocator identities remain structural inferences.
extern "C" Ptr32<void> sol35f7a_pool_allocate_80212fd4(unsigned);
extern "C" Ptr32<void> sol35f7a_pool_fallback_803413d8(unsigned);
extern "C" void sol35f7a_pool_free_802134fc(Ptr32<void>);
inline void *operator new(__SIZE_TYPE__,void *place) throw() { return place; }
struct Sol35f7aPoolString;
extern "C" void sol35f7a_pool_string_init_8020c5c0(Ptr32<Sol35f7aPoolString>);
extern "C" void sol35f7a_pool_string_finish_8020c5c4(Ptr32<Sol35f7aPoolString>);
extern "C" void sol35f7a_pool_string_release_80341588(Ptr32<Sol35f7aPoolString>);
extern "C" Ptr32<unsigned short> sol35f7a_pool_string_header_80341884(Ptr32<Sol35f7aPoolString>);
struct Sol35f7aPoolStringHeader { unsigned short references; unsigned short length,capacity; };
extern "C" void sol35f7a_pool_header_release_8020bb2c(Ptr32<Sol35f7aPoolStringHeader>);
struct Sol35f7aPoolString {
    Ptr32<char> data;
    Sol35f7aPoolString(const Sol35f7aPoolString &x) {
        sol35f7a_pool_string_init_8020c5c0(this);
        data=x.data;
        ++*sol35f7a_pool_string_header_80341884(this);
    }
    ~Sol35f7aPoolString() {
        sol35f7a_pool_string_finish_8020c5c4(this);
        sol35f7a_pool_string_release_80341588(this);
    }
    Ptr32<Sol35f7aPoolStringHeader> header() const { return ((Ptr32<Sol35f7aPoolStringHeader>)data)-1; }
    static void release(Ptr32<Sol35f7aPoolStringHeader> h) { if(--h->references==0) sol35f7a_pool_header_release_8020bb2c(h); }
    Sol35f7aPoolString &operator=(const Sol35f7aPoolString &x) {
        ++x.header()->references;
        release(header());
        data=x.data;
        return *this;
    }
};
// Original stores the two byte fields separately and the final halfword.
struct Sol35f7aPoolRecord {
    Sol35f7aPoolString name;
    unsigned char first,second;
    unsigned short value;
};
template<class T> struct Sol35f7aPoolRecordAllocator {
    Sol35f7aPoolRecordAllocator() {}
    Sol35f7aPoolRecordAllocator(const Sol35f7aPoolRecordAllocator &) {}
    static Ptr32<void> allocate_bytes(unsigned bytes) {
        Ptr32<void> p=sol35f7a_pool_allocate_80212fd4(bytes);
        if(!p) p=sol35f7a_pool_fallback_803413d8(bytes);
        return p;
    }
    Ptr32<T> allocate(unsigned count) { return count ? (Ptr32<T>)allocate_bytes(count*sizeof(T)) : 0; }
    void deallocate(Ptr32<T> p,unsigned) { if(p) sol35f7a_pool_free_802134fc(p); }
 char w3d_empty; };
template<class T> struct Sol35f7aPoolRecordStorageEnd : Sol35f7aPoolRecordAllocator<T> { Ptr32<T> data __attribute__((aligned(__alignof__(Sol35f7aPoolRecordAllocator<T>)))); };
template<class T> inline const T &sol35f7a_pool_record_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol35f7a_pool_record_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol35f7a_pool_record_destroy(T *p) { p->~T(); }
template<class T> inline void sol35f7a_pool_record_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol35f7a_pool_record_destroy(w3d::R(first));
}
template<class T> inline void sol35f7a_pool_record_destroy_range(T *first,T *last) { sol35f7a_pool_record_destroy_range_aux(w3d::R(first),w3d::R(last)); }
struct Sol35f7aPoolRecordNotTrivial { char w3d_empty; };
template<class T> inline Ptr32<T> sol35f7a_pool_record_uninitialized_copy(const T *first,const T *last,T *out,const Sol35f7aPoolRecordNotTrivial &) {
    for(;first!=last;++first,++out) sol35f7a_pool_record_construct(w3d::R(out),*first);
    return out;
}
template<class T> inline Ptr32<T> sol35f7a_pool_record_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol35f7a_pool_record_construct(w3d::R(out),value);
    return out;
}
template<class T> inline Ptr32<T> sol35f7a_pool_record_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol35f7a_pool_record_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol35f7aPoolRecordVector {
    Ptr32<T> start; Ptr32<T> finish;
    Sol35f7aPoolRecordStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol35f7a_pool_record_destroy_range(w3d::R(start),w3d::R(finish));
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(Ptr32<T> s,Ptr32<T> f,Ptr32<T> e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(Ptr32<T> pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+sol35f7a_pool_record_max(old_size,fill_len);
        Ptr32<T> new_start=end_of_storage.allocate(len);
        Ptr32<T> new_finish=new_start;
        new_finish=sol35f7a_pool_record_uninitialized_copy(w3d::R((Ptr32<const T>)start),w3d::R((Ptr32<const T>)pos),w3d::R(new_finish),Sol35f7aPoolRecordNotTrivial());
        if(fill_len==1) {
            sol35f7a_pool_record_construct(w3d::R(new_finish),x);
            ++new_finish;
        } else {
            new_finish=sol35f7a_pool_record_uninitialized_fill_n(w3d::R(new_finish),fill_len,x);
        }
        new_finish=sol35f7a_pool_record_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)finish),w3d::R(new_finish),Sol35f7aPoolRecordNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }

};
typedef Sol35f7aPoolRecordVector<Sol35f7aPoolRecord> Sol35f7aPoolRecordContainer;
typedef char Sol35f7aPoolRecordFootprint[(sizeof(Sol35f7aPoolRecord)==8)?1:-1];
typedef char Sol35f7aPoolRecordVectorFootprint[(sizeof(Sol35f7aPoolRecordContainer)==16)?1:-1];
extern "C" void sol35f7a_string_record_insert_8034d568(Ptr32<Sol35f7aPoolRecordContainer> self,Ptr32<Sol35f7aPoolRecord> pos,unsigned n,const Sol35f7aPoolRecord &x) {
    typedef Sol35f7aPoolRecord T;

    if(n!=0) {
        if(unsigned(self->end_of_storage.data-self->finish)>=n) {
            T x_copy=x;
            const unsigned elems_after=self->finish-pos;
            Ptr32<T> old_finish=self->finish;
            if(elems_after>n) {
                sol35f7a_pool_record_uninitialized_copy(w3d::R((Ptr32<const T>)(self->finish-n)),w3d::R((Ptr32<const T>)self->finish),w3d::R(self->finish),Sol35f7aPoolRecordNotTrivial());
                self->finish+=n;
                sol35f7a_pool_record_copy_backward(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)(old_finish-n)),w3d::R(old_finish));
                sol35f7a_pool_record_assign(w3d::R(pos),w3d::R(pos+n),x_copy);
            } else {
                sol35f7a_pool_record_uninitialized_fill_n(w3d::R(self->finish),n-elems_after,x_copy);
                self->finish+=n-elems_after;
                sol35f7a_pool_record_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)old_finish),w3d::R(self->finish),Sol35f7aPoolRecordNotTrivial());
                self->finish+=elems_after;
                sol35f7a_pool_record_assign(w3d::R(pos),w3d::R(old_finish),x_copy);
            }
        } else {
            self->insert_overflow(pos,x,n);
        }
    }
    
}



