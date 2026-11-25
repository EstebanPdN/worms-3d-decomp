
// PPC32 matrix is nine row-major floats; original permits aliasing and performs no singularity check.
struct Matrix{float m[9];};extern "C" const float one_803b1624[];
extern "C" int w3d_cx13b_matrix3_inverse_801f65f0(Matrix*out,const Matrix*a){float c0=a->m[4]*a->m[8]-a->m[5]*a->m[7];float c1=a->m[3]*a->m[8]-a->m[5]*a->m[6];float c2=a->m[3]*a->m[7]-a->m[4]*a->m[6];float factor=one_803b1624[0]/(a->m[0]*c0-a->m[1]*c1+a->m[2]*c2);out->m[0]=factor*c0;out->m[1]=-factor*(a->m[1]*a->m[8]-a->m[2]*a->m[7]);out->m[2]=factor*(a->m[1]*a->m[5]-a->m[2]*a->m[4]);out->m[3]=-factor*(a->m[3]*a->m[8]-a->m[5]*a->m[6]);out->m[4]=factor*(a->m[0]*a->m[8]-a->m[2]*a->m[6]);out->m[5]=-factor*(a->m[0]*a->m[5]-a->m[2]*a->m[3]);out->m[6]=factor*(a->m[3]*a->m[7]-a->m[4]*a->m[6]);out->m[7]=-factor*(a->m[0]*a->m[7]-a->m[1]*a->m[6]);out->m[8]=factor*(a->m[0]*a->m[4]-a->m[1]*a->m[3]);return 0;}

