#include "w3d_ptr.h"
#line 1 "h1_tagged_801d1ccc.cpp"
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
        w3d::be_array<volatile unsigned char, 4> byte;
    } u;
} W3dTag;

typedef struct W3dTagged {
    Ptr32<Ptr32<void>> vtbl;
    W3dTag tag;
    W3dTagPair pair;
} W3dTagged;

static inline void w3d_tag_pair_init(Ptr32<W3dTagPair> pair)
{
    pair->second = 0;
}

static inline void w3d_tag_triple_init(Ptr32<void> p)
{
    ((Ptr32<int>)p)[2] = 0;
    ((Ptr32<int>)p)[1] = 0;
}

extern unsigned char w3d_vtable_80416408[];
extern unsigned char w3d_vtable_80416468[];

typedef struct W3dListNode {
    int value;
    int unknown_04;
    Ptr32<struct W3dListNode> prev;       /* +8 */
    Ptr32<struct W3dListNode> next;       /* +12 */
} W3dListNode;

typedef struct W3dList {
    int unknown_00;
    Ptr32<W3dListNode> head;              /* +4 */
    int count;                      /* +8 */
    unsigned char flag;             /* +12 */
} W3dList;

Ptr32<void> w3d_handle_storage_allocate(int size);

Ptr32<void> w3d_handle_storage_fallback(int size);

static inline Ptr32<W3dListNode> w3d_list_node_allocate(int size)
{
    Ptr32<W3dListNode> node = (Ptr32<W3dListNode>)w3d_handle_storage_allocate(size);
    if (!node)
        node = (Ptr32<W3dListNode>)w3d_handle_storage_fallback(size);
    return node;
}

static inline void w3d_list_init(Ptr32<W3dList> list, int size)
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

Ptr32<void> fn_80203204(Ptr32<void> member);

Ptr32<void> w3d_s21_construct_list_8020351c(Ptr32<void> member);

#define W3D_PAIR(off) ((W3dTagPair *)w3d::AG((char *)self + (off)))

#define W3D_INT(off) (*(int *)w3d::AG((char *)self + (off)))

typedef struct W3dRef W3dRef;

typedef struct W3dRefVtbl {
    Ptr32<void> slots[3];
    Ptr32<void (Ptr32<W3dRef>)> retain;              /* +12 */
    Ptr32<void (Ptr32<W3dRef>)> release;             /* +16 */
} W3dRefVtbl;

struct W3dRef {
    Ptr32<W3dRefVtbl> vtbl;
};

extern unsigned char w3d_type_80416630[];

Ptr32<W3dRef> w3d_s10_service_forward_8020b680(Ptr32<void> type);

Ptr32<W3dTagged> w3d_tagged_construct_801d1ccc(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80416468;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80416408;
    Ptr32<W3dRef> ref;
    Ptr32<W3dRef> old;
    volatile char pad[48];
    w3d_list_init((Ptr32<W3dList>)((Ptr32<char>)self + 20), 84);
    w3d_list_init((Ptr32<W3dList>)((Ptr32<char>)self + 36), 84);
    w3d_list_init((Ptr32<W3dList>)((Ptr32<char>)self + 52), 84);
    W3D_INT(68) = 0;
    ref = w3d_s10_service_forward_8020b680(w3d_type_80416630);
    if (ref)
        ref->vtbl->retain(ref);
    old = *(Ptr32<Ptr32<W3dRef>>)((Ptr32<char>)self + 68);
    if (old)
        old->vtbl->release(old);
    *(Ptr32<Ptr32<W3dRef>>)((Ptr32<char>)self + 68) = ref;
    return self;
}

}


