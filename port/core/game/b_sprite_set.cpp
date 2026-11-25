#include "w3d_ptr.h"
#line 1 "b_sprite_set.cpp"
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
    Ptr32<void> vtable;
    unsigned char type;        /* +0x04 */
    unsigned char unknown_05;
    unsigned short slot;       /* +0x06 */
    unsigned int flag:1; unsigned int references:15; unsigned int id:16;
    W3dVec3 position;          /* +0x0c */
    W3dVec3 rotation;          /* +0x18 */
    W3dVec3 scale;             /* +0x24 */
    Ptr32<void> parent;              /* +0x30 */
    unsigned char unknown_34[0x68 - 0x34];
    Ptr32<Ptr32<void>> children_begin;     /* +0x68 */
    Ptr32<Ptr32<void>> children_end;       /* +0x6c */
    Ptr32<Ptr32<void>> children_capacity;  /* +0x70 */
    Ptr32<W3dObject> attachment;     /* +0x74 */
} W3dNode;

typedef struct W3dSpriteSetClass {
    unsigned char unknown_00[0x20];
    unsigned short count; unsigned short w3d_flags_high;
} W3dSpriteSetClass;

typedef struct W3dSpriteSet {
    Ptr32<void> vtable;
    unsigned short references;     /* +0x04, also the list link */
} W3dSpriteSet;

extern W3dSpriteSetClass w3d_sprite_set_class_80361c28;
extern unsigned char w3d_sprite_set_interfaces_803a7ae4[];

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_state_register(Ptr32<W3dSpriteSetClass> list, Ptr32<void> link);
void w3d_owner_list_remove(Ptr32<W3dSpriteSetClass> list, Ptr32<void> link);
Ptr32<W3dSpriteSet> w3d_sprite_set_construct_80186b5c(Ptr32<W3dSpriteSet> self);
void w3d_sprite_set_destruct_80187380(Ptr32<W3dSpriteSet> self, int flags);
int w3d_query_interface_8020b460(Ptr32<void> object, Ptr32<void> interfaces, Ptr32<const void> iid, Ptr32<Ptr32<void>> out);

Ptr32<W3dVec3> w3d_node_position(Ptr32<W3dNode> self)
{
    return &self->position;
}

Ptr32<W3dVec3> w3d_node_rotation(Ptr32<W3dNode> self)
{
    return &self->rotation;
}

Ptr32<W3dVec3> w3d_node_scale(Ptr32<W3dNode> self)
{
    return &self->scale;
}

unsigned int w3d_node_flag(Ptr32<W3dNode> self)
{
    return self->flag;
}

unsigned char w3d_node_type(Ptr32<W3dNode> self)
{
    return self->type;
}

Ptr32<W3dObject> w3d_node_attachment(Ptr32<W3dNode> self)
{
    return self->attachment;
}

int w3d_node_child_count(Ptr32<W3dNode> self)
{
    return self->children_end - self->children_begin;
}

int w3d_node_has_parent(Ptr32<W3dNode> self)
{
    if (self->parent)
        return 1;
    return 0;
}

Ptr32<void> w3d_node_parent(Ptr32<W3dNode> self)
{
    return self->parent;
}

Ptr32<W3dSpriteSetClass> w3d_sprite_set_get_class(void)
{
    return &w3d_sprite_set_class_80361c28;
}

void w3d_sprite_set_unlink(Ptr32<W3dSpriteSet> self)
{
    w3d_owner_list_remove(&w3d_sprite_set_class_80361c28, &self->references);
    w3d_sprite_set_class_80361c28.count--;
}

Ptr32<W3dSpriteSet> w3d_sprite_set_create(void)
{
    Ptr32<W3dSpriteSet> self = w3d_sprite_set_construct_80186b5c((Ptr32<W3dSpriteSet>)w3d_heap_allocate_entry_a(0x3c));
    w3d_state_register(&w3d_sprite_set_class_80361c28, self ? w3d::R(&self->references) : 0);
    w3d_sprite_set_class_80361c28.count++;
    return self;
}

Ptr32<void> w3d_sprite_set_interfaces(void)
{
    return w3d_sprite_set_interfaces_803a7ae4;
}

unsigned short w3d_sprite_set_release(Ptr32<W3dSpriteSet> self)
{
    unsigned short remaining = --self->references;
    if (remaining == 0) {
        w3d_sprite_set_unlink(self);
        if (self)
            w3d_sprite_set_destruct_80187380(self, 3);
    }
    return remaining;
}

unsigned short w3d_sprite_set_add_ref(Ptr32<W3dSpriteSet> self)
{
    return self->references++;
}

int w3d_sprite_set_query_interface(Ptr32<W3dSpriteSet> self, Ptr32<const void> iid, Ptr32<Ptr32<void>> out)
{
    return w3d_query_interface_8020b460(self, w3d_sprite_set_interfaces(), iid, out);
}

}


