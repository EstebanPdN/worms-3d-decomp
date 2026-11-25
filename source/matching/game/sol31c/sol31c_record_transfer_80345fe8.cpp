// GWMP8P rev0: append each twelve-byte polymorphic record, then clear source.
// GC32 offsets are observed; original class identity and portable behavior remain unknown.
extern "C" void *sol31c_transfer_allocate_80212fd4(unsigned);
extern "C" void *sol31c_transfer_fallback_803413d8(unsigned);
extern "C" void sol31c_transfer_free_802134fc(void *);
inline void *operator new(unsigned,void *place) throw() { return place; }
#include "sol31c_transfer_record.h"
template<class T> struct Sol31cTransferRecordAllocator {
 T *allocate(unsigned n) {
  if(n) { unsigned bytes=n*sizeof(T); void *p=sol31c_transfer_allocate_80212fd4(bytes); if(!p) p=sol31c_transfer_fallback_803413d8(bytes); return (T *)p; }
  return 0;
 }
 void deallocate(T *p,unsigned) { if(p) sol31c_transfer_free_802134fc(p); }
};
template<class T> struct Sol31cTransferRecordStorageEnd : Sol31cTransferRecordAllocator<T> { T *data; };
template<class T> inline const T &sol31c_transfer_record_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol31c_transfer_record_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol31c_transfer_record_destroy(T *p) { p->~T(); }
template<class T> inline void sol31c_transfer_record_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol31c_transfer_record_destroy(first);
}
template<class T> inline void sol31c_transfer_record_destroy_range(T *first,T *last) { sol31c_transfer_record_destroy_range_aux(first,last); }
struct Sol31cTransferRecordNotTrivial {};
template<class T> inline T *sol31c_transfer_record_uninitialized_copy(const T *first,const T *last,T *out,const Sol31cTransferRecordNotTrivial &) {
    for(;first!=last;++first,++out) sol31c_transfer_record_construct(out,*first);
    return out;
}
template<class T> inline T *sol31c_transfer_record_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol31c_transfer_record_construct(out,value);
    return out;
}
template<class T> inline T *sol31c_transfer_record_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol31c_transfer_record_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol31cTransferRecordVector {
    T *start,*finish;
    Sol31cTransferRecordStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol31c_transfer_record_destroy_range(start,finish);
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(T *s,T *f,T *e) { start=s; finish=f; end_of_storage.data=e; }
    void append_overflow(T *pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+sol31c_transfer_record_max(old_size,fill_len);
        T *new_start=end_of_storage.allocate(len);
        T *new_finish=sol31c_transfer_record_uninitialized_copy((const T *)start,(const T *)pos,new_start,Sol31cTransferRecordNotTrivial());
        if(fill_len==1) {
            sol31c_transfer_record_construct(new_finish,x);
            ++new_finish;
        } else {
            new_finish=sol31c_transfer_record_uninitialized_fill_n(new_finish,fill_len,x);
        }
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }

};
typedef Sol31cTransferRecordVector<Sol31cTransferRecord> Sol31cTransferRecordContainer;
typedef char Sol31cTransferRecordFootprint[(sizeof(Sol31cTransferRecord)==12)?1:-1];
typedef char Sol31cTransferRecordVectorFootprint[(sizeof(Sol31cTransferRecordContainer)==16)?1:-1];
extern "C" void sol31c_record_transfer_80345fe8(Sol31cTransferRecordContainer *self,Sol31cTransferRecordContainer *other) {
 for(Sol31cTransferRecord *p=other->start;p!=other->finish;++p) {
  if(self->finish!=self->end_of_storage.data) {
   sol31c_transfer_record_construct(self->finish,*p);
   ++self->finish;
  } else self->append_overflow(self->finish,*p,1);
 }
 sol31c_transfer_record_destroy_range(other->start,other->finish);
 other->finish=other->start;
}
