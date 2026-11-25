#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_handle_member_set_word.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
void w3d_actor_handle_member_set_word(Ptr32<ActorHandleStorage> member, unsigned int value)
{
    member->unknown_04 = value;
}
#ifdef __cplusplus
}
#endif

}
