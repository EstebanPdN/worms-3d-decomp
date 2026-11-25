/* Hand-lifted component constructors and destructors (0x80068570..0x800beeb0).
 *
 * Names are inferred from behavior; no original symbols survive. These are
 * members of the shared component types whose bodies do more than clear
 * fields: they construct or finish embedded strings (4-byte string handles,
 * 0x803426b8 default-constructs one, 0x8020c5c4 + w3d_string_release finish
 * one), delete owned members, or publish the object in a small-data
 * instance pointer. Held interfaces use a 4-byte-entry vtable at +0 with the
 * release slot at +0x10.
 */
extern "C" {

typedef struct W3dInterface W3dInterface;

typedef struct W3dInterfaceTable {
    void *unknown_00[4];
    void (*release)(W3dInterface *object);
} W3dInterfaceTable;

struct W3dInterface {
    W3dInterfaceTable *vtable;
};

typedef struct W3dString {
    char *text;
} W3dString;

/* Two banks of ten names embedded at +0x78 of the type registered at 0x8006844c. */
typedef struct W3dNameBanks {
    unsigned char unknown_00[0x28];
    W3dString names_a[10];
    unsigned char unknown_50[0xa0 - 0x50];
    W3dString names_b[10];
} W3dNameBanks;

/* Type registered at 0x8006844c: two banks of ten names and two extra names. */
typedef struct W3dNamedComponent {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x06];
    W3dInterface *held_01c;
    W3dInterface *held_020;
    unsigned char unknown_024[0x60 - 0x24];
    W3dInterface *held_060;
    W3dInterface *held_064;
    void *member_068;
    W3dInterface *held_06c;
    unsigned char unknown_070[0x78 - 0x70];
    W3dNameBanks banks;
    unsigned char unknown_140[0x16c - 0x140];
    W3dString title;
    W3dString subtitle;
    W3dInterface *held_174;
    W3dInterface *held_178;
    W3dInterface *held_17c;
    W3dInterface *held_180;
    W3dInterface *held_184;
    W3dInterface *held_188;
} W3dNamedComponent;

/* Type registered at 0x80098a94: publishes itself while alive. */
typedef struct W3dSingletonComponent {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x40 - 0x06];
    void *handle_040;
} W3dSingletonComponent;

/* Type registered at 0x800a4f84: one name and one held interface. */
typedef struct W3dLabelComponent {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x06];
    W3dString label;
    W3dInterface *held_020;
} W3dLabelComponent;

/* Type registered at 0x800bed38: an owned member and three held interfaces. */
typedef struct W3dOwnerComponent {
    const void *vtable;
    unsigned short references;
    unsigned char unknown_006[0x1c - 0x06];
    void *member_01c;
    W3dInterface *held_020;
    W3dInterface *held_024;
    unsigned char unknown_028[0x38 - 0x28];
    W3dInterface *held_038;
} W3dOwnerComponent;

extern const void *w3d_component_vtable_8040ef28[];
extern const void *w3d_component_vtable_8040f310[];
extern const void *w3d_component_vtable_8040f5a8[];
extern const void *w3d_component_vtable_8040f868[];
extern int w3d_component_active_804aaa9c;
extern void *w3d_component_instance_804aabd4;

void * w3d_string_default(W3dString *string);
void w3d_string_base_finish(W3dString *string);
void w3d_string_release(W3dString *string);
void w3d_handle_storage_release(void *handle);
void w3d_actor_handle_member_destroy(void *member, int flags);
int w3d_actor_base_initialize(void *object);
void w3d_actor_base_destroy(void *object, int flags);
int w3d_base_construct_8015fef0(void *object);
void w3d_base_destroy_8015ff2c(void *object, int flags);
void w3d_base_destroy_801628ec(void *object, int flags);

W3dNamedComponent *w3d_component_construct_80068570(W3dNamedComponent *object)
{
    W3dNameBanks *banks = &object->banks;
    W3dString *name;
    int count;
    w3d_base_construct_8015fef0(object);
    object->vtable = w3d_component_vtable_8040ef28;
    object->held_01c = 0;
    object->held_020 = 0;
    object->held_060 = 0;
    object->held_064 = 0;
    object->held_06c = 0;
    name = banks->names_a;
    count = 9;
    do {
        w3d_string_default(name);
        name++;
    } while (count-- != 0);
    name = banks->names_b;
    count = 9;
    do {
        w3d_string_default(name);
        name++;
    } while (count-- != 0);
    w3d_string_default(&object->title);
    w3d_string_default(&object->subtitle);
    object->held_174 = 0;
    object->held_178 = 0;
    object->held_17c = 0;
    object->held_180 = 0;
    object->held_184 = 0;
    object->held_188 = 0;
    w3d_component_active_804aaa9c = 1;
    object->member_068 = 0;
    return object;
}

#if 0 /* 0x80068648: array-teardown null test lands in r0 with a loop copy in r29; not reproduced. */
void w3d_component_destroy_80068648(W3dNamedComponent *object, int flags)
{
    W3dNameBanks *banks;
    object->vtable = w3d_component_vtable_8040ef28;
    w3d_component_active_804aaa9c = 0;
    if (object->member_068) {
        w3d_actor_handle_member_destroy(object->member_068, 3);
        object->member_068 = 0;
    }
    if (object->held_188)
        object->held_188->vtable->release(object->held_188);
    if (object->held_184)
        object->held_184->vtable->release(object->held_184);
    if (object->held_180)
        object->held_180->vtable->release(object->held_180);
    if (object->held_17c)
        object->held_17c->vtable->release(object->held_17c);
    if (object->held_178)
        object->held_178->vtable->release(object->held_178);
    if (object->held_174)
        object->held_174->vtable->release(object->held_174);
    w3d_string_base_finish(&object->subtitle);
    w3d_string_release(&object->subtitle);
    w3d_string_base_finish(&object->title);
    w3d_string_release(&object->title);
    banks = &object->banks;
    {
        W3dString *first = banks->names_b;
        if (first) {
            W3dString *name = &banks->names_b[10];
            W3dString *start = first;
            while (start != name) {
                --name;
                w3d_string_base_finish(name);
                w3d_string_release(name);
            }
        }
    }
    {
        W3dString *first = banks->names_a;
        if (first) {
            W3dString *name = &banks->names_a[10];
            W3dString *start = first;
            while (start != name) {
                --name;
                w3d_string_base_finish(name);
                w3d_string_release(name);
            }
        }
    }
    if (object->held_06c)
        object->held_06c->vtable->release(object->held_06c);
    if (object->held_064)
        object->held_064->vtable->release(object->held_064);
    if (object->held_060)
        object->held_060->vtable->release(object->held_060);
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    if (object->held_01c)
        object->held_01c->vtable->release(object->held_01c);
    w3d_base_destroy_8015ff2c(object, flags);
}
#endif

void w3d_component_destroy_80098c2c(W3dSingletonComponent *object, int flags)
{
    object->vtable = w3d_component_vtable_8040f310;
    w3d_component_instance_804aabd4 = 0;
    if (object->handle_040)
        w3d_handle_storage_release(object->handle_040);
    w3d_base_destroy_801628ec(object, flags);
}

W3dLabelComponent *w3d_component_construct_800a50a8(W3dLabelComponent *object)
{
    w3d_actor_base_initialize(object);
    object->vtable = w3d_component_vtable_8040f5a8;
    w3d_string_default(&object->label);
    object->held_020 = 0;
    return object;
}

void w3d_component_destroy_800a50f4(W3dLabelComponent *object, int flags)
{
    object->vtable = w3d_component_vtable_8040f5a8;
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    w3d_string_base_finish(&object->label);
    w3d_string_release(&object->label);
    w3d_actor_base_destroy(object, flags);
}

void w3d_component_destroy_800beeb0(W3dOwnerComponent *object, int flags)
{
    object->vtable = w3d_component_vtable_8040f868;
    if (object->member_01c)
        w3d_actor_handle_member_destroy(object->member_01c, 3);
    object->member_01c = 0;
    if (object->held_038)
        object->held_038->vtable->release(object->held_038);
    if (object->held_024)
        object->held_024->vtable->release(object->held_024);
    if (object->held_020)
        object->held_020->vtable->release(object->held_020);
    w3d_base_destroy_8015ff2c(object, flags);
}

}
