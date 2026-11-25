
// PPC32: owner slot +32 returns pointer array and writes count; child slot +24 accepts zero.
struct Interface{void**table;};
extern "C" int w3d_cx14b_child_callbacks_apply_801fc5f4(Interface*self){unsigned count;int result=0;unsigned i=0;Interface**returned=((Interface**(*)(Interface*,unsigned*))self->table[8])(self,&count);if(i<count){Interface**items=returned;do{Interface*p=*items++;if(p){int r=((int(*)(Interface*,int))p->table[6])(p,0);if(r<0)result=r;}++i;}while(i<count);}return result;}


