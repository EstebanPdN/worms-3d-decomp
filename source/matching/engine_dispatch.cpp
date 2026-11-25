/* C-compatible context/lookup helpers, built with the recorded SN C++ profile.
 * The shared header records the same observed ABI as actor_dispatch.c.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_dispatch.h"

EngineContext *w3d_engine_get_context(void) { return w3d_engine_context; }

Actor *w3d_actor_from_handle(ActorTable *table, ActorHandle handle)
{
    ActorRecord *record;
    if (handle == 0xffffffffu) record = 0;
    else {
        ActorRecord *candidate = &table->records[handle & 0xfff];
        record = 0;
        if (candidate->handle == handle) record = candidate;
    }
    if (record == 0) return 0;
    return record->object;
}
#ifdef __cplusplus
}
#endif
