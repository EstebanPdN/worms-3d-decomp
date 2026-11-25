/* Standard-interface allocator over the engine's module heap pair 0x801907a8 and
 * 0x801907d0. The class itself is inferred: the original shows vectors allocating
 * through that pair with no zero check, not a name (d28r-allocator-review.md). */
#ifndef D29S_MODULE_ALLOCATOR_H
#define D29S_MODULE_ALLOCATOR_H
extern "C" void *w3d_auto_801907a8(unsigned);
extern "C" void w3d_auto_801907d0(void *);
template <class T> class ModuleAllocator {
public:
    typedef T value_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef unsigned size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef ModuleAllocator<U> other; };
    ModuleAllocator() {}
    ModuleAllocator(const ModuleAllocator &) {}
    template <class U> ModuleAllocator(const ModuleAllocator<U> &) {}
    ~ModuleAllocator() {}
    T *allocate(unsigned n, const void * = 0) const { return (T *)w3d_auto_801907a8(n * sizeof(T)); }
    void deallocate(T *p, unsigned) const { if (p) w3d_auto_801907d0(p); }
    void deallocate(T *p) const { if (p) w3d_auto_801907d0(p); }
    unsigned max_size() const { return unsigned(-1) / sizeof(T); }
};
#endif
