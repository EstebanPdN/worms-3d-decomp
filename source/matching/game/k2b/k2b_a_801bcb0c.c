struct K2bVec3 { float x, y, z; };
struct K2bTag { unsigned char pad0[7]; unsigned char flags; };
struct K2bNode { void **vtable; struct K2bTag tag; unsigned char pad12[60]; struct K2bVec3 a; struct K2bVec3 b; struct K2bVec3 c; int link; };
extern void *w3d_vtable_80415280[];
extern int w3d_node_base_init_801bc6c4(struct K2bNode *self, void *);
static inline void k2b_vec3_fill(struct K2bVec3 *v, float value)
{
    v->x = value;
    v->y = value;
    v->z = value;
}
static inline void k2b_tag_set_flag(struct K2bTag *tag)
{
    tag->flags |= 2;
}
struct K2bNode *w3d_k2b_node_construct_801bcb0c(struct K2bNode *self, void * arg_r4)
{
    w3d_node_base_init_801bc6c4(self, arg_r4);
    self->vtable = w3d_vtable_80415280;
    k2b_vec3_fill(&self->a, 1.0f);
    k2b_vec3_fill(&self->b, 0.0f);
    k2b_vec3_fill(&self->c, 0.0f);
    self->link = 0;
    k2b_tag_set_flag(&self->tag);
    return self;
}
// desc: Appears to construct a node on its base constructor, install its vtable, set three vectors and a link, and set a flag bit.
