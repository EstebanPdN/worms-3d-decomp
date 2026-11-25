// Partial PPC32 owner layout; center and radius names describe observed arithmetic.
struct Vec3 {float x,y,z;void add(const Vec3&o){x+=o.x;y+=o.y;z+=o.z;}};
struct Owner {char unknown[140];Vec3 center;char unknown152[36];float radius;};
extern "C" float sin_802e88ac(float),cos_802e86d4(float);
extern "C" void f1b_spherical_point_800d4d64(Owner*s,Vec3*out,float a,float b){
out->y=s->radius*sin_802e88ac(b);
out->x=cos_802e86d4(b)*sin_802e88ac(a)*s->radius;
out->z=cos_802e86d4(b)*cos_802e86d4(a)*s->radius;
out->add(s->center);
}
