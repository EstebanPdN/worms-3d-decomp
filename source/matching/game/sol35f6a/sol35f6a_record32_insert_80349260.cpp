// GWMP8P rev0: repeated insertion of observed 32-byte retained records.
// GC32 outer vector: start +0, finish +4, allocator base +8, storage end +12.
// Element: word +0; held interfaces +4/+8/+12; counted-reference array +16;
// payload word +28. Interface retain/release dispatch at +12/+16 requires
// the observed four-byte thunk vtable ABI (-fvtable-thunks).
// Copy construction/destruction follows member lifetimes. Growth initializes
// its advancing destination iterator from new_start before the first copy.
// Names, semantic types and STL identity remain inferred. Valid storage,
// live compatible interfaces, representable same-array pointer arithmetic
// and external allocator/copy/destructor contracts are required. Native
// null-empty subtraction is not an ISO C++ portability guarantee.
inline void *operator new(unsigned,void *place) throw() { return place; }
extern "C" void *sol35f6a_allocate_80212fd4(unsigned);
extern "C" void *sol35f6a_fallback_803413d8(unsigned);
extern "C" void sol35f6a_release_802134fc(void *);
// Fresh record ABI from 0x80349260: word, three retained interfaces,
// 12-byte counted reference array, trailing word. All names are inferred.
struct Interface {
 virtual void slot0()=0;
 virtual void retain()=0;
 virtual void release()=0;
};
struct HeldInterface {
 Interface *pointer;
 HeldInterface(const HeldInterface &x):pointer(x.pointer) { if(pointer) pointer->retain(); }
 ~HeldInterface() { if(pointer) pointer->release(); }
};
struct CountedRefs;
extern "C" CountedRefs *sol35f6a_copy_refs_802109fc(CountedRefs *,const CountedRefs *);
extern "C" void sol35f6a_destroy_refs_80210abc(CountedRefs *,int);
struct CountedRefs {
 unsigned count;
 unsigned short capacity,growth;
 Interface **slots;
 CountedRefs(const CountedRefs &x) { sol35f6a_copy_refs_802109fc(this,&x); }
 ~CountedRefs() { sol35f6a_destroy_refs_80210abc(this,2); }
};
struct RefRecord;
extern "C" RefRecord *sol35f6a_assign_80349154(RefRecord *,const RefRecord *);
struct RefRecord {
 unsigned key;
 HeldInterface a,b,c;
 CountedRefs refs;
 unsigned payload;
 RefRecord &operator=(const RefRecord &x) { sol35f6a_assign_80349154(this,&x); return *this; }
};
template<class T> struct FillAllocator {
    FillAllocator() {}
    FillAllocator(const FillAllocator &) {}
    static void *storage(unsigned bytes) {void *p=sol35f6a_allocate_80212fd4(bytes);if(!p)p=sol35f6a_fallback_803413d8(bytes);return p;}
    T *allocate(unsigned count) {return count?(T *)storage(count*sizeof(T)):0;}
    void deallocate(T *p,unsigned) { if(p) sol35f6a_release_802134fc(p); }
};
template<class T> struct FillStorageEnd : FillAllocator<T> { T *data; };
template<class T> inline const T &fill_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void fill_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void fill_destroy(T *p) { p->~T(); }
template<class T> inline void fill_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) fill_destroy(first);
}
template<class T> inline void fill_destroy_range(T *first,T *last) { fill_destroy_range_aux(first,last); }
struct FillNotTrivial {};
template<class T> inline T *fill_uninitialized_copy(const T *first,const T *last,T *out,const FillNotTrivial &) {
    for(;first!=last;++first,++out) fill_construct(out,*first);
    return out;
}
template<class T> inline T *fill_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) fill_construct(out,value);
    return out;
}
template<class T> inline T *fill_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void fill_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct FillVector {
    T *start,*finish;
    FillStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        fill_destroy_range(start,finish);
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(T *s,T *f,T *e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(T *pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+fill_max(old_size,fill_len);
        T *new_start=end_of_storage.allocate(len);
        T *new_finish=new_start;
        new_finish=fill_uninitialized_copy((const T *)start,(const T *)pos,new_finish,FillNotTrivial());
        if(fill_len==1) {
            fill_construct(new_finish,x);
            ++new_finish;
        } else {
            new_finish=fill_uninitialized_fill_n(new_finish,fill_len,x);
        }
        new_finish=fill_uninitialized_copy((const T *)pos,(const T *)finish,new_finish,FillNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }
};
typedef FillVector<RefRecord> RefRecordVector;
typedef char RefRecordFootprint[(sizeof(RefRecord)==32)?1:-1];
typedef char FillVectorFootprint[(sizeof(RefRecordVector)==16)?1:-1];
extern "C" void sol35f6a_record32_insert_80349260(RefRecordVector *self,RefRecord *pos,unsigned n,const RefRecord &x) {
    typedef RefRecord T;
        if(n!=0) {
            if(unsigned(self->end_of_storage.data-self->finish)>=n) {
                T x_copy=x;
                const unsigned elems_after=self->finish-pos;
                T *old_finish=self->finish;
                if(elems_after>n) {
                    fill_uninitialized_copy((const T *)(self->finish-n),(const T *)self->finish,self->finish,FillNotTrivial());
                    self->finish+=n;
                    fill_copy_backward((const T *)pos,(const T *)(old_finish-n),old_finish);
                    fill_assign(pos,pos+n,x_copy);
                } else {
                    fill_uninitialized_fill_n(self->finish,n-elems_after,x_copy);
                    self->finish+=n-elems_after;
                    fill_uninitialized_copy((const T *)pos,(const T *)old_finish,self->finish,FillNotTrivial());
                    self->finish+=elems_after;
                    fill_assign(pos,old_finish,x_copy);
                }
            } else {
                self->insert_overflow(pos,x,n);
            }
        }
}
