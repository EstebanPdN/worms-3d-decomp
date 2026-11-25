/* Entity and service types from 0x80121754..0x80125460: TrailGraphicEntity,
 * TransitionService, TriggerGraphicEntity and one LogicEntity-derived type
 * (registry list 0x80361440).
 *
 * Names are inferred from behavior and from the type-name strings the static
 * initializers register; no original symbols survive. Each type keeps a global
 * registry list (u16 count at +0x22) and follows one shape: list getter,
 * unlink, create, release and retain on the u16 reference count at +4, a
 * constructor, a destructor that releases held interfaces (4-byte-entry vtable,
 * release slot +0x10) in reverse order, and a message handler for ids 64
 * (attach) and 66 (detach).
 */
extern "C" {

typedef struct W3dSharedList {
    unsigned char unknown_00[0x22];
    unsigned short count;
} W3dSharedList;

typedef struct W3dMessage {
    unsigned short id;
} W3dMessage;

typedef struct W3dInterface W3dInterface;

typedef struct W3dInterfaceTable {
    void *unknown_00[4];
    void (*release)(W3dInterface *object);
} W3dInterfaceTable;

struct W3dInterface {
    W3dInterfaceTable *vtable;
};

/* Engine string: one pointer to text behind a small header. */
typedef struct W3dString {
    char *data;
} W3dString;

/* Embedded handle member (constructed and destroyed out of line). */
typedef struct W3dMember {
    unsigned char unknown_00[4];
} W3dMember;

void *w3d_heap_allocate_entry_a(unsigned int size);
void w3d_owner_list_remove(W3dSharedList *list, void *link);
void w3d_state_register(W3dSharedList *list, void *link);
void w3d_string_base_finish(W3dString *string);
void w3d_string_release(W3dString *string);

extern const void *w3d_component_vtable_80410bd8[];
extern const void *w3d_trail_graphic_entity_vtable_80410b18[];
extern const void *w3d_transition_service_vtable_80410b58[];
extern const void *w3d_trigger_graphic_entity_vtable_80410b98[];
int w3d_base_handle_message_8015fb34(void *object, W3dMessage *message);
void w3d_actor_base_destroy(void *object, int flags);
void w3d_actor_handle_member_destroy(void *member, int flags);
void w3d_base_destroy_8015ff2c(void *object, int flags);
void w3d_base_destroy_801628ec(void *object, int flags);

typedef struct W3dVec3 {
    float x, y, z;
} W3dVec3;

typedef struct W3dSegment {
    W3dVec3 start;
    W3dVec3 end;
} W3dSegment;

/* Lazily resolved message name (identifier word, then the name text). */
typedef struct W3dCachedMessage {
    unsigned int value;
    const char *name;
} W3dCachedMessage;

/* Small posted message: identifier, then its vtable. */
typedef struct W3dPostedMessage {
    unsigned short id;
    unsigned short unknown_02;
    const void *vtable;
} W3dPostedMessage;

unsigned int w3d_cached_message_id(W3dCachedMessage *message, int force);
int w3d_message_post_current(void *message);
void *w3d_message_allocate_801613f0(void *arena, unsigned int size);
extern void *w3d_message_arena_804b1754;
extern const void *w3d_message_vtable_8040db38[];

/* ---- Wider interface table for graphic objects (slots observed by offset). ---- */
typedef struct W3dGraphic W3dGraphic;
typedef struct W3dGraphicTable {
    void *unknown_00[3];
    void (*add_ref)(W3dGraphic *object);
    void (*release)(W3dGraphic *object);
    void *unknown_14[14];
    void (*set_position_4c)(W3dGraphic *object, W3dVec3 *position, int flags);
    void *unknown_50;
    void (*set_scale_54)(W3dGraphic *object, W3dVec3 *scale, int flags);
} W3dGraphicTable;
struct W3dGraphic {
    W3dGraphicTable *vtable;
};


typedef struct W3dTrailGraphicEntity {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x20 - 0x6];
    W3dInterface * held_020;
    W3dInterface * held_024;
    unsigned char unknown_028[0x2c - 0x28];
    W3dInterface * held_02c;
    W3dInterface * held_030;
    W3dString name_034;
    W3dInterface * held_038;
    unsigned char unknown_03c[0x64 - 0x3c];
    W3dInterface * held_064;
    W3dInterface * held_068;
    int value_06c;
    unsigned char unknown_070[0x74 - 0x70];
    int flag_074;
    unsigned char unknown_078[0x7c - 0x78];
    int value_07c;
    unsigned char unknown_080[0x170 - 0x80];
    W3dInterface * held_170;
    unsigned char unknown_174[0x354 - 0x174];
    W3dSegment segments[20];
    int segment_used[20];
} W3dTrailGraphicEntity;
extern W3dSharedList w3d_trail_graphic_entity_list_803613b0;

typedef struct W3dTransitionService {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    W3dInterface * held_01c;
    int playing_020;
    W3dInterface * held_024;
    unsigned int in_count;
    unsigned int out_count;
    W3dInterface * held_030;
    W3dInterface * held_034;
    W3dInterface * held_038;
    int closing_03c;
} W3dTransitionService;
extern W3dSharedList w3d_transition_service_list_803613e0;

typedef struct W3dTriggerGraphicEntity {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x6];
    int owner_01c;
    W3dGraphic * held_020;
} W3dTriggerGraphicEntity;
extern W3dSharedList w3d_trigger_graphic_entity_list_80361410;

typedef struct W3dComponent_80124db8 {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x14 - 0x6];
    int handle_014;
    unsigned char unknown_018[0x1c - 0x18];
    W3dVec3 position;
    float radius;
    int target_02c;
    unsigned char unknown_030[0x38 - 0x30];
    int team_038;
    int worm_03c;
    unsigned char unknown_040[0x4c - 0x40];
    int disabled_04c;
    int disabled_050;
    int value_054;
    int triggered_058;
    W3dInterface * held_05c;
    W3dInterface * held_060;
    W3dMember member_064;
    unsigned char unknown_068[0x6c - 0x68];
    W3dInterface * held_06c;
    int value_070;
    int value_074;
} W3dComponent_80124db8;
extern W3dSharedList w3d_component_list_80361440;

/* TrailGraphicEntity: registry list 0x803613b0, 1460 bytes. */
W3dTrailGraphicEntity *w3d_trail_graphic_entity_construct_80121878(W3dTrailGraphicEntity *object);
void w3d_trail_graphic_entity_destroy_80121940(W3dTrailGraphicEntity *object, int flags);
void w3d_trail_graphic_entity_unlink_80121760(W3dTrailGraphicEntity *object);
void w3d_trail_graphic_entity_attach_801222b8(W3dTrailGraphicEntity *object);
void w3d_trail_graphic_entity_detach_80123e88(W3dTrailGraphicEntity *object);















/* TransitionService: registry list 0x803613e0, 64 bytes. */
W3dTransitionService *w3d_transition_service_construct_8012403c(W3dTransitionService *object);
void w3d_transition_service_destroy_80124100(W3dTransitionService *object, int flags);
void w3d_transition_service_unlink_80123f24(W3dTransitionService *object);













/* TriggerGraphicEntity: registry list 0x80361410, 36 bytes. */
W3dTriggerGraphicEntity *w3d_trigger_graphic_entity_construct_80124b24(W3dTriggerGraphicEntity *object);
void w3d_trigger_graphic_entity_destroy_80124b6c(W3dTriggerGraphicEntity *object, int flags);
void w3d_trigger_graphic_entity_unlink_80124a0c(W3dTriggerGraphicEntity *object);
void w3d_trigger_graphic_entity_attach_80124c5c(W3dTriggerGraphicEntity *object);
void w3d_trigger_graphic_entity_detach_80124d28(W3dTriggerGraphicEntity *object);















/* Component_80124db8: registry list 0x80361440, 120 bytes. */
W3dComponent_80124db8 *w3d_component_construct_80124edc(W3dComponent_80124db8 *object);
void w3d_component_destroy_80124f4c(W3dComponent_80124db8 *object, int flags);
void w3d_component_unlink_80124dc4(W3dComponent_80124db8 *object);














/* ---- Hand-recovered members ---- */

/* Inline reference holder: add_ref on construction, release on scope exit. */
typedef struct W3dRefTable {
    void *unknown_00[3];
    void (*add_ref)(W3dInterface *object);
    void (*release)(W3dInterface *object);
} W3dRefTable;

struct W3dRef {
    W3dInterface *p;
    W3dRef(W3dInterface *object) : p(object) { if (p) ((W3dRefTable *)p->vtable)->add_ref(p); }
    ~W3dRef() { if (p) ((W3dRefTable *)p->vtable)->release(p); }
};

extern W3dTrailGraphicEntity *w3d_trail_graphic_entity_current_804b186c;
extern W3dTransitionService *w3d_transition_service_instance_804ab044;
extern const char *w3d_transition_in_names_804ab048[2];
extern const char *w3d_transition_out_names_804ab050[2];
extern unsigned char w3d_interface_id_804144f8[];
extern W3dCachedMessage w3d_msg_804af4f0;
extern W3dCachedMessage w3d_msg_804af4f8;
extern W3dCachedMessage w3d_msg_804af500;
extern W3dCachedMessage w3d_msg_804af508;
extern W3dCachedMessage w3d_msg_804af518;
extern const float w3d_f32_8039b858[];
extern const float w3d_f32_8039b85c[];
extern const float w3d_f32_8039b860[];
extern const float w3d_f32_8039b864[];

W3dInterface *w3d_interface_lookup_8020b680(void *id);
void w3d_entity_attach_interface_80174820(void *object, W3dInterface *iface);
void w3d_service_construct_801628b0(void *object);
int w3d_service_handle_message_8016293c(void *object, W3dMessage *message);
int w3d_message_is_8015f620(W3dCachedMessage *message, unsigned short id);
void w3d_entity_finish_8015fd1c(void *object);
void w3d_service_subscribe_80162024(void *object, unsigned short *id, W3dInterface **slot);
unsigned int w3d_random_80162ba8(void);
void w3d_transition_play_80181640(W3dInterface *mesh, const char *name, int *handle, float a, float b, float c, int flags);
int w3d_transition_state_80181ccc(W3dInterface *mesh, int handle);
void w3d_transition_service_load_mesh_801247d0(W3dTransitionService *object);
void w3d_transition_service_update_8012458c(W3dTransitionService *object);
void w3d_transition_service_attach_801242e0(W3dTransitionService *object);
void w3d_transition_service_detach_801243b0(W3dTransitionService *object);
void w3d_base_construct_8015fef0(void *object);















void w3d_transition_service_circle_in_80124424(W3dTransitionService *object);
void w3d_transition_service_circle_out_801244d8(W3dTransitionService *object);

#if 0 /* 0x801241d0: the original copies the message id into a second register for the switch; not reproduced (6 attempts). */
int w3d_transition_service_handle_message_801241d0(W3dTransitionService *object, W3dMessage *message)
{
    unsigned short id = message->id;
    switch (message->id) {
    case 64:
        if (w3d_service_handle_message_8016293c(object, message) >= 0) {
            w3d_transition_service_attach_801242e0(object);
            return 0;
        }
        return 0x80004005;
    case 66:
        w3d_transition_service_detach_801243b0(object);
        break;
    default: {
        if (w3d_message_is_8015f620(&w3d_msg_804af4f8, id))
            w3d_transition_service_circle_in_80124424(object);
        else if (w3d_message_is_8015f620(&w3d_msg_804af4f0, id))
            w3d_transition_service_circle_out_801244d8(object);
        else if (w3d_message_is_8015f620(&w3d_msg_804af500, id))
            w3d_entity_finish_8015fd1c(object);
        break;
    }
    }
    return w3d_service_handle_message_8016293c(object, message);
}
#endif





















/* Local engine string: the original reserves an 8-byte stack slot. */
typedef struct W3dLocalString {
    W3dString s;
    int unknown_04;
} W3dLocalString;

W3dString *w3d_string_from_text(W3dString *string, const char *text);

/* C++ helpers matching the inlined constructor/destructor sequences. */
struct W3dTextName {
    W3dString s;
    int unknown_04;
    W3dTextName(const char *text) { w3d_string_from_text(&s, text); }
    ~W3dTextName() { w3d_string_base_finish(&s); w3d_string_release(&s); }
};

struct W3dVec3c {
    float x, y, z;
    W3dVec3c(float a, float b, float c) { x = a; y = b; z = c; }
};

typedef struct W3dGraphicRefTable {
    void *unknown_00[21];
    void (*set_scale_54)(W3dGraphic *object, const W3dVec3c &scale, int flags);
} W3dGraphicRefTable;

typedef void (*W3dSetNameRef)(const W3dTextName &name, void *resource, unsigned int flags);
#define w3d_handle_set_name_ref ((W3dSetNameRef)w3d_handle_set_name)

typedef struct W3dGameState {
    unsigned char unknown_00[0xb8];
    float fade_0b8;
} W3dGameState;

extern const char w3d_str_8039b868[];
extern const char w3d_str_8039b900[];
extern W3dGameState *w3d_game_state_804b1788;
extern const float w3d_f32_8039b878[];
extern const float w3d_f32_8039b87c[];
extern W3dCachedMessage w3d_msg_804af544;
extern W3dCachedMessage w3d_msg_804af54c;
extern W3dCachedMessage w3d_msg_804af554;
extern W3dCachedMessage w3d_msg_804af58c;

void w3d_handle_set_name(W3dString *name, void *resource, unsigned int flags);
W3dGraphic *w3d_empty_80343584(void *resource);
void *w3d_entity_lookup_80164fc8(int handle);
int w3d_message_is_8015f65c(unsigned short id, W3dCachedMessage *message);
int w3d_message_payload_int_800a830c(W3dMessage *message);
void *w3d_message_handle_init_801190b4(void *message, unsigned short id, int value);
void *w3d_message_string_init(void *message, unsigned short id, const char *text);
int w3d_game_paused_8006e71c(void);
void w3d_actor_base_initialize(void *object);
void w3d_actor_handle_member_initialize(void *member);
void *w3d_worm_data_800fc6dc(int worm);

#if 0 /* 0x801247d0: name-string temporary and vector address registers differ from the original (6 attempts). */
void w3d_transition_service_load_mesh_801247d0(W3dTransitionService *object)
{
    W3dInterface **slot = &object->held_01c;
    if (object->held_01c == 0) {
        W3dGraphic *mesh;
        float fade;
        {
            W3dTextName name(w3d_str_8039b868);
            w3d_handle_set_name_ref(name, slot, 34);
        }
        mesh = w3d_empty_80343584(object->held_01c);
        if (mesh)
            mesh->vtable->add_ref(mesh);
        if (object->held_024)
            object->held_024->vtable->release(object->held_024);
        object->held_024 = (W3dInterface *)mesh;
        fade = w3d_game_state_804b1788->fade_0b8;
        fade = fade * w3d_f32_8039b87c[0] + (w3d_f32_8039b878[0] - fade);
        ((W3dGraphicRefTable *)mesh->vtable)->set_scale_54(mesh, W3dVec3c(fade, fade, w3d_f32_8039b878[0]), 0);
    }
}
#endif

typedef struct W3dZoneView {
    unsigned char unknown_00[0x1c];
} W3dZoneView;

float *w3d_component_radius_801256e4(W3dComponent_80124db8 *object);
W3dVec3 *w3d_component_position_801256ec(W3dComponent_80124db8 *object);

#if 0 /* 0x80124c5c: the original recomputes the name-string address after its constructor call; not reproduced. */
void w3d_trigger_graphic_entity_attach_80124c5c(W3dTriggerGraphicEntity *object)
{
    W3dComponent_80124db8 *zone;
    {
        W3dTextName name = W3dTextName(w3d_str_8039b900);
        w3d_handle_set_name(&name.s, &object->held_020, 255);
    }
    zone = (W3dComponent_80124db8 *)w3d_entity_lookup_80164fc8(object->owner_01c);
    if (zone) {
        float radius = *w3d_component_radius_801256e4(zone);
        W3dVec3c scale(radius, radius, radius);
        object->held_020->vtable->set_scale_54(object->held_020, (W3dVec3 *)&scale, 0);
        object->held_020->vtable->set_position_4c(object->held_020, w3d_component_position_801256ec(zone), 0);
    }
}
#endif

#if 0 /* 0x80124edc: vtable store and member-address computation are scheduled in the opposite order (5 attempts). */
W3dComponent_80124db8 *w3d_component_construct_80124edc(W3dComponent_80124db8 *object)
{
    w3d_actor_base_initialize(object);
    object->vtable = w3d_component_vtable_80410bd8;
    object->held_05c = 0;
    object->held_060 = 0;
    w3d_actor_handle_member_initialize(&object->member_064);
    object->held_06c = 0;
    object->value_074 = -1;
    object->disabled_04c = 0;
    object->disabled_050 = 0;
    object->value_054 = 0;
    object->triggered_058 = 0;
    object->value_070 = 0;
    return object;
}
#endif

void w3d_component_attach_80125108(W3dComponent_80124db8 *object);
void w3d_component_detach_80125404(W3dComponent_80124db8 *object);
void w3d_component_on_target_8012545c(W3dComponent_80124db8 *object, W3dMessage *message);
void w3d_component_on_worm_moved_801256f4(W3dComponent_80124db8 *object, W3dMessage *message);
void w3d_component_update_80125934(W3dComponent_80124db8 *object);
int w3d_base_handle_message_8015fb34(void *object, W3dMessage *message);















typedef struct W3dWormEntity {
    unsigned char unknown_00[0x248];
    int worm_248;
} W3dWormEntity;

typedef struct W3dWormData {
    unsigned char unknown_00[0xd5];
    unsigned char team_0d5;
} W3dWormData;



/* ---- Message handling helpers from the first source file (0x8012028c..0x80121620). ---- */
typedef struct W3dClassInfo {
    unsigned char unknown_00[0x14];
    struct W3dClassInfo *parent;
} W3dClassInfo;

typedef struct W3dClassObject W3dClassObject;
typedef struct W3dClassObjectTable {
    void *unknown_00[5];
    W3dClassInfo *(*get_class)(W3dClassObject *object);
} W3dClassObjectTable;

struct W3dClassObject {
    W3dClassObjectTable *vtable;
    unsigned char unknown_04[0x248 - 0x4];
    int worm_248;
};

static inline int w3d_class_is_a(W3dClassInfo *info, W3dClassInfo *target)
{
    while (info != target) {
        if (info == info->parent)
            return 0;
        info = info->parent;
    }
    return 1;
}

typedef struct W3dInputOwner {
    unsigned char unknown_00[0x4c];
    int target_04c;
} W3dInputOwner;

typedef struct W3dCamera {
    unsigned char unknown_00[0x334];
    float blend_334;
} W3dCamera;

extern W3dClassInfo w3d_worm_class_803615f0;
extern W3dCachedMessage w3d_msg_804af4cc;
extern W3dCachedMessage w3d_msg_804af4dc;
extern W3dCachedMessage w3d_msg_804af4e4;
extern void *w3d_input_state_804ab400;
extern W3dCamera *w3d_camera_804aa8c8;
extern const char w3d_str_8039b6a4[];
extern const char w3d_str_8039b6ac[];
extern const float w3d_f32_8039b6c0[];
extern W3dVec3 w3d_vec3_zero_8043ae20;

int w3d_input_active_80158dd4(void *state);
int w3d_entity_has_focus_8015abcc(void *object);
void w3d_camera_set_mode_80035714(W3dCamera *camera, const char *mode, float blend);
void w3d_payload_get_int_800fc230(const char **key, int *value);
int w3d_entity_get_point_8015ac04(void *object, void *key, W3dVec3 *out);
void *w3d_message_int_init(void *message, unsigned short id, int value);







}

extern "C" {
extern __typeof__(w3d_interface_lookup_8020b680) fn_8020b680;
extern __typeof__(w3d_entity_attach_interface_80174820) fn_80174820;
extern __typeof__(w3d_interface_id_804144f8) lbl_804144f8;
}

extern "C" {
int s8_transplant_800bea4c(void *object)
{
    W3dRef ref(fn_8020b680(lbl_804144f8));
    fn_80174820(object, ref.p);
    return 0;
}
}
