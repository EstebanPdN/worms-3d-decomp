// GWMP8P rev0 0x80347570: shared-string fill insertion.
// GC32 element stride 4; vector footprint 16, start +0, finish +4,
// allocator base +8, storage end +12. Header is six bytes before string data.
// Real string copy/assignment/destruction follow original ownership operations.
// Growth initializes its advancing destination iterator before the first copy.
// Names and STL identity remain inferred. Valid live storage, same-array bounds
// and external ownership contracts are required; native null-empty pointer
// arithmetic is not ISO-portable or runtime equivalence evidence.
extern "C" void *sol35f7a_pool_allocate_80212fd4(unsigned);
extern "C" void *sol35f7a_pool_fallback_803413d8(unsigned);
extern "C" void sol35f7a_pool_free_802134fc(void *);
inline void *operator new(unsigned,void *place) throw() { return place; }
struct Sol35f7aPoolString;
extern "C" void sol35f7a_pool_string_init_8020c5c0(Sol35f7aPoolString *);
extern "C" void sol35f7a_pool_string_finish_8020c5c4(Sol35f7aPoolString *);
extern "C" void sol35f7a_pool_string_release_80341588(Sol35f7aPoolString *);
extern "C" unsigned short *sol35f7a_pool_string_header_80341884(Sol35f7aPoolString *);
struct Sol35f7aPoolStringHeader { unsigned short references; unsigned short length,capacity; };
extern "C" void sol35f7a_pool_header_release_8020bb2c(Sol35f7aPoolStringHeader *);
struct Sol35f7aPoolString {
    char *data;
    Sol35f7aPoolString(const Sol35f7aPoolString &x) {
        sol35f7a_pool_string_init_8020c5c0(this);
        data=x.data;
        ++*sol35f7a_pool_string_header_80341884(this);
    }
    ~Sol35f7aPoolString() {
        sol35f7a_pool_string_finish_8020c5c4(this);
        sol35f7a_pool_string_release_80341588(this);
    }
    Sol35f7aPoolStringHeader *header() const { return ((Sol35f7aPoolStringHeader *)data)-1; }
    static void release(Sol35f7aPoolStringHeader *h) { if(--h->references==0) sol35f7a_pool_header_release_8020bb2c(h); }
    Sol35f7aPoolString &operator=(const Sol35f7aPoolString &x) {
        ++x.header()->references;
        release(header());
        data=x.data;
        return *this;
    }
};
template<class T> struct Sol35f7aPoolRecordAllocator {
    Sol35f7aPoolRecordAllocator() {}
    Sol35f7aPoolRecordAllocator(const Sol35f7aPoolRecordAllocator &) {}
    static void *allocate_bytes(unsigned bytes) {
        void *p=sol35f7a_pool_allocate_80212fd4(bytes);
        if(!p) p=sol35f7a_pool_fallback_803413d8(bytes);
        return p;
    }
    T *allocate(unsigned count) { return count ? (T *)allocate_bytes(count*sizeof(T)) : 0; }
    void deallocate(T *p,unsigned) { if(p) sol35f7a_pool_free_802134fc(p); }
};
template<class T> struct Sol35f7aPoolRecordStorageEnd : Sol35f7aPoolRecordAllocator<T> { T *data; };
template<class T> inline const T &sol35f7a_pool_record_max(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline void sol35f7a_pool_record_construct(T *p,const T &value) { new(p) T(value); }
template<class T> inline void sol35f7a_pool_record_destroy(T *p) { p->~T(); }
template<class T> inline void sol35f7a_pool_record_destroy_range_aux(T *first,T *last) {
    for(;first!=last;++first) sol35f7a_pool_record_destroy(first);
}
template<class T> inline void sol35f7a_pool_record_destroy_range(T *first,T *last) { sol35f7a_pool_record_destroy_range_aux(first,last); }
struct Sol35f7aPoolRecordNotTrivial {};
template<class T> inline T *sol35f7a_pool_record_uninitialized_copy(const T *first,const T *last,T *out,const Sol35f7aPoolRecordNotTrivial &) {
    for(;first!=last;++first,++out) sol35f7a_pool_record_construct(out,*first);
    return out;
}
template<class T> inline T *sol35f7a_pool_record_uninitialized_fill_n(T *out,unsigned n,const T &value) {
    for(;n>0;--n,++out) sol35f7a_pool_record_construct(out,value);
    return out;
}
template<class T> inline T *sol35f7a_pool_record_copy_backward(const T *first,const T *last,T *result) {
    for(int n=last-first;n>0;--n) *--result=*--last;
    return result;
}
template<class T> inline void sol35f7a_pool_record_assign(T *first,T *last,const T &value) {
    for(;first!=last;++first) *first=value;
}
template<class T> struct Sol35f7aPoolRecordVector {
    T *start,*finish;
    Sol35f7aPoolRecordStorageEnd<T> end_of_storage;
    unsigned size() const { return finish-start; }
    void clear_storage() {
        sol35f7a_pool_record_destroy_range(start,finish);
        end_of_storage.deallocate(start,end_of_storage.data-start);
    }
    void set(T *s,T *f,T *e) { start=s; finish=f; end_of_storage.data=e; }
    void insert_overflow(T *pos,const T &x,unsigned fill_len) {
        const unsigned old_size=size();
        const unsigned len=old_size+sol35f7a_pool_record_max(old_size,fill_len);
        T *new_start=end_of_storage.allocate(len);
        T *new_finish=new_start;
        new_finish=sol35f7a_pool_record_uninitialized_copy((const T *)start,(const T *)pos,new_finish,Sol35f7aPoolRecordNotTrivial());
        if(fill_len==1) {
            sol35f7a_pool_record_construct(new_finish,x);
            ++new_finish;
        } else {
            new_finish=sol35f7a_pool_record_uninitialized_fill_n(new_finish,fill_len,x);
        }
        new_finish=sol35f7a_pool_record_uninitialized_copy((const T *)pos,(const T *)finish,new_finish,Sol35f7aPoolRecordNotTrivial());
        clear_storage();
        set(new_start,new_finish,new_start+len);
    }

};
typedef Sol35f7aPoolRecordVector<Sol35f7aPoolString> Sol35f7aPoolRecordContainer;
typedef char Sol35f7aPoolStringFootprint[(sizeof(Sol35f7aPoolString)==4)?1:-1];
typedef char Sol35f7aPoolRecordVectorFootprint[(sizeof(Sol35f7aPoolRecordContainer)==16)?1:-1];
extern "C" void sol35f7a_string_insert_80347570(Sol35f7aPoolRecordContainer *self,Sol35f7aPoolString *pos,unsigned n,const Sol35f7aPoolString &x) {
    typedef Sol35f7aPoolString T;

    if(n!=0) {
        if(unsigned(self->end_of_storage.data-self->finish)>=n) {
            T x_copy=x;
            const unsigned elems_after=self->finish-pos;
            T *old_finish=self->finish;
            if(elems_after>n) {
                sol35f7a_pool_record_uninitialized_copy((const T *)(self->finish-n),(const T *)self->finish,self->finish,Sol35f7aPoolRecordNotTrivial());
                self->finish+=n;
                sol35f7a_pool_record_copy_backward((const T *)pos,(const T *)(old_finish-n),old_finish);
                sol35f7a_pool_record_assign(pos,pos+n,x_copy);
            } else {
                sol35f7a_pool_record_uninitialized_fill_n(self->finish,n-elems_after,x_copy);
                self->finish+=n-elems_after;
                sol35f7a_pool_record_uninitialized_copy((const T *)pos,(const T *)old_finish,self->finish,Sol35f7aPoolRecordNotTrivial());
                self->finish+=elems_after;
                sol35f7a_pool_record_assign(pos,old_finish,x_copy);
            }
        } else {
            self->insert_overflow(pos,x,n);
        }
    }
    
}

