// (Worms 3D GameCube PAL, 0x801a3eb0).
//
// Builds a 3x3 rotation matrix from Euler angles for one of six rotation
// orders; sine and cosine pairs come from 0x801f3db0, and orders outside
// 0..5 leave the matrix untouched. Row 0 is written directly, rows 1 and 2
// through row references. Case 4's first row uses cy*sx where a textbook
// matrix has cy*sz: this is in the original and kept. Order names are not
// known.

extern "C" void w3d_d24e_sin_cos_801f3db0(float angle, float *outSin, float *outCos);
struct Row { float x, y, z; };
struct Mat { Row r[3]; };
struct Euler { float x, y, z; };
extern "C" void w3d_d26e_euler_matrix_801a3eb0(const Euler *e, int order, Mat *m) {
    float sx, cx, sy, cy, sz, cz;
    w3d_d24e_sin_cos_801f3db0(e->x, &sx, &cx);
    w3d_d24e_sin_cos_801f3db0(e->y, &sy, &cy);
    w3d_d24e_sin_cos_801f3db0(e->z, &sz, &cz);
    switch (order) {
    case 0:
        m->r[0].x = cz * cy; m->r[0].y = cy * sz; m->r[0].z = -sy;
        { Row &r = m->r[1]; r.x = sx * sy * cz - cx * sz; r.y = sx * sy * sz + cx * cz; r.z = sx * cy; }
        { Row &r = m->r[2]; r.x = cx * sy * cz + sx * sz; r.y = cx * sy * sz - sx * cz; r.z = cx * cy; }
        break;
    case 3:
        m->r[0].x = cz * cy; m->r[0].y = sz; m->r[0].z = -cz * sy;
        { Row &r = m->r[1]; r.x = -cx * sz * cy + sx * sy; r.y = cx * cz; r.z = cx * sy * sz + sx * cy; }
        { Row &r = m->r[2]; r.x = sx * sz * cy + cx * sy; r.y = -sx * cz; r.z = -sx * sy * sz + cx * cy; }
        break;
    case 1:
        m->r[0].x = cz * cy; m->r[0].y = cx * sz * cy + sx * sy; m->r[0].z = sx * sz * cy - cx * sy;
        { Row &r = m->r[1]; r.x = -sz; r.y = cx * cz; r.z = sx * cz; }
        { Row &r = m->r[2]; r.x = cz * sy; r.y = cx * sy * sz - sx * cy; r.z = sx * sy * sz + cx * cy; }
        break;
    case 4:
        m->r[0].x = cx * cy - sx * sy * sz; m->r[0].y = sx * sy * cz + cy * sx; m->r[0].z = -cx * sy;
        { Row &r = m->r[1]; r.x = -cx * sz; r.y = cx * cz; r.z = sx; }
        { Row &r = m->r[2]; r.x = cz * sy + sx * sz * cy; r.y = sy * sz - cy * sx * cz; r.z = cx * cy; }
        break;
    case 2:
        m->r[0].x = cz * cy + sx * sy * sz; m->r[0].y = cx * sz; m->r[0].z = -cz * sy + sx * sz * cy;
        { Row &r = m->r[1]; r.x = -cy * sz + sx * sy * cz; r.y = cx * cz; r.z = sy * sz + sx * cy * cz; }
        { Row &r = m->r[2]; r.x = cx * sy; r.y = -sx; r.z = cx * cy; }
        break;
    case 5:
        m->r[0].x = cz * cy; m->r[0].y = cx * sz + sx * sy * cz; m->r[0].z = sx * sz - cx * sy * cz;
        { Row &r = m->r[1]; r.x = -cy * sz; r.y = cx * cz - sx * sy * sz; r.z = sx * cz + cx * sy * sz; }
        { Row &r = m->r[2]; r.x = sy; r.y = -sx * cy; r.z = cx * cy; }
        break;
    }
}
