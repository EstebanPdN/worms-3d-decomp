#include "w3d_ptr.h"
#line 1 "f5c_find_index_80205738.cpp"
struct Node{Ptr32<Node> parent; Ptr32<Node> left; Ptr32<Node> right;int tag;int value;};extern "C" Ptr32<Node> fn_80351ef8(Ptr32<Node>);struct It{Ptr32<Node> p;template <class W3dU> It(Ptr32<W3dU> w3d_p) : It((Node *)w3d_p.get()) {}
 It(Node*q):p(q){}It(const It&o){p=o.p;}bool operator!=(const It&o)const{return p!=o.p;}It&operator++(){p=fn_80351ef8(p);return *this;}It operator++(int){It t=*this;p=fn_80351ef8(p);return t;}};struct Tree{int unused;Ptr32<Node> head;It begin(){return It(head->right);}It end(){return It(head);}};struct Owner{char unknown[44];Tree tree;};extern "C" unsigned short f5c_find_index_80205738(Ptr32<Owner> o,int key){unsigned short n=0;It p=o->tree.begin();It end=o->tree.end();for(;p!=end;++p){if(p.p->value==key)return n;++n;}return -1;}

