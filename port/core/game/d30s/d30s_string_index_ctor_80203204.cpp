#include "w3d_ptr.h"
#line 1 "d30s_string_index_ctor_80203204.cpp"
/* GWMP8P rev0 0x80203204. Constructs a string index: a real STLport 4.5.3 map at +0 holding the
 * empty string at index 0, next index 1. The three-argument construct-at-address stands in for a
 * member constructor without the null check. */
#include "compat/stlport_sn_oom.h"
#include <map>
#include <string.h>
extern "C" void w3d_string_base_init(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<const void>);
extern "C" void w3d_string_base_finish(Ptr32<void>);
extern "C" void w3d_string_release(Ptr32<void>);
struct D30sStr {
    Ptr32<char> text;
    D30sStr(const D30sStr &o) { w3d_string_base_init(this); text = o.text; ++*w3d_string_header(this); }
    ~D30sStr() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct D30sStrLessFn : std::binary_function<D30sStr, D30sStr, bool> { bool operator()(const D30sStr &a, const D30sStr &b) const { return strcmp(a.text, b.text) < 0; } };
typedef std::map<D30sStr, int, D30sStrLessFn> D30sStringIndex;
typedef D30sStringIndex::_Rep_type D30sStringTree;
template <> D30sStringTree::iterator D30sStringTree::insert_unique(D30sStringTree::iterator, const D30sStringTree::value_type &);
template <> void D30sStringTree::_M_erase(Ptr32<_STL::_Rb_tree_node < D30sStringTree::value_type >>);
struct D30sStringOwner { D30sStringIndex m; int count; };
inline void *operator new(__SIZE_TYPE__, void *p, int) { return p; }
extern D30sStr d30s_empty_string_804b06a0[];
extern "C" Ptr32<D30sStringOwner> d30s_string_index_ctor_80203204(Ptr32<D30sStringOwner> self) {
    new (&self->m, 0) D30sStringIndex;
    const D30sStr &key = d30s_empty_string_804b06a0[0];
    self->m[key] = 0;
    self->count = 1;
    return self;
}


