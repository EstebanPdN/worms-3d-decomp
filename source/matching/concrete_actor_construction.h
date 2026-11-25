#ifndef W3D_CONCRETE_ACTOR_CONSTRUCTION_H
#define W3D_CONCRETE_ACTOR_CONSTRUCTION_H
#include "actor_construction.h"
typedef struct ConstructorOwned ConstructorOwned;
typedef struct ConstructorOwnedMethods {
    void *unknown_00[3];
    void (*acquire)(ConstructorOwned *);
    void (*release)(ConstructorOwned *);
} ConstructorOwnedMethods;
struct ConstructorOwned { const ConstructorOwnedMethods *methods; };
typedef struct ConstructorBuffer {
    void *data;
    unsigned int word_04, word_08;
} ConstructorBuffer;
typedef struct ConstructorActor {
    ActorBaseStorage base;
    ActorMethodStorage member_1c;
    unsigned char unknown_48[0xac];
    ConstructorOwned *owned_f4;
    unsigned int word_f8;
    unsigned char unknown_fc[0x30];
    unsigned int word_12c, word_130, word_134;
    ActorVector3 vector_138;
    unsigned char unknown_144[0x1c];
    ActorMethodStorage member_160;
    unsigned char unknown_18c[0x8c];
    ConstructorOwned *owned_218[6];
    ActorVector3 vector_230;
    unsigned char unknown_23c[0x10];
    float float_24c, float_250;
    unsigned int word_254, word_258, word_25c, word_260;
    unsigned int word_264, word_268, word_26c, word_270, word_274;
    unsigned int word_278, word_27c, word_280, word_284, word_288;
    unsigned int word_28c, word_290, word_294, word_298, word_29c;
    unsigned int unknown_2a0;
    ActorVector3 vector_2a4, vector_2b0;
    unsigned char unknown_2bc[0x10];
    unsigned int word_2cc, word_2d0;
    ActorVector3 vector_2d4;
    unsigned int word_2e0, unknown_2e4, word_2e8, word_2ec;
    unsigned int word_2f0, word_2f4, word_2f8, unknown_2fc;
    float float_300;
    unsigned char unknown_304[0x0c];
    unsigned int word_310, word_314, word_318, word_31c;
    ConstructorOwned *owned_320[4];
    float float_330, float_334;
    unsigned int flags_338;
    unsigned char unknown_33c[0x14];
    ConstructorOwned *owned_350[74];
    ActorHandleStorage member_478;
    unsigned char member_480[0x28];
    ConstructorOwned *owned_4a8[3];
    ActorVector3 vector_4b4;
    ConstructorOwned *owned_4c0[10];
    unsigned char unknown_4e8[0x58];
    ConstructorBuffer buffer_540;
    ConstructorOwned *owned_54c[2];
} ConstructorActor;
/* Observed 0x554-byte constructor storage extent, not allocation-size proof.
 * Compile-time target layout witnesses, never a host-layout assumption. */
typedef char constructor_size_must_be_554[sizeof(ConstructorActor) == 0x554 ? 1 : -1];
extern const unsigned char w3d_concrete_actor_methods[];
extern const float constructor_zero[], constructor_one[], constructor_bounds[], constructor_vertical[];
extern ActorVector3 constructor_default_vector;
extern const char constructor_land_name[];
void *constructor_optional_initialize(void *);
unsigned int w3d_constructor_lookup_name(const void *, void *);
ConstructorOwned *w3d_constructor_native_cast(ConstructorOwned *);
#endif
