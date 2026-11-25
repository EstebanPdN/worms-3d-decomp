// Original entry 0x800b2328; coordinate/grid names are inferred.
struct Header {unsigned unused;unsigned short kind;char p[18];unsigned count;unsigned short refs;char pad[2];unsigned char bytes[1];};struct Array {Header *h;};
extern "C" void *fn_801ef048(Array*,unsigned,int,int);
inline void *read(Array*a,unsigned count){Header*h=a->h;if(h->kind==1){++h->refs;return h->bytes;}return fn_801ef048(a,count,4,2);}
struct Entry {char p[56];unsigned coord;};struct Range {Entry **begin,**end;unsigned size()const{return end-begin;}};struct Body {char p[440];Array array;};struct Obj {char p[4];Body *body;char q[12];Range list;};
extern "C" {int fn_8002c73c(void*,int,int,int,int);void fn_8006096c(Entry*);
void w3d_f2a_filter_grid_entries_800b2328(Obj *p){void *grid=read(&p->body->array,p->body->array.h->count);for(unsigned i=0;i<p->list.size();++i){Entry*e=*(Entry**)((char*)p->list.begin+(i<<2));unsigned c=e->coord;if(!fn_8002c73c(grid,c&255,(c>>8)&255,(c>>16)&255,4))fn_8006096c(e);}}}
