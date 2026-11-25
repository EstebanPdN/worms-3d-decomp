
// Clear script collection in index order; callback may alter the array, so
// each loop condition re-reads its size. The zero-byte move is original.
struct cc38a_Script;
extern "C" void cc38a_destroy_800ffb78(cc38a_Script*,int);
extern "C" void* cc38a_move_802eee50(void*,const void*,unsigned,...);
struct cc38a_Array {cc38a_Script** begin;cc38a_Script** end;cc38a_Script** capacity;
 unsigned size()const{return end-begin;}
 cc38a_Script* at(unsigned i)const{return *(cc38a_Script**)((char*)begin+(i<<2));}
 void clear(){cc38a_Script** first=begin;cc38a_Script** last=end;int bytes=(char*)last-(char*)first;cc38a_move_802eee50(first,last,0);end=(cc38a_Script**)((char*)end-bytes);}
};
struct cc38a_Runtime {unsigned char unknown[28];cc38a_Array scripts;int active;void clear(int value){scripts.clear();active=value;}};
extern "C" void cc38a_script_clear_80102474(cc38a_Runtime* self){
 for(unsigned i=0;i<self->scripts.size();++i){cc38a_Script* p=self->scripts.at(i);if(p)cc38a_destroy_800ffb78(p,3);}
 self->clear(0);
}
