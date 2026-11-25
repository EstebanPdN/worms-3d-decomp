// All names, types, layouts and roles are inferred. 
struct Node;extern "C" int fn_80162310(Node*);extern "C" char*allocate_80212fd4(unsigned);extern "C" void release_802134fc(void*);extern "C" void*copy_802eee50(...);
template<class T>inline const T&maximum(const T&a,const T&b){return a<b?b:a;}template<class T>inline const T&minimum(const T&a,const T&b){return b<a?b:a;}
struct Node{int word,id;unsigned short kind,pad;int value,state;};
struct Array{Node**begin,**end,**capacity;void push(Node*const&value){if(end==capacity){unsigned old=(char*)end-(char*)begin;int one=old+1,grow=old+(old>>1);unsigned bytes=maximum(one,grow)<<2;char*p=allocate_80212fd4(bytes);if(begin){copy_802eee50(p,begin,minimum(bytes,old));release_802134fc(begin);}begin=(Node**)p;end=(Node**)(p+old);capacity=(Node**)(p+bytes);}*end=value;end++;}};extern Array registry_80455244[];
extern "C" void f5b_register_node_80161570(Node*n){Array*r=&registry_80455244[0];fn_80162310(n);Node*value=n;r->push(value);n->id=-1;n->kind=0;n->value=0;n->state=1;}
