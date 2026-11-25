// Inferred SGI-shaped vector reset. Original observes three pointers only.
// The empty allocator is the real constructor argument; no stored padding.
namespace Sol35d6TypedResetVector {
extern "C" void *sol35d6_copy_802eee50(void *,const void *,unsigned,...);
extern "C" void sol35d6_release_802134fc(void *);
struct Type;
struct Allocator {};
struct Trivial {};
template<class T> inline void destroy(T *,T *,Trivial) {}
template<class T> inline void swap(T &a,T &b) { T old=a; a=b; b=old; }
struct Base {
    Type **begin, **end, **capacity;
    Base(const Allocator &):begin(0),end(0),capacity(0) {}
    ~Base() {
        if(begin) sol35d6_release_802134fc(begin);
    }
};
struct Vector : Base {
    Vector(const Allocator &a=Allocator()):Base(a) {}
    ~Vector() { destroy(begin,end,Trivial()); }
    void erase(Type **first,Type **last) {
        unsigned removed=(unsigned)last-(unsigned)first;
        sol35d6_copy_802eee50(first,last,(unsigned)end-(unsigned)last);
        destroy(first+(end-last),end,Trivial());
        end=(Type **)((unsigned)end-removed);
    }
    void clear() { erase(begin,end); }
    void swap(Vector &other) {
        Sol35d6TypedResetVector::swap(begin,other.begin);
        Sol35d6TypedResetVector::swap(end,other.end);
        Sol35d6TypedResetVector::swap(capacity,other.capacity);
    }
};
extern "C" Vector sol35d6_types_80365770[];
}
extern "C" int sol35d6_reset_vector_801e8128_v5() {
    using namespace Sol35d6TypedResetVector;
    sol35d6_types_80365770[0].clear();
    Vector().swap(sol35d6_types_80365770[0]);
    return 0;
}
typedef char Sol35d6TypedResetVectorSize[sizeof(Sol35d6TypedResetVector::Vector)==12?1:-1];
