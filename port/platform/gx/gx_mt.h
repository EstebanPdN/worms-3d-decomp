// v36: GX en otro núcleo (New 3DS). El hilo del juego graba las órdenes de GX en una cola y un hilo en otro núcleo
// las ejecuta: decodificación de vértices, cachés de listas y texturas, traducción a PICA y envío a la GPU.
//
// Es el modelo para el que está escrito el juego: en GameCube el procesador gráfico lee las listas, los arrays de vértices,
// las texturas y las paletas de forma asíncrona, después de que la CPU deje la orden en la FIFO. Lo que GX copia en la
// FIFO (matrices, luces, GXTexObj, vértices inmediatos, colores) se copia aquí al grabar; lo que el procesador gráfico
// lee de la memoria del juego (listas, arrays, imágenes, paletas) lo lee el otro hilo al ejecutar. Las marcas de
// DCFlushRange/DCInvalidateRange van en la misma cola, en su orden.
//
// Dos estados de GX: `g` (gx_internal.h) es el del hilo que ejecuta, el que lee el backend; `*mt::front` es el que
// escribe el hilo del juego (sdk_gx.cpp). Con la cola apagada son el mismo objeto y todo va como hasta la v35.
// La cola solo está activa en partida (modo 7) y cambia al final de un cuadro, con la cola vacía: los menús a dos
// pantallas, las películas y el arranque siguen en un solo hilo. Al final de cada cuadro (GXCopyDisp) el hilo del juego
// espera a que la cola quede vacía y cierra el cuadro él mismo (UI y C3D_FrameEnd).
//
// v38: la cola publica con barreras de memoria (dmb en gx_mt.cpp). Sin ellas se colgó en la consola en la primera partida.
//
// debug.ini: W3D_GX_MT=0 la quita; W3D_GX_CORE=<n> elige el núcleo (por defecto prueba el 3 y, si no vale, el 2).
#ifndef W3D_GX_MT_H
#define W3D_GX_MT_H
#include "gx_internal.h"

namespace w3d {
namespace gx {
namespace mt {

#if defined(__3DS__)
extern State *front;   // estado que escribe el hilo del juego
extern bool on;        // cola activa en este cuadro (lo lee y lo cambia solo el hilo del juego)

// Hilo del juego: graba. kind: 0 sin más, 1 touch(), 2 touch_keep() antes de copiar. n = 0: solo el touch.
void patch(const void *field, u32 n, int kind);
void prim(u32 prim, u32 fmt, u32 count, const u8 *data, u32 n);   // primitiva inmediata completa
// v37: malla por índices. stream = nullptr: solo la identidad (el otro hilo ya la tiene residente).
void mesh(u32 prim, u32 fmt, u32 count, u32 key, const MeshSrc &s, const u8 *stream, u32 bytes);
void exec_mesh(u32 prim, u32 fmt, u32 count, u32 key, const MeshSrc *s, const u8 *stream, u32 bytes);
void call(u32 guest, u32 size);                                    // GXCallDisplayList
void tlut(const GTlutObj &o, u32 name);                            // GXLoadTlut
void epoch();                                                      // GXInvalidateTexAll
void flush();                                                      // flush_batch
void mark(u32 a, u32 n);                                           // DCFlushRange / DCInvalidateRange
void drain();                                                      // espera a que la cola quede vacía
void drain_if_owner();                                             // v38: lo mismo, solo desde el hilo del juego y con la cola activa
void frame_end();                                                  // fin de copy_display: estadísticas y cambio de modo

// Hilo que ejecuta (gx_state.cpp).
void exec_prim(u32 prim, u32 fmt, u32 count, const u8 *data, u32 n);
void exec_call(u32 guest, u32 size);
// Lo que el dibujo necesita saber del juego, tomado al grabar cada dibujo (gx_pica.cpp lo lee con ctx_*).
extern bool ctx_live;
extern u32 ctx_word;   // bit 0 cámara de pantalla del HUD, bit 1 panel de armas abierto, 8-15 popups, 16-23 filas, 24-31 modo
#else
// Mac: sin cola.
static State *const front = &g;
static const bool on = false;
inline void patch(const void *, u32, int) {}
inline void prim(u32, u32, u32, const u8 *, u32) {}
inline void mesh(u32, u32, u32, u32, const MeshSrc &, const u8 *, u32) {}
inline void call(u32, u32) {}
inline void tlut(const GTlutObj &, u32) {}
inline void epoch() {}
inline void flush() {}
inline void drain() {}
inline void drain_if_owner() {}
inline void frame_end() {}
#endif

}  // namespace mt
}  // namespace gx
}  // namespace w3d
#endif
