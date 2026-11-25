#include "w3d_ptr.h"
#line 1 "f1b_drain_list_service_8016636c.cpp"
// Partial PPC32 node and service views; list and object roles are inferred.
struct Node {Ptr32<Node> next; char unknown[36]; Ptr32<char> object;};
struct Iterator {Ptr32<Node> node; template <class W3dU> Iterator(Ptr32<W3dU> w3d_p) : Iterator((Node *)w3d_p.get()) {}
 Iterator(Node*n):node(n){}Iterator(const Iterator&o){node=o.node;} int operator!=(const Iterator&o)const{if(node==o.node)return 0;return 1;} Ptr32<Node> operator->()const{return node;}};
struct List {int unknown;Ptr32<Node> sentinel;Iterator begin(){return Iterator(sentinel->next);}Iterator end(){return Iterator(sentinel);}};
struct Service {Ptr32<Ptr32<void>> table;};
struct Owner {char unknown[20];Ptr32<Service> service;List list;};
inline Ptr32<char> adjust(Ptr32<char> p){return p?w3d::R(p+4):0;}
extern "C" int f1b_drain_list_service_8016636c(Ptr32<Owner> s){while(s->list.begin()!=s->list.end()){((Ptr32<void (Ptr32<Service>, Ptr32<char>, int)>)s->service->table[12])(s->service,adjust(s->list.begin()->object),0);}return 0;}


