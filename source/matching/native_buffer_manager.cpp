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
    BufferUnit *base;
    u16 units;
    u16 records;
    u32 state;
    BufferRequest request;
    u32 unknown24to40[8];
    u32 flags;
};
struct BufferSpan { BufferUnit *data; u16 units; u16 tail;
 u32 count() const { return units; }
 void set(BufferUnit *p,u16 n) { data=p;units=n; }
};
struct Record { u32 unknown; BufferSpan span; BufferSpan *get() { return &span; } };
struct RecordTable { Record *base; Record *at(u32 i) { return base+i; } };
extern "C" {
extern TemporaryOwner *w3d_buffer_shared_cell();
extern void *w3d_temporary_owner_allocate(TemporaryOwner *, u32);
extern void *w3d_temporary_owner_release(TemporaryOwner *);
extern void w3d_buffer_storage_release(TemporaryOwner *, void *);
extern int w3d_buffer_request_state(void *);
extern u32 w3d_buffer_external_word;
void w3d_buffer_manager_initialize(BufferManager *m)
{
    m->records = 0;
    m->units = 0;
    m->flags |= 0x40000000u;
    m->base = (BufferUnit *)w3d_temporary_owner_allocate(w3d_buffer_shared_cell(), 36000);
    w3d_buffer_external_word = 0;
}

void w3d_buffer_manager_release_temporary(BufferManager *m)
{
    w3d_temporary_owner_release(w3d_buffer_shared_cell());
    m->flags &= ~0x40000000u;
}
void w3d_buffer_manager_release_storage(BufferManager *m)
{
    m->request.words[0] = 2;
    if (m->base) w3d_buffer_storage_release(w3d_buffer_shared_cell(), m->base);
    m->base = 0;
}
u32 w3d_buffer_manager_poll_state(BufferManager *m)
{
    switch(w3d_buffer_request_state(&m->request)) {
    case 2: m->state=3; break;
    case 3: m->state=2; break;
    case 5: m->state=1; break;
    }
    return m->state;
}


void w3d_buffer_manager_move(BufferManager *m, BufferManager *destination)
{
    *destination=*m;
    m->request.clear();
    m->flags &= ~0x80000000u;
    destination->flags |= 0x80000000u;
    m->base=0;
}
void w3d_buffer_manager_clear_records(BufferManager *m, RecordTable *records)
{
    w3d_buffer_manager_release_storage(m);
    for(u32 i=0;i<m->records;i++) records->at(i)->get()->set(0,records->at(i)->get()->count());
}

}

}
