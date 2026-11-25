#ifndef W3D_ACTOR_DESTRUCTION_H
#define W3D_ACTOR_DESTRUCTION_H
#include "actor_ownership.h"
#include "actor_base_cleanup.h"
typedef struct ActorOwnedObject ActorOwnedObject;
typedef struct ActorOwnedMethods {
    void *unknown_00[4];
    void (*release)(ActorOwnedObject *);
} ActorOwnedMethods;
struct ActorOwnedObject { const ActorOwnedMethods *methods; };
/* Complete extent, with only destructor-observed fields named by offset. */
typedef struct ConcreteActorStorage {
    ActorBaseStorage base;
    ActorMethodMember member_1c;
    unsigned char unknown_44[0xb0];
    ActorOwnedObject *owned_f4;
    unsigned char unknown_f8[0x68];
    ActorMethodMember member_160;
    unsigned char unknown_188[0x90];
    ActorOwnedObject *owned_218[6];
    unsigned char unknown_230[0xf0];
    ActorOwnedObject *owned_320[4];
    unsigned char unknown_330[0x20];
    ActorOwnedObject *owned_350[74];
    ActorHandleMember member_478;
    unsigned char unknown_47c[4];
    unsigned char member_480[0x28];
    ActorOwnedObject *owned_4a8[3];
    unsigned char unknown_4b4[12];
    ActorOwnedObject *owned_4c0[10];
    unsigned char unknown_4e8[0x58];
    void *buffer_540;
    unsigned char unknown_544[8];
    ActorOwnedObject *owned_54c[2];
} ConcreteActorStorage;
#endif
