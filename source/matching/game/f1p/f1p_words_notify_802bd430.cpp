// Original 0x802bd430. Observed layout and operations; role inferred.
struct Words { unsigned x,y,z; int operator==(const Words &b)const{return x==b.x && y==b.y && z==b.z;} };
struct Item { void **v; };
struct Owner { char pad[40];Words words;char pad34[44];Item *item; };
extern "C" void fn_802bf81c(Owner *);
extern "C" void fn_802bd354(Owner *);
extern "C" void w3d_words_notify_802bd430(Owner *self,const Words *words) {
 int changed=0;
 if(!(self->words==*words)) {self->words=*words;changed=1;}
 if(changed==1 && self->item){((void(*)(Item*,Words*,int))self->item->v[19])(self->item,&self->words,0);fn_802bf81c(self);}
 fn_802bd354(self);
}
