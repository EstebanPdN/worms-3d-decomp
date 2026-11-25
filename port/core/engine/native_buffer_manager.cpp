#include "w3d_ptr.h"
#line 1 "native_buffer_manager.cpp"
/* Reference ABI reconstruction: names, class role and ownership inferred.
 * Six complete bodies only. Unknown methods remain external obligations. */
struct TemporaryOwner; /* Same opaque cell type as native_temporary_owner.cpp. */
namespace w3d_native_buffer_detail {
/* Six complete byte-exact candidates only; no runtime or ownership claim. */
/* Inferred names; observed offsets and integer widths retained. */
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
 u32 count() const { return units; }
 void set(Ptr32<BufferUnit> p,u16 n) { data=p;units=n; }
};
struct Record { u32 unknown; BufferSpan span; Ptr32<BufferSpan> get() { return &span; } };
struct RecordTable { Ptr32<Record> base; Ptr32<Record> at(u32 i) { return base+i; } };
extern "C" {
extern Ptr32<TemporaryOwner> w3d_buffer_shared_cell();
extern Ptr32<void> w3d_temporary_owner_allocate(Ptr32<TemporaryOwner>, u32);
extern Ptr32<void> w3d_temporary_owner_release(Ptr32<TemporaryOwner>);
extern void w3d_buffer_storage_release(Ptr32<TemporaryOwner>, Ptr32<void>);
extern int w3d_buffer_request_state(Ptr32<void>);
extern u32 w3d_buffer_external_word;
void w3d_buffer_manager_initialize(Ptr32<BufferManager> m)
{
    m->records = 0;
    m->units = 0;
    m->flags |= 0x40000000u;
    m->base = (Ptr32<BufferUnit>)w3d_temporary_owner_allocate(w3d_buffer_shared_cell(), 36000);
    w3d_buffer_external_word = 0;
}

void w3d_buffer_manager_release_temporary(Ptr32<BufferManager> m)
{
    w3d_temporary_owner_release(w3d_buffer_shared_cell());
    m->flags &= ~0x40000000u;
}
void w3d_buffer_manager_release_storage(Ptr32<BufferManager> m)
{
    m->request.words[0] = 2;
    if (m->base) w3d_buffer_storage_release(w3d_buffer_shared_cell(), m->base);
    m->base = 0;
}
u32 w3d_buffer_manager_poll_state(Ptr32<BufferManager> m)
{
    switch(w3d_buffer_request_state(&m->request)) {
    case 2: m->state=3; break;
    case 3: m->state=2; break;
    case 5: m->state=1; break;
    }
    return m->state;
}


void w3d_buffer_manager_move(Ptr32<BufferManager> m, Ptr32<BufferManager> destination)
{
    *destination=*m;
    m->request.clear();
    m->flags &= ~0x80000000u;
    destination->flags |= 0x80000000u;
    m->base=0;
}
void w3d_buffer_manager_clear_records(Ptr32<BufferManager> m, Ptr32<RecordTable> records)
{
    w3d_buffer_manager_release_storage(m);
    for(u32 i=0;i<m->records;i++) records->at(i)->get()->set(0,records->at(i)->get()->count());
}

}

}


