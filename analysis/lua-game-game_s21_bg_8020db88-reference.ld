/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_write_u64_text_8020db88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802ef9c0 = 0x802ef9c0;
fn_80355a44 = 0x80355a44;
lbl_803b3248 = 0x803b3248;
SECTIONS {
  .text.w3d_s21_write_u64_text_8020db88 0x8020db88 : { *(.text.w3d_s21_write_u64_text_8020db88) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
