/* Observed list-node and embedded actor-data layouts; unknown words remain untouched. */
#define FIELD(p,T,o) (*(T *)((char *)(p)+(o)))
extern char lbl_80411ac0[];
extern char lbl_80411a70[];
extern "C" void *fn_80212fd4(unsigned int);
extern "C" void *fn_803413d8(unsigned int);
extern "C" void fn_80210990(void *,int);
inline void *operator new(unsigned int,void *storage) throw() { return storage; }
union S9ElementId { unsigned int word; struct { unsigned short value,padding; } parts; };
union S9ElementFlags { unsigned int word; struct { char unknown[3]; volatile unsigned char value; } byte; };
struct S9ElementData {
    S9ElementId id;
    S9ElementFlags flags;
    unsigned int unknown12;
    unsigned int vector[4];
    void *owner;
    void *parent;
};
enum S9RootOnly { S9RootOnlyStage };
struct S9ListElement {
    void *volatile vtable;
    S9ElementData data;
    S9ListElement(S9RootOnly) { vtable=lbl_80411ac0; }
    void initialize(S9ElementData *d) {
        d->flags.byte.value=2;
        unsigned int value=d->flags.byte.value;
        vtable=lbl_80411a70;
        d->flags.word=value;
        d->id.parts.value=0;
        unsigned int *out=d->vector;
        int n=4;
        do { *out++=0; } while(--n);
    }
    S9ListElement(const S9ListElement &other) {
        vtable=lbl_80411ac0;
        data.id.word=other.data.id.word;
        data.flags.word=other.data.flags.word;
        vtable=lbl_80411a70;
        data.unknown12=other.data.unknown12;
        const unsigned int *input=other.data.vector;
        unsigned int *out=data.vector;
        int n=4;
        do { *out++=*input++; } while(--n);
        data.owner=other.data.owner;
        data.parent=other.data.parent;
    }
    void finish(S9ElementData *d) { vtable=lbl_80411ac0;fn_80210990(d,0); }
};
struct S9InsertNode { S9InsertNode *next,*previous; S9ListElement element; };
struct S9InsertIterator { S9InsertNode *node;int unknown; };
struct S9InsertManager { void **vtable; };
typedef void (*S9InsertNotify)(S9InsertManager *,void *,S9ListElement *);
extern "C" int s9_insert_owner_node_80165b88(void *self,void *owner,unsigned int value)
{
    volatile S9InsertIterator selected,position,copy;
    char *list;
    {
        S9InsertNode *head=FIELD(self,S9InsertNode *,28);
        S9ListElement temporary(S9RootOnlyStage);
        copy.node=head;
        position.node=head;
        unsigned int data_address=(unsigned int)&temporary.data;
        temporary.initialize((S9ElementData *)data_address);
        S9InsertNode *node=(S9InsertNode *)fn_80212fd4(48);
        if(!node)node=(S9InsertNode *)fn_803413d8(48);
        list=(char *)self+24;
        S9ListElement *storage=(S9ListElement *)((unsigned int)node+8);
        new (storage) S9ListElement(temporary);
        S9InsertNode *sentinel=copy.node;
        S9InsertNode *previous=sentinel->previous;
        node->next=sentinel;
        node->previous=previous;
        previous->next=node;
        sentinel->previous=node;
        selected.node=node;
        temporary.finish((S9ElementData *)data_address);
    }
    S9InsertNode *head=FIELD(list,S9InsertNode *,4);
    selected.node=head;
    S9InsertNode *tail=head->previous;
    selected.node=tail;
    S9ListElement *element=&tail->element;
    element->data.owner=owner;
    element->data.vector[0]=value;
    element->data.unknown12=0;
    element->data.parent=self;
    S9InsertManager *manager=FIELD(self,S9InsertManager *,20);
    void **table=manager->vtable;
    void *adjusted=0;
    if(owner)adjusted=(char *)owner+4;
    head=FIELD(list,S9InsertNode *,4);
    selected.node=head;
    tail=head->previous;
    selected.node=tail;
    ((S9InsertNotify)table[12])(manager,adjusted,&tail->element);
    return 0;
}
