/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_read_game_type_80262124)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc550 = 0x800fc550;
lbl_803cae50 = 0x803cae50;
SECTIONS {
  .text.w3d_s21_read_game_type_80262124 0x80262124 : { *(.text.w3d_s21_read_game_type_80262124) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
