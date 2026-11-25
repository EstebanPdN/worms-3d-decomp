// Lo que cada plataforma pone para la UI de dos pantallas (platform/ui): 3DS en platform/3ds/ui_backend_3ds.cpp (PICA
// con gx_pica.cpp) y Mac en platform/gx/gx_metal.mm (Metal, W3D_DUAL=1).
#pragma once
#include <stdint.h>

extern "C" {
// Textura desde RGBA8 (filas de arriba abajo). fmt: 0 RGBA8, 1 RGBA4, 2 RGB565 (en Mac todo es RGBA8); + 8: con
// mipmaps (Mac). Devuelve el
// número de textura o -1; pw/ph: tamaño potencia de dos. En 3DS, fuera de un cuadro (w3d_ui_after_frame).
int uib_tex_create(const uint8_t *rgba, unsigned w, unsigned h, int fmt, unsigned *pw, unsigned *ph);
void uib_tex_free(int id);
void uib_tex_gc(void);
// Dibujo, solo dentro de w3d_ui_frame: pantalla 0 arriba (400x240, encima de la imagen del juego) o 1 abajo (320x240).
// Cuadriláteros: 16 floats cada uno (x, y, u, v de las esquinas arriba-izq, arriba-der, abajo-der, abajo-izq; u y v de
// la imagen con v hacia abajo) y un color por cuadrilátero (bytes r, g, b, a). tex < 0: color liso.
void uib_begin(int screen);
void uib_quads(int tex, const float *v, const uint32_t *rgba, int nquads);
// Triángulos sueltos: x, y, u, v por vértice y un color por vértice (bytes r, g, b, a); nverts múltiplo de 3.
void uib_tris(int tex, const float *v, const uint32_t *rgba, int nverts);
void uib_end(void);
void uib_blend(int mode);          // 0 normal (alfa), 1 máximo por canal (rellenar lo negro sin tapar lo que hay)
double uib_seconds(void);
int uib_console_lang(void);          // 0 inglés, 1 francés, 2 alemán, 3 italiano, 4 español
int uib_console_busy(void);          // la consola de desarrollador o un volcado tienen la pantalla de abajo
int uib_dev_get(int which);          // 0 overlay, 1 volcado con SELECT
void uib_dev_set(int which, int v);
int uib_test_running(void);          // prueba automática de 3DS
int uib_read_own(const char *name, unsigned char **data, long *size);   // arte propio (malloc; uib_free)
void uib_free(void *p);
void uib_log(const char *fmt, ...) __attribute__((format(printf, 1, 2)));
}
