#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_as_80200af8.c"
// desc: Appears to insert a node into a singly linked list kept in descending order of an integer key at offset 16.
struct S21Node { Ptr32<struct S21Node> next; char pad[12]; int key; Ptr32<struct S21List> list; };
struct S21List { char pad[8]; Ptr32<struct S21Node> first; };
void w3d_s21_insert_sorted_80200af8(Ptr32<struct S21Node> node)
{
    Ptr32<struct S21List> list = node->list;
    int key = node->key;
    Ptr32<struct S21Node> previous = 0;
    Ptr32<Ptr32<struct S21Node>> head = &list->first;
    Ptr32<struct S21Node> current = *head;
    for (; current && current->key >= key; current = previous->next)
        previous = current;
    if (previous) {
        node->next = previous->next;
        previous->next = node;
    } else {
        node->next = *head;
        *head = node;
    }
}

}
