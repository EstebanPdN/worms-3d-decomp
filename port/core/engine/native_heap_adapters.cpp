#include "w3d_ptr.h"
#line 1 "native_heap_adapters.cpp"
/* Address labels and signatures are reconstruction choices, not historical names.
   The metadata parameters are forwarded to the native boundary but are unused
   by the complete observed 801fe268 -> 80212fd4 implementation. */
extern "C" {
typedef unsigned int u32;
extern Ptr32<void> w3d_handle_storage_allocate(u32 size);
extern const char w3d_heap_allocation_file[];

Ptr32<void> w3d_heap_allocate_with_metadata(u32 size, Ptr32<const char> file, u32 line)
{
    return w3d_handle_storage_allocate(size);
}

Ptr32<void> w3d_heap_allocate_file_line(u32 size)
{
    return w3d_heap_allocate_with_metadata(size, w3d_heap_allocation_file, 0x70);
}

Ptr32<void> w3d_heap_allocate_entry_a(u32 size)
{
    return w3d_heap_allocate_file_line(size);
}

Ptr32<void> w3d_heap_allocate_entry_b(u32 size)
{
    return w3d_heap_allocate_file_line(size);
}

}


