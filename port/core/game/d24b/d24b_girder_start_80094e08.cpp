#include "w3d_ptr.h"
#line 1 "d24b_girder_start_80094e08.cpp"
/* Girder placement start (0x80094e08): selects the UtilityGirder slot, reads the girder
 * settings into +724, +728, +736, retains Girder.Camera.Occlude in +752, reads Water.Level
 * and Land.InitialMaxHeight into +756 and +760, creates the handle in +764, fills the
 * corner and marker point table at +348, subscribes to 26 messages with handlers +64 to
 * +164, posts the created message, reads Weapon.Girder.MaxDistance into +344 and runs
 * 0x80095450 and 0x80095b58. Field and type names are inferred from the original
 * instructions. Owns its float literals at 0x8037eb20. */
struct Object;
struct ObjectVtable {
    Ptr32<void> unknown00[3];
    Ptr32<void (Ptr32<Object>)> retain;   /* +12 */
    Ptr32<void (Ptr32<Object>)> release;  /* +16 */
};
struct Object { Ptr32<ObjectVtable> vtable; };
struct Handle {
    Ptr32<Object> value;
    Handle() {}
    ~Handle() { if (value) value->vtable->release(value); }
private:
    Handle(const Handle &);
};
struct PropertyKey { Ptr32<const char> name; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Vec3 { float x, y, z; void Set(float v) { x = v; y = v; z = v; } };
struct GirderHandle;
struct Id { int value; Id(int v) { value = v; } };
struct GirderStart {
    char unknown00[20];
    int id;                /* +20 */
    char unknown24[40];
    char handlers[26][4];  /* +64 */
    char unknown168[176];
    char maxDistance[4];   /* +344 */
    float points[36];      /* +348 */
    char unknown492[192];
    int value684;          /* +684 */
    char unknown688[36];
    char position[4];      /* +724 */
    char velocity[4];      /* +728 */
    char unknown732[4];
    char placed[4];        /* +736 */
    char unknown740[12];
    Ptr32<Object> occlude;       /* +752 */
    char waterLevel[4];    /* +756 */
    char maxHeight[4];     /* +760 */
    Ptr32<GirderHandle> handle;  /* +764 */
};
extern "C" void w3d_named_slot_select_800a7e14(int, Ptr32<const char>);
extern "C" int w3d_resource_property_800fc1b0(Ptr32<PropertyKey>, Ptr32<void>);
extern "C" int w3d_float_read_800fc270(Ptr32<PropertyKey>, Ptr32<void>);
extern "C" Ptr32<Object> w3d_identity_803426b4(Ptr32<Object>);
extern "C" int w3d_update_value_80178c54(Ptr32<Object>, Ptr32<int>);
extern "C" Ptr32<void> w3d_heap_allocate_802098d8(Ptr32<void>, int);
extern "C" Ptr32<GirderHandle> w3d_handle_construct_801261bc(Ptr32<void>, Ptr32<Vec3>, int, int, float);
extern "C" void w3d_handle_member_query_80126308(Ptr32<GirderHandle>, int);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_subscribe_80162024(Ptr32<GirderStart>, const unsigned short &, Ptr32<void>);
extern "C" Ptr32<void> w3d_arena_alloc_801613f0(Ptr32<void>, int);
extern "C" Ptr32<void> w3d_created_message_800c1620(Ptr32<void>, const Id &);
extern "C" int w3d_message_post_8016239c(Ptr32<void>);
extern "C" void w3d_planar_heading_80095450(Ptr32<GirderStart>);
extern "C" void w3d_transform_points_80095b58(Ptr32<GirderStart>);
extern Ptr32<void> w3d_message_arena_804b1754;
extern char w3d_pool_804af5bc[8];
extern MessageCache w3d_message_804ade50, w3d_message_804ade78, w3d_message_804ade80, w3d_message_804ade58, w3d_message_804ade60, w3d_message_804ade68, w3d_message_804ade70, w3d_message_804ade88, w3d_message_804ade90, w3d_message_804ade98, w3d_message_804adea0, w3d_message_804adea8, w3d_message_804adeb0, w3d_message_804adeb8, w3d_message_804adec0, w3d_message_804adec8, w3d_message_804aded0, w3d_message_804aded8, w3d_message_804adee0, w3d_message_804adee8, w3d_message_804adef0, w3d_message_804adef8, w3d_message_804adf00, w3d_message_804adf30, w3d_message_804adf38, w3d_message_804adf40;
extern "C" char w3d_string_8037ea14[]; /* "UtilityGirder" */
extern "C" char w3d_string_8037ea8c[]; /* "Girder.Position" */
extern "C" char w3d_string_8037ea9c[]; /* "Girder.Velocity" */
extern "C" char w3d_string_8037eaac[]; /* "Girder.Camera.Occlude" */
extern "C" char w3d_string_8037eac4[]; /* "Girder.TotalNumberPlaced" */
extern "C" char w3d_string_8037eae0[]; /* "Water.Level" */
extern "C" char w3d_string_8037eaec[]; /* "Land.InitialMaxHeight" */
extern "C" char w3d_string_8037eb04[]; /* "Weapon.Girder.MaxDistance" */

inline void ReadResource(Ptr32<const char> name, Ptr32<void> out)
{
    PropertyKey key;
    key.name = name;
    w3d_resource_property_800fc1b0(&key, out);
}
inline void ReadFloat(Ptr32<const char> name, Ptr32<void> out)
{
    PropertyKey key;
    key.name = name;
    w3d_float_read_800fc270(&key, out);
}

extern "C" void w3d_d24b_girder_start_80094e08(Ptr32<GirderStart> self)
{
    Handle handle;
    handle.value = 0;
    Ptr32<Ptr32<Object>> slot = &handle.value;
    w3d_named_slot_select_800a7e14(0, w3d_string_8037ea14);
    ReadResource(w3d_string_8037ea8c, self->position);
    ReadResource(w3d_string_8037ea9c, self->velocity);
    ReadResource(w3d_string_8037eaac, slot);
    ReadResource(w3d_string_8037eac4, self->placed);
    Ptr32<Object> object = w3d_identity_803426b4(handle.value);
    if (object) object->vtable->retain(object);
    if (self->occlude) self->occlude->vtable->release(self->occlude);
    self->occlude = object;
    {
        int value = 0;
        w3d_update_value_80178c54(object, &value);
    }
    ReadFloat(w3d_string_8037eae0, self->waterLevel);
    ReadFloat(w3d_string_8037eaec, self->maxHeight);
    {
        float zero = 0.0f;
        Vec3 offset;
        Ptr32<Vec3> pv = &offset;
        offset.x = zero;
        pv->y = zero;
        pv->z = zero;
        Ptr32<void> memory = w3d_heap_allocate_802098d8(w3d_pool_804af5bc, 8);
        Ptr32<GirderHandle> h = w3d_handle_construct_801261bc(memory, pv, 0, 63, 25.0f);
        self->handle = h;
        w3d_handle_member_query_80126308(h, self->id);
    }
    float zero = 0.0f;
    float a25 = 25.0f, m25 = -25.0f, b15 = 15.0f, m15 = -15.0f, a12 = 12.5f, m12 = -12.5f;
    self->points[0] = m25;
    self->points[1] = b15;
    self->points[2] = m25;
    self->points[3] = m25;
    self->points[4] = b15;
    self->points[5] = a25;
    self->points[6] = a25;
    self->points[7] = b15;
    self->points[8] = a25;
    self->points[9] = a25;
    self->points[10] = b15;
    self->points[11] = m25;
    self->points[12] = m25;
    self->points[13] = m15;
    self->points[14] = m25;
    self->points[15] = m25;
    self->points[16] = m15;
    self->points[17] = a25;
    self->points[18] = a25;
    self->points[19] = m15;
    self->points[20] = a25;
    self->points[21] = a25;
    self->points[22] = m15;
    self->points[23] = m25;
    self->points[24] = a12;
    self->points[25] = zero;
    self->points[26] = a12;
    self->points[27] = m12;
    self->points[28] = zero;
    self->points[29] = a12;
    self->points[30] = a12;
    self->points[31] = zero;
    self->points[32] = m12;
    self->points[33] = m12;
    self->points[34] = zero;
    self->points[35] = m12;
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ade50, 1), self->handlers + 0);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ade78, 1), self->handlers + 1);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ade80, 1), self->handlers + 2);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ade58, 1), self->handlers + 3);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ade60, 1), self->handlers + 4);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ade68, 1), self->handlers + 5);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ade70, 1), self->handlers + 6);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ade88, 1), self->handlers + 7);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ade90, 1), self->handlers + 8);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804ade98, 1), self->handlers + 9);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adea0, 1), self->handlers + 10);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adea8, 1), self->handlers + 11);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adeb0, 1), self->handlers + 12);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adeb8, 1), self->handlers + 13);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adec0, 1), self->handlers + 14);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adec8, 1), self->handlers + 15);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aded0, 1), self->handlers + 16);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804aded8, 1), self->handlers + 17);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adee0, 1), self->handlers + 18);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adee8, 1), self->handlers + 19);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adef0, 1), self->handlers + 20);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adef8, 1), self->handlers + 21);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adf00, 1), self->handlers + 22);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adf30, 1), self->handlers + 23);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adf38, 1), self->handlers + 24);
    w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804adf40, 1), self->handlers + 25);
    w3d_message_post_8016239c(w3d_created_message_800c1620(w3d_arena_alloc_801613f0(w3d_message_arena_804b1754, 12), Id(self->id)));
    ReadFloat(w3d_string_8037eb04, self->maxDistance);
    w3d_planar_heading_80095450(self);
    w3d_transform_points_80095b58(self);
    self->value684 = 0;
}


