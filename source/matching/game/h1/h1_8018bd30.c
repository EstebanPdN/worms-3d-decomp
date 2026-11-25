/* Shared-node derived constructor (session 47b5d14a, hand-matched). The
 * three 12-byte members are initialized through an inline helper whose
 * pointer parameter GCC 2.95 keeps in a register (stores at +8, +4); the
 * constructor body clears their first word. Field meanings are inferred. */

typedef struct W3dTriple_8018bd30 {
    int first;
    int second;
    int third;
} W3dTriple_8018bd30;
typedef struct W3dNode_8018bd30 {
    void *vtbl;
    unsigned char unknown_04[164];
    int words_a8[3];                /* +168 */
    W3dTriple_8018bd30 list_b4;     /* +180 */
    int unknown_c0;
    int unknown_c4;                 /* +196 */
    unsigned char member_c8[12];    /* +200 */
    unsigned char member_d4[12];    /* +212 */
    unsigned char member_e0[12];    /* +224 */
    unsigned char unknown_ec[12];
    unsigned char text_f8[4];       /* +248 */
    W3dTriple_8018bd30 list_fc;     /* +252 */
    W3dTriple_8018bd30 list_108;    /* +264 */
} W3dNode_8018bd30;
extern unsigned char w3d_vtable_80412f50[];
extern int w3d_sda_node_count_804ab6ac;
void *s9_construct_shared_node_8017990c(void *self);
void *w3d_construct_802109dc(void *member);
void *w3d_string_default(void *text);
static inline void w3d_h1_triple_init(W3dTriple_8018bd30 *t)
{
    t->third = 0;
    t->second = 0;
}
W3dNode_8018bd30 *w3d_h1_node_construct_8018bd30(W3dNode_8018bd30 *self)
{
    s9_construct_shared_node_8017990c(self);
    self->words_a8[0] = 0;
    self->vtbl = w3d_vtable_80412f50;
    self->words_a8[1] = 0;
    self->words_a8[2] = 0;
    w3d_h1_triple_init(&self->list_b4);
    self->list_b4.first = 0;
    self->unknown_c4 = 0;
    w3d_construct_802109dc(self->member_c8);
    w3d_construct_802109dc(self->member_d4);
    w3d_construct_802109dc(self->member_e0);
    w3d_string_default(self->text_f8);
    w3d_h1_triple_init(&self->list_fc);
    self->list_fc.first = 0;
    w3d_h1_triple_init(&self->list_108);
    self->list_108.first = 0;
    w3d_sda_node_count_804ab6ac++;
    return self;
}
