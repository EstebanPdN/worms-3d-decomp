#include "w3d_ptr.h"
#line 1 "s8transplantcpp_800d1104.cpp"
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
    Ptr32<void> owned;
} W3dOwnerSlot;

typedef struct W3dLazyState {
    unsigned char unknown_00[0x44];
    int ready;
} W3dLazyState;

typedef struct W3dTimedState {
    unsigned char unknown_00[0x24];
    Ptr32<void> resource;
    unsigned char unknown_28[0x38 - 0x28];
    int mode;
    unsigned char unknown_3c[0x54 - 0x3c];
    float rate;
    unsigned char unknown_58[0x78 - 0x58];
    int frame_time;
} W3dTimedState;

typedef struct W3dMotionPair {
    unsigned char unknown_00[0x114];
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
    Ptr32<const void> vtable;
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
extern Ptr32<const void> w3d_value_range_vtable_8040db38[];
extern Ptr32<void> w3d_slot_table_8042e700[];
extern Ptr32<W3dGameContext> w3d_game_context_804b1788;

void w3d_owned_release_800e5bb8(Ptr32<void> owned);
void w3d_component_step_800ed090(Ptr32<void> object);
void w3d_lazy_state_prepare_8015fd1c(Ptr32<void> object);
void w3d_component_refresh_80064c6c(Ptr32<void> object);
Ptr32<void> w3d_empty_80343580(Ptr32<void> resource);
void w3d_resource_set_mode_8018c5b0(Ptr32<void> resource, int mode);
void w3d_timed_state_apply_800642ac(Ptr32<W3dTimedState> state);
void w3d_component_step_80066068(Ptr32<void> object);
Ptr32<W3dEngineContext> w3d_engine_get_context(void);
Ptr32<void> w3d_session_current_800c8120(void);
void w3d_session_attach_800c70e4(Ptr32<void> session, Ptr32<void> object);
void w3d_session_set_paused_800c7cd0(Ptr32<void> session, int paused);
void w3d_pause_prepare_800fde38(void);

































































}

extern "C" {

}

extern "C" {
Ptr32<W3dVec3> s8_transplant_800d1104(Ptr32<W3dVec3> out, Ptr32<W3dMotionPair> motion)
{
    Ptr32<const W3dVec3> source = &motion->position;
    float x = source->x, y = source->y, z = source->z;
    out->x = x;
    out->y = y;
    out->z = z;
    return out;
}
}


