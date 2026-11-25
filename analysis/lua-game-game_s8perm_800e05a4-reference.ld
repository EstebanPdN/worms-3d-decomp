/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_permuted_800e05a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800DE930 = 0x800de930;
fn_800E0678 = 0x800e0678;
fn_8020FD04 = 0x8020fd04;
lbl_80360CF0 = 0x80360cf0;
SECTIONS {
  .text.s8_permuted_800e05a4 0x800e05a4 : { *(.text.s8_permuted_800e05a4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
