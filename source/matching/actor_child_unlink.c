#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
void w3d_actor_child_unlink(ActorChildNode *node, ActorChildNode **head)
{
    if (*head == node) {
        *head = node->next;
        if (node->next != 0)
            node->next->previous = 0;
    } else {
        node->previous->next = node->next;
        if (node->next != 0)
            node->next->previous = node->previous;
    }
    node->parent = 0;
    node->unknown_0c = 0;
}
#ifdef __cplusplus
}
#endif
