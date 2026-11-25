// desc: Appears to insert a node into a singly linked list kept in descending order of an integer key at offset 16.
struct S21Node { struct S21Node *next; char pad[12]; int key; struct S21List *list; };
struct S21List { char pad[8]; struct S21Node *first; };
void w3d_s21_insert_sorted_80200af8(struct S21Node *node)
{
    struct S21List *list = node->list;
    int key = node->key;
    struct S21Node *previous = 0;
    struct S21Node **head = &list->first;
    struct S21Node *current = *head;
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
