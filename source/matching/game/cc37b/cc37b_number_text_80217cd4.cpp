// Sixteen-byte suffix view covers signed32 decimal output, NUL and cursor decrement.
// Its extent describes accesses here, not the full original scratch allocation.
// Legacy shared scratch formatter: zero mode is hexadecimal with 0x prefix,
// positive mode is unsigned decimal, negative mode signed decimal.
// Scratch and digit-table data remain external and unowned.
extern "C" char cc37b_scratch_suffix_804641b0[16];
extern "C" const char cc37b_hex_digits_803b3800[];
extern "C" char* w3d_cc37b_number_text_80217cd4(unsigned value,int mode) {
 char* p=cc37b_scratch_suffix_804641b0+15;
 *p=0; --p;
 if(mode==0) {
  do { *p=cc37b_hex_digits_803b3800[value&15]; --p; value>>=4; }while(value);
  *p--='x'; *p='0';
 } else if(mode>0) {
  do { unsigned q=value/10; *p--=value-q*10+'0'; value=q;}while(value);
  goto finished;
 } else {
  bool negative=(int)value<0;
  if(negative) value=-value;
  do {unsigned q=value/10; *p--=value-q*10+'0'; value=q;}while(value);
  if(!negative) goto finished;
  *p='-';
 }
 --p;
 finished:
 return p+1;
}
