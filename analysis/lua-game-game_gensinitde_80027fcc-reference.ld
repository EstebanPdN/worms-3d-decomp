/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_sinit_80027fcc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16W3dType_8015f518Pv = 0x8015f518;
__16W3dType_801629f8PvN21ii = 0x801629f8;
__16W3dType_802097ecPvii = 0x802097ec;
fn_80027588 = 0x80027588;
fn_801e1b58 = 0x801e1b58;
fn_8020fbd0 = 0x8020fbd0;
lbl_8035fc40 = 0x8035fc40;
lbl_803618f0 = 0x803618f0;
lbl_803656dc = 0x803656dc;
lbl_8036ccec = 0x8036ccec;
lbl_8036ccfc = 0x8036ccfc;
lbl_8036cd08 = 0x8036cd08;
lbl_8036cd1c = 0x8036cd1c;
lbl_8036cd30 = 0x8036cd30;
lbl_8036cd44 = 0x8036cd44;
lbl_8036cd50 = 0x8036cd50;
lbl_803b0604 = 0x803b0604;
lbl_803e77d8 = 0x803e77d8;
lbl_803ea050 = 0x803ea050;
SECTIONS {
  .text.w3d_sinit_80027fcc 0x80027fcc : { *(.text.w3d_sinit_80027fcc) }
  .text.w3d_sinit_801e25dc 0x801e25dc : { *(.text.w3d_sinit_801e25dc) }
  .sdata 0x804aa80c (NOLOAD) : {
    . = 0x0; lbl_804aa80c = .;
    . = 0x2364; lbl_804acb70 = .;
    . = 0x2368; lbl_804acb74 = .;
    . = 0x236c; lbl_804acb78 = .;
    . = 0x2370; lbl_804acb7c = .;
    . = 0x2374; lbl_804acb80 = .;
    . = 0x2378; lbl_804acb84 = .;
    . = 0x237c; lbl_804acb88 = .;
    . = 0x2380; lbl_804acb8c = .;
    . = 0x2384; lbl_804acb90 = .;
    . = 0x2388; lbl_804acb94 = .;
    . = 0x2390; lbl_804acb9c = .;
    . = 0x2398; lbl_804acba4 = .;
    . = 0x23a0; lbl_804acbac = .;
    . = 0x23a8; lbl_804acbb4 = .;
    . = 0x23b0; lbl_804acbbc = .;
    . = 0x23b8; lbl_804acbc4 = .;
    . = 0x23c0; lbl_804acbcc = .;
    . = 0x23c8; lbl_804acbd4 = .;
    . = 0x5d58; lbl_804b0564 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
