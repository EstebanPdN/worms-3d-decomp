
struct Range { int value,lower,upper; };
struct Object { void *vtable; unsigned char opaque[24]; int values[7]; int state; int opaque60; Range ranges[4]; };
extern "C" int base_801628b0(Object*);
extern "C" unsigned char table_8041baf0[];
extern "C" Object *w3d_cx12b_four_ranges_construct_8025d818(Object *self) {
 base_801628b0(self); self->vtable=table_8041baf0;
 self->values[0]=0;self->values[1]=0;self->values[2]=0;self->values[3]=0;self->values[4]=0;self->values[5]=0;self->values[6]=0;self->state=0;
 Range *p=self->ranges;int n=4;do {p->value=0;p->lower=23;p->upper=23;++p;}while(--n);return self;
}


