#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
void w3d_actor_handle_member_set_slot_word(ActorHandleMember *member, unsigned int value)
{
    w3d_handle_set_slot_word(member->handle, value);
}
#ifdef __cplusplus
}
#endif
