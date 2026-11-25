/* Deleting destructors, vector teardown and a formatting wrapper (0x80342a7c..0x80343584).
 *
 * Names are inferred from behavior; no original symbols survive. The deleting
 * destructors run the base destructor at 0x80021468 with flag 0 and free the
 * storage through 0x80015264 when bit 0 of the flags is set. Interfaces held
 * at +0x14/+0x18 have a 4-byte-entry vtable at +0 with a release slot at +0x10.
 * Buffer sets keep three pairs of 16-byte buffers at +0x24, +0x44 and +0x64,
 * each buffer owning the storage pointer at its +0.
 */
#include <stdarg.h>
#include <sn-inline-stdarg.h>

extern "C" {

typedef struct W3dPointerVector {
    void **begin;
    void **end;
    void **capacity;
} W3dPointerVector;

typedef struct W3dBuffer {
    void *data;
    unsigned char unknown_04[12];
} W3dBuffer;

typedef struct W3dBufferSet {
    unsigned char unknown_00[0x24];
    W3dBuffer a[2];
    W3dBuffer b[2];
    W3dBuffer c[2];
} W3dBufferSet;

typedef struct W3dInterface W3dInterface;

typedef struct W3dInterfaceTable {
    void *unknown_00[4];
    void (*release)(W3dInterface *object);
} W3dInterfaceTable;

struct W3dInterface {
    W3dInterfaceTable *vtable;
};

typedef struct W3dTwoHandles {
    unsigned char unknown_00[0x14];
    W3dInterface *first;
    W3dInterface *second;
} W3dTwoHandles;

void w3d_operator_delete_80015264(void *object);
void w3d_buffer_free_800152ac(void *data);
void w3d_object_base_destroy_80021468(void *object, int flags);
void w3d_buffer_set_finish_8001d1d8(W3dBufferSet *set);
int w3d_text_vformat_802ed5e0(char *target, const char *format, va_list arguments);

#if 0 /* 0x80342a7c: array-member destructor loops; register allocation differs (one extra saved register). */
void w3d_vector_destroy_buffers_80342a7c(W3dPointerVector *vector)
{
    while (vector->begin != vector->end) {
        void **end = vector->end;
        W3dBufferSet *set = (W3dBufferSet *)*--end;
        vector->end = end;
        if (set) {
            W3dBuffer *buffer;
            W3dBuffer *first_a = set->a;
            W3dBuffer *first_b = set->b;
            W3dBuffer *first_c;
            w3d_buffer_set_finish_8001d1d8(set);
            first_c = set->c;
            if (first_c) {
                buffer = set->c + 2;
                while (first_c != buffer) {
                    --buffer;
                    if (buffer->data)
                        w3d_buffer_free_800152ac(buffer->data);
                }
            }
            if (first_b) {
                buffer = first_c;
                while (first_b != buffer) {
                    --buffer;
                    if (buffer->data)
                        w3d_buffer_free_800152ac(buffer->data);
                }
            }
            if (first_a) {
                buffer = first_b;
                while (first_a != buffer) {
                    --buffer;
                    if (buffer->data)
                        w3d_buffer_free_800152ac(buffer->data);
                }
            }
            w3d_operator_delete_80015264(set);
        }
    }
}
#endif

void w3d_vector_free_80342b60(W3dPointerVector *vector)
{
    while (vector->begin != vector->end) {
        void **end = vector->end;
        void *object = *--end;
        vector->end = end;
        w3d_operator_delete_80015264(object);
    }
}

void w3d_empty_80342fa4(void)
{
}

int w3d_return_zero_80342fa8(void)
{
    return 0;
}

void w3d_class_destroy_80342fb0(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80342ff4(W3dTwoHandles *object, int flags)
{
    if (object->second)
        object->second->vtable->release(object->second);
    if (object->first)
        object->first->vtable->release(object->first);
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80343074(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803430b8(W3dTwoHandles *object, int flags)
{
    if (object->first)
        object->first->vtable->release(object->first);
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_8034311c(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80343160(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803431a4(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803431e8(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_8034322c(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80343270(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803432b4(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803432f8(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_8034333c(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80343380(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_803433c4(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80343408(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_8034344c(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

void w3d_class_destroy_80343490(void *object, int flags)
{
    w3d_object_base_destroy_80021468(object, 0);
    if (flags & 1)
        w3d_operator_delete_80015264(object);
}

char *w3d_text_format_803434d4(char *target, const char *format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    w3d_text_vformat_802ed5e0(target, format, arguments);
    return target;
}

void w3d_empty_8034357c(void)
{
}

void w3d_empty_80343580(void)
{
}

void w3d_empty_80343584(void)
{
}

}
