#include "w3d_ptr.h"
#line 1 "f15a_clear_selection_80285ee0.cpp"
// Inferred partial selection-list and reference-counted text views.
// Entry stride12 and header offsets are observed; no complete owner layout or
// allocation size claimed. Native member destruction precedes base-interface release.
extern "C" void fn_8020bb2c(Ptr32<void>),fn_8020c5c4(Ptr32<void>),fn_80341588(Ptr32<void>);
struct F15aEraseIface {Ptr32<Ptr32<void>> table;};
struct F15aEraseHeader {unsigned short references,length,capacity;};
struct F15aEraseText {
 Ptr32<char> text;
 ~F15aEraseText(){fn_8020c5c4(this);fn_80341588(this);}
 void assign(const F15aEraseText&o){
  Ptr32<F15aEraseHeader> next=(Ptr32<F15aEraseHeader>)(o.text-6);++next->references;
  Ptr32<F15aEraseHeader> old=(Ptr32<F15aEraseHeader>)(text-6);if(!--old->references)fn_8020bb2c(old);
  text=o.text;
 }
};
struct F15aEraseHeld{Ptr32<F15aEraseIface> held;~F15aEraseHeld(){if(held)((Ptr32<void (Ptr32<void>)>)held->table[4])(held);}void clear(Ptr32<F15aEraseIface> v){if(held)((Ptr32<void (Ptr32<void>)>)held->table[4])(held);held=v;}};
struct F15aEraseEntry: F15aEraseHeld{
 unsigned id __attribute__((aligned(__alignof__(F15aEraseHeld))));F15aEraseText text;
 void assign(const F15aEraseEntry&o){
  if(o.held)((Ptr32<void (Ptr32<void>)>)o.held->table[3])(o.held);
  if(held)((Ptr32<void (Ptr32<void>)>)held->table[4])(held);
  held=o.held;id=o.id;text.assign(o.text);
 }
};
inline Ptr32<F15aEraseEntry> copyEntries(Ptr32<F15aEraseEntry> first,Ptr32<F15aEraseEntry> last,Ptr32<F15aEraseEntry> dest){for(int count=last-first;count>0;--count){dest->assign(*first);++first;++dest;}return dest;}
struct F15aEraseVector{Ptr32<F15aEraseEntry> begin; Ptr32<F15aEraseEntry> end;
 Ptr32<F15aEraseEntry> beginIt(){return begin;} Ptr32<F15aEraseEntry> endIt(){return end;}
 Ptr32<F15aEraseEntry> erase(Ptr32<F15aEraseEntry> position){
  if(position+1!=endIt())copyEntries(position+1,endIt(),position);
  Ptr32<F15aEraseEntry> oldEnd=end;end=oldEnd-1;(oldEnd-1)->~F15aEraseEntry();return position;
 }
};
struct F15aEraseList{char unknown[224];F15aEraseVector entries;};
extern "C" void w3d_f15a_clear_selection_80285ee0(Ptr32<F15aEraseList> s){
 Ptr32<F15aEraseEntry> position=s->entries.beginIt();
 if(position!=s->entries.endIt()){do{position->clear(0);position=s->entries.erase(position);}while(position!=s->entries.endIt());}
}


