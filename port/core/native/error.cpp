// Errores fatales del juego, escritos a mano. Dirección original en cada símbolo.
#include "w3d_ptr.h"
#if defined(__APPLE__)
#include <execinfo.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace w3d;

extern "C" {
void diag_stack_trace(const char *);
extern w3d_u32 A804b05dc;  // Manejador de errores fatales que instala el juego.

// 0x801fcb90: recibe {mensaje, código}. Avisa al manejador si lo hay; si no, muestra el error y detiene el juego.
w3d_u32 A801fcb90(w3d_u32 error) {
    const w3d_u32 *e = (const w3d_u32 *)g2h(error);
    fflush(stdout);
    fprintf(stderr, "[juego] FATAL ERROR: %s (%08x)\n", (const char *)g2h(e[0]), e[1]);
    void *frames[32];
#if defined(__APPLE__)
    backtrace_symbols_fd(frames, backtrace(frames, 32), 2);
#endif
#if defined(__3DS__)
    diag_stack_trace("error fatal");
#endif
    if (A804b05dc) return ((w3d_u32 (*)(w3d_u32))g2h(A804b05dc))(error);
    _exit(3);
}
}
