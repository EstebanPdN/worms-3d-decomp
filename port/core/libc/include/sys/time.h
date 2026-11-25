// STLport la incluye en su código de hilos, que aquí está desactivado.
#ifndef W3D_SYS_TIME_H
#define W3D_SYS_TIME_H
#include <time.h>
struct timeval { int tv_sec; int tv_usec; };
struct timespec { int tv_sec; int tv_nsec; };
extern "C" int nanosleep(const struct timespec *, struct timespec *);
#endif
