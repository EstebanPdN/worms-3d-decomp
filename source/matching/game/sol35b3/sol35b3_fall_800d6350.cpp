// Inferred native GC32 layouts and names. Named multiplication result and
// explicit float copy construction preserve genuine aggregate return lifetimes.
// The step is loaded into a real scalar before evaluating the velocity operand.
// External bounds/removal operations and object ownership remain separate.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3 &v) { float a=v.x,b=v.y,c=v.z; x=a;y=b;z=c; }
    void assign(float a,float b,float c) {x=a;y=b;z=c;}
    Vec3 operator*(float s) const {
        Vec3 result; result.x=x*s; result.y=y*s; result.z=z*s; return result;
    }
    void operator+=(const Vec3 &v) { x+=v.x; y+=v.y; z+=v.z; }
};
struct Falling {
    char unknown0[28];
    Vec3 position, velocity;
};
extern const float sol35b3_zero_80388e68[];
extern const float sol35b3_down_80388e6c[];
extern const float sol35b3_step_80388e70[];
extern const float sol35b3_limit_80388e74[];
extern "C" void sol35b3_bounds_800d60ac(Falling *);
extern "C" void sol35b3_remove_8015fd1c(Falling *);
extern "C" void sol35b3_fall_800d6350(Falling *s) {
    s->velocity.assign(sol35b3_zero_80388e68[0], sol35b3_down_80388e6c[0], sol35b3_zero_80388e68[0]);
    float step = sol35b3_step_80388e70[0];
    Vec3 delta = s->velocity * step;
    s->position += delta;
    sol35b3_bounds_800d60ac(s);
    if (s->position.y < sol35b3_limit_80388e74[0])
        sol35b3_remove_8015fd1c(s);
}
