#!/usr/bin/env python3
"""Lo mismo que macho_rename.py para objetos ELF de ARM (3DS). Da los nombres con '_' delante, como Mach-O, para que link_all.py no cambie."""
import os, struct, subprocess
BIN = os.path.expanduser('~/devkitpro/devkitARM/bin/arm-none-eabi-')


def read_symbols(path):
    out = subprocess.run([BIN + 'nm', '-g', path], capture_output=True, text=True, errors='replace').stdout
    r = []
    for i, line in enumerate(out.splitlines()):
        p = line.split()
        if len(p) == 2 and p[0] in 'Uw': r.append((i, '_' + p[1], 1, 0, 0, 0))
        elif len(p) == 3: r.append((i, '_' + p[2], 1, 1, 0, int(p[0], 16)))
    return r


def rename(src, dst, mapping, undefine=(), keep_init=True):
    """mapping usa nombres con '_'. Edita .symtab directamente: varios símbolos pueden ir al mismo nombre, y objcopy lo rechaza.
    Una función sustituida queda débil: gana la sustituta, también en las llamadas internas del objeto."""
    b = bytearray(open(src, 'rb').read())
    shoff, = struct.unpack_from('<I', b, 32)
    shentsize, shnum = struct.unpack_from('<2H', b, 46)
    und = {u[1:] for u in undefine}
    for i in range(shnum):
        o = shoff + i * shentsize
        if struct.unpack_from('<I', b, o + 4)[0] != 2: continue   # SHT_SYMTAB
        off, size, link = struct.unpack_from('<3I', b, o + 16)
        so = shoff + link * shentsize
        stroff, strsize = struct.unpack_from('<2I', b, so + 16)
        extra = bytearray(); table = {}
        for k in range(size // 16):
            e = off + k * 16
            nm, value, sz, info, other, shndx = struct.unpack_from('<IIIBBH', b, e)
            if info >> 4 == 0 or not nm: continue
            end = b.index(0, stroff + nm)
            name = '_' + b[stroff + nm:end].decode('latin-1')
            new = mapping.get(name)
            if new is None: continue
            new = new[1:]
            if new not in table:
                table[new] = strsize + len(extra); extra += new.encode('latin-1') + b'\0'
            struct.pack_into('<I', b, e, table[new])
            if new in und and shndx: struct.pack_into('<B', b, e + 12, (2 << 4) | (info & 15))
        # La tabla de cadenas nueva va al final del archivo.
        new_off = len(b)
        b += b[stroff:stroff + strsize] + extra
        struct.pack_into('<2I', b, so + 16, new_off, strsize + len(extra))
        break
    open(dst, 'wb').write(b)
    if not keep_init:
        subprocess.check_call([BIN + 'objcopy', '-R', '.init_array', '-R', '.ctors', dst])
    return len(mapping)
