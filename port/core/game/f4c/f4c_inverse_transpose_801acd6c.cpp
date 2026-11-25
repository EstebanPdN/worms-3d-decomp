#include "w3d_ptr.h"
#line 1 "f4c_inverse_transpose_801acd6c.cpp"
// Partial layout, inverse-transpose name and volatile accesses are inferred.
// The second argument is stored at offset44 and forwarded to the observed inverse helper.
struct Matrix {volatile float values[9];
};
extern "C" int fn_801f65f0(Ptr32<Matrix>,Ptr32<const Matrix>);
extern "C" void f4c_inverse_transpose_801acd6c(Ptr32<char> self,Ptr32<const Matrix> input){*(Ptr32<Ptr32<const Matrix>>)(self+44)=input;
Ptr32<Matrix> m=(Ptr32<Matrix>)(self+48);
fn_801f65f0(m,input);
float temp=m->values[1];
float a=m->values[3];
m->values[3]=temp;
temp=m->values[5];
float b=m->values[7];
m->values[7]=temp;
temp=m->values[6];
float c=m->values[2];
m->values[2]=temp;
m->values[1]=a;
m->values[5]=b;
m->values[6]=c;
}

