#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_member_optional_delete.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_member_cleanup.h"
void w3d_actor_member_optional_delete(Ptr32<void> member, unsigned int flags)
{
    if (flags & 1)
        w3d_actor_member_delete_backend(member);
}
#ifdef __cplusplus
}
#endif

}
