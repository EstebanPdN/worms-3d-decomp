// GWMP8P rev0 0x80354f08: fill insertion into a vector of owned-buffer records.
// Names and STL identity are inferred. On GC32 the record is a 12-byte buffer
// (start, finish, capacity) plus one payload word; the outer vector is 16 bytes.
// Copy construction allocates and copies exactly the source buffer length;
// assignment resizes existing storage, then copies. Destruction releases it.
// The outer growth allocator has a zero-count guard and out-of-memory fallback.
// The first destination iterator starts at the newly allocated start before
// uninitialized copying advances it. This lifetime reproduces the growth join.
// Pointer differences require valid same-array bounds; null-empty subtraction
// follows the reference compiler idiom and is not an ISO portability proof.
inline void *operator new(unsigned,void *place) throw() { return place; }
extern "C" void *sol35f4r_allocate_80212fd4(unsigned);
extern "C" void *sol35f4r_fallback_803413d8(unsigned);
extern "C" void sol35f4r_release_802134fc(void *);
extern "C" void *sol35f4r_resize_80213750(void *,unsigned);
// Original call sites clear CR1.eq immediately before memcpy: variadic ABI.
extern "C" void *sol35f4r_memcpy_802eee50(void *,const void *,unsigned,...);
struct Buffer {
 char *start,*finish,*capacity;
 Buffer(const Buffer &x) {
  unsigned length=x.finish-x.start;
  start=(char *)sol35f4r_allocate_80212fd4(length);
  capacity=finish=start+length;
  sol35f4r_memcpy_802eee50(start,x.start,length);
 }
 ~Buffer(){if(start)sol35f4r_release_802134fc(start);}
 Buffer &operator=(const Buffer &x) {
  unsigned length=x.finish-x.start;
  start=(char *)sol35f4r_resize_80213750(start,length);
  capacity=finish=start+length;
  sol35f4r_memcpy_802eee50(start,x.start,length);
  return *this;
 }
};
struct BufferRecord {
    Buffer bytes;
    unsigned payload;
    BufferRecord(const BufferRecord &x):bytes(x.bytes),payload(x.payload) {}
};
template<class T> struct FillAllocator {
    FillAllocator() {}
    FillAllocator(const FillAllocator &) {}
    static void *storage(unsigned bytes) {void *p=sol35f4r_allocate_80212fd4(bytes);if(!p)p=sol35f4r_fallback_803413d8(bytes);return p;}
    T *allocate(unsigned count) {return count?(T *)storage(count*sizeof(T)):0;}
    void deallocate(T *p,unsigned) { if(p) sol35f4r_release_802134fc(p); }
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
typedef FillVector<BufferRecord> BufferRecordVector;
typedef char BufferRecordFootprint[(sizeof(BufferRecord)==16)?1:-1];
typedef char FillVectorFootprint[(sizeof(BufferRecordVector)==16)?1:-1];
extern "C" void sol35f4r_nested_buffer_insert_80354f08(BufferRecordVector *self,BufferRecord *pos,unsigned n,const BufferRecord &x) {
    typedef BufferRecord T;
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
