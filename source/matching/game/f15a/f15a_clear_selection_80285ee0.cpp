// Inferred partial selection-list and reference-counted text views.
// Entry stride12 and header offsets are observed; no complete owner layout or
// allocation size claimed. Native member destruction precedes base-interface release.
extern "C" void fn_8020bb2c(void*),fn_8020c5c4(void*),fn_80341588(void*);
struct F15aEraseIface {void **table;};
struct F15aEraseHeader {unsigned short references,length,capacity;};
struct F15aEraseText {
 char*text;
 ~F15aEraseText(){fn_8020c5c4(this);fn_80341588(this);}
 void assign(const F15aEraseText&o){
  F15aEraseHeader*next=(F15aEraseHeader*)(o.text-6);++next->references;
  F15aEraseHeader*old=(F15aEraseHeader*)(text-6);if(!--old->references)fn_8020bb2c(old);
  text=o.text;
 }
};
struct F15aEraseHeld{F15aEraseIface*held;~F15aEraseHeld(){if(held)((void(*)(void*))held->table[4])(held);}void clear(F15aEraseIface*v){if(held)((void(*)(void*))held->table[4])(held);held=v;}};
struct F15aEraseEntry: F15aEraseHeld{
 unsigned id;F15aEraseText text;
 void assign(const F15aEraseEntry&o){
  if(o.held)((void(*)(void*))o.held->table[3])(o.held);
  if(held)((void(*)(void*))held->table[4])(held);
  held=o.held;id=o.id;text.assign(o.text);
 }
};
inline F15aEraseEntry*copyEntries(F15aEraseEntry*first,F15aEraseEntry*last,F15aEraseEntry*dest){for(int count=last-first;count>0;--count){dest->assign(*first);++first;++dest;}return dest;}
struct F15aEraseVector{F15aEraseEntry*begin,*end;
 F15aEraseEntry*beginIt(){return begin;} F15aEraseEntry*endIt(){return end;}
 F15aEraseEntry*erase(F15aEraseEntry*position){
  if(position+1!=endIt())copyEntries(position+1,endIt(),position);
  F15aEraseEntry*oldEnd=end;end=oldEnd-1;(oldEnd-1)->~F15aEraseEntry();return position;
 }
};
struct F15aEraseList{char unknown[224];F15aEraseVector entries;};
extern "C" void w3d_f15a_clear_selection_80285ee0(F15aEraseList*s){
 F15aEraseEntry*position=s->entries.beginIt();
 if(position!=s->entries.endIt()){do{position->clear(0);position=s->entries.erase(position);}while(position!=s->entries.endIt());}
}
