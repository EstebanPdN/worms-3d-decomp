/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_permuted_800d2488)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002A914 = 0x8002a914;
lbl_8040FC48 = 0x8040fc48;
SECTIONS {
  .text.s8_permuted_800d2488 0x800d2488 : { *(.text.s8_permuted_800d2488) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
