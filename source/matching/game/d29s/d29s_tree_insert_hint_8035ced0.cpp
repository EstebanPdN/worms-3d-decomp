/* std::map<unsigned, void *> hinted insert (_Rb_tree::insert_unique(iterator, value))
 * from unmodified STLport 4.5.3. The node insert lives in its own unit. */
#include "compat/stlport_sn_oom.h"
#include <map>

typedef std::map<unsigned, void *>::_Rep_type D29sTree_8035ced0;
template <> D29sTree_8035ced0::iterator D29sTree_8035ced0::_M_insert(_STL::_Rb_tree_node_base *, _STL::_Rb_tree_node_base *, const D29sTree_8035ced0::value_type &, _STL::_Rb_tree_node_base *);
template D29sTree_8035ced0::iterator D29sTree_8035ced0::insert_unique(D29sTree_8035ced0::iterator, const D29sTree_8035ced0::value_type &);
