/* Eight-byte iterator objects retain their observed stack slots across inline operations. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
typedef struct S9ListNode {
    struct S9ListNode *next;
    struct S9ListNode *previous;
    void *vtable;
    char payload[28];
    void *owner;
} S9ListNode;
typedef struct S9Iterator { S9ListNode *node; int unused; } S9Iterator;
extern char lbl_80411ac0[];
extern void fn_80210990(void *,int);
extern void fn_802134fc(void *);
int s9_remove_owner_node_80165d4c(void *self,void *owner)
{
    volatile S9Iterator current,end,next,removed;
    S9ListNode *node;
    S9ListNode *following;
    S9ListNode *previous;
    void *list=(char *)self+24;
    int different;
    void *type_table;
    FIELD(owner,int,48)=0;
    type_table=lbl_80411ac0;
    current.node=FIELD(list,S9ListNode * volatile,4)->next;
    end.node=FIELD(list,S9ListNode * volatile,4);
    goto condition;
body:
    if(node->owner!=owner)goto increment;
    removed.node=node;
    following=node->next;
    previous=node->previous;
    previous->next=following;
    following->previous=previous;
    node->vtable=type_table;
    fn_80210990(node->payload,0);
    if(node)fn_802134fc(node);
    next.node=following;
    goto done;
increment:
    current.node=node->next;
condition:
    node=current.node;
    different=1;
    if(node!=end.node)goto compared;
    different=0;
compared:
    if(different)goto body;
done:
    return 0;
}

int s9_remove_owner_node_80165fd4(void *self,void *owner)
{
    volatile S9Iterator current,end,next,removed;
    S9ListNode *node;
    S9ListNode *following;
    S9ListNode *previous;
    void *list=(char *)self+24;
    int different;
    void *type_table;
    FIELD(owner,int,24)=0;
    type_table=lbl_80411ac0;
    current.node=FIELD(list,S9ListNode * volatile,4)->next;
    end.node=FIELD(list,S9ListNode * volatile,4);
    goto condition;
body:
    if(node->owner!=owner)goto increment;
    removed.node=node;
    following=node->next;
    previous=node->previous;
    previous->next=following;
    following->previous=previous;
    node->vtable=type_table;
    fn_80210990(node->payload,0);
    if(node)fn_802134fc(node);
    next.node=following;
    goto done;
increment:
    current.node=node->next;
condition:
    node=current.node;
    different=1;
    if(node!=end.node)goto compared;
    different=0;
compared:
    if(different)goto body;
done:
    return 0;
}

int s9_remove_owner_node_801662a8(void *self,void *owner)
{
    volatile S9Iterator current,end,next,removed;
    S9ListNode *node;
    S9ListNode *following;
    S9ListNode *previous;
    void *list=(char *)self+24;
    int different;
    void *type_table;
    FIELD(owner,int,20)=0;
    type_table=lbl_80411ac0;
    current.node=FIELD(list,S9ListNode * volatile,4)->next;
    end.node=FIELD(list,S9ListNode * volatile,4);
    goto condition;
body:
    if(node->owner!=owner)goto increment;
    removed.node=node;
    following=node->next;
    previous=node->previous;
    previous->next=following;
    following->previous=previous;
    node->vtable=type_table;
    fn_80210990(node->payload,0);
    if(node)fn_802134fc(node);
    next.node=following;
    goto done;
increment:
    current.node=node->next;
condition:
    node=current.node;
    different=1;
    if(node!=end.node)goto compared;
    different=0;
compared:
    if(different)goto body;
done:
    return 0;
}
