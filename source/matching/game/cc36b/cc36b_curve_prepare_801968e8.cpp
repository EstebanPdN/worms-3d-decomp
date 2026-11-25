// Arithmetic order preserves the original single-precision operations and NaN tests.
// Literals independently decoded from DOL803a84d8/dc/e0:5729578.0,0.0,1.0.
// Field names are inferred; scratch declarations establish no runtime ownership.
// Four-sample endpoint tangent cubic setup. Global scratch remains unowned.
struct cc36b_CurveScratch { float cubic,quadratic,linear,constant; };
extern cc36b_CurveScratch cc36b_curve_scratch_804a91d8[];
extern float cc36b_curve_origin_804b18d0;
extern "C" void w3d_cc36b_curve_prepare_801968e8(int *enabled,float *times,float *values) {
 if(!*enabled) return;
 cc36b_curve_origin_804b18d0=times[0];
 float leftWidth=times[1]-times[0];
 float span=times[3]-times[0];
 float delta=values[3]-values[0];
 float left=5729578.0f;
 float right=left;
 if(leftWidth!=0.0f) left=(values[1]-values[0])/leftWidth;
 float rightWidth=times[3]-times[2];

 if(rightWidth!=0.0f) right=(values[3]-values[2])/rightWidth;
 float scaledLeft=span*left;
 float scaledRight=span*right;
 float factor=1.0f/(span*span);
 cc36b_CurveScratch *out=cc36b_curve_scratch_804a91d8;
 out->linear=left;
 out->cubic=(((scaledLeft+scaledRight)-delta)-delta)*factor/span;
 out->quadratic=((((delta+delta+delta)-scaledLeft)-scaledLeft)-scaledRight)*factor;
 out->constant=values[0];
}
