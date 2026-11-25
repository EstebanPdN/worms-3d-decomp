#include "w3d_ptr.h"
#line 1 "native_buffer_submission.cpp"
/* Two complete reference-ABI bodies. Names, source class identity and ownership
 * inferred; no whole-path or runtime equivalence claim. Integer address arithmetic
 * intentionally models the original 32-bit target; not a portable host API. */
struct TemporaryOwner;
namespace w3d_native_buffer_submission_detail {
typedef unsigned int u32;
typedef unsigned short u16;
struct BufferUnit { unsigned char bytes[24]; };
struct BufferRequest { u32 words[6];
 void clear() {words[0]=0;words[1]=0;words[4]=~0u;words[2]=0;words[3]=0;words[5]=0;}
};
struct BufferManager {
    Ptr32<BufferUnit> base;
    u16 units;
    u16 records;
    u32 state;
    BufferRequest request;
    u32 unknown24to40[8];
    u32 flags;
};
struct BufferSpan { Ptr32<BufferUnit> data; u16 units; u16 tail;
 u16 count() const { return units; }
 void set(Ptr32<BufferUnit> p,u32 n) { data=p;units=n; }
};
struct Record { u32 unknown; BufferSpan span; Ptr32<BufferSpan> get() { return &span; } };
struct RecordTable { Ptr32<Record> base; Ptr32<Record> at(u32 i) { return base+i; } };
extern "C" {
extern Ptr32<TemporaryOwner> w3d_buffer_shared_cell();
extern Ptr32<void> w3d_temporary_owner_release(Ptr32<TemporaryOwner>);
extern u32 w3d_buffer_external_word;
extern Ptr32<void> w3d_buffer_request_service();
extern void w3d_buffer_request_write(Ptr32<void>, Ptr32<void>, u32, Ptr32<void>);

void w3d_buffer_manager_register(Ptr32<BufferManager> m, short n, Ptr32<Record> r)
{
    Ptr32<BufferUnit> data = (Ptr32<BufferUnit>)w3d::G((m->units * 24 + (u32)w3d::H(m->base)));
    m->records++;
    r->get()->set(data,n);
    m->units += n;
}




void w3d_buffer_manager_submit(Ptr32<BufferManager> m, Ptr32<RecordTable> records)
{
    u16 quantity=m->units;
    if(quantity) {
        u32 n=(quantity*24+31)&~31u;
        w3d_buffer_request_write(w3d_buffer_request_service(),m->base,n,&m->request);
        w3d_temporary_owner_release(w3d_buffer_shared_cell());
        m->base=0;
        for(u32 i=0;i<m->records;i++) records->at(i)->get()->set(0,records->at(i)->get()->count());
        m->state=3;
    }
    m->flags &= ~0x40000000u;
    w3d_buffer_external_word=0;
}



}

}


