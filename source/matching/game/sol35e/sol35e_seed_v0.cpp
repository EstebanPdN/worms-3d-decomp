// Observed seed string view; the character table pointer has its original
// one-byte bias. Signed character classification is intentional.
struct sol35e_Seed { char *text; unsigned length() const {return ((unsigned short *)text)[-2];} char at(unsigned i) const {return text[i];} };
extern "C" void sol35e_assign_8020bd38(sol35e_Seed *,const char *);
extern "C" int sol35e_atol_802ed8c4(const char *);
extern "C" unsigned sol35e_hash_8026cde8(sol35e_Seed *,const char *);
extern "C" unsigned sol35e_normalize_8026ce2c(sol35e_Seed *,unsigned);
extern "C" void sol35e_decode_8026c96c(sol35e_Seed *,unsigned);
extern const unsigned char sol35e_ctype_803db449[];
extern "C" void sol35e_parse_seed_8026c8a8(sol35e_Seed *self,const char *text) {
 bool decimal=true;
 sol35e_assign_8020bd38(self,text);
 for(unsigned i=0;i<self->length();++i) {
  if (!(sol35e_ctype_803db449[self->at(i)]&4)) {decimal=false;break;}
 }
 unsigned value;
 if(decimal) value=sol35e_atol_802ed8c4(self->text);
 else value=sol35e_hash_8026cde8(self,self->text);
 sol35e_decode_8026c96c(self,sol35e_normalize_8026ce2c(self,value));
}
