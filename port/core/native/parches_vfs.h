// Archivos que los VFS de Mac y 3DS (platform/common/vfs.cpp, platform/3ds/vfs_3ds.cpp) sirven parcheados
// (core/native/parches_vfs.cpp). Dos formas:
//   1: parche entero en memoria (w3d_parche_aplica): el VFS lee el archivo y sirve el resultado guardado. El
//      francotirador usa la misma forma con los números 4 y 5 (uno por archivo).
//   2: por tramos (w3d_parche_tramos): el VFS sirve el archivo como una lista de tramos, cada uno leído del archivo
//      original o de memoria. Para archivos grandes: en la consola el montón de malloc va casi lleno durante la
//      partida (79 KB libres de 86 MB en los volcados de la v23).
#pragma once

// Tramo de un archivo servido por partes: 'bytes' bytes del archivo original desde 'desde', o de 'mem' si no es nulo.
struct W3dTramo { const unsigned char *mem; unsigned desde, bytes; };
// Lee n bytes del archivo original desde la posición off; 1 si los leyó todos.
typedef int (*W3dLeer)(void *ctx, unsigned off, void *dst, unsigned n);

extern "C" {
// 0 si el archivo se sirve tal cual; si no, la forma del parche (2 por tramos; 1, 4 o 5 entero en memoria).
int w3d_parche_quiere(const char *path);
// Forma 1. Con in == nullptr devuelve lo ya parcheado, si lo hay.
int w3d_parche_aplica(int k, const unsigned char *in, unsigned size, const unsigned char **out, unsigned *out_size);
// Forma 2. size: tamaño del archivo original. Devuelve 1 con los tramos (memoria del parche, que no se libera).
int w3d_parche_tramos(int k, W3dLeer leer, void *ctx, unsigned size, const W3dTramo **tramos, int *n);
// 1 si el parche k va por tramos (forma 2: el 2 y el 6); si no, entero en memoria (forma 1).
int w3d_parche_es_tramos(int k);
}
