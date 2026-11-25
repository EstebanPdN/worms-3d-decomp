// Arena del juego. Todo lo que el núcleo guarda como P<T> vive en ella o en el
// ejecutable, dentro de la ventana de 4 GB que empieza en la base de la imagen.
#ifndef W3D_ARENA_H
#define W3D_ARENA_H
namespace w3d {
// Reserva la arena. Devuelve false si no cabe en la ventana.
bool arena_init(unsigned long bytes);
void *arena_alloc(unsigned long bytes);
void *arena_realloc(void *p, unsigned long bytes);
void arena_free(void *p);
unsigned long arena_used();
void *arena_begin();
void *arena_end();
}
#endif
