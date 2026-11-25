// GWMP8P rev0 0x803501ac: fill insertion for an opaque retained 16-byte record.
// Direct four-byte virtual entries at vtable offsets 12 and 16 independently
// require the original thunk ABI (-fvtable-thunks); this is not a flag search.
extern "C" void *native_array_allocate_801907a8(unsigned);
extern "C" void native_array_free_801907d0(void *);
inline void *operator new(unsigned,void *place) throw() { return place; }
// Observed interface handle followed by four byte fields and two words.
struct Sol29cRetainedInterface {
    virtual void slot0()=0;
    virtual void retain()=0;
    virtual void release()=0;
};
struct Sol29cRetainedHandle {
    Sol29cRetainedInterface *pointer;
    Sol29cRetainedHandle(const Sol29cRetainedHandle &x):pointer(x.pointer) { if(pointer) pointer->retain(); }
    ~Sol29cRetainedHandle() { if(pointer) pointer->release(); }
    Sol29cRetainedHandle &operator=(const Sol29cRetainedHandle &x) {
        if(x.pointer) x.pointer->retain();
        if(pointer) pointer->release();
        pointer=x.pointer;
        return *this;
    }
};
struct Sol29cRetainedRecord {
    Sol29cRetainedHandle handle;
    unsigned char a,b,c,d;
    unsigned value0,value1;
};
template<class T> struct Sol29cRetainedAllocator {
    Sol29cRetainedAllocator() {}
    Sol29cRetainedAllocator(const Sol29cRetainedAllocator &) {}
    T *allocate(unsigned count) { return (T *)native_array_allocate_801907a8(count*sizeof(T)); }
    void deallocate(T *p,unsigned) { if(p) native_array_free_801907d0(p); }
};
template<class T> struct Sol29cRetainedStorageEnd : Sol29cRetainedAllocator<T> { T *data; };
template<class T> inline const T &sol29c_retained_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol29c_retained_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol29c_retained_destroy(T *p) { p->~T(); }
template<class T> inline void sol29c_retained_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol29c_retained_destroy(first);
}
template<class T> inline void sol29c_retained_destroy_range(T *first,T *last) { sol29c_retained_destroy_range_aux(first,last); }
struct Sol29cRetainedNotTrivial {};
template<class T> inline T *sol29c_retained_uninitialized_copy(const T *first,const T *last,T *out,const Sol29cRetainedNotTrivial &) {
    for(;first!=last;++first,++out) sol29c_retained_construct(out,*first);
    return out;
}
template<class T> inline T *sol29c_retained_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol29c_retained_construct(out,value);
    return out;
}
template<class T> inline T *sol29c_retained_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol29c_retained_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol29cRetainedVector {
    T *start,*finish;
    Sol29cRetainedStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol29c_retained_destroy_range(start,finish);
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(T *s,T *f,T *e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(T *pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+sol29c_retained_max(old_size,fill_len);
        T *new_start=end_of_storage.allocate(len);
        T *new_finish=sol29c_retained_uninitialized_copy((const T *)start,(const T *)pos,new_start,Sol29cRetainedNotTrivial());
        if(fill_len==1) {
            sol29c_retained_construct(new_finish,x);
            ++new_finish;
        } else {
            new_finish=sol29c_retained_uninitialized_fill_n(new_finish,fill_len,x);
        }
        new_finish=sol29c_retained_uninitialized_copy((const T *)pos,(const T *)finish,new_finish,Sol29cRetainedNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }

};
typedef Sol29cRetainedVector<Sol29cRetainedRecord> Sol29cRetainedContainer;
typedef char Sol29cRetainedRecordFootprint[(sizeof(Sol29cRetainedRecord)==16)?1:-1];
typedef char Sol29cRetainedVectorFootprint[(sizeof(Sol29cRetainedContainer)==16)?1:-1];
extern "C" void sol29c_retained_fill_insert_803501ac(Sol29cRetainedContainer *self,Sol29cRetainedRecord *pos,unsigned n,const Sol29cRetainedRecord &x) {
    typedef Sol29cRetainedRecord T;

        if(n!=0) {
            if(unsigned(self->end_of_storage.data-self->finish)>=n) {
                T x_copy=x;
                const unsigned elems_after=self->finish-pos;
                T *old_finish=self->finish;
                if(elems_after>n) {
                    sol29c_retained_uninitialized_copy((const T *)(self->finish-n),(const T *)self->finish,self->finish,Sol29cRetainedNotTrivial());
                    self->finish+=n;
                    sol29c_retained_copy_backward((const T *)pos,(const T *)(old_finish-n),old_finish);
                    sol29c_retained_assign(pos,pos+n,x_copy);
                } else {
                    sol29c_retained_uninitialized_fill_n(self->finish,n-elems_after,x_copy);
                    self->finish+=n-elems_after;
                    sol29c_retained_uninitialized_copy((const T *)pos,(const T *)old_finish,self->finish,Sol29cRetainedNotTrivial());
                    self->finish+=elems_after;
                    sol29c_retained_assign(pos,old_finish,x_copy);
                }
            } else {
                self->insert_overflow(pos,x,n);
            }
        }
    
}
