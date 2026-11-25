#include "w3d_ptr.h"
#line 1 "h1_stlport_vec4_tables_ctor.cpp"
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
 char w3d_empty; };
template <class T> struct W3dAllocProxy : W3dAllocator
{
    Ptr32<T> data __attribute__((aligned(__alignof__(W3dAllocator))));
    W3dAllocProxy(const W3dAllocator &, Ptr32<T> d) : data(d) {}
};
template <class T> struct W3dVector16
{
    Ptr32<T> start;
    Ptr32<T> finish;
    W3dAllocProxy<T> end_of_storage;
    W3dVector16(const W3dAllocator &a = W3dAllocator()) : start(0), finish(0), end_of_storage(a, 0) {}
};
class W3dTablesBase
{
public:
    void w3d_r_unused_slot() __asm__(W3D_SYM("_ZN13W3dTablesBase11unused_slotEv"));
 __attribute__((always_inline)) inline void unused_slot() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_W3dTablesBase, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_W3dTablesBase;  W3dTablesBase() { W3D_SET_VPTR(this->w3d_vptr_W3dTablesBase, w3d_vt___vt_13W3dTablesBase, "__vt_13W3dTablesBase"); } };
class W3dVec4TablesC : public W3dTablesBase
{
public:
    W3dVec4TablesC();
    W3dVector16<int> first __attribute__((aligned(__alignof__(W3dTablesBase))));
    W3dVector16<int> second;
    W3dVector16<int> third;
    W3dVector16<int> fourth;
};
W3dVec4TablesC::W3dVec4TablesC()
{ W3D_SET_VPTR(this->W3dTablesBase::w3d_vptr_W3dTablesBase, w3d_vt___vt_14W3dVec4TablesC, "__vt_14W3dVec4TablesC"); 
}



