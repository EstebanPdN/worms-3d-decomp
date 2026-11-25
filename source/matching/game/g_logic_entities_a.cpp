/* Script-driven logic entities around the low-gravity utility (0x800c1620..0x800c2404).
 *
 * Names are inferred from behavior; no original symbols survive. Each logic
 * class keeps its live instances in a global type record (0x80360990,
 * 0x803609c0, 0x803609f0) whose u16 instance count sits at +0x22; instances
 * are linked through their u16 reference count at +0x04. The two base classes
 * seen here are the actor base (0x80161014 / 0x80161050, message handler
 * 0x8015fb34) and the logic base (0x801628b0 / 0x801628ec, handler 0x8016293c).
 * Message 64 attaches an entity and message 66 detaches it.
 */
#include "g_types.h"

/* Counted interface held by value: retains on construction, releases on exit. */
struct W3dGRef {
    W3dGIface *object;
    W3dGRef(W3dGIface *pointer) : object(pointer)
    {
        if (object)
            object->vtbl->retain(object);
    }
    ~W3dGRef()
    {
        if (object)
            object->vtbl->release(object);
    }
};

/* Counted interface slot inside another object. */
struct W3dGRefSlot {
    W3dGIface *object;
    W3dGRefSlot &operator=(const W3dGRef &other)
    {
        W3dGIface *pointer = other.object;
        if (pointer)
            pointer->vtbl->retain(pointer);
        if (object)
            object->vtbl->release(object);
        object = pointer;
        return *this;
    }
};

/* Position value built from three floats. */
struct W3dGPoint {
    float x, y, z;
    W3dGPoint() {}
    W3dGPoint(float px, float py, float pz) : x(px), y(py), z(pz) {}
    W3dGPoint(const W3dGVec3 &v) : x(v.x), y(v.y), z(v.z) {}
};

extern "C" {

typedef struct W3dLogicType {
    unsigned char unknown_00[0x22];
    unsigned short count;
} W3dLogicType;

typedef struct W3dLogicEntity {
    void *vtable;
    unsigned short references;
    unsigned char unknown_06[0x1c - 0x06];
    W3dGIface *held_1c;
    W3dGIface *held_20;
    int active;
    int owner;
} W3dLogicEntity;

typedef struct W3dLogicEntityB {
    void *vtable;
    unsigned short references;
    unsigned char unknown_06[0x14 - 0x06];
    int owner;
    unsigned char unknown_18[0x1c - 0x18];
    W3dGIface *held_1c;
    W3dGIface *held_20;
    W3dGIface *held_24;
} W3dLogicEntityB;

typedef struct W3dLogicEntityC {
    void *vtable;
    unsigned short references;
    unsigned char unknown_06[0x1c - 0x06];
    W3dGIface *held_1c;
} W3dLogicEntityC;

typedef struct W3dGameState {
    unsigned char unknown_00[0x90];
    W3dGRefSlot current;
} W3dGameState;

typedef struct W3dPositioned {
    unsigned char unknown_00[0x230];
    W3dGVec3 position;
} W3dPositioned;

typedef struct W3dValueMessage {
    unsigned short id;
    void *vtable;
    int value;
} W3dValueMessage;

typedef struct W3dPlainMessage {
    unsigned short id;
    void *vtable;
} W3dPlainMessage;

extern W3dLogicType w3d_logic_type_80360990;
extern W3dLogicType w3d_logic_type_803609c0;
extern W3dLogicType w3d_logic_type_803609f0;
extern unsigned char w3d_vtable_8040db38[];
extern unsigned char w3d_vtable_8040f8e8[];
extern unsigned char w3d_vtable_8040f928[];
extern unsigned char w3d_vtable_8040f968[];
extern W3dGCachedMessage w3d_message_created_804ae678;
extern W3dGCachedMessage w3d_message_weapon_delete_804ae684;
extern W3dGCachedMessage w3d_message_fire_pressed_804ae68c;
extern W3dLogicEntityB *w3d_logic_b_instance_804aadcc;

void w3d_state_register(W3dLogicType *type, void *link);
void w3d_owner_list_remove(W3dLogicType *type, void *link);
int w3d_actor_base_initialize(void *object);
void w3d_actor_base_destroy(void *object, int flags);
int w3d_logic_base_init_801628b0(void *object);
void w3d_logic_base_destroy_801628ec(void *object, int flags);
int w3d_actor_handle_8015fb34(void *object, W3dGMessage *message);
int w3d_logic_base_handle_8016293c(void *object, W3dGMessage *message);
int w3d_message_matches_8015f65c(unsigned int id, W3dGCachedMessage *message);
void w3d_actor_remove_8015fd1c(void *object);
int w3d_actor_subscribe_80162024(void *object, unsigned short *id, void *slot);
void w3d_low_gravity_activate_800c1a14(W3dLogicEntity *entity);
void w3d_logic_b_attach_800c1f00(W3dLogicEntityB *entity);
W3dGIface *w3d_class_create_8020b680(void *type);
int w3d_object_add_80161dd4(W3dGIface *object, void *data);
int w3d_fn_8015f618(void);
int w3d_registry_add_80164514(void *registry, W3dGIface *object, int owner);
void w3d_game_refresh_80126884(W3dGameState *game);
W3dPositioned *w3d_actor_lookup_80164fc8(int owner);
void *w3d_message_allocate_801613f0(void *storage, unsigned int size);
void *w3d_int_message_init_80125fdc(void *message, unsigned short id, int value);
void w3d_lookup_float_800fc270(const char **name, float *value);
void w3d_set_float_800fc4c8(const char **name, float value);
void w3d_spawn_effect_800e5ca4(const W3dGPoint &position, const char *name, float scale, int flags);

extern W3dGameState *w3d_game_804b1788;
extern void *w3d_registry_804b178c;
extern void *w3d_message_storage_804b1754;
extern W3dGCachedMessage w3d_message_decrement_inventory_804ae694;
extern const float w3d_f32_8038308c[];
extern const float w3d_f32_80383090[];
extern const char w3d_str_8038304c[];
extern const char w3d_str_80383060[];
extern const char w3d_str_80383078[];
extern unsigned char w3d_class_804117b8[];
extern unsigned char w3d_data_803f4cc4[];
extern unsigned char w3d_data_80402008[];
extern unsigned char w3d_data_80403fd4[];
extern unsigned char w3d_data_80400784[];
extern unsigned char w3d_class_8041bfc0[];
extern unsigned char w3d_class_80410b48[];
extern unsigned char w3d_class_8040f618[];
extern unsigned char w3d_class_8040ef88[];
extern unsigned char w3d_class_80410510[];
extern unsigned char w3d_class_8040dde8[];
extern unsigned char w3d_class_8041bd10[];
extern unsigned char w3d_class_80410470[];
extern unsigned char w3d_class_8041beb0[];
extern unsigned char w3d_class_8041c040[];
extern unsigned char w3d_class_8041c000[];

W3dValueMessage *w3d_created_message_init_800c1620(W3dValueMessage *message, int *value)
{
    message->id = w3d_cached_message_id(&w3d_message_created_804ae678, 1);
    message->vtable = w3d_vtable_8040db38;
    message->value = *value;
    return message;
}

W3dLogicType *w3d_low_gravity_type_800c16e4(void)
{
    return &w3d_logic_type_80360990;
}

void w3d_low_gravity_unlink_800c16f0(W3dLogicEntity *entity)
{
    w3d_owner_list_remove(&w3d_logic_type_80360990, &entity->references);
    w3d_logic_type_80360990.count--;
}

W3dLogicEntity *w3d_low_gravity_construct_800c1808(W3dLogicEntity *entity);
void w3d_low_gravity_destroy_800c1858(W3dLogicEntity *entity, int flags);

W3dLogicEntity *w3d_low_gravity_create_800c1734(void)
{
    W3dLogicEntity *entity = w3d_low_gravity_construct_800c1808((W3dLogicEntity *)w3d_heap_allocate_entry_a(44));
    w3d_state_register(&w3d_logic_type_80360990, entity ? &entity->references : 0);
    w3d_logic_type_80360990.count++;
    return entity;
}

unsigned short w3d_low_gravity_release_800c1794(W3dLogicEntity *entity)
{
    unsigned short remaining = --entity->references;
    if (remaining == 0) {
        w3d_low_gravity_unlink_800c16f0(entity);
        if (entity)
            w3d_low_gravity_destroy_800c1858(entity, 3);
    }
    return remaining;
}

unsigned short w3d_low_gravity_retain_800c17f0(W3dLogicEntity *entity)
{
    return entity->references++;
}

W3dLogicEntity *w3d_low_gravity_construct_800c1808(W3dLogicEntity *entity)
{
    w3d_actor_base_initialize(entity);
    entity->vtable = w3d_vtable_8040f8e8;
    entity->held_1c = 0;
    entity->held_20 = 0;
    entity->active = 0;
    entity->owner = 0;
    return entity;
}

void w3d_low_gravity_destroy_800c1858(W3dLogicEntity *entity, int flags)
{
    entity->vtable = w3d_vtable_8040f8e8;
    if (entity->held_20)
        entity->held_20->vtbl->release(entity->held_20);
    if (entity->held_1c)
        entity->held_1c->vtbl->release(entity->held_1c);
    w3d_actor_base_destroy(entity, flags);
}

void w3d_low_gravity_subscribe_800c19a8(W3dLogicEntity *entity);
void w3d_low_gravity_detach_800c1a10(W3dLogicEntity *entity);

int w3d_low_gravity_handle_800c18d4(W3dLogicEntity *entity, W3dGMessage *message)
{
    unsigned short id = message->id;
    switch (id) {
    case 64:
        if (w3d_actor_handle_8015fb34(entity, message) >= 0) {
            w3d_low_gravity_subscribe_800c19a8(entity);
            break;
        }
        return 0x80004005;
    case 66:
        w3d_low_gravity_detach_800c1a10(entity);
        return w3d_actor_handle_8015fb34(entity, message);
    default:
        if (w3d_message_matches_8015f65c(id, &w3d_message_weapon_delete_804ae684))
            w3d_actor_remove_8015fd1c(entity);
        else if (w3d_message_matches_8015f65c(id, &w3d_message_fire_pressed_804ae68c))
            w3d_low_gravity_activate_800c1a14(entity);
        else
            return w3d_actor_handle_8015fb34(entity, message);
        break;
    }
    return 0;
}

int w3d_low_gravity_kind_800c19a0(void)
{
    return -1;
}

void w3d_low_gravity_subscribe_800c19a8(W3dLogicEntity *entity)
{
    unsigned short delete_id;
    unsigned short fire_id;
    delete_id = w3d_cached_message_id(&w3d_message_weapon_delete_804ae684, 1);
    w3d_actor_subscribe_80162024(entity, &delete_id, &entity->held_1c);
    fire_id = w3d_cached_message_id(&w3d_message_fire_pressed_804ae68c, 1);
    w3d_actor_subscribe_80162024(entity, &fire_id, &entity->held_20);
}

void w3d_low_gravity_detach_800c1a10(W3dLogicEntity *entity)
{
}

W3dGPoint w3d_low_gravity_position_800c1b20(W3dLogicEntity *entity);

#if 0 /* 0x800c1a14: two scheduling swaps remain (value store vs &name, and the r3/r4 argument order of the effect call). */
void w3d_low_gravity_activate_800c1a14(W3dLogicEntity *entity)
{
    if (entity->active == 0) {
        const char *on_name;
        float value;
        const char *multiplier_name;
        W3dPlainMessage *removed;
        void *decrement;
        entity->active = 1;
        on_name = w3d_str_8038304c;
        value = w3d_f32_8038308c[0];
        w3d_lookup_float_800fc270(&on_name, &value);
        multiplier_name = w3d_str_80383060;
        w3d_set_float_800fc4c8(&multiplier_name, value);
        removed = (W3dPlainMessage *)w3d_message_allocate_801613f0(w3d_message_storage_804b1754, 8);
        removed->id = w3d_cached_message_id(&w3d_message_weapon_delete_804ae684, 1);
        removed->vtable = w3d_vtable_8040db38;
        w3d_message_post_current(removed);
        decrement = w3d_message_allocate_801613f0(w3d_message_storage_804b1754, 12);
        w3d_message_post_current(w3d_int_message_init_80125fdc(decrement,
            w3d_cached_message_id(&w3d_message_decrement_inventory_804ae694, 1), 44));
        w3d_spawn_effect_800e5ca4(w3d_low_gravity_position_800c1b20(entity), w3d_str_80383078, w3d_f32_80383090[0], 0);
        w3d_actor_remove_8015fd1c(entity);
    }
}

#endif

W3dGPoint w3d_low_gravity_position_800c1b20(W3dLogicEntity *entity)
{
    W3dGVec3 position = w3d_actor_lookup_80164fc8(entity->owner)->position;
    return W3dGPoint(position);
}

W3dLogicType *w3d_logic_b_type_800c1c5c(void)
{
    return &w3d_logic_type_803609c0;
}

void w3d_logic_b_unlink_800c1c68(W3dLogicEntityB *entity)
{
    w3d_owner_list_remove(&w3d_logic_type_803609c0, &entity->references);
    w3d_logic_type_803609c0.count--;
}

W3dLogicEntityB *w3d_logic_b_construct_800c1d80(W3dLogicEntityB *entity);
void w3d_logic_b_destroy_800c1dd0(W3dLogicEntityB *entity, int flags);

W3dLogicEntityB *w3d_logic_b_create_800c1cac(void)
{
    W3dLogicEntityB *entity = w3d_logic_b_construct_800c1d80((W3dLogicEntityB *)w3d_heap_allocate_entry_a(40));
    w3d_state_register(&w3d_logic_type_803609c0, entity ? &entity->references : 0);
    w3d_logic_type_803609c0.count++;
    return entity;
}

unsigned short w3d_logic_b_release_800c1d0c(W3dLogicEntityB *entity)
{
    unsigned short remaining = --entity->references;
    if (remaining == 0) {
        w3d_logic_b_unlink_800c1c68(entity);
        if (entity)
            w3d_logic_b_destroy_800c1dd0(entity, 3);
    }
    return remaining;
}

unsigned short w3d_logic_b_retain_800c1d68(W3dLogicEntityB *entity)
{
    return entity->references++;
}

W3dLogicEntityB *w3d_logic_b_construct_800c1d80(W3dLogicEntityB *entity)
{
    w3d_actor_base_initialize(entity);
    entity->vtable = w3d_vtable_8040f928;
    entity->held_1c = 0;
    entity->held_20 = 0;
    entity->held_24 = 0;
    w3d_logic_b_instance_804aadcc = entity;
    return entity;
}

void w3d_logic_b_destroy_800c1dd0(W3dLogicEntityB *entity, int flags)
{
    entity->vtable = w3d_vtable_8040f928;
    w3d_logic_b_instance_804aadcc = 0;
    if (entity->held_24)
        entity->held_24->vtbl->release(entity->held_24);
    if (entity->held_20)
        entity->held_20->vtbl->release(entity->held_20);
    if (entity->held_1c)
        entity->held_1c->vtbl->release(entity->held_1c);
    w3d_actor_base_destroy(entity, flags);
}

void w3d_logic_b_detach_800c2140(W3dLogicEntityB *entity);

int w3d_logic_b_handle_800c1e70(W3dLogicEntityB *entity, W3dGMessage *message)
{
    switch (message->id) {
    case 64:
        if (w3d_actor_handle_8015fb34(entity, message) >= 0) {
            w3d_logic_b_attach_800c1f00(entity);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_logic_b_detach_800c2140(entity);
        break;
    }
    return w3d_actor_handle_8015fb34(entity, message);
}

int w3d_logic_b_kind_800c1ef8(void)
{
    return -1;
}

}

static inline void w3d_registry_add(W3dGIface *object, int owner)
{
    w3d_registry_add_80164514(w3d_registry_804b178c, object, owner);
}

extern "C" {

void w3d_logic_b_attach_800c1f00(W3dLogicEntityB *entity)
{
    W3dGRef object(w3d_class_create_8020b680(w3d_class_804117b8));
    w3d_object_add_80161dd4(object.object, w3d_data_803f4cc4);
    w3d_object_add_80161dd4(object.object, w3d_data_80402008);
    w3d_object_add_80161dd4(object.object, w3d_data_80403fd4);
    w3d_object_add_80161dd4(object.object, w3d_data_80400784);
    w3d_fn_8015f618();
    w3d_game_804b1788->current = object;
    w3d_registry_add_80164514(w3d_registry_804b178c, object.object, entity->owner);
    w3d_game_refresh_80126884(w3d_game_804b1788);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_8041bfc0), entity->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_80410b48), entity->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_8040f618), entity->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_8040ef88), entity->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_80410510), entity->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_8040dde8), entity->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_8041bd10), entity->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_80410470), entity->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_8041beb0), entity->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_8041c040), entity->owner);
    w3d_registry_add(w3d_class_create_8020b680(w3d_class_8041c000), entity->owner);
}

void w3d_logic_b_detach_800c2140(W3dLogicEntityB *entity)
{
}

W3dLogicType *w3d_logic_c_type_800c21d0(void)
{
    return &w3d_logic_type_803609f0;
}

void w3d_logic_c_unlink_800c21dc(W3dLogicEntityC *entity)
{
    w3d_owner_list_remove(&w3d_logic_type_803609f0, &entity->references);
    w3d_logic_type_803609f0.count--;
}

W3dLogicEntityC *w3d_logic_c_construct_800c22f4(W3dLogicEntityC *entity);
void w3d_logic_c_destroy_800c2338(W3dLogicEntityC *entity, int flags);

W3dLogicEntityC *w3d_logic_c_create_800c2220(void)
{
    W3dLogicEntityC *entity = w3d_logic_c_construct_800c22f4((W3dLogicEntityC *)w3d_heap_allocate_entry_a(32));
    w3d_state_register(&w3d_logic_type_803609f0, entity ? &entity->references : 0);
    w3d_logic_type_803609f0.count++;
    return entity;
}

unsigned short w3d_logic_c_release_800c2280(W3dLogicEntityC *entity)
{
    unsigned short remaining = --entity->references;
    if (remaining == 0) {
        w3d_logic_c_unlink_800c21dc(entity);
        if (entity)
            w3d_logic_c_destroy_800c2338(entity, 3);
    }
    return remaining;
}

unsigned short w3d_logic_c_retain_800c22dc(W3dLogicEntityC *entity)
{
    return entity->references++;
}

W3dLogicEntityC *w3d_logic_c_construct_800c22f4(W3dLogicEntityC *entity)
{
    w3d_logic_base_init_801628b0(entity);
    entity->vtable = w3d_vtable_8040f968;
    entity->held_1c = 0;
    return entity;
}

void w3d_logic_c_destroy_800c2338(W3dLogicEntityC *entity, int flags)
{
    entity->vtable = w3d_vtable_8040f968;
    if (entity->held_1c)
        entity->held_1c->vtbl->release(entity->held_1c);
    w3d_logic_base_destroy_801628ec(entity, flags);
}

void w3d_logic_c_attach_800c2404(W3dLogicEntityC *entity);

int w3d_logic_c_handle_800c2398(W3dLogicEntityC *entity, W3dGMessage *message)
{
    if (message->id == 64) {
        if (w3d_logic_base_handle_8016293c(entity, message) >= 0) {
            w3d_logic_c_attach_800c2404(entity);
            return 0;
        }
        return 0x80004005;
    }
    return w3d_logic_base_handle_8016293c(entity, message);
}

int w3d_logic_c_kind_800c23fc(void)
{
    return -1;
}

void w3d_logic_c_attach_800c2404(W3dLogicEntityC *entity)
{
}

}
