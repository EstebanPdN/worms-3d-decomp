/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800da85c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800da17c = 0x800da17c;
fn_8015f518 = 0x8015f518;
fn_80160038 = 0x80160038;
lbl_80360c90 = 0x80360c90;
lbl_803617d0 = 0x803617d0;
lbl_803897a4 = 0x803897a4;
lbl_803897bc = 0x803897bc;
lbl_803e815c = 0x803e815c;
SECTIONS {
  .text.s8_static_init_800da85c 0x800da85c : { *(.text.s8_static_init_800da85c) }
  .sdata 0x804aeb8c (NOLOAD) : {
    . = 0x0; lbl_804aeb8c = .;
    . = 0x8; lbl_804aeb94 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
