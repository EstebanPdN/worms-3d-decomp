#include "arena.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include "w3d_ptr.h"

// Asignador de listas libres por tamaño de potencia de dos.
namespace {
struct Header { uint32_t size_class; uint32_t pad[3]; };
const int kClasses = 30;
const unsigned kMinShift = 4;
void *free_list[kClasses];
char *arena_start, *arena_cursor, *arena_limit;
unsigned long used_bytes;

int class_of(unsigned long n) {
    int c = 0; unsigned long s = 1ul << kMinShift;
    while (s < n) { s <<= 1; c++; }
    return c;
}
}

namespace w3d {
bool arena_init(unsigned long bytes) {
    if (arena_start) return true;
#if W3D_POINTER_64
    // Imagen 0x1_00xx_xxxx, pila 0x1_6xxx_xxxx, caché de dyld 0x1_8xxx_xxxx.
    uintptr_t hint = 0x110000000ul;
    void *p = mmap((void *)hint, bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (p == MAP_FAILED) return false;
    if (!in_window(p) || !in_window((char *)p + bytes - 1)) {
        fprintf(stderr, "arena fuera de la ventana: %p\n", p);
        munmap(p, bytes);
        return false;
    }
#else
    void *p = mmap(0, bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (p == MAP_FAILED) return false;
#endif
    arena_start = arena_cursor = (char *)p;
    arena_limit = arena_start + bytes;
    return true;
}
void *arena_alloc(unsigned long n) {
    if (n == 0) n = 1;
    unsigned long total = n + sizeof(Header);
    int c = class_of(total);
    Header *h;
    if (free_list[c]) {
        h = (Header *)free_list[c];
        free_list[c] = *(void **)(h + 1);
    } else {
        unsigned long sz = 1ul << (c + kMinShift);
        if (arena_cursor + sz > arena_limit) { fprintf(stderr, "arena agotada (%lu B)\n", n); return 0; }
        h = (Header *)arena_cursor; arena_cursor += sz;
        h->size_class = (uint32_t)c;
    }
    used_bytes += 1ul << (c + kMinShift);
    return h + 1;
}
void arena_free(void *p) {
    if (!p) return;
    Header *h = (Header *)p - 1;
    used_bytes -= 1ul << (h->size_class + kMinShift);
    *(void **)p = free_list[h->size_class];
    free_list[h->size_class] = h;
}
void *arena_realloc(void *p, unsigned long n) {
    if (!p) return arena_alloc(n);
    if (n == 0) { arena_free(p); return 0; }
    Header *h = (Header *)p - 1;
    unsigned long cap = (1ul << (h->size_class + kMinShift)) - sizeof(Header);
    if (n <= cap) return p;
    void *q = arena_alloc(n);
    if (q) { memcpy(q, p, cap); arena_free(p); }
    return q;
}
unsigned long arena_used() { return used_bytes; }
void *arena_begin() { return arena_start; }
void *arena_end() { return arena_limit; }
}
