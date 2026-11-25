#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s9_owner_list.c"
/* Eight-byte iterator objects retain their observed stack slots across inline operations. */
#define FIELD(p,T,o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p)+(o)))
typedef struct S9ListNode {
    Ptr32<struct S9ListNode> next;
    Ptr32<struct S9ListNode> previous;
    Ptr32<void> vtable;
    char payload[28];
    Ptr32<void> owner;
} S9ListNode;
typedef struct S9Iterator { Ptr32<S9ListNode> node; int unused; } S9Iterator;
extern char lbl_80411ac0[];
extern void fn_80210990(Ptr32<void>,int);
extern void fn_802134fc(Ptr32<void>);
int s9_remove_owner_node_80165d4c(Ptr32<void> self,Ptr32<void> owner)
{
    volatile S9Iterator current,end,next,removed;
    Ptr32<S9ListNode> node;
    Ptr32<S9ListNode> following;
    Ptr32<S9ListNode> previous;
    Ptr32<void> list=(Ptr32<char>)self+24;
    int different;
    Ptr32<void> type_table;
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

int s9_remove_owner_node_80165fd4(Ptr32<void> self,Ptr32<void> owner)
{
    volatile S9Iterator current,end,next,removed;
    Ptr32<S9ListNode> node;
    Ptr32<S9ListNode> following;
    Ptr32<S9ListNode> previous;
    Ptr32<void> list=(Ptr32<char>)self+24;
    int different;
    Ptr32<void> type_table;
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

int s9_remove_owner_node_801662a8(Ptr32<void> self,Ptr32<void> owner)
{
    volatile S9Iterator current,end,next,removed;
    Ptr32<S9ListNode> node;
    Ptr32<S9ListNode> following;
    Ptr32<S9ListNode> previous;
    Ptr32<void> list=(Ptr32<char>)self+24;
    int different;
    Ptr32<void> type_table;
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

}
