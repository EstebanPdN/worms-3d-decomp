// Partial inferred turn-list view. Four list headers begin at byte 100.
struct cc43a_TeamList { int* begin; int* end; int* capacity; };
struct cc43a_TurnLists { unsigned char unknown00[100]; cc43a_TeamList lists[4]; unsigned char unknown94[236]; int enabled; };
struct cc43a_TeamIterator { int* pointer; cc43a_TeamIterator(int* p):pointer(p){} bool operator!=(const cc43a_TeamIterator& other) const {return pointer!=other.pointer;} void operator++() {++pointer;} };
extern "C" void cc43a_remove_team_801565e4(cc43a_TurnLists* self,int team) {
 if(self->enabled) {
  cc43a_TeamList* list=self->lists;
  for(unsigned int i=0;i<4;++i,++list) {
   for(cc43a_TeamIterator it(list->begin);it!=cc43a_TeamIterator(list->end);++it) {
    int* p=it.pointer;
    if(*p==team) {
     if(p+1!=list->end) __builtin_memcpy(p,p+1,(unsigned int)((char*)(list->end-1)-(char*)p));
     --list->end;
     return;
    }
   }
  }
 }
}
