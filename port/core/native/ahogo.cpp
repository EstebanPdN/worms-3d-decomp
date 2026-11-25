// Ahogo de los worms (v26, pedido del dueño el 2026-11-05; investigación en docs/ahogo-ultimate-mayhem.md, sección "v26").
// - Ahogo de Worms Ultimate Mayhem (UM), activado al arrancar: todo worm que cae al agua toma el estado 27 de W3D y hace
//   la física de UM. Salpica, se hunde, frena, sube a Water.Level − 8, se balancea 2 s y explota. No deja lápida.
//   - Entrada (d29d_worm_drown_80149f18, como CheckDrown 0x5AD640): si caminaba o resbalaba, v = (v.x·0,5, −0,03, v.z·0,5);
//     si caía, la misma velocidad.
//   - Cada tic de 20 ms (d41d_worm_sim_update_80144904, caso 27): w3d_ahogo_um_tic, copia de UpdateDrownFloat 0x5AA130
//     con sus ayudas 0x5A59F0 y 0x569FA0. Mismas operaciones en float y en el mismo orden que el original.
//   - Al explotar: d24d_worm_death_8014cb88 pone EffectWaterExplosion en la superficie y EffectWormExplosion subido
//     sobre el agua, como WXP_WormDrownPopSplash y WXP_Explosion_Small en 0x5A9400, y no pone la lápida.
//   - Mientras flota, nada lo saca de ahí, como en UM: el empujón de una explosión se deshace (w3d_ahogo_um_restaurar,
//     desde d41d) y Worm.TimeToDie no lo pone a morir (d24d_worm_dying_8015115c).
// - v27 (pedido del dueño): activado, cada ahogo tira al azar; el 50 % de las veces flota como en UM y el otro 50 % se
//   hunde como en W3D (estado 19, al 35 %), también en agua poco profunda. W3D_AHOGO_UM_PCT=<0-100> cambia el reparto.
//   La tirada mezcla el tiempo del juego y el número del worm: no gasta el generador del juego.
// - v28 (pedido del dueño): el ahogo de UM siempre, sin botón en la pantalla de abajo. El reparto por defecto pasa a
//   100 %; W3D_AHOGO_UM_PCT y W3D_AHOGO siguen sirviendo para las pruebas.
// - Desactivado: el ahogo de W3D. Con suelo a menos de 100 unidades, el estado 27 original: quieto bajo el agua y explota
//   a los 4 s. En agua honda, el estado 19: se hunde al 35 % de su velocidad (W3D_HUNDIR) y desaparece a 1 s.
// - La elección se lee en cada ahogo. La pantalla de abajo de 3DS la cambia con w3d_ahogo_um_set. W3D_AHOGO=0|1 en el
//   entorno o en debug.ini fija el valor al arrancar. Un worm que ya flota sigue como entró.
// - Hundirse: la animación SinkWater (d31d, estado gráfico 13) y la bajada del estado 19 (f1b, 0x80146aa4) van al 35 % de
//   su velocidad. El worm se sigue retirando a los 1000 ms. W3D_HUNDIR=<1-100> cambia el porcentaje (100 = original).
// - Pruebas: W3D_PRUEBA_AHOGO=<segundos> en debug.ini. Pasados esos segundos de juego, d29d lleva una vez al worm que juega
//   el turno 60 unidades por encima del agua honda abierta más cercana, cae solo y la cámara lo sigue.
//   W3D_PRUEBA_AHOGO_CADA=<segundos> lo repite. W3D_PRUEBA_AHOGO_SOMERO=1 busca agua poco profunda (suelo a menos de
//   108 unidades bajo la superficie). W3D_PRUEBA_AHOGO_ALTURA=<h> y W3D_PRUEBA_AHOGO_VX=<v> cambian la altura de la caída
//   (60) y la velocidad en x (0); con h < −7 el worm queda de pie en el agua y entra como si caminara.
// Para 3DS (ARM de 32 bits): solo enteros, float y punteros como argumentos, ninguna estructura por valor.
#include <math.h>
#include <stdlib.h>

extern "C" void w3d_dbg(const char *, ...);

namespace {
int env_int(const char *name, int def, int lo, int hi) {
    const char *e = getenv(name);
    if (!e || !*e) return def;
    int v = atoi(e);
    return v < lo ? lo : v > hi ? hi : v;
}
bool g_init;
int g_um = 1, g_hundir = 35, g_mezcla = 100;
float g_k = 1.0f, g_freno = 0.98f, g_suave = 0.5f;
int g_prueba_ms = -1, g_prueba_cada_ms, g_prueba_somero;
float g_prueba_altura = 60.0f, g_prueba_vx;
// Un worm por número (0-15, el +584 del worm). activo: entró al agua con el ahogo de UM. temporizador: el +0x128 de UM.
// v: su velocidad al final del último tic, para deshacer un empujón (w3d_ahogo_um_restaurar).
struct Flota { int activo, temporizador; float v[3]; };
Flota g_flota[16];
void init() {
    if (g_init) return;
    g_init = true;
    g_um = env_int("W3D_AHOGO", 1, 0, 1);
    g_mezcla = env_int("W3D_AHOGO_UM_PCT", 100, 0, 100);
    g_hundir = env_int("W3D_HUNDIR", 35, 1, 100);
    g_k = g_hundir / 100.0f;
    // f1b frena la caída x0,98 por tic de 20 ms y acerca la velocidad a -0,02 con un factor 0,5 por tic. Con el tiempo
    // a k, lo que pasa en un tic es 0,98^k y 1 - 0,5^k; con k = 1 queda el original.
    g_freno = powf(0.98f, g_k);
    g_suave = 1.0f - powf(0.5f, g_k);
    if (const char *e = getenv("W3D_PRUEBA_AHOGO")) g_prueba_ms = atoi(e) * 1000;
    if (const char *e = getenv("W3D_PRUEBA_AHOGO_CADA")) g_prueba_cada_ms = atoi(e) * 1000;
    g_prueba_somero = env_int("W3D_PRUEBA_AHOGO_SOMERO", 0, 0, 1);
    if (const char *e = getenv("W3D_PRUEBA_AHOGO_ALTURA")) g_prueba_altura = (float)atof(e);
    if (const char *e = getenv("W3D_PRUEBA_AHOGO_VX")) g_prueba_vx = (float)atof(e);
    w3d_dbg("[ahogo] ahogo de UM %s (%d %% de los ahogos), hundirse al %d %%%s\n", g_um ? "activado" : "desactivado", g_mezcla, g_hundir,
            g_prueba_ms >= 0 ? (g_prueba_somero ? " (prueba de ahogo en agua poco profunda)" : " (prueba de ahogo)") : "");
}
Flota *flota(int worm) { return (unsigned)worm < 16u ? &g_flota[worm] : 0; }

// 0x5A59F0: v = (t + k·v)·(1/(k+1)). Una operación por línea: así se redondea igual que el original.
void frenar(float *v, float tx, float ty, float tz, float k) {
    float ax = v[0] * k, ay = v[1] * k, az = v[2] * k;
    float sx = tx + ax, sy = ty + ay, sz = tz + az;
    float k1 = k + 1.0f;
    float inv = 1.0f / k1;
    v[0] = inv * sx;
    v[1] = inv * sy;
    v[2] = inv * sz;
}
// 0x569FA0: lo mismo, pero si el cambio de v mide más que tope, se recorta a tope.
void acercar(float *v, float tx, float ty, float tz, float k, float tope) {
    float ax = v[0] * k, ay = v[1] * k, az = v[2] * k;
    float sx = tx + ax, sy = ay + ty, sz = tz + az;
    float k1 = k + 1.0f;
    float inv = 1.0f / k1;
    float nx = inv * sx, ny = sy * inv, nz = inv * sz;
    float dx = nx - v[0], dy = ny - v[1], dz = nz - v[2];
    float xx = dx * dx, yy = dy * dy, zz = dz * dz;
    float s2 = xx + yy;
    s2 = s2 + zz;
    float len = __builtin_sqrtf(s2);
    if (!(tope < len)) {
        v[0] = nx;
        v[1] = ny;
        v[2] = nz;
        return;
    }
    float f = tope / len;
    float px = dx * f, py = dy * f, pz = dz * f;
    v[0] = px + v[0];
    v[1] = py + v[1];
    v[2] = pz + v[2];
}
}

extern "C" {
// Interruptor de la pantalla de abajo (3DS) y de W3D_AHOGO.
int w3d_ahogo_um_get(void) { init(); return g_um; }
void w3d_ahogo_um_set(int on) {
    init();
    g_um = on ? 1 : 0;
    w3d_dbg("[ahogo] ahogo de UM %s\n", g_um ? "activado" : "desactivado");
}

// d29d, en cada ahogo (ms: tiempo del juego). 1 si este worm hace el ahogo de UM, que se apunta para el resto de su
// ahogo; 2 si se hunde (estado 19) aunque el agua sea poco profunda; 0 el ahogo de W3D (interruptor desactivado).
int w3d_ahogo_um_entrar(int worm, int hondo, unsigned ms) {
    init();
    Flota *f = flota(worm);
    int modo = 0;
    if (g_um && f) {
        unsigned h = ms * 2654435761u ^ (unsigned)(worm + 1) * 40503u;
        h ^= h >> 15; h *= 2246822519u; h ^= h >> 13; h *= 3266489917u; h ^= h >> 16;
        modo = (int)(h % 100u) < g_mezcla ? 1 : 2;
    }
    if (f) { f->activo = modo == 1; f->temporizador = 0; }
    w3d_dbg("[ahogo] worm %d al agua (%s): %s\n", worm, hondo ? "honda" : "poco profunda",
            modo == 1 ? "flota como en UM" : modo == 2 || hondo ? "se hunde" : "ahogo de W3D en agua poco profunda");
    return modo;
}
// 1 mientras el worm hace el ahogo de UM (de la entrada a la explosión).
int w3d_ahogo_um_flotando(int worm) {
    Flota *f = flota(worm);
    return f && f->activo;
}
// d24d, al explotar.
void w3d_ahogo_um_fin(int worm) {
    if (Flota *f = flota(worm)) f->activo = 0;
}

// UM no deja que nada cambie el estado de un worm que flota: ImpulseWorm (0x5AD010) no lo empuja (0x5AD203) y
// StartDying (0x5ADBF0) no lo pone a morir. En W3D, el empujón de una explosión (0x80148c14) le cambia el modo y la
// velocidad. d41d llama a esto si un worm que flota ya no está en el modo 27: le devuelve su velocidad y sigue flotando.
int w3d_ahogo_um_restaurar(int worm, int modo, float *vel) {
    Flota *f = flota(worm);
    if (!f || !f->activo) return 0;
    vel[0] = f->v[0];
    vel[1] = f->v[1];
    vel[2] = f->v[2];
    w3d_dbg("[ahogo] worm %d flota como en UM: se ignora el cambio al modo %d\n", worm, modo);
    return 1;
}

// Un tic de UpdateDrownFloat (0x5AA130). pos y vel son el +560 y el +676 del worm; agua, Water.Level.
// mover = 0 en el tic de la entrada: UM no mueve al worm hasta el tic siguiente; solo se guarda la velocidad.
// Devuelve 1 si el worm explota en este tic: entonces no se mueve, como en UM (la explosión usa la posición de antes).
int w3d_ahogo_um_tic(int worm, float *pos, float *vel, float agua, int mover) {
    Flota *f = flota(worm);
    if (!f) return 0;
    if (!mover) {
        f->v[0] = vel[0]; f->v[1] = vel[1]; f->v[2] = vel[2];
        return 0;
    }
    float L = agua - 8.0f;
    if (f->temporizador == 0) {
        if (!(pos[1] < L)) {
            if (vel[1] >= 0.0f) f->temporizador = 2000;            // asentado: empieza la cuenta de 2 s
        } else if (!(vel[1] < 0.0f)) {
            acercar(vel, 0.0f, 0.03f, 0.0f, 12.0f, 0.001f);       // sube hacia 0,03 por ms
        } else {
            frenar(vel, 0.0f, 0.03f, 0.0f, 6.0f);                  // frena la caída
        }
    } else {
        float d = pos[1] - L;                                      // balanceo: muelle amortiguado hacia L
        float m = d * 0.001f;
        float a = vel[1] - m;
        vel[1] = a * 0.95f;
    }
    if (f->temporizador > 0) {
        f->temporizador -= 20;
        if (f->temporizador <= 0) return 1;                        // explota: d41d sigue con la retirada
    }
    float mx = vel[0] * 20.0f, my = vel[1] * 20.0f, mz = vel[2] * 20.0f;
    pos[0] = pos[0] + mx;
    pos[1] = pos[1] + my;
    pos[2] = pos[2] + mz;
    f->v[0] = vel[0]; f->v[1] = vel[1]; f->v[2] = vel[2];
    return 0;
}

float w3d_hundir_velocidad(void) { init(); return g_k; }
float w3d_hundir_freno(void) { init(); return g_freno; }
float w3d_hundir_suave(void) { init(); return g_suave; }

// Prueba: 1 cuando toca llevar al worm del turno sobre el agua (una vez, o cada W3D_PRUEBA_AHOGO_CADA).
int w3d_prueba_ahogo_toca(int now) {
    init();
    if (g_prueba_ms < 0 || now < g_prueba_ms) return 0;
    g_prueba_ms = g_prueba_cada_ms > 0 ? now + g_prueba_cada_ms : 0x7fffffff;
    return 1;
}
int w3d_prueba_ahogo_somero(void) { init(); return g_prueba_somero; }
// Altura sobre el agua a la que se deja al worm (60 por defecto) y su velocidad en x. Bajo agua − 7 (por ejemplo −7,1)
// el worm queda de pie (kStatic) y se ahoga en el acto, como uno que entra caminando.
float w3d_prueba_ahogo_altura(void) { init(); return g_prueba_altura; }
float w3d_prueba_ahogo_vx(void) { init(); return g_prueba_vx; }
void w3d_prueba_ahogo_log(int worm, float x, float y, float z, int found) {
    const char *agua = g_prueba_somero ? "agua poco profunda" : "agua honda";
    if (found) w3d_dbg("[ahogo] prueba: worm %d llevado sobre %s en (%.0f, %.0f, %.0f)\n", worm, agua, x, y, z);
    else w3d_dbg("[ahogo] prueba: worm %d sin %s cerca\n", worm, agua);
}
}

// W3D_LOG_TILT=1: registro de la inclinación del worm al ahogarse (d31d_worm_graphic_state_80135c20). Las unidades del
// juego no pueden leer el entorno de la plataforma (su getenv es el de la libc del juego).
extern "C" int w3d_ahogo_log_tilt(void) { static const int on = getenv("W3D_LOG_TILT") != nullptr; return on; }
