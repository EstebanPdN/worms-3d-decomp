#include "w3d_ptr.h"
#line 1 "k5a_bomber_ground_velocity_8002f2d8.cpp"
struct K5aVec3 { float x, y, z; };
extern "C" char w3d_string_80372d2c[];
extern "C" int w3d_auto_800fc270(Ptr32<Ptr32<const char>> name, Ptr32<float> value);

extern "C" Ptr32<K5aVec3> k5a_bomber_ground_velocity_8002f2d8(Ptr32<K5aVec3> result, Ptr32<const K5aVec3> direction)
{
    Ptr32<const char> name = w3d_string_80372d2c;
    float speed;
    K5aVec3 tmp;
    w3d_auto_800fc270(&name, &speed);
    tmp.x = direction->x * speed;
    tmp.y = direction->y * speed;
    tmp.z = direction->z * speed;
    result->x = tmp.x; result->y = tmp.y; result->z = tmp.z;
    return result;
}


