/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_clear_flags_801f3ccc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020fe00 = 0x8020fe00;
fn_8020fe18 = 0x8020fe18;
lbl_803657d8 = 0x803657d8;
SECTIONS {
  .text.w3d_s21_clear_flags_801f3ccc 0x801f3ccc : { *(.text.w3d_s21_clear_flags_801f3ccc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
