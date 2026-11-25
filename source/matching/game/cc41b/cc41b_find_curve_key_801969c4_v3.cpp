// Original 0x801969c4. Partial 24-byte key stride, key count and array reference.
// Inverse ordered comparisons follow fcmpu branches: unordered comparisons take the found path.
struct cc41b_CurveKey { float time; unsigned char unknown[20]; };
struct cc41b_CurveKeys { unsigned unknown; cc41b_CurveKey *keys; unsigned short count; };
struct cc41b_CurveReference { cc41b_CurveKeys *data; };
extern "C" int cc41b_find_curve_key_801969c4(cc41b_CurveReference *self,int *index,float key) {
 if(!self->data || !index)return 0;
 {
  *index=0;
  int count=self->data->count;
  if(count>0) {
   cc41b_CurveKey *keys=self->data->keys;
   int lower=0,upper=count-1;
   do {
    int middle=(lower+upper)/2;
    float time=*(float *)((char *)keys+middle*24);
    if(key<time)upper=middle-1;
    else {
     if(key>time)lower=middle+1;
     else {*index=middle;return 1;}
    }
   }while(lower<=upper);
   *index=lower;
  }
  return 0;
 }
 return 0;
}
