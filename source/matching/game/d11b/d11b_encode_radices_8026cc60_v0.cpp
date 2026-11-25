// Partial seed/string-owner view; original complete type/sizeof unknown.
struct d11b_Seed { unsigned char unknown00[52]; unsigned int encoded, digits[10]; };
extern const unsigned short d11b_radices_803cbcb0[];
extern const char d11b_seed_format_803cbc80[];
// Original helper consumes r4, returning the supplied value or one when zero.
extern "C" unsigned int d11b_nonzero_seed_8026ce3c(d11b_Seed *,unsigned int);
extern "C" void d11b_format_seed_8020c510(d11b_Seed *,const char *,...);
extern "C" unsigned int d11b_encode_radices_8026cc60(d11b_Seed *self) {
    self->encoded=self->digits[0];
    unsigned int i=1;
    do {
        unsigned int offset=i*sizeof(unsigned int);
        unsigned int product=d11b_radices_803cbcb0[0];
        for (unsigned int j=1;j<i;++j) product*=d11b_radices_803cbcb0[j];
        ++i;
        self->encoded+=*reinterpret_cast<unsigned int *>(reinterpret_cast<unsigned char *>(self->digits)+offset)*product;
    } while (i<10);
    d11b_format_seed_8020c510(self,d11b_seed_format_803cbc80,d11b_nonzero_seed_8026ce3c(self,self->encoded));
    return self->encoded;
}
