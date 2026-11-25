#include "w3d_ptr.h"
#line 1 "f6a_destroy_console_8028e02c.cpp"
/* Iterator and deque names are inferred from the four-word positions and
 * the original base-destruction call. The empty range helpers describe the
 * observed trivial element cleanup; they still copy iterators by value. */
struct F6aIterator {
    unsigned current, first, last, node;
    F6aIterator(const F6aIterator &other) {
        unsigned a = other.current, b = other.first;
        unsigned c = other.last, d = other.node;
        current = a;
        first = b;
        last = c;
        node = d;
    }
};
struct F6aDeque {
    F6aIterator begin, end;
    F6aIterator first() { return begin; }
    F6aIterator last() { return end; }
};
inline void f6a_finish(F6aIterator first, F6aIterator last) {}
inline void f6a_dispatch(F6aIterator first, F6aIterator last) {
    f6a_finish(first, last);
}
inline void f6a_destroy_range(F6aIterator first, F6aIterator last) {
    f6a_dispatch(first, last);
}
extern "C" void fn_8035edbc(Ptr32<void>,int),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>),fn_800c45b8(Ptr32<void>,int),fn_801628ec(Ptr32<void>,int);
struct Deque:F6aDeque{Deque();char unknown[16] __attribute__((aligned(__alignof__(F6aDeque))));~Deque(){f6a_destroy_range(first(),last());fn_8035edbc(this,2);}};
struct Text{Ptr32<char> text;~Text(){fn_8020c5c4(this);fn_80341588(this);}};
struct Names{char unknown[20];};
struct Owner{Owner();char base[28];Ptr32<void> handles[8];int unknown60,unknown64,unknown68;Names names,history;Text name,previous;Deque deque;};
extern char vt_8041c1b0[];
extern "C" void w3d_f6a_destroy_console_8028e02c(Ptr32<Owner> self,int flags){
 *(Ptr32<Ptr32<void>>)self=vt_8041c1b0;self->deque.~Deque();self->previous.~Text();self->name.~Text();
 fn_800c45b8(&self->history,2);fn_800c45b8(&self->names,2);
 if(self->handles[7])(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)self->handles[7])[4](self->handles[7]);
 if(self->handles[6])(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)self->handles[6])[4](self->handles[6]);
 if(self->handles[5])(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)self->handles[5])[4](self->handles[5]);
 if(self->handles[4])(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)self->handles[4])[4](self->handles[4]);
 if(self->handles[3])(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)self->handles[3])[4](self->handles[3]);
 if(self->handles[2])(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)self->handles[2])[4](self->handles[2]);
 if(self->handles[1])(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)self->handles[1])[4](self->handles[1]);
 if(self->handles[0])(*(Ptr32<Ptr32<Ptr32<void (Ptr32<void>)>>>)self->handles[0])[4](self->handles[0]);
 fn_801628ec(self,flags);
}


