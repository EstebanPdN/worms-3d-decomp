extern float lbl_804ab6e4;
extern float lbl_803a8504[],lbl_803a8508[],lbl_803a850c[],lbl_803a8510[],lbl_803a8514[],lbl_803a8518[];
extern "C" float fn_802e82c0(float);
extern "C" void sol35c_ratio_roots_80197128(void *,float *first,float *second) {
 float input=*first;
 float result;
 if(input+lbl_804ab6e4<lbl_803a8504[0]) {
  float a=input-lbl_803a8508[0];
  float b=input-lbl_803a850c[0];
  float root=fn_802e82c0(a*a-b*lbl_803a8510[0]*b);
  a=-a;
  float candidate=(a+root)*lbl_803a8514[0];
  if(*second+lbl_804ab6e4>candidate)result=candidate-lbl_804ab6e4;
  else {result=(a-root)*lbl_803a8514[0]+lbl_804ab6e4;if(*second>=result)return;}
 }else {
  *first=lbl_803a8504[0]-lbl_804ab6e4;
  result=lbl_803a8518[0]-lbl_804ab6e4;
 }
 *second=result;
}
