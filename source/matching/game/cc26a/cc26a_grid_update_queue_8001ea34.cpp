// Original bounded grid update queue. Entries are32-byte value records.
struct cc26a_EntryEa34 {int finished;unsigned int unknown[4];int x,z,layer;};
inline void cc26a_copyEa34(cc26a_EntryEa34 *where,cc26a_EntryEa34 *next,cc26a_EntryEa34 *last){int count=last-next;for(;count>0;--count)*where++=*next++;}
struct cc26a_RangeEa34 {cc26a_EntryEa34 *begin,*end;bool empty()const{return begin==end;}void erase(cc26a_EntryEa34 *where){cc26a_EntryEa34 *next=where+1;if(next!=end){cc26a_copyEa34(where,next,end);}--end;}};
struct cc26a_GridEa34 {unsigned char unknown[72];cc26a_RangeEa34 pending;unsigned char unknown80[68];int dirty;};
extern "C" void cc26a_prepare_8001f2cc(cc26a_GridEa34*);
extern "C" void *cc26a_find_8001df1c(cc26a_GridEa34*,int,int);
extern "C" int cc26a_update_8001e590(cc26a_GridEa34*,int,int,int);
extern "C" void cc26a_finish_8001eee8(cc26a_EntryEa34*);
extern "C" void cc26a_grid_update_queue_8001ea34(cc26a_GridEa34 *self){
 if(!self->pending.empty()){
  cc26a_prepare_8001f2cc(self);
  if(!self->pending.empty()){
   int budget=1;
   do {
    cc26a_EntryEa34 *entry=self->pending.begin;
    if(entry->finished==1){self->pending.erase(entry);if(self->pending.empty())return;}
    entry=self->pending.begin;
    int x=entry->x,z=entry->z,layer=entry->layer;int complete=1;
    if(cc26a_find_8001df1c(self,x,z))complete=cc26a_update_8001e590(self,x,z,layer);
    else --budget;
    if(complete){cc26a_finish_8001eee8(entry);if(entry->layer==0)self->dirty=1;}
    if(self->pending.empty())return;
   }while(budget++<=0);
  }
 }
}
