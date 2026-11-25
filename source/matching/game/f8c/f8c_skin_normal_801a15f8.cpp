// Names, roles, types, qualifiers and layouts are inferred from original instructions.
struct F8cNormalMatrix{float m[16];};
extern const float lbl_803a9b50[],lbl_803a9b54[];extern unsigned char*lbl_804ab744;
union F8cNormalBits{float f;unsigned u;};
extern "C" void f8c_skin_normal_801a15f8(float*src,unsigned influences,float*weights,unsigned char*indices,F8cNormalMatrix**matrices,float*dst,int count,int srcStride,int dstStride){
while(count--){float y=src[1],x=src[0],z=src[2];float*m=matrices[*indices]->m;float w0=*weights;float a0=(x*m[0]+y*m[4]+z*m[8])*w0;float a1=(x*m[1]+y*m[5]+z*m[9])*w0;float a2=(x*m[2]+y*m[6]+z*m[10])*w0;
for(unsigned i=1;i<influences;++i){if(*(unsigned*)(weights+i)){float*m=matrices[indices[i]]->m;float w=weights[i];a0=w*(x*m[0]+y*m[4]+z*m[8])+a0;a1=w*(x*m[1]+y*m[5]+z*m[9])+a1;a2=w*(x*m[2]+y*m[6]+z*m[10])+a2;}}
float n=a0*a0;n=a1*a1+n;n=a2*a2+n;F8cNormalBits b;unsigned bits=*(unsigned*)&n;b.u=(((380-((bits>>23)&255))<<22)&0xff800000)|(unsigned(lbl_804ab744[(bits>>17)&127])<<15);float v=b.f;v=(lbl_803a9b50[0]-v*v*n)*v*lbl_803a9b54[0];float inv=v;dst[0]=a0*inv;dst[1]=a1*inv;dst[2]=a2*inv;
weights+=influences;indices+=influences;src=(float*)((char*)src+srcStride);dst=(float*)((char*)dst+dstStride);
}}
