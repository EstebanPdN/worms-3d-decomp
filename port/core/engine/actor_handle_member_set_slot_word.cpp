#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_handle_member_set_slot_word.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
void w3d_actor_handle_member_set_slot_word(Ptr32<ActorHandleMember> member, unsigned int value)
{
    w3d_handle_set_slot_word(member->handle, value);
}
#ifdef __cplusplus
}
#endif

}
