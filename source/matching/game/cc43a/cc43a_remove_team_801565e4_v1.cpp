// Volatile end models the original repeated loads at 80156608 and 80156658;
// its original declaration is unknown. It is not used for stack placement.
// Partial inferred turn-list view. Four list headers begin at byte 100.
struct cc43a_TeamList { int* begin; int* volatile end; int* capacity; };
struct cc43a_TurnLists { unsigned char unknown00[100]; cc43a_TeamList lists[4]; unsigned char unknown94[236]; int enabled; };
extern "C" void cc43a_remove_team_801565e4(cc43a_TurnLists* self,int team) {
 if(self->enabled) {
  cc43a_TeamList* list=self->lists;
  for(unsigned int i=0;i<4;++i,++list) {
   for(int* p=list->begin;p!=list->end;++p) {
    if(*p==team) {
     if(p+1!=list->end) __builtin_memcpy(p,p+1,(unsigned int)((char*)(list->end-1)-(char*)p));
     --list->end;
     return;
    }
   }
  }
 }
}
