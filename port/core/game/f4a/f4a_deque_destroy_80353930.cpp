#include "w3d_ptr.h"
#line 1 "f4a_deque_destroy_80353930.cpp"
/* Iterator and deque names are inferred from the four-word positions and
 * the original base-destruction call. The empty range helpers describe the
 * observed trivial element cleanup; they still copy iterators by value. */
struct F4aIterator {
    unsigned current, first, last, node;
    F4aIterator(const F4aIterator &other) {
        unsigned a = other.current, b = other.first;
        unsigned c = other.last, d = other.node;
        current = a;
        first = b;
        last = c;
        node = d;
    }
};
struct F4aDeque {
    F4aIterator begin, end;
    F4aIterator first() { return begin; }
    F4aIterator last() { return end; }
};
inline void f4a_finish(F4aIterator first, F4aIterator last) {}
inline void f4a_dispatch(F4aIterator first, F4aIterator last) {
    f4a_finish(first, last);
}
inline void f4a_destroy_range(F4aIterator first, F4aIterator last) {
    f4a_dispatch(first, last);
}
extern "C" void fn_80353604(Ptr32<F4aDeque>, int);
extern "C" void fn_801fe1f8(Ptr32<void>);
extern "C" void w3d_f4a_deque_destroy_80353930(Ptr32<F4aDeque> self, unsigned flags) {
    f4a_destroy_range(self->first(), self->last());
    fn_80353604(self, 2);
    if (flags & 1) fn_801fe1f8(self);
}


