#include "w3d_ptr.h"
#line 1 "d32h_mesh_tree_cull_800bcdec.cpp"
// GWMP8P rev0 0x800bcdec. Mesh tree cull into a visibility bit mask: nodes
// are walked in order, a box test with an enlarged limit rejects a subtree
// (the skip count advances the node pointer and the mask by the subtree's
// leaves), then a band test against the view plane or a cone test against
// the view axis. Mesh, Node and the four camera vectors are partial views.
// The 30.0 limit sits just before this function's pool at 0x80382ce4, so it
// is declared extern.
//
// v34 (port): el recorrido de siempre queda en mesh_tree_cull_original y el que se usa es mesh_tree_cull_fast, con las mismas
// pruebas de coma flotante sobre los mismos nodos y en el mismo orden de nodos: misma máscara bit a bit y mismas palabras
// escritas. W3D_COL_CHECK=1 hace los dos y compara (core/native/land_collision.cpp).
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    bool NonZero() const { bool r = true; if (x == 0.0f && y == 0.0f) r = z != 0.0f; return r; }
    float Dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
};
struct Node { Vec min; Vec max; float radius; unsigned short skip; unsigned short leaves; };
struct Mesh { char unknown0[116]; Ptr32<Node> first; Ptr32<Node> last; char unknown124[4]; unsigned bits[1]; };
extern Vec lbl_8043add8[];
extern Vec lbl_8043ade4[];
extern Vec lbl_8043adf0[];
extern Vec lbl_8043adfc[];
extern float lbl_804b181c;
extern float lbl_80382ce4[];
#define NEXT() mask <<= 1; if (mask == 0) { self->bits[word] = cur; mask = 1; word++; cur = 0; }
#define SKIP() { for (i = 0; i < n->leaves; i++) { NEXT() } n += n->skip; }
#define INBOX() Sub(d, n->min, c); Sub(e, c, n->max); \
    if (d.x < limit && d.y < limit && d.z < limit && e.x < limit && e.y < limit && e.z < limit)
inline void Add(Vec &o, const Vec &a, const Vec &b) { o.x = a.x + b.x; o.y = a.y + b.y; o.z = a.z + b.z; }
inline void ScaleSub(Vec &o, float k, const Vec &b) { o.x = o.x * k - b.x; o.y = o.y * k - b.y; o.z = o.z * k - b.z; }
inline void Sub(Vec &o, const Vec &a, const Vec &b) { o.x = a.x - b.x; o.y = a.y - b.y; o.z = a.z - b.z; }
// El recorrido original, sin cambios salvo que devuelve la última palabra escrita (para W3D_COL_CHECK).
static int mesh_tree_cull_original(Ptr32<Mesh> self, float r) {
    Vec c = lbl_8043add8[0];
    Ptr32<Node> end = self->last;
    Ptr32<Node> n = self->first;
    Vec a = lbl_8043ade4[0];
    Vec b = lbl_8043adf0[0];
    unsigned short i;
    Vec na = a;
    if (a.x == 0.0f && a.y == 0.0f && a.z == 0.0f) na = b;
    float inv = 1.0f / na.len();
    Vec w = lbl_8043adfc[0];
    Vec m, d, e;
    na.x *= inv; na.y *= inv; na.z *= inv;
    float s; float limit = lbl_804b181c + r;
    bool has = w.NonZero();
    unsigned cur = 0, mask = 1;
    int word = 0;
    if (has) {
        if (limit > lbl_80382ce4[0]) {
            while (n != end) {
                INBOX() {
                                        Add(m, n->min, n->max);
                    ScaleSub(m, 0.5f, c);
                    float dot = m.Dot(w);
                    s = n->radius + r;
                    if (dot > -s && dot < s) {
                        if (n->skip == 1) { cur |= mask; NEXT() }
                        n++;
                    } else SKIP()
                } else SKIP()
            }
        } else {
            while (n != end) {
                INBOX() {
                    if (n->skip == 1) { cur |= mask; NEXT() }
                    n++;
                } else SKIP()
            }
        }
    } else {
        while (n != end) {
            INBOX() {
                                    Add(m, n->min, n->max);
                    ScaleSub(m, 0.5f, c);
                float len2 = m.lenSq();
                float dot = m.Dot(na);
                s = n->radius + r;
                if (len2 < s * s + dot * dot) {
                    if (n->skip == 1) { cur |= mask; NEXT() }
                    n++;
                } else SKIP()
            } else SKIP()
        }
    }
    self->bits[word] = cur;
    return word;
}

// ---- v34: recorrido rápido ----
// Ahorra, por nodo: las lecturas volátiles de Ptr32 (cada n->, self-> y el propio n, que vivía en la pila, pasaban por
// Ptr32::get() const volatile), el bucle de SKIP() que hacía un NEXT() por cada hoja de un subárbol descartado, las restas
// de la prueba de caja que no hacían falta (el original calculaba las seis antes de comparar) y comparaciones, porque ahora
// se miran primero los ejes horizontales. El árbol solo agrupa trozos con hijos en la escena (d32h_land_tree_build), así que
// si es plano cada consulta prueba los ~180 nodos del mapa y esto es casi todo el coste de la fase amplia.
namespace {
// Cursor de la máscara de trozos: palabra en curso y bit dentro de ella. next() es NEXT(): al pasar del bit 31 se guarda la
// palabra y se empieza otra a cero.
struct MaskCursor {
    unsigned *bits;
    unsigned cur;
    int bit, word;
    void next() {
        if (++bit == 32) { bits[word++] = cur; cur = 0; bit = 0; }
    }
    void mark() { cur |= 1u << bit; next(); }
    // Lo mismo que «leaves» veces NEXT() sin marcar: la primera palabra que se llena se guarda con lo marcado, las siguientes
    // enteras van a cero, y el bit queda en (bit + leaves) % 32.
    void skip(unsigned leaves) {
        unsigned total = (unsigned)bit + leaves;
        if (total < 32) { bit = (int)total; return; }
        bits[word++] = cur;
        cur = 0;
        for (total -= 32; total >= 32; total -= 32) bits[word++] = 0;
        bit = (int)total;
    }
};
enum { kBoxOnly, kBand, kCone };
}
// INBOX() con las seis comparaciones en otro orden: x y z primero, que son las que fallan en una isla ancha y baja. Cada
// una es la misma resta comparada con el mismo límite, sin efectos: el resultado no depende del orden.
static inline bool in_reach(const Node *n, const Vec &c, float limit) {
    return n->min.x - c.x < limit && c.x - n->max.x < limit
        && n->min.z - c.z < limit && c.z - n->max.z < limit
        && n->min.y - c.y < limit && c.y - n->max.y < limit;
}
// Banda contra el plano del movimiento: las mismas operaciones que el original (Add, ScaleSub y Dot).
static inline bool in_band(const Node *n, const Vec &c, float r, const Vec &w) {
    Vec m;
    Add(m, n->min, n->max);
    ScaleSub(m, 0.5f, c);
    const float dot = m.Dot(w);
    const float s = n->radius + r;
    return dot > -s && dot < s;
}
// Cono contra el eje del movimiento, igual.
static inline bool in_cone(const Node *n, const Vec &c, float r, const Vec &na) {
    Vec m;
    Add(m, n->min, n->max);
    ScaleSub(m, 0.5f, c);
    const float len2 = m.lenSq();
    const float dot = m.Dot(na);
    const float s = n->radius + r;
    return len2 < s * s + dot * dot;
}
template <int kTest>
static int cull_walk(const Node *n, const Node *end, const Vec &c, float limit, float r, const Vec &axis, unsigned *bits) {
    MaskCursor mask = {bits, 0u, 0, 0};
    while (n != end) {
        bool pass = in_reach(n, c, limit);
        if (pass && kTest == kBand) pass = in_band(n, c, r, axis);
        if (pass && kTest == kCone) pass = in_cone(n, c, r, axis);
        if (pass) {
            if (n->skip == 1) mask.mark();
            n++;
        } else {
            mask.skip(n->leaves);
            n += n->skip;
        }
    }
    bits[mask.word] = mask.cur;
    return mask.word;
}
static int mesh_tree_cull_fast(Mesh *self, float r) {
    const Vec c = lbl_8043add8[0];
    const Node *const end = self->last.get();
    const Node *const first = self->first.get();
    const Vec a = lbl_8043ade4[0];
    const Vec b = lbl_8043adf0[0];
    Vec na = a;
    if (a.x == 0.0f && a.y == 0.0f && a.z == 0.0f) na = b;
    const float inv = 1.0f / na.len();
    const Vec w = lbl_8043adfc[0];
    na.x *= inv; na.y *= inv; na.z *= inv;
    const float limit = lbl_804b181c + r;
    unsigned *const bits = self->bits;
    if (w.NonZero()) {
        if (limit > lbl_80382ce4[0]) return cull_walk<kBand>(first, end, c, limit, r, w, bits);
        return cull_walk<kBoxOnly>(first, end, c, limit, r, w, bits);
    }
    return cull_walk<kCone>(first, end, c, limit, r, na, bits);
}

extern "C" int w3d_col_check(void);
extern "C" void w3d_col_check_note(int site, int differs, int where, unsigned original, unsigned fast);
// W3D_COL_CHECK: el original primero; se guardan sus palabras, se hace el rápido y se compara. Se queda lo del original.
static void mesh_tree_cull_checked(Ptr32<Mesh> self, float r) {
    const int last = mesh_tree_cull_original(self, r);
    const int kept = last < 63 ? last + 1 : 64;
    unsigned original[64];
    for (int k = 0; k < kept; k++) original[k] = self->bits[k];
    const int fast_last = mesh_tree_cull_fast(self.get(), r);
    int differs = 0, where = -1;
    unsigned was = (unsigned)last, now = (unsigned)fast_last;
    if (fast_last != last) differs = 1;
    for (int k = 0; !differs && k < kept; k++) {
        if (self->bits[k] == original[k]) continue;
        differs = 1; where = k; was = original[k]; now = self->bits[k];
    }
    w3d_col_check_note(1, differs, where, was, now);
    for (int k = 0; k < kept; k++) self->bits[k] = original[k];
}
// W3D_COL_CHECK=2: solo el original, para medir.
extern "C" void d32h_mesh_tree_cull_800bcdec(Ptr32<Mesh> self, float r) {
    const int check = w3d_col_check();
    if (__builtin_expect(check != 0, 0)) {
        if (check == 2) mesh_tree_cull_original(self, r);
        else mesh_tree_cull_checked(self, r);
        return;
    }
    mesh_tree_cull_fast(self.get(), r);
}
