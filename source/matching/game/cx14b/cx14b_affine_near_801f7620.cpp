
// PPC32 affine matrix consists of twelve four-byte floats; translation starts +36.
struct Matrix{float m[12];};extern "C" int near_801f659c(const Matrix*,const Matrix*,float);
inline int translation(const float*a,const float*b,float e){int n=3,off=0;do{if(__builtin_fabsf(*(const float*)(off+(unsigned)b)-*(const float*)(off+(unsigned)a))>e)return 0;off+=4;}while(--n);return 1;}
extern "C" int w3d_cx14b_affine_near_801f7620(const Matrix*a,const Matrix*b,float epsilon){return near_801f659c(a,b,epsilon)&&translation(a->m+9,b->m+9,epsilon);}


