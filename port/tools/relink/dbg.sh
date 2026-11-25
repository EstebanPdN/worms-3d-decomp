#!/bin/zsh
# Ejecuta el juego en lldb con tiempo límite y muestra registros y pila al fallar. Uso: dbg.sh [segundos] [comandos lldb extra...]
D="${0:A:h:h:h:h}"; t=${1:-40}; shift
args=()
for c in "$@"; do args+=(-k "$c"); done
cd /tmp
W3D_HIDDEN=1 perl -e "alarm $t; exec @ARGV" lldb --batch -o "process launch --environment W3D_HIDDEN=1 --environment W3D_DEBUG=1" -k "register read x0 x1 x2 x3 x8 x9 x19 lr pc" -k "bt 12" "${args[@]}" -- /tmp/w3dp/link/worms3d "$D/gamedata/GWMP8P" 2>&1 | grep -v "\[Connection\]\|\[Application\]\|\[WindowTab\]" > /tmp/w3dp/lldb.txt
pkill -9 -f 'w3dp/link/worms3d' 2>/dev/null; pkill -9 debugserver 2>/dev/null; true
