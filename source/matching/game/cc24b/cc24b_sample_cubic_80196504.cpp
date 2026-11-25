struct Cc24bSampleCubic {float coefficients[4];};
extern "C" float lbl_803a84b0[],lbl_803a84b4[];
extern "C" float lbl_804b18d0,lbl_804b18d4;
extern "C" int lbl_804b18c4;
extern "C" Cc24bSampleCubic lbl_804a91d8,lbl_804a91e8;
extern "C" int fn_801975b4(float,float,int*,float*,int,int,int,float*);
extern "C" float w3d_cc24b_sample_cubic_80196504(float value,int *active){
 if(!*active)return lbl_803a84b0[0];
 if(lbl_804b18d0==value)value=lbl_803a84b0[0];
 else if(lbl_804b18d4==value)value=lbl_803a84b4[0];
 else value=(value-lbl_804b18d0)/(lbl_804b18d4-lbl_804b18d0);
 float t;
 if(lbl_804b18c4)t=value;
 else{
  float equation[4];float roots[6];
  float constant=lbl_804a91d8.coefficients[0]-value;
  equation[3]=lbl_804a91d8.coefficients[3];equation[2]=lbl_804a91d8.coefficients[2];equation[1]=lbl_804a91d8.coefficients[1];equation[0]=constant;
  int count=fn_801975b4(lbl_803a84b0[0],lbl_803a84b4[0],active,equation,3,1,1,roots);
  t=count==1?roots[0]:lbl_803a84b0[0];
 }
 Cc24bSampleCubic *curve=&lbl_804a91e8;
 return t*(t*(t*curve->coefficients[3]+curve->coefficients[2])+curve->coefficients[1])+curve->coefficients[0];
}
