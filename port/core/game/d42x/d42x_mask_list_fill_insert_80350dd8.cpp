#include "w3d_ptr.h"
#line 1 "d42x_mask_list_fill_insert_80350dd8.cpp"
// d42x: 0x80350dd8. vector<Mask>::_M_fill_insert from unmodified STLport
// 4.5.3 over the module allocator. Mask is a vector of words with its own
// copy constructor: resize to the source size, then copy element by element.
// Its operator= is 0x80350ca8 and the word vector's fill insert is
// 0x80350a78.
#include "compat/stlport_sn_oom.h"
#include <vector>
#include "compat/module_allocator.h"
typedef std::vector<int, ModuleAllocator<int> > D42xWords;
template <> void D42xWords::_M_fill_insert(Ptr32<int>, unsigned, const int &);
struct D42xMask : D42xWords {
    D42xMask(const D42xMask &o) {
        unsigned n = o.size();
        resize(n);
        for (unsigned i = 0; i < n; i++) (*this)[i] = o[i];
    }
    D42xMask &operator=(const D42xMask &);
};
typedef std::vector<D42xMask, ModuleAllocator<D42xMask> > D42xMasks;
template void D42xMasks::_M_fill_insert(Ptr32<D42xMask>, unsigned, const D42xMask &);


