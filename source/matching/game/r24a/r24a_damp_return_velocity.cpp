// Worms 3D PAL GWMP8P rev0. Names are inferred; offsets describe PPC32.
// External data and calls remain unresolved ownership dependencies.
extern "C" {
struct ScorePair { int value; int unknown; };
extern ScorePair scores_80431c80[];
int w3d_r24a_sum_even_scores_8008da24()
{
    int total = 0;
    for (int index = 0; index < 40; index += 2) {
        total += scores_80431c80[index].value;
    }
    return total;
}

struct DampedValue {
    unsigned char unknown[136];
    float position; // +136
    float velocity; // +140
};
extern const float stiffness_8038989c[];
extern const float damping_803898a0[];
float w3d_r24a_damp_value_800dbd74(DampedValue *value)
{
    float position = value->position;
    float previous_velocity = value->velocity;
    float velocity = (-position * stiffness_8038989c[0] + previous_velocity) * damping_803898a0[0];
    value->velocity = velocity;
    value->position = position + velocity;
    return velocity;
}

struct QueueEntry {
    unsigned int first, second, third, fourth, untouched;
    void clear()
    {
        first = 0;
        second = 0;
        third = 0;
        fourth = 0;
    }
};
struct EntryQueue {
    unsigned char unknown[388];
    QueueEntry entries[8]; // +388, stride 20
    int count; // +548
};
QueueEntry *w3d_r24a_append_empty_entry_8016e908(EntryQueue *queue)
{
    QueueEntry *entry = &queue->entries[queue->count];
    entry->clear();
    queue->count++;
    return entry;
}

struct WordTriple { unsigned int x, y, z; };
struct TripleMemberObject {
    unsigned char unknown[28];
    WordTriple value; // +28
    unsigned char unknown40[28];
    unsigned char member[1]; // +68, full extent unresolved
};
void member_query_801262c0(void *);
void w3d_r24a_set_triple_query_8003e1f8(TripleMemberObject *object, const WordTriple *value)
{
    unsigned int x = value->x;
    unsigned int y = value->y;
    unsigned int z = value->z;
    object->value.x = x;
    object->value.z = z;
    object->value.y = y;
    member_query_801262c0(object->member);
}

struct RetainedInterface;
struct RetainDispatch {
    void (*unknown[3])();
    void (*retain)(RetainedInterface *); // +12
};
struct RetainedInterface { RetainDispatch *dispatch; };
struct InterfaceHolder { RetainedInterface *held; };
struct InterfaceSource {
    unsigned char unknown[40];
    RetainedInterface *held; // +40
};
InterfaceHolder *w3d_r24a_copy_retain_800ccd04(InterfaceHolder *holder, InterfaceSource *source)
{
    RetainedInterface *held = source->held;
    holder->held = held;
    if (held) {
        held->dispatch->retain(held);
    }
    return holder;
}
}
