#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
void w3d_actor_member_delete_backend(void *block)
{
    if (block != 0)
        w3d_task_array_release_backend(block);
}
#ifdef __cplusplus
}
#endif
