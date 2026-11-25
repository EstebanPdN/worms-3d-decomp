/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_set_class_801e9090)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020fe00 = 0x8020fe00;
fn_8020fe18 = 0x8020fe18;
SECTIONS {
  .text.w3d_s21_set_class_801e9090 0x801e9090 : { *(.text.w3d_s21_set_class_801e9090) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
