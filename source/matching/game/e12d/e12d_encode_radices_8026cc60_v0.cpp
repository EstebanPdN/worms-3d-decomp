// Mixed-radix encoding of a seed's digit array into one scalar value.
//
// The seed keeps its encoded value at +0x34 and nine mixed-radix digits at
// +0x38 (the digit at +0x38 is the most significant one and is copied to the
// encoded value first). For each following digit the product of the radices
// below it is rebuilt from the static radix table 0x803cbcb0 and added in.
//
// Observed layout:
//   seed + 0x34 : encoded value
//   seed + 0x38 : digits[10] (only the first nine are consumed here)
//   radices     : unsigned short[9] at 0x803cbcb0 (shared with the decoder at
//                 0x8026c96c)

// Partial seed view; the surrounding fields of the original type are unknown.
struct W3dSeed {
    unsigned char unknown00[52];
    unsigned int encoded;        // +0x34
    unsigned int digits[10];     // +0x38
};

extern const unsigned short w3d_radices_803cbcb0[];

// Format text with one argument, referenced by original address.
extern const char w3d_seed_format_803cbc80[];

// Original helper 0x8026ce3c: returns its second argument, or 1 when zero.
extern "C" unsigned int w3d_nonzero_seed_8026ce3c(W3dSeed *, unsigned int);

// Original variadic string formatter 0x8020c510.
extern "C" void w3d_string_format_8020c510(W3dSeed *, const char *, ...);

extern "C" unsigned int e12d_encode_radices_8026cc60(W3dSeed *self)
{
    unsigned int i;
    self->encoded = self->digits[0];
    for (i = 1; i < 10; i++) {
        // Product of radices[0..i-1].
        unsigned int product = w3d_radices_803cbcb0[0];
        unsigned int j = 1;
        while (j < i)
            product *= w3d_radices_803cbcb0[j++];
        self->encoded += self->digits[i] * product;
    }
    // Format the seed with its non-zero encoded value; the result is dropped.
    w3d_string_format_8020c510(self, w3d_seed_format_803cbc80,
                               w3d_nonzero_seed_8026ce3c(self, self->encoded));
    return self->encoded;
}
