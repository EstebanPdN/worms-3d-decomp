#!/usr/bin/env python3
"""Thunks de ABI AAPCS-VFP (3DS). Con punteros de 32 bits casi todo coincide: I, P y R son una palabra en r0-r3 y luego pila.

Quedan los flotantes de otro ancho y los agregados homogéneos, que clang devuelve en s0-s3 y GCC 2.95 por puntero oculto.
"""


def _fp(p): return [x for x in p if x in 'FD']
def _ints(p): return sum(2 if x == 'L' else 1 for x in p if x in 'ILPR')


def stack_words(params):
    """Palabras de argumentos en pila (cota alta si hay agregados, cuyo tamaño se ha perdido)."""
    n = max(0, _ints(params) - 4)
    if any(x in ('S', 'A') for x in params): n += 4
    return n


def inherit_entry(target):
    return '\n'.join(['  push {r0, r1}', '  ldr r0, =w3d_inh'] + [x for i in range(4) for x in (f'  ldr r1, [sp, #{8 + i * 4}]', f'  str r1, [r0, #{i * 4}]')] + ['  pop {r0, r1}', f'  b {target}'])


def inherit_call(target, have, want):
    room = ((want + 1) & ~1) * 4
    body = ['  push {r4, lr}', f'  sub sp, sp, #{room}', '  ldr r4, =w3d_inh']
    for i in range(want):
        body += [f'  ldr ip, [sp, #{room + 8 + i * 4}]' if i < have else f'  ldr ip, [r4, #{i * 4}]', f'  str ip, [sp, #{i * 4}]']
    return '\n'.join(body + [f'  bl {target}', f'  add sp, sp, #{room}', '  pop {r4, pc}'])


def keep_first(target, params):
    """Conserva r0 tras una función declarada void: GCC 2.95 deja ahí this. Copia los argumentos de pila, que el marco desplaza."""
    extra = stack_words(params)
    if not extra: return f'  push {{r0, lr}}\n  bl {target}\n  pop {{r0, pc}}'
    room = ((extra + 1) & ~1) * 4
    body = ['  push {r0, lr}', f'  sub sp, sp, #{room}']
    for i in range(extra): body += [f'  ldr ip, [sp, #{room + 8 + i * 4}]', f'  str ip, [sp, #{i * 4}]']
    return '\n'.join(body + [f'  bl {target}', f'  add sp, sp, #{room}', '  pop {r0, pc}'])


def thunk_body(use, d, target):
    ur, up = use; dr, dp = d
    uvar, dvar = '...' in up, '...' in dp
    if uvar != dvar:
        # Lo variádico lleva los flotantes por r0-r3 como dobles: los enteros coinciden, los flotantes no.
        return 'manual' if _fp(up) or _fp(dp) else None
    if uvar: return None
    # El llamador recibe en registros (s0-s3) y la definición escribe en un destino oculto, primer entero.
    if ur == 'S' and dp and dp[0] == 'R' and dr == 'V' and _ints(up) + 1 <= _ints(dp) and _ints(up) <= 5 and not any(x in ('S', 'A') for x in up):
        return _ret_hfa(up, target)
    if ur == 'S' and dr in 'VIP' and _ints(up) + 1 <= _ints(dp) and _ints(up) <= 5 and not any(x in ('S', 'A') for x in up + dp):
        return _ret_hfa(up, target)
    if ur == 'I' and dp and dp[0] == 'R' and dr == 'V' and _ints(up) + 1 <= _ints(dp) and _ints(up) <= 3 and not any(x in ('S', 'A') for x in up):
        return None  # Vista con Ptr32 de retorno: el destino es el primer argumento que el llamador ya pasa, o un retorno sin usar.
    # Al revés: quien llama da el destino y la definición devuelve en s0-s2.
    if dr == 'S' and up and up[0] in 'RP' and ur == 'V' and _ints(up) >= _ints(dp) + 1 and _ints(dp) <= 3 and not any(x in ('S', 'A') for x in dp):
        return '\n'.join(['  push {r4, lr}', '  mov r4, r0'] + [f'  mov r{k}, r{k + 1}' for k in range(_ints(dp))] + [f'  bl {target}', '  vstm r4, {s0-s2}', '  pop {r4, pc}'])
    if any(x in ('S', 'A') for x in up + dp) or ur in ('S', 'A') or dr in ('S', 'A'):
        return 'manual' if tuple(up) != tuple(dp) or ur != dr else None
    pre = []
    uf, df = _fp(up), _fp(dp)
    if uf != df:
        n = min(len(uf), len(df))
        if n and set(uf[:n]) == {'F'} and set(df[:n]) == {'D'}:
            for k in range(n - 1, -1, -1): pre.append(f'  vcvt.f64.f32 d{k}, s{k}')
        elif n and set(uf[:n]) == {'D'} and set(df[:n]) == {'F'}:
            for k in range(n): pre.append(f'  vcvt.f32.f64 s{k}, d{k}')
        elif uf[:n] != df[:n]:
            return 'manual'
    post = None
    if ur == 'F' and dr == 'D': post = '  vcvt.f32.f64 s0, d0'
    elif ur == 'D' and dr == 'F': post = '  vcvt.f64.f32 d0, s0'
    elif ur in 'FD' and dr in 'ILP': return 'manual'
    elif dr in 'FD' and ur in 'ILP': return 'manual'
    if post is None:
        return '\n'.join(pre + [f'  b {target}']) if pre else None
    if stack_words(up): return 'manual'
    return '\n'.join(['  push {r4, lr}'] + pre + [f'  bl {target}', post, '  pop {r4, pc}'])


def _shift(up):
    n = _ints(up)
    return [f'  mov r{k}, r{k - 1}' for k in range(n, 0, -1)]


def _ret_hfa(up, target):
    # Pila: dos palabras de argumentos salientes y el resultado en +8. Marco total de 40 B con el lr y r4 guardados.
    n = _ints(up); body = ['  push {r4, lr}', '  sub sp, sp, #32']
    if n >= 5: body += ['  ldr ip, [sp, #40]', '  str ip, [sp, #4]']
    if n >= 4: body.append('  str r3, [sp, #0]')
    body += [f'  mov r{k}, r{k - 1}' for k in range(min(n, 3), 0, -1)]
    body += ['  add r0, sp, #8', f'  bl {target}', '  add ip, sp, #8', '  vldm ip, {s0-s3}', '  add sp, sp, #32', '  pop {r4, pc}']
    return '\n'.join(body)


def _ret_int(up, target):
    return '\n'.join(['  push {lr}', '  sub sp, sp, #20'] + _shift(up) + ['  mov r0, sp', f'  bl {target}', '  ldr r0, [sp]', '  add sp, sp, #20', '  pop {pc}'])
