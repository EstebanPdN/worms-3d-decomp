
struct Owner{void*vtable;unsigned char opaque[204];void*second;int a,b,c;void*children[3];int d,e,f,g,h,i,j;};extern "C" int base_8015fef0(Owner*);extern "C" void * member_802afb20(void*);extern "C" unsigned char table_8041c700[],table_8041c6b0[];
extern "C" Owner*w3d_cx12b_three_child_view_construct_802b4030(Owner*self){base_8015fef0(self);member_802afb20((unsigned char*)self+28);self->second=table_8041c6b0;self->vtable=table_8041c700;void**p=self->children;int n=3;do{*p++=0;}while(--n);self->d=0;self->e=0;self->g=0;self->h=0;self->i=0;self->j=0;self->a=0;self->b=0;self->c=0;self->f=0;return self;}

