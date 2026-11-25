#include "w3d_ptr.h"
#line 1 "a_ai_moves.cpp"
/* AI worm move queue (0x80003300..0x8000419c).
 *
 * Names are inferred from behavior; no original symbols survive. Callees
 * outside this unit stay external and are bound to their original addresses
 * by the reference linker. Observed layout of the move queue object:
 *   +0x04 finished flag, +0x08 busy flag, +0x0c kind (5 after construction)
 *   +0x10 vtable (4-byte entries; +0x08 destroy, +0x0c timeout, +0x14 start)
 *   +0x14/+0x18/+0x1c pointer vector begin/end/capacity
 *   +0x24 progress word, +0x28 state (6 = timed wait), +0x2c references
 */
extern "C" {

typedef struct W3dMoveQueue W3dMoveQueue;

typedef struct W3dMoveQueueVtable {
    Ptr32<void> unknown_00[2];
    Ptr32<void (Ptr32<W3dMoveQueue>, int)> destroy;
    Ptr32<void (Ptr32<W3dMoveQueue>)> timeout;
    Ptr32<void> unknown_10;
    Ptr32<void (Ptr32<W3dMoveQueue>)> start;
} W3dMoveQueueVtable;

typedef struct W3dMoveVector {
    Ptr32<Ptr32<void>> begin;
    Ptr32<Ptr32<void>> end;
    Ptr32<Ptr32<void>> capacity;
} W3dMoveVector;

struct W3dMoveQueue {
    unsigned char unknown_00[4];
    int finished;
    int busy;
    int kind;
    Ptr32<W3dMoveQueueVtable> vtable;
    W3dMoveVector moves;
    unsigned char unknown_20[4];
    int progress;
    int state;
    int references;
};

typedef struct W3dMoveStep {
    unsigned char unknown_00[2];
    short x;
    short y;
    unsigned char flags;
} W3dMoveStep;

typedef struct W3dMovePosition {
    int x;
    int y;
    int z;
} W3dMovePosition;

/* Queued move: kind at +0, target position at +4. */
typedef struct W3dMove {
    int kind;
    W3dMovePosition position;
} W3dMove;

typedef struct W3dMoveTimed {
    int kind;
    float value;
    unsigned char unknown_08[8];
} W3dMoveTimed;

/* 184-byte action record copied into a move; +0x24 is preserved by the copy. */
typedef struct W3dMoveAction {
    unsigned char unknown_00[0x24];
    int preserved;
    unsigned char unknown_28[0xb8 - 0x28];
} W3dMoveAction;

typedef struct W3dMoveWithAction {
    int kind;
    W3dMovePosition position;
    W3dMoveAction action;
} W3dMoveWithAction;

typedef struct W3dEngineContext {
    unsigned char unknown_00[0x34];
    int frame_time;
} W3dEngineContext;

typedef struct W3dMessageTarget {
    unsigned char unknown_00[8];
    int value;
} W3dMessageTarget;

extern W3dMoveQueueVtable w3d_move_queue_vtable_8040cad0;
extern unsigned char w3d_move_default_8045e788[];
extern int w3d_move_wait_start_804b174c;
extern int w3d_move_wait_length_804b1750;
extern Ptr32<void> w3d_message_queue_804b1754;
extern Ptr32<void> w3d_move_cursor_804b1758;

void w3d_vector_clear_8034134c(Ptr32<W3dMoveVector> vector);
void w3d_actor_member_delete_backend(Ptr32<void> object);
void w3d_handle_storage_release(Ptr32<void> storage);
void w3d_object_base_destroy_80021468(Ptr32<void> object, int flags);
void w3d_operator_delete_80015264(Ptr32<void> object);
void w3d_memmove_802eee50(Ptr32<void> dest, Ptr32<const void> source, unsigned int size, ...);
int w3d_message_prepare_801613f0(Ptr32<void> queue, int id);
Ptr32<W3dMessageTarget> w3d_message_target_80131a84(Ptr32<void>);
int w3d_message_post_current(Ptr32<void>);
Ptr32<W3dEngineContext> w3d_engine_get_context(void);
extern const char w3d_str_move_rethink_80368db0[];
extern const char w3d_str_move_skip_80368de0[];
extern const char w3d_str_move_keep_trying_80368e08[];
extern const char w3d_str_move_jump_forward_80368e2c[];
extern const char w3d_str_move_backflip_80368e3c[];
extern const char w3d_str_move_jump_up_80368e4c[];
extern const char w3d_str_move_jump_up_no_aftertouch_80368e54[];
extern const char w3d_str_move_jetpack_80368e6c[];
extern const char w3d_str_move_parachute_start_80368e74[];
extern const char w3d_str_move_parachute_80368e84[];
extern const char w3d_str_move_ninja_rope_80368e90[];
extern const char w3d_str_move_super_sheep_80368e9c[];
extern const char w3d_str_move_delay_80368ea8[];
extern const char w3d_str_move_unknown_80368eb0[];
extern Ptr32<const char> w3d_move_type_name_804ac824;

Ptr32<void> w3d_move_step_apply_8001e224(Ptr32<void> object, Ptr32<void> cursor, int x, int y, int flags);
Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
Ptr32<void> w3d_handle_storage_allocate(unsigned int bytes);
void w3d_memmove_802eeef4(Ptr32<void> dest, Ptr32<const void> source, unsigned int size);
Ptr32<void> w3d_actor_method_member_initialize(Ptr32<void> member);

void w3d_move_queue_reset_800039ac(Ptr32<W3dMoveQueue> queue);

/* The vector begin word is cleared separately in the constructor body. */
static inline void w3d_move_vector_init(Ptr32<W3dMoveVector> vector)
{
    vector->capacity = 0;
    vector->end = 0;
}

extern "C++" {
template<class T> inline const T &w3d_move_max(const T &first, const T &second)
{ return first < second ? second : first; }
template<class T> inline const T &w3d_move_min(const T &first, const T &second)
{ return second < first ? second : first; }
}

/* Pointer vector growth: capacity grows to max(n + 1, 1.5 n) entries. */
inline void w3d_move_vector_grow(Ptr32<W3dMoveVector> vector)
{
    unsigned int used = (Ptr32<unsigned char>)vector->end - (Ptr32<unsigned char>)vector->begin;
    unsigned int bytes = 4 * w3d_move_max((int)(used + 1), (int)(used + (used >> 1)));
    Ptr32<unsigned char> replacement = (Ptr32<unsigned char>)w3d_handle_storage_allocate(bytes);
    if (vector->begin) {
        w3d_memmove_802eee50(replacement, vector->begin, w3d_move_min(bytes, used));
        w3d_handle_storage_release(vector->begin);
    }
    vector->begin = (Ptr32<Ptr32<void>>)replacement;
    vector->end = (Ptr32<Ptr32<void>>)(replacement + used);
    vector->capacity = (Ptr32<Ptr32<void>>)(replacement + bytes);
}

inline void w3d_move_vector_push(Ptr32<W3dMoveVector> vector, Ptr32<void> const &item)
{
    if (vector->end == vector->capacity)
        w3d_move_vector_grow(vector);
    *vector->end = item;
    vector->end++;
}

Ptr32<W3dMoveQueue> w3d_move_queue_construct(Ptr32<W3dMoveQueue> queue)
{
    queue->vtable = &w3d_move_queue_vtable_8040cad0;
    queue->kind = 0;
    queue->finished = 0;
    queue->busy = 0;
    w3d_move_vector_init(&queue->moves);
    queue->kind = 5;
    queue->moves.begin = 0;
    queue->progress = 0;
    queue->state = 0;
    queue->references = 0;
    w3d_move_queue_reset_800039ac(queue);
    return queue;
}

void w3d_move_queue_destroy(Ptr32<W3dMoveQueue> queue, int flags)
{
    queue->vtable = &w3d_move_queue_vtable_8040cad0;
    w3d_move_queue_reset_800039ac(queue);
    if (queue->moves.begin)
        w3d_handle_storage_release(queue->moves.begin);
    w3d_object_base_destroy_80021468(queue, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(queue);
}

void w3d_move_queue_release(Ptr32<W3dMoveQueue> queue)
{
    if (--queue->references == 0 && queue)
        queue->vtable->destroy(queue, 3);
}

Ptr32<const char> w3d_move_type_name(int type)
{
    switch (type) {
    case 0: w3d_move_type_name_804ac824 = w3d_str_move_rethink_80368db0; break;
    case 1: w3d_move_type_name_804ac824 = w3d_str_move_skip_80368de0; break;
    case 2: w3d_move_type_name_804ac824 = w3d_str_move_keep_trying_80368e08; break;
    case 3: w3d_move_type_name_804ac824 = w3d_str_move_jump_forward_80368e2c; break;
    case 4: w3d_move_type_name_804ac824 = w3d_str_move_backflip_80368e3c; break;
    case 5: w3d_move_type_name_804ac824 = w3d_str_move_jump_up_80368e4c; break;
    case 6: w3d_move_type_name_804ac824 = w3d_str_move_jump_up_no_aftertouch_80368e54; break;
    case 7: w3d_move_type_name_804ac824 = w3d_str_move_jetpack_80368e6c; break;
    case 8: w3d_move_type_name_804ac824 = w3d_str_move_parachute_start_80368e74; break;
    case 9: w3d_move_type_name_804ac824 = w3d_str_move_parachute_80368e84; break;
    case 10: w3d_move_type_name_804ac824 = w3d_str_move_ninja_rope_80368e90; break;
    case 11: w3d_move_type_name_804ac824 = w3d_str_move_super_sheep_80368e9c; break;
    case 12: w3d_move_type_name_804ac824 = w3d_str_move_delay_80368ea8; break;
    default: w3d_move_type_name_804ac824 = w3d_str_move_unknown_80368eb0; break;
    }
    return w3d_move_type_name_804ac824;
}

void w3d_move_queue_reset_800039ac(Ptr32<W3dMoveQueue> queue)
{
    w3d_vector_clear_8034134c(&queue->moves);
    queue->progress = 0;
}

Ptr32<void> w3d_move_queue_current_step(Ptr32<W3dMoveQueue> queue)
{
    if (queue->moves.begin != queue->moves.end)
        return (Ptr32<char>)queue->moves.end[-1] + 4;
    return w3d_move_default_8045e788;
}

void w3d_move_queue_pop_front(Ptr32<W3dMoveQueue> queue)
{
    Ptr32<W3dMoveVector> moves;
    Ptr32<Ptr32<void>> begin;

    queue->progress = 0;
    moves = &queue->moves;
    if (queue->moves.begin != moves->end) {
        w3d_actor_member_delete_backend(*queue->moves.begin);
        *queue->moves.begin = 0;
        begin = queue->moves.begin;
        if (begin + 1 != moves->end)
        {
            Ptr32<Ptr32<void>> last = moves->end - 1;
            w3d_memmove_802eee50(begin, begin + 1, (Ptr32<char>)last - (Ptr32<char>)begin);
        }
        moves->end--;
    }
    if (queue->moves.begin == queue->moves.end) {
        queue->finished = 1;Ptr32<W3dMessageTarget> finished_message = w3d_message_target_80131a84((Ptr32<void>)w3d::G(w3d_message_prepare_801613f0(w3d_message_queue_804b1754, 236)));
        finished_message->value = 0;
        w3d_message_post_current(finished_message);
    }
}

void w3d_move_queue_advance(Ptr32<W3dMoveQueue> queue)
{
    switch (queue->state) {
    case 0:
        w3d_move_queue_pop_front(queue);
        break;
    case 1: case 2: case 3: case 4: case 5: case 6:
        queue->progress = 0;
        break;
    }
    if (queue->moves.begin != queue->moves.end) {
        queue->busy = 1;
        queue->vtable->start(queue);
    }
}

void w3d_move_queue_check_timeout(Ptr32<W3dMoveQueue> queue)
{
    if (queue->state == 6
        && w3d_engine_get_context()->frame_time - w3d_move_wait_start_804b174c > w3d_move_wait_length_804b1750)
        queue->vtable->timeout(queue);
}

void w3d_move_queue_start_wait(Ptr32<W3dMoveQueue> queue, int length)
{
    w3d_move_wait_length_804b1750 = length;
    w3d_move_wait_start_804b174c = w3d_engine_get_context()->frame_time;
    queue->state = 6;
}

Ptr32<void> w3d_move_step_apply(Ptr32<void> object, Ptr32<W3dMoveStep> step)
{
    w3d_move_step_apply_8001e224(object, w3d_move_cursor_804b1758, step->x, step->y, step->flags);
    return object;
}


#if 0
/* Skipped: 0x80003424, 0x80003558, 0x80003710, 0x80003834 (vector push/insert).
 * Original schedules the vector end/capacity loads above the stores into the
 * freshly allocated move; this source keeps them after the stores. */
void w3d_move_queue_add_position(W3dMoveQueue *queue, const W3dMovePosition *position, int kind)
{
    W3dMove *move = (W3dMove *)w3d_heap_allocate_entry_a(sizeof(W3dMove));
    move->position = *position;
    move->kind = kind;
    w3d_move_vector_push(&queue->moves, move);
}

void w3d_move_queue_add_action(W3dMoveQueue *queue, const W3dMovePosition *position, int kind,
                               const W3dMoveAction *action)
{
    W3dMoveWithAction *move = (W3dMoveWithAction *)w3d_heap_allocate_entry_a(sizeof(W3dMoveWithAction));
    int preserved;
    move->position = *position;
    move->kind = kind;
    w3d_actor_method_member_initialize(&move->action);
    preserved = move->action.preserved;
    move->action = *action;
    move->action.preserved = preserved;
    w3d_move_vector_push(&queue->moves, move);
}

void w3d_move_queue_add_delay(W3dMoveQueue *queue, float value)
{
    W3dMoveTimed *move = (W3dMoveTimed *)w3d_heap_allocate_entry_a(sizeof(W3dMoveTimed));
    move->value = value;
    move->kind = 12;
    w3d_move_vector_push(&queue->moves, move);
}

void w3d_move_queue_push_front(W3dMoveQueue *queue, const W3dMovePosition *position, int kind)
{
    void **at = queue->moves.begin;
    W3dMove *move = (W3dMove *)w3d_heap_allocate_entry_a(sizeof(W3dMove));
    W3dMoveVector *vector = &queue->moves;
    void *const &item = move;
    move->position = *position;
    move->kind = kind;
    if (vector->end == vector->capacity) {
        int index = at - vector->begin;
        w3d_move_vector_grow(vector);
        at = vector->begin + index;
    }
    if (at == vector->end) {
        *at = item;
        vector->end++;
    } else {
        void *copy = item;
        w3d_memmove_802eeef4(at + 1, at, (unsigned char *)vector->end - (unsigned char *)at);
        vector->end++;
        *at = copy;
    }
}

#endif

}


