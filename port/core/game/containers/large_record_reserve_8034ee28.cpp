#include "w3d_ptr.h"
#line 1 "large_record_reserve_8034ee28.cpp"
// GWMP8P rev0: reserve for a vector of 84-byte records.
// Observed GC32 layout: shared string at +0, float at +4, 72-byte
// member at +8, byte at +80, and normal ABI alignment to 84 bytes.
// The vector is 16 bytes. Container and allocator names are inferred.
// Opening comments corrected in a new parent version; frozen worker inputs
// and their complete original proofs are preserved without changes.
extern "C" Ptr32<void> native_array_allocate_801907a8(unsigned);
extern "C" void native_array_free_801907d0(Ptr32<void>);
inline void *operator new(__SIZE_TYPE__,void *place) throw() { return place; }
struct Sol30cLargeReserveString;
extern "C" void sol30c_large_reserve_string_init_8020c5c0(Ptr32<Sol30cLargeReserveString>);
extern "C" void sol30c_large_reserve_string_finish_8020c5c4(Ptr32<Sol30cLargeReserveString>);
extern "C" void sol30c_large_reserve_string_release_80341588(Ptr32<Sol30cLargeReserveString>);
extern "C" Ptr32<unsigned short> sol30c_large_reserve_string_header_80341884(Ptr32<Sol30cLargeReserveString>);
struct Sol30cLargeReserveStringHeader { unsigned short references; unsigned short length,capacity; };
extern "C" void sol30c_large_reserve_header_release_8020bb2c(Ptr32<Sol30cLargeReserveStringHeader>);
struct Sol30cLargeReserveString {
    Ptr32<char> data;
    Sol30cLargeReserveString(const Sol30cLargeReserveString &x) {
        sol30c_large_reserve_string_init_8020c5c0(this);
        data=x.data;
        ++*sol30c_large_reserve_string_header_80341884(this);
    }
    ~Sol30cLargeReserveString() {
        sol30c_large_reserve_string_finish_8020c5c4(this);
        sol30c_large_reserve_string_release_80341588(this);
    }
    Ptr32<Sol30cLargeReserveStringHeader> header() const { return ((Ptr32<Sol30cLargeReserveStringHeader>)data)-1; }
    static void release(Ptr32<Sol30cLargeReserveStringHeader> h) { if(--h->references==0) sol30c_large_reserve_header_release_8020bb2c(h); }
    Sol30cLargeReserveString &operator=(const Sol30cLargeReserveString &x) {
        ++x.header()->references;
        release(header());
        data=x.data;
        return *this;
    }
};
struct Sol30cLargeReserveBuffer;
extern "C" void sol30c_large_reserve_buffer_destroy_80197ce4(Ptr32<Sol30cLargeReserveBuffer>,int);
// Original copies seventy-two bytes in a twenty-four-byte block loop, then
// calls the buffer destruction entry with flag two during record destruction.
struct Sol30cLargeReserveBuffer {
    unsigned words[18];
    ~Sol30cLargeReserveBuffer() { sol30c_large_reserve_buffer_destroy_80197ce4(this,2); }
};
struct Sol30cLargeReserveRecord {
    Sol30cLargeReserveString name;
    float value;
    Sol30cLargeReserveBuffer buffer;
    unsigned char flag;
};
template<class T> struct Sol30cLargeReserveRecordAllocator {
    Sol30cLargeReserveRecordAllocator() {}
    Sol30cLargeReserveRecordAllocator(const Sol30cLargeReserveRecordAllocator &) {}
    Ptr32<T> allocate(unsigned count) { return (Ptr32<T>)native_array_allocate_801907a8(count*sizeof(T)); }
    void deallocate(Ptr32<T> p,unsigned) { if(p) native_array_free_801907d0(p); }
 char w3d_empty; };
template<class T> struct Sol30cLargeReserveRecordStorageEnd : Sol30cLargeReserveRecordAllocator<T> { Ptr32<T> data __attribute__((aligned(__alignof__(Sol30cLargeReserveRecordAllocator<T>)))); };
template<class T> inline const T &sol30c_large_reserve_record_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol30c_large_reserve_record_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol30c_large_reserve_record_destroy(T *p) { p->~T(); }
template<class T> inline void sol30c_large_reserve_record_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol30c_large_reserve_record_destroy(w3d::R(first));
}
template<class T> inline void sol30c_large_reserve_record_destroy_range(T *first,T *last) { sol30c_large_reserve_record_destroy_range_aux(w3d::R(first),w3d::R(last)); }
struct Sol30cLargeReserveRecordNotTrivial { char w3d_empty; };
template<class T> inline Ptr32<T> sol30c_large_reserve_record_uninitialized_copy(const T *first,const T *last,T *out,const Sol30cLargeReserveRecordNotTrivial &) {
    for(;first!=last;++first,++out) sol30c_large_reserve_record_construct(w3d::R(out),*first);
    return out;
}
template<class T> inline Ptr32<T> sol30c_large_reserve_record_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol30c_large_reserve_record_construct(w3d::R(out),value);
    return out;
}
template<class T> inline Ptr32<T> sol30c_large_reserve_record_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol30c_large_reserve_record_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol30cLargeReserveRecordVector {
    Ptr32<T> start; Ptr32<T> finish;
    Sol30cLargeReserveRecordStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol30c_large_reserve_record_destroy_range(w3d::R(start),w3d::R(finish));
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(Ptr32<T> s,Ptr32<T> f,Ptr32<T> e) { start=s; finish=f; end_of_storage.data=e; }
    unsigned capacity() const { return end_of_storage.data-start; }
    Ptr32<T> allocate_and_copy(unsigned n,Ptr32<const T> first,Ptr32<const T> last) {
        Ptr32<T> result=end_of_storage.allocate(n);
        sol30c_large_reserve_record_uninitialized_copy(w3d::R(first),w3d::R(last),w3d::R(result),Sol30cLargeReserveRecordNotTrivial());
        return result;
    }
    void reserve(unsigned n) {
        if(capacity()<n) {
            const unsigned old_size=size();
            Ptr32<T> tmp;
            if(start) {
                tmp=allocate_and_copy(n,start,finish);
                clear_storage();
            } else tmp=end_of_storage.allocate(n);
            set(tmp,tmp+old_size,tmp+n);
        }
    }

};
typedef Sol30cLargeReserveRecordVector<Sol30cLargeReserveRecord> Sol30cLargeReserveRecordContainer;
typedef char Sol30cLargeReserveRecordFootprint[(sizeof(Sol30cLargeReserveRecord)==84)?1:-1];
typedef char Sol30cLargeReserveRecordVectorFootprint[(sizeof(Sol30cLargeReserveRecordContainer)==16)?1:-1];
extern "C" void sol30c_large_record_reserve_8034ee28(Ptr32<Sol30cLargeReserveRecordContainer> self,unsigned n) { self->reserve(n); }


