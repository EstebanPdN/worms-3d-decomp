struct K5aVec3 { float x, y, z; };
extern "C" char w3d_string_80372d2c[];
extern "C" int w3d_auto_800fc270(const char **name, float *value);

extern "C" K5aVec3 *k5a_bomber_ground_velocity_8002f2d8(K5aVec3 *result, const K5aVec3 *direction)
{
    const char *name = w3d_string_80372d2c;
    float speed;
    K5aVec3 tmp;
    w3d_auto_800fc270(&name, &speed);
    tmp.x = direction->x * speed;
    tmp.y = direction->y * speed;
    tmp.z = direction->z * speed;
    result->x = tmp.x; result->y = tmp.y; result->z = tmp.z;
    return result;
}
