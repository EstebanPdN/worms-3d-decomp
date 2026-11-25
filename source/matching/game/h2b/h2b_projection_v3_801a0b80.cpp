// External camera view; the matrix's four columns are observed in-place.
struct Column {float x,y,z,w;};
struct Matrix {Column column[4];};
struct CameraView {unsigned unknown[21]; Matrix projection; float left,right,bottom,top,nearPlane,farPlane;int orthographic;};
extern "C" {extern const float scalar_803a9b24[],scalar_803a9b28[],scalar_803a9b2c[],scalar_803a9b30[],scalar_803a9b34[];}
extern "C" void h2b_projection_v3_801a0b80(CameraView *c) {
    float dx=c->right-c->left,sx=c->right+c->left;
    float dy=c->top-c->bottom,sy=c->top+c->bottom;
    float dz=c->farPlane-c->nearPlane,sz=c->farPlane+c->nearPlane;
    if(c->orthographic) {
        Column *c0=&c->projection.column[0],*c1=&c->projection.column[1],*c2=&c->projection.column[2],*c3=&c->projection.column[3];
        c0->x=scalar_803a9b24[0]/dx;c1->x=scalar_803a9b28[0];c2->x=scalar_803a9b28[0];c3->x=-sx/dx;
        c0->y=scalar_803a9b28[0];c1->y=scalar_803a9b24[0]/dy;c2->y=scalar_803a9b28[0];c3->y=-sy/dy;
        c0->z=scalar_803a9b28[0];c1->z=scalar_803a9b28[0];c2->z=scalar_803a9b2c[0]/dz;c3->z=-sz/dz;
        c0->w=scalar_803a9b28[0];c1->w=scalar_803a9b28[0];c2->w=scalar_803a9b28[0];c3->w=scalar_803a9b30[0];
    } else {
        Column *c0=&c->projection.column[0],*c1=&c->projection.column[1],*c2=&c->projection.column[2],*c3=&c->projection.column[3];
        c0->x=scalar_803a9b24[0]/dx;c1->x=scalar_803a9b28[0];c2->x=sx/dx;c3->x=scalar_803a9b28[0];
        c0->y=scalar_803a9b28[0];c1->y=scalar_803a9b24[0]/dy;c2->y=sy/dy;c3->y=scalar_803a9b28[0];
        c0->z=scalar_803a9b28[0];c1->z=scalar_803a9b28[0];c2->z=-sz/dz;c3->z=c->nearPlane*scalar_803a9b2c[0]*c->farPlane/dz;
        c0->w=scalar_803a9b28[0];c1->w=scalar_803a9b28[0];c2->w=scalar_803a9b34[0];c3->w=scalar_803a9b28[0];
    }
}
