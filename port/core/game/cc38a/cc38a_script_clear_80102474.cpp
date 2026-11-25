#include "w3d_ptr.h"
#line 1 "cc38a_script_clear_80102474.cpp"

// Clear script collection in index order; callback may alter the array, so
// each loop condition re-reads its size. The zero-byte move is original.
struct cc38a_Script;
extern "C" void cc38a_destroy_800ffb78(Ptr32<cc38a_Script>,int);
extern "C" Ptr32<void> cc38a_move_802eee50(Ptr32<void>,Ptr32<const void>,unsigned,...);
struct cc38a_Array {Ptr32<Ptr32<cc38a_Script>> begin;Ptr32<Ptr32<cc38a_Script>> end;Ptr32<Ptr32<cc38a_Script>> capacity;
 unsigned size()const{return end-begin;}
 Ptr32<cc38a_Script> at(unsigned i)const{return *(Ptr32<Ptr32<cc38a_Script>>)((Ptr32<char>)begin+(i<<2));}
 void clear(){Ptr32<Ptr32<cc38a_Script>> first=begin;Ptr32<Ptr32<cc38a_Script>> last=end;int bytes=(Ptr32<char>)last-(Ptr32<char>)first;cc38a_move_802eee50(first,last,0);end=(Ptr32<Ptr32<cc38a_Script>>)((Ptr32<char>)end-bytes);}
};
struct cc38a_Runtime {unsigned char unknown[28];cc38a_Array scripts;int active;void clear(int value){scripts.clear();active=value;}};
extern "C" void cc38a_script_clear_80102474(Ptr32<cc38a_Runtime> self){
 for(unsigned i=0;i<self->scripts.size();++i){Ptr32<cc38a_Script> p=self->scripts.at(i);if(p)cc38a_destroy_800ffb78(p,3);}
 self->clear(0);
}


