/* Small component accessors and helpers (0x800609ec..0x8006bcd0).
 *
 * Names are inferred from behavior; no original symbols survive. These are
 * short methods of the component types in this range: field getters and
 * setters, vector copies, thin forwarding wrappers and flag toggles. Layouts
 * are given per function group because the owning types differ; only the
 * offsets each function touches are described. The game context pointer at
 * 0x804b1788 keeps a flag word at +0x4c.
 */
extern "C" {

typedef struct W3dVec3 {
    float x;
    float y;
    float z;
} W3dVec3;

typedef struct W3dWordVec3 {
    int x;
    int y;
    int z;
} W3dWordVec3;

typedef struct W3dOwnerSlot {
    unsigned char unknown_00[0x44];
    void *owned;
} W3dOwnerSlot;

typedef struct W3dLazyState {
    unsigned char unknown_00[0x44];
    int ready;
} W3dLazyState;

typedef struct W3dTimedState {
    unsigned char unknown_00[0x24];
    void *resource;
    unsigned char unknown_28[0x38 - 0x28];
    int mode;
    unsigned char unknown_3c[0x54 - 0x3c];
    float rate;
    unsigned char unknown_58[0x78 - 0x58];
    int frame_time;
} W3dTimedState;

typedef struct W3dMotionPair {
    unsigned char unknown_00[0x08];
    W3dVec3 position;
    W3dVec3 velocity;
    float value_20;
    float value_24;
    float value_28;
    float value_2c;
    float value_30;
} W3dMotionPair;

typedef struct W3dPlacement {
    unsigned char unknown_00[0x1c];
    W3dWordVec3 offset;
    W3dWordVec3 target;
    W3dWordVec3 extra;
} W3dPlacement;

typedef struct W3dValueRange {
    short id;
    unsigned char unknown_02[2];
    const void *vtable;
    float low;
    float high;
} W3dValueRange;

typedef struct W3dStampPair {
    unsigned char unknown_00[0x54];
    int stamp_a;
    int stamp_b;
} W3dStampPair;

typedef struct W3dEngineContext {
    unsigned char unknown_00[0x34];
    int frame_time;
} W3dEngineContext;

typedef struct W3dGameContext {
    unsigned char unknown_00[0x4c];
    unsigned int flags;
} W3dGameContext;

extern int w3d_stamp_a_804b17ac;
extern int w3d_stamp_b_804b17a8;
extern const void *w3d_value_range_vtable_8040db38[];
extern void *w3d_slot_table_8042e700[];
extern W3dGameContext *w3d_game_context_804b1788;

void w3d_owned_release_800e5bb8(void *owned);
void w3d_component_step_800ed090(void *object);
void w3d_lazy_state_prepare_8015fd1c(void *object);
void w3d_component_refresh_80064c6c(void *object, void *);
void *w3d_empty_80343580(void *resource);
int w3d_resource_set_mode_8018c5b0(void *resource, int mode);
void w3d_timed_state_apply_800642ac(W3dTimedState *state);
int w3d_component_step_80066068(void *object);
W3dEngineContext *w3d_engine_get_context(void);
void *w3d_session_current_800c8120(void);
void w3d_session_attach_800c70e4(void *session, int object);
void w3d_session_set_paused_800c7cd0(void *session, int paused);
void w3d_pause_prepare_800fde38(void);

void w3d_owner_slot_assign_800609ec(W3dOwnerSlot *slot, void *owned)
{
    if (slot->owned)
        w3d_owned_release_800e5bb8(slot->owned);
    slot->owned = owned;
}

void w3d_component_step_80061684(void *object)
{
    w3d_component_step_800ed090(object);
}

void w3d_lazy_state_ensure_80062614(W3dLazyState *state)
{
    if (state->ready == 0)
        w3d_lazy_state_prepare_8015fd1c(state);
}

int w3d_component_refresh_800639e8(void *object, void * arg_r4)
{
    w3d_component_refresh_80064c6c(object, arg_r4);
    return 0;
}

void w3d_timed_state_set_mode_80064190(W3dTimedState *state, int mode)
{
    state->mode = mode;
}

void w3d_timed_state_resource_mode_80064274(W3dTimedState *state, int mode)
{
    w3d_resource_set_mode_8018c5b0(w3d_empty_80343580(state->resource), mode);
}

void w3d_timed_state_set_rate_80064548(W3dTimedState *state, float rate)
{
    state->rate = rate;
    w3d_timed_state_apply_800642ac(state);
}

void w3d_component_step_80065ff0(void *object)
{
    w3d_component_step_80066068(object);
}

void w3d_timed_state_stamp_800664c4(W3dTimedState *state)
{
    state->frame_time = w3d_engine_get_context()->frame_time;
}

W3dVec3 *w3d_motion_get_position_80066894(W3dVec3 *out, W3dMotionPair *motion)
{
    const W3dVec3 *source = &motion->position;
    float x = source->x, y = source->y, z = source->z;
    out->x = x;
    out->y = y;
    out->z = z;
    return out;
}

W3dVec3 *w3d_motion_get_velocity_800668b8(W3dVec3 *out, W3dMotionPair *motion)
{
    const W3dVec3 *source = &motion->velocity;
    float x = source->x, y = source->y, z = source->z;
    out->x = x;
    out->y = y;
    out->z = z;
    return out;
}

float w3d_motion_get_30_800668dc(W3dMotionPair *motion)
{
    return motion->value_30;
}

float w3d_motion_get_28_800668e4(W3dMotionPair *motion)
{
    return motion->value_28;
}

float w3d_motion_get_2c_800668ec(W3dMotionPair *motion)
{
    return motion->value_2c;
}

float w3d_motion_get_20_800668f4(W3dMotionPair *motion)
{
    return motion->value_20;
}

float w3d_motion_get_24_800668fc(W3dMotionPair *motion)
{
    return motion->value_24;
}

void w3d_placement_set_target_80067268(W3dPlacement *placement, const W3dWordVec3 *target)
{
    placement->target = *target;
}

void w3d_placement_set_offset_80067288(W3dPlacement *placement, const W3dWordVec3 *offset)
{
    placement->offset = *offset;
}

W3dWordVec3 *w3d_placement_target_800672a8(W3dPlacement *placement)
{
    return &placement->target;
}

W3dWordVec3 *w3d_placement_offset_800672b0(W3dPlacement *placement)
{
    return &placement->offset;
}

W3dWordVec3 *w3d_placement_extra_800672b8(W3dPlacement *placement)
{
    return &placement->extra;
}

void w3d_empty_800672c0(void)
{
}

void w3d_stamp_pair_capture_80067510(W3dStampPair *state)
{
    state->stamp_a = w3d_stamp_a_804b17ac;
    state->stamp_b = w3d_stamp_b_804b17a8;
}

int w3d_return_minus_one_800681cc(void)
{
    return -1;
}

void w3d_empty_8006823c(void)
{
}

float w3d_value_range_low_80069a28(W3dValueRange *range)
{
    return range->low;
}

W3dValueRange *w3d_value_range_init_80069a30(W3dValueRange *range, short id, float low, float high)
{
    W3dValueRange *self = range;
    self->id = id;
    self->vtable = w3d_value_range_vtable_8040db38;
    self->low = low;
    self->high = high;
    return self;
}

void w3d_value_range_get_80069a50(W3dValueRange *range, float *low, float *high)
{
    *low = range->low;
    *high = range->high;
}

void w3d_session_attach_80069be0(void *object)
{
    w3d_session_attach_800c70e4(w3d_session_current_800c8120(), (int)object);
}

void w3d_session_pause_80069c14(void)
{
    w3d_pause_prepare_800fde38();
    w3d_session_set_paused_800c7cd0(w3d_session_current_800c8120(), 1);
    w3d_game_context_804b1788->flags = (w3d_game_context_804b1788->flags | 0x20000000) & ~0x40000000;
}

void w3d_session_resume_80069c54(void)
{
    w3d_session_set_paused_800c7cd0(w3d_session_current_800c8120(), 0);
    w3d_game_context_804b1788->flags &= ~0x20000000;
}

void *w3d_slot_table_get_8006bcd0(int index)
{
    return w3d_slot_table_8042e700[index];
}

}
