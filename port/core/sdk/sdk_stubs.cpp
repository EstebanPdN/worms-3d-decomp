// Generado por tools/relink/gen_sdk_stubs.py. Pendientes del SDK: devuelven 0 y dejan rastro con W3D_TRACE_SDK.
#include <stdio.h>
#include <stdlib.h>
static int trace = -1;
static void note(const char *n, unsigned a) { if (trace < 0) trace = getenv("W3D_TRACE_SDK") != nullptr; if (trace) fprintf(stderr, "[sdk] %s (0x%08x)\n", n, a); }
extern "C" {
}
