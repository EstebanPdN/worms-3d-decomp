/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_message_initialize_800feae4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fefe8 = 0x800fefe8;
fn_8015fb34 = 0x8015fb34;
SECTIONS {
  .text.s8_message_initialize_800feae4 0x800feae4 : { *(.text.s8_message_initialize_800feae4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
