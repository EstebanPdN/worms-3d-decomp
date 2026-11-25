
struct Object {void *vtable; unsigned char opaque[204];void *second;int a,b,c,d,e;int entries[3];int f,g,h;};
extern "C" int base_8015fef0(Object*);extern "C" void * member_802afb20(void*);
extern "C" unsigned char table_8041bb80[],table_8041bb30[];
extern "C" Object *w3d_cx12b_composite_construct_8025f1b8(Object *self) {
 base_8015fef0(self);member_802afb20((unsigned char*)self+28);self->second=table_8041bb30;self->vtable=table_8041bb80;self->e=0;
 int *p=self->entries;int n=3;do{*p++=0;}while(--n);
 self->f=0;self->g=0;self->a=0;self->b=0;self->c=0;self->h=0;self->d=0;return self;
}


