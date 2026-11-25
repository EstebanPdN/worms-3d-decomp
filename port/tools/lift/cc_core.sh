#!/bin/zsh
# Compila un fichero del núcleo. Uso: cc_core.sh <target> <salida.o> <fuente> [flags...]
PORT="${0:A:h:h:h}"
RES="$(clang -print-resource-dir)"
T="$1"; O="$2"; S="$3"; shift 3
# 3DS: ARM11 MPCore con VFPv2 y ABI de coma flotante por registros.
ARCH=(); [[ $T == armv6k* ]] && ARCH=(-fno-short-enums -mfloat-abi=hard -mfpu=vfpv2 -mtune=mpcore -D__3DS__ -ffunction-sections -fdata-sections -fno-unwind-tables -fno-asynchronous-unwind-tables)
# W3D_LAYOUT_DIR: en vez de compilar, vuelca las disposiciones de los registros (tools/build3ds/layout_diff.py).
if [[ -n $W3D_LAYOUT_DIR ]]; then
  exec clang++ -target "$T" -std=gnu++17 $ARCH -nostdinc -nostdinc++ -isystem "$RES/include" -I "$PORT/core/libc/include" -I "$PORT/core/runtime" \
    -D_NOTHREADS -D_STLP_NO_THREADS -funsigned-char -fno-builtin -fno-exceptions -fno-rtti -fno-access-control -fno-threadsafe-statics -w -fsyntax-only -Xclang -fdump-record-layouts-simple "$S" "$@" > "$W3D_LAYOUT_DIR/${O:t}.txt" 2>/dev/null
fi
# v34: accesores de Ptr32 sin volatile (core/runtime/w3d_ptr.h, W3D_PTR_FAST): W3D_PTR_FAST=1 en todas las unidades, o
# W3D_PTR_FAST_LIST=<archivo con una ruta por línea> solo en esas (para bisecar). Por defecto, la forma de la v33.
VOL=()
[[ $W3D_PTR_FAST == 1 ]] && VOL=(-DW3D_PTR_FAST)
[[ -n $W3D_PTR_FAST_LIST && -f $W3D_PTR_FAST_LIST ]] && grep -qxF "$S" "$W3D_PTR_FAST_LIST" && VOL=(-DW3D_PTR_FAST)
# W3D_CC_SCAN=<carpeta>: no compila; busca variables locales que se leen sin inicializar y deja los avisos por unidad.
if [[ -n $W3D_CC_SCAN ]]; then
  clang++ -target "$T" -std=gnu++17 $ARCH -nostdinc -nostdinc++ -isystem "$RES/include" -I "$PORT/core/libc/include" -I "$PORT/core/runtime" \
    -D_NOTHREADS -D_STLP_NO_THREADS -funsigned-char -fno-builtin -fno-exceptions -fno-rtti -fno-access-control -fno-threadsafe-statics -fsyntax-only \
    -Wno-everything -Wuninitialized -Wsometimes-uninitialized -Wconditional-uninitialized "$S" "$@" 2> "$W3D_CC_SCAN/${O:t}.txt"
  exit 0
fi
exec clang++ -target "$T" -std=gnu++17 $ARCH $VOL -nostdinc -nostdinc++ -isystem "$RES/include" \
  -I "$PORT/core/libc/include" -I "$PORT/core/runtime" \
  -D_NOTHREADS -D_STLP_NO_THREADS -funsigned-char -fno-builtin -fno-exceptions -fno-rtti -fno-access-control -fno-stack-protector -fno-threadsafe-statics -ffp-contract=off -fwrapv -fno-strict-aliasing -O1 -g \
  -Wno-everything -Werror=int-to-pointer-cast -Werror=pointer-to-int-cast -Werror=void-pointer-to-int-cast \
  -c -o "$O" "$S" "$@"
