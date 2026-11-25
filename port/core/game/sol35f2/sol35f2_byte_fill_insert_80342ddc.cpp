#include "w3d_ptr.h"
#line 1 "sol35f2_byte_fill_insert_80342ddc.cpp"
// GWMP8P rev0 [0x80342ddc,0x80342fa4): byte-vector fill insertion.
// The complete insertion body is emitted here rather than inlined through a
// wrapper. This gives the observed x-copy / old-size / count slots at 8/12/16.
// POD copy/fill dispatch and allocator-proxy lifetimes are source-form/compiler
// evidence; the original STL identity and container semantic names are unproved.
// Observed GC32 layout: start +0, finish +4, allocator +8, storage end +12.
// Valid same-array bounds and sufficient allocated extents are assumed. The
// null-empty pointer-subtraction idiom is not a portable ISO C++ guarantee.
// No whole-game, host behavior, ARM build, or hardware claim is made.
// Inferred trivial-element counterpart of the proven mx25oc insertion template.
// GC32 allocator-proxy and algorithm lifetimes are hypotheses, not STL identity.
extern "C" Ptr32<void> sol35f2_allocate_8001528c(unsigned);
extern "C" void sol35f2_free_800152ac(Ptr32<void>);
extern "C" Ptr32<void> sol35f2_move_802eeef4(Ptr32<void>,Ptr32<const void>,unsigned);
template<class T> struct Allocator {
    Allocator() {}
    Allocator(const Allocator &) {}
    Ptr32<T> allocate(unsigned n) {return (Ptr32<T>)sol35f2_allocate_8001528c(n*sizeof(T));}
    void deallocate(Ptr32<T> p,unsigned) {if(p)sol35f2_free_800152ac(p);}
 char w3d_empty; };
template<class T> struct StorageEnd : Allocator<T> {Ptr32<T> data __attribute__((aligned(__alignof__(Allocator<T>))));};
struct Trivial { char w3d_empty; };
template<class T> inline const T &maximum(const T &a,const T &b) {return a<b?b:a;}
template<class T> inline Ptr32<T> copy_words(const T *first,const T *last,T *out) {
    if(last!=first) {
        unsigned bytes=(Ptr32<const char>)last-(Ptr32<const char>)first;
        return (Ptr32<T>)((Ptr32<char>)sol35f2_move_802eeef4(out,first,bytes)+bytes);
    }
    return out;
}
template<class T> inline Ptr32<T> copy_aux(const T *first,const T *last,T *out,const Trivial &) {return copy_words(w3d::R(first),w3d::R(last),w3d::R(out));}
template<class T> inline Ptr32<T> copy(const T *first,const T *last,T *out) {return copy_aux(w3d::R(first),w3d::R(last),w3d::R(out),Trivial());}
extern "C" Ptr32<void> sol35f2_fill_802eefe0(Ptr32<void>,int,unsigned);
template<class T> inline Ptr32<T> fill_words(T *out,unsigned n,const T &x) {Ptr32<T> last=out+n;sol35f2_fill_802eefe0(out,x,last-out);return last;}
template<class T> inline Ptr32<T> fill_aux(T *out,unsigned n,const T &x,const Trivial &) {return fill_words(w3d::R(out),n,x);}
template<class T> inline Ptr32<T> fill_n(T *out,unsigned n,const T &x) {return fill_aux(w3d::R(out),n,x,Trivial());}
template<class T> inline void fill(T *first,T *last,const T &x) {sol35f2_fill_802eefe0(first,x,last-first);}
template<class T> inline Ptr32<T> copy_backward(const T *first,const T *last,T *out) {
    int bytes=(Ptr32<const char>)last-(Ptr32<const char>)first;
    if(bytes>0)sol35f2_move_802eeef4((Ptr32<char>)out-bytes,first,bytes);
    return (Ptr32<T>)((Ptr32<char>)out-bytes);
}
template<class T> inline void destroy_aux(T *,T *,const Trivial &) {}
template<class T> inline void destroy(T *first,T *last) {destroy_aux(w3d::R(first),w3d::R(last),Trivial());}
template<class T> struct Vector {
    Ptr32<T> start; Ptr32<T> finish;
    StorageEnd<T> storage_end;
    unsigned size() const {return finish-start;}
    void clear_storage() {destroy(w3d::R(start),w3d::R(finish));storage_end.deallocate(start,storage_end.data-start);}
    void set(Ptr32<T> s,Ptr32<T> f,Ptr32<T> e) {start=s;finish=f;storage_end.data=e;}
    void insert_overflow(Ptr32<T> pos,const T &x,unsigned n) {
        const unsigned old_size=size();
        const unsigned length=old_size+maximum(old_size,n);
        Ptr32<T> new_start=storage_end.allocate(length);
        Ptr32<T> new_finish=copy(w3d::R((Ptr32<const T>)start),w3d::R((Ptr32<const T>)pos),w3d::R(new_start));
        new_finish=fill_n(w3d::R(new_finish),n,x);
        new_finish=copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)finish),w3d::R(new_finish));
        clear_storage();
        set(new_start,new_finish,new_start+length);
    }

};
typedef unsigned char Value;
typedef Vector<Value> ByteVector;
typedef char VectorFootprint[sizeof(ByteVector)==16?1:-1];
typedef char ByteFootprint[sizeof(Value)==1?1:-1];
extern "C" void sol35f2_byte_fill_insert_80342ddc(Ptr32<ByteVector> self,Ptr32<Value> pos,unsigned n,const Value &x) {
    typedef Value T;
        if(n) {
            if(unsigned(self->storage_end.data-self->finish)>=n) {
                T x_copy=x;
                const unsigned after=self->finish-pos;
                Ptr32<T> old_finish=self->finish;
                if(after>n) {
                    copy(w3d::R((Ptr32<const T>)(self->finish-n)),w3d::R((Ptr32<const T>)self->finish),w3d::R(self->finish));
                    self->finish+=n;
                    copy_backward(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)(old_finish-n)),w3d::R(old_finish));
                    fill(w3d::R(pos),w3d::R(pos+n),x_copy);
                } else {
                    fill_n(w3d::R(self->finish),n-after,x_copy);
                    self->finish+=n-after;
                    copy(w3d::R((Ptr32<const T>)pos),w3d::R((Ptr32<const T>)old_finish),w3d::R(self->finish));
                    self->finish+=after;
                    fill(w3d::R(pos),w3d::R(old_finish),x_copy);
                }
            } else self->insert_overflow(pos,x,n);
        }
    
}


