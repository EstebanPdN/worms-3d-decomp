#include "w3d_ptr.h"
#line 1 "d_refobj_release.cpp"
/* Release helpers for u16 reference-counted engine objects (0x80240124..).
 *
 * Each release drops the count at +0x04; at zero it unlinks the object from
 * its owner list and runs the deleting destructor with flags 3. The unlink
 * and destructor callees differ per object kind and stay external.
 */
#include "d_types.h"

extern "C" {

void w3d_counted_unlink_8023c750(Ptr32<W3dCounted> object);
void w3d_counted_destroy_8023c7d0(Ptr32<W3dCounted> object, int flags);
void w3d_counted_unlink_8023c8b8(Ptr32<W3dCounted> object);
void w3d_counted_destroy_8023c940(Ptr32<W3dCounted> object, int flags);
void w3d_counted_unlink_8023ca64(Ptr32<W3dCounted> object);
void w3d_counted_destroy_8023cc94(Ptr32<W3dCounted> object, int flags);
void w3d_counted_unlink_8023d2e8(Ptr32<W3dCounted> object);
void w3d_counted_destroy_8023d398(Ptr32<W3dCounted> object, int flags);
void w3d_counted_unlink_8023d530(Ptr32<W3dCounted> object);
void w3d_counted_destroy_8023d5b0(Ptr32<W3dCounted> object, int flags);
void w3d_counted_unlink_8023d698(Ptr32<W3dCounted> object);
void w3d_counted_destroy_8023d774(Ptr32<W3dCounted> object, int flags);
void w3d_counted_unlink_8023d9a4(Ptr32<W3dCounted> object);
void w3d_counted_destroy_8023da24(Ptr32<W3dCounted> object, int flags);
void w3d_counted_unlink_8023db0c(Ptr32<W3dCounted> object);
void w3d_counted_destroy_8023dbe8(Ptr32<W3dCounted> object, int flags);
void w3d_counted_unlink_8023de18(Ptr32<W3dCounted> object);
void w3d_counted_destroy_8023def4(Ptr32<W3dCounted> object, int flags);

unsigned short w3d_counted_release_80240124(Ptr32<W3dCounted> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_counted_unlink_8023c750(object);
        if (object)
            w3d_counted_destroy_8023c7d0(object, 3);
    }
    return remaining;
}

unsigned short w3d_counted_release_80240180(Ptr32<W3dCounted> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_counted_unlink_8023c8b8(object);
        if (object)
            w3d_counted_destroy_8023c940(object, 3);
    }
    return remaining;
}

unsigned short w3d_counted_release_802401dc(Ptr32<W3dCounted> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_counted_unlink_8023ca64(object);
        if (object)
            w3d_counted_destroy_8023cc94(object, 3);
    }
    return remaining;
}

unsigned short w3d_counted_release_80240238(Ptr32<W3dCounted> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_counted_unlink_8023d2e8(object);
        if (object)
            w3d_counted_destroy_8023d398(object, 3);
    }
    return remaining;
}

/* Empty hook between two release helpers. */
void w3d_counted_hook_80240294(void)
{
}

unsigned short w3d_counted_release_80240298(Ptr32<W3dCounted> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_counted_unlink_8023d530(object);
        if (object)
            w3d_counted_destroy_8023d5b0(object, 3);
    }
    return remaining;
}

void w3d_counted_hook_802402f4(void)
{
}

unsigned short w3d_counted_release_802402f8(Ptr32<W3dCounted> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_counted_unlink_8023d698(object);
        if (object)
            w3d_counted_destroy_8023d774(object, 3);
    }
    return remaining;
}

unsigned short w3d_counted_release_80240354(Ptr32<W3dCounted> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_counted_unlink_8023d9a4(object);
        if (object)
            w3d_counted_destroy_8023da24(object, 3);
    }
    return remaining;
}

unsigned short w3d_counted_release_802403b0(Ptr32<W3dCounted> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_counted_unlink_8023db0c(object);
        if (object)
            w3d_counted_destroy_8023dbe8(object, 3);
    }
    return remaining;
}

unsigned short w3d_counted_release_8024040c(Ptr32<W3dCounted> object)
{
    unsigned short remaining = --object->references;
    if (remaining == 0) {
        w3d_counted_unlink_8023de18(object);
        if (object)
            w3d_counted_destroy_8023def4(object, 3);
    }
    return remaining;
}

}


