// Interfaz común entre el núcleo del juego y cada plataforma (macOS, 3DS).
#ifndef W3D_PLATFORM_H
#define W3D_PLATFORM_H
#include <stdint.h>

namespace w3d {
namespace plat {

struct Config {
    const char *data_root;  // Copia local del usuario: contiene sys/ y files/.
    const char *save_root;  // Partidas y ajustes del port.
    int width, height;
    const char *title;
    bool hidden;  // Sin ventana visible, para pruebas de consola.
};

bool init(const Config &cfg);
void shutdown();

// Eventos y tiempo. pump devuelve false cuando el usuario cierra la ventana.
bool pump();
double now_seconds();
void sleep_seconds(double s);

// Sistema de archivos de solo lectura sobre files/ del juego.
struct File;
File *file_open(const char *game_path);  // Ruta del disco, sin distinguir mayúsculas.
long file_size(File *f);
long file_read(File *f, void *dst, long offset, long bytes);
void file_close(File *f);
// v34 (3DS): lecturas en segundo plano para los streams del juego (audio .dsp, sdk_core.cpp). aio_read: false si no se
// puede (cola llena: se lee en el momento). aio_done: una lectura terminada (id y bytes, o -1), o false si no hay.
// aio_cancel: la quita de la cola, o espera a que termine si ya se está leyendo; su resultado no sale por aio_done.
bool aio_read(const char *path, void *dst, long off, long len, unsigned id);
bool aio_done(unsigned *id, long *result);
void aio_cancel(unsigned id);

// Mando en el formato de GameCube.
struct Pad {
    uint16_t buttons;
    int8_t stick_x, stick_y, cstick_x, cstick_y;
    uint8_t trigger_l, trigger_r;
    bool connected;
};
void pad_read(int index, Pad *out);

// Audio: la plataforma pide cuadros estéreo de 16 bits a 48 kHz desde su propio hilo.
typedef void (*AudioPull)(int16_t *stereo, int frames);
bool audio_start(AudioPull pull);

// Presentación mínima. El render real del juego entra por GX.
void present_clear(float r, float g, float b);
// Superficies para el backend GX, sin retener: id<MTLDevice>, id<MTLCommandQueue> y CAMetalLayer*.
void *metal_device();
void *metal_queue();
void *metal_layer();  // Nulo con la ventana oculta: sin presentación, la captura sigue funcionando.
// Textura que capture_frame guardará. Es la imagen real de la copia a pantalla.
void set_presented_texture(void *mtl_texture);
// Guarda la última imagen presentada como PPM. Lee la textura real de Metal.
bool capture_frame(const char *path);

}  // namespace plat
}  // namespace w3d
#endif
