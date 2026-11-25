/* Actor-derived constructor (session 47b5d14a, hand-matched). The member
 * initializer is a constructor returning its object; declaring it void
 * changes the scheduling of the vtable store. Field meanings are inferred. */

typedef struct W3dActor_80124edc {
    void *vtbl;
    unsigned char unknown_04[72];
    int words_4c[4];                /* +76 */
    int unknown_5c;                 /* +92 */
    int unknown_60;                 /* +96 */
    unsigned char handle[8];        /* +100 */
    int unknown_6c;                 /* +108 */
    int unknown_70;                 /* +112 */
    int unknown_74;                 /* +116 */
} W3dActor_80124edc;
extern unsigned char w3d_vtable_80410bd8[];
int w3d_actor_base_initialize(void *self);
void *w3d_actor_handle_member_initialize(void *member);
W3dActor_80124edc *w3d_h1_actor_construct_80124edc(W3dActor_80124edc *self)
{
    w3d_actor_base_initialize(self);
    self->unknown_5c = 0;
    self->unknown_60 = 0;
    *(void **)self = w3d_vtable_80410bd8;
    w3d_actor_handle_member_initialize(self->handle);
    self->unknown_74 = -1;
    self->unknown_6c = 0;
    self->words_4c[0] = 0;
    self->words_4c[1] = 0;
    self->words_4c[2] = 0;
    self->words_4c[3] = 0;
    self->unknown_70 = 0;
    return self;
}
