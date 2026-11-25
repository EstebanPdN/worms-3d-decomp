/* Constructor of the four-vector record whose destructor is 0x8035a244
 * (session b169b320). STLport vectors here are 16 bytes: start, finish and
 * an allocator proxy holding end_of_storage. The default allocator
 * argument of vector() creates temporaries that only reserve stack space;
 * the allocator declares its constructors, as STLport's does. The vtable
 * pointer belongs to a polymorphic base. */

struct W3dAllocator
{
    W3dAllocator() {}
    W3dAllocator(const W3dAllocator &) {}
};
template <class T> struct W3dAllocProxy : W3dAllocator
{
    T *data;
    W3dAllocProxy(const W3dAllocator &, T *d) : data(d) {}
};
template <class T> struct W3dVector16
{
    T *start;
    T *finish;
    W3dAllocProxy<T> end_of_storage;
    W3dVector16(const W3dAllocator &a = W3dAllocator()) : start(0), finish(0), end_of_storage(a, 0) {}
};
class W3dTablesBase
{
public:
    virtual void unused_slot();
};
class W3dVec4TablesC : public W3dTablesBase
{
public:
    W3dVec4TablesC();
    W3dVector16<int> first;
    W3dVector16<int> second;
    W3dVector16<int> third;
    W3dVector16<int> fourth;
};
W3dVec4TablesC::W3dVec4TablesC()
{
}

