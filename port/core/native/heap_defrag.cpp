// Compacta el montón de datos de carga: reserva de nuevo cada bloque grande, y si la copia queda más abajo lo traslada.
#include "native_common.h"

namespace {
const int kBlockWindow = 128;
struct HeapBlocks {
    w3d_u32 table;
    w3d_u32 count;        // +4
    w3d_u32 pad;
    w3d_u32 biggest;      // +0xc
    w3d_u32 blocks[kBlockWindow];  // +0x10
    w3d_u32 sizes[kBlockWindow];   // +0x210
};
}
extern "C" {
extern char A804b05a0;  // El montón.
extern w3d_u32 A80417658;
void A80358118(void *);
w3d_u32 A802099d4(void *heap);
void A802099b0(void *heap, w3d_u32 mode);
w3d_u32 A80209968(void *heap);
void A8020998c(void *heap, HeapBlocks *out);
w3d_u32 A802098fc(void *heap, w3d_u32 bytes, w3d_u32 align);
void A80209920(void *heap, w3d_u32 block);
int A801ea59c(w3d_u32 *from, w3d_u32 *to, int count);
void A802eee50(void *to, const void *from, w3d_u32 bytes);

// 0x801edc5c: repite hasta que una pasada no mueva nada. Devuelve el número de pasadas. La comparación de la ventana es sin signo,
// como en el original: con menos de 128 bloques vale ya en la primera vuelta y no se mueve nada. La versión original además mide el tiempo
// para un informe que no llegó a la versión final.
int A801edc5c() {
    int passes = 0;
    HeapBlocks scan;
    scan.table = h2g(&A80417658);
    A80358118(&scan);
    const w3d_u32 mode = A802099d4(&A804b05a0);
    A802099b0(&A804b05a0, mode | 4);
    for (;;) {
        scan.biggest = 0;
        scan.count = 0;
        scan.pad = 0;
        A80209968(&A804b05a0);
        A8020998c(&A804b05a0, &scan);
        if (!scan.count) break;
        w3d_u32 from[kBlockWindow], to[kBlockWindow], lengths[kBlockWindow];
        int moved = 0;
        for (int i = (int)scan.count - 1; i >= 0 && (w3d_u32)i > scan.count - kBlockWindow; i--) {
            const w3d_u32 slot = i & (kBlockWindow - 1);
            const w3d_u32 size = scan.sizes[slot];
            if (size >= scan.biggest) continue;
            const w3d_u32 copy = A802098fc(&A804b05a0, size, 0x20);
            if (copy < scan.blocks[slot]) {
                from[moved] = scan.blocks[slot];
                to[moved] = copy;
                lengths[moved] = size;
                moved++;
            } else {
                A80209920(&A804b05a0, copy);
                A80209968(&A804b05a0);
            }
        }
        if (!moved) break;
        passes++;
        for (int i = 0; i < moved; i++) {
            A802eee50(g2h(to[i]), g2h(from[i]), lengths[i]);
            A80209920(&A804b05a0, from[i]);
        }
        A801ea59c(from, to, moved);
    }
    A802099b0(&A804b05a0, mode);
    return passes;
}
}
