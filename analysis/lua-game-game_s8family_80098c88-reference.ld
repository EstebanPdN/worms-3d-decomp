/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_message_initialize_80098c88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80098d94 = 0x80098d94;
fn_8016293c = 0x8016293c;
SECTIONS {
  .text.s8_message_initialize_80098c88 0x80098c88 : { *(.text.s8_message_initialize_80098c88) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
