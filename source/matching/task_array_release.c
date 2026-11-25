/* Native array deallocation adapters. The allocator itself is an explicit
 * unresolved dependency; these wrappers do not replace its implementation.
 */
#ifdef __cplusplus
extern "C" {
#endif
extern void w3d_system_heap_release(void *block);

void w3d_task_array_release_backend(void *block)
{
    w3d_system_heap_release(block);
}

void w3d_task_array_release(void *block)
{
    if (block != 0)
        w3d_task_array_release_backend(block);
}
#ifdef __cplusplus
}
#endif
