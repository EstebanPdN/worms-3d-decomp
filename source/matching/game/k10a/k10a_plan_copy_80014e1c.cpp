// Appears to copy-construct a path plan that carries an extra method member:
// the base plan is constructed and bitwise-copied (keeping the vtable chosen
// for this class), both held queue references are retained, the plan is tagged
// with kind 29 and its member is initialised.
struct K10aQueue
{
    char pad0[44];
    int references;           // +44
};

struct K10aRef
{
    int unknown;
    K10aQueue *pointer;
};

static inline void k10a_ref_init(K10aRef *ref) { ref->pointer = 0; }

struct K10aPlanBase
{
    int kind;                 // +0
    float score;              // +4
    int active;               // +8
    void *volatile vtable;    // +12
    int index;                // +16
    int weapon;               // +20
    char pad24[44];
    int flags;                // +68
    K10aRef first;            // +72
    K10aRef second;           // +80
    char pad88[16];
};

extern "C" void *memcpy(void *dst, const void *src, unsigned int size);
extern "C" void w3d_path_cost_construct(K10aPlanBase *plan);
extern "C" void * w3d_actor_method_member_initialize(void *member);
extern char w3d_vtable_8040d7b8[];
extern char w3d_vtable_8040cd20[];
extern const float w3d_f32_8036a52c[];

extern "C" K10aPlanBase *w3d_k10a_plan_copy_80014e1c(K10aPlanBase *dst, K10aPlanBase *src)
{
    w3d_path_cost_construct(dst);
    dst->vtable = w3d_vtable_8040d7b8;
    k10a_ref_init(&dst->first);
    k10a_ref_init(&dst->second);
    void *volatile saved;
    saved = dst->vtable;
    memcpy(dst, src, 104);
    dst->vtable = saved;
    dst->score = *w3d_f32_8036a52c;
    if (src->first.pointer)
    {
        dst->first.pointer = src->first.pointer;
        dst->first.pointer->references++;
    }
    if (src->second.pointer)
    {
        dst->second.pointer = src->second.pointer;
        dst->second.pointer->references++;
    }
    dst->flags = 1345;
    dst->vtable = w3d_vtable_8040cd20;
    w3d_actor_method_member_initialize((char *)dst + 104);
    dst->weapon = 29;
    dst->flags &= ~0x100;
    return dst;
}
