#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_member_delete_backend.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
void w3d_actor_member_delete_backend(Ptr32<void> block)
{
    if (block != 0)
        w3d_task_array_release_backend(block);
}
#ifdef __cplusplus
}
#endif

}
