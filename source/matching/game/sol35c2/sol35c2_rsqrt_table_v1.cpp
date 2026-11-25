// Original constructs a byte lookup table by rounding reciprocal-root IEEE bits.
extern "C" void *fn_801fe220(unsigned int);
extern "C" float fn_802e82c0(float);
extern unsigned char *lbl_804ab744;
extern float lbl_803a9b48[];
union FloatBits { unsigned int bits; float value; };
extern "C" int sol35c2_rsqrt_table_801a118c() {
 unsigned int input = 0;
 unsigned char *out = (unsigned char *)fn_801fe220(128);
 int remaining = 128;
 float scale = lbl_803a9b48[0];
 lbl_804ab744 = out;
 do {
  FloatBits v;
  v.bits = input | 0x3f000000;
  input += 0x20000;
  v.value = scale / fn_802e82c0(v.value);
  --remaining;
  *out++ = (v.bits + 0x2000) >> 15;
 } while(remaining);
 lbl_804ab744[64] = 255;
 return 0;
}
