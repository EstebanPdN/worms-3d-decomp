/* "ParticleSet" descriptor and XParticleSetInstance (0x801832bc..0x801851dc).
 * Same registration scheme as the Null class (class record 0x80361bf8 with
 * a u16 live count at +0x22). Names inferred from behavior and type names.
 */
#include "b_types2.h"

extern "C" {

typedef struct W3dPSetClass {
    unsigned char unknown_00[0x22];
    unsigned short count;
} W3dPSetClass;

typedef struct W3dRefSlot { W3dObject *p; } W3dRefSlot;

static inline void w3d_ref_slot_set(W3dRefSlot *slot, W3dObject *value)
{
    if (value)
        value->vt->add_ref(value);
    if (slot->p)
        slot->p->vt->release(slot->p);
    slot->p = value;
}

static inline void w3d_ref_slot_assign(W3dRefSlot *slot, W3dObject *value)
{
    if (slot->p)
        slot->p->vt->release(slot->p);
    slot->p = value;
}

/* 8-byte local reference holder (the original reserves 8-aligned slots). */
struct W3dLocalRef {
    W3dObject *p;
    int unknown_04;
    W3dLocalRef() : p(0) {}
    W3dLocalRef(W3dObject *object) : p(object) { if (p) p->vt->add_ref(p); }
    ~W3dLocalRef() { if (p) p->vt->release(p); }
};

typedef struct W3dEffectGroup {
    unsigned char unknown_00[0x20];
    W3dObject *emitter;            /* +0x20 */
    unsigned char unknown_24[0x34 - 0x24];
    W3dObject *effect;             /* +0x34 */
} W3dEffectGroup;

typedef struct W3dEffectHolder {
    unsigned char unknown_00[0x2c];
    W3dEffectGroup *group;         /* +0x2c */
} W3dEffectHolder;

typedef struct W3dPSet {
    void *vtable;
    unsigned short references;     /* +0x04, also the list link */
    unsigned char unknown_06[0x18 - 0x06];
    union {
        struct {
            unsigned char kind;    /* +0x18 */
            unsigned char mode;    /* +0x19 */
        } bytes;
        unsigned int word;         /* +0x18, bit 0x8000 = settings overridden */
    } state;
    unsigned char unknown_1c[0x20 - 0x1c];
    unsigned int value_20;
    unsigned short value_24;
    unsigned short value_26;
    unsigned char value_28;
    unsigned char unknown_29[0x2c - 0x29];
    W3dEffectGroup *group;         /* +0x2c, referenced */
    W3dEffectHolder *holder;       /* +0x30, referenced */
    unsigned short flags;          /* +0x34 */
} W3dPSet;

/* Serializer used by save/load: +0x20 writes or reads a named reference. */
typedef struct W3dArchive W3dArchive;
typedef struct W3dArchiveVtbl {
    void *slot_00[8];
    void (*reference)(W3dArchive *self, void *value, const char *name);
} W3dArchiveVtbl;
struct W3dArchive { W3dArchiveVtbl *vt; };

typedef struct W3dPSetInstance {
    void *vtable;
    unsigned char unknown_04[0xa8 - 0x04];
    W3dObject *emitter;            /* +0xa8, referenced */
} W3dPSetInstance;

extern W3dPSetClass w3d_pset_class_80361bf8;
extern unsigned char w3d_pset_interfaces_803a7974[];
extern unsigned char w3d_pset_instance_vtable_80412c40[];
extern int w3d_pset_instance_count_804ab674;
extern unsigned short w3d_pset_pool_size_804ab65c;
extern unsigned short w3d_pset_free_count_804ab668;
extern void *w3d_pset_state_off_804b01f0;
extern void *w3d_pset_state_on_804b01f4;
extern void *w3d_pset_state_off_804b01d8;
extern void *w3d_pset_state_on_804b01d4;
extern void *w3d_pset_state_off_804b01e4;
extern void *w3d_pset_state_on_804b01e8;
extern const char w3d_str_803a7944[];
extern const char w3d_str_803a7a30[];
extern const char w3d_str_803a7a64[];

void *w3d_heap_allocate_entry_a(unsigned int size);
void w3d_state_register(W3dPSetClass *list, void *link);
void w3d_owner_list_remove(W3dPSetClass *list, void *link);
W3dPSet *w3d_pset_construct_80183434(W3dPSet *self);
void w3d_pset_destruct_80183ae8(W3dPSet *self, int flags);
int w3d_query_interface_8020b460(void *object, void *interfaces, const void *iid, void **out);
W3dPSet *w3d_pset_lookup_8034cc34(void *key);
int w3d_effect_set_state_801d4544(W3dObject *effect, void *state);
int w3d_descriptor_save_801904c0(W3dPSet *self, W3dArchive *archive);
int w3d_descriptor_load_80190538(W3dPSet *self, W3dArchive *archive);
void * w3d_component_construct_8017990c(void *self);
void w3d_component_destruct_801799d4(void *self, int flags);

W3dPSetClass *w3d_pset_get_class(void)
{
    return &w3d_pset_class_80361bf8;
}

void w3d_pset_unlink(W3dPSet *self)
{
    w3d_owner_list_remove(&w3d_pset_class_80361bf8, &self->references);
    w3d_pset_class_80361bf8.count--;
}

W3dPSet *w3d_pset_create(void)
{
    W3dPSet *self = w3d_pset_construct_80183434((W3dPSet *)w3d_heap_allocate_entry_a(0x38));
    w3d_state_register(&w3d_pset_class_80361bf8, self ? &self->references : 0);
    w3d_pset_class_80361bf8.count++;
    return self;
}

void *w3d_pset_interfaces(void)
{
    return w3d_pset_interfaces_803a7974;
}

unsigned short w3d_pset_release(W3dPSet *self)
{
    unsigned short remaining = --self->references;
    if (remaining == 0) {
        w3d_pset_unlink(self);
        if (self)
            w3d_pset_destruct_80183ae8(self, 3);
    }
    return remaining;
}

unsigned short w3d_pset_add_ref(W3dPSet *self)
{
    return self->references++;
}

int w3d_pset_query_interface(W3dPSet *self, const void *iid, void **out)
{
    return w3d_query_interface_8020b460(self, w3d_pset_interfaces(), iid, out);
}

int w3d_pset_copy_settings(W3dPSet *self, void *key)
{
    W3dPSet *source = w3d_pset_lookup_8034cc34(key);
    self->state.bytes.mode = source->state.bytes.mode;
    self->value_20 = source->value_20;
    self->value_24 = source->value_24;
    self->value_26 = source->value_26;
    self->value_28 = source->value_28;
    self->state.word |= 0x8000;
    self->flags = source->flags;
    w3d_ref_slot_set((W3dRefSlot *)&self->group, self->holder->group->emitter);
    return 0;
}

unsigned short w3d_pset_pool_size(void)
{
    return w3d_pset_pool_size_804ab65c;
}

unsigned short w3d_pset_pool_used(void)
{
    return w3d_pset_pool_size_804ab65c - w3d_pset_free_count_804ab668;
}

int w3d_pset_check_override(W3dPSet *self)
{
    if (!(self->state.word & 0x8000))
        return W3D_E_FAIL;
    return 0;
}

int w3d_pset_reset(W3dPSet *self)
{
    self->state.word &= ~0x8000;
    w3d_ref_slot_assign((W3dRefSlot *)&self->group, 0);
    w3d_ref_slot_assign((W3dRefSlot *)&self->holder, 0);
    return 0;
}

int w3d_pset_set_flag_0(W3dPSet *self, int on)
{
    W3dLocalRef effect(self->group->effect);
    if (on == 0) {
        w3d_effect_set_state_801d4544(effect.p, w3d_pset_state_off_804b01f0);
        self->flags &= ~1;
    } else {
        w3d_effect_set_state_801d4544(effect.p, w3d_pset_state_on_804b01f4);
        self->flags |= 1;
    }
    return 0;
}

int w3d_pset_set_flag_1(W3dPSet *self, int on)
{
    W3dLocalRef effect(self->group->effect);
    if (on == 0) {
        w3d_effect_set_state_801d4544(effect.p, w3d_pset_state_off_804b01d8);
        self->flags &= ~2;
    } else {
        w3d_effect_set_state_801d4544(effect.p, w3d_pset_state_on_804b01d4);
        self->flags |= 2;
    }
    return 0;
}

int w3d_pset_set_flag_4(W3dPSet *self, int on)
{
    W3dLocalRef effect(self->group->effect);
    if (on == 0) {
        w3d_effect_set_state_801d4544(effect.p, w3d_pset_state_off_804b01e4);
        self->flags &= ~0x10;
    } else {
        w3d_effect_set_state_801d4544(effect.p, w3d_pset_state_on_804b01e8);
        self->flags |= 0x10;
    }
    return 0;
}

int w3d_pset_save(W3dPSet *self, W3dArchive *archive)
{
    int result = w3d_descriptor_save_801904c0(self, archive);
    if (result >= 0) {
        archive->vt->reference(archive, self->holder, w3d_str_803a7a30);
        result = (int)0x80004001;
    }
    return result;
}

int w3d_pset_load(W3dPSet *self, W3dArchive *archive)
{
    int result = w3d_descriptor_load_80190538(self, archive);
    if (result >= 0) {
        {
            W3dLocalRef holder;
            archive->vt->reference(archive, &holder.p, w3d_str_803a7a30);
            w3d_ref_slot_set((W3dRefSlot *)&self->holder, holder.p);
        }
        result = (int)0x80004001;
    }
    return result;
}

int w3d_pset_type_id(void)
{
    return 4;
}

const char *w3d_pset_type_name(void)
{
    return w3d_str_803a7944;
}

unsigned int w3d_pset_flag_0(W3dPSet *self)
{
    return self->flags & 1;
}

unsigned int w3d_pset_flag_1(W3dPSet *self)
{
    return (self->flags >> 1) & 1;
}

unsigned int w3d_pset_flag_4(W3dPSet *self)
{
    return (self->flags >> 4) & 1;
}

W3dPSetInstance *w3d_pset_instance_construct(W3dPSetInstance *self)
{
    w3d_component_construct_8017990c(self);
    self->vtable = w3d_pset_instance_vtable_80412c40;
    self->emitter = 0;
    w3d_pset_instance_count_804ab674++;
    return self;
}

void w3d_pset_instance_destruct(W3dPSetInstance *self, int flags)
{
    self->vtable = w3d_pset_instance_vtable_80412c40;
    w3d_pset_instance_count_804ab674--;
    if (self->emitter)
        self->emitter->vt->release(self->emitter);
    w3d_component_destruct_801799d4(self, flags);
}

int w3d_pset_instance_type_id(void)
{
    return 4;
}

const char *w3d_pset_instance_type_name(void)
{
    return w3d_str_803a7a64;
}

}
