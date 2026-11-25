/* Inferred names; observed offsets and integer widths retained. */
typedef unsigned int u32;
typedef unsigned short u16;
struct BufferUnit { unsigned char bytes[24]; };
struct BufferRequest { u32 words[6];
 void clear() {words[0]=0;words[1]=0;words[4]=~0u;words[2]=0;words[3]=0;words[5]=0;}
};
struct BufferManager {
    BufferUnit *base;
    u16 units;
    u16 records;
    u32 state;
    BufferRequest request;
    u32 unknown24to40[8];
    u32 flags;
};
struct SpanCount { u16 value; SpanCount(u16 n):value(n) {} operator u32() const { return value; } };
struct BufferSpan { BufferUnit *data; u16 units; u16 tail;
 SpanCount count() const { return SpanCount(units); }
 void set(BufferUnit *p,u32 n) { data=p;units=n; }
};
struct Record { u32 unknown; BufferSpan span; BufferSpan *get() { return &span; } };
struct RecordTable { Record *base; Record *at(u32 i) { return base+i; } };
extern "C" {
extern void *buffer_shared_cell();
extern void *buffer_owner_allocate(void *, u32);
extern void *buffer_owner_release(void *);
extern void buffer_storage_release(void *, void *);
extern int buffer_request_state(void *);
extern u32 buffer_external;
extern void *buffer_request_service();
extern void buffer_request_write(void *, void *, u32, void *);
extern void buffer_request_read(void *, void *, void *, u32);
extern u32 buffer_storage_available(void *);
extern BufferUnit *buffer_storage_allocate(void *,u32);
extern void buffer_error(const char *, ...);
extern const char buffer_error_text[];

u32 w3d_r24a_read_rebind_8019805c(BufferManager *m, RecordTable *records)
{
    if(buffer_request_state(&m->request)==2) {
        u32 n=(m->units*24+31)&~31u;
        if(buffer_storage_available(buffer_shared_cell()) < n) {
            buffer_error(buffer_error_text);
            return 0;
        }
        m->base=buffer_storage_allocate(buffer_shared_cell(),n);
        buffer_request_read(buffer_request_service(),&m->request,m->base,n);
        while(buffer_request_state(&m->request)!=3) {}
        BufferUnit *p=m->base;
        for(u32 i=0;i<m->records;i++) {
            u32 count=records->at(i)->get()->count();
            records->at(i)->get()->set(p,count);
            p+=count;
        }
    }
    return 1;
}
}
