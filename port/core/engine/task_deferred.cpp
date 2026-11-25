#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "task_deferred.c"
/* Native reference-array cleanup, used for deferred actor releases.
 * The array allocation has an eight-byte prefix; its first word supplies the
 * destructor count independently of the container's logical count.
 */
#ifdef __cplusplus
extern "C" {
#endif
typedef unsigned int RefWord;
typedef struct DeferredObject DeferredObject;
typedef struct DeferredMethods {
    Ptr32<void> unknown_00[4];
    Ptr32<void (Ptr32<DeferredObject>)> release;
} DeferredMethods;
struct DeferredObject { Ptr32<DeferredMethods> methods; };
typedef struct DeferredReferences {
    RefWord count;
    unsigned short flags, inline_capacity;
    Ptr32<Ptr32<DeferredObject>> objects;
} DeferredReferences;
extern void w3d_task_array_release(Ptr32<void>);

void w3d_task_deferred_clear(Ptr32<DeferredReferences> references)
{
    Ptr32<Ptr32<DeferredObject>> objects = references->objects;
    if (objects != 0) {
        Ptr32<Ptr32<DeferredObject>> end = objects + ((Ptr32<RefWord>)objects)[-2];
        if (objects != end) {
            do {
                Ptr32<DeferredObject> object = *--end;
                if (object != 0)
                    object->methods->release(object);
            } while (references->objects != end);
        }
        w3d_task_array_release((Ptr32<unsigned char>)references->objects - 8);
    }
    references->objects = 0;
    references->count = 0;
    references->inline_capacity = 4;
    references->flags = 0;
}
#ifdef __cplusplus
}
#endif

}
