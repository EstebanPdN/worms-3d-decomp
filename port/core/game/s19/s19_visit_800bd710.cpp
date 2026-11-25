#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_visit_800bd710.c"
extern struct { Ptr32<Ptr32<void>> begin; Ptr32<Ptr32<void>> end; int pad[2]; } lbl_8043bb64;
extern int FUN_800b53d8(Ptr32<void>);
extern void FUN_800bcdec(Ptr32<void>, float);
int w3d_col_check(void);
void w3d_col_check_note(int site, int differs, int where, unsigned original, unsigned fast);

/* v34 (port): los trozos marcados se recorren por sus bits a 1 (ctz), en orden creciente como el original, en vez de mirar
   los ~180 trozos uno a uno con lecturas volátiles de Ptr32. El barrido (0x800b53d8) no toca la máscara ni la lista, así
   que leer cada palabra una vez da los mismos trozos en el mismo orden, y el orden importa: cada impacto acorta los barridos
   siguientes (0x804b1814). */
struct MarkedLands {
    const unsigned *words;
    unsigned count, base, marked;
};
static void marked_start(MarkedLands *m, Ptr32<void> self)
{
    m->words = (const unsigned *)((char *)self.get() + 128);
    m->count = (unsigned)(lbl_8043bb64.end - lbl_8043bb64.begin);
    m->base = 0u - 32u;
    m->marked = 0;
}
/* Siguiente trozo marcado, o -1. Los bits de la última palabra por encima de la lista no cuentan. */
static int marked_next(MarkedLands *m)
{
    while (m->marked == 0) {
        m->base += 32u;
        if (m->base >= m->count) return -1;
        m->marked = m->words[m->base >> 5];
        if (m->count - m->base < 32u) m->marked &= (1u << (m->count - m->base)) - 1u;
    }
    const unsigned bit = (unsigned)__builtin_ctz(m->marked);
    m->marked &= m->marked - 1u;
    return (int)(m->base + bit);
}

/* W3D_COL_CHECK: la visita original; con compare, comparando cada trozo con el que da el recorrido por bits (con 2, sin
   comparar, para medir). */
static void refresh_marked_original(Ptr32<void> self, int compare)
{
    Ptr32<Ptr32<void>> it;
    Ptr32<Ptr32<void>> end;
    unsigned mask = 1;
    Ptr32<unsigned int> word;
    MarkedLands fast;
    int slot = 0, position = 0, differs = 0, where = 0;
    unsigned was = 0, now = 0;
    marked_start(&fast, self);
    it = lbl_8043bb64.begin;
    end = lbl_8043bb64.end;
    if (it != end) {
        word = (Ptr32<unsigned int>)((Ptr32<char>)self + 128);
        do {
            if (*word & mask) {
                if (compare) {
                    const int next = marked_next(&fast);
                    if (!differs && next != slot) { differs = 1; where = position; was = (unsigned)slot; now = (unsigned)next; }
                    position++;
                }
                FUN_800b53d8(*it);
            }
            mask <<= 1;
            if (mask == 0) {
                mask = 1;
                word++;
            }
            it++;
            slot++;
        } while (it != end);
    }
    if (!compare) return;
    const int extra = marked_next(&fast);
    if (!differs && extra >= 0) { differs = 1; where = position; was = 0xffffffffu; now = (unsigned)extra; }
    w3d_col_check_note(2, differs, where, was, now);
}

void s19_refresh_marked_800bd710(Ptr32<void> self)
{
    FUN_800bcdec(self, 0.0f);
    const int check = w3d_col_check();
    if (check) {
        refresh_marked_original(self, check == 1);
        return;
    }
    MarkedLands marked;
    marked_start(&marked, self);
    Ptr32<void> *const lands = lbl_8043bb64.begin.get();
    for (int i = marked_next(&marked); i >= 0; i = marked_next(&marked)) FUN_800b53d8(lands[i]);
}

}
