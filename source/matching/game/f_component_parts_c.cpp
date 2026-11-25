/* Hand-lifted component constructors (0x80062c24..0x800bffb4).
 *
 * Names are inferred from behavior; no original symbols survive. These are
 * constructors of the shared component types whose bodies do more than
 * clear fields: they derive float defaults from the game context, clear
 * embedded three-word records through a member pointer, or publish the new
 * object in a small-data instance pointer. Float constants are read from the
 * original .rodata through extern arrays.
 */
extern "C" {

typedef struct W3dWordVec3 {
    int x;
    int y;
    int z;
} W3dWordVec3;

typedef struct W3dGameContext {
    unsigned char unknown_00[0xb8];
    float level;
} W3dGameContext;

/* Type registered at 0x80062b00: blend weights derived from the context level. */
typedef struct W3dBlendComponent {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x06];
    void *held_01c;
    unsigned char unknown_020[0x28 - 0x20];
    void *held_028;
    void *held_02c;
    void *held_030;
    void *held_034;
    unsigned char unknown_038[0x40 - 0x38];
    float weight_a;
    float weight_b;
    float weight_c;
} W3dBlendComponent;

/* Type registered at 0x80098a94: publishes itself while alive. */
typedef struct W3dSingletonComponent {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x06];
    void *held_01c;
    unsigned char unknown_020[0x24 - 0x20];
    void *held_024;
    void *held_028;
    unsigned char unknown_02c[0x38 - 0x2c];
    void *held_038;
    int selected;
    W3dWordVec3 cursor;
    int limit;
} W3dSingletonComponent;

extern W3dGameContext *w3d_game_context_804b1788;
extern const float w3d_f32_80379b00[];
extern const float w3d_f32_80379b04[];
extern const float w3d_f32_80379b08[];
extern const float w3d_f32_80379b0c[];
extern const float w3d_f32_80379b10[];
extern const void *w3d_component_vtable_8040ed80[];
extern const void *w3d_component_vtable_8040f310[];
extern void *w3d_component_instance_804aabd4;

void w3d_base_construct_8015fef0(void *object);
void w3d_base_construct_801628b0(void *object);

W3dBlendComponent *w3d_component_construct_80062c24(W3dBlendComponent *object)
{
    W3dGameContext *context;
    float level;
    float rest;
    float weight;
    w3d_base_construct_8015fef0(object);
    context = w3d_game_context_804b1788;
    object->vtable = w3d_component_vtable_8040ed80;    object->held_01c = 0;    object->held_028 = 0;    object->held_02c = 0;    object->held_030 = 0;    object->held_034 = 0;    level = context->level;
    rest = w3d_f32_80379b00[0] - level;
    weight = level * w3d_f32_80379b0c[0] + rest * w3d_f32_80379b10[0];
    object->weight_b = weight;
    object->weight_a = level * w3d_f32_80379b04[0] + rest * w3d_f32_80379b08[0];
    object->weight_c = weight - w3d_f32_80379b10[0];
    return object;
}

W3dSingletonComponent *w3d_component_construct_80098bb8(W3dSingletonComponent *object)
{
    W3dWordVec3 *cursor;
    w3d_base_construct_801628b0(object);
    cursor->y = 0;    cursor = &object->cursor;
    object->vtable = w3d_component_vtable_8040f310;    cursor->x = 0;    cursor->z = 0;    w3d_component_instance_804aabd4 = object;    object->selected = -1;    object->held_028 = 0;    object->held_01c = 0;    object->held_024 = 0;    object->held_038 = 0;    object->limit = 7;    return object;
}

}
