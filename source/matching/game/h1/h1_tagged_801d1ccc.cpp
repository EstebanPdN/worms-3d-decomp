/* Constructors of the tagged object family (session 47b5d14a), hand-matched
 * with analysis/worker-reports/h1_tagtry.py from the tools/gen_tag_ctor_units.py
 * template and proven identical to the original after linking. The inlined
 * base constructor sets the tag type byte to 2 (volatile, because the
 * original reloads it), clears the pair through an inline initializer and
 * the tag halves, then the derived constructor installs its vtable and sets
 * its own fields. Names are structural (original address). */
extern "C" {

typedef struct W3dTagPair {
    int first;
    int second;
} W3dTagPair;

typedef struct W3dTag {
    unsigned short a;
    unsigned short b;
    union {
        unsigned int word;
        volatile unsigned char byte[4];
    } u;
} W3dTag;

typedef struct W3dTagged {
    void **vtbl;
    W3dTag tag;
    W3dTagPair pair;
} W3dTagged;

static inline void w3d_tag_pair_init(W3dTagPair *pair)
{
    pair->second = 0;
}

static inline void w3d_tag_triple_init(void *p)
{
    ((int *)p)[2] = 0;
    ((int *)p)[1] = 0;
}

extern unsigned char w3d_vtable_80416408[];
extern unsigned char w3d_vtable_80416468[];

typedef struct W3dListNode {
    int value;
    int unknown_04;
    struct W3dListNode *prev;       /* +8 */
    struct W3dListNode *next;       /* +12 */
} W3dListNode;

typedef struct W3dList {
    int unknown_00;
    W3dListNode *head;              /* +4 */
    int count;                      /* +8 */
    unsigned char flag;             /* +12 */
} W3dList;

void *w3d_handle_storage_allocate(int size);

void *w3d_handle_storage_fallback(int size);

static inline W3dListNode *w3d_list_node_allocate(int size)
{
    W3dListNode *node = (W3dListNode *)w3d_handle_storage_allocate(size);
    if (!node)
        node = (W3dListNode *)w3d_handle_storage_fallback(size);
    return node;
}

static inline void w3d_list_init(W3dList *list, int size)
{
    list->head = 0;
    list->head = w3d_list_node_allocate(size);
    list->count = 0;
    list->flag = 0;
    list->head->value = 0;
    list->head->unknown_04 = 0;
    list->head->prev = list->head;
    list->head->next = list->head;
}

void *fn_80203204(void *member);

void *w3d_s21_construct_list_8020351c(void *member);

#define W3D_PAIR(off) ((W3dTagPair *)((char *)self + (off)))

#define W3D_INT(off) (*(int *)((char *)self + (off)))

typedef struct W3dRef W3dRef;

typedef struct W3dRefVtbl {
    void *slots[3];
    void (*retain)(W3dRef *self);              /* +12 */
    void (*release)(W3dRef *self);             /* +16 */
} W3dRefVtbl;

struct W3dRef {
    W3dRefVtbl *vtbl;
};

extern unsigned char w3d_type_80416630[];

W3dRef *w3d_s10_service_forward_8020b680(void *type);

W3dTagged *w3d_tagged_construct_801d1ccc(W3dTagged *self)
{
    W3dTag *tag = &self->tag;
    self->vtbl = (void **)w3d_vtable_80416468;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (void **)w3d_vtable_80416408;
    W3dRef *ref;
    W3dRef *old;
    volatile char pad[48];
    w3d_list_init((W3dList *)((char *)self + 20), 84);
    w3d_list_init((W3dList *)((char *)self + 36), 84);
    w3d_list_init((W3dList *)((char *)self + 52), 84);
    W3D_INT(68) = 0;
    ref = w3d_s10_service_forward_8020b680(w3d_type_80416630);
    if (ref)
        ref->vtbl->retain(ref);
    old = *(W3dRef **)((char *)self + 68);
    if (old)
        old->vtbl->release(old);
    *(W3dRef **)((char *)self + 68) = ref;
    return self;
}

}
