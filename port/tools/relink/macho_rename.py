#!/usr/bin/env python3
"""Renombra símbolos externos en un objeto Mach-O arm64 (Xcode no trae llvm-objcopy)."""
import struct

LC_SYMTAB = 2


def read_symbols(path):
    b = open(path, 'rb').read()
    return list(_iter(b))


def _symtab(b):
    magic, _, _, _, ncmds, _, _, _ = struct.unpack_from('<8I', b, 0)
    if magic != 0xfeedfacf: raise ValueError('no es Mach-O de 64 bits')
    off = 32
    for _ in range(ncmds):
        cmd, size = struct.unpack_from('<2I', b, off)
        if cmd == LC_SYMTAB: return off, struct.unpack_from('<4I', b, off + 8)
        off += size
    return None, None


def _iter(b):
    _, st = _symtab(b)
    if st is None: return
    symoff, nsyms, stroff, strsize = st
    for i in range(nsyms):
        strx, ntype, sect, desc, value = struct.unpack_from('<IBBHQ', b, symoff + i * 16)
        end = b.index(b'\0', stroff + strx)
        name = b[stroff + strx:end].decode('latin-1')
        yield i, name, ntype, sect, desc, value


def neutralize_init(b):
    """Quita los inicializadores estáticos del anfitrión: el juego los llama desde su tabla .ctors."""
    ncmds = struct.unpack_from('<I', b, 16)[0]; off = 32; n = 0
    for _ in range(ncmds):
        cmd, size = struct.unpack_from('<2I', b, off)
        if cmd == 0x19:
            for i in range(struct.unpack_from('<I', b, off + 64)[0]):
                q = off + 72 + i * 80
                fl = struct.unpack_from('<I', b, q + 64)[0]
                if fl & 0xff == 9:
                    struct.pack_into('<I', b, q + 64, fl & ~0xff); n += 1
        off += size
    return n


def rename(src, dst, mapping, undefine=(), keep_init=True):
    """mapping usa nombres con el '_' inicial. Las cadenas nuevas se añaden al final de la tabla."""
    b = bytearray(open(src, 'rb').read())
    # Los inicializadores del anfitrión solo crean tablas con punteros y corren antes de main.
    if not keep_init: neutralize_init(b)
    cmd_off, st = _symtab(b)
    if st is None:
        open(dst, 'wb').write(b); return 0
    symoff, nsyms, stroff, strsize = st
    if stroff + strsize != len(b):
        raise ValueError('la tabla de cadenas no está al final del objeto')
    extra = bytearray(); table = {}; n = 0
    for i, name, ntype, sect, desc, value in list(_iter(bytes(b))):
        new = mapping.get(name)
        if new is None or not (ntype & 0x01): continue  # Solo externos (N_EXT).
        if new not in table:
            table[new] = strsize + len(extra)
            extra += new.encode('latin-1') + b'\0'
        struct.pack_into('<I', b, symoff + i * 16, table[new]); n += 1
        if new in undefine and sect:
            # Función sustituida: también las llamadas internas del objeto deben ir a la sustituta.
            struct.pack_into('<IBBHQ', b, symoff + i * 16, table[new], 0x01, 0, 0, 0)
    b += extra
    pad = (-len(b)) % 8
    b += b'\0' * pad
    struct.pack_into('<I', b, cmd_off + 8 + 12, strsize + len(extra) + pad)
    open(dst, 'wb').write(b)
    return n
