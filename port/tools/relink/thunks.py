#!/usr/bin/env python3
"""Thunks de ABI arm64 entre la forma en que una unidad llama y la forma en que otra define.

Clases: I entero, L entero de 64 (Ptr32), P puntero real, F float, D double, R retorno por puntero oculto,
S/A agregado por valor, V nada. En PPC los bancos de enteros y de flotantes son independientes, igual que aquí.
"""


def banks(params):
    ints = [p for p in params if p in 'ILP']
    fps = [p for p in params if p in 'FD']
    return ints, fps


def fix_ptr(i):
    return [f'  mov w{i}, w{i}', f'  cbz w{i}, 1f', f'  movk x{i}, #1, lsl #32', '1:']


def thunk_body(use, d, target):
    """Cuerpo en ensamblador, None si no hace falta, 'manual' si no se puede generar."""
    ur, up = use; dr, dp = d
    # El llamador ve un tipo trivial que vuelve en registros y la definición tiene constructor de copia y usa x8.
    if ur in ('S', 'A') and dr == 'V' and dp and dp[0] == 'R' and len(up) == len(dp) - 1 and not any(x in ('S', 'A', '...') for x in up + dp[1:]):
        pre = []
        # Por banco de registros: llamador y definición pueden poner los float en otro lugar de la lista.
        ui_ = [u for u in up if u in 'ILP']; di_ = [x for x in dp[1:] if x in 'ILP']
        for ii, (u, x) in enumerate(zip(ui_, di_)):
            if x == 'P' and u in 'IL' and ii < 8: pre += fix_ptr(ii)
        load = ['  ldp s0, s1, [sp, #16]', '  ldp s2, s3, [sp, #24]'] if ur == 'S' else ['  ldp x0, x1, [sp, #16]']
        return '\n'.join(pre + ['  stp x29, x30, [sp, #-48]!', '  mov x29, sp', '  add x8, sp, #16', f'  bl {target}'] + load + ['  ldp x29, x30, [sp], #48', '  ret'])
    # El llamador ve un tipo trivial que vuelve en registros y la definición recibe el destino como primer entero (como PPC).
    if ur in ('S', 'A') and dr in 'VILP' and len(up) == len(dp) - 1 and not any(x in ('S', 'A', '...', 'R') for x in up + dp):
        ui_ = [x for x in up if x in 'ILP']; di_ = [x for x in dp if x in 'ILP']
        if len(ui_) + 1 == len(di_) and len(di_) <= 8 and [x for x in up if x in 'FD'] == [x for x in dp if x in 'FD']:
            pre = []
            for k in range(len(ui_), 0, -1):
                pre.append(f'  mov x{k}, x{k - 1}')
                if di_[k] == 'P' and ui_[k - 1] in 'IL': pre += fix_ptr(k)
            load = ['  ldp s0, s1, [sp, #16]', '  ldp s2, s3, [sp, #24]'] if ur == 'S' else ['  ldp x0, x1, [sp, #16]']
            return '\n'.join(['  stp x29, x30, [sp, #-48]!', '  mov x29, sp'] + pre + ['  add x0, sp, #16', f'  bl {target}'] + load + ['  ldp x29, x30, [sp], #48', '  ret'])
    if any(x in ('S', 'A') for x in up + dp) or ur in ('S', 'A') or dr in ('S', 'A'):
        return 'manual' if tuple(up) != tuple(dp) or ur != dr else None
    pre = []
    uvar = '...' in up; dvar = '...' in dp
    if dvar and not uvar: return 'manual'
    u_fixed = [x for x in up if x != '...']; d_fixed = [x for x in dp if x != '...']
    u_r = bool(u_fixed and u_fixed[0] == 'R'); d_r = bool(d_fixed and d_fixed[0] == 'R')
    if u_r: u_fixed = u_fixed[1:]
    if d_r: d_fixed = d_fixed[1:]
    ui, uf = banks(u_fixed); di, df = banks(d_fixed)
    # Retorno por puntero oculto: x8 frente a primer entero.
    if u_r and not d_r:
        n = len(di)
        for k in range(min(n, 8) - 1, 0, -1): pre.append(f'  mov x{k}, x{k - 1}')
        pre.append('  mov x0, x8')
        if di and di[0] == 'P': pass
        di = di[1:] if di else []
        shift = 1
    elif d_r and not u_r:
        pre += ['  mov w8, w0', '  cbz w8, 1f', '  movk x8, #1, lsl #32', '1:']
        for k in range(0, min(len(ui), 8) - 1): pre.append(f'  mov x{k}, x{k + 1}')
        ui = ui[1:] if ui else []
        shift = 0
    else:
        shift = 0
    for k in range(min(len(ui), len(di))):
        if di[k] == 'P' and ui[k] in 'IL': pre += fix_ptr(k + shift)
    # El llamador no declara ese argumento y confía en que el registro sigue vivo (normal en PPC): llega como dirección de 32 bits.
    if not uvar:
        for k in range(len(ui), min(len(di), 8)):
            if di[k] == 'P': pre += fix_ptr(k + shift)
    for k in range(min(len(uf), len(df), 8)):
        if uf[k] == 'F' and df[k] == 'D': pre.append(f'  fcvt d{k}, s{k}')
        elif uf[k] == 'D' and df[k] == 'F': pre.append(f'  fcvt s{k}, d{k}')
    if uvar and not dvar:
        # Apple arm64: lo variádico va por pila, en ranuras de 8 B.
        slot = 0
        ii, ff = len(ui), len(uf)
        for x in d_fixed[len(u_fixed):]:
            if x in 'ILP':
                if ii < 8: pre.append(f'  ldr x{ii}, [sp, #{slot * 8}]')
                if x == 'P' and ii < 8: pre += fix_ptr(ii)
                ii += 1
            else:
                if ff < 8:
                    pre.append(f'  ldr d{ff}, [sp, #{slot * 8}]')
                    if x == 'F': pre.append(f'  fcvt s{ff}, d{ff}')
                ff += 1
            slot += 1
    post = []
    if ur == 'P' and dr in 'IL': post += ['  mov w0, w0', '  cbz w0, 2f', '  movk x0, #1, lsl #32', '2:']
    elif ur == 'F' and dr == 'D': post.append('  fcvt s0, d0')
    elif ur == 'D' and dr == 'F': post.append('  fcvt d0, s0')
    elif ur in 'FD' and dr in 'ILP': return 'manual'
    elif dr in 'FD' and ur in 'ILP': return 'manual'
    # Lo variádico va por pila: un marco propio correría los argumentos. Definición variádica: salto directo sin arreglar
    # el retorno (son formateadores y constructores cuyo resultado no se usa). Llamada variádica a definición normal:
    # los argumentos ya se leen aquí, pero hay que contar el marco.
    if dvar: post = []
    if uvar and not dvar and post:
        import re
        pre = [re.sub(r'\[sp, #(\d+)\]', lambda m: f'[sp, #{int(m[1]) + 16}]', x) for x in pre]
    if not pre and not post: return None
    if not post:
        return '\n'.join(pre + [f'  b {target}'])
    if len(ui) > 8 or len(uf) > 8: return 'manual'
    return '\n'.join(['  stp x29, x30, [sp, #-16]!', '  mov x29, sp'] + pre + [f'  bl {target}'] + post + ['  ldp x29, x30, [sp], #16', '  ret'])
