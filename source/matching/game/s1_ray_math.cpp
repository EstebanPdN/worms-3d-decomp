/* Observed sphere-query setup and vertical intersection calculations. */
extern "C" {
struct W3dS1MathVec { float x,y,z; };
struct W3dS1MathSphere { W3dS1MathVec position; float radius; int reserved[4]; };
struct W3dS1MathBuffer { W3dS1MathSphere *begin,*end; };
extern W3dS1MathBuffer w3d_spheres_804273ec[];
extern W3dS1MathVec w3d_origin_80427408[];
extern unsigned short w3d_exclude_804aa950;
extern float w3d_radius_804b17b8;
extern void *w3d_context_804b17e0;
int w3d_fn_800bdb5c(void *, W3dS1MathVec *, float);
float w3d_sqrt_802e82c0(float);
void w3d_fn_80041838(unsigned int index)
{
    W3dS1MathSphere *sphere = w3d_spheres_804273ec[0].begin + index;
    w3d_origin_80427408[0] = sphere->position;
    w3d_exclude_804aa950 = index;
    w3d_radius_804b17b8 = sphere->radius;
    w3d_fn_800bdb5c(w3d_context_804b17e0, w3d_origin_80427408, sphere->radius);
}
int w3d_fn_800419cc(float height, float *result, W3dS1MathVec *origin, W3dS1MathVec *velocity, W3dS1MathVec *acceleration)
{
    struct { short unknown[11]; } frame_slot; /* Observed unused 24-byte frame reservation. */
    if (acceleration->y == 0.0f) {
        float v = velocity->y;
        if (v >= 0.0f) return 0;
        *result = (height-origin->y)/v;
        return *result > 0.0f;
    }
    float a = acceleration->y * 0.5f;
    float b = velocity->y;
    float c = origin->y-height;
    float d = b*b - (a*4.0f)*c;
    if (d < 0.0f) return 0;
    float root=w3d_sqrt_802e82c0(d);
    float negative=-b;
    float denominator=a+a;
    float plus=(negative+root)/denominator;
    float minus=(negative-root)/denominator;
    if (plus < 0.0f && minus < 0.0f) return 0;
    if (plus > 0.0f && minus > 0.0f) {
        if (plus < minus) *result=minus;
        else *result=plus;
    } else if (plus > 0.0f) *result=plus;
    else *result=minus;
    return 1;
}
}
