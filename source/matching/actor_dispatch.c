/* Original global-context delivery entry; shared C table implementation. */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_delivery_impl.h"
int w3d_message_dispatch_core(void *message, ActorHandle recipient, int children)
{
    return dispatch_on_table(w3d_engine_context->actors, message, recipient, children);
}
#ifdef __cplusplus
}
#endif
