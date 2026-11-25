#include "w3d_ptr.h"
#line 1 "cc23b_integer_digits_80212c74.cpp"
// Inferred integer formatting helper; preserves original unconditional reversal.
extern "C" void w3d_cc23b_integer_digits_80212c74(unsigned int value,Ptr32<char> out,unsigned int radix,int negative) {
 if (negative) { value = -value; *out++ = '-'; }
 Ptr32<char> first=out;
 unsigned int quotient;
 do { quotient=value/radix; unsigned int digit=value-quotient*radix;
 value=quotient; if(digit>9)*out=digit+'W';else *out=digit+'0'; ++out;
 } while(quotient);
 *out=0; --out;
 do {char a=*first; char b=*out; *out=a; *first=b; --out; ++first;}while(first<out);
}


