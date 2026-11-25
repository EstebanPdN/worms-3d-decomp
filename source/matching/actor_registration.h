#ifndef W3D_REFERENCE_ACTOR_REGISTRATION_H
#define W3D_REFERENCE_ACTOR_REGISTRATION_H
#include "task_scheduler.h"

/* Observed registration fields; names describe recovered roles. */
typedef struct RegistrationRecord {
    unsigned int unknown_00;
    ActorIndex unknown_04, first_child, unknown_08, next_sibling;
    Actor *object;
    ActorIndex parent, flags;
    ActorHandle handle;
    unsigned char unknown_18[12];
} RegistrationRecord;
typedef struct RegistrationMethods {
    void *unknown_00[3];
    void (*acquire)(Actor *);
    void (*release)(Actor *);
    ActorType *(*type)(Actor *);
} RegistrationMethods;
typedef struct RegistrationType {
    unsigned char unknown_00[0x20];
    unsigned int attributes;
} RegistrationType;
extern ActorType w3d_registration_phase4, w3d_registration_phase3,
                 w3d_registration_phase5;
const char *w3d_heap_actor_type_name(ActorType *);
void w3d_actor_registration_notify(TaskTable *, RegistrationRecord *, int);
ActorHandle w3d_actor_register(EngineContext *, Actor *, ActorHandle);
#endif
