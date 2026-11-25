/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_handle_800fc710)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80179598 = 0x80179598;
fn_80341584 = 0x80341584;
lbl_8044a524 = 0x8044a524;
SECTIONS {
  .text.s8_handle_800fc710 0x800fc710 : { *(.text.s8_handle_800fc710) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
