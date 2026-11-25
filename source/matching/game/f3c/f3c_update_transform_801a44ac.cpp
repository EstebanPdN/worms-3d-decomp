// Structural names, math representations, and partial layouts inferred from original instructions.
struct Matrix {float v[10];};
struct Vec3 {float x,y,z;inline void assign(const Vec3 &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}};
struct Tag {unsigned short a,b;unsigned char word[4];};
struct Node {void *vtable;Tag tag;unsigned pad[2];Matrix transform;Vec3 pad2,angles,pad3,position;unsigned mode;Vec3 scale,pivot;};
struct Service {unsigned pad[6];char *table;};
struct Global{unsigned pad[8];unsigned selector;};
extern Global *lbl_80363938[];
extern "C" void fn_801a3eb0(void *,unsigned,Matrix *);
extern "C" void fn_801f606c(Matrix *,const Matrix *,const Matrix *);
extern "C" void fn_801f6448(Matrix *,float,float,float);
extern "C" void f3c_update_transform_801a44ac(Service *service,Node *self){Tag *tag=&self->tag;if(tag->word[3]&2){tag->word[3]&=253;
Matrix a,b,c,d;
fn_801a3eb0((char *)self+84,*(unsigned *)((char *)self+108),&a);
fn_801a3eb0((char *)self+124,0,&b);
fn_801a3eb0((char *)self+112,0,&c);
fn_801f606c(&d,&b,&a);Matrix *out=(Matrix *)((char *)self+20);fn_801f606c(out,&d,&c);
Vec3 *angles=(Vec3 *)((char *)self+72);fn_801f6448(out,angles->x,angles->y,angles->z);
((Vec3 *)((char *)self+56))->assign(*(Vec3 *)((char *)self+96));
}
unsigned offset=(lbl_80363938[0]->selector>>20)&0xffc;(*(void (**)(Service *,Node *))(offset+(unsigned)service->table))(service,self);}