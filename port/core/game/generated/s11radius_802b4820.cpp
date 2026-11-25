#include "w3d_ptr.h"
#line 1 "s11radius_802b4820.cpp"
/* Inferred 2-D radius hit test using three-component vector temporaries. */
struct S11Vec3 {
    float x,y,z;
    S11Vec3() {}
    S11Vec3(float a,float b,float c):x(a),y(b),z(c){}
    S11Vec3(const S11Vec3 &v) {float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;}
    S11Vec3 operator*(const S11Vec3 &v) const {S11Vec3 result(x*v.x,y*v.y,z*v.z); return result;}
    S11Vec3 operator-(const S11Vec3 &v) const {return S11Vec3(x-v.x,y-v.y,z-v.z);}
    float squared() const {return z*z+(x*x+y*y);}
    float distance_squared(const S11Vec3 &v) const {/* The original reserves an empty-constructed vector slot here. */ S11Vec3 scratch;float a=x-v.x,b=y-v.y,c=z-v.z;return c*c+(a*a+b*b);}
};
struct S11ScaleObject;
struct S11ScaleTable { Ptr32<void (void)> unused[27]; Ptr32<Ptr32<const S11Vec3> (Ptr32<S11ScaleObject>)> get_scale; };
struct S11ScaleObject {Ptr32<S11ScaleTable> vtable;};
struct S11RadiusConfig {char unknown00[20];S11Vec3 scale;};
struct S11RadiusOwner {char unknown00[40];Ptr32<S11RadiusConfig> config;char unknown2c[68];Ptr32<S11ScaleObject> graphic;char unknown74[96];int override_hit;};
extern "C" {
int fn_802B15E0(Ptr32<void>, float, float);
void fn_802B22E4(Ptr32<S11Vec3>,Ptr32<void>);
float fn_802E82C0(float);
extern const float lbl_803D7E14[],lbl_803D7E18[];
extern int lbl_804ABB4C;
int s11_radius_test_802b4820(Ptr32<S11RadiusOwner> owner,float x,float y) {
    if (owner->override_hit==1) return fn_802B15E0((Ptr32<char>)owner+0x1c, x, y);
    if (lbl_804ABB4C==1) return 0;
    S11Vec3 origin;
    fn_802B22E4(&origin,(Ptr32<char>)owner+0x1c);
    S11Vec3 scale(*owner->graphic->vtable->get_scale(owner->graphic));
    S11Vec3 extent(owner->config->scale);
    extent=extent*scale;
    S11Vec3 point(x,y,origin.z);
    extent.x*=lbl_803D7E14[0];
    float distance=fn_802E82C0(point.distance_squared(origin));
    if (distance<lbl_803D7E18[0]) distance=-distance;
    if (extent.x<lbl_803D7E18[0]) extent.x=-extent.x;
    return distance<=extent.x;
}
}


