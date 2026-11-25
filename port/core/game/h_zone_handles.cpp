#include "w3d_ptr.h"
#line 1 "h_zone_handles.cpp"
/* Trigger-zone helpers, small message records and handle-member wrappers
 * (0x80125c80..0x801266ac).
 *
 * Names are inferred from behavior; no original symbols survive. The trigger
 * zone layout repeats the observed offsets of the zone type in h_entities_a.
 * Handle members keep a u16 engine handle at +2 and a word at +4; most
 * wrappers forward that handle to the handle API in 0x8003f000..0x800c2000.
 */
extern "C" {

typedef struct W3dSharedList {
    unsigned char unknown_00[0x20];
    unsigned short count; unsigned short w3d_flags_high;
} W3dSharedList;

typedef struct W3dMessage {
    unsigned short id;
} W3dMessage;

typedef struct W3dInterface W3dInterface;

typedef struct W3dInterfaceTable {
    Ptr32<void> unknown_00[4];
    Ptr32<void (Ptr32<W3dInterface>)> release;
} W3dInterfaceTable;

struct W3dInterface {
    Ptr32<W3dInterfaceTable> vtable;
};

/* Engine string: one pointer to text behind a small header. */
typedef struct W3dString {
    Ptr32<char> data;
} W3dString;

/* Embedded handle member (constructed and destroyed out of line). */
typedef struct W3dMember {
    unsigned char unknown_00[4];
} W3dMember;

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_state_register(Ptr32<W3dSharedList> list, Ptr32<void> link);
void w3d_string_base_finish(Ptr32<W3dString> string);
void w3d_string_release(Ptr32<W3dString> string);




typedef struct W3dHeap {
    unsigned char unknown_00[4];
} W3dHeap;

typedef struct W3dVec3 {
    float x, y, z;
} W3dVec3;

typedef struct W3dTriggerZone {
    unsigned char unknown_00[0x38];
    int team_038;
    int worm_03c;
    int team_040;
    int team_044;
    unsigned char unknown_48[0x4c - 0x48];
    int disabled_04c;
    int disabled_050;
    int value_054;
    int triggered_058;
    unsigned char unknown_5c[0x6c - 0x5c];
    Ptr32<void> owner_06c;
    int reason_070;
    int worm_074;
} W3dTriggerZone;

typedef struct W3dWormData {
    unsigned char unknown_00[0xd5];
    unsigned char team_0d5;
} W3dWormData;

/* Small message records: identifier, base vtable, payload. */
typedef struct W3dIntMessage {
    unsigned short id;
    unsigned short unknown_02;
    Ptr32<const void> vtable;
    int value;
} W3dIntMessage;

typedef struct W3dVecMessage {
    unsigned short id;
    unsigned short unknown_02;
    Ptr32<const void> vtable;
    W3dVec3 value;
} W3dVecMessage;

typedef struct W3dHandleMember {
    unsigned short unknown_00;
    unsigned short handle;
    unsigned int word;
} W3dHandleMember;

extern Ptr32<const void> w3d_message_vtable_8040db38[];
extern Ptr32<unsigned int (void)> w3d_clock_804b17b4;
extern W3dHeap w3d_handle_heap_804af5bc;

int w3d_entity_worm_80178c48(Ptr32<void> owner);
Ptr32<W3dWormData> w3d_worm_data_800fc6dc(int worm);
unsigned int w3d_handle_create_8003f400(unsigned int flags);
void w3d_handle_set_bounds(unsigned int handle, Ptr32<const W3dVec3> position, float radius);
void w3d_handle_set_slot_word(unsigned int handle, unsigned int value);
int w3d_handle_query_8003fad8(unsigned int handle, float);
int w3d_handle_query_8003fa90(unsigned int handle, Ptr32<void>);
int w3d_handle_query_8003fbd0(unsigned int handle, Ptr32<void>);
int w3d_handle_call_8003fbe8(unsigned int handle, unsigned int word, int mode);
int w3d_handle_query_80041838(unsigned int handle);
int w3d_handle_call_8003fc70(unsigned int handle, unsigned int word, Ptr32<void> a, int b, int mode);
int w3d_handle_call_8003fd54(unsigned int handle, unsigned int word, Ptr32<void> a, Ptr32<void> b, int c, int mode);
int w3d_handle_query_8003ffac(unsigned int handle);
int w3d_handle_activate_resource(unsigned int handle);
unsigned int w3d_handle_create_800c07c4(int kind);
void w3d_handle_destroy_800c1004(unsigned int handle);
int w3d_handle_query_800c125c(unsigned int handle, Ptr32<void>);
int w3d_handle_query_800c1348(unsigned int handle, float);
int w3d_handle_query_800c136c(unsigned int handle, float, float, float);
void w3d_heap_release(Ptr32<W3dHeap> heap, Ptr32<void> object);

void w3d_trigger_zone_check_team_a_80125c80(Ptr32<W3dTriggerZone> object)
{
    if (object->disabled_04c == 0 && object->disabled_050 == 0 && object->triggered_058 == 0) {
        int worm = w3d_entity_worm_80178c48(object->owner_06c);
        if (object->team_040 == -1 || object->team_040 == w3d_worm_data_800fc6dc(worm)->team_0d5) {
                        object->triggered_058 = 1;
            object->reason_070 = 3;
            object->worm_074 = worm;
            }
    }
}

void w3d_trigger_zone_check_team_b_80125d0c(Ptr32<W3dTriggerZone> object)
{
    if (object->disabled_04c == 0 && object->disabled_050 == 0 && object->triggered_058 == 0) {
        int worm = w3d_entity_worm_80178c48(object->owner_06c);
        if (object->team_044 == -1 || w3d_worm_data_800fc6dc(worm)->team_0d5 == object->team_044) {
                        object->worm_074 = worm;
            object->triggered_058 = 1;
            object->reason_070 = 2;
            }
    }
}

void w3d_trigger_zone_trigger_now_80125d98(Ptr32<W3dTriggerZone> object)
{
    if (object->disabled_04c == 0 && object->disabled_050 == 0 && object->triggered_058 == 0) {
        object->triggered_058 = 1;
        object->reason_070 = 4;
        object->worm_074 = w3d_entity_worm_80178c48(object->owner_06c);
    }
}

unsigned int w3d_trigger_zone_filter_flags_80125e00(Ptr32<W3dTriggerZone> object)
{
    unsigned int flags = 0;
    if ((unsigned int)(object->team_038 + 1) <= 4 || (unsigned int)(object->worm_03c + 1) <= 16)
        flags = 1;
    if ((unsigned int)(object->team_040 + 1) <= 4)
        flags |= 0x80;
    if ((unsigned int)(object->team_044 + 1) <= 4)
        flags |= 8;
    if (object->value_054)
        flags |= 0x200;
    return flags;
}

Ptr32<W3dIntMessage> w3d_int_message_init_80125fdc(Ptr32<W3dIntMessage> message, unsigned short id, int value)
{
    message->id = id;
    message->vtable = w3d_message_vtable_8040db38;
    message->value = value;
    return message;
}

int w3d_int_message_value_80125ff8(Ptr32<W3dIntMessage> message)
{
    return message->value;
}

Ptr32<W3dVecMessage> w3d_vec_message_init_80126000(Ptr32<W3dVecMessage> message, unsigned short id, Ptr32<const W3dVec3> value)
{
    message->id = id;
    message->vtable = w3d_message_vtable_8040db38;
    message->value = *value;
    return message;
}

Ptr32<W3dVec3> w3d_vec_message_value_80126034(Ptr32<W3dVecMessage> message)
{
    return &message->value;
}

unsigned int w3d_bits_2_to_7_80126174(unsigned int value)
{
    return (value >> 2) & 0x3f;
}

unsigned int w3d_bits_10_to_15_8012617c(unsigned int value)
{
    return (value >> 10) & 0x3f;
}

#if 0 /* 0x801261bc: code matches but the original frame is 8 bytes larger (float-parameter slot); struct-local and inline variants tried. */
static inline void w3d_handle_member_set_bounds_inline(W3dHandleMember *member, const W3dVec3 *position, float radius)
{
    w3d_handle_set_bounds(member->handle, position, radius);
}

static inline void w3d_handle_member_set_slot_word_inline(W3dHandleMember *member, unsigned int value)
{
    w3d_handle_set_slot_word(member->handle, value);
}

W3dHandleMember *w3d_handle_member_init_bounds_801261bc(W3dHandleMember *member, const W3dVec3 *position,
                                                        unsigned int slot_word, unsigned int word, float radius)
{
    member->handle = w3d_handle_create_8003f400(0);
    w3d_handle_member_set_bounds_inline(member, position, radius);
    w3d_handle_member_set_slot_word_inline(member, slot_word);
    member->word = word;
    return member;
}
#endif

int w3d_handle_member_query_8012629c(Ptr32<W3dHandleMember> member, float arg_f1)
{
    return w3d_handle_query_8003fad8(member->handle, arg_f1);
}

int w3d_handle_member_query_801262c0(Ptr32<W3dHandleMember> member, Ptr32<void> arg_r4)
{
    return w3d_handle_query_8003fa90(member->handle, arg_r4);
}

int w3d_handle_member_query_80126308(Ptr32<W3dHandleMember> member, Ptr32<void> arg_r4)
{
    return w3d_handle_query_8003fbd0(member->handle, arg_r4);
}

int w3d_handle_member_call_80126334(Ptr32<W3dHandleMember> member)
{
    return w3d_handle_call_8003fbe8(member->handle, member->word, -2);
}

int w3d_handle_member_query_80126360(Ptr32<W3dHandleMember> member)
{
    return w3d_handle_query_80041838(member->handle);
}

int w3d_handle_member_call_80126384(Ptr32<W3dHandleMember> member, int a, int b)
{
    return w3d_handle_call_8003fc70(member->handle, member->word, (Ptr32<void>)w3d::G(a), b, -2);
}

int w3d_handle_member_call_801263bc(Ptr32<W3dHandleMember> member, int a, int b, int c)
{
    return w3d_handle_call_8003fd54(member->handle, member->word, (Ptr32<void>)w3d::G(a), (Ptr32<void>)w3d::G(b), c, -2);
}

unsigned int w3d_handle_clock_801264fc(void)
{
    return w3d_clock_804b17b4();
}

int w3d_handle_member_query_80126524(Ptr32<W3dHandleMember> member)
{
    return w3d_handle_query_8003ffac(member->handle);
}

int w3d_handle_member_activate_80126548(Ptr32<W3dHandleMember> member)
{
    return w3d_handle_activate_resource(member->handle);
}

Ptr32<W3dHandleMember> w3d_handle_member_init_kind_8012656c(Ptr32<W3dHandleMember> member, int kind)
{
    member->handle = w3d_handle_create_800c07c4(kind);
    return member;
}

void w3d_handle_member_destroy_801265a4(Ptr32<W3dHandleMember> member, int flags)
{
    w3d_handle_destroy_800c1004(member->handle);
    if (flags & 1)
        w3d_heap_release(&w3d_handle_heap_804af5bc, member);
}

int w3d_handle_member_query_801265ec(Ptr32<W3dHandleMember> member, Ptr32<void> arg_r4)
{
    return w3d_handle_query_800c125c(member->handle, arg_r4);
}

int w3d_handle_member_query_80126688(Ptr32<W3dHandleMember> member, float arg_f1)
{
    return w3d_handle_query_800c1348(member->handle, arg_f1);
}

int w3d_handle_member_query_801266ac(Ptr32<W3dHandleMember> member, float arg_f1, float arg_f2, float arg_f3)
{
    return w3d_handle_query_800c136c(member->handle, arg_f1, arg_f2, arg_f3);
}

}


