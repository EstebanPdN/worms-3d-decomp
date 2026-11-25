// GWMP8P rev0 0x80346ef0: repeated unsigned-halfword insertion.
// GC32 vector footprint 16: start +0, finish +4, allocator base +8, storage
// end +12. Two-byte elements follow lhz/sth and original stride arithmetic.
// Generic trivial copy/fill/destruction dispatch and allocator lifetimes are
// inferred source structure; full linked instruction equality is separate
// from STL identity or portable behavior. Valid storage, bounds and external
// allocation/memmove contracts are required. Native null-empty pointer
// arithmetic is not an ISO C++ portability guarantee.
extern "C" void *sol35f7a_allocate_80212fd4(unsigned);
extern "C" void *sol35f7a_fallback_803413d8(unsigned);
extern "C" void sol35f7a_free_802134fc(void *);
extern "C" void *sol35f7a_move_802eeef4(void *,const void *,unsigned);
template<class T> struct Allocator {
    Allocator() {}
    Allocator(const Allocator &) {}
    static void *storage(unsigned bytes) {
        void *p=sol35f7a_allocate_80212fd4(bytes);
        if(!p)p=sol35f7a_fallback_803413d8(bytes);
        return p;
    }
    T *allocate(unsigned n) {return n?(T *)storage(n*sizeof(T)):0;}
    void deallocate(T *p,unsigned) {if(p)sol35f7a_free_802134fc(p);}
};
template<class T> struct StorageEnd : Allocator<T> {T *data;};
struct Trivial {};
template<class T> inline const T &maximum(const T &a,const T &b) {return a<b?b:a;}
template<class T> inline T *copy_words(const T *first,const T *last,T *out) {
    if(last!=first) {
        unsigned bytes=(const char *)last-(const char *)first;
        return (T *)((char *)sol35f7a_move_802eeef4(out,first,bytes)+bytes);
    }
    return out;
}
template<class T> inline T *copy_aux(const T *first,const T *last,T *out,const Trivial &) {return copy_words(first,last,out);}
template<class T> inline T *copy(const T *first,const T *last,T *out) {return copy_aux(first,last,out,Trivial());}
template<class T> inline T *fill_words(T *out,unsigned n,const T &x) {for(;n;--n,++out)*out=x;return out;}
template<class T> inline T *fill_aux(T *out,unsigned n,const T &x,const Trivial &) {return fill_words(out,n,x);}
template<class T> inline T *fill_n(T *out,unsigned n,const T &x) {return fill_aux(out,n,x,Trivial());}
template<class T> inline void fill(T *first,T *last,const T &x) {for(;first!=last;++first)*first=x;}
template<class T> inline T *copy_backward(const T *first,const T *last,T *out) {
    int bytes=(const char *)last-(const char *)first;
    if(bytes>0)sol35f7a_move_802eeef4((char *)out-bytes,first,bytes);
    return (T *)((char *)out-bytes);
}
template<class T> inline void destroy_aux(T *,T *,const Trivial &) {}
template<class T> inline void destroy(T *first,T *last) {destroy_aux(first,last,Trivial());}
template<class T> struct Vector {
    T *start,*finish;
    StorageEnd<T> storage_end;
    unsigned size() const {return finish-start;}
    void clear_storage() {destroy(start,finish);storage_end.deallocate(start,storage_end.data-start);}
    void set(T *s,T *f,T *e) {start=s;finish=f;storage_end.data=e;}
    void insert_overflow(T *pos,const T &x,unsigned n) {
        const unsigned old_size=size();
        const unsigned length=old_size+maximum(old_size,n);
        T *new_start=storage_end.allocate(length);
        T *new_finish=copy((const T *)start,(const T *)pos,new_start);
        new_finish=fill_n(new_finish,n,x);
        new_finish=copy((const T *)pos,(const T *)finish,new_finish);
        clear_storage();
        set(new_start,new_finish,new_start+length);
    }

};
typedef unsigned short Value;
typedef Vector<Value> HalfwordVector;
typedef char VectorFootprint[sizeof(HalfwordVector)==16?1:-1];
extern "C" void sol35f7a_halfword_insert_80346ef0(HalfwordVector *self,Value *pos,unsigned n,const Value &x) { typedef Value T;

        if(n) {
            if(unsigned(self->storage_end.data-self->finish)>=n) {
                T x_copy=x;
                const unsigned after=self->finish-pos;
                T *old_finish=self->finish;
                if(after>n) {
                    copy((const T *)(self->finish-n),(const T *)self->finish,self->finish);
                    self->finish+=n;
                    copy_backward((const T *)pos,(const T *)(old_finish-n),old_finish);
                    fill(pos,pos+n,x_copy);
                } else {
                    fill_n(self->finish,n-after,x_copy);
                    self->finish+=n-after;
                    copy((const T *)pos,(const T *)old_finish,self->finish);
                    self->finish+=after;
                    fill(pos,old_finish,x_copy);
                }
            } else self->insert_overflow(pos,x,n);
        }
    
}
