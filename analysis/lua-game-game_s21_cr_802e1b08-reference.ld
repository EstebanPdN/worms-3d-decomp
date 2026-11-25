/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_apply_802e1b08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802e23e8 = 0x802e23e8;
fn_802e2508 = 0x802e2508;
fn_802e2a00 = 0x802e2a00;
SECTIONS {
  .text.w3d_s21_apply_802e1b08 0x802e1b08 : { *(.text.w3d_s21_apply_802e1b08) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
