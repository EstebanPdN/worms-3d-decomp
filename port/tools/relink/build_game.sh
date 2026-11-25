#!/bin/zsh
# Compila el código de plataforma y enlaza el juego. Uso: build_game.sh <carpeta de datos>
P="${0:A:h:h:h}"; W3DP=${W3DP:-/tmp/w3dp}; O=$W3DP/link/extra; L=$W3DP/link/extra_ll; mkdir -p $O $L
HF=(-DW3D_PUBLIC=1 -target arm64-apple-macos27 -std=gnu++17 -O1 -g -I "$P/core/runtime" -w -ffp-contract=off -fwrapv -fno-strict-aliasing)
python3 "$P/tools/relink/gen_sdk_stubs.py" || exit 1
rm -f $O/*.o(N) $L/*.ll(N)
NATIVE=("$P"/core/native/*.cpp(N))
# W3D_NATIVE_ONLY="a b": enlaza solo esas unidades de core/native, sin las sustituciones a medias.
if [ -n "$W3D_NATIVE_ONLY" ]; then NATIVE=(); for n in ${=W3D_NATIVE_ONLY}; do NATIVE+=("$P/core/native/$n.cpp"); done; fi
# W3D_NATIVE_WIP=<carpeta>: añade unidades aún sin probar, que quedan fuera del árbol.
if [ -n "$W3D_NATIVE_WIP" ]; then NATIVE+=("$W3D_NATIVE_WIP"/*.cpp(N)); fi
build_pids=()
for f in "$P"/core/boot/*.cpp "$P"/core/libc/src/*.cpp "$P"/core/sdk/*.cpp "$P"/core/overrides/*.cpp "$P"/core/open/*.cpp(N) "${NATIVE[@]}" "$P"/platform/common/*.cpp "$P"/platform/gx/*.cpp(N) "$P"/platform/ui/*.cpp(N); do
  b=${f:t:r}; ( clang++ $HF -c "$f" -o $O/$b.o && clang++ $HF -S -emit-llvm -g0 -O0 -Xclang -disable-O0-optnone "$f" -o $L/$b.ll ) &
  build_pids+=($!)
done
for f in "$P"/platform/macos/*.mm(N) "$P"/platform/gx/*.mm(N); do
  b=${f:t:r}; clang++ $HF -I/opt/homebrew/include -fobjc-arc -c "$f" -o $O/$b.o &
  build_pids+=($!)
done
build_failed=0
for build_pid in $build_pids; do wait $build_pid || build_failed=1; done
if (( build_failed )); then print -u2 "Compilation failed; refusing to relink stale objects."; exit 1; fi
exec python3 "$P/tools/relink/link_all.py" "$1" --extra $O/*.o --extra-ll $L/*.ll
