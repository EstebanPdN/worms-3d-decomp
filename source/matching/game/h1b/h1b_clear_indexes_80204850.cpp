// External container prefixes; no objects of these layout views are locally constructed.
struct Record {unsigned words[16];~Record(){}};
struct Node {unsigned color;Node*parent;Node*left;Node*right;};
struct Tree {unsigned unknown;Node*head;unsigned count;};
struct Owner {unsigned unknown[6];unsigned status;Record*begin;Record*end;unsigned unknown36[2];Tree first;unsigned unknown56;Tree second;unsigned unknown72[5];unsigned*wordBegin;unsigned*wordEnd;};
extern "C" void fn_8035b84c(Tree*,Node*);
extern "C" void fn_8035b8a4(Tree*,Node*);
inline void reset(Tree*t){t->head->left=t->head;t->head->parent=0;t->head->right=t->head;t->count=0;}
extern "C" void h1b_clear_indexes_80204850(Owner*self){
 for(Record*p=self->begin;p!=self->end;++p)p->~Record();self->end=self->begin;
 if(self->first.count){fn_8035b84c(&self->first,self->first.head->parent);reset(&self->first);}
 if(self->second.count){fn_8035b8a4(&self->second,self->second.head->parent);reset(&self->second);}
 self->status=0;
 for(unsigned*p=self->wordBegin;p!=self->wordEnd;++p){}
 self->wordEnd=self->wordBegin;
}
