/* Heap insertion, reconstructed from GWMP8P 0x8034a400. */
#ifdef __cplusplus
extern "C" {
#endif
#include "task_heap.h"

void w3d_task_heap_push(TaskEvent *begin, TaskEvent *end, const unsigned char *tag)
{
    TaskEvent value = end[-1];
    int hole = (int)(end - begin) - 1;
    (void)tag;
    while (hole > 0) {
        int parent = (hole - 1) / 2;
        if (!w3d_task_event_later(begin[parent], value))
            break;
        begin[hole] = begin[parent];
        hole = parent;
    }
    begin[hole] = value;
}
#ifdef __cplusplus
}
#endif
