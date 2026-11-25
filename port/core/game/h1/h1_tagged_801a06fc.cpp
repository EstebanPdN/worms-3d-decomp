#include "w3d_ptr.h"
#line 1 "h1_tagged_801a06fc.cpp"
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

extern unsigned char w3d_vtable_80413428[];
extern unsigned char w3d_vtable_80413470[];
extern unsigned char w3d_vtable_804138d0[];
extern unsigned char w3d_vtable_80413920[];
extern unsigned char w3d_vtable_80416af8[];
extern unsigned char w3d_vtable_80416b50[];
extern unsigned char w3d_vtable_80416cc8[];
extern unsigned char w3d_vtable_80416d78[];
extern unsigned char w3d_vtable_804180d8[];
extern unsigned char w3d_vtable_80418110[];
extern unsigned char w3d_vtable_80418490[];
extern unsigned char w3d_vtable_804192d8[];
extern unsigned char w3d_vtable_80419510[];
extern unsigned char w3d_vtable_80419540[];
extern unsigned char w3d_vtable_80419668[];
extern unsigned char w3d_vtable_80419688[];
extern unsigned char w3d_vtable_80419700[];

typedef struct W3dHeld_8019895c W3dHeld_8019895c;

typedef struct W3dHeldVtbl_8019895c {
    Ptr32<void> slots[4];
    Ptr32<void (Ptr32<W3dHeld_8019895c>)> release;   /* +16 */
} W3dHeldVtbl_8019895c;

struct W3dHeld_8019895c {
    Ptr32<W3dHeldVtbl_8019895c> vtbl;
};

extern const float w3d_float_803a86d0[];

#define W3D_PAIR(off) ((W3dTagPair *)w3d::AG((char *)self + (off)))

extern const float w3d_float_803a9b04[];

extern const float w3d_float_803a9b08[];

extern const float w3d_float_803a9b0c[];

extern const float w3d_float_803a9b10[];

Ptr32<void> w3d_construct_801f67e0(Ptr32<void> member);

static inline void w3d_vec3_init_yz(Ptr32<void> v, float y, float z)
{
    ((Ptr32<float>)v)[1] = y;
    ((Ptr32<float>)v)[2] = z;
}

extern const float w3d_float_803b0328[];

extern const float w3d_float_803b032c[];

typedef struct W3dHeld_801dfbd4 W3dHeld_801dfbd4;

typedef struct W3dHeldVtbl_801dfbd4 {
    Ptr32<void> slots[4];
    Ptr32<void (Ptr32<W3dHeld_801dfbd4>)> release;   /* +16 */
} W3dHeldVtbl_801dfbd4;

struct W3dHeld_801dfbd4 {
    Ptr32<W3dHeldVtbl_801dfbd4> vtbl;
};

extern const float w3d_float_803b0404[];

extern Ptr32<void> w3d_sda_owner_804ab834;

Ptr32<void> w3d_construct_801e6ea8(Ptr32<void> member);

typedef struct W3dRef_801f83b4 W3dRef_801f83b4;

typedef struct W3dRefVtbl_801f83b4 {
    Ptr32<void> slots[3];
    Ptr32<void (Ptr32<W3dRef_801f83b4>)> retain;     /* +12 */
    Ptr32<void (Ptr32<W3dRef_801f83b4>)> release;    /* +16 */
} W3dRefVtbl_801f83b4;

struct W3dRef_801f83b4 {
    Ptr32<W3dRefVtbl_801f83b4> vtbl;
};

typedef struct W3dService_801f83b4 W3dService_801f83b4;

typedef struct W3dServiceVtbl_801f83b4 {
    Ptr32<void> slots[23];
    Ptr32<Ptr32<W3dRef_801f83b4> (Ptr32<W3dService_801f83b4>, Ptr32<void>)> find;  /* +92 */
} W3dServiceVtbl_801f83b4;

struct W3dService_801f83b4 {
    Ptr32<W3dServiceVtbl_801f83b4> vtbl;
};

extern unsigned char w3d_type_80418070[];

Ptr32<W3dService_801f83b4> w3d_auto_8020b648(void);

void fn_801f7f1c(Ptr32<W3dRef_801f83b4> ref, Ptr32<void> owner);

static inline Ptr32<W3dRef_801f83b4> w3d_find_service_ref(Ptr32<void> type)
{
    Ptr32<W3dService_801f83b4> service = w3d_auto_8020b648();
    return service->vtbl->find(service, type);
}

typedef struct W3dRef_802084f8 W3dRef_802084f8;

typedef struct W3dRefVtbl_802084f8 {
    Ptr32<void> slots[3];
    Ptr32<void (Ptr32<W3dRef_802084f8>)> retain;     /* +12 */
    Ptr32<void (Ptr32<W3dRef_802084f8>)> release;    /* +16 */
} W3dRefVtbl_802084f8;

struct W3dRef_802084f8 {
    Ptr32<W3dRefVtbl_802084f8> vtbl;
};

typedef struct W3dBits_802084f8 {
    unsigned int rest:11; unsigned int width:5; unsigned int level:8; unsigned int flag:1; unsigned int kind:7;
} W3dBits_802084f8;

Ptr32<void> w3d_string_default(Ptr32<void> text);

typedef struct W3dLink_802084f8 {
    Ptr32<void> target;
    W3dBits_802084f8 bits;
} W3dLink_802084f8;

static inline void w3d_link_init(Ptr32<W3dLink_802084f8> link, int kind, int width)
{
    link->target = 0;
    link->bits.kind = kind;
    link->bits.flag = 0;
    link->bits.level = 0;
    link->bits.width = width;
}

static inline void w3d_middle_init(Ptr32<W3dTagged> obj)
{
    obj->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80418490;
    w3d_link_init((Ptr32<W3dLink_802084f8>)((Ptr32<char>)obj + 20), 10, 6);
}

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

static inline void w3d_list_init(Ptr32<W3dList> list)
{
    list->head = 0;
    list->head = w3d_list_node_allocate(24);
    list->flag = 0;
    list->count = 0;
    list->head->value = 0;
    list->head->unknown_04 = 0;
    list->head->prev = list->head;
    list->head->next = list->head;
}

extern char w3d_string_localhost_803b35fc[];

extern Ptr32<void> w3d_sda_network_804b18fc;

Ptr32<void> w3d_string_from_text(Ptr32<void> text, Ptr32<const char> chars);

Ptr32<void> fn_8035e070(Ptr32<void> member);

typedef struct W3dEntry_802110cc { int a; int b; int c; } W3dEntry_802110cc;

Ptr32<W3dTagged> w3d_tagged_construct_8019895c(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80413470;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80413428;
    volatile char pad[24];
    Ptr32<W3dHeld_8019895c> held;
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 32) = 0;
    w3d_tag_pair_init(W3D_PAIR(32));
    w3d_tag_pair_init(W3D_PAIR(40));
    *(Ptr32<int>)((Ptr32<char>)self + 48) = 0;
    w3d_tag_pair_init(W3D_PAIR(48));
    w3d_tag_pair_init(W3D_PAIR(56));
    *(Ptr32<int>)((Ptr32<char>)self + 68) = 0;
    w3d_tag_pair_init(W3D_PAIR(68));
    w3d_tag_pair_init(W3D_PAIR(76));
    held = *(Ptr32<Ptr32<W3dHeld_8019895c>>)((Ptr32<char>)self + 20);
    if (held)
        held->vtbl->release(held);
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 64) = 0;
    *(Ptr32<float>)((Ptr32<char>)self + 24) = w3d_float_803a86d0[0];
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_801a06fc(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80413920;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804138d0;
    w3d_construct_801f67e0((Ptr32<char>)self + 20);
    w3d_construct_801f67e0((Ptr32<char>)self + 84);
    float b = w3d_float_803a9b0c[0];
    float a = w3d_float_803a9b10[0];
    float c = w3d_float_803a9b04[0];
    float d = w3d_float_803a9b08[0];
    *(Ptr32<int>)((Ptr32<char>)self + 172) = 0;
    *(Ptr32<float>)((Ptr32<char>)self + 168) = d;
    *(Ptr32<float>)((Ptr32<char>)self + 164) = c;
    *(Ptr32<float>)((Ptr32<char>)self + 148) = b;
    *(Ptr32<float>)((Ptr32<char>)self + 152) = b;
    *(Ptr32<float>)((Ptr32<char>)self + 156) = b;
    *(Ptr32<float>)((Ptr32<char>)self + 160) = b;
    *(Ptr32<float>)((Ptr32<char>)self + 176) = a;
    w3d_vec3_init_yz((Ptr32<char>)self + 176, a, a);
    *(Ptr32<float>)((Ptr32<char>)self + 188) = a;
    w3d_vec3_init_yz((Ptr32<char>)self + 188, a, b);
    *(Ptr32<float>)((Ptr32<char>)self + 200) = a;
    w3d_vec3_init_yz((Ptr32<char>)self + 200, c, a);
    *(Ptr32<int>)((Ptr32<char>)self + 212) = 1;
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_801de81c(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80416b50;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80416af8;
    float zero = w3d_float_803b0328[0];
    float one = w3d_float_803b032c[0];
    *(Ptr32<float>)((Ptr32<char>)self + 20) = zero;
    w3d_vec3_init_yz((Ptr32<char>)self + 20, zero, zero);
    *(Ptr32<float>)((Ptr32<char>)self + 44) = zero;
    w3d_vec3_init_yz((Ptr32<char>)self + 44, one, zero);
    *(Ptr32<float>)((Ptr32<char>)self + 32) = zero;
    w3d_vec3_init_yz((Ptr32<char>)self + 32, zero, one);
    *(Ptr32<float>)((Ptr32<char>)self + 56) = zero;
    w3d_vec3_init_yz((Ptr32<char>)self + 56, zero, zero);
    *(Ptr32<float>)((Ptr32<char>)self + 68) = one;
    *(Ptr32<float>)((Ptr32<char>)self + 72) = one;
    *(Ptr32<float>)((Ptr32<char>)self + 76) = one;
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_801dfbd4(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80416d78;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80416cc8;
    Ptr32<W3dHeld_801dfbd4> held;
    Ptr32<int> words;
    int i;
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    w3d_tag_triple_init((Ptr32<char>)self + 36);
    *(Ptr32<int>)((Ptr32<char>)self + 36) = 0;
    w3d_construct_801e6ea8((Ptr32<char>)self + 176);
    held = *(Ptr32<Ptr32<W3dHeld_801dfbd4>>)((Ptr32<char>)self + 20);
    w3d_sda_owner_804ab834 = self;
    if (held)
        held->vtbl->release(held);
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    *(Ptr32<float>)((Ptr32<char>)self + 24) = w3d_float_803b0404[0];
    *(Ptr32<int>)((Ptr32<char>)self + 28) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 32) = 0;
    {
        int zero = 0;
        words = (Ptr32<int>)((Ptr32<char>)self + 48);
        for (i = 32; i != 0; i--)
            *words++ = zero;
    }
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_801f83b4(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80418110;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804180d8;
    Ptr32<W3dRef_801f83b4> ref;
    Ptr32<W3dRef_801f83b4> old;
    *(Ptr32<int>)((Ptr32<char>)self + 20) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 24) = 0;
    ref = w3d_find_service_ref(w3d_type_80418070);
    if (ref)
        ref->vtbl->retain(ref);
    old = *(Ptr32<Ptr32<W3dRef_801f83b4>>)((Ptr32<char>)self + 24);
    if (old)
        old->vtbl->release(old);
    *(Ptr32<Ptr32<W3dRef_801f83b4>>)((Ptr32<char>)self + 24) = ref;
    fn_801f7f1c(ref, self);
    *((Ptr32<unsigned char>)self + 28) = 0;
    *(Ptr32<int>)((Ptr32<char>)self + 36) = 0;
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_802084f8(Ptr32<W3dTagged> self, Ptr32<W3dRef_802084f8> source)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80418490;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    Ptr32<W3dRef_802084f8> me = (Ptr32<W3dRef_802084f8>)self;
    Ptr32<W3dRef_802084f8> old;
    w3d_middle_init(self);
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_804192d8;
    *(Ptr32<Ptr32<W3dRef_802084f8>>)((Ptr32<char>)self + 28) = source;
    if (source)
        source->vtbl->retain(source);
    w3d_string_default((Ptr32<char>)self + 32);
    if (me)
        me->vtbl->retain(me);
    old = *(Ptr32<Ptr32<W3dRef_802084f8>>)((Ptr32<char>)self + 20);
    if (old)
        old->vtbl->release(old);
    *(Ptr32<int>)((Ptr32<char>)self + 36) = 1;
    *(Ptr32<Ptr32<W3dRef_802084f8>>)((Ptr32<char>)self + 20) = me;
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_8020dfdc(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80419540;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80419510;
    volatile char pad[16];
    w3d_list_init((Ptr32<W3dList>)((Ptr32<char>)self + 20));
    return self;
}

Ptr32<W3dTagged> w3d_tagged_construct_802110cc(Ptr32<W3dTagged> self)
{
    Ptr32<W3dTag> tag = &self->tag;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80419700;
    tag->u.byte[3] = 2;
    tag->u.word = tag->u.byte[3];
    self->pair.first = 0;
    w3d_tag_pair_init(&self->pair);
    tag->a = 0;
    tag->b = 0;
    Ptr32<W3dEntry_802110cc> entry;
    int i;
    *(Ptr32<Ptr32<void>>)((Ptr32<char>)self + 20) = w3d_vtable_80419668;
    self->vtbl = (Ptr32<Ptr32<void>>)w3d_vtable_80419688;
    w3d_string_from_text((Ptr32<char>)self + 24, w3d_string_localhost_803b35fc);
    w3d_string_default((Ptr32<char>)self + 28);
    w3d_string_default((Ptr32<char>)self + 32);
    fn_8035e070((Ptr32<char>)self + 36);
    fn_8035e070((Ptr32<char>)self + 64);
    entry = (Ptr32<W3dEntry_802110cc>)((Ptr32<char>)self + 92);
    for (i = 13; i != 0; i--) {
        entry->c = 0;
        entry->b = 0;
        entry->a = 0;
        entry++;
    }
    fn_8035e070((Ptr32<char>)self + 248);
    w3d_sda_network_804b18fc = self;
    return self;
}

}


