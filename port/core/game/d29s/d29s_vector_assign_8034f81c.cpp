#include "w3d_ptr.h"
#line 1 "d29s_vector_assign_8034f81c.cpp"
/* std::vector<T, ModuleAllocator<T> >::operator= from unmodified STLport 4.5.3; T is a one-word record, copied without memmove. */
#include "compat/stlport_sn.h"
#include <vector>
#include "compat/module_allocator.h"

struct D29sRecord4_8034f81c { int word; };
typedef std::vector<D29sRecord4_8034f81c, ModuleAllocator<D29sRecord4_8034f81c> > D29sVector_8034f81c;
template D29sVector_8034f81c &D29sVector_8034f81c::operator=(const D29sVector_8034f81c &);


