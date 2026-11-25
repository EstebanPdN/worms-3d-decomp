/* std::map<unsigned, int> hinted insert (_Rb_tree::insert_unique(iterator, value))
 * from unmodified STLport 4.5.3. The node insert lives in its own unit. */
#include "compat/stlport_sn_oom.h"
#include <map>

typedef std::map<unsigned, int>::_Rep_type D29sTree_803531e8;
template <> D29sTree_803531e8::iterator D29sTree_803531e8::_M_insert(_STL::_Rb_tree_node_base *, _STL::_Rb_tree_node_base *, const D29sTree_803531e8::value_type &, _STL::_Rb_tree_node_base *);
template D29sTree_803531e8::iterator D29sTree_803531e8::insert_unique(D29sTree_803531e8::iterator, const D29sTree_803531e8::value_type &);
