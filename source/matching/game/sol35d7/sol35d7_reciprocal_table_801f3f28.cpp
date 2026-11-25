// Inferred 128-entry reciprocal lookup, with explicit IEEE32 representation access.
namespace sol35d7_reciprocal_table {
union FloatWord { float value; unsigned int word; };
extern "C" unsigned char *lbl_804ab8d0;
extern "C" const float lbl_803b0ec0[];
extern "C" void *fn_801fe220(unsigned int);
extern "C" float fn_802e82c0(float);
}
extern "C" int sol35d7_reciprocal_table_801f3f28() {
 using namespace sol35d7_reciprocal_table;
 unsigned char *out=static_cast<unsigned char *>(fn_801fe220(128));
 unsigned int bits=0;
 lbl_804ab8d0=out;
 float scale=lbl_803b0ec0[0];
 int remaining=128;
 do {
  FloatWord input; input.word=bits|0x3f000000U;
  bits+=0x20000;
  FloatWord result;result.value=scale/fn_802e82c0(input.value);
  *out++=static_cast<unsigned char>((result.word+0x2000U)>>15);
 }while(--remaining);
 lbl_804ab8d0[64]=255;
 return 0;
}
