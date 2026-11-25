// External descriptor and owner views; neither is constructed locally.
struct Type {void**table;Type*next;unsigned unknown[3];Type*parent;unsigned unknown24[2];unsigned tag;};
extern "C" Type*fn_8020ff3c();
extern "C" Type*fn_8020ff34();
struct TypeIterator {
 Type*owner;Type*current;unsigned pending:1;unsigned includePending:1;unsigned unknownFlags:30;
 void seek(){while(current==owner || (current && current->parent!=owner))current=current->next;}
 TypeIterator(Type*o,bool end):owner(o){
  if(end)current=0;
  else{pending=includePending=0;current=fn_8020ff3c();seek();
   if(!current && includePending){current=fn_8020ff34();pending=1;seek();}}
 }
 TypeIterator&operator++(){if(current){current=current->next;seek();
  if(!current && !pending && includePending){current=fn_8020ff34();pending=1;seek();}}
  return *this;
 }
 bool operator!=(const TypeIterator&o)const{if(owner!=o.owner)return true;if(current!=o.current)return true;return false;}
 Type*operator->()const{return current;}
};
struct Object {unsigned unknown[13];unsigned*values;unsigned unknown56[2];unsigned char*states;};
extern Type**types_8045e080[];
extern "C" void g4b_propagate_schema_801e7270(Object*self,unsigned index,unsigned value,int state){
 unsigned char previous=self->states[index];
 Type*type=(*types_8045e080)[index];
 if(previous!=1 && (previous!=2 || state!=0)){
  self->values[index]=value;self->states[index]=state;
  TypeIterator cursor(type,false),end(type,true);
  for(;cursor!=end;++cursor){unsigned child=cursor->tag>>22;if(self->states[child]==0)g4b_propagate_schema_801e7270(self,child,value,0);}
 }
}
