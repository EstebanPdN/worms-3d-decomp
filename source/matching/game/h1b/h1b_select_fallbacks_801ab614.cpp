// External table and receiver prefixes. No local runtime arrays are constructed.
extern const unsigned char lbl_803aa2b0[];
struct Receiver {unsigned unknown[31];unsigned mapping[26];};
extern "C" int h1b_select_fallbacks_801ab614(Receiver*self,const unsigned*available,unsigned count){
 unsigned row=0;
 do {
  unsigned offset=row*27;unsigned index=0;++row;
  unsigned chosen=26;bool missing=true;unsigned primary=lbl_803aa2b0[offset];
  while(index<count){if(primary==available[index]){chosen=primary;missing=false;break;}++index;}
  unsigned fallback=0;
  if(missing && lbl_803aa2b0[offset+1]!=26){
   do {
    unsigned at=offset+fallback;++fallback;index=0;chosen=lbl_803aa2b0[at+1];
    while(index<count){if(chosen==available[index]){missing=false;break;}++index;}
   }while(missing && lbl_803aa2b0[offset+fallback+1]!=26);
  }
  self->mapping[primary]=chosen;
 }while(row<=10);
 return 0;
}
