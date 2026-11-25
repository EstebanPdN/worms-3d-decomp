// Native four-byte value vector; inferred STL-like allocation and copy helpers.
inline void *operator new(unsigned,void *p) throw() { return p; }
namespace sol35d10_append_word {
extern "C" void *fn_80212fd4(unsigned);
extern "C" void *fn_803413d8(unsigned);
extern "C" void fn_802134fc(void *);
extern "C" void *fn_802eeef4(void *,const void *,unsigned);
template<class T> inline const T &maximum(const T &a,const T &b) { return a<b?b:a; }
template<class T> inline T *copy(const T *first,const T *last,T *out) {
    if(first!=last) return static_cast<T *>(fn_802eeef4(out,first,(last-first)*sizeof(T)))+(last-first);
    return out;
}
template<class T> inline T *fill(T *out,unsigned count,const T &value) {
    for(;count;--count,++out) new(out) T(value);
    return out;
}
template<class T> struct Allocator {
    T *allocate(unsigned n) {
        if(!n) return 0;
        unsigned bytes=n*sizeof(T);
        void *p=fn_80212fd4(bytes);
        if(!p) p=fn_803413d8(bytes);
        return static_cast<T *>(p);
    }
    void deallocate(T *p) { if(p) fn_802134fc(p); }
};
template<class T> struct StorageEnd : Allocator<T> { T *pointer; };
template<class T> struct Vector {
    T *start,*finish;
    StorageEnd<T> storage;
    unsigned size() const { return finish-start; }
    void append_slow(T *position,const T &value,unsigned n) {
        const unsigned old_size=size();
        const unsigned length=old_size+maximum(old_size,n);
        T *new_start=storage.allocate(length);
        T *new_finish=copy(start,position,new_start);
        new_finish=fill(new_finish,n,value);
        storage.deallocate(start);
        start=new_start;
        storage.pointer=new_start+length;
        finish=new_finish;
    }
    void append(const T &value) {
        if(finish!=storage.pointer) {
            new(finish) T(value);
            ++finish;
        } else append_slow(finish,value,1);
    }
};
struct Owner { unsigned fields[5]; Vector<unsigned> words; };
typedef char VectorSize[(sizeof(Vector<unsigned>)==16)?1:-1];
}
extern "C" void sol35d10_append_word_801f7f1c(sol35d10_append_word::Owner *self,unsigned value) {
    self->words.append(value);
}
