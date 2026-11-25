#include "w3d_ptr.h"
#line 1 "d26b_water_destroy_8009081c.cpp"
/* Water mesh destructor (0x8009081c): installs the table 0x8040f150 at +2792, clears the
 * flag 0x804aab68, frees the owned buffers to the heap 0x804adde4 (0x80209920), clears
 * them and runs 0x8008eb98 and 0x80078db8; the member destructors then release the held
 * objects through slot +16, delete the vector storage (0x802134fc) and destroy the lists
 * +60 to +180 (0x801f2758). The base destructor clears +28. Field names are inferred from
 * the original instructions. Owns no data. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[4];
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Held { Ptr32<Object> object; ~Held() { if (object) object->vtable->release(object); } };
extern "C" void w3d_handle_delete_802134fc(Ptr32<void>);
struct Storage { Ptr32<void> begin; int unknown04[2]; ~Storage() { if (begin) w3d_handle_delete_802134fc(begin); } };
struct D26bList_801f2758 { char unknown00[12]; ~D26bList_801f2758(); };
struct D26bBase {
    char unknown00[28];
    int value28;
    ~D26bBase() { value28 = 0; }
    Ptr32<void> unknown32[5];
    Ptr32<void> buffer52;
    int unknown56;
};
extern char w3d_table_8040f150[];
extern int w3d_flag_804aab68;
extern Ptr32<void> w3d_buffer_804b1800;
extern char w3d_heap_804adde4;
extern "C" void w3d_heap_free_80209920(Ptr32<void>, Ptr32<void>);
extern "C" void w3d_water_clear_8008eb98();
struct D26bWater;
extern "C" int w3d_lists_clear_80078db8(Ptr32<D26bWater>);
struct D26bWater : D26bBase {
    D26bList_801f2758 list60 __attribute__((aligned(__alignof__(D26bBase))));
    D26bList_801f2758 list72;
    D26bList_801f2758 list84;
    D26bList_801f2758 list96;
    D26bList_801f2758 list108;
    D26bList_801f2758 list120;
    D26bList_801f2758 list132;
    D26bList_801f2758 list144;
    D26bList_801f2758 list156;
    D26bList_801f2758 list168;
    D26bList_801f2758 list180;
    Held held192;
    Held held196;
    Held held200;
    Held held204;
    Held held208;
    Held held212;
    Held held216;
    Held held220;
    Held held224;
    Held held228;
    Held held232;
    Held held236;
    Held held240;
    char unknown244[124];
    Held held368;
    char unknown372[160];
    Ptr32<void> proto532;
    int value536;
    char unknown540[16];
    Held held556;
    Held held560;
    char unknown564[108];
    Ptr32<void> buffer672;
    Ptr32<void> buffer676;
    Ptr32<void> buffer680;
    Ptr32<void> buffer684;
    Ptr32<void> buffer688;
    Ptr32<void> buffer692;
    Ptr32<void> buffer696;
    int unknown700;
    Ptr32<void> buffer704;
    Ptr32<void> buffer708;
    Ptr32<void> buffer712;
    Ptr32<void> buffer716;
    int value720;
    Ptr32<void> a724;
    char unknown728[1576];
    Storage storage2304;
    Storage storage2316;
    Storage storage2328;
    Storage storage2340;
    Storage storage2352;
    Storage storage2364;
    Storage storage2376;
    Storage storage2388;
    Storage storage2400;
    Storage storage2412;
    Storage storage2424;
    Storage storage2436;
    Storage storage2448;
    Storage storage2460;
    Ptr32<void> buffer2472;
    char unknown2476[16];
    int value2492;
    Ptr32<void> b2496;
    char unknown2500[268];
    Storage storage2768;
    Held held2780;
    Held held2784;
    Held held2788;
    Ptr32<void> table;
    ~D26bWater();
    void operator delete(void *p) { w3d_heap_free_80209920(&w3d_heap_804adde4, p); }
};
D26bWater::~D26bWater()
{
    table = w3d_table_8040f150;
    w3d_flag_804aab68 = 0;
    {
        unsigned i = 0;
        Ptr32<void> zero = 0;
        Ptr32<Ptr32<void>> p = &b2496;
        for (; i < 1; i++) {
            w3d_heap_free_80209920(&w3d_heap_804adde4, p[-443]);
            w3d_heap_free_80209920(&w3d_heap_804adde4, *p);
            p[-443] = zero;
            *p = zero;
            p++;
        }
    }
    Ptr32<void> shared = w3d_buffer_804b1800;
    value720 = 0;
    value2492 = 0;
    w3d_heap_free_80209920(&w3d_heap_804adde4, shared);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer2472);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer672);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer676);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer680);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer684);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer716);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer688);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer704);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer708);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer712);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer52);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer692);
    w3d_heap_free_80209920(&w3d_heap_804adde4, buffer696);
    if (held368.object) held368.object->vtable->release(held368.object);
    held368.object = 0;
    proto532 = 0;
    value536 = 1;
    w3d_water_clear_8008eb98();
    w3d_lists_clear_80078db8(this);
}


