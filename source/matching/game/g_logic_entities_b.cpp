/* Weapon-style logic entity with a timed state machine, and the sky/water setup entity (0x800c2654..0x800c44b0).
 *
 * Names are inferred from behavior; no original symbols survive. Both classes
 * follow the logic-class family (type record with u16 count at +0x22, u16
 * references at +0x04). Observed layout of the 116-byte entity (type 0x80360a20):
 *   +0x14 owner id, +0x1c held resource, +0x20 state (1..7), +0x24 held object,
 *   +0x28 held effect (vtable slots +0x14 release-like, +0x18 stop, +0x24 busy,
 *   +0x38 configure), +0x2c settings record (+0xe0/+0xe4 engine strings, +0xf8 flag),
 *   +0x48 deadline, +0x50..+0x5c held objects, +0x60 owned object, +0x64 buffer.
 * The 36-byte entity (type 0x80360a50) has a held object at +0x1c and a float at +0x20.
 */
#include "g_types2.h"

extern "C" {

typedef struct W3dGBuffer {
    void *data;
    void *end;
    void *capacity;
} W3dGBuffer;

typedef struct W3dGEffect W3dGEffect;
typedef struct W3dGEffectVtbl {
    void *unknown_00[4];
    void (*release)(W3dGEffect *effect);
    void (*finish)(W3dGEffect *effect);
    void (*stop)(W3dGEffect *effect);
    void *unknown_1c[2];
    int (*busy)(W3dGEffect *effect);
    void *unknown_28[4];
    void (*configure)(W3dGEffect *effect, int mode, const W3dGPos *position);
} W3dGEffectVtbl;
struct W3dGEffect {
    W3dGEffectVtbl *vtbl;
};

typedef struct W3dGEffectFactory W3dGEffectFactory;
typedef struct W3dGEffectFactoryVtbl {
    void *unknown_00[23];
    void (*create)(W3dGEffectFactory *factory, char *name, W3dGEffect **out);
} W3dGEffectFactoryVtbl;
struct W3dGEffectFactory {
    W3dGEffectFactoryVtbl *vtbl;
};

typedef struct W3dGWeaponSettings {
    unsigned char unknown_00[0xe0];
    W3dGString effect_name;
    W3dGString sound_name;
    unsigned char unknown_e8[0xf8 - 0xe8];
    int flag_f8;
} W3dGWeaponSettings;

typedef struct W3dGGameState {
    unsigned char unknown_00[0x6c];
    W3dGEffectFactory *effects;
} W3dGGameState;

typedef struct W3dGTimed {
    unsigned char unknown_00[0x38];
    int delay;
    unsigned char unknown_3c[0x9c - 0x3c];
    int ready;
} W3dGTimed;

typedef struct W3dGContext {
    unsigned char unknown_00[0x34];
    int now;
} W3dGContext;

typedef struct W3dGTarget {
    unsigned char unknown_00[0x2a4];
    W3dGVec3 position;
    unsigned char unknown_2b0[0x2f8 - 0x2b0];
    int alive;
} W3dGTarget;

typedef struct W3dLogic_80360a20 {
    void *vtable;
    unsigned short references;
    unsigned char unknown_06[0x14 - 0x06];
    int owner;
    unsigned char unknown_18[0x1c - 0x18];
    W3dGIface *held_1c;
    int state;
    W3dGIface *held_24;
    W3dGEffect *effect;
    W3dGWeaponSettings *settings;
    unsigned char unknown_30[0x48 - 0x30];
    int deadline;
    unsigned char unknown_4c[0x50 - 0x4c];
    W3dGIface *held_50;
    W3dGIface *held_54;
    W3dGIface *held_58;
    W3dGIface *held_5c;
    void *owned;
    W3dGBuffer buffer;
    unsigned char unknown_70[0x74 - 0x70];
} W3dLogic_80360a20;

typedef struct W3dLogic_80360a50 {
    void *vtable;
    unsigned short references;
    unsigned char unknown_06[0x14 - 0x06];
    int owner;
    unsigned char unknown_18[0x1c - 0x18];
    W3dGIface *field_1c;
    float value;
} W3dLogic_80360a50;

extern W3dLogicType w3d_logic_type_80360a20;
extern W3dLogicType w3d_logic_type_80360a50;
extern unsigned char w3d_vtable_8040f9a8[];
extern unsigned char w3d_vtable_8040f9e8[];
extern W3dGGameState *w3d_game_804b1788;
extern void *w3d_target_source_804ab400;
extern W3dGCachedMessage w3d_message_804ae6dc;
extern W3dGCachedMessage w3d_message_804ae6ec;
extern W3dGCachedMessage w3d_message_804ae6fc;
extern W3dGCachedMessage w3d_message_804ae724;
extern W3dGCachedMessage w3d_message_804ae734;
extern W3dGCachedMessage w3d_message_804ae74c;
extern const float w3d_f32_80383248[];
extern const float w3d_f32_8038346c[];
extern const float w3d_f32_8038356c[];
extern const char w3d_str_8038349c[];
extern const char w3d_str_803834b0[];
extern const char w3d_str_803834c0[];
extern const char w3d_str_803834d0[];
extern const char w3d_str_80383470[];
extern const char w3d_str_803834dc[];
extern const char w3d_str_803834f0[];
extern const char w3d_str_80383504[];
extern const char w3d_str_80383520[];
extern const char w3d_str_80383538[];
extern const char w3d_str_80383554[];
extern unsigned char w3d_class_80410680[];
extern unsigned char w3d_class_8040fb28[];

void w3d_actor_handle_member_destroy(void *object, int flags);
void w3d_handle_storage_release(void *storage);
void w3d_logic_hook_800c2e44(W3dLogic_80360a20 *object);
void w3d_logic_hook_800c31f0(W3dLogic_80360a20 *object);
int w3d_logic_ready_800c3cf4(W3dLogic_80360a20 *object);
void *w3d_empty_80341584(W3dGIface *object);
W3dGTimed *w3d_timed_lookup_801797b4(void *object);
W3dGContext *w3d_engine_get_context(void);
void *w3d_empty_803426b4(W3dGIface *object);
void *w3d_fn_80178c48(void *object);
void *w3d_fn_800fc6dc(int object);
int w3d_spawn_effect_800e5ca4(const W3dGPos &position, const char *name, float scale, int flags);
int w3d_target_id_80156f88(void *source);
W3dGTarget *w3d_actor_lookup_80164fc8(void *id);
int w3d_base_construct_8015fef0(void *object);
void w3d_base_destroy_8015ff2c(void *object, int flags);
int w3d_lookup_text_800fc550(const char **name, const char *fallback);
int w3d_set_float_800fc4c8(const char **name, float value);
unsigned int w3d_constructor_lookup_name(const void *name, void *output);

}

/* Buffer member constructor: empty range. */
static inline void w3d_gbuffer_init(W3dGBuffer *buffer)
{
    buffer->capacity = 0;
    buffer->end = 0;
    buffer->data = 0;
}

extern "C" {

W3dLogicType *w3d_logic_type_get_800c2654(void)
{
    return &w3d_logic_type_80360a20;
}

void w3d_logic_unlink_800c2660(W3dLogic_80360a20 *object)
{
    w3d_owner_list_remove(&w3d_logic_type_80360a20, &object->references);
    w3d_logic_type_80360a20.count--;
}

W3dLogic_80360a20 *w3d_logic_construct_800c2778(W3dLogic_80360a20 *object);
W3dLogic_80360a20 *w3d_logic_create_800c26a4(void)
{
    W3dLogic_80360a20 *object = w3d_logic_construct_800c2778((W3dLogic_80360a20 *)w3d_heap_allocate_entry_a(116));
    w3d_state_register(&w3d_logic_type_80360a20, object ? &object->references : 0);
    w3d_logic_type_80360a20.count++;
    return object;
}

void w3d_logic_unlink_800c2660(W3dLogic_80360a20 *object);
void w3d_logic_destroy_800c2810(W3dLogic_80360a20 *object, int flags);
unsigned short w3d_logic_release_800c2704(W3dLogic_80360a20 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_logic_unlink_800c2660(object);
        if (object)
            w3d_logic_destroy_800c2810(object, 3);
    }
    return remaining;
}

unsigned short w3d_logic_retain_800c2760(W3dLogic_80360a20 *object)
{
    return object->references++;
}

W3dLogic_80360a20 *w3d_logic_construct_800c2778(W3dLogic_80360a20 *object)
{
    w3d_actor_base_initialize(object);
    object->vtable = w3d_vtable_8040f9a8;
    object->held_1c = 0;
    object->held_24 = 0;
    object->effect = 0;
    object->settings = 0;
    object->held_50 = 0;
    object->held_54 = 0;
    object->held_58 = 0;
    object->held_5c = 0;
    w3d_gbuffer_init(&object->buffer);
    if (object->held_1c)
        object->held_1c->vtbl->release(object->held_1c);
    object->held_1c = 0;
    object->state = 0;
    object->owned = 0;
    return object;
}

void w3d_logic_destroy_800c2810(W3dLogic_80360a20 *object, int flags)
{
    object->vtable = w3d_vtable_8040f9a8;
    if (object->owned)
        w3d_actor_handle_member_destroy(object->owned, 3);
    object->owned = 0;
    if (object->buffer.data)
        w3d_handle_storage_release(object->buffer.data);
    if (object->held_5c)
        object->held_5c->vtbl->release(object->held_5c);
    if (object->held_58)
        object->held_58->vtbl->release(object->held_58);
    if (object->held_54)
        object->held_54->vtbl->release(object->held_54);
    if (object->held_50)
        object->held_50->vtbl->release(object->held_50);
    if (object->settings)
        ((W3dGIface *)object->settings)->vtbl->release((W3dGIface *)object->settings);
    if (object->effect)
        ((W3dGIface *)object->effect)->vtbl->release((W3dGIface *)object->effect);
    if (object->held_24)
        object->held_24->vtbl->release(object->held_24);
    if (object->held_1c)
        object->held_1c->vtbl->release(object->held_1c);
    w3d_actor_base_destroy(object, flags);
}

#if 0 /* 0x800c2960: the original compares a register copy of the message id (mr r0,r30); not reproduced in 14 variants. */
int w3d_logic_handle_800c2960(W3dLogic_80360a20 *object, W3dGMessage *message)
{
    unsigned short id = message->id;
    switch (message->id) {
    case 64:
        if (w3d_actor_handle_8015fb34(object, message) >= 0) {
            w3d_logic_hook_800c2e44(object);
            break;
        }
        return 0x80004005;
    case 66:
        if (object->state != 0)
            w3d_post_plain_message(&w3d_message_804ae6ec);
        w3d_logic_hook_800c31f0(object);
        return w3d_actor_handle_8015fb34(object, message);
    default:
        if (w3d_message_matches_8015f65c(id, &w3d_message_804ae6fc)) {
            if (!w3d_logic_ready_800c3cf4(object))
                break;
            if (object->state == 0) {
                W3dGTimed *timed;
                w3d_post_plain_message(&w3d_message_804ae74c);
                w3d_post_plain_message(&w3d_message_804ae734);
                W3dGContext *context;
                timed = w3d_timed_lookup_801797b4(w3d_empty_80341584(object->held_1c));
                context = w3d_engine_get_context();
                object->deadline = context->now + timed->delay;
                object->state = 1;
            }
        } else if (w3d_message_matches_8015f65c(id, &w3d_message_804ae6dc)) {
            if (object->effect && object->effect->vtbl->busy(object->effect))
                object->state = 5;
            else
                w3d_actor_remove_8015fd1c(object);
        } else if (w3d_message_matches_8015f65c(id, &w3d_message_804ae724)) {
            if (object->state == 3)
                object->state = 4;
        }
        return w3d_actor_handle_8015fb34(object, message);
    }
    return 0;
}
#endif

void w3d_logic_hook_800c31f0(W3dLogic_80360a20 *object)
{
}

void w3d_logic_lookup_800c31f4(W3dLogic_80360a20 *object, const char *name)
{
    w3d_constructor_lookup_name(&name, &object->held_1c);
}

void *w3d_logic_resource_800c3224(W3dLogic_80360a20 *object)
{
    return w3d_fn_800fc6dc((int)(w3d_fn_80178c48(w3d_empty_803426b4(object->held_24))));
}

void w3d_logic_play_800c3250(W3dLogic_80360a20 *object, const W3dGPos &position)
{
    if (w3d_gstring_length(&object->settings->sound_name) != 0)
        w3d_spawn_effect_800e5ca4(position, object->settings->sound_name.data, w3d_f32_80383248[0], 0);
    if (w3d_gstring_length(&object->settings->effect_name) != 0 && w3d_game_804b1788->effects) {
        if (object->effect) {
            object->effect->vtbl->stop(object->effect);
            if (object->effect)
                object->effect->vtbl->release(object->effect);
            object->effect = 0;
        }
        w3d_game_804b1788->effects->vtbl->create(w3d_game_804b1788->effects,
            object->settings->effect_name.data, &object->effect);
        object->effect->vtbl->configure(object->effect, 3, &position);
        object->effect->vtbl->finish(object->effect);
    }
}

int w3d_logic_ready_800c3cf4(W3dLogic_80360a20 *object)
{
    W3dGTimed *timed = w3d_timed_lookup_801797b4(w3d_empty_80341584(object->held_1c));
    W3dGTarget *target = w3d_actor_lookup_80164fc8((void *)w3d_target_id_80156f88(w3d_target_source_804ab400));
    const W3dGVec3 &p = target->position;
    W3dGPos position(p.x, p.y, p.z);
    return target->alive == 0 || timed->ready != 0;
}

W3dLogicType *w3d_logic_type_get_800c3f54(void)
{
    return &w3d_logic_type_80360a50;
}

void w3d_logic_unlink_800c3f60(W3dLogic_80360a50 *object)
{
    w3d_owner_list_remove(&w3d_logic_type_80360a50, &object->references);
    w3d_logic_type_80360a50.count--;
}

W3dLogic_80360a50 *w3d_logic_construct_800c4078(W3dLogic_80360a50 *object);
W3dLogic_80360a50 *w3d_logic_create_800c3fa4(void)
{
    W3dLogic_80360a50 *object = w3d_logic_construct_800c4078((W3dLogic_80360a50 *)w3d_heap_allocate_entry_a(36));
    w3d_state_register(&w3d_logic_type_80360a50, object ? &object->references : 0);
    w3d_logic_type_80360a50.count++;
    return object;
}

void w3d_logic_unlink_800c3f60(W3dLogic_80360a50 *object);
void w3d_logic_destroy_800c40c8(W3dLogic_80360a50 *object, int flags);
unsigned short w3d_logic_release_800c4004(W3dLogic_80360a50 *object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_logic_unlink_800c3f60(object);
        if (object)
            w3d_logic_destroy_800c40c8(object, 3);
    }
    return remaining;
}

unsigned short w3d_logic_retain_800c4060(W3dLogic_80360a50 *object)
{
    return object->references++;
}

W3dLogic_80360a50 *w3d_logic_construct_800c4078(W3dLogic_80360a50 *object)
{
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_vtable_8040f9e8;
    object->field_1c = 0;
    object->value = w3d_f32_8038346c[0];
    return object;
}

void w3d_logic_destroy_800c40c8(W3dLogic_80360a50 *object, int flags)
{
    object->vtable = w3d_vtable_8040f9e8;
    if (object->field_1c)
        object->field_1c->vtbl->release(object->field_1c);
    w3d_base_destroy_8015ff2c(object, flags);
}

void w3d_logic_hook_800c43a8(W3dLogic_80360a50 *object);
void w3d_logic_hook_800c44b0(W3dLogic_80360a50 *object);
int w3d_logic_handle_800c4128(W3dLogic_80360a50 *object, W3dGMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_actor_handle_8015fb34(object, message) >= 0) {
            w3d_logic_hook_800c43a8(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_logic_hook_800c44b0(object);
        break;
    }
    return w3d_actor_handle_8015fb34(object, message);
}

void w3d_logic_hook_800c43a8(W3dLogic_80360a50 *object)
{
    const char *sky;
    const char *water;
    const char *level;
    const char *water_resource;
    const char *offset_resource;
    const char *detail_resource;
    sky = w3d_str_8038349c;
    w3d_lookup_text_800fc550(&sky, w3d_str_803834b0);
    water = w3d_str_803834c0;
    w3d_lookup_text_800fc550(&water, w3d_str_803834d0);
    level = w3d_str_80383470;
    w3d_set_float_800fc4c8(&level, w3d_f32_8038356c[0]);
    water_resource = w3d_str_803834dc;
    w3d_lookup_text_800fc550(&water_resource, w3d_str_803834f0);
    offset_resource = w3d_str_80383504;
    w3d_lookup_text_800fc550(&offset_resource, w3d_str_80383520);
    detail_resource = w3d_str_80383538;
    w3d_lookup_text_800fc550(&detail_resource, w3d_str_80383554);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_80410680), object->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_8040fb28), object->owner);
}

void w3d_logic_hook_800c44b0(W3dLogic_80360a50 *object)
{
}

}
