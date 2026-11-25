/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_load_80208f48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80208fd8 = 0x80208fd8;
fn_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_s21_load_80208f48 0x80208f48 : { *(.text.w3d_s21_load_80208f48) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
