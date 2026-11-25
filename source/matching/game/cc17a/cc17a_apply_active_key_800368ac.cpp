// Pointer-vector owner at +4; entry match word is observed at +12.
struct Cc17aEntry{char pad[12];int key;};struct Cc17aVector{Cc17aEntry **begin,**end,**capacity;unsigned cc17a_size(){return end-begin;}};struct Cc17aOwner{unsigned tag;Cc17aVector items;};
extern "C" int active_80036c8c(Cc17aEntry*);extern "C" void apply_80036afc(Cc17aEntry*);
extern "C" void w3d_cc17a_apply_active_key_800368ac(Cc17aOwner*self,int key){for(unsigned i=0;i<self->items.cc17a_size();++i){if(active_80036c8c(*(Cc17aEntry**)((char*)self->items.begin+(i<<2))) && key==(*(Cc17aEntry**)((char*)self->items.begin+(i<<2)))->key){apply_80036afc(*(Cc17aEntry**)((char*)self->items.begin+(i<<2)));break;}}}
