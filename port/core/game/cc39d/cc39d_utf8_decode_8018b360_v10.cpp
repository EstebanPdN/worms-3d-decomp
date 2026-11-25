#include "w3d_ptr.h"
#line 1 "cc39d_utf8_decode_8018b360_v10.cpp"
// Decode one UTF-8 sequence to a 16-bit code unit (0x8018b360), the
// counterpart of the admitted 16-bit encoder at 0x8018b2b0. Lead bytes
// 0xxxxxxx, 110xxxxx and 1110xxxx give lengths 1, 2 and 3; any other lead
// byte gives length 0 and value 0. Continuation bytes are not validated.
// A local receives the length when no output is supplied. The three-byte
// form reads through a separate cursor. The original names, the cursor's
// role in the original source and any wider context are unknown.
extern "C" unsigned short cc39d_utf8_decode_8018b360(Ptr32<const unsigned char> text, Ptr32<unsigned int> length) {
    unsigned int local;
    Ptr32<const unsigned char> s = text;
    if (!length) length = &local;
    if (!(text[0] & 0x80)) { *length = 1; return text[0]; }
    else if ((text[0] & 0xe0) == 0xc0) { *length = 2; return ((text[0] & 0x1f) << 6) | (text[1] & 0x3f); }
    else if ((text[0] & 0xf0) == 0xe0) {
        *length = 3;
        unsigned char b0 = *s++;
        unsigned char b1 = *s++;
        unsigned char b2 = *s;
        return ((b0 & 0x0f) << 12) | ((b1 & 0x3f) << 6) | (b2 & 0x3f);
    }
    else { *length = 0; return 0; }
}


