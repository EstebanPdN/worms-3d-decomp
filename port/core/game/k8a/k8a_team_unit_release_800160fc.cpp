#include "w3d_ptr.h"
#line 1 "k8a_team_unit_release_800160fc.cpp"
// Appears to release the current team unit: when the unit's team index is valid and its
// stored position still equals the team's position, the unit is pushed back to storage;
// the unit is then destroyed if it was not and the global pointer is cleared.
struct K8aWords3 { int a, b, c; };
struct K8aUnit
{
    char pad0[16];
    int team;                // +16
    K8aWords3 position;      // +20
    int signature;           // +32
};
extern Ptr32<K8aUnit> w3d_unit_804aa6f4;
extern "C" int w3d_auto_800155ac(int team);
extern "C" Ptr32<K8aWords3> w3d_auto_80015588(int team);
extern "C" void w3d_cx9a_storage_push_global_8001634c(Ptr32<K8aUnit> unit);
extern "C" void w3d_auto_80015d18(Ptr32<K8aUnit> unit, int flags);
extern "C" void w3d_unit_finish_800161d8(void);
static inline int k8a_same(Ptr32<const K8aWords3> left, Ptr32<const K8aWords3> right)
{
    return left->a == right->a && left->b == right->b && left->c == right->c;
}
extern "C" void w3d_k8a_team_unit_release_800160fc(void)
{
    if (w3d_unit_804aa6f4)
    {
        int team = w3d_unit_804aa6f4->team;
        int destroy = 1;
        if (team != -1 && w3d_auto_800155ac(team) == w3d_unit_804aa6f4->signature
            && k8a_same(&w3d_unit_804aa6f4->position, w3d_auto_80015588(team)))
        {
            destroy = 0;
            w3d_cx9a_storage_push_global_8001634c(w3d_unit_804aa6f4);
        }
        if (destroy && w3d_unit_804aa6f4)
            w3d_auto_80015d18(w3d_unit_804aa6f4, 3);
        w3d_unit_804aa6f4 = 0;
        w3d_unit_finish_800161d8();
    }
}


