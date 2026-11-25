#!/bin/zsh
# Compila el piloto de Lua y deja los errores en /tmp/w3dp/lua/errors.txt
cd "${0:A:h:h:h}"
mkdir -p /tmp/w3dp/lua; : > /tmp/w3dp/lua/errors.txt; n=0; bad=0
for f in core/lua/src/*.cpp core/lua/lib/*.cpp; do b=${f:t:r}; [[ $b == ltests || $b == lua || $b == luac ]] && continue
  n=$((n+1))
  tools/lift/cc_core.sh arm64-apple-macos14 /tmp/w3dp/lua/$b.o $f -I core/lua/include -I core/lua/src -DNDEBUG '-DLUA_USER_H="lua_game_port_user.h"' >/tmp/w3dp/lua/$b.err 2>&1 || { bad=$((bad+1)); print -- "=== $f" >> /tmp/w3dp/lua/errors.txt; grep -E 'error' /tmp/w3dp/lua/$b.err | head -${1:-8} >> /tmp/w3dp/lua/errors.txt; }
done
print "archivos $n, fallan $bad"
