#include "w3d_ptr.h"
#line 1 "handle_storage_fallback.cpp"
/* Reconstructed from original Worms3D GameCube instructions.
 * Names and pointer types are inferred. Only observed prefix offsets are
 * represented. All external implementations remain external dependencies. */
extern "C" {
extern Ptr32<void (void)> w3d_handle_retry_handler;
extern Ptr32<void> w3d_handle_storage_allocate(unsigned int bytes);

Ptr32<void> w3d_handle_storage_fallback(unsigned int bytes)
{
    Ptr32<void> storage;
    do {
        /* Native code invokes the loaded handler without checking for null. */
        w3d_handle_retry_handler();
        storage = w3d_handle_storage_allocate(bytes);
    } while (storage == 0);
    return storage;
}

}


