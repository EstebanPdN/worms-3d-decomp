struct G1cSlotArray { int values[1]; int &operator[](unsigned index) { return values[index]; } };
struct G1cSeekOwnerPrefix { unsigned char unknown0[132]; G1cSlotArray selected; };
extern "C" G1cSeekOwnerPrefix *owner_804aac54;
extern "C" const char empty_803814dc[];
extern "C" int compare_802ef234(const char *,const char *);
extern "C" int find_800a7da4(G1cSeekOwnerPrefix *,const char *);
extern "C" void seek_800a7ee4(G1cSeekOwnerPrefix *);
extern "C" void g1c_named_slot_select_800a7e14(unsigned slot,const char *name) {
 if(!name || compare_802ef234(name,empty_803814dc)==0) {
  G1cSeekOwnerPrefix *owner=owner_804aac54;owner->selected[slot]=-1;seek_800a7ee4(owner);
 } else {
  int found=find_800a7da4(owner_804aac54,name);
  if(found>=0){G1cSeekOwnerPrefix *owner=owner_804aac54;owner->selected[slot]=found;seek_800a7ee4(owner);}
 }
}
