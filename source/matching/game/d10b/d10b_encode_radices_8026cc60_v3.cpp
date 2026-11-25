// Partial seed/string-owner view; original complete type/sizeof unknown.
struct d10b_Seed { unsigned char unknown00[52]; unsigned int encoded, digits[10]; };
extern const unsigned short d10b_radices_803cbcb0[];
extern const char d10b_seed_format_803cbc80[];
// Original helper consumes r4, returning the supplied value or one when zero.
extern "C" unsigned int d10b_nonzero_seed_8026ce3c(d10b_Seed *,unsigned int);
extern "C" void d10b_format_seed_8020c510(d10b_Seed *,const char *,...);
extern "C" unsigned int d10b_encode_radices_8026cc60(d10b_Seed *self) {
    self->encoded=self->digits[0];
    unsigned int i=1;
    do {
        unsigned int product=d10b_radices_803cbcb0[0];
        for (unsigned int j=1;j<i;++j) product*=d10b_radices_803cbcb0[j];
        self->encoded+=self->digits[i]*product;
        ++i;
    } while (i<10);
    d10b_format_seed_8020c510(self,d10b_seed_format_803cbc80,d10b_nonzero_seed_8026ce3c(self,self->encoded));
    return self->encoded;
}
