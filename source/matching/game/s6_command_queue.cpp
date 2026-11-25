/* Command queue storage; layouts describe observed byte offsets. */
extern "C" {
struct S6Command;
struct S6Vector { S6Command **begin; S6Command **end; S6Command **limit; };
struct S6Queue { char unknown[20]; S6Vector entries; };
struct S6Position { float x, y, z; };
struct S6Command { int type; S6Position position; };
void *w3d_heap_allocate_entry_a(unsigned int);
void *w3d_handle_storage_allocate(unsigned int);
void w3d_handle_storage_release(void *);
void *memcpy(void *, const void *, unsigned int, ...);
}
static inline const int &s6_max(const int &a, const int &b) { return a < b ? b : a; }
static inline const unsigned int &s6_min(const unsigned int &a, const unsigned int &b) { return b < a ? b : a; }
static inline void s6_push(S6Vector *v, void *const &entry) {
    if (v->end == v->limit) {
        unsigned int used = (char *)v->end - (char *)v->begin;
        unsigned int bytes = s6_max(used + 1, used + (used >> 1)) * 4;
        char *data = (char *)w3d_handle_storage_allocate(bytes);
        if (v->begin) {
            memcpy(data, v->begin, s6_min(bytes, used));
            w3d_handle_storage_release(v->begin);
        }
        char *nextEnd = data + used;
        char *nextLimit = data + bytes;
        v->begin = (S6Command **)data;
        v->end = (S6Command **)nextEnd;
        v->limit = (S6Command **)nextLimit;
    }
    *(void **)v->end = entry;
    v->end++;
}
#if 0 /* Eight attempts: instruction scheduling differs in the command copy. */
extern "C" void w3d_queue_position_command_80003424(S6Queue *queue, const S6Position *position, int type) {
    S6Command *command = (S6Command *)w3d_heap_allocate_entry_a(16);
    command->position = *position;
    command->type = type;
    s6_push(&queue->entries, command);
}

#endif

extern "C" {
struct S6ActorMember { int words[46]; };
struct S6ActorCommand { int type; S6Position position; S6ActorMember member; };
void w3d_actor_method_member_initialize(void *);
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_queue_actor_command_80003558(S6Queue *queue, const S6Position *position, int type, const S6ActorMember *member) {
    S6Vector *v = &queue->entries;
    S6ActorCommand *command = (S6ActorCommand *)w3d_heap_allocate_entry_a(200);
    command->position = *position;
    command->type = type;
    w3d_actor_method_member_initialize(&command->member);
    struct { int word; } saved;
    saved.word = command->member.words[9];
    command->member = *member;
    command->member.words[9] = saved.word;
    s6_push(v, command);
}
#endif
#if 0 /* Not exact: register allocation or instruction scheduling differs. */
void w3d_queue_float_command_80003710(S6Queue *queue, float value) {
    S6Command *command = (S6Command *)w3d_heap_allocate_entry_a(16);
    struct { float word; int unused; } local;
    local.word = value;
    S6Vector *v = &queue->entries;
    S6Command **end = v->end;
    S6Command **limit = v->limit;
    *(float *)&command->position = local.word;
    command->type = 12;
    s6_push(v, command);
}
#endif
}
