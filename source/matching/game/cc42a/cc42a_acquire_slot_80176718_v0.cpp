// Inferred partial layouts. The original multiplies slot indices by 24; the
// stride is observed, but a complete original class declaration is not known.
struct cc42a_Slot;
struct cc42a_SlotVtable {void* unknown00[3];int (*retain)(cc42a_Slot*);int (*release)(cc42a_Slot*);};
struct cc42a_Slot {cc42a_SlotVtable* vtable;unsigned int value;unsigned short index;unsigned short unknown0a;unsigned int cleared;unsigned int argument;unsigned int unknown14;};
struct cc42a_Group;
struct cc42a_GroupVtable {void* unknown00[14];int (*attach)(cc42a_Group*,cc42a_Slot*);};
struct cc42a_Group {cc42a_GroupVtable* vtable;};
struct cc42a_FreeSlots {unsigned int* begin;unsigned int* end;inline unsigned int count(){return ((unsigned int)end-(unsigned int)begin)>>2;} inline unsigned int pop(){return *--end;}};
struct cc42a_SlotOwner {unsigned char unknown00[24];cc42a_Group** groups;unsigned char unknown1c[2068];cc42a_Slot* slots;unsigned int unknown834;cc42a_FreeSlots freeSlots;};
extern "C" int cc42a_find_80177eb0(cc42a_SlotOwner*,void*,unsigned short*);
extern "C" int cc42a_acquire_slot_80176718(cc42a_SlotOwner* self,void* key,unsigned int value,unsigned int argument,cc42a_Slot** output) {
 unsigned short index;
 int status=cc42a_find_80177eb0(self,key,&index);
 if(status<0)return status;
 if(!self->freeSlots.count())return (int)0x80004005;
 unsigned int slot=self->freeSlots.pop();
 cc42a_Slot* item=&self->slots[slot];
 if(item)item->vtable->retain(item);
 if(*output)(*output)->vtable->release(*output);
 *output=item;
 item->value=value;
 (*output)->cleared=0;
 (*output)->index=index;
 (*output)->argument=argument;
 cc42a_Group* group=*(cc42a_Group**)(index*4+(char*)self->groups);
 return group->vtable->attach(group,*output);
}
