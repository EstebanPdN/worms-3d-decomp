// List layout, interface release role and erase name are inferred from original instructions.
struct List {unsigned count,capacity;
void **items;
};
extern "C" void *fn_802eefe0(void *,int,unsigned);
inline void release(void *p){(*(void (**)(void *))(*(char **)p+16))(p);
}extern "C" void f4c_erase_80210dd8(List *self,void **first,void **last){unsigned removed=last-first;
void **end=self->items+self->count;
unsigned i=0;
if(i<removed){void **cursor=first;
do{void *p=*cursor++;
if(p)release(p);
++i;
}while(i<removed);
}unsigned count=end-last;
void **source=first+removed;
for(i=0;
i<count;
++i)first[i]=source[i];
fn_802eefe0(first+count,0,removed*4);
self->count-=removed;
}