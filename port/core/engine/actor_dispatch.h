#ifndef W3D_REFERENCE_ACTOR_DISPATCH_H
#define W3D_REFERENCE_ACTOR_DISPATCH_H
typedef unsigned int ActorHandle;
typedef unsigned short ActorIndex;
typedef struct Actor Actor;
typedef struct ActorType {
    Ptr32<void> unknown_00;
    Ptr32<struct ActorType> next;
    unsigned char unknown_08[0x0c];
    Ptr32<struct ActorType> parent;
    unsigned char unknown_18[0x14];
    Ptr32<void> first_link;
} ActorType;
typedef struct ActorMethods {
    Ptr32<void> unknown_00[5];
    Ptr32<Ptr32<ActorType> (Ptr32<Actor>)> type;
    Ptr32<void> unknown_18[2];
    Ptr32<int (Ptr32<Actor>, unsigned int)> run;
    Ptr32<int (Ptr32<Actor>, Ptr32<void>)> message;
} ActorMethods;
struct Actor {
    Ptr32<ActorMethods> methods;
    unsigned char unknown_04[8];
    Ptr32<void> next_link;
};
typedef struct ActorRecord {
    unsigned char unknown_00[6];
    ActorIndex first_child, unknown_08, next_sibling;
    Ptr32<Actor> object;
    ActorHandle unknown_10, handle;
    unsigned char unknown_18[12];
} ActorRecord;
typedef struct ActorQueueCursor {
    Ptr32<void> begin;
    Ptr32<void> limit;
    Ptr32<void> end;
} ActorQueueCursor;
typedef struct ActorTable {
    Ptr32<ActorRecord> records;
    unsigned int time_bias;
    unsigned char unknown_08[0x10];
    Ptr32<ActorQueueCursor> queue_primary;
    Ptr32<ActorQueueCursor> queue_secondary;
} ActorTable;
typedef struct EngineContext {
    unsigned char unknown_00[0x1c];
    Ptr32<ActorTable> actors;
    unsigned char unknown_20[0x10];
    unsigned int next_time, current_time, stopped;
    unsigned int phase;
} EngineContext;
extern Ptr32<EngineContext> w3d_engine_context;
extern ActorType w3d_dispatch_type_phase8, w3d_dispatch_type_phase6,
                 w3d_dispatch_type_phase7;
extern Ptr32<EngineContext> w3d_engine_get_context(void);
extern Ptr32<Actor> w3d_actor_from_handle(Ptr32<ActorTable>, ActorHandle);
int w3d_message_dispatch_core(Ptr32<void>, ActorHandle, int);
int w3d_actor_table_deliver(Ptr32<ActorTable>, Ptr32<void>, ActorHandle, int);
extern Ptr32<ActorType> w3d_actor_type_registry;
Ptr32<Actor> w3d_actor_type_first(Ptr32<ActorType>);
Ptr32<Actor> w3d_actor_type_next(Ptr32<ActorType>, Ptr32<Actor>);
Ptr32<ActorType> w3d_actor_types_first(void);
int w3d_message_broadcast_type(Ptr32<ActorTable>, Ptr32<void>, Ptr32<ActorType>, int);
void w3d_actor_queue_exchange(Ptr32<ActorTable>);
#endif
