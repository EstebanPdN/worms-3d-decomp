// External camera view; the matrix's four columns are observed in-place.
struct Column {float x,y,z,w;};
struct Matrix {Column column[4];
    void set(float a,float b,float c,float d,float e,float f,float g,float h,
             float i,float j,float k,float l,float m,float n,float o,float p) {
        Column *c0=&column[0],*c1=&column[1],*c2=&column[2],*c3=&column[3];
        c0->x=a;c1->x=b;c2->x=c;c3->x=d;
        c0->y=e;c1->y=f;c2->y=g;c3->y=h;
        c0->z=i;c1->z=j;c2->z=k;c3->z=l;
        c0->w=m;c1->w=n;c2->w=o;c3->w=p;
    }
};
struct CameraView {unsigned unknown[21]; Matrix projection; float left,right,bottom,top,nearPlane,farPlane;int orthographic;};
extern "C" {extern const float scalar_803a9b24[],scalar_803a9b28[],scalar_803a9b2c[],scalar_803a9b30[],scalar_803a9b34[];}
extern "C" void h2b_projection_801a0b80(CameraView *c) {
    float sx=c->right+c->left,dx=c->right-c->left;
    float sy=c->top+c->bottom,dy=c->top-c->bottom;
    float sz=c->farPlane+c->nearPlane,dz=c->farPlane-c->nearPlane;
    if(c->orthographic) {
        c->projection.set(scalar_803a9b24[0]/dx,scalar_803a9b28[0],scalar_803a9b28[0],-sx/dx,
            scalar_803a9b28[0],scalar_803a9b24[0]/dy,scalar_803a9b28[0],-sy/dy,
            scalar_803a9b28[0],scalar_803a9b28[0],scalar_803a9b2c[0]/dz,-sz/dz,
            scalar_803a9b28[0],scalar_803a9b28[0],scalar_803a9b28[0],scalar_803a9b30[0]);
    } else {
        c->projection.set(scalar_803a9b24[0]/dx,scalar_803a9b28[0],sx/dx,scalar_803a9b28[0],
            scalar_803a9b28[0],scalar_803a9b24[0]/dy,sy/dy,scalar_803a9b28[0],
            scalar_803a9b28[0],scalar_803a9b28[0],-sz/dz,(c->nearPlane*scalar_803a9b2c[0]*c->farPlane)/dz,
            scalar_803a9b28[0],scalar_803a9b28[0],scalar_803a9b34[0],scalar_803a9b28[0]);
    }
}
