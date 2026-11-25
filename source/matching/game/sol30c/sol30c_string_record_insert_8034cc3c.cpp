// GWMP8P rev0: shared-string record fill insertion.
// Eight-byte records and a sixteen-byte vector are observed GC32 layouts;
// container and allocator identities remain structural inferences.
extern "C" void *native_array_allocate_801907a8(unsigned);
extern "C" void native_array_free_801907d0(void *);
inline void *operator new(unsigned,void *place) throw() { return place; }
struct Sol30cString;
extern "C" void sol30c_string_init_8020c5c0(Sol30cString *);
extern "C" void sol30c_string_finish_8020c5c4(Sol30cString *);
extern "C" void sol30c_string_release_80341588(Sol30cString *);
extern "C" unsigned short *sol30c_string_header_80341884(Sol30cString *);
// Six-byte prefix observed at data - 6; other halfword meanings are unknown.
struct Sol30cStringHeader { unsigned short references; unsigned short metadata0,metadata1; };
extern "C" void sol30c_header_release_8020bb2c(Sol30cStringHeader *);
struct Sol30cString {
    char *data;
    Sol30cString(const Sol30cString &x) {
        sol30c_string_init_8020c5c0(this);
        data=x.data;
        ++*sol30c_string_header_80341884(this);
    }
    ~Sol30cString() {
        sol30c_string_finish_8020c5c4(this);
        sol30c_string_release_80341588(this);
    }
    Sol30cStringHeader *header() const { return ((Sol30cStringHeader *)data)-1; }
    // The original computes the header before decrementing and passes that same
    // pointer to release; capture it as a helper argument across the decrement.
    static void release(Sol30cStringHeader *h) { if(--h->references==0) sol30c_header_release_8020bb2c(h); }
    Sol30cString &operator=(const Sol30cString &x) {
        ++x.header()->references;
        release(header());
        data=x.data;
        return *this;
    }
};
// Original stores the two byte fields separately and the final halfword.
struct Sol30cRecord {
    Sol30cString name;
    unsigned char first,second;
    unsigned short value;
};
template<class T> struct Sol30cRecordAllocator {
    Sol30cRecordAllocator() {}
    Sol30cRecordAllocator(const Sol30cRecordAllocator &) {}
    T *allocate(unsigned count) { return (T *)native_array_allocate_801907a8(count*sizeof(T)); }
    void deallocate(T *p,unsigned) { if(p) native_array_free_801907d0(p); }
};
template<class T> struct Sol30cRecordStorageEnd : Sol30cRecordAllocator<T> { T *data; };
template<class T> inline const T &sol30c_record_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol30c_record_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol30c_record_destroy(T *p) { p->~T(); }
template<class T> inline void sol30c_record_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol30c_record_destroy(first);
}
template<class T> inline void sol30c_record_destroy_range(T *first,T *last) { sol30c_record_destroy_range_aux(first,last); }
struct Sol30cRecordNotTrivial {};
template<class T> inline T *sol30c_record_uninitialized_copy(const T *first,const T *last,T *out,const Sol30cRecordNotTrivial &) {
    for(;first!=last;++first,++out) sol30c_record_construct(out,*first);
    return out;
}
template<class T> inline T *sol30c_record_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol30c_record_construct(out,value);
    return out;
}
template<class T> inline T *sol30c_record_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol30c_record_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol30cRecordVector {
    T *start,*finish;
    Sol30cRecordStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol30c_record_destroy_range(start,finish);
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(T *s,T *f,T *e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(T *pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+sol30c_record_max(old_size,fill_len);
        T *new_start=end_of_storage.allocate(len);
        T *new_finish=sol30c_record_uninitialized_copy((const T *)start,(const T *)pos,new_start,Sol30cRecordNotTrivial());
        if(fill_len==1) {
            sol30c_record_construct(new_finish,x);
            ++new_finish;
        } else {
            new_finish=sol30c_record_uninitialized_fill_n(new_finish,fill_len,x);
        }
        new_finish=sol30c_record_uninitialized_copy((const T *)pos,(const T *)finish,new_finish,Sol30cRecordNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }

};
typedef Sol30cRecordVector<Sol30cRecord> Sol30cRecordContainer;
typedef char Sol30cRecordFootprint[(sizeof(Sol30cRecord)==8)?1:-1];
typedef char Sol30cRecordVectorFootprint[(sizeof(Sol30cRecordContainer)==16)?1:-1];
extern "C" void sol30c_record_fill_insert_8034cc3c(Sol30cRecordContainer *self,Sol30cRecord *pos,unsigned n,const Sol30cRecord &x) {
    typedef Sol30cRecord T;

    if(n!=0) {
        if(unsigned(self->end_of_storage.data-self->finish)>=n) {
            T x_copy=x;
            const unsigned elems_after=self->finish-pos;
            T *old_finish=self->finish;
            if(elems_after>n) {
                sol30c_record_uninitialized_copy((const T *)(self->finish-n),(const T *)self->finish,self->finish,Sol30cRecordNotTrivial());
                self->finish+=n;
                sol30c_record_copy_backward((const T *)pos,(const T *)(old_finish-n),old_finish);
                sol30c_record_assign(pos,pos+n,x_copy);
            } else {
                sol30c_record_uninitialized_fill_n(self->finish,n-elems_after,x_copy);
                self->finish+=n-elems_after;
                sol30c_record_uninitialized_copy((const T *)pos,(const T *)old_finish,self->finish,Sol30cRecordNotTrivial());
                self->finish+=elems_after;
                sol30c_record_assign(pos,old_finish,x_copy);
            }
        } else {
            self->insert_overflow(pos,x,n);
        }
    }
    
}

