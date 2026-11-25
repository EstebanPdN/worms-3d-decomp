// Preparación de la IA para el equipo activo, y creación de sus registros de seguimiento.
#include "native_game.h"
#include <stdlib.h>

namespace {
struct Vector3 { float x, y, z; };
struct TeamInfo { char pad[0xd5]; uint8_t is_cpu; };
struct TrackRecord { w3d_u32 pad; w3d_u32 a, b, c; };
struct TrackHolder { w3d_u32 table; w3d_u32 pad; w3d_u32 d; Ptr32<TrackRecord> record; };
// Francotirador de UM, solo pruebas: W3D_FRANCO_IA_PREF=<n> pone PrefMagicBullet (AIParametersContainer +0x180, el
// caso 28 de 0x8021d100) en el ajuste del equipo. Sin la variable queda el del AITwk.xom: 1,0 en los 24 niveles, como
// las demás armas. La puntuación del plan se multiplica por él (0x8000b7dc): más alto, más lo elige.
void franco_ia_pref(w3d_u32 params) {
    static int leido;
    static float pref = -1.0f;
    if (!leido) {
        leido = 1;
        if (const char *e = getenv("W3D_FRANCO_IA_PREF")) pref = (float)atof(e);
    }
    if (pref >= 0.0f && params) *at<float>(params + 0x180) = pref;
}
}
extern "C" {
extern w3d_u32 A804aa6c0, A804aa6c4, A804aa6c8, A804aa6cc, A804aa6d0, A804aa6d8, A804aa6dc;
extern w3d_u32 A804aa598, A804aa59c;
extern Vector3 A8041d3a0, A8041d3ac;
extern const char A8036a588[];
w3d_u32 A800fc6dc(void *team);
w3d_u32 A800154b4(void *team);
w3d_u32 A80015588(void *team);
w3d_u32 A800154e0(void *team);
w3d_u32 A800fcb4c(void *team);
w3d_u32 A800fc230(void *key, void *out, ...);
void A80006ff4();

// 0x800152fc: copia los datos del equipo a las globales de la IA; la primera vez que el ajuste lo pide, arranca también los registros.
void A800152fc(Ptr32<void> team) {
    A804aa6c0 = team.v;
    A804aa6cc = at<TeamInfo>(A800fc6dc(team))->is_cpu;
    A804aa6d0 = A800154b4(team);
    const Vector3 goal = *at<Vector3>(A80015588(team));
    A8041d3a0 = goal;
    A8041d3ac = goal;
    A804aa6dc = A800154e0(team);
    A804aa6d8 = A800fcb4c(team);
    franco_ia_pref(A804aa6d8);
    A804aa6c8 = team.v;
    Ptr32<const char> key(A8036a588);
    w3d_u32 enabled;
    ((w3d_u32 (*)(void *, void *))A800fc230)(&key, &enabled);
    if (enabled && !A804aa598) {
        A804aa6c4 = team.v;
        A80006ff4();
        A804aa59c = 1;
    }
}

extern char A804aca40;                   // Fondo de bloques de 16 B.
extern WordVector A804200a4;             // Todos los registros creados.
extern w3d_u32 A8040de28;                // Tabla del portador.
extern Ptr32<void> A804aca48;            // Contador de registros.
w3d_u32 A802098d8(void *pool, w3d_u32 bytes);
int A80178c48(void *counter);
void A80178c54(void *counter, int *value);

// 0x80022e20: crea el registro (a, b, c) con su portador y lo deja en la referencia.
w3d_u32 A80022e20(w3d_u32 a, w3d_u32 b, w3d_u32 c, Ptr32<Ptr32<TrackHolder>> slot) {
    release_if_set(slot->get());
    *slot = (TrackHolder *)nullptr;
    const w3d_u32 record_block = A802098d8(&A804aca40, 16);
    A804200a4.push_back(record_block);
    TrackHolder *holder = at<TrackHolder>(A802098d8(&A804aca40, 16));
    holder->record.v = 0;
    holder->table = h2g(&A8040de28);
    holder->d = 0;
    add_reference(holder);
    release_if_set(slot->get());
    *slot = holder;
    holder->record.v = record_block;
    TrackRecord *record = holder->record;
    record->b = b;
    record->a = a;
    record->c = c;
    int count = A80178c48(A804aca48.get()) + 1;
    A80178c54(A804aca48.get(), &count);
    return 0;
}
}
