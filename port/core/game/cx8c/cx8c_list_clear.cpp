#include "w3d_ptr.h"
#line 1 "cx8c_list_clear.cpp"
/* Layout offsets and call addresses observed in the original. Names and object roles are inferred. */
struct Cx8cNode {Ptr32<Cx8cNode> next; Ptr32<Cx8cNode> previous;Ptr32<void> vtable;unsigned char member[4];};
struct Cx8cList {unsigned int unknown;Ptr32<Cx8cNode> head;};
extern "C" {extern char cx8c_vtable_80411ac0[];void cx8c_member_destroy_80210990(Ptr32<void>,int);void cx8c_deallocate_802134fc(Ptr32<void>);}
extern "C" void w3d_cx8c_list_clear_8034ba74(Ptr32<Cx8cList> self) {
 Ptr32<Cx8cNode> node=self->head->next;
 while(node!=self->head) {Ptr32<Cx8cNode> old=node;node=node->next;old->vtable=cx8c_vtable_80411ac0;cx8c_member_destroy_80210990(old->member,0);if(old) cx8c_deallocate_802134fc(old);}
 self->head->next=self->head;self->head->previous=self->head;
}


