// Partial layout, inverse-transpose name and volatile accesses are inferred.
// The second argument is stored at offset44 and forwarded to the observed inverse helper.
struct Matrix {volatile float values[9];
};
extern "C" int fn_801f65f0(Matrix *,const Matrix *);
extern "C" void f4c_inverse_transpose_801acd6c(char *self,const Matrix *input){*(const Matrix **)(self+44)=input;
Matrix *m=(Matrix *)(self+48);
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