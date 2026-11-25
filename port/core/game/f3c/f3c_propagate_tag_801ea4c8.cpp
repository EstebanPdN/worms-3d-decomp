#include "w3d_ptr.h"
#line 1 "f3c_propagate_tag_801ea4c8.cpp"
// Structural names and partial layouts inferred from original instructions.
struct Tag {unsigned short a,b;unsigned char word[4];};
struct Node {Ptr32<Ptr32<void>> vtable;Tag tag;};
struct List {unsigned pad[15];Ptr32<Ptr32<Node>> begin; Ptr32<Ptr32<Node>> end;};
extern "C" Ptr32<Node> fn_801e9db8(Ptr32<List>,int);
extern "C" void f3c_propagate_tag_801ea4c8(Ptr32<Node> self,Ptr32<Node> other){Ptr32<List> list=((Ptr32<Ptr32<List> (Ptr32<Node>)>)self->vtable[5])(self);int count=list->end-list->begin;
while(count--){Ptr32<Node> entry=fn_801e9db8(list,count);Ptr32<Tag> object=*(Ptr32<Ptr32<Tag>>)entry;if(!(object->word[3]&32)){Ptr32<Ptr32<void>> vtable=*(Ptr32<Ptr32<Ptr32<void>>>)((Ptr32<char>)entry+4);((Ptr32<void (Ptr32<Node>, Ptr32<Node>, Ptr32<Node>, Ptr32<Node>)>)vtable[2])(entry,self,other,entry);}}
Ptr32<Tag> tag=&self->tag;tag->word[0]=(tag->word[0]&242)|(other->tag.word[0]&13);}

