#include "w3d_ptr.h"
#line 1 "f16b_destroy_nested_vectors_801908bc.cpp"
// Inferred owner/container views: factory80190680 allocates80B; ctor80190800 writes through79.
// Nested vector strides and member cleanup come from original destructor801908bc.
// No local construction or allocation; hidden fields and original identities are unknown.
extern "C" void fn_801907d0(Ptr32<void>);extern "C" void fn_8020c5c4(Ptr32<void>);extern "C" void fn_80341588(Ptr32<void>);extern "C" void fn_80197ce4(Ptr32<void>,int);extern "C" void fn_80210990(Ptr32<void>,int);extern "C" Ptr32<void> fn_803439d8();extern "C" void fn_80198710(Ptr32<void>,Ptr32<void>);extern "C" void fn_80197f98(Ptr32<void>,Ptr32<void>);
extern Ptr32<void> vt_804132e0[]; extern Ptr32<void> vt_80413338[];
struct F16bText{unsigned text,unknown;~F16bText(){fn_8020c5c4(this);fn_80341588(this);}};
struct F16bPod3{unsigned words[3];~F16bPod3(){}};
struct F16bBuffer76{unsigned words[19];~F16bBuffer76(){fn_80197ce4(this,2);}};
struct F16bRecord84{F16bText text;F16bBuffer76 buffer;~F16bRecord84(){}};
template<class T>struct F16bVector{Ptr32<T> begin; Ptr32<T> end; Ptr32<T> capacity;unsigned unknown;unsigned size()const{return end-begin;}~F16bVector(){Ptr32<T> last=end;for(Ptr32<T> p=begin;p!=last;++p)p->~T();if(begin)fn_801907d0(begin);}};
struct F16bBase492{Ptr32<Ptr32<void>> table;unsigned node[4];~F16bBase492(){table=vt_80413338;fn_80210990(node,0);}};
struct F16bOwner492:F16bBase492{F16bVector<F16bText>text __attribute__((aligned(__alignof__(F16bBase492))));F16bVector<F16bRecord84>records;F16bVector<F16bVector<F16bPod3> >buffers;F16bText name;unsigned unknown76;~F16bOwner492();static void operator delete(void*);};
F16bOwner492::~F16bOwner492(){table=vt_804132e0;fn_80198710(fn_803439d8(),this);for(unsigned i=0;i<records.size();++i)fn_80197f98(&records.begin[i].buffer,&buffers.begin[i]);}


