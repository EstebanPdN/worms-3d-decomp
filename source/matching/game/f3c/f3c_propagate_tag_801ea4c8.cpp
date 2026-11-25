// Structural names and partial layouts inferred from original instructions.
struct Tag {unsigned short a,b;unsigned char word[4];};
struct Node {void **vtable;Tag tag;};
struct List {unsigned pad[15];Node **begin,**end;};
extern "C" Node *fn_801e9db8(List *,int);
extern "C" void f3c_propagate_tag_801ea4c8(Node *self,Node *other){List *list=((List *(*)(Node *))self->vtable[5])(self);int count=list->end-list->begin;
while(count--){Node *entry=fn_801e9db8(list,count);Tag *object=*(Tag **)entry;if(!(object->word[3]&32)){void **vtable=*(void ***)((char *)entry+4);((void (*)(Node *,Node *,Node *,Node *))vtable[2])(entry,self,other,entry);}}
Tag *tag=&self->tag;tag->word[3]=(tag->word[3]&242)|(other->tag.word[3]&13);}