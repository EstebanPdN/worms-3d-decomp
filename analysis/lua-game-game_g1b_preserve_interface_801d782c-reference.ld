/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g1b_preserve_interface_801d782c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ea18c = 0x801ea18c;
SECTIONS {
  .text.g1b_preserve_interface_801d782c 0x801d782c : { *(.text.g1b_preserve_interface_801d782c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
