/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_float_init_800a9d08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015F518 = 0x8015f518;
lbl_803819A0 = 0x803819a0;
lbl_803819B4 = 0x803819b4;
lbl_803819C8 = 0x803819c8;
lbl_80439590 = 0x80439590;
SECTIONS {
  .text.s8_float_init_800a9d08 0x800a9d08 : { *(.text.s8_float_init_800a9d08) }
  .rodata 0x803819e0 : { *(.rodata) }
  .sdata 0x804ae30c (NOLOAD) : {
    . = 0x0; lbl_804AE30C = .;
    . = 0x8; lbl_804AE314 = .;
    . = 0x10; lbl_804AE31C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
