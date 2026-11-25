/* Small runtime helpers and pointer-vector teardown loops (0x80341260..0x80341584).
 *
 * Names are inferred from behavior; no original symbols survive. Callees
 * outside this unit stay external and are bound to their original addresses
 * by the reference linker. The pointer vectors are {begin, end, capacity}
 * triples; every clear loop pops from the end until end == begin.
 * The character class table at 0x803db449 has bit 0 set for upper case.
 */
extern "C" {

typedef struct W3dPointerVector {
    void **begin;
    void **end;
    void **capacity;
} W3dPointerVector;

typedef struct W3dVirtualObject W3dVirtualObject;

typedef struct W3dVirtualTable {
    void *unknown_00[2];
    void (*destroy_08)(W3dVirtualObject *object, int flags);
    void (*destroy_0c)(W3dVirtualObject *object, int flags);
} W3dVirtualTable;

typedef struct W3dVirtualAt16 {
    unsigned char unknown_00[0x10];
    W3dVirtualTable *vtable;
} W3dVirtualAt16;

typedef struct W3dVirtualAt12 {
    unsigned char unknown_00[0x0c];
    W3dVirtualTable *vtable;
} W3dVirtualAt12;

typedef struct W3dNamedEntry {
    unsigned char unknown_00[4];
    unsigned char name[4];
} W3dNamedEntry;

typedef struct W3dRangeLimits {
    unsigned char unknown_00[2];
    short first;
    short second;
    unsigned char unknown_06;
    unsigned char flag;
    short limit_08;
    short limit_0a;
    short limit_0c;
    unsigned char unknown_0e[2];
    int value;
} W3dRangeLimits;

typedef struct W3dServiceHolder {
    unsigned char unknown_00[8];
    void *service;
} W3dServiceHolder;

extern const unsigned char w3d_char_class_803db449[];
extern W3dServiceHolder *w3d_service_holder_804ac570;

void * w3d_service_request_802f06c8(void *service, void *first, int second);
void w3d_actor_member_delete_backend(void *object);
void w3d_string_base_finish(void *string);
void w3d_string_release(void *string);
void w3d_operator_delete_80015264(void *object);

int w3d_char_to_lower(int c)
{
    if ((c + w3d_char_class_803db449)[0] & 1)
        return c + 32;
    return c;
}

void w3d_service_request_8034127c(int first, int second)
{
    w3d_service_request_802f06c8(w3d_service_holder_804ac570->service, (void *)first, second);
}

void w3d_empty_80341348(void)
{
}

void w3d_vector_clear_8034134c(W3dPointerVector *vector)
{
    while (vector->begin != vector->end) {
        void **end = vector->end;
        void *object = *--end;
        vector->end = end;
        w3d_actor_member_delete_backend(object);
    }
}

void w3d_range_limits_reset(W3dRangeLimits *limits)
{
    limits->value = 0;
    limits->second = -1;
    limits->first = -1;
    limits->limit_0c = 0x7fff;
    limits->limit_0a = 0x7fff;
    limits->limit_08 = 0x7fff;
    limits->flag = 0;
}

void w3d_empty_80341448(void)
{
}

void w3d_empty_8034144c(void)
{
}

void w3d_vector_destroy_virtual16(W3dPointerVector *vector)
{
    while (vector->begin != vector->end) {
        void **end = vector->end;
        W3dVirtualAt16 *object = (W3dVirtualAt16 *)*--end;
        vector->end = end;
        if (object)
            object->vtable->destroy_08((W3dVirtualObject *)object, 3);
    }
}

void w3d_vector_destroy_virtual12(W3dPointerVector *vector)
{
    while (vector->begin != vector->end) {
        void **end = vector->end;
        W3dVirtualAt12 *object = (W3dVirtualAt12 *)*--end;
        vector->end = end;
        if (object)
            object->vtable->destroy_0c((W3dVirtualObject *)object, 3);
    }
}

void w3d_vector_destroy_named(W3dPointerVector *vector)
{
    while (vector->begin != vector->end) {
        void **end = vector->end;
        W3dNamedEntry *entry = (W3dNamedEntry *)*--end;
        vector->end = end;
        if (entry) {
            w3d_string_base_finish(entry->name);
            w3d_string_release(entry->name);
            w3d_operator_delete_80015264(entry);
        }
    }
}

void w3d_empty_80341584(void)
{
}

}
