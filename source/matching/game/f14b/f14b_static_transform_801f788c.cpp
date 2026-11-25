// Inferred identity-basis and zero-translation setup. The local basis is 36 bytes,
// the local vector is 12 bytes, and the external destination view spans 48 bytes.
// This is not the unrelated 64-byte matrix read view or an external matrix constructor.
// External destination ownership, original names and complete class identity remain unknown.
struct F14bBasis{float xx,xy,xz,yx,yy,yz,zx,zy,zz;F14bBasis(){xx=1.0f;xy=0.0f;xz=0.0f;yx=0.0f;yy=1.0f;yz=0.0f;zx=0.0f;zy=0.0f;zz=1.0f;}};
struct F14bVec{float x,y,z;F14bVec(float a,float b,float c):x(a),y(b),z(c){}F14bVec&operator=(const F14bVec&o){float a=o.x,b=o.y,c=o.z;x=a;y=b;z=c;return *this;}};
struct F14bTransform{F14bBasis basis;F14bVec translation;void set(const F14bBasis&b,const F14bVec&t){basis=b;translation=t;}};extern F14bTransform lbl_8045e748[];
extern "C" void f14b_static_transform_801f788c(int initialize,int priority){if(priority==65535&&initialize){F14bBasis basis;F14bVec translation(0.0f,0.0f,0.0f);lbl_8045e748[0].set(basis,translation);}}
