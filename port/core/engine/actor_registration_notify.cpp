#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_registration_notify.c"
/* Native registration notification. Preserve the receiver/method table and
 * generation handle captured before reserving the twelve-byte message.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_registration.h"
#include "message_arena.h"
typedef struct ActorRegisteredMessage {
    unsigned short flags, unknown_02;
    Ptr32<const void> methods;
    ActorHandle handle;
} ActorRegisteredMessage;
extern const unsigned int w3d_actor_registered_message_methods[];

void w3d_actor_registration_notify(Ptr32<TaskTable> table, Ptr32<RegistrationRecord> record,
                                   int deferred)
{
    Ptr32<Actor> actor = record->object;
    ActorHandle handle = record->handle;
    Ptr32<ActorMethods> methods = actor->methods;
    Ptr32<ActorRegisteredMessage> message = (Ptr32<ActorRegisteredMessage>)w3d_message_allocate(w3d_message_storage, 12);
    (void)table;
    message->flags = 0x40;
    message->methods = w3d_actor_registered_message_methods;
    message->handle = handle;
    if (deferred != 0)
        message->handle = handle | 0x80000000u;
    methods->message(actor, message);
}
#ifdef __cplusplus
}
#endif

}
