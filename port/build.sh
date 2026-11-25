#!/bin/zsh
# Compila el juego desde cero y lo publica en port/build/worms3d. Uso: port/build.sh
# W3DP=<carpeta> cambia la carpeta de trabajo; W3D_NO_PUBLISH=1 deja el binario en $W3DP/link/worms3d.
P="${0:A:h}"; D="${P:h}"; export W3DP=${W3DP:-$P/build/work}; export W3D_TMP=$W3DP
GD=${1:-"$D/gamedata/GWMP8P"}
GD=${GD:A}
[[ $(shasum -a 256 "$GD/sys/main.dol" | cut -d' ' -f1) == bb1b36b9bbb806688e616208254907ae2af59d2e191ff839b3a046a6c2c6f514 ]] || { print -u2 "Expected GWMP8P revision 0 (sys/main.dol)."; exit 1; }
[ -d "$GD/files" ] || { echo "Faltan los datos del juego en $GD"; exit 1; }
cd "$P" || exit 1
mkdir -p $W3DP/lua $W3DP/lua_ll $W3DP/objs $W3DP/ll
for ir in "" --ir; do
  r=$(python3 tools/lift/lift_all.py --no-lift ${=ir} --jobs ${W3D_JOBS:-10} | grep -E '^compilan'); print -- "$r"
  [[ $r == *"fallan 0"* ]] || { echo "Hay unidades que no compilan: ver $W3DP/lift-errors.json"; exit 1; }
done
LUA=(-I core/lua/include -I core/lua/src -DNDEBUG '-DLUA_USER_H="lua_game_port_user.h"')
for f in core/lua/src/*.cpp core/lua/lib/*.cpp; do b=${f:t:r}; [[ $b == ltests || $b == lua || $b == luac ]] && continue
  tools/lift/cc_core.sh arm64-apple-macos14 $W3DP/lua/$b.o $f $LUA || exit 1
  tools/lift/cc_core.sh arm64-apple-macos14 $W3DP/lua_ll/$b.ll $f $LUA -S -emit-llvm -g0 -O0 -Xclang -disable-O0-optnone || exit 1
done
tools/relink/build_game.sh "$GD" || exit 1
[ -x $W3DP/link/worms3d ] || { echo "No se enlazó"; exit 1; }
[ -n "$W3D_NO_PUBLISH" ] && { echo "Listo: $W3DP/link/worms3d"; exit 0; }
pgrep -f "$P/build/worms3d" >/dev/null && { echo "El juego está abierto: no se publica. Binario en $W3DP/link/worms3d"; exit 0; }
mkdir -p build; cp $W3DP/link/worms3d build/worms3d.new && mv -f build/worms3d.new build/worms3d && echo "Publicado: $P/build/worms3d"
