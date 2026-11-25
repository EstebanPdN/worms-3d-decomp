/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_message_initialize_800efc14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800efc80 = 0x800efc80;
fn_8016293c = 0x8016293c;
SECTIONS {
  .text.s8_message_initialize_800efc14 0x800efc14 : { *(.text.s8_message_initialize_800efc14) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
