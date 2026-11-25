
// Message-like layout: ushort identifier +0, vtable +4; four payload helpers.
struct Cx7aMessage {unsigned short id,padding;void *vtable;};
extern unsigned char vtable_8040db38[];
extern "C" int set_800a4f44(Cx7aMessage *,int);
extern "C" int set_800a4f54(Cx7aMessage *,int);
extern "C" int set_800a4f64(Cx7aMessage *,int);
extern "C" void set_800a4f74(Cx7aMessage *,int);
extern "C" Cx7aMessage *w3d_cx7a_message_construct_800a4ed0(Cx7aMessage *self,unsigned short id,int a,int b,int c,int d) {self->id=id;self->vtable=vtable_8040db38;set_800a4f44(self,a);set_800a4f54(self,b);set_800a4f64(self,c);set_800a4f74(self,d);return self;}
