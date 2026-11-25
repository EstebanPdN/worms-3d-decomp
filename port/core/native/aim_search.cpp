// Busca un tiro de la IA contra un blanco: prueba velocidades o tiempos de vuelo, descarta los que chocan y guarda el que cae más cerca.
#include "native_common.h"

namespace {
struct Vector3 { float x, y, z; };
struct AimSolver {
    char pad[0xc];
    Vector3 launch;          // +0xc
    char pad2[0x98 - 0x18];
    Vector3 high_launch;     // +0x98
    char pad3[0xb0 - 0xa4];
    float time, high_time;   // +0xb0
    char pad4[0xd0 - 0xb8];
    Vector3 chosen;          // +0xd0
    Vector3 landing;         // +0xdc
};
inline float distance_squared(const Vector3 &a, const Vector3 &b) {
    const float dy = (float)(a.y - b.y), dx = (float)(a.x - b.x), dz = (float)(a.z - b.z);
    return fused_madd(dz, dz, fused_madd(dx, dx, (float)(dy * dy)));
}
}
extern "C" {
extern AimSolver A8041e780;
extern const Vector3 A8045e788;
extern float A804b1768, A804b1770, A804b1774, A804b1778;
extern const float A8036afc0, A8036afc4, A8036afc8, A8036afcc, A8036afd0, A8036afd4, A8036afd8, A8036afdc, A8036afe0;
void A801182c0(AimSolver *solver, const Vector3 *target);
w3d_u32 A801182ec(AimSolver *solver, float speed);
w3d_u32 A801188c4(AimSolver *solver, float time);
w3d_u32 A8001b830(Vector3 *launch, float time);
w3d_u32 A80118268(AimSolver *solver, const Vector3 *launch);
void A800d75f0(AimSolver *solver, Vector3 *landing, float time);
float A802e82c0(float value);

static void keep_nearest(const Vector3 &launch, const Vector3 &landing, float squared) {
    A804b1778 = A802e82c0(squared);
    A8041e780.chosen = launch;
    A8041e780.landing = landing;
}
// 0x8001aaf8: por velocidad, entre dos fracciones del rango de velocidades.
w3d_u32 A8001aaf8(Ptr32<const Vector3> target, float from, float to) {
    A801182c0(&A8041e780, target.get());
    const float range = (float)(A804b1770 - A804b1774);
    const float last = fused_madd(range, to, A804b1774);
    float first = fused_madd(range, from, A804b1774);
    float step = (float)((float)(last - first) / A8036afc0);
    if (step == A8036afc4) {
        step = A8036afc8;
        first = (float)(first - step);
    }
    A8041e780.chosen = A8045e788;
    const Vector3 zero = {A8036afc4, A8036afc4, A8036afc4};
    Vector3 landings[2] = {zero, zero}, launches[2] = {zero, zero};
    Vector3 best_launch = {}, best_landing = {};
    float best = A8036afcc;
    const float limit = (float)(last + A8036afd0);
    for (float speed = (float)(first + step); speed <= limit; speed = (float)(speed + step)) {
        if (A801182ec(&A8041e780, speed)) {
            if (A8001b830(&A8041e780.high_launch, A8041e780.high_time)) {
                A8041e780.chosen = A8041e780.high_launch;
                return 1;
            }
            landings[0] = A8041e780.landing;
            launches[0] = A8041e780.high_launch;
            if (A8001b830(&A8041e780.launch, A8041e780.time)) {
                A8041e780.chosen = A8041e780.launch;
                return 1;
            }
            landings[1] = A8041e780.landing;
            launches[1] = A8041e780.launch;
        }
        for (int i = 0; i < 2; i++) {
            const float squared = distance_squared(*target, landings[i]);
            if (squared < best) {
                best = squared;
                best_launch = launches[i];
                best_landing = landings[i];
            }
        }
    }
    keep_nearest(best_launch, best_landing, best);
    return 0;
}
// 0x8001ae30: por tiempo de vuelo. Si hace falta más velocidad de la máxima, se limita y ese tiro ya no vale como solución limpia.
w3d_u32 A8001ae30(Ptr32<const Vector3> target) {
    A801182c0(&A8041e780, target.get());
    const float step = A8036afd8;
    const float max_squared = (float)(A804b1770 * A804b1770);
    A804b1768 = step;
    float best = A8036afd4;
    Vector3 best_launch = {}, best_landing = {};
    do {
        const float time = (float)(A804b1768 * A8036afe0);
        if (A801188c4(&A8041e780, time)) {
            bool clipped = false;
            const Vector3 launch = A8041e780.launch;
            const float length_squared = fused_madd(launch.z, launch.z, fused_madd(launch.x, launch.x, (float)(launch.y * launch.y)));
            if (length_squared > max_squared) {
                clipped = true;
                const float scale = (float)(step / A802e82c0(length_squared));
                const Vector3 limited = {(float)((float)(launch.x * scale) * A804b1770), (float)((float)(launch.y * scale) * A804b1770), (float)((float)(launch.z * scale) * A804b1770)};
                A80118268(&A8041e780, &limited);
                A800d75f0(&A8041e780, &A8041e780.landing, time);
            }
            if (A8001b830(&A8041e780.launch, time) && !clipped) {
                A8041e780.chosen = A8041e780.launch;
                return 1;
            }
            const float squared = distance_squared(*target, A8041e780.landing);
            if (squared < best) {
                best = squared;
                best_launch = A8041e780.launch;
                best_landing = A8041e780.landing;
            }
        }
        A804b1768 = (float)(A804b1768 + step);
    } while (A804b1768 <= A8036afdc);
    keep_nearest(best_launch, best_landing, best);
    return 0;
}
}
