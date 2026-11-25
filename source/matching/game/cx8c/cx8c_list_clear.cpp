/* Layout offsets and call addresses observed in the original. Names and object roles are inferred. */
struct Cx8cNode {Cx8cNode *next,*previous;void *vtable;unsigned char member[4];};
struct Cx8cList {unsigned int unknown;Cx8cNode *head;};
extern "C" {extern char cx8c_vtable_80411ac0[];void cx8c_member_destroy_80210990(void *,int);void cx8c_deallocate_802134fc(void *);}
extern "C" void w3d_cx8c_list_clear_8034ba74(Cx8cList *self) {
 Cx8cNode *node=self->head->next;
 while(node!=self->head) {Cx8cNode *old=node;node=node->next;old->vtable=cx8c_vtable_80411ac0;cx8c_member_destroy_80210990(old->member,0);if(old) cx8c_deallocate_802134fc(old);}
 self->head->next=self->head;self->head->previous=self->head;
}
