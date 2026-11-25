#include "w3d_ptr.h"
#line 1 "cx11b_name_registry_index_80207c0c.cpp"
// Observed far globals: count at +20 of registry base, pointer slots at a separate original address.
struct Registry {unsigned char opaque[20];unsigned int count;};
extern Registry registry_8045ee54[];
extern unsigned int count_8045ee68[];
extern Ptr32<const char> names_8045ee78[];
extern "C" int compare_802ef234(Ptr32<const char>,Ptr32<const char>);
extern "C" unsigned short w3d_cx11b_name_registry_index_80207c0c(Ptr32<const char> name) {
 unsigned int count=count_8045ee68[0],i=0;if(i<count){Ptr32<Ptr32<const char>> p=names_8045ee78;do {if(compare_802ef234(*p++,name)==0)return i;++i;}while(i<count);}
 names_8045ee78[count]=name;++registry_8045ee54[0].count;return count;
}




