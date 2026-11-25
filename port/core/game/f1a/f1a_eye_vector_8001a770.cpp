#include "w3d_ptr.h"
#line 1 "f1a_eye_vector_8001a770.cpp"
// Original 0x8001a770; eye-level interpretation follows its original property string.
struct F1aEyeVec {float x,y,z;};
inline F1aEyeVec &copy_eye(F1aEyeVec &dst,const F1aEyeVec &src){dst=src;return dst;}
extern "C" {
extern F1aEyeVec lbl_8041e838,lbl_8041e844;
extern char lbl_8036af50[];
int w3d_auto_800fc270(Ptr32<Ptr32<const char>>,Ptr32<float>);
void w3d_f1a_eye_vector_8001a770(Ptr32<const F1aEyeVec> v,int flag) {
 copy_eye(lbl_8041e844,copy_eye(lbl_8041e838,*v));
 if(flag){Ptr32<const char> name=lbl_8036af50;float value;w3d_auto_800fc270(&name,&value);lbl_8041e844.y+=value;}
}
}


