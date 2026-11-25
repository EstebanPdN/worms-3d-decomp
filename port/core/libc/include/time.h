#ifndef W3D_TIME_H
#define W3D_TIME_H
#include "w3d_libc_decl.h"
#include <stddef.h>
typedef int time_t;
typedef int clock_t;
#define CLOCKS_PER_SEC 1000
struct tm { int tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst; };
extern "C" {
time_t time(Ptr32<time_t>) W3D_LIBC(time);
clock_t clock(void) W3D_LIBC(clock);
}
#endif
