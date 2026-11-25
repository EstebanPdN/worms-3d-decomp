#include "w3d_ptr.h"
#line 1 "b_null.cpp"
/* "Null" scene-descriptor class (0x801825b8..0x80182a20): reference
 * counting, registration in its class record, construction and flag
 * accessors. The class record at 0x80361bc8 doubles as the list of live
 * objects with a u16 count at +0x22 (same scheme as shared_object_list).
 * Vtable 0x80412aa0: +0x08 query, +0x0c add_ref, +0x10 release, +0x14 class.
 */
#include "b_types2.h"

extern "C" {

typedef struct W3dNullClass {
    unsigned char unknown_00[0x20];
    unsigned short count; unsigned short w3d_flags_high;
} W3dNullClass;

typedef struct W3dNull {
    Ptr32<void> vtable;
    unsigned short references;     /* +0x04, also the list link */
    unsigned char unknown_06[0x14 - 0x06];
    W3dString name;                /* +0x14 */
    union {
        struct { char w3d_gap0[2]; unsigned char mode; unsigned char kind; } bytes;
        unsigned int word;         /* +0x18, bit 0x8000 = mode overridden */
    } state;
} W3dNull;

typedef struct W3dNullSource {
    Ptr32<const char> name;
    unsigned char kind;            /* +0x04 */
    unsigned char mode;            /* +0x05 */
} W3dNullSource;

/* Pooled XNullInstance objects (176 bytes each). Vtable +0x0c add_ref,
 * +0x10 release, +0x28 bind to a descriptor, +0x30 kind, +0x38 pool index,
 * +0x40 key.
 */
typedef struct W3dNullInstance W3dNullInstance;
typedef struct W3dNullInstanceVtbl {
    W3D_VTBL_HEAD(W3dNullInstance);
    Ptr32<void> slot_14[5];
    Ptr32<int (Ptr32<W3dNullInstance>, Ptr32<W3dNull>, int)> bind;
    Ptr32<void> slot_2c;
    Ptr32<int (Ptr32<W3dNullInstance>)> get_kind;
    Ptr32<void> slot_34;
    Ptr32<unsigned short (Ptr32<W3dNullInstance>)> get_index;
    Ptr32<void> slot_3c;
    Ptr32<int (Ptr32<W3dNullInstance>)> get_key;
} W3dNullInstanceVtbl;
struct W3dNullInstance {
    Ptr32<W3dNullInstanceVtbl> vt;
    unsigned char unknown_04[0xb0 - 0x04];
};

typedef struct W3dRefSlot { Ptr32<W3dObject> p; } W3dRefSlot;

static inline void w3d_ref_slot_set(Ptr32<W3dRefSlot> slot, Ptr32<W3dObject> value)
{
    if (value)
        value->vt->add_ref(value);
    if (slot->p)
        slot->p->vt->release(slot->p);
    slot->p = value;
}

extern Ptr32<W3dNullInstance> w3d_null_pool_804ab634;
extern unsigned short w3d_null_pool_size_804ab638;
extern Ptr32<unsigned short> w3d_null_free_stack_804ab640;
extern unsigned short w3d_null_free_count_804ab644;
extern int w3d_null_kind_counts_804a89d8[];
extern unsigned char w3d_null_instance_vtable_80412b00[];
extern int w3d_null_instance_count_804ab64c;
extern const char w3d_str_803a78b8[];
extern const char w3d_str_803a7918[];

int w3d_descriptor_attach_80190438(Ptr32<W3dNull> self, Ptr32<W3dRefSlot> out, int mode);
void w3d_descriptor_detach_80190458(Ptr32<W3dNull> self, Ptr32<W3dNullInstance> instance);
int w3d_descriptor_method_801904c0(Ptr32<void> self, Ptr32<void> a, Ptr32<void> b);
int w3d_descriptor_method_80190538(Ptr32<void> self, Ptr32<void> a, Ptr32<void> b);
int w3d_instance_in_use_80185b0c(Ptr32<W3dNullInstance> instance);
Ptr32<void> w3d_component_construct_8017990c(Ptr32<void> self);
void w3d_component_destruct_801799d4(Ptr32<void> self, int flags);

extern W3dNullClass w3d_null_class_80361bc8;
extern unsigned char w3d_null_interfaces_803a78dc[];
extern unsigned char w3d_null_vtable_80412aa0[];
extern int w3d_null_count_804ab63c;

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_state_register(Ptr32<W3dNullClass> list, Ptr32<void> link);
void w3d_owner_list_remove(Ptr32<W3dNullClass> list, Ptr32<void> link);
void w3d_base_destroy(Ptr32<void> object, int flags);
int w3d_descriptor_construct_801902e8(Ptr32<void> object);
int w3d_query_interface_8020b460(Ptr32<void> object, Ptr32<void> interfaces, Ptr32<const void> iid, Ptr32<Ptr32<void>> out);
Ptr32<W3dString> w3d_string_assign(Ptr32<W3dString> string, Ptr32<const char> text);
Ptr32<W3dNull> w3d_null_lookup_8034cc30(Ptr32<void> key);

Ptr32<W3dNull> w3d_null_construct(Ptr32<W3dNull> self);
void w3d_null_destruct(Ptr32<W3dNull> self, int flags);

Ptr32<W3dNullClass> w3d_null_get_class(void)
{
    return &w3d_null_class_80361bc8;
}

void w3d_null_unlink(Ptr32<W3dNull> self)
{
    w3d_owner_list_remove(&w3d_null_class_80361bc8, &self->references);
    w3d_null_class_80361bc8.count--;
}

Ptr32<W3dNull> w3d_null_create(void)
{
    Ptr32<W3dNull> self = w3d_null_construct((Ptr32<W3dNull>)w3d_heap_allocate_entry_a(0x20));
    w3d_state_register(&w3d_null_class_80361bc8, self ? w3d::R(&self->references) : 0);
    w3d_null_class_80361bc8.count++;
    return self;
}

Ptr32<void> w3d_null_interfaces(void)
{
    return w3d_null_interfaces_803a78dc;
}

unsigned short w3d_null_release(Ptr32<W3dNull> self)
{
    unsigned short remaining = --self->references;
    if (remaining == 0) {
        w3d_null_unlink(self);
        if (self)
            w3d_null_destruct(self, 3);
    }
    return remaining;
}

unsigned short w3d_null_add_ref(Ptr32<W3dNull> self)
{
    return self->references++;
}

int w3d_null_query_interface(Ptr32<W3dNull> self, Ptr32<const void> iid, Ptr32<Ptr32<void>> out)
{
    return w3d_query_interface_8020b460(self, w3d_null_interfaces(), iid, out);
}

Ptr32<W3dNull> w3d_null_construct(Ptr32<W3dNull> self)
{
    w3d_descriptor_construct_801902e8(self);
    self->vtable = w3d_null_vtable_80412aa0;
    w3d_null_count_804ab63c++;
    return self;
}

int w3d_null_load(Ptr32<W3dNull> self, Ptr32<W3dNullSource> source)
{
    w3d_string_assign(&self->name, source->name);
    self->state.bytes.kind = source->kind;
    self->state.bytes.mode = source->mode;
    self->state.word &= ~0x8000;
    return 0;
}

int w3d_null_copy_mode(Ptr32<W3dNull> self, Ptr32<void> key)
{
    self->state.bytes.mode = w3d_null_lookup_8034cc30(key)->state.bytes.mode;
    self->state.word |= 0x8000;
    return 0;
}

void w3d_null_destruct(Ptr32<W3dNull> self, int flags)
{
    self->vtable = w3d_null_vtable_80412aa0;
    w3d_null_count_804ab63c--;
    w3d_base_destroy(self, flags);
}

unsigned short w3d_null_pool_size(void)
{
    return w3d_null_pool_size_804ab638;
}

unsigned short w3d_null_pool_used(void)
{
    return w3d_null_pool_size_804ab638 - w3d_null_free_count_804ab644;
}

int w3d_null_set_override(Ptr32<W3dNull> self)
{
    self->state.word |= 0x8000;
    return 0;
}

int w3d_null_check_override(Ptr32<W3dNull> self)
{
    if (!(self->state.word & 0x8000))
        return W3D_E_FAIL;
    return 0;
}

int w3d_null_clear_override(Ptr32<W3dNull> self)
{
    self->state.word &= ~0x8000;
    return 0;
}

#if 0 /* 0x80182a24: pool address formed as offset+base (add. r30,r31,r29), mine base+offset.
        * 0x80182b20: counts-array address materialized before the first call; original after it. */
int w3d_null_create_instance(W3dNull *self, W3dRefSlot *out, int mode)
{
    int result;
    W3dNullInstance *instance;
    if (w3d_null_free_count_804ab644 == 0)
        return W3D_E_FAIL;
    if (mode == 255)
        mode = self->state.bytes.mode;
    instance = &w3d_null_pool_804ab634[w3d_null_free_stack_804ab640[--w3d_null_free_count_804ab644]];
    w3d_ref_slot_set(out, (W3dObject *)instance);
    result = instance->vt->bind(instance, self, mode);
    if (result >= 0) {
        w3d_null_kind_counts_804a89d8[self->state.bytes.kind]++;
        result = w3d_descriptor_attach_80190438(self, out, 255);
    }
    return result;
}

int w3d_null_release_instance(W3dNull *self, W3dNullInstance *instance)
{
    w3d_descriptor_detach_80190458(self, instance);
    w3d_null_kind_counts_804a89d8[instance->vt->get_kind(instance)]--;
    w3d_null_free_stack_804ab640[w3d_null_free_count_804ab644++] = instance->vt->get_index(instance);
    return 0;
}

#endif

int w3d_null_find_instance(int key)
{
    int i;
    for (i = 0; i < w3d_null_pool_size_804ab638; i++) {
        if (w3d_instance_in_use_80185b0c(&w3d_null_pool_804ab634[i])
            && key == w3d_null_pool_804ab634[i].vt->get_key(&w3d_null_pool_804ab634[i]))
            break;
    }
    return i == w3d_null_pool_size_804ab638 ? -1 : i;
}

Ptr32<W3dNullInstance> w3d_null_next_instance(int key, Ptr32<int> cursor)
{
    Ptr32<W3dNullInstance> result;
    if (*cursor < 0)
        return 0;
    result = &w3d_null_pool_804ab634[*cursor];
    for (; *cursor < w3d_null_pool_size_804ab638; (*cursor)++) {
        if (w3d_instance_in_use_80185b0c(&w3d_null_pool_804ab634[*cursor])
            && key == w3d_null_pool_804ab634[*cursor].vt->get_key(&w3d_null_pool_804ab634[*cursor]))
            break;
    }
    if (*cursor == w3d_null_pool_size_804ab638)
        *cursor = -1;
    return result;
}

int w3d_null_method_801904c0(Ptr32<void> self, Ptr32<void> a, Ptr32<void> b)
{
    return w3d_descriptor_method_801904c0(self, a, b);
}

int w3d_null_method_80190538(Ptr32<void> self, Ptr32<void> a, Ptr32<void> b)
{
    return w3d_descriptor_method_80190538(self, a, b);
}

int w3d_null_type_id(void)
{
    return 6;
}

Ptr32<const char> w3d_null_type_name(void)
{
    return w3d_str_803a78b8;
}

Ptr32<W3dNullInstance> w3d_null_instance_construct(Ptr32<W3dNullInstance> self)
{
    w3d_component_construct_8017990c(self);
    self->vt = (Ptr32<W3dNullInstanceVtbl>)w3d_null_instance_vtable_80412b00;
    w3d_null_instance_count_804ab64c++;
    return self;
}

void w3d_null_instance_destruct(Ptr32<W3dNullInstance> self, int flags)
{
    self->vt = (Ptr32<W3dNullInstanceVtbl>)w3d_null_instance_vtable_80412b00;
    w3d_null_instance_count_804ab64c--;
    w3d_component_destruct_801799d4(self, flags);
}

int w3d_null_instance_type_id(void)
{
    return 6;
}

Ptr32<const char> w3d_null_instance_type_name(void)
{
    return w3d_str_803a7918;
}

}


