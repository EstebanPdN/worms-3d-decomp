#if 0 /* Unmatched vector expression scheduling and frame layout. */
/* Vector expressions used by sphere-ray refinement. */
struct W3dS1Vector {
    float x,y,z;
    W3dS1Vector() {}
    W3dS1Vector(float a,float b,float c):x(a),y(b),z(c) {}
    W3dS1Vector operator*(float s) const { return W3dS1Vector(x*s,y*s,z*s); }
    W3dS1Vector operator+(const W3dS1Vector &b) const { return W3dS1Vector(x+b.x,y+b.y,z+b.z); }
    W3dS1Vector operator-(const W3dS1Vector &b) const { return W3dS1Vector(x-b.x,y-b.y,z-b.z); }
    W3dS1Vector &operator+=(const W3dS1Vector &b) { x+=b.x;y+=b.y;z+=b.z;return *this; }
    float squared() const { return z*z+(x*x+y*y); }
};
extern "C" {
extern W3dS1Vector w3d_velocity_80427414[],w3d_acceleration_80427438[],w3d_delta_80427444[],w3d_origin_80427408[],w3d_normal_80427450[];
extern float w3d_refined_804b17d4,w3d_radius2_804b17d8;
int w3d_fn_80040ff4(float lower,float upper)
{
    W3dS1Vector acceleration = w3d_acceleration_80427438[0]*(lower*lower*0.5f);
    W3dS1Vector velocity = w3d_velocity_80427414[0]*lower;
    W3dS1Vector point=w3d_delta_80427444[0]+velocity;
    point+=acceleration;
    if (point.squared() <= w3d_radius2_804b17d8) return 1;
    int found=0;
    for (int i=5;i;i--) {
        acceleration=w3d_acceleration_80427438[0]*(lower*lower*0.5f);
        velocity=w3d_velocity_80427414[0]*lower;
        float mid=(lower+upper)*0.5f;
        point=w3d_delta_80427444[0]+velocity;
        point+=acceleration;
        if(point.squared() <= w3d_radius2_804b17d8) {
            upper=mid;found=1;w3d_refined_804b17d4=upper;
        } else lower=mid;
    }
    return found;
}
struct W3dS1VectorSphere { W3dS1Vector position; float radius; int unknown[4]; };
extern W3dS1VectorSphere *w3d_spheres_804273ec[];
extern unsigned short w3d_hit_804aa95e;
extern int w3d_distance_804b1790;
unsigned short w3d_fn_800400f0(void);
extern unsigned short (*w3d_scan_804b17b4)(void);
W3dS1Vector *w3d_fn_800418ac(void)
{
    if (w3d_scan_804b17b4==w3d_fn_800400f0) {
        W3dS1Vector scaled=w3d_velocity_80427414[0]*(float)w3d_distance_804b1790;
        W3dS1Vector point=w3d_origin_80427408[0]+scaled;
        w3d_normal_80427450[0]=point-w3d_spheres_804273ec[0][w3d_hit_804aa95e].position;
    }
    return w3d_normal_80427450;
}
}

#endif
