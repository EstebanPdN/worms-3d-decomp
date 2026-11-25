#!/usr/bin/env python3
"""Lectores y escritores de archivos en anfitrión little-endian.

El PPC es big-endian y los archivos XOM little-endian, así que el juego invierte bytes al leer y escribir.
En macOS y 3DS esa inversión sobra: el valor leído ya está en el orden del procesador. Esta pasada sustituye
cada expresión que invierte bytes por su operando y gira las etiquetas de cuatro letras comparadas con palabras leídas.
Solo se aplica a las unidades de LE_UNITS. La inversión se reconoce evaluando la expresión.
"""
import re

LE_UNITS = ['s21_av_802014ec', 's21_av_80201558', 's21_az_802016d0', 's21_ax_80201768', 'genparamc_80201b64', 'genparamc_801b5838',
            'd25e_read_floats_swapped_80201ea4', 'cc43b_read_records_802020f4_v3', 's21_gc_802021dc', 'd26e_read_records_802029b8',
            'tsonnet_c26_skip_records_80202b18', 'tsonnet_c26_swapped_header_80202bb4', 'd32s_strs_read_80202c5c',
            'd33e_read_object_header_80202f34', 'd25e_write_float_swapped_802041d4', 'f5c_write_uuid_80204250', 'f7c_header_80204c18',
            'f7c_types_80204d88', 'f7c_guids_80204f08', 'd47j_write_schema_chunk_80204ffc', 'cx8c_stream_swap_8035bc90',
            's21_au_80201438', 's21_x_802040a8', 's21_au_80201494', 'cx8c_stream_swap_8035bbf0', 'genparamc_80201a14', 's21_x_8020406c']
TAGS = {'0x4d4f494b': '0x4b494f4d', '0x47554944': '0x44495547', '0x54595045': '0x45505954', '0x5343484d': '0x4d484353'}
CAST = re.compile(r'\(\s*(?:unsigned(?:\s+(?:int|short|long))?|int|short|u32|u16|w3d_u32)\s*\)')
VAR = re.compile(r'\*?\s*\b(?!0x)[A-Za-z_]\w*(?:(?:\.|->)\w+|\[\w+\])*')


def is_reversal(expr):
    """Devuelve el operando si expr invierte los bytes de una sola variable."""
    e = CAST.sub('', expr)
    e = re.sub(r'(0x[0-9a-fA-F]+|\b\d+)[uUlL]+', r'\1', e)
    names = {n.strip() for n in VAR.findall(e)}
    if len(names) != 1: return None
    v = names.pop()
    py = re.sub(re.escape(v) + r'(?!\w)', 'x', e)
    if not re.fullmatch(r'[x0-9a-fA-F\s()<>&|]+', py): return None
    try:
        r32 = eval(py, {'x': 0x11223344}) & 0xffffffff
        r16 = eval(py, {'x': 0x1122}) & 0xffff
    except Exception:
        return None
    if r32 == 0x44332211: return v
    if r16 == 0x2211 and '<<' in py and '>>' in py and '24' not in py: return v
    # Con máscara de 16 bits: (x & 0xff) << 8 | x >> 8 no da 0x2211 alto pero sí en el campo de 16.
    return None


def fix_text(text):
    """Busca sentencias con << y comprueba la parte derecha de la asignación o del return."""
    out = text; n = 0; i = 0
    STMT_END = re.compile(r'[;{}]')
    while True:
        m = re.compile(r'<<\s*(24|8)\b').search(out, i)
        if not m: break
        a = m.start()
        while a > 0 and out[a - 1] not in ';{}': a -= 1
        e = STMT_END.search(out, m.end())
        if not e: break
        b = e.start()
        stmt = out[a:b]
        k = None
        for q in re.finditer(r'(?<![=!<>])=(?!=)', stmt): k = q.end()
        r = re.search(r'\breturn\b', stmt)
        start = k if k is not None else (r.end() if r else 0)
        expr = stmt[start:]
        rep = is_reversal(expr.strip())
        if rep:
            out = out[:a + start] + ' ' + rep + out[b:]
            n += 1
            i = a + start + len(rep)
        else:
            i = m.end()
    # Giro de 16 bits con temporal: unsigned short t=v<<8; v=(v>>8)|t;
    out, c = re.subn(r'unsigned short (\w+)\s*=\s*(\w+)\s*<<\s*8\s*;\s*\2\s*=\s*\(\s*\2\s*>>\s*8\s*\)\s*\|\s*\1\s*;', '', out)
    n += c
    for k_, v_ in TAGS.items():
        out = re.sub(k_, v_, out, flags=re.I)
    return out, n


def apply(path):
    t = open(path, encoding='latin-1').read()
    r, n = fix_text(t)
    if r != t: open(path, 'w', encoding='latin-1').write(r)
    return n
