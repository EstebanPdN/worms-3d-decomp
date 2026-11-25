/* Scene-node accessors (0x8018697c..0x801869e0) and the start of the
 * "SpriteSet" descriptor class (0x801869e4..0x80186b58): registration in its
 * class record 0x80361c28 (u16 live count at +0x22) and reference counting.
 * Names are inferred from behavior and nearby type-name strings.
 */
#include "b_types2.h"

extern "C" {

typedef struct W3dVec3 {
    float x, y, z;
} W3dVec3;

typedef struct W3dNode {
    void *vtable;
    unsigned char type;        /* +0x04 */
    unsigned char unknown_05;
    unsigned short slot;       /* +0x06 */
    unsigned int id : 16;      /* +0x08 */
    unsigned int references : 15;
    unsigned int flag : 1;
    W3dVec3 position;          /* +0x0c */
    W3dVec3 rotation;          /* +0x18 */
    W3dVec3 scale;             /* +0x24 */
    void *parent;              /* +0x30 */
    unsigned char unknown_34[0x68 - 0x34];
    void **children_begin;     /* +0x68 */
    void **children_end;       /* +0x6c */
    void **children_capacity;  /* +0x70 */
    W3dObject *attachment;     /* +0x74 */
} W3dNode;

typedef struct W3dSpriteSetClass {
    unsigned char unknown_00[0x22];
    unsigned short count;
} W3dSpriteSetClass;

typedef struct W3dSpriteSet {
    void *vtable;
    unsigned short references;     /* +0x04, also the list link */
} W3dSpriteSet;

extern W3dSpriteSetClass w3d_sprite_set_class_80361c28;
extern unsigned char w3d_sprite_set_interfaces_803a7ae4[];

void *w3d_heap_allocate_entry_a(unsigned int size);
void w3d_state_register(W3dSpriteSetClass *list, void *link);
void w3d_owner_list_remove(W3dSpriteSetClass *list, void *link);
W3dSpriteSet *w3d_sprite_set_construct_80186b5c(W3dSpriteSet *self);
void w3d_sprite_set_destruct_80187380(W3dSpriteSet *self, int flags);
int w3d_query_interface_8020b460(void *object, void *interfaces, const void *iid, void **out);

W3dVec3 *w3d_node_position(W3dNode *self)
{
    return &self->position;
}

W3dVec3 *w3d_node_rotation(W3dNode *self)
{
    return &self->rotation;
}

W3dVec3 *w3d_node_scale(W3dNode *self)
{
    return &self->scale;
}

unsigned int w3d_node_flag(W3dNode *self)
{
    return self->flag;
}

unsigned char w3d_node_type(W3dNode *self)
{
    return self->type;
}

W3dObject *w3d_node_attachment(W3dNode *self)
{
    return self->attachment;
}

int w3d_node_child_count(W3dNode *self)
{
    return self->children_end - self->children_begin;
}

int w3d_node_has_parent(W3dNode *self)
{
    if (self->parent)
        return 1;
    return 0;
}

void *w3d_node_parent(W3dNode *self)
{
    return self->parent;
}

W3dSpriteSetClass *w3d_sprite_set_get_class(void)
{
    return &w3d_sprite_set_class_80361c28;
}

void w3d_sprite_set_unlink(W3dSpriteSet *self)
{
    w3d_owner_list_remove(&w3d_sprite_set_class_80361c28, &self->references);
    w3d_sprite_set_class_80361c28.count--;
}

W3dSpriteSet *w3d_sprite_set_create(void)
{
    W3dSpriteSet *self = w3d_sprite_set_construct_80186b5c((W3dSpriteSet *)w3d_heap_allocate_entry_a(0x3c));
    w3d_state_register(&w3d_sprite_set_class_80361c28, self ? &self->references : 0);
    w3d_sprite_set_class_80361c28.count++;
    return self;
}

void *w3d_sprite_set_interfaces(void)
{
    return w3d_sprite_set_interfaces_803a7ae4;
}

unsigned short w3d_sprite_set_release(W3dSpriteSet *self)
{
    unsigned short remaining = --self->references;
    if (remaining == 0) {
        w3d_sprite_set_unlink(self);
        if (self)
            w3d_sprite_set_destruct_80187380(self, 3);
    }
    return remaining;
}

unsigned short w3d_sprite_set_add_ref(W3dSpriteSet *self)
{
    return self->references++;
}

int w3d_sprite_set_query_interface(W3dSpriteSet *self, const void *iid, void **out)
{
    return w3d_query_interface_8020b460(self, w3d_sprite_set_interfaces(), iid, out);
}

}
