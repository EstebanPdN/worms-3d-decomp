/* Full source hypothesis for original 80141d68..801421c8.
 * Reconstructed from original Worms3D GameCube instructions.
 * External calls retain native dependencies; no stub implementations. */
extern "C" {
#include "concrete_actor_construction.h"
static inline void set_vector(ActorVector3 *v, float x, float y, float z)
{
    v->x = x; v->y = y; v->z = z;
}
static inline void clear_buffer(ConstructorBuffer *buffer)
{
    buffer->word_08 = 0; buffer->word_04 = 0; buffer->data = 0;
}
static inline void release_owned(ConstructorOwned *object)
{
    if (object != 0) object->methods->release(object);
}
}
/* Native stack overlays: only first pointer words are interpreted.
 * Suffix extents reproduce the reference ABI; original class identities and
 * complete type sizes remain unverified. No host portability is claimed. */
struct ConstructorReference {
    ConstructorOwned *object;
    unsigned char unobserved_04[4];
    ConstructorReference() {}
    ~ConstructorReference() { release_owned(object); }
};
struct ConstructorName {
    const char *text;
    unsigned char unobserved_04[8];
    ConstructorName(const char *value) : text(value) {}
};
extern "C" {
ConstructorActor *w3d_concrete_actor_initialize(ConstructorActor *actor)
{
    ActorHandleStorage *handle = &actor->member_478;
    float zero;
    ConstructorOwned *land;
    w3d_actor_base_initialize(&actor->base);
    actor->base.base.methods = (void *)w3d_concrete_actor_methods;
    w3d_actor_method_member_initialize(&actor->member_1c);
    actor->owned_f4 = 0;
    w3d_actor_method_member_initialize(&actor->member_160);
    actor->owned_218[0] = 0;
    actor->owned_218[1] = 0;
    actor->owned_218[2] = 0;
    actor->owned_218[3] = 0;
    actor->owned_218[4] = 0;
    actor->owned_218[5] = 0;
    actor->owned_320[0] = 0;
    actor->owned_320[1] = 0;
    actor->owned_320[2] = 0;
    actor->owned_320[3] = 0;
    actor->owned_350[0] = 0;
    actor->owned_350[1] = 0;
    actor->owned_350[2] = 0;
    actor->owned_350[3] = 0;
    actor->owned_350[4] = 0;
    actor->owned_350[5] = 0;
    actor->owned_350[6] = 0;
    actor->owned_350[7] = 0;
    actor->owned_350[8] = 0;
    actor->owned_350[9] = 0;
    actor->owned_350[10] = 0;
    actor->owned_350[11] = 0;
    actor->owned_350[12] = 0;
    actor->owned_350[13] = 0;
    actor->owned_350[14] = 0;
    actor->owned_350[15] = 0;
    actor->owned_350[16] = 0;
    actor->owned_350[17] = 0;
    actor->owned_350[18] = 0;
    actor->owned_350[19] = 0;
    actor->owned_350[20] = 0;
    actor->owned_350[21] = 0;
    actor->owned_350[22] = 0;
    actor->owned_350[23] = 0;
    actor->owned_350[24] = 0;
    actor->owned_350[25] = 0;
    actor->owned_350[26] = 0;
    actor->owned_350[27] = 0;
    actor->owned_350[28] = 0;
    actor->owned_350[29] = 0;
    actor->owned_350[30] = 0;
    actor->owned_350[31] = 0;
    actor->owned_350[32] = 0;
    actor->owned_350[33] = 0;
    actor->owned_350[34] = 0;
    actor->owned_350[35] = 0;
    actor->owned_350[36] = 0;
    actor->owned_350[37] = 0;
    actor->owned_350[38] = 0;
    actor->owned_350[39] = 0;
    actor->owned_350[40] = 0;
    actor->owned_350[41] = 0;
    actor->owned_350[42] = 0;
    actor->owned_350[43] = 0;
    actor->owned_350[44] = 0;
    actor->owned_350[45] = 0;
    actor->owned_350[46] = 0;
    actor->owned_350[47] = 0;
    actor->owned_350[48] = 0;
    actor->owned_350[49] = 0;
    actor->owned_350[50] = 0;
    actor->owned_350[51] = 0;
    actor->owned_350[52] = 0;
    actor->owned_350[53] = 0;
    actor->owned_350[54] = 0;
    actor->owned_350[55] = 0;
    actor->owned_350[56] = 0;
    actor->owned_350[57] = 0;
    actor->owned_350[58] = 0;
    actor->owned_350[59] = 0;
    actor->owned_350[60] = 0;
    actor->owned_350[61] = 0;
    actor->owned_350[62] = 0;
    actor->owned_350[63] = 0;
    actor->owned_350[64] = 0;
    actor->owned_350[65] = 0;
    actor->owned_350[66] = 0;
    actor->owned_350[67] = 0;
    actor->owned_350[68] = 0;
    actor->owned_350[69] = 0;
    actor->owned_350[70] = 0;
    actor->owned_350[71] = 0;
    actor->owned_350[72] = 0;
    actor->owned_350[73] = 0;
    w3d_actor_handle_member_initialize(&handle->base);
    constructor_optional_initialize(actor->member_480);
    actor->owned_4a8[0] = 0;
    zero = 0.0f;
    actor->owned_4a8[1] = 0;
    actor->owned_4a8[2] = 0;
    actor->owned_4c0[0] = 0;
    actor->owned_4c0[1] = 0;
    actor->owned_4c0[2] = 0;
    actor->owned_4c0[3] = 0;
    actor->owned_4c0[4] = 0;
    actor->owned_4c0[5] = 0;
    actor->owned_4c0[6] = 0;
    actor->owned_4c0[7] = 0;
    actor->owned_4c0[8] = 0;
    actor->owned_4c0[9] = 0;
    clear_buffer(&actor->buffer_540);
    actor->owned_54c[0] = 0;
    actor->owned_54c[1] = 0;
    actor->word_278 = 0;
    actor->word_27c = 0;
    actor->word_280 = 0;
    actor->word_f8 = 0;
    set_vector(&actor->vector_2b0, zero, -0.00025f, zero);
    set_vector(&actor->vector_2a4, zero, zero, zero);
    actor->word_284 = 0;
    actor->word_274 = 0;
    actor->word_288 = 0;
    actor->word_29c = 1000;
    actor->word_2e8 = 0;
    actor->word_2f8 = 0;
    actor->float_300 = zero;
    actor->word_270 = 0;
    actor->word_26c = 0;
    actor->word_268 = 0;
    actor->word_264 = 0;
    actor->word_2f0 = 0;
    actor->word_12c = 0;
    w3d_actor_reset_construction_words((ActorConstructionPrefix *)actor);
    set_vector(&actor->vector_138, zero, zero, zero);
    actor->word_310 = -1;
    actor->word_314 = -1;
    actor->word_318 = -1;
    actor->word_2f4 = 1000;
    actor->word_31c = 0;
    actor->float_24c = zero;
    actor->float_250 = zero;
    actor->word_254 = 0;
    actor->word_258 = 0;
    actor->float_330 = zero;
    actor->float_334 = zero;
    set_vector(&actor->vector_230, zero, zero, zero);
    actor->word_2cc = 0;
    actor->flags_338 &= 0x7fffffff;
    w3d_actor_handle_member_set_word(handle, 0x419);
    w3d_actor_handle_member_set_slot_word(&handle->base, 1);
    w3d_actor_handle_member_set_bounds(&handle->base, &actor->vector_230, 10.0f);
    set_vector(&actor->vector_4b4, zero, 1.0f, zero);
    actor->word_25c = 0;
    actor->word_260 = 0;
    actor->word_2ec = 0;
    actor->word_28c = 0;
    actor->word_290 = 0;
    actor->word_2d0 = 0;
    actor->vector_2d4 = constructor_default_vector;
    actor->word_2e0 = 0;
    /* Earlier native calls may populate these owners. Reload after every call. */
    release_owned(actor->owned_320[0]);
    actor->owned_320[0] = 0;
    release_owned(actor->owned_320[1]);
    actor->owned_320[1] = 0;
    release_owned(actor->owned_320[2]);
    actor->owned_320[2] = 0;
    actor->word_294 = 0;
    actor->flags_338 &= 0xbfffffff;
    actor->word_298 = 0;
    ConstructorReference temporary;
    ConstructorName name(constructor_land_name);
    temporary.object = 0;
    w3d_constructor_lookup_name(&name, &temporary);
    land = w3d_constructor_native_cast(temporary.object);
    if (land != 0) land->methods->acquire(land);
    release_owned(actor->owned_54c[1]);
    actor->owned_54c[1] = land;
    return actor;
}
}
