// Original entry 0x800b8f30; dimensions and corner-table meaning are inferred.
// The temporary handle includes the observed unused frame word.
struct Header {unsigned unused;unsigned short kind;char p[18];unsigned count;unsigned short refs;char pad[2];unsigned char bytes[1];};struct Array {Header *h;};
extern "C" unsigned char *fn_801ef048(Array*,unsigned,int,int);
inline unsigned char*write(Array*a,unsigned count){Header*h=a->h;if(h->kind==1&&count==h->count){++h->refs;return h->bytes;}return fn_801ef048(a,count,1,1);}
struct Body{void **vt;char p[436];Array grid;char q[13];unsigned char z,y,x;Array output;};struct Obj{void **vt;};struct Handle{Body*p;int reserved;Handle():p(0){}};
extern "C" {extern char lbl_8040e078[];void fn_800b3e20(void*,unsigned char*,unsigned,unsigned,unsigned);
int w3d_f2a_build_corner_table_800b8f30(Obj*self){Handle h;((int(*)(Obj*,const char*,int,Body**))self->vt[14])(self,lbl_8040e078,0,&h.p);unsigned x=h.p->x,y=h.p->y,z=h.p->z;unsigned length=(x+1)*(y+1)*(z+1);void *grid=h.p->grid.h->bytes;unsigned char*out=write(&h.p->output,length);fn_800b3e20(grid,out,x,y,z);if(h.p)((void(*)(Body*))h.p->vt[4])(h.p);return 0;}}
