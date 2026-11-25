// Partial list layout and virtual-method roles are inferred from original offsets.
struct List {unsigned count,capacity;
void **items;
};
extern "C" void fn_80210dd8(List *,void **,void **);
inline void call(void *p,unsigned off){(*(void (**)(void *))(*(char **)p+off))(p);
}extern "C" int f4c_clear_801db8b4(char *self){(*(void (**)(void *))(*(char **)self+32))(self);
(*(int (**)(void *,int))(*(char **)self+140))(self,1);
call(self,88);
if(*(unsigned *)(self+48)){List *list=(List *)(self+48);
do{void **first=list->items;
call(*first,24);
fn_80210dd8(list,first,first+1);
}while(*(unsigned *)(self+48));
}void *old=*(void **)(self+172);
if(old)call(old,16);
*(void **)(self+172)=0;
return 0;
}