/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80024d08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8010A8E0 = 0x8010a8e0;
fn_8015F5A0 = 0x8015f5a0;
fn_80161014 = 0x80161014;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
lbl_8037310C = 0x8037310c;
lbl_8040DEC8 = 0x8040dec8;
lbl_8040DF48 = 0x8040df48;
SECTIONS {
  .text.w3d_auto_80024d08 0x80024d08 : { *(.text.w3d_auto_80024d08) }
  .text.w3d_auto_80025830 0x80025830 : { *(.text.w3d_auto_80025830) }
  .text.w3d_auto_800306a4 0x800306a4 : { *(.text.w3d_auto_800306a4) }
  .sdata 0x804acd54 (NOLOAD) : {
    . = 0x0; lbl_804ACD54 = .;
    . = 0x4a00; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
