/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_append_ref_801ddf5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80210d54 = 0x80210d54;
SECTIONS {
  .text.w3d_s21_append_ref_801ddf5c 0x801ddf5c : { *(.text.w3d_s21_append_ref_801ddf5c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
