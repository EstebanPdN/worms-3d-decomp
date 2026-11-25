#ifndef W3D_REFERENCE_ACTOR_DISPATCH_H
#define W3D_REFERENCE_ACTOR_DISPATCH_H
typedef unsigned int ActorHandle;
typedef unsigned short ActorIndex;
typedef struct Actor Actor;
typedef struct ActorType {
    void *unknown_00;
    struct ActorType *next;
    unsigned char unknown_08[0x0c];
    struct ActorType *parent;
    unsigned char unknown_18[0x14];
    void *first_link;
} ActorType;
typedef struct ActorMethods {
    void *unknown_00[5];
    ActorType *(*type)(Actor *);
    void *unknown_18[2];
    int (*run)(Actor *, unsigned int);
    int (*message)(Actor *, void *);
} ActorMethods;
struct Actor {
    ActorMethods *methods;
    unsigned char unknown_04[8];
    void *next_link;
};
typedef struct ActorRecord {
    unsigned char unknown_00[6];
    ActorIndex first_child, unknown_08, next_sibling;
    Actor *object;
    ActorHandle unknown_10, handle;
    unsigned char unknown_18[12];
} ActorRecord;
typedef struct ActorQueueCursor {
    void *begin;
    void *limit;
    void *end;
} ActorQueueCursor;
typedef struct ActorTable {
    ActorRecord *records;
    unsigned int time_bias;
    unsigned char unknown_08[0x10];
    ActorQueueCursor *queue_primary;
    ActorQueueCursor *queue_secondary;
} ActorTable;
typedef struct EngineContext {
    unsigned char unknown_00[0x1c];
    ActorTable *actors;
    unsigned char unknown_20[0x10];
    unsigned int next_time, current_time, stopped;
    unsigned int phase;
} EngineContext;
extern EngineContext *w3d_engine_context;
extern ActorType w3d_dispatch_type_phase8, w3d_dispatch_type_phase6,
                 w3d_dispatch_type_phase7;
extern EngineContext *w3d_engine_get_context(void);
extern Actor *w3d_actor_from_handle(ActorTable *, ActorHandle);
int w3d_message_dispatch_core(void *, ActorHandle, int);
int w3d_actor_table_deliver(ActorTable *, void *, ActorHandle, int);
extern ActorType *w3d_actor_type_registry;
Actor *w3d_actor_type_first(ActorType *);
Actor *w3d_actor_type_next(ActorType *, Actor *);
ActorType *w3d_actor_types_first(void);
int w3d_message_broadcast_type(ActorTable *, void *, ActorType *, int);
void w3d_actor_queue_exchange(ActorTable *);
#endif
