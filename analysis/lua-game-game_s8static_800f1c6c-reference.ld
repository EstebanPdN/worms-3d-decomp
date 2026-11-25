/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_static_init_800f1c6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800f165c = 0x800f165c;
fn_8015f518 = 0x8015f518;
fn_80160038 = 0x80160038;
lbl_80360f00 = 0x80360f00;
lbl_803617d0 = 0x803617d0;
lbl_8038c404 = 0x8038c404;
lbl_803e82c8 = 0x803e82c8;
SECTIONS {
  .text.s8_static_init_800f1c6c 0x800f1c6c : { *(.text.s8_static_init_800f1c6c) }
  .sdata 0x804af098 (NOLOAD) : {
    . = 0x0; lbl_804af098 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
