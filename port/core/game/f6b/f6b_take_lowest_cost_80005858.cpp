#include "w3d_ptr.h"
#line 1 "f6b_take_lowest_cost_80005858.cpp"
// Inferred bucket, node, cost and index roles. Explicit countdown follows the prior report next hypothesis.
struct Node{char gap[8];short costA,pad,costB;};struct Bucket{Ptr32<Ptr32<Node>> begin; Ptr32<Ptr32<Node>> end;int capacity,pad;int size()const{return end-begin;}Ptr32<Node> at(int i)const{return *(Ptr32<Ptr32<Node>>)((Ptr32<char>)begin+(i<<2));}};struct Index{int bucket,index;};extern "C" void fn_8000553c(Ptr32<Bucket>,Ptr32<const Index>);
extern "C" Ptr32<Node> f6b_take_lowest_cost_80005858(Ptr32<Bucket> b,int first){Ptr32<Node> best=0;Index selected;int i=0,n=1024;Ptr32<Bucket> p=b;do{if(p->begin!=p->end){best=*p->begin;selected.bucket=i;selected.index=0;break;}p++;i++;}while(--n);if(best==0)return 0;if(first){for(int i=0;i<1024;i++){Ptr32<Bucket> p=(Ptr32<Bucket>)((Ptr32<char>)b+(i<<4));int count=p->size();for(int j=0;j<count;j++){Ptr32<Node> n=p->at(j);if(best->costA>n->costA){best=n;selected.bucket=i;selected.index=j;}}}}else{for(int i=0;i<1024;i++){Ptr32<Bucket> p=(Ptr32<Bucket>)((Ptr32<char>)b+(i<<4));int count=p->size();for(int j=0;j<count;j++){Ptr32<Node> n=p->at(j);if(best->costB>n->costB){best=n;selected.bucket=i;selected.index=j;}}}}fn_8000553c(b,&selected);return best;}


