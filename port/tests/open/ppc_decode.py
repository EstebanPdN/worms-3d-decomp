#!/usr/bin/env python3
"""Decodificador PPC (Gekko, sin paired singles aritméticos) para traducir funciones sin fuente admitida.

Cada instrucción se reduce a (usos, definiciones, operación). No imprime C: eso lo hace ppc2cpp.py.
"""
import struct


def s16(x): return x - 0x10000 if x & 0x8000 else x
def s12(x): return x - 0x1000 if x & 0x800 else x
def r(n): return 'r%d' % n
def f(n): return 'f%d' % n
def cr(n): return 'cr%d' % n


def rlw_mask(mb, me):
    m = 0
    i = mb
    while True:
        m |= 1 << (31 - i)
        if i == me: break
        i = (i + 1) & 31
    return m


class I:
    __slots__ = ('a', 'w', 'op', 'd', 'ra', 'rb', 'imm', 'x', 'rc', 'uses', 'defs', 'bo', 'bi', 'target', 'lk', 'sz', 'fp', 'upd', 'sign', 'load', 'mb', 'me', 'sh', 'mask')

    def __init__(self, a, w):
        self.a = a; self.w = w; self.op = None; self.d = self.ra = self.rb = self.imm = None; self.x = None; self.rc = False
        self.uses = set(); self.defs = set(); self.bo = self.bi = self.target = None; self.lk = False
        self.sz = 0; self.fp = False; self.upd = False; self.sign = False; self.load = False; self.mb = self.me = self.sh = 0; self.mask = 0


LOADS = {32: ('l', 4, 0, 0), 33: ('l', 4, 0, 1), 34: ('l', 1, 0, 0), 35: ('l', 1, 0, 1), 40: ('l', 2, 0, 0), 41: ('l', 2, 0, 1), 42: ('l', 2, 1, 0), 43: ('l', 2, 1, 1),
         36: ('s', 4, 0, 0), 37: ('s', 4, 0, 1), 38: ('s', 1, 0, 0), 39: ('s', 1, 0, 1), 44: ('s', 2, 0, 0), 45: ('s', 2, 0, 1)}
FLOADS = {48: ('l', 4, 0), 49: ('l', 4, 1), 50: ('l', 8, 0), 51: ('l', 8, 1), 52: ('s', 4, 0), 53: ('s', 4, 1), 54: ('s', 8, 0), 55: ('s', 8, 1)}
XMEM = {23: ('l', 4, 0, 0), 55: ('l', 4, 0, 1), 87: ('l', 1, 0, 0), 119: ('l', 1, 0, 1), 279: ('l', 2, 0, 0), 311: ('l', 2, 0, 1), 343: ('l', 2, 1, 0), 375: ('l', 2, 1, 1),
        151: ('s', 4, 0, 0), 183: ('s', 4, 0, 1), 215: ('s', 1, 0, 0), 247: ('s', 1, 0, 1), 407: ('s', 2, 0, 0), 439: ('s', 2, 0, 1)}
XFMEM = {535: ('l', 4, 0), 567: ('l', 4, 1), 599: ('l', 8, 0), 631: ('l', 8, 1), 663: ('s', 4, 0), 695: ('s', 4, 1), 727: ('s', 8, 0), 759: ('s', 8, 1)}
ARITH3 = {266: 'add', 40: 'subf', 235: 'mullw', 75: 'mulhw', 11: 'mulhwu', 491: 'divw', 459: 'divwu', 10: 'addc', 8: 'subfc', 138: 'adde', 136: 'subfe'}
ARITH2 = {104: 'neg', 202: 'addze', 200: 'subfze', 234: 'addme', 232: 'subfme'}
LOGIC3 = {28: 'and', 444: 'or', 316: 'xor', 60: 'andc', 412: 'orc', 124: 'nor', 284: 'eqv', 476: 'nand', 24: 'slw', 536: 'srw', 792: 'sraw'}
LOGIC2 = {954: 'extsb', 922: 'extsh', 26: 'cntlzw'}
NOPS31 = {54, 86, 278, 246, 470, 982, 598, 854, 306, 370, 566}
FP3 = {18: 'fdiv', 20: 'fsub', 21: 'fadd'}
FP4 = {28: 'fmsub', 29: 'fmadd', 30: 'fnmsub', 31: 'fnmadd'}


def decode(a, w):
    i = I(a, w)
    op = w >> 26; rd = (w >> 21) & 31; ra = (w >> 16) & 31; rb = (w >> 11) & 31; rc5 = (w >> 6) & 31; imm = w & 0xffff; rc = w & 1; xo = (w >> 1) & 1023
    i.d, i.ra, i.rb = rd, ra, rb; i.imm = imm; i.rc = bool(rc)
    if w in (0, 1):
        i.op = 'word'; i.imm = w; return i
    if op == 7: i.op = 'mulli'; i.imm = s16(imm); i.uses = {r(ra)}; i.defs = {r(rd)}
    elif op == 8: i.op = 'subfic'; i.imm = s16(imm); i.uses = {r(ra)}; i.defs = {r(rd), 'ca'}
    elif op == 10 or op == 11:
        i.op = 'cmpli' if op == 10 else 'cmpi'; i.imm = imm if op == 10 else s16(imm); i.d = rd >> 2
        if rd & 1: raise ValueError('cmp L=1')
        i.uses = {r(ra)}; i.defs = {cr(i.d)}
    elif op == 12 or op == 13:
        i.op = 'addic'; i.imm = s16(imm); i.rc = op == 13; i.uses = {r(ra)}; i.defs = {r(rd), 'ca'}
        if op == 13: i.defs.add('cr0')
    elif op == 14 or op == 15:
        i.op = 'addi' if op == 14 else 'addis'; i.imm = s16(imm); i.rc = False
        i.uses = {r(ra)} if ra else set(); i.defs = {r(rd)}
    elif op == 16:
        i.op = 'bc'; i.bo = rd; i.bi = ra; i.lk = bool(w & 1); d = w & 0xfffc
        i.target = (a + (d - 0x10000 if d & 0x8000 else d)) & 0xffffffff if not w & 2 else (d - 0x10000 if d & 0x8000 else d) & 0xffffffff
        i.rc = False; bc_uses(i)
    elif op == 18:
        li = w & 0x03fffffc
        if li & 0x02000000: li -= 0x04000000
        i.op = 'b'; i.lk = bool(w & 1); i.target = (a + li) & 0xffffffff if not w & 2 else li & 0xffffffff; i.rc = False
    elif op == 19:
        if xo == 16 or xo == 528:
            i.op = 'bclr' if xo == 16 else 'bcctr'; i.bo = rd; i.bi = ra; i.lk = bool(w & 1); i.rc = False; bc_uses(i)
            i.uses.add('lr' if xo == 16 else 'ctr')
        elif xo in (33, 129, 193, 225, 257, 289, 417, 449):
            i.op = {33: 'crnor', 129: 'crandc', 193: 'crxor', 225: 'crnand', 257: 'crand', 289: 'creqv', 417: 'crorc', 449: 'cror'}[xo]; i.rc = False
            i.uses = {cr(ra >> 2), cr(rb >> 2), cr(rd >> 2)}; i.defs = {cr(rd >> 2)}
        elif xo == 0: i.op = 'mcrf'; i.rc = False; i.uses = {cr(ra >> 2)}; i.defs = {cr(rd >> 2)}
        elif xo == 150: i.op = 'nop'
        elif xo == 50: i.op = 'rfi'
        else: raise ValueError('op19 %d' % xo)
    elif op in (20, 21, 23):
        i.op = {20: 'rlwimi', 21: 'rlwinm', 23: 'rlwnm'}[op]; i.sh = rb; i.mb = rc5; i.me = (w >> 1) & 31; i.mask = rlw_mask(i.mb, i.me)
        i.uses = {r(rd)}; i.defs = {r(ra)}
        if op == 20: i.uses.add(r(ra))
        if op == 23: i.uses.add(r(rb))
        if rc: i.defs.add('cr0')
    elif op in (24, 25, 26, 27, 28, 29):
        i.op = {24: 'ori', 25: 'oris', 26: 'xori', 27: 'xoris', 28: 'andi', 29: 'andis'}[op]; i.rc = op >= 28
        i.uses = {r(rd)}; i.defs = {r(ra)}
        if op >= 28: i.defs.add('cr0')
    elif op == 31: dec31(i, rd, ra, rb, xo, rc, w)
    elif op in LOADS:
        k, sz, sg, up = LOADS[op]; i.op = 'mem'; i.load = k == 'l'; i.sz = sz; i.sign = bool(sg); i.upd = bool(up); i.imm = s16(imm); i.rb = None; i.rc = False
        i.uses = {r(ra)} if ra else set(); i.defs = set()
        if i.load: i.defs.add(r(rd))
        else: i.uses.add(r(rd))
        if up: i.defs.add(r(ra))
    elif op == 46 or op == 47:
        i.op = 'lmw' if op == 46 else 'stmw'; i.imm = s16(imm); i.rc = False; i.uses = {r(ra)}
        if op == 46: i.defs = {r(x) for x in range(rd, 32)}
        else: i.uses |= {r(x) for x in range(rd, 32)}
    elif op in FLOADS:
        k, sz, up = FLOADS[op]; i.op = 'mem'; i.fp = True; i.load = k == 'l'; i.sz = sz; i.upd = bool(up); i.imm = s16(imm); i.rb = None; i.rc = False
        i.uses = {r(ra)} if ra else set()
        if i.load: i.defs.add(f(rd))
        else: i.uses.add(f(rd))
        if up: i.defs.add(r(ra))
    elif op == 56 or op == 60:
        i.op = 'psq_l' if op == 56 else 'psq_st'; i.imm = s12(imm & 0xfff); i.sz = (imm >> 15) & 1; i.mb = (imm >> 12) & 7; i.rc = False
        i.uses = {r(ra)} if ra else set()
        if op == 56: i.defs = {f(rd)}
        else: i.uses.add(f(rd))
    elif op == 59:
        xo5 = (w >> 1) & 31
        if xo5 in FP3: i.op = FP3[xo5] + 's'; i.uses = {f(ra), f(rb)}; i.defs = {f(rd)}
        elif xo5 == 25: i.op = 'fmuls'; i.uses = {f(ra), f(rc5)}; i.defs = {f(rd)}; i.rb = rc5
        elif xo5 in FP4: i.op = FP4[xo5] + 's'; i.uses = {f(ra), f(rb), f(rc5)}; i.defs = {f(rd)}; i.sh = rc5
        elif xo5 == 24: i.op = 'fres'; i.uses = {f(rb)}; i.defs = {f(rd)}
        else: raise ValueError('op59 %d' % xo5)
        if rc: i.defs.add('cr1')
    elif op == 63:
        xo5 = (w >> 1) & 31
        if xo == 0 or xo == 32: i.op = 'fcmp'; i.d = rd >> 2; i.rc = False; i.uses = {f(ra), f(rb)}; i.defs = {cr(i.d)}
        elif xo in (12, 14, 15, 40, 72, 136, 264):
            i.op = {12: 'frsp', 14: 'fctiw', 15: 'fctiwz', 40: 'fneg', 72: 'fmr', 136: 'fnabs', 264: 'fabs'}[xo]; i.uses = {f(rb)}; i.defs = {f(rd)}
        elif xo5 in FP3: i.op = FP3[xo5]; i.uses = {f(ra), f(rb)}; i.defs = {f(rd)}
        elif xo5 == 25: i.op = 'fmul'; i.uses = {f(ra), f(rc5)}; i.defs = {f(rd)}; i.rb = rc5
        elif xo5 in FP4: i.op = FP4[xo5]; i.uses = {f(ra), f(rb), f(rc5)}; i.defs = {f(rd)}; i.sh = rc5
        elif xo5 == 23: i.op = 'fsel'; i.uses = {f(ra), f(rb), f(rc5)}; i.defs = {f(rd)}; i.sh = rc5
        elif xo5 == 26: i.op = 'frsqrte'; i.uses = {f(rb)}; i.defs = {f(rd)}
        elif xo in (583, 711, 38, 70, 134): i.op = 'nop'
        else: raise ValueError('op63 %d' % xo)
        if rc and i.op != 'fcmp': i.defs.add('cr1')
    else:
        raise ValueError('op %d' % op)
    return i


def bc_uses(i):
    if not i.bo & 4: i.uses.add('ctr'); i.defs.add('ctr')
    if not i.bo & 16: i.uses.add(cr(i.bi >> 2))


def dec31(i, rd, ra, rb, xo, rc, w):
    i.x = xo
    if xo == 0 or xo == 32:
        i.op = 'cmp' if xo == 0 else 'cmpl'; i.d = rd >> 2; i.rc = False; i.uses = {r(ra), r(rb)}; i.defs = {cr(i.d)}
    elif xo in XMEM:
        k, sz, sg, up = XMEM[xo]; i.op = 'memx'; i.load = k == 'l'; i.sz = sz; i.sign = bool(sg); i.upd = bool(up); i.rc = False
        i.uses = ({r(ra)} if ra else set()) | {r(rb)}
        if i.load: i.defs.add(r(rd))
        else: i.uses.add(r(rd))
        if up: i.defs.add(r(ra))
    elif xo in XFMEM:
        k, sz, up = XFMEM[xo]; i.op = 'memx'; i.fp = True; i.load = k == 'l'; i.sz = sz; i.upd = bool(up); i.rc = False
        i.uses = ({r(ra)} if ra else set()) | {r(rb)}
        if i.load: i.defs.add(f(rd))
        else: i.uses.add(f(rd))
        if up: i.defs.add(r(ra))
    elif xo in ARITH3:
        i.op = ARITH3[xo]; i.uses = {r(ra), r(rb)}; i.defs = {r(rd)}
        if i.op in ('addc', 'subfc', 'adde', 'subfe'): i.defs.add('ca')
        if i.op in ('adde', 'subfe'): i.uses.add('ca')
        if rc: i.defs.add('cr0')
    elif xo in ARITH2:
        i.op = ARITH2[xo]; i.uses = {r(ra)}; i.defs = {r(rd)}
        if i.op != 'neg': i.uses.add('ca'); i.defs.add('ca')
        if rc: i.defs.add('cr0')
    elif xo in LOGIC3:
        i.op = LOGIC3[xo]; i.uses = {r(rd), r(rb)}; i.defs = {r(ra)}
        if i.op == 'sraw': i.defs.add('ca')
        if rc: i.defs.add('cr0')
    elif xo in LOGIC2:
        i.op = LOGIC2[xo]; i.uses = {r(rd)}; i.defs = {r(ra)}
        if rc: i.defs.add('cr0')
    elif xo == 824:
        i.op = 'srawi'; i.sh = rb; i.uses = {r(rd)}; i.defs = {r(ra), 'ca'}
        if rc: i.defs.add('cr0')
    elif xo == 19: i.op = 'mfcr'; i.rc = False; i.uses = {cr(x) for x in range(8)}; i.defs = {r(rd)}
    elif xo == 144:
        i.op = 'mtcrf'; i.rc = False; i.imm = (w >> 12) & 0xff; i.uses = {r(rd)}; i.defs = {cr(x) for x in range(8) if i.imm & (0x80 >> x)}
        i.uses |= i.defs
    elif xo == 339 or xo == 467:
        spr = ((w >> 16) & 31) | (((w >> 11) & 31) << 5); i.rc = False; i.imm = spr
        if xo == 339: i.op = 'mfspr'; i.defs = {r(rd)}; i.uses = {{8: 'lr', 9: 'ctr'}[spr]} if spr in (8, 9) else set()
        else:
            i.op = 'mtspr'; i.uses = {r(rd)}; i.defs = {{8: 'lr', 9: 'ctr'}[spr]} if spr in (8, 9) else set()
    elif xo == 83 or xo == 146 or xo == 467: i.op = 'msr'; i.rc = False
    elif xo == 1014: i.op = 'dcbz'; i.rc = False; i.uses = ({r(ra)} if ra else set()) | {r(rb)}
    elif xo in NOPS31: i.op = 'nop'; i.rc = False
    else:
        raise ValueError('op31 %d' % xo)
