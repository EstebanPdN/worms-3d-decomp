/* Heap removal, reconstructed from GWMP8P 0x8034a7fc. */
#ifdef __cplusplus
extern "C" {
#endif
#include "task_heap.h"

void w3d_task_heap_pop(TaskEvent *begin, TaskEvent *end, const unsigned char *tag)
{
    TaskEvent replacement = end[-1];
    unsigned char compare = *tag;
    end[-1] = *begin;
    w3d_task_heap_adjust(begin, 0, (int)(end - begin) - 1, &replacement, &compare);
}
#ifdef __cplusplus
}
#endif
