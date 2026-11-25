// GWMP8P rev0 0x80348a4c. Observed 32-byte retained records: word, three
// held interfaces, counted reference array, trailing word (layout from
// sol35f6a_record32_insert_80347dec). The real tail copy folds away but its
// const tag temporary keeps the finish reload (d24d finding), with STLport-
// shaped three-layer destroy.
struct D24fInterface {
 virtual void slot0()=0;
 virtual void retain()=0;
 virtual void release()=0;
};
struct D24fHeld {
 D24fInterface *pointer;
 D24fHeld():pointer(0) {}
 ~D24fHeld() { if(pointer) pointer->release(); }
};
struct D24fRefs;
extern "C" D24fRefs *w3d_construct_802109dc(D24fRefs *);
extern "C" void w3d_auto_80210abc(D24fRefs *,int);
struct D24fRefs {
 unsigned count;
 unsigned short capacity,growth;
 D24fInterface **slots;
 D24fRefs() { w3d_construct_802109dc(this); }
 ~D24fRefs() { w3d_auto_80210abc(this,2); }
};
struct D24fRecord {
 unsigned key;
 D24fHeld a,b,c;
 D24fRefs refs;
 unsigned payload;
 D24fRecord &operator=(const D24fRecord &x);
};
struct D24fRecordVector {
 D24fRecord *start,*finish;
 int allocator;
 D24fRecord *storage_end;
 unsigned size() const { return finish-start; }
 D24fRecord *erase(D24fRecord *first,D24fRecord *last);
 void resize(unsigned n,const D24fRecord &x);
};
extern "C" void sol35f6a_record32_insert_80347dec(D24fRecordVector *,D24fRecord *,unsigned,const D24fRecord &);
template<class T> inline void d24f_destroy(T *p) { p->~T(); }
struct D24fNotPod {};
template<class T> inline void d24f_destroy_aux(T *first,T *last,const D24fNotPod &) { for(;first!=last;++first) d24f_destroy(first); }
template<class T> inline void d24f_destroy_typed(T *first,T *last,T *) { d24f_destroy_aux(first,last,D24fNotPod()); }
template<class T> inline void d24f_destroy_range(T *first,T *last) { d24f_destroy_typed(first,last,(T *)0); }
template<class T> inline T *d24f_copy_ptrs(const T *first,const T *last,T *out,const D24fNotPod &) { for(int n=last-first;n>0;--n) { *out=*first;++first;++out; } return out; }
inline D24fRecord *D24fRecordVector::erase(D24fRecord *first,D24fRecord *last) {
 D24fRecord *kept=d24f_copy_ptrs((const D24fRecord *)last,(const D24fRecord *)finish,first,D24fNotPod());
 d24f_destroy_range(kept,finish);
 finish=kept;
 return first;
}
inline void D24fRecordVector::resize(unsigned n,const D24fRecord &x) {
 if(n<size()) erase(start+n,finish);
 else sol35f6a_record32_insert_80347dec(this,finish,n-size(),x);
}
struct D24fRecordOwner {
 char pad[20];
 unsigned count;
 D24fRecordVector records;
};
extern "C" int d24f_record_vector_resize_80348a4c(D24fRecordOwner *self,unsigned n) {
 self->records.resize(n,D24fRecord());
 self->count=n;
 return 0;
}
