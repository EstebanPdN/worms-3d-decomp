#include "w3d_ptr.h"
#line 1 "f2a_filter_grid_entries_800b2328.cpp"
// Original entry 0x800b2328; coordinate/grid names are inferred.
struct Header {unsigned unused;unsigned short kind;char p[18];unsigned count;unsigned short refs;char pad[2];unsigned char bytes[1];};struct Array {Ptr32<Header> h;};
extern "C" Ptr32<void> fn_801ef048(Ptr32<Array>,unsigned,int,int);
inline Ptr32<void> read(Ptr32<Array> a,unsigned count){Ptr32<Header> h=a->h;if(h->kind==1){++h->refs;return h->bytes;}return fn_801ef048(a,count,4,2);}
struct Entry {char p[56];unsigned coord;};struct Range {Ptr32<Ptr32<Entry>> begin; Ptr32<Ptr32<Entry>> end;unsigned size()const{return end-begin;}};struct Body {char p[440];Array array;};struct Obj {char p[4];Ptr32<Body> body;char q[12];Range list;};
extern "C" {int fn_8002c73c(Ptr32<void>,int,int,int,int);void fn_8006096c(Ptr32<Entry>);
void w3d_f2a_filter_grid_entries_800b2328(Ptr32<Obj> p){Ptr32<void> grid=read(&p->body->array,p->body->array.h->count);for(unsigned i=0;i<p->list.size();++i){Ptr32<Entry> e=*(Ptr32<Ptr32<Entry>>)((Ptr32<char>)p->list.begin+(i<<2));unsigned c=e->coord;if(!fn_8002c73c(grid,c&255,(c>>8)&255,(c>>16)&255,4))fn_8006096c(e);}}}


