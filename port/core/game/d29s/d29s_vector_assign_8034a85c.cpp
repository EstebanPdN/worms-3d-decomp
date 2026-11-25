#include "w3d_ptr.h"
#line 1 "d29s_vector_assign_8034a85c.cpp"
/* std::vector<T>::operator= from unmodified STLport 4.5.3 with the stock malloc allocator; T is an 8-byte record. */
#include "compat/stlport_sn_oom.h"
#include <vector>

struct D29sRecord8_8034a85c { int a, b; };
typedef std::vector<D29sRecord8_8034a85c> D29sVector_8034a85c;
template D29sVector_8034a85c &D29sVector_8034a85c::operator=(const D29sVector_8034a85c &);


