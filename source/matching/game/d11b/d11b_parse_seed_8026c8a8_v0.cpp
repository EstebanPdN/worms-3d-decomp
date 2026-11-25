// Partial seed/string owner. The string's unsigned 16-bit length is observed
// four bytes before its text. The classifier symbol is the original biased
// table origin and must retain signed-character indexing.
struct d11b_ParsedSeed { char *text; };
extern const unsigned char d11b_seed_classification_803db449[];
extern "C" d11b_ParsedSeed *d11b_assign_seed_text_8020bd38(d11b_ParsedSeed *,const char *);
extern "C" long d11b_decimal_seed_802ed8c4(const char *);
extern "C" unsigned int d11b_hash_seed_8026cde8(d11b_ParsedSeed *,const char *);
extern "C" unsigned int d11b_nonzero_seed_value_8026ce2c(d11b_ParsedSeed *,unsigned int);
extern "C" void d11b_decode_seed_8026c96c(d11b_ParsedSeed *,unsigned int);
extern "C" void d11b_parse_seed_8026c8a8(d11b_ParsedSeed *self,const char *input) {
    bool numeric=true;
    d11b_assign_seed_text_8020bd38(self,input);
    const char *text=self->text;
    unsigned int index=0;
    if(reinterpret_cast<const unsigned short *>(text)[-2]) {
        do {
            if(!(d11b_seed_classification_803db449[static_cast<signed char>(text[index])]&4)) {numeric=false;break;}
            ++index;
        } while(index<reinterpret_cast<const unsigned short *>(text)[-2]);
    }
    unsigned int value;
    if(numeric)value=d11b_decimal_seed_802ed8c4(self->text);
    else value=d11b_hash_seed_8026cde8(self,self->text);
    d11b_decode_seed_8026c96c(self,d11b_nonzero_seed_value_8026ce2c(self,value));
}
