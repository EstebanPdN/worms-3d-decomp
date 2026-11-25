/* Complete original802eafc4..802eafcc. Pointer/global names are inferred;
 * the pointer's initialized storage and pointee remain native dependencies. */
extern int *w3d_heap_error_pointer;
int *w3d_heap_errno(void)
{
    return w3d_heap_error_pointer;
}
