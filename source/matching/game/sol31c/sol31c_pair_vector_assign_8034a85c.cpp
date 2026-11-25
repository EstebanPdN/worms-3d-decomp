// GWMP8P rev0: assignment of a vector of eight-byte records.
// Two whole-word copies, empty record destruction loops and a pool allocator
// are observed. Names describe layout, not recovered original class identity.
// This is a GC32 ABI reconstruction; portable integration is not verified.
inline void *operator new(unsigned,void *p) throw() { return p; }
extern "C" void *sol31c_pair_allocate_80212fd4(unsigned);
extern "C" void *sol31c_pair_fallback_803413d8(unsigned);
extern "C" void sol31c_pair_free_802134fc(void *);
struct Sol31cPairRecord { unsigned first,second; ~Sol31cPairRecord() {} };
struct Sol31cPairNontrivial {};
template<class T> inline void sol31c_pair_construct(T *p,const T &v) { new(p) T(v); }
template<class T> inline T *sol31c_pair_copy_aux(const T *first,const T *last,T *out) {
    for(int n=last-first;n>0;--n,++first,++out) *out=*first;
    return out;
}
template<class T> inline T *sol31c_pair_copy(const T *first,const T *last,T *out) { return sol31c_pair_copy_aux(first,last,out); }
template<class T> inline T *sol31c_pair_uninitialized_copy(const T *first,const T *last,T *out,Sol31cPairNontrivial) {
    for(;first!=last;++first,++out) sol31c_pair_construct(out,*first);
    return out;
}
template<class T> inline void sol31c_pair_destroy_aux(T *first,T *last) { for(;first!=last;++first) first->~T(); }
template<class T> inline void sol31c_pair_destroy(T *first,T *last) { sol31c_pair_destroy_aux(first,last); }
template<class T> struct Sol31cPairAllocator {
    T *allocate(unsigned n) {
        if(n) {
            unsigned bytes=n*sizeof(T);
            void *p=sol31c_pair_allocate_80212fd4(bytes);
            if(!p) p=sol31c_pair_fallback_803413d8(bytes);
            return (T *)p;
        }
        return 0;
    }
    void deallocate(T *p,unsigned) { if(p) sol31c_pair_free_802134fc(p); }
};
template<class T> struct Sol31cPairStorageEnd : Sol31cPairAllocator<T> { T *data; };
template<class T> struct Sol31cPairVector {
    T *start,*finish; Sol31cPairStorageEnd<T> storage;
    unsigned size() const { return finish-start; }
    unsigned capacity() const { return storage.data-start; }
    T *allocate_copy(unsigned n,const T *first,const T *last) {
        T *p=storage.allocate(n);
        sol31c_pair_uninitialized_copy(first,last,p,Sol31cPairNontrivial());
        return p;
    }
    Sol31cPairVector &operator=(const Sol31cPairVector &x) {
        if(&x!=this) {
            unsigned n=x.size();
            if(n>capacity()) {
                T *p=allocate_copy(n,x.start,x.finish);
                sol31c_pair_destroy(start,finish);
                storage.deallocate(start,capacity());
                start=p; storage.data=p+n;
            } else if(size()>=n) {
                T *last=sol31c_pair_copy(x.start,x.finish,start);
                sol31c_pair_destroy(last,finish);
            } else {
                sol31c_pair_copy(x.start,x.start+size(),start);
                sol31c_pair_uninitialized_copy(x.start+size(),x.finish,finish,Sol31cPairNontrivial());
            }
            finish=start+n;
        }
        return *this;
    }
};
typedef Sol31cPairVector<Sol31cPairRecord> Sol31cPairContainer;
typedef char Sol31cPairRecordSize[(sizeof(Sol31cPairRecord)==8)?1:-1];
typedef char Sol31cPairContainerSize[(sizeof(Sol31cPairContainer)==16)?1:-1];
extern "C" Sol31cPairContainer *sol31c_pair_vector_assign_8034a85c(Sol31cPairContainer *self,const Sol31cPairContainer *other) { return &(*self=*other); }
