/* Additional observed shapes for worker-b units (b_types.h is frozen). */
#ifndef B_TYPES2_H
#define B_TYPES2_H

#include "b_types.h"

extern "C" {

/* Common head of every observed interface vtable: two header words, then
 * query (+0x08), add_ref (+0x0c) and release (+0x10).
 */
#define W3D_VTBL_HEAD(Type) \
    Ptr32<void> header_00; \
    Ptr32<void> header_04; \
    Ptr32<int (Ptr32<Type>)> query_08; \
    Ptr32<int (Ptr32<Type>)> add_ref; \
    Ptr32<int (Ptr32<Type>)> release

/* Pointer vector {begin, end} of 4-byte elements. */
typedef struct W3dPtrVector {
    Ptr32<Ptr32<void>> begin;
    Ptr32<Ptr32<void>> end;
} W3dPtrVector;

static inline unsigned int w3d_ptr_vector_size(Ptr32<W3dPtrVector> vector)
{
    return vector->end - vector->begin;
}

/* Generic failure status returned by interface methods. */
#define W3D_E_FAIL ((int)0x80004005)

/* String header: the reference count is the first halfword. */
typedef struct W3dStringHeader {
    unsigned short references;
    unsigned short length;
    unsigned short capacity;
} W3dStringHeader;

Ptr32<W3dStringHeader> w3d_string_header(Ptr32<W3dString> string);

/* Inlined string copy constructor into a local holder. */
static inline void w3d_local_string_copy(Ptr32<W3dLocalString> copy, Ptr32<W3dString> source)
{
    w3d_string_base_init(&copy->s);
    copy->s.data = source->data;
    w3d_string_header(&copy->s)->references++;
}

}

#endif
