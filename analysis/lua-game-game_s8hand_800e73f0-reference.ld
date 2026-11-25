/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_guarded_stop_800e73f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800b0100 = 0x800b0100;
fn_800b01b0 = 0x800b01b0;
SECTIONS {
  .text.s8_guarded_stop_800e73f0 0x800e73f0 : { *(.text.s8_guarded_stop_800e73f0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
