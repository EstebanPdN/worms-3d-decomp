#include "w3d_ptr.h"
#line 1 "large_record_insert_8034db14.cpp"
// GWMP8P rev0: insert for a vector of 84-byte records.
// Observed GC32 layout: shared string at +0, float at +4, 72-byte
// member at +8, byte at +80, and normal ABI alignment to 84 bytes.
// The vector is 16 bytes. Container and allocator names are inferred.
// Opening comments corrected in a new parent version; frozen worker inputs
// and their complete original proofs are preserved without changes.
extern "C" Ptr32<void> native_array_allocate_801907a8(unsigned);
extern "C" void native_array_free_801907d0(Ptr32<void>);
inline void *operator new(__SIZE_TYPE__,void *place) throw() { return place; }
struct Sol30cLargeString;
extern "C" void sol30c_large_string_init_8020c5c0(Ptr32<Sol30cLargeString>);
extern "C" void sol30c_large_string_finish_8020c5c4(Ptr32<Sol30cLargeString>);
extern "C" void sol30c_large_string_release_80341588(Ptr32<Sol30cLargeString>);
extern "C" Ptr32<unsigned short> sol30c_large_string_header_80341884(Ptr32<Sol30cLargeString>);
struct Sol30cLargeStringHeader { unsigned short references; unsigned short length,capacity; };
extern "C" void sol30c_large_header_release_8020bb2c(Ptr32<Sol30cLargeStringHeader>);
struct Sol30cLargeString {
    Ptr32<char> data;
    Sol30cLargeString(const Sol30cLargeString &x) {
        sol30c_large_string_init_8020c5c0(this);
        data=x.data;
        ++*sol30c_large_string_header_80341884(this);
    }
    ~Sol30cLargeString() {
        sol30c_large_string_finish_8020c5c4(this);
        sol30c_large_string_release_80341588(this);
    }
    Ptr32<Sol30cLargeStringHeader> header() const { return ((Ptr32<Sol30cLargeStringHeader>)data)-1; }
    static void release(Ptr32<Sol30cLargeStringHeader> h) { if(--h->references==0) sol30c_large_header_release_8020bb2c(h); }
    Sol30cLargeString &operator=(const Sol30cLargeString &x) {
        ++x.header()->references;
        release(header());
        data=x.data;
        return *this;
    }
};
struct Sol30cLargeBuffer;
extern "C" void sol30c_large_buffer_destroy_80197ce4(Ptr32<Sol30cLargeBuffer>,int);
// Original copies seventy-two bytes in a twenty-four-byte block loop, then
// calls the buffer destruction entry with flag two during record destruction.
struct Sol30cLargeBuffer {
    unsigned words[18];
    ~Sol30cLargeBuffer() { sol30c_large_buffer_destroy_80197ce4(this,2); }
};
struct Sol30cLargeRecord {
    Sol30cLargeString name;
    float value;
    Sol30cLargeBuffer buffer;
    unsigned char flag;
};
template<class T> struct Sol30cLargeRecordAllocator {
    Sol30cLargeRecordAllocator() {}
    Sol30cLargeRecordAllocator(const Sol30cLargeRecordAllocator &) {}
    Ptr32<T> allocate(unsigned count) { return (Ptr32<T>)native_array_allocate_801907a8(count*sizeof(T)); }
    void deallocate(Ptr32<T> p,unsigned) { if(p) native_array_free_801907d0(p); }
 char w3d_empty; };
template<class T> struct Sol30cLargeRecordStorageEnd : Sol30cLargeRecordAllocator<T> { Ptr32<T> data __attribute__((aligned(__alignof__(Sol30cLargeRecordAllocator<T>)))); };
template<class T> inline const T &sol30c_large_record_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol30c_large_record_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol30c_large_record_destroy(T *p) { p->~T(); }
template<class T> inline void sol30c_large_record_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol30c_large_record_destroy(w3d::R(first));
}
template<class T> inline void sol30c_large_record_destroy_range(T *first,T *last) { sol30c_large_record_destroy_range_aux(w3d::R(first),w3d::R(last)); }
struct Sol30cLargeRecordNotTrivial { char w3d_empty; };
template<class T> inline Ptr32<T> sol30c_large_record_uninitialized_copy(const T *first,const T *last,T *out,const Sol30cLargeRecordNotTrivial &) {
    for(;first!=last;++first,++out) sol30c_large_record_construct(w3d::R(out),*first);
    return out;
}
template<class T> inline Ptr32<T> sol30c_large_record_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol30c_large_record_construct(w3d::R(out),value);
    return out;
}
template<class T> inline Ptr32<T> sol30c_large_record_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol30c_large_record_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol30cLargeRecordVector {
    Ptr32<T> start; Ptr32<T> finish;
    Sol30cLargeRecordStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol30c_large_record_destroy_range(w3d::R(start),w3d::R(finish));
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(Ptr32<T> s,Ptr32<T> f,Ptr32<T> e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(Ptr32<T> pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+sol30c_large_record_max(old_size,fill_len);
        Ptr32<T> new_start=end_of_storage.allocate(len);
        Ptr32<T> new_finish=sol30c_large_record_uninitialized_copy(w3d::R((Ptr32<const T>)start),w3d::R((Ptr32<const T>)pos),w3d::R(new_start),Sol30cLargeRecordNotTrivial());
        if(fill_len==1) {
            sol30c_large_record_construct(w3d::R(new_finish),x);
            ++new_finish;
        } else {
            new_finish=sol30c_large_record_uninitialized_fill_n(w3d::R(new_finish),fill_len,x);
        }
        new_finish=sol30c_large_record_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)finish),w3d::R(new_finish),Sol30cLargeRecordNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }

};
typedef Sol30cLargeRecordVector<Sol30cLargeRecord> Sol30cLargeRecordContainer;
typedef char Sol30cLargeRecordFootprint[(sizeof(Sol30cLargeRecord)==84)?1:-1];
typedef char Sol30cLargeRecordVectorFootprint[(sizeof(Sol30cLargeRecordContainer)==16)?1:-1];
extern "C" void sol30c_large_record_fill_insert_8034db14(Ptr32<Sol30cLargeRecordContainer> self,Ptr32<Sol30cLargeRecord> pos,unsigned n,const Sol30cLargeRecord &x) {
    typedef Sol30cLargeRecord T;

    if(n!=0) {
        if(unsigned(self->end_of_storage.data-self->finish)>=n) {
            T x_copy=x;
            const unsigned elems_after=self->finish-pos;
            Ptr32<T> old_finish=self->finish;
            if(elems_after>n) {
                sol30c_large_record_uninitialized_copy(w3d::R((Ptr32<const T>)(self->finish-n)),w3d::R((Ptr32<const T>)self->finish),w3d::R(self->finish),Sol30cLargeRecordNotTrivial());
                self->finish+=n;
                sol30c_large_record_copy_backward(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)(old_finish-n)),w3d::R(old_finish));
                sol30c_large_record_assign(w3d::R(pos),w3d::R(pos+n),x_copy);
            } else {
                sol30c_large_record_uninitialized_fill_n(w3d::R(self->finish),n-elems_after,x_copy);
                self->finish+=n-elems_after;
                sol30c_large_record_uninitialized_copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)old_finish),w3d::R(self->finish),Sol30cLargeRecordNotTrivial());
                self->finish+=elems_after;
                sol30c_large_record_assign(w3d::R(pos),w3d::R(old_finish),x_copy);
            }
        } else {
            self->insert_overflow(pos,x,n);
        }
    }
    
}



