// Inferred SGI-shaped vector reset. Original observes three pointers only.
// The empty allocator is the real constructor argument; no stored padding.
namespace Sol35d6ResetVectorV4 {
extern "C" void *sol35d6_copy_802eee50(void *,const void *,unsigned,...);
extern "C" void sol35d6_release_802134fc(void *);
struct Allocator {};
struct Trivial {};
template<class T> inline void destroy(T *,T *,Trivial) {}
template<class T> inline void swap(T &a,T &b) { T old=a; a=b; b=old; }
struct Vector {
    void **begin, **end, **capacity;
    Vector(const Allocator &a=Allocator()):begin(0),end(0),capacity(0) {}
    ~Vector() {
        destroy(begin,end,Trivial());
        if(begin) sol35d6_release_802134fc(begin);
    }
    void erase(void **first,void **last) {
        unsigned removed=(unsigned)last-(unsigned)first;
        sol35d6_copy_802eee50(first,last,(unsigned)end-(unsigned)last);
        destroy(first+(end-last),end,Trivial());
        end=(void **)((unsigned)end-removed);
    }
    void clear() { erase(begin,end); }
    void swap(Vector &other) {
        Sol35d6ResetVectorV4::swap(begin,other.begin);
        Sol35d6ResetVectorV4::swap(end,other.end);
        Sol35d6ResetVectorV4::swap(capacity,other.capacity);
    }
};
extern "C" Vector sol35d6_types_80365770[];
}
extern "C" int sol35d6_reset_vector_801e8128_v3() {
    using namespace Sol35d6ResetVectorV4;
    sol35d6_types_80365770[0].clear();
    Vector empty;
    sol35d6_types_80365770[0].swap(empty);
    return 0;
}
typedef char Sol35d6ResetVectorV4Size[sizeof(Sol35d6ResetVectorV4::Vector)==12?1:-1];
