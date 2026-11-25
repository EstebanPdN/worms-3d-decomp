// Recovered from GWMP8P rev0. Both bodies use 12-byte records and 16-byte containers.
// Copy construction uses the observed whole-record assignment shape; allocator identity
// and container naming are inferred, while layouts are reference GC32 ABI facts.
extern "C" void *native_array_allocate_801907a8(unsigned);
extern "C" void native_array_free_801907d0(void *);
inline void *operator new(unsigned,void *place) throw() { return place; }
// Opaque 12-byte record; the original uses integer word copies at offsets 0, 4 and 8.
struct Sol29cRecord {
    unsigned x,y,z;
    Sol29cRecord(const Sol29cRecord &v) { *this=v; }
};
template<class T> struct Sol29cRecordAllocator {
    Sol29cRecordAllocator() {}
    Sol29cRecordAllocator(const Sol29cRecordAllocator &) {}
    T *allocate(unsigned count) { return (T *)native_array_allocate_801907a8(count*sizeof(T)); }
    void deallocate(T *p,unsigned) { if(p) native_array_free_801907d0(p); }
};
template<class T> struct Sol29cRecordStorageEnd : Sol29cRecordAllocator<T> { T *data; };
template<class T> inline const T &sol29c_record_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol29c_record_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol29c_record_destroy(T *p) { p->~T(); }
template<class T> inline void sol29c_record_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol29c_record_destroy(first);
}
template<class T> inline void sol29c_record_destroy_range(T *first,T *last) { sol29c_record_destroy_range_aux(first,last); }
struct Sol29cRecordNotTrivial {};
template<class T> inline T *sol29c_record_uninitialized_copy(const T *first,const T *last,T *out,const Sol29cRecordNotTrivial &) {
    for(;first!=last;++first,++out) sol29c_record_construct(out,*first);
    return out;
}
template<class T> inline T *sol29c_record_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol29c_record_construct(out,value);
    return out;
}
template<class T> inline T *sol29c_record_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol29c_record_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol29cRecordVector {
    T *start,*finish;
    Sol29cRecordStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol29c_record_destroy_range(start,finish);
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(T *s,T *f,T *e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(T *pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+sol29c_record_max(old_size,fill_len);
        T *new_start=end_of_storage.allocate(len);
        T *new_finish=sol29c_record_uninitialized_copy((const T *)start,(const T *)pos,new_start,Sol29cRecordNotTrivial());
        if(fill_len==1) {
            sol29c_record_construct(new_finish,x);
            ++new_finish;
        } else {
            new_finish=sol29c_record_uninitialized_fill_n(new_finish,fill_len,x);
        }
        new_finish=sol29c_record_uninitialized_copy((const T *)pos,(const T *)finish,new_finish,Sol29cRecordNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }

};
typedef Sol29cRecordVector<Sol29cRecord> Sol29cRecordContainer;
typedef char Sol29cRecordFootprint[(sizeof(Sol29cRecord)==12)?1:-1];
typedef char Sol29cRecordVectorFootprint[(sizeof(Sol29cRecordContainer)==16)?1:-1];
extern "C" void sol29c_record_fill_insert_8034f47c(Sol29cRecordContainer *self,Sol29cRecord *pos,unsigned n,const Sol29cRecord &x) {
    typedef Sol29cRecord T;

    if(n!=0) {
        if(unsigned(self->end_of_storage.data-self->finish)>=n) {
            T x_copy=x;
            const unsigned elems_after=self->finish-pos;
            T *old_finish=self->finish;
            if(elems_after>n) {
                sol29c_record_uninitialized_copy((const T *)(self->finish-n),(const T *)self->finish,self->finish,Sol29cRecordNotTrivial());
                self->finish+=n;
                sol29c_record_copy_backward((const T *)pos,(const T *)(old_finish-n),old_finish);
                sol29c_record_assign(pos,pos+n,x_copy);
            } else {
                sol29c_record_uninitialized_fill_n(self->finish,n-elems_after,x_copy);
                self->finish+=n-elems_after;
                sol29c_record_uninitialized_copy((const T *)pos,(const T *)old_finish,self->finish,Sol29cRecordNotTrivial());
                self->finish+=elems_after;
                sol29c_record_assign(pos,old_finish,x_copy);
            }
        } else {
            self->insert_overflow(pos,x,n);
        }
    }
    
}

extern "C" void sol29c_record_fill_insert_8034d1c8(Sol29cRecordContainer *self,Sol29cRecord *pos,unsigned n,const Sol29cRecord &x) {
    typedef Sol29cRecord T;

    if(n!=0) {
        if(unsigned(self->end_of_storage.data-self->finish)>=n) {
            T x_copy=x;
            const unsigned elems_after=self->finish-pos;
            T *old_finish=self->finish;
            if(elems_after>n) {
                sol29c_record_uninitialized_copy((const T *)(self->finish-n),(const T *)self->finish,self->finish,Sol29cRecordNotTrivial());
                self->finish+=n;
                sol29c_record_copy_backward((const T *)pos,(const T *)(old_finish-n),old_finish);
                sol29c_record_assign(pos,pos+n,x_copy);
            } else {
                sol29c_record_uninitialized_fill_n(self->finish,n-elems_after,x_copy);
                self->finish+=n-elems_after;
                sol29c_record_uninitialized_copy((const T *)pos,(const T *)old_finish,self->finish,Sol29cRecordNotTrivial());
                self->finish+=elems_after;
                sol29c_record_assign(pos,old_finish,x_copy);
            }
        } else {
            self->insert_overflow(pos,x,n);
        }
    }
    
}
