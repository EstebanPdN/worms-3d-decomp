#include "w3d_ptr.h"
#line 1 "f5b_register_node_80161570.cpp"
// All names, types, layouts and roles are inferred. 
struct Node;extern "C" int fn_80162310(Ptr32<Node>);extern "C" Ptr32<char> allocate_80212fd4(unsigned);extern "C" void release_802134fc(Ptr32<void>);extern "C" Ptr32<void> copy_802eee50(...);
template<class T>inline const T&maximum(const T&a,const T&b){return a<b?b:a;}template<class T>inline const T&minimum(const T&a,const T&b){return b<a?b:a;}
struct Node{int word,id;unsigned short kind,pad;int value,state;};
struct Array{Ptr32<Ptr32<Node>> begin; Ptr32<Ptr32<Node>> end; Ptr32<Ptr32<Node>> capacity;void push(Ptr32<Node> const &value){if(end==capacity){unsigned old=(Ptr32<char>)end-(Ptr32<char>)begin;int one=old+1,grow=old+(old>>1);unsigned bytes=maximum(one,grow)<<2;Ptr32<char> p=allocate_80212fd4(bytes);if(begin){copy_802eee50(w3d::VA(p),w3d::VA(begin),minimum(bytes,old));release_802134fc(begin);}begin=(Ptr32<Ptr32<Node>>)p;end=(Ptr32<Ptr32<Node>>)(p+old);capacity=(Ptr32<Ptr32<Node>>)(p+bytes);}*end=value;end++;}};extern Array registry_80455244[];
extern "C" void f5b_register_node_80161570(Ptr32<Node> n){Ptr32<Array> r=&registry_80455244[0];fn_80162310(n);Ptr32<Node> value=n;r->push(value);n->id=-1;n->kind=0;n->value=0;n->state=1;}


