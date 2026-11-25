extern float fn_802e86d4(float angle);
extern float fn_802e88ac(float angle);
void w3d_k5b_matrix3_axis_angle_801f6480(float m[3][3], float x, float y, float z, float angle)
{
    float s = fn_802e88ac(angle);
    float c = fn_802e86d4(angle);
    float t = 1.0f - c;
    m[0][0] = t * x * x + c;
    m[0][1] = t * x * y + s * z;
    m[0][2] = t * x * z - s * y;
    m[1][0] = t * x * y - s * z;
    m[1][1] = t * y * y + c;
    m[1][2] = t * y * z + s * x;
    m[2][0] = t * x * z + s * y;
    m[2][1] = t * y * z - s * x;
    m[2][2] = t * z * z + c;
}
// desc: w3d_k5b_matrix3_axis_angle_801f6480: Appears to build a 3x3 rotation matrix from a unit axis and an angle (sine 0x802e88ac, cosine 0x802e86d4).
