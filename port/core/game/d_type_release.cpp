#include "w3d_ptr.h"
#line 1 "d_type_release.cpp"
/* Release helpers for the registered engine types (0x80248768..0x80249194).
 *
 * Each drops the object's u16 reference count; at zero it unlinks the object
 * from its type registry and runs that type's deleting destructor (flags 3).
 * The unlink/destroy callees are the per-type functions of d_typeobj_a..e.
 */
#include "d_types.h"

extern "C" {

typedef struct W3dType80247d2c {
    W3dObjectBase base;
    int values_14[12];
} W3dType80247d2c;

void w3d_type_unlink_80241b68(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80241e4c(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_802427f4(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80242910(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80242c30(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80242cd0(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80242e78(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_802432a8(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80244230(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_802442fc(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_802444e8(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80244588(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80244730(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_802447d0(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80244978(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80244d60(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80245778(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_8024583c(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_802459a0(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80245a58(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80245c40(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80245d58(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_8024605c(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_802463b8(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80246bf4(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80246cbc(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80246ed8(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80247000(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80247374(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_802473fc(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80247500(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_802475ac(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80247720(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_802477a8(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_802478ac(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_802479b8(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80247c14(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80247c9c(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80247da0(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_80247e5c(Ptr32<W3dObjectBase> object, int flags);
void w3d_type_unlink_80248010(Ptr32<W3dObjectBase> object);
void w3d_type_destroy_802480f0(Ptr32<W3dObjectBase> object, int flags);

unsigned short w3d_type_release_80248768(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80241b68(object);
        if (object)
            w3d_type_destroy_80241e4c(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248a30(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_802427f4(object);
        if (object)
            w3d_type_destroy_80242910(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248a8c(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80242c30(object);
        if (object)
            w3d_type_destroy_80242cd0(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248ae8(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80242e78(object);
        if (object)
            w3d_type_destroy_802432a8(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248b44(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80244230(object);
        if (object)
            w3d_type_destroy_802442fc(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248ba0(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_802444e8(object);
        if (object)
            w3d_type_destroy_80244588(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248bfc(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80244730(object);
        if (object)
            w3d_type_destroy_802447d0(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248c58(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80244978(object);
        if (object)
            w3d_type_destroy_80244d60(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248cb4(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80245778(object);
        if (object)
            w3d_type_destroy_8024583c(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248d10(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_802459a0(object);
        if (object)
            w3d_type_destroy_80245a58(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248d6c(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80245c40(object);
        if (object)
            w3d_type_destroy_80245d58(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248dc8(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_8024605c(object);
        if (object)
            w3d_type_destroy_802463b8(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248e24(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80246bf4(object);
        if (object)
            w3d_type_destroy_80246cbc(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248e80(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80246ed8(object);
        if (object)
            w3d_type_destroy_80247000(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248edc(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80247374(object);
        if (object)
            w3d_type_destroy_802473fc(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248f38(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80247500(object);
        if (object)
            w3d_type_destroy_802475ac(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248f94(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80247720(object);
        if (object)
            w3d_type_destroy_802477a8(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_80248ff0(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_802478ac(object);
        if (object)
            w3d_type_destroy_802479b8(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_8024904c(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80247c14(object);
        if (object)
            w3d_type_destroy_80247c9c(object, 3);
    }
    return remaining;
}

unsigned short w3d_type_release_802490a8(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80247da0(object);
        if (object)
            w3d_type_destroy_80247e5c(object, 3);
    }
    return remaining;
}

/* Clears the twelve words of the type registered at 0x80367ae8 (see
 * w3d_type_construct_80247de4, which calls this after its own clearing).
 */
void w3d_type_reset_80249104(Ptr32<W3dType80247d2c> object)
{
    object->values_14[11] = 0;
    object->values_14[10] = 0;
    object->values_14[9] = 0;
    object->values_14[8] = 0;
    object->values_14[7] = 0;
    object->values_14[6] = 0;
    object->values_14[5] = 0;
    object->values_14[4] = 0;
    object->values_14[3] = 0;
    object->values_14[2] = 0;
    object->values_14[1] = 0;
    object->values_14[0] = 0;
}

unsigned short w3d_type_release_8024913c(Ptr32<W3dObjectBase> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_type_unlink_80248010(object);
        if (object)
            w3d_type_destroy_802480f0(object, 3);
    }
    return remaining;
}
}


