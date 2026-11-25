// UNPROVED recovery candidate, GWMP8P rev0. Original body: [0x80345648,0x803459fc).
// Reference compile is 944 vs 948 bytes; no full-link or coverage claim.
// Inferred partial GC32 types: outer vector 16 bytes; record 16 bytes,
// key halfword +0, time word +4, vptr +8, shared-string member +12.
// Real polymorphic copy construction and assignment preserve the observed
// native vptr and string ownership behavior. Unknown prefix storage in gate
// is a partial external view, never constructed here. Its flags word is +188.
// Precondition: live compatible interfaces, valid aligned objects/headers,
// same-array extents and representable arithmetic. Allocation, message post,
// global gate and string-header release remain external behavior boundaries.
// Native null-empty pointer arithmetic does not establish ISO portability.
// No behavior, whole-game, 3DS, emulator or hardware validation is claimed.
extern "C" void *sol35f8a_transfer_allocate_80212fd4(unsigned);
extern "C" void *sol35f8a_transfer_fallback_803413d8(unsigned);
extern "C" void sol35f8a_transfer_free_802134fc(void *);
inline void *operator new(unsigned,void *place) throw() { return place; }

namespace sol35f8a_string_delivery_80345648 {
struct Sol35f8aPoolString;
extern "C" void sol35f8a_pool_string_init_8020c5c0(Sol35f8aPoolString *);
extern "C" void sol35f8a_pool_string_finish_8020c5c4(Sol35f8aPoolString *);
extern "C" void sol35f8a_pool_string_release_80341588(Sol35f8aPoolString *);
extern "C" unsigned short *sol35f8a_pool_string_header_80341884(Sol35f8aPoolString *);
struct Sol35f8aPoolStringHeader { unsigned short references; unsigned short length,capacity; };
extern "C" void sol35f8a_pool_header_release_8020bb2c(Sol35f8aPoolStringHeader *);
struct Sol35f8aPoolString {
    char *data;
    Sol35f8aPoolString(const Sol35f8aPoolString &x) {
        sol35f8a_pool_string_init_8020c5c0(this);
        data=x.data;
        ++*sol35f8a_pool_string_header_80341884(this);
    }
    ~Sol35f8aPoolString() {
        sol35f8a_pool_string_finish_8020c5c4(this);
        sol35f8a_pool_string_release_80341588(this);
    }
    Sol35f8aPoolStringHeader *header() const { return ((Sol35f8aPoolStringHeader *)data)-1; }
    static void release(Sol35f8aPoolStringHeader *h) { if(--h->references==0) sol35f8a_pool_header_release_8020bb2c(h); }
    Sol35f8aPoolString &operator=(const Sol35f8aPoolString &x) {
        ++x.header()->references;
        release(header());
        data=x.data;
        return *this;
    }
};

}
#include "sol35f8a_string_delivery_80345648.h"
namespace sol35f8a_string_delivery_80345648 {

template<class T> struct Sol35f8aTransferRecordAllocator {
 static void *allocate_bytes(unsigned bytes) {
  void *p=sol35f8a_transfer_allocate_80212fd4(bytes); if(!p) p=sol35f8a_transfer_fallback_803413d8(bytes); return p;
 }
 T *allocate(unsigned n) { return n ? (T *)allocate_bytes(n*sizeof(T)) : 0; }
 void deallocate(T *p,unsigned) { if(p) sol35f8a_transfer_free_802134fc(p); }
};
template<class T> struct Sol35f8aTransferRecordStorageEnd : Sol35f8aTransferRecordAllocator<T> { T *data; };
template<class T> inline const T &sol35f8a_transfer_record_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol35f8a_transfer_record_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol35f8a_transfer_record_destroy(T *p) { p->~T(); }
template<class T> inline void sol35f8a_transfer_record_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol35f8a_transfer_record_destroy(first);
}
template<class T> inline void sol35f8a_transfer_record_destroy_range(T *first,T *last) { sol35f8a_transfer_record_destroy_range_aux(first,last); }
struct Sol35f8aTransferRecordNotTrivial {};
template<class I,class O> inline O uninitialized_copy_aux(I first,I last,O result,Sol35f8aTransferRecordNotTrivial) {
 O cur=result;
 for(;first!=last;++first,++cur) sol35f8a_transfer_record_construct(cur,*first);
 return cur;
}
template<class I,class O,class T> inline O uninitialized_copy_type(I first,I last,O result,T *) {return uninitialized_copy_aux(first,last,result,Sol35f8aTransferRecordNotTrivial());}
template<class T> inline T *sol35f8a_transfer_record_uninitialized_copy(const T *first,const T *last,T *out,const Sol35f8aTransferRecordNotTrivial &) {return uninitialized_copy_type(first,last,out,(T *)0);}
template<class T> inline T *sol35f8a_transfer_record_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol35f8a_transfer_record_construct(out,value);
    return out;
}
template<class T> inline T *sol35f8a_transfer_record_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol35f8a_transfer_record_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol35f8aTransferRecordVector {
    T *start,*finish;
    Sol35f8aTransferRecordStorageEnd<T> end_of_storage;
    T *begin() {return start;}
    T *end() {return finish;}
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol35f8a_transfer_record_destroy_range(start,finish);
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(T *s,T *f,T *e) { start=s; finish=f; end_of_storage.data=e; }
    T *allocate(unsigned n) {return end_of_storage.allocate(n);}
    void append_overflow(T *pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+sol35f8a_transfer_record_max(old_size,fill_len);
        T *new_start=allocate(len);
        T *new_finish=new_start;
        new_finish=sol35f8a_transfer_record_uninitialized_copy((const T *)start,(const T *)pos,new_finish,Sol35f8aTransferRecordNotTrivial());
        if(fill_len==1) {
            sol35f8a_transfer_record_construct(new_finish,x);
            ++new_finish;
        } else {
            new_finish=sol35f8a_transfer_record_uninitialized_fill_n(new_finish,fill_len,x);
        }
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }

void append(const T &x) {
 if(finish!=end_of_storage.data) {
  sol35f8a_transfer_record_construct(finish,x); ++finish;
 } else append_overflow(end(),x,1);
}

};

typedef Sol35f8aTransferRecordVector<Record> Container;
template<class T> inline T *copy(const T *first,const T *last,T *out) {
 for(int n=last-first;n>0;--n,++first,++out) *out=*first;
 return out;
}
inline void erase(Container *self,Record *pos) {
 if(pos+1!=self->finish) copy((const Record *)(pos+1),(const Record *)self->finish,pos);
 --self->finish;
 sol35f8a_transfer_record_destroy(self->finish);
}

}
struct Sol35f8aDeliveryGate { unsigned char opaque_before_flags[188]; unsigned flags; };
extern "C" Sol35f8aDeliveryGate *sol35f8a_gate_804b1788;
extern "C" void sol35f8a_post_current_8016239c();
typedef char Sol35f8aRecordFootprint[sizeof(sol35f8a_string_delivery_80345648::Record)==16?1:-1];
typedef char Sol35f8aVectorFootprint[sizeof(sol35f8a_string_delivery_80345648::Container)==16?1:-1];
extern "C" void sol35f8a_delivery_80345648(sol35f8a_string_delivery_80345648::Container *self,sol35f8a_string_delivery_80345648::Container *history,unsigned now) {
 using namespace sol35f8a_string_delivery_80345648;
 for(Record *p=self->start;p!=self->finish;) {
  if(p->time<=now) {
   p->deliver();
   sol35f8a_post_current_8016239c();
   if(sol35f8a_gate_804b1788->flags&0x8000) history->append(*p);
   erase(self,p);
  } else ++p;
 }
}
