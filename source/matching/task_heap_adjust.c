/* Heap hole adjustment, reconstructed from GWMP8P 0x8034a568. */
#ifdef __cplusplus
extern "C" {
#endif
#include "task_heap.h"

void w3d_task_heap_adjust(TaskEvent *begin, int top, int length,
                          const TaskEvent *replacement, const unsigned char *tag)
{
    TaskEvent value = *replacement;
    int hole = top, child = 2 * top + 2;
    (void)tag;
    while (child < length) {
        if (w3d_task_event_later(begin[child], begin[child - 1]))
            --child;
        begin[hole] = begin[child];
        hole = child;
        child = 2 * (child + 1);
    }
    if (child == length) {
        begin[hole] = begin[child - 1];
        hole = child - 1;
    }
    while (top < hole) {
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
