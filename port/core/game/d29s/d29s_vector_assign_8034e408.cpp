#include "w3d_ptr.h"
#line 1 "d29s_vector_assign_8034e408.cpp"
/* std::vector<T, ModuleAllocator<T> >::operator= from unmodified STLport 4.5.3.
 * T is a three-word record; the original copies it field by field. */
#include "compat/stlport_sn.h"
#include <vector>
#include "compat/module_allocator.h"

struct D29sRecord12_8034e408 { int a, b, c; };
typedef std::vector<D29sRecord12_8034e408, ModuleAllocator<D29sRecord12_8034e408> > D29sVector_8034e408;
template D29sVector_8034e408 &D29sVector_8034e408::operator=(const D29sVector_8034e408 &);


