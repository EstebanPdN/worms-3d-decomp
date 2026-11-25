#ifndef W3D_REFERENCE_ACTOR_DELIVERY_IMPL_H
#define W3D_REFERENCE_ACTOR_DELIVERY_IMPL_H
#include "actor_dispatch.h"

static __inline__ ActorRecord *find_actor_record(ActorTable *table,
    ActorHandle handle)
{
    ActorRecord *record;
    if (handle == 0xffffffffu) return 0;
    record = &table->records[handle & 0xfff];
    return record->handle == handle ? record : 0;
}

static __inline__ int actor_type_derives(ActorType *type, ActorType *wanted)
{
    while (type != wanted) {
        if (type == type->parent) return 0;
        type = type->parent;
    }
    return 1;
}

static __inline__ int dispatch_on_table(ActorTable *table, void *message,
    ActorHandle recipient, int children)
{
    ActorRecord *record = find_actor_record(table, recipient);
    unsigned int phase;
    int result;
    if (record == 0) return (int)0x80004005u;
    w3d_engine_get_context();
    if (actor_type_derives(record->object->methods->type(record->object),
            &w3d_dispatch_type_phase8)) phase = 8;
    else if (actor_type_derives(record->object->methods->type(record->object),
            &w3d_dispatch_type_phase6)) phase = 6;
    else if (actor_type_derives(record->object->methods->type(record->object),
            &w3d_dispatch_type_phase7)) phase = 7;
    else goto deliver;
    w3d_engine_get_context()->phase = phase;
deliver:
    result = record->object->methods->message(record->object, message);
    if (result >= 0 && children != 0) {
        ActorHandle handles[256];
        int count = 0, i;
        ActorIndex index = record->first_child;
        while (index != 0) {
            ActorRecord *child = &table->records[index];
            handles[count++] = child->handle;
            index = child->next_sibling;
        }
        for (i = 0; i < count; ++i) {
            Actor *child = w3d_actor_from_handle(table, handles[i]);
            if (child != 0) result = child->methods->message(child, message);
            if (result < 0) break;
        }
    }
    return result;
}
#endif
