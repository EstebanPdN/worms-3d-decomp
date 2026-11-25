/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800af134)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800ad984 = 0x800ad984;
fn_8015f518 = 0x8015f518;
fn_80160038 = 0x80160038;
lbl_80360870 = 0x80360870;
lbl_803617d0 = 0x803617d0;
lbl_80382230 = 0x80382230;
lbl_80382244 = 0x80382244;
lbl_803e7ef4 = 0x803e7ef4;
SECTIONS {
  .text.s8_static_init_800af134 0x800af134 : { *(.text.s8_static_init_800af134) }
  .sdata 0x804ae3dc (NOLOAD) : {
    . = 0x0; lbl_804ae3dc = .;
    . = 0x8; lbl_804ae3e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
