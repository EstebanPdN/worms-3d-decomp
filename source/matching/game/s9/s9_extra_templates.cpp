/* Message, shared-owner cleanup and graphics-buffer callback layouts. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
struct S9Message {
    unsigned short code,unknown2;
    void *vtable;
    int version,selector;
    unsigned short field16,field18;
    unsigned char flag20;
    char unknown21[3];
    float x,y,z;
    S9Message(int id,float a,float b,float c);
    static void *operator new(unsigned int size);
};
extern char lbl_8040db38[];
inline S9Message::S9Message(int id,float a,float b,float c)
    : code(0x1004),vtable(lbl_8040db38),version(2),selector(id),field18(0),flag20(0),x(a),y(b),z(c)
{ field16=0; }

extern "C" void *fn_801613f0(int,int);
extern int lbl_804b1754;
inline void *S9Message::operator new(unsigned int size) { return fn_801613f0(lbl_804b1754,size); }
extern int lbl_803fe234[];
extern float lbl_803a4660[];
extern "C" void fn_8015fc84(void *,void *);
extern "C" void fn_802fa988(void *,unsigned int);
extern "C" void fn_80307d88(int,void *,int);
struct S9BufferHeader { char unknown0[24]; unsigned int count; unsigned short dirty; char unknown30[2]; char data[1]; void flush(unsigned int bytes) { if(dirty) { fn_802fa988(data,bytes);dirty=0; } } };
struct S9ReleaseInterface { void **vtable; void release() { ((void (*)(S9ReleaseInterface *))vtable[4])(this); } };
extern int lbl_804ab5d0;
extern S9ReleaseInterface *lbl_804b015c;
extern char lbl_80412450[];
extern "C" void fn_80178958(void *,int);

extern "C" void s9_dispatch_vector_message_80160780(void *self,int unused,int index)
{
    S9Message *message=new S9Message(lbl_803fe234[index],FIELD(self,float,32),FIELD(self,float,36),*lbl_803a4660);
    fn_8015fc84(self,message);
}
extern "C" int s9_bind_buffer_8016944c(void *self,void *argument)
{
    char *base=self ? (char *)self-4:0;
    S9BufferHeader *buffer=FIELD(argument,S9BufferHeader *,24);
    unsigned int count=buffer->count;
    char *data=buffer->data;
    if(count) {
        buffer->flush(count*16);
        fn_80307d88(9,data,16);
        int flags=FIELD(base,int,288);
        int issued=FIELD(base,int,284);
        FIELD(base,int,288)=flags|1;
        FIELD(base,int,284)=issued+1;
    }
    return 0;
}
extern "C" void s9_destroy_shared_owner_8017922c(void *self,int flags)
{
    int remaining=lbl_804ab5d0-1;
    *(void **)self=lbl_80412450;
    lbl_804ab5d0=remaining;
    if(!remaining) {
        if(lbl_804b015c)lbl_804b015c->release();
        lbl_804b015c=(S9ReleaseInterface *)remaining;
    }
    fn_80178958(self,flags);
}
