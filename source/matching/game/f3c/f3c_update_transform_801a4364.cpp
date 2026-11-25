// Structural names, math representations, and partial layouts inferred from original instructions.
struct Vec3 {float x,y,z;inline void init(float f){x=f;y=f;z=f;}};
struct Matrix {float values[9];Vec3 pos;};
struct Tag {unsigned short a,b;unsigned char word[4];inline int dirty(){return word[3]&2;}inline void clear(){word[3]&=253;}};
struct Node {void *vtable;Tag tag;unsigned pad[2];Matrix transform;Vec3 angles,extra,position;unsigned mode;Vec3 scale,pivot;};
struct Service {unsigned pad[6];char *table;};
struct Global{unsigned pad[8];unsigned selector;};
extern Global *lbl_80363938[];
extern const float lbl_803a9c1c[];
extern "C" void fn_801a3eb0(void *,unsigned,Matrix *);
extern "C" void fn_801f7854(Matrix *,float,float,float);
extern "C" void fn_801f77f4(Matrix *,float,float,float);
extern "C" void fn_801f6298(Matrix *,float,float,float);
inline void update(Matrix *temp,Node *self,float zero){temp->pos.init(zero);
fn_801a3eb0((char *)self+84,*(unsigned *)((char *)self+108),temp);
Vec3 *pivot=(Vec3 *)((char *)self+124);fn_801f7854(temp,-pivot->x,-pivot->y,-pivot->z);fn_801f77f4(temp,pivot->x,pivot->y,pivot->z);
Vec3 *angles=(Vec3 *)((char *)self+72);fn_801f6298(temp,angles->x,angles->y,angles->z);
Vec3 *pos=(Vec3 *)((char *)self+96);fn_801f77f4(temp,pos->x,pos->y,pos->z);
*(Matrix *)((char *)self+20)=*temp;}
extern "C" void f3c_update_transform_801a4364(Service *service,Node *self){Tag *tag=&self->tag;if(tag->dirty()){tag->word[3]&=253;float zero=lbl_803a9c1c[0];Matrix temp;update(&temp,self,zero);
}
unsigned offset=(lbl_80363938[0]->selector>>20)&0xffc;(*(void (**)(Service *,Node *))(offset+(unsigned)service->table))(service,self);}