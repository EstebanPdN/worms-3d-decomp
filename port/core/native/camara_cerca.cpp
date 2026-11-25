// Cámara en tercera persona más cerca del worm (v25, pedido del dueño el 2026-11-05).
// Con p = w3d_cam_cerca_pct, la cámara se pone a 1/(1+p/100) de su distancia: el worm se ve un p % más grande. Solo
// cambia la cámara 3D: el HUD queda igual, y los nombres sobre los worms siguen a los worms porque se proyectan con la
// misma cámara.
// v26 (pedido del dueño): sin opción en la pantalla de abajo; en 3DS va fija al 55 % (0,645 de la distancia). En Mac
// queda como el original (0), para comparar con Dolphin. W3D_CAM=<p> (0-100, en debug.ini o en el entorno) lo cambia
// en los dos, solo para pruebas.
//
// Cámaras que se acercan: las que se enlazan con los ajustes "ShoulderCamera" (la "Default", la de mover un worm, y la
// "Jetpack_Ground") y "NinjaCamera" (cuerda ninja). Las demás (vigas, seguimiento, vuelo, vista general) no cambian.
// Cada cámara enlaza sus ajustes por nombre con A800d31d8 (settings_store.cpp), que llama aquí con el nombre y lo que
// queda en su campo +0x88. d27c (0x800d40f4, colocación de la cámara en cada cuadro) pide el factor con ese campo.
// Un valor que se enlaza después con otro nombre sale de la lista, por si la memoria de una cámara vieja se reutiliza.
#include <stdlib.h>
#include <string.h>

typedef unsigned int w3d_cam_u32;
extern "C" void w3d_dbg(const char *, ...);
// v39 (el dueño, 2026-11-10, con la v38 en la consola): «por defecto que esté un 15 % más lejos de lo que está ahora».
// Con el 55 % la cámara iba a 0,645 de la distancia original; un 15 % más lejos es 0,742, que es el 35 %.
#if defined(__3DS__)
const int kCamDefecto = 35;
#else
const int kCamDefecto = 0;
#endif
extern "C" { volatile int w3d_cam_cerca_pct = kCamDefecto; }

namespace {
w3d_cam_u32 g_props[8];
int g_count;
bool g_init;
void init() {
    if (g_init) return;
    g_init = true;
    if (const char *e = getenv("W3D_CAM")) {
        int v = atoi(e);
        w3d_cam_cerca_pct = v <= 0 ? 0 : v >= 100 ? 100 : v;
        w3d_dbg("[camara] W3D_CAM: %d %%\n", w3d_cam_cerca_pct);
    }
}
}

extern "C" {
int w3d_cam_cerca_get(void) { init(); return w3d_cam_cerca_pct; }
void w3d_cam_cerca_enlace(const char *name, w3d_cam_u32 props) {
    init();
    bool want = name && (!strcmp(name, "ShoulderCamera") || !strcmp(name, "NinjaCamera"));
    for (int i = 0; i < g_count; i++) {
        if (g_props[i] != props) continue;
        if (!want) g_props[i] = g_props[--g_count];
        return;
    }
    if (want && props && g_count < 8) {
        g_props[g_count++] = props;
        w3d_dbg("[camara] %s: se acerca un %d %%\n", name, w3d_cam_cerca_pct);
    }
}
float w3d_cam_cerca(w3d_cam_u32 props) {
    int p = w3d_cam_cerca_pct;
    if (p <= 0 || !props) return 1.0f;
    for (int i = 0; i < g_count; i++)
        if (g_props[i] == props) return 1.0f / (1.0f + (float)p / 100.0f);
    return 1.0f;
}
}
