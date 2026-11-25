// Complete native deque iterator: four pointer fields, all copied/accessed below.
// Receiver and target views are partial external ABI views and never constructed locally.
struct G1bTarget {void **table;unsigned unknown[8];int flag;int key(){return ((int(*)(G1bTarget*))table[5])(this);}};
struct G1bDequeIterator {G1bTarget **current,**first,**last,***node;
 void setNode(G1bTarget***n){node=n;first=*n;last=first+32;}
 G1bDequeIterator&operator--(){if(current==first){setNode(node-1);current=last;}--current;return *this;}
 G1bTarget*operator*()const{return *current;}
};
struct G1bDequeOwner {char prefix[64];G1bDequeIterator end;};
extern "C" int fn_801a7680(void*,G1bTarget*);
extern "C" int g1b_skip_duplicate_801a7c4c(char*self,G1bTarget*target){
 G1bDequeOwner *owner=self?(G1bDequeOwner*)(self-4):0;
 if(target->flag==0){G1bDequeIterator previous=owner->end;--previous;G1bTarget*tail=*previous;
 int key=target->key();if(key==tail->key()&&tail->flag==0)return 0;}
 return fn_801a7680(self,target);
}
