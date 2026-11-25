// 0x8034e638: insert n copies of a vector of 12-byte records before a
// position in a vector of such vectors. Inferred STLport-shaped containers
// (identity unverified), layout as in the admitted 0x8034efd0 reserve: begin at
// 0, finish at 4, an allocator proxy at 8 holding the storage-end pointer at
// proxy offset 4, 16 bytes per inner vector. Same insertion template as the
// 4-byte instance at 0x8034f1a0. Evidence for the structure below:
//  - inner copies use an allocating base constructor taking the length and a
//    by-value allocator temporary (zeroed fields, allocate, then copy);
//  - placement construction is null-checked (operator new declared throw());
//  - inner assignment is not inlined: it calls the function at 0x8034e408,
//    declared here as an external native alias (not part of this unit);
//  - the saved value copy lives in the frame (8(r1)) and is destroyed and
//    freed where the spare-capacity branches join;
//  - the body is the insertion member compiled out of line: in the shared
//    destructor block the copy's finish is read through the object pointer
//    (4(r21)), which only happens when the body is not inlined into a caller.
// Allocation 0x801907a8 takes a byte count; release 0x801907d0 a block.
// Portability: the 16-byte layouts assume 32-bit pointers (checked below).
extern "C" void *native_array_allocate_801907a8(unsigned);
extern "C" void native_array_free_801907d0(void *);
inline void *operator new(unsigned,void *place) throw() { return place; }
template<class T> struct NestAllocator {
    NestAllocator() {}
    NestAllocator(const NestAllocator &) {}
    T *allocate(unsigned count) { return (T *)native_array_allocate_801907a8(count*sizeof(T)); }
    void deallocate(T *p,unsigned) { if(p) native_array_free_801907d0(p); }
};
template<class T> struct NestStorageEnd : NestAllocator<T> {
    T *data;
    NestStorageEnd(const NestAllocator<T> &a,T *p):NestAllocator<T>(a),data(p) {}
};
template<class T> inline const T &nest_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void nest_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void nest_destroy(T *p) { p->~T(); }
template<class T> inline void nest_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) nest_destroy(first);
}
template<class T> inline void nest_destroy_range(T *first,T *last) { nest_destroy_range_aux(first,last); }
struct NestNotTrivial {};
template<class T> inline T *nest_uninitialized_copy(const T *first,const T *last,T *out,const NestNotTrivial &) {
    for(;first!=last;++first,++out) nest_construct(out,*first);
    return out;
}
template<class T> inline T *nest_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) nest_construct(out,value);
    return out;
}
template<class T> inline T *nest_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void nest_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct NestVectorBase {
    T *start,*finish;
    NestStorageEnd<T> end_of_storage;
    NestVectorBase(unsigned n,const NestAllocator<T> &a):start(0),finish(0),end_of_storage(a,0) {
        start=end_of_storage.allocate(n);
        finish=start;
        end_of_storage.data=start+n;
    }
    ~NestVectorBase() { if(start!=0) end_of_storage.deallocate(start,end_of_storage.data-start); }
};
// Record payload is not recovered; copied as three words.
struct NestRecord { unsigned x,y,z; };
struct NestRecordVector;
// External: out-of-line assignment of the inner record vector (0x8034e408).
extern "C" NestRecordVector *native_record_vector_assign_8034e408(NestRecordVector *,const NestRecordVector *);
struct NestRecordVector : NestVectorBase<NestRecord> {
    unsigned size() const { return finish-start; }
    NestAllocator<NestRecord> get_allocator() const { return end_of_storage; }
    NestRecordVector(const NestRecordVector &x):NestVectorBase<NestRecord>(x.size(),x.get_allocator()) {
        finish=nest_uninitialized_copy((const NestRecord *)x.start,(const NestRecord *)x.finish,start,NestNotTrivial());
    }
    ~NestRecordVector() { nest_destroy_range(start,finish); }
    NestRecordVector &operator=(const NestRecordVector &x) {
        native_record_vector_assign_8034e408(this,&x);
        return *this;
    }
};
template<class T> struct NestVector {
    T *start,*finish;
    NestStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        nest_destroy_range(start,finish);
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(T *s,T *f,T *e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(T *pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+nest_max(old_size,fill_len);
        T *new_start=end_of_storage.allocate(len);
        T *new_finish=nest_uninitialized_copy((const T *)start,(const T *)pos,new_start,NestNotTrivial());
        if(fill_len==1) {
            nest_construct(new_finish,x);
            ++new_finish;
        } else {
            new_finish=nest_uninitialized_fill_n(new_finish,fill_len,x);
        }
        new_finish=nest_uninitialized_copy((const T *)pos,(const T *)finish,new_finish,NestNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }
};
typedef NestVector<NestRecordVector> NestedRecordVector;
typedef char NestRecordFootprint[(sizeof(NestRecord)==12)?1:-1];
typedef char NestInnerFootprint[(sizeof(NestRecordVector)==16)?1:-1];
typedef char NestOuterFootprint[(sizeof(NestedRecordVector)==16)?1:-1];
// Out-of-line insertion member of the outer vector.
extern "C" void mx25oc_nested_vector_fill_insert_8034e638(NestedRecordVector *self,NestRecordVector *pos,unsigned n,const NestRecordVector &x) {
    typedef NestRecordVector T;
    if(n!=0) {
        if(unsigned(self->end_of_storage.data-self->finish)>=n) {
            T x_copy=x;
            const unsigned elems_after=self->finish-pos;
            T *old_finish=self->finish;
            if(elems_after>n) {
                nest_uninitialized_copy((const T *)(self->finish-n),(const T *)self->finish,self->finish,NestNotTrivial());
                self->finish+=n;
                nest_copy_backward((const T *)pos,(const T *)(old_finish-n),old_finish);
                nest_assign(pos,pos+n,x_copy);
            } else {
                nest_uninitialized_fill_n(self->finish,n-elems_after,x_copy);
                self->finish+=n-elems_after;
                nest_uninitialized_copy((const T *)pos,(const T *)old_finish,self->finish,NestNotTrivial());
                self->finish+=elems_after;
                nest_assign(pos,old_finish,x_copy);
            }
        } else {
            self->insert_overflow(pos,x,n);
        }
    }
}
