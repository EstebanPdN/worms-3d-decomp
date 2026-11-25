/* Standard-interface allocator over the engine's module heap pair 0x801907a8 and
 * 0x801907d0. The class itself is inferred: the original shows vectors allocating
 * through that pair with no zero check, not a name (d28r-allocator-review.md). */
#ifndef D29S_MODULE_ALLOCATOR_H
#define D29S_MODULE_ALLOCATOR_H
extern "C" Ptr32<void> w3d_auto_801907a8(unsigned);
extern "C" void w3d_auto_801907d0(Ptr32<void>);
template <class T> class ModuleAllocator {
public:
    typedef T value_type;
    typedef Ptr32<T> pointer;
    typedef Ptr32<const T> const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef unsigned size_type;
    typedef int difference_type;
    template <class U> struct rebind { typedef ModuleAllocator<U> other;  char w3d_empty; };
    ModuleAllocator() {}
    ModuleAllocator(const ModuleAllocator &) {}
    template <class U> ModuleAllocator(const ModuleAllocator<U> &) {}
    ~ModuleAllocator() {}
    Ptr32<T> allocate(unsigned n, Ptr32<const void> = 0) const { return (Ptr32<T>)w3d_auto_801907a8(n * sizeof(T)); }
    void deallocate(Ptr32<T> p, unsigned) const { if (p) w3d_auto_801907d0(p); }
    void deallocate(Ptr32<T> p) const { if (p) w3d_auto_801907d0(p); }
    unsigned max_size() const { return unsigned(-1) / sizeof(T); }
 char w3d_empty; };
#endif
