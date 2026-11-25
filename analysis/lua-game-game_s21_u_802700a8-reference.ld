/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_panel_update_802700a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801797b4 = 0x801797b4;
fn_8026f948 = 0x8026f948;
fn_802bc8b4 = 0x802bc8b4;
fn_80341584 = 0x80341584;
SECTIONS {
  .text.w3d_s21_panel_update_802700a8 0x802700a8 : { *(.text.w3d_s21_panel_update_802700a8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
